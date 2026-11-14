// ts4_script.h - scripted pad input and guest-memory watch list for headless runs.
//
// Input script (TS4_INPUT_SCRIPT), one state per line, held until the next line:
//   <frame> <buttons> [lt=N] [rt=N] [lx=N] [ly=N] [rx=N] [ry=N]
//   frame   VdSwap count at which the state starts; "+N" = N frames after the previous line
//   buttons '-' or names joined by '+': A B X Y START BACK UP DOWN LEFT RIGHT LB RB LS RS
//   lt/rt 0..255, sticks -32768..32767. '#' starts a comment.
// Example: press START for 10 frames at frame 900, then A twice:
//   900 START
//   +10 -
//   +60 A
//   +6 -
// Button edges are also delivered as XamInputGetKeystroke(Ex) events (VK_PAD_*).
// Two kinds of line block the script until the game reaches a point, so menus can be driven
// without knowing load times; a following "+N" counts from the swap at which the block cleared:
//   wait <type> <expr> <op> <value> [max=N]   guest-memory condition (op == != < > <= >=;
//                                             type str compares a C string with == or !=)
//   idle <import> <N> [max=N]                 import counter unchanged for N swaps, e.g.
//                                             "idle NtReadFile 90" = file loading has stopped
// max=N gives up after N swaps (logged) and carries on. The pad state is held while blocked.
//
// Watch list (TS4_WATCH), one value per line:  <name> <type> <expr>
//   type  u8 u16 u32 s32 f32 f32x3 (three consecutive floats -> name.x/.y/.z) str (C string;
//         commas are written as '?')
//   expr  0xADDR | [expr]+0xOFF | [expr]-0xOFF   ([] dereferences a big-endian u32 pointer)
// Unreadable values (null or out-of-range pointers) are written as empty fields.

#pragma once

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

#include <rex/import_trace.h>
#include <rex/input/device_assignment.h>
#include <rex/input/input.h>
#include <rex/input/input_driver.h>
#include <rex/input/input_system.h>
#include <rex/input/nop/nop_input_driver.h>
#include <rex/logging.h>
#include <rex/system/xmemory.h>

namespace ts4 {
using namespace rex;

struct PadState {
  uint16_t buttons = 0;
  uint8_t lt = 0, rt = 0;
  int16_t lx = 0, ly = 0, rx = 0, ry = 0;
  bool operator==(const PadState& o) const {
    return buttons == o.buttons && lt == o.lt && rt == o.rt && lx == o.lx && ly == o.ly &&
           rx == o.rx && ry == o.ry;
  }
};

struct ButtonName {
  const char* name;
  uint16_t mask;
  uint16_t vk;
};
inline constexpr ButtonName kButtons[] = {
    {"UP", 0x0001, 0x5810},    {"DOWN", 0x0002, 0x5811}, {"LEFT", 0x0004, 0x5812},
    {"RIGHT", 0x0008, 0x5813}, {"START", 0x0010, 0x5814}, {"BACK", 0x0020, 0x5815},
    {"LS", 0x0040, 0x5816},    {"RS", 0x0080, 0x5817},   {"LB", 0x0100, 0x5805},
    {"RB", 0x0200, 0x5804},    {"A", 0x1000, 0x5800},    {"B", 0x2000, 0x5801},
    {"X", 0x4000, 0x5802},     {"Y", 0x8000, 0x5803},
};

// Guest memory used by script conditions; set by the app once the title is loaded.
inline rex::memory::Memory*& ScriptMemory() {
  static rex::memory::Memory* mem = nullptr;
  return mem;
}

// Guest ranges that are mapped while the title runs: heaps 0x40000000.., XEX images
// 0x82000000.., physical views 0xA0000000... A null-page pointer is rejected.
inline bool GuestReadable(uint32_t a) { return a >= 0x40000000u && a < 0xFFFF0000u; }

inline uint32_t LoadBE32(const uint8_t* p) {
  return uint32_t(p[0]) << 24 | uint32_t(p[1]) << 16 | uint32_t(p[2]) << 8 | p[3];
}

// expr := number | '[' expr ']' ; followed by any number of (+|-) number.
inline bool EvalExpr(const std::string& e, size_t& pos, rex::memory::Memory* mem, uint32_t& out) {
  uint32_t v;
  if (pos < e.size() && e[pos] == '[') {
    pos++;
    uint32_t inner;
    if (!EvalExpr(e, pos, mem, inner)) return false;
    if (pos >= e.size() || e[pos] != ']') return false;
    pos++;
    if (!mem || !GuestReadable(inner)) return false;
    v = LoadBE32(mem->TranslateVirtual<const uint8_t*>(inner));
  } else {
    char* end;
    v = uint32_t(std::strtoul(e.c_str() + pos, &end, 0));
    pos = size_t(end - e.c_str());
  }
  while (pos < e.size() && (e[pos] == '+' || e[pos] == '-')) {
    char op = e[pos++];
    char* end;
    uint32_t off = uint32_t(std::strtoul(e.c_str() + pos, &end, 0));
    pos = size_t(end - e.c_str());
    v = op == '+' ? v + off : v - off;
  }
  out = v;
  return true;
}

// Reads one typed value (u8 u16 u32 s32 f32) at the address an expression gives.
inline bool ReadTyped(const std::string& type, const std::string& expr, rex::memory::Memory* mem,
                      double& value) {
  size_t pos = 0;
  uint32_t addr;
  if (!EvalExpr(expr, pos, mem, addr) || !mem || !GuestReadable(addr)) return false;
  const uint8_t* p = mem->TranslateVirtual<const uint8_t*>(addr);
  if (type == "u8") value = p[0];
  else if (type == "u16") value = uint16_t(p[0] << 8 | p[1]);
  else if (type == "u32") value = LoadBE32(p);
  else if (type == "s32") value = int32_t(LoadBE32(p));
  else if (type == "f32") {
    uint32_t b = LoadBE32(p);
    float f;
    std::memcpy(&f, &b, 4);
    value = f;
  } else return false;
  return true;
}

// Reads a NUL-terminated guest string (printable ASCII, at most 47 characters).
inline bool ReadString(const std::string& expr, rex::memory::Memory* mem, std::string& out) {
  size_t pos = 0;
  uint32_t addr;
  if (!EvalExpr(expr, pos, mem, addr) || !mem || !GuestReadable(addr)) return false;
  const uint8_t* p = mem->TranslateVirtual<const uint8_t*>(addr);
  out.clear();
  for (int i = 0; i < 47 && p[i]; i++) out.push_back(p[i] >= 0x20 && p[i] < 0x7F && p[i] != 0x2C ? char(p[i]) : 0x3F);
  return true;
}

class InputScript {
 public:
  bool Load(const std::string& path) {
    std::ifstream in(path);
    if (!in) return false;
    std::string line;
    int lineno = 0;
    while (std::getline(in, line)) {
      lineno++;
      if (auto h = line.find('#'); h != std::string::npos) line.resize(h);
      std::istringstream ss(line);
      std::string first;
      if (!(ss >> first)) continue;
      Event ev;
      ev.line = lineno;
      if (first == "wait" || first == "idle") {
        ev.kind = first == "wait" ? Event::kWait : Event::kIdle;
        bool ok = ev.kind == Event::kWait
                      ? bool(ss >> ev.type >> ev.expr >> ev.op >> ev.value_s)
                      : bool(ss >> ev.expr >> ev.count);
        if (!ok) {
          REXLOG_WARN("[ts4] input script line {}: malformed '{}'", lineno, first);
          continue;
        }
        if (ev.kind == Event::kIdle && ev.expr.rfind("__imp__", 0) != 0) ev.expr = "__imp__" + ev.expr;
        if (ev.kind == Event::kWait) {
          bool hex = ev.value_s.rfind("0x", 0) == 0 || ev.value_s.rfind("0X", 0) == 0;
          ev.value = hex ? double(std::strtoul(ev.value_s.c_str(), nullptr, 16))
                         : std::strtod(ev.value_s.c_str(), nullptr);
        }
        std::string kv;
        while (ss >> kv)
          if (kv.rfind("max=", 0) == 0) ev.max = std::strtoull(kv.c_str() + 4, nullptr, 0);
        events_.push_back(ev);
        continue;
      }
      std::string buttons_s;
      if (!(ss >> buttons_s)) buttons_s = "-";
      ev.kind = Event::kState;
      ev.relative = first[0] == '+';
      ev.frame = std::strtoull(first.c_str() + (ev.relative ? 1 : 0), nullptr, 0);
      if (buttons_s != "-") {
        std::stringstream bs(buttons_s);
        std::string b;
        while (std::getline(bs, b, '+')) {
          bool ok = false;
          for (auto& k : kButtons)
            if (b == k.name) ev.state.buttons |= k.mask, ok = true;
          if (!ok) REXLOG_WARN("[ts4] input script line {}: unknown button '{}'", lineno, b);
        }
      }
      std::string kv;
      while (ss >> kv) {
        auto eq = kv.find('=');
        if (eq == std::string::npos) continue;
        std::string k = kv.substr(0, eq);
        long v = std::strtol(kv.c_str() + eq + 1, nullptr, 0);
        if (k == "lt") ev.state.lt = uint8_t(v);
        else if (k == "rt") ev.state.rt = uint8_t(v);
        else if (k == "lx") ev.state.lx = int16_t(v);
        else if (k == "ly") ev.state.ly = int16_t(v);
        else if (k == "rx") ev.state.rx = int16_t(v);
        else if (k == "ry") ev.state.ry = int16_t(v);
      }
      events_.push_back(ev);
    }
    return true;
  }

  // Advances the script to `swap` and returns the pad state. Call with non-decreasing swaps.
  // `counter` reads an import counter, `mem` is the guest memory for wait conditions.
  template <typename Counter>
  PadState Step(uint64_t swap, Counter&& counter, rex::memory::Memory* mem) {
    while (cursor_ < events_.size()) {
      Event& e = events_[cursor_];
      if (e.kind == Event::kState) {
        uint64_t due = e.relative ? anchor_ + e.frame : e.frame;
        if (swap < due) break;
        state_ = e.state;
        Advance(due);
        continue;
      }
      if (!blocked_) {
        blocked_ = true;
        block_start_ = idle_since_ = swap;
        if (e.kind == Event::kIdle) idle_value_ = counter(e.expr);
      }
      bool done = false;
      if (e.kind == Event::kWait && e.type == "str") {
        std::string v;
        if (ReadString(e.expr, mem, v)) done = e.op == "==" ? v == e.value_s : e.op == "!=" ? v != e.value_s : false;
      } else if (e.kind == Event::kWait) {
        double v;
        if (ReadTyped(e.type, e.expr, mem, v)) done = Compare(v, e.op, e.value);
      } else {
        uint64_t c = counter(e.expr);
        if (c != idle_value_) idle_value_ = c, idle_since_ = swap;
        done = swap - idle_since_ >= e.count;
      }
      bool timed_out = !done && e.max && swap - block_start_ >= e.max;
      if (!done && !timed_out) break;
      REXLOG_INFO("[ts4] script line {} {} at swap {} (blocked {} swaps)", e.line,
                  done ? "satisfied" : "TIMED OUT", swap, swap - block_start_);
      if (log_) {
        std::fprintf(log_, "%llu,%d,%s\n", (unsigned long long)swap, e.line,
                     done ? "satisfied" : "timeout");
        std::fflush(log_);
      }
      blocked_ = false;
      Advance(swap);
    }
    return state_;
  }

  size_t size() const { return events_.size(); }
  void SetLog(FILE* f) { log_ = f; }

 private:
  struct Event {
    enum Kind { kState, kWait, kIdle } kind = kState;
    int line = 0;
    bool relative = false;
    uint64_t frame = 0;
    PadState state;
    std::string type, expr, op, value_s;
    double value = 0;
    uint64_t count = 0, max = 0;
  };

  static bool Compare(double v, const std::string& op, double ref) {
    if (op == "==") return v == ref;
    if (op == "!=") return v != ref;
    if (op == "<") return v < ref;
    if (op == ">") return v > ref;
    if (op == "<=") return v <= ref;
    if (op == ">=") return v >= ref;
    return false;
  }

  void Advance(uint64_t at) {
    anchor_ = at;
    cursor_++;
  }

  std::vector<Event> events_;
  size_t cursor_ = 0;
  uint64_t anchor_ = 0, block_start_ = 0, idle_since_ = 0, idle_value_ = 0;
  bool blocked_ = false;
  PadState state_;
  FILE* log_ = nullptr;
};

class ScriptInputDriver final : public rex::input::InputDriver {
 public:
  explicit ScriptInputDriver(std::string path) : InputDriver(nullptr, 0), path_(std::move(path)) {}

  X_STATUS Setup() override {
    if (!script_.Load(path_)) {
      REXLOG_ERROR("[ts4] cannot read input script {}", path_);
      return X_STATUS_UNSUCCESSFUL;
    }
    REXLOG_INFO("[ts4] input script: {} lines", script_.size());
    if (const char* lp = std::getenv("TS4_SCRIPT_LOG")) {
      if (FILE* f = std::fopen(lp, "w")) std::fprintf(f, "swap,line,result\n"), script_.SetLog(f);
    }
    return X_STATUS_SUCCESS;
  }

  void EnumerateDevices(std::vector<rex::input::DeviceInfo>& out) override {
    rex::input::DeviceInfo info;
    info.id = kDevice;
    info.name = "TS4 script pad";
    out.push_back(info);
  }

  X_RESULT GetDeviceState(rex::input::DeviceId id, rex::input::X_INPUT_STATE* out) override {
    if (id != kDevice) return X_ERROR_DEVICE_NOT_CONNECTED;
    std::lock_guard lock(mutex_);
    PadState st = Current();
    if (!(st == last_state_)) {
      last_state_ = st;
      packet_++;
    }
    if (out) {
      std::memset(out, 0, sizeof(*out));
      out->packet_number = packet_;
      out->gamepad.buttons = st.buttons;
      out->gamepad.left_trigger = st.lt;
      out->gamepad.right_trigger = st.rt;
      out->gamepad.thumb_lx = st.lx;
      out->gamepad.thumb_ly = st.ly;
      out->gamepad.thumb_rx = st.rx;
      out->gamepad.thumb_ry = st.ry;
    }
    return X_ERROR_SUCCESS;
  }

  X_RESULT GetDeviceCapabilities(rex::input::DeviceId id, uint32_t,
                                 rex::input::X_INPUT_CAPABILITIES* caps) override {
    if (id != kDevice) return X_ERROR_DEVICE_NOT_CONNECTED;
    if (caps) {
      std::memset(caps, 0, sizeof(*caps));
      caps->type = 0x01;
      caps->sub_type = 0x01;
      caps->gamepad.buttons = 0xFFFF;
      caps->gamepad.left_trigger = 0xFF;
      caps->gamepad.right_trigger = 0xFF;
      caps->gamepad.thumb_lx = int16_t(0x7FFF);
      caps->gamepad.thumb_ly = int16_t(0x7FFF);
      caps->gamepad.thumb_rx = int16_t(0x7FFF);
      caps->gamepad.thumb_ry = int16_t(0x7FFF);
    }
    return X_ERROR_SUCCESS;
  }

  X_RESULT SetDeviceVibration(rex::input::DeviceId id, rex::input::X_INPUT_VIBRATION*) override {
    return id == kDevice ? X_ERROR_SUCCESS : X_ERROR_DEVICE_NOT_CONNECTED;
  }

  X_RESULT GetDeviceKeystroke(rex::input::DeviceId id, uint32_t,
                              rex::input::X_INPUT_KEYSTROKE* out) override {
    if (id != kDevice) return X_ERROR_DEVICE_NOT_CONNECTED;
    std::lock_guard lock(mutex_);
    PadState st = Current();
    uint16_t changed = st.buttons ^ key_buttons_;
    for (auto& k : kButtons) {
      if (changed & k.mask) keys_.push_back({k.vk, uint16_t((st.buttons & k.mask) ? 1 : 2)});
    }
    key_buttons_ = st.buttons;
    if (keys_.empty()) return X_ERROR_EMPTY;
    auto [vk, flags] = keys_.front();
    keys_.pop_front();
    if (out) {
      std::memset(out, 0, sizeof(*out));
      out->virtual_key = vk;
      out->flags = flags;
      out->user_index = 0;
    }
    return X_ERROR_SUCCESS;
  }

 private:
  static constexpr auto kDevice = static_cast<rex::input::DeviceId>(0x54533400);
  PadState Current() {
    uint64_t swap = rex::trace::GetImportCount("__imp__VdSwap");
    if (swap < last_swap_) swap = last_swap_;
    last_swap_ = swap;
    return script_.Step(swap, [](const std::string& n) { return rex::trace::GetImportCount(n.c_str()); },
                        ScriptMemory());
  }
  uint64_t last_swap_ = 0;

  std::string path_;
  InputScript script_;
  std::mutex mutex_;
  PadState last_state_;
  uint32_t packet_ = 1;
  uint16_t key_buttons_ = 0;
  std::deque<std::pair<uint16_t, uint16_t>> keys_;
};

inline std::unique_ptr<rex::input::InputSystem> CreateScriptInputSystem(const std::string& path) {
  auto input = std::make_unique<rex::input::InputSystem>(nullptr);
  auto drv = std::make_unique<ScriptInputDriver>(path);
  if (drv->Setup() == X_STATUS_SUCCESS) input->AddDriver(std::move(drv));
  input->AddDriver(std::make_unique<rex::input::nop::NopInputDriver>(nullptr, 1));
  input->SetDeviceAssignment(std::make_unique<rex::input::SlotAssignment>());
  return input;
}

// ---------------------------------------------------------------------------
// Guest memory watch list.
class WatchList {
 public:
  bool Load(const std::string& path) {
    std::ifstream in(path);
    if (!in) return false;
    std::string line;
    while (std::getline(in, line)) {
      if (auto h = line.find('#'); h != std::string::npos) line.resize(h);
      std::istringstream ss(line);
      Item it;
      if (!(ss >> it.name >> it.type >> it.expr)) continue;
      items_.push_back(it);
    }
    REXLOG_INFO("[ts4] watch list: {} values", items_.size());
    return !items_.empty();
  }

  void WriteHeader(FILE* f) const {
    std::fprintf(f, "swap");
    for (auto& it : items_) {
      if (it.type == "f32x3")
        std::fprintf(f, ",%s.x,%s.y,%s.z", it.name.c_str(), it.name.c_str(), it.name.c_str());
      else
        std::fprintf(f, ",%s", it.name.c_str());
    }
    std::fprintf(f, "\n");
  }

  void WriteRow(FILE* f, uint64_t swap, rex::memory::Memory* mem) const {
    std::fprintf(f, "%llu", (unsigned long long)swap);
    for (auto& it : items_) {
      size_t pos = 0;
      uint32_t addr = 0;
      bool ok = Eval(it.expr, pos, mem, addr);
      if (it.type == "str") {
        std::string v;
        std::fprintf(f, ",");
        if (ok && ReadString(it.expr, mem, v)) std::fprintf(f, "%s", v.c_str());
        continue;
      }
      int n = it.type == "f32x3" ? 3 : 1;
      for (int k = 0; k < n; k++) {
        std::fprintf(f, ",");
        if (!ok) continue;
        uint32_t a = addr + 4 * k;
        if (!Readable(a)) continue;
        const uint8_t* p = mem->TranslateVirtual<const uint8_t*>(a);
        if (it.type == "u8") std::fprintf(f, "%u", p[0]);
        else if (it.type == "u16") std::fprintf(f, "%u", unsigned(p[0] << 8 | p[1]));
        else {
          uint32_t v = uint32_t(p[0]) << 24 | uint32_t(p[1]) << 16 | uint32_t(p[2]) << 8 | p[3];
          if (it.type == "u32") std::fprintf(f, "0x%08X", v);
          else if (it.type == "s32") std::fprintf(f, "%d", int32_t(v));
          else {
            float fv;
            std::memcpy(&fv, &v, 4);
            std::fprintf(f, "%.6g", fv);
          }
        }
      }
    }
    std::fprintf(f, "\n");
  }

 private:
  struct Item {
    std::string name, type, expr;
  };

  static bool Eval(const std::string& e, size_t& pos, rex::memory::Memory* mem, uint32_t& out) {
    return EvalExpr(e, pos, mem, out);
  }
  static bool Readable(uint32_t a) { return GuestReadable(a); }

  std::vector<Item> items_;
};

}  // namespace ts4
