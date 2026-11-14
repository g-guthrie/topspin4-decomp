// ts4 - ReXGlue host app for the Top Spin 4 bring-up (generated scaffold + RC2 hooks).
//
// Everything is driven by environment variables so a run can be scripted headlessly:
//   TS4_ISO=path             mount the owner's disc image; game:/d: point at it once default.xex
//                            has been loaded from game_data_root
//   REX_IMPORT_TRACE_DIR=d   import-call counters -> d/imports_latest.tsv every 2 s
//   TS4_INPUT_SCRIPT=file    scripted pad for user 0 (see ts4_script.h for the format); replaces
//                            the SDL / keyboard drivers
//   TS4_SHOT_DIR=d           capture the guest output image to d/frame_<swap>.ppm ...
//   TS4_SHOT_EVERY=n         ... every n VdSwap calls (default 30)
//   TS4_WATCH=file           guest-memory values to log (see ts4_script.h) ...
//   TS4_WATCH_OUT=file.csv   ... one row per VdSwap (default <TS4_SHOT_DIR>/watch.csv)
//   TS4_FRAME_LOG=file.csv   swap count and wall time per second (frame rate measurement)
//   TS4_EXIT_AT_SWAP=n       hard-exit after n VdSwap calls

#pragma once

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <thread>

#include <rex/filesystem/devices/disc_image_device.h>
#include <rex/filesystem/vfs.h>
#include <rex/import_trace.h>
#include <rex/logging.h>
#include <rex/rex_app.h>
#include <rex/runtime.h>
#include <rex/system/interfaces/graphics.h>
#include <rex/system/xmemory.h>
#include <rex/ui/presenter.h>

#include "ts4_script.h"

class Ts4App : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<Ts4App>(new Ts4App(ctx, "ts4", PPCImageConfig));
  }

  ~Ts4App() override {
    stop_.store(true);
    if (dumper_.joinable()) dumper_.join();
    if (frame_thread_.joinable()) frame_thread_.join();
  }

 protected:
  void OnPreSetup(rex::RuntimeConfig& config) override {
    if (const char* script = std::getenv("TS4_INPUT_SCRIPT")) {
      std::string path = script;
      config.input_factory = [path](bool) -> std::unique_ptr<rex::system::IInputSystem> {
        return ts4::CreateScriptInputSystem(path);
      };
      REXLOG_INFO("[ts4] scripted input from {}", path);
    }
  }

  void OnPostLoadXexImage() override {
    StartImportDumper();
    StartFrameThread();
    const char* iso = std::getenv("TS4_ISO");
    if (!iso || !*iso) return;
    auto* fs = runtime()->file_system();
    constexpr const char* kMount = "\\Device\\Cdrom0";
    auto dev = std::make_unique<rex::filesystem::DiscImageDevice>(kMount, iso);
    if (!dev->Initialize()) {
      REXLOG_ERROR("[ts4] failed to open disc image {}", iso);
      return;
    }
    REXLOG_INFO("[ts4] disc image {}: {} files", iso, dev->file_count());
    fs->RegisterDevice(std::move(dev));
    fs->UnregisterSymbolicLink("game:");
    fs->UnregisterSymbolicLink("d:");
    fs->RegisterSymbolicLink("game:", kMount);
    fs->RegisterSymbolicLink("d:", kMount);
    REXLOG_INFO("[ts4] game: and d: now point at {}", kMount);
  }

  void OnShutdown() override { DumpImports("shutdown"); }

 private:
  static long EnvLong(const char* name, long def) {
    const char* v = std::getenv(name);
    return v && *v ? std::strtol(v, nullptr, 0) : def;
  }

  void DumpImports(const char* label) {
    const char* dir = std::getenv("REX_IMPORT_TRACE_DIR");
    if (!dir) return;
    std::string path = std::string(dir) + "/imports_latest.tsv";
    rex::trace::DumpImportCounts(path.c_str(), label);
  }

  void StartImportDumper() {
    if (!std::getenv("REX_IMPORT_TRACE_DIR") || dumper_.joinable()) return;
    dumper_ = std::thread([this] {
      while (!stop_.load()) {
        for (int i = 0; i < 20 && !stop_.load(); i++)
          std::this_thread::sleep_for(std::chrono::milliseconds(100));
        DumpImports("periodic");
      }
    });
  }

  // Polls the VdSwap counter: frame captures, memory watch rows, frame-rate log, exit.
  void StartFrameThread() {
    if (frame_thread_.joinable()) return;
    const char* shot_dir = std::getenv("TS4_SHOT_DIR");
    const char* watch = std::getenv("TS4_WATCH");
    const char* frame_log = std::getenv("TS4_FRAME_LOG");
    long exit_at = EnvLong("TS4_EXIT_AT_SWAP", 0);
    if (!shot_dir && !watch && !frame_log && !exit_at) return;
    long every = EnvLong("TS4_SHOT_EVERY", 30);
    std::string watch_out = std::getenv("TS4_WATCH_OUT")       ? std::getenv("TS4_WATCH_OUT")
                            : shot_dir                         ? std::string(shot_dir) + "/watch.csv"
                                                               : std::string("watch.csv");
    frame_thread_ = std::thread([=, this] {
      ts4::WatchList wl;
      FILE* wf = nullptr;
      if (watch && wl.Load(watch)) {
        wf = std::fopen(watch_out.c_str(), "w");
        if (wf) wl.WriteHeader(wf);
      }
      FILE* ff = frame_log ? std::fopen(frame_log, "w") : nullptr;
      if (ff) std::fprintf(ff, "t_ms,swaps\n");
      auto t0 = std::chrono::steady_clock::now();
      auto last_log = t0;
      uint64_t last = 0, last_shot = 0;
      while (!stop_.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        uint64_t n = rex::trace::GetImportCount("__imp__VdSwap");
        auto now = std::chrono::steady_clock::now();
        if (ff && now - last_log >= std::chrono::seconds(1)) {
          last_log = now;
          std::fprintf(ff, "%lld,%llu\n",
                       (long long)std::chrono::duration_cast<std::chrono::milliseconds>(now - t0).count(),
                       (unsigned long long)n);
          std::fflush(ff);
        }
        if (n == last) continue;
        last = n;
        if (wf) {
          wl.WriteRow(wf, n, runtime()->memory());
          if (n % 30 == 0) std::fflush(wf);
        }
        if (shot_dir && every > 0 && n >= last_shot + uint64_t(every)) {
          last_shot = n;
          Capture(std::string(shot_dir), n);
        }
        if (exit_at && n >= uint64_t(exit_at)) {
          if (wf) std::fclose(wf);
          if (ff) std::fclose(ff);
          DumpImports("exit_at_swap");
          REXLOG_INFO("[ts4] TS4_EXIT_AT_SWAP reached ({}); exiting", n);
          std::_Exit(0);
        }
      }
      if (wf) std::fclose(wf);
      if (ff) std::fclose(ff);
    });
  }

  void Capture(const std::string& dir, uint64_t swap) {
    auto* gs = runtime()->graphics_system();
    auto* presenter = gs ? gs->presenter() : nullptr;
    if (!presenter) return;
    rex::ui::RawImage img;
    if (!presenter->CaptureGuestOutput(img) || !img.width || !img.height) return;
    char name[64];
    std::snprintf(name, sizeof(name), "/frame_%06llu.ppm", (unsigned long long)swap);
    FILE* f = std::fopen((dir + name).c_str(), "wb");
    if (!f) return;
    std::fprintf(f, "P6\n%u %u\n255\n", img.width, img.height);
    for (uint32_t y = 0; y < img.height; y++) {
      const uint8_t* row = img.data.data() + y * img.stride;
      for (uint32_t x = 0; x < img.width; x++) std::fwrite(row + 4 * x, 1, 3, f);
    }
    std::fclose(f);
  }

  std::atomic<bool> stop_{false};
  std::thread dumper_;
  std::thread frame_thread_;
};
