# Recovered classes (Xbox 360, Swing_DLL.xex)

C++ classes rebuilt from every function that touches them. The definitions are in
`src/xbox360/include/ts4/classes.h`. That header is opt-in: include it after `include/ts4/ts4.h`. Field tags follow
docs/agents/types.md (`V <addr>` = offset used by a byte-matched function, `U asm <addr>` = offset seen only in the
disassembly of an unmatched function). Every MATCH was measured with
`TS4_MATCHING_DIR=work/matching-b215 python3 tools/fn_check.py <src> '<decorated>=0xADDR'` (cl 16.00.10224 PPC) on
2026-11-23.

## Ts4Vector3 (0xC) / Ts4Matrix44 (0x40, align 16)

| | |
|---|---|
| vtable / ctor / dtor | none (value classes) |
| operator= | Vector3: loads z, y, x into temporaries, then stores x, y, z. Matrix44: `memcpy(this, &s, 0x40)` as a real call |
| evidence | 88187B18 (3 vector copies + 1 matrix memcpy), 88187BC0 (through Ts4XformBlock) |
| status | used by matched code |

## Ts4XformBlock (0x80)

| off | field | type | evidence |
|---|---|---|---|
| 0x00 | a | Ts4Vector3 | V 88187B18 |
| 0x0C | b | Ts4Vector3 | V 88187B18 |
| 0x18 | c | Ts4Vector3 | V 88187B18 |
| 0x30 | m | Ts4Matrix44 | V 88187B18 |
| 0x70 | dx, dy, dz | float x3 (copied in field order, so not a Vector3) | V 88187B18 |

- Members: `Set(const Ts4XformBlock&)` = 88187B18, **MATCH** (`?Set@Ts4XformBlock@@QAAXABU1@@Z`).
- Callers: 88187BC0 (matched) and 887D7FB0 (unmatched, 31 off in scratch). 887D7FB0 copies record[0].block into
  every record of a 0xD0-stride array at owner+0xB0.

## Ts4RelArr\<T\> (0xC, template view of Ts4RelArray12)

`{int offset (-1 = none); unsigned count; unsigned capacity}`. The data is at `(char*)this + offset`. `Assign(src)`:
if `n = src.count > 0` (signed test), both offsets are set and `capacity >= n` (unsigned), then memcpy n elements
and set `count = max(count, n)` (cmplw). **Conflict with containers.h**: Ts4RelArray12 declares count and capacity
as int, but 88187BC0 needs them unsigned. The layout is the same.

## Ts4XformRecord (0xD0)

| off | field | type | evidence |
|---|---|---|---|
| 0x00 | a | Ts4RelArr<0x30-byte elem> | V 88187BC0 |
| 0x0C / 0x18 / 0x24 | b, c, d | Ts4RelArr<8-byte elem> | V 88187BC0 |
| 0x30, 0x31 | f_30, f_31 | u8 | V 88187BC0 |
| 0x40 | block | Ts4XformBlock | V 88187BC0, U asm 887D7FB0 |
| 0xC0 | e | Ts4RelArr<0x10-byte elem> | V 88187BC0 |

- Members: `Set(const Ts4XformRecord&)` = 88187BC0, **MATCH** (`?Set@Ts4XformRecord@@QAAXABU1@@Z`).
- C callers: cx34_f.c (`fn_88187BC0`) and cx40_a.c (`fn_887D7FB0`).
- Source: src/xbox360/q5s_cls_xform.cpp. Spec: work/specs/Q5S/q5s_cls_xform.json.

## Ts4Tracker (0x98), vtable lbl_880F3798

| off | field | type | evidence |
|---|---|---|---|
| 0x00 | vptr | lbl_880F3798 (1 slot: deleting dtor 88262BB0) | U asm 886CC058 886C3510 |
| 0x04 | f_04 | int | V 886CBC30 |
| 0x08 | shell | Ts4TrackerShell (vptr lbl_880D6B70) | U asm 886CC058 886C3510 |
| 0x0C-0x2C | f_0c..f_2c | float x9 | V 886CBC30 |
| 0x30 | f_30 | int (ctor only) | U asm 886CC058 |
| 0x34 | f_34 | int | V 886CBC30 |
| 0x38 / 0x3C / 0x40 | f_38, scale (reset to 1.0f), f_40 | float | V 886CBC30 |
| 0x44 | a | Ts4TrackerAcc {float v[4]; int n} (0x14) | V 886CBC30 |
| 0x58 | b | Ts4TrackerAcc (ctor only) | U asm 886CC058 |
| 0x6C / 0x70 | f_6c (int), f_70 (float) | | V 886CBC30 |
| 0x74-0x7C | f_74, f_78, f_7c | int | V 886CBC30 |
| 0x80 | f_80 | u8 | V 886CBC30 |
| 0x81-0x97 | unknown | | size from vector delete 88262730 (stride 0x98) |

- ctor 886CC058: vptrs, then `a()` and `b()`, then `{ f_30 = 0; Reset(); }` with Reset inlined. **Open, 6 off**:
  three list-scheduling pairs (drafts/q5s_swan_886cc058_nearmiss.c).
- `Reset()` 886CBC30: **MATCH** (`?Reset@Ts4Tracker@@QAAXXZ`). Source: src/xbox360/q5s_cls_tracker.cpp. Spec:
  work/specs/Q5S/q5s_cls_tracker.json.
- dtor: the inline body is 886C3510 (stores both vptrs), the deleting dtor is 88262BB0, the vector delete is 88262730.
- Other loaders of lbl_880F3798 (containers that embed the tracker; not examined): 88266740, 886D66A8, 886E1328.
- 886C5230 (on the task list as a Tracker function) works on a clip/held table instead; it does not touch this class.

## lbl_880D6B70: not one class

This vtable has one slot, 8816F628, a deleting dtor that only resets the vptr. The linker folds (ICF) the vtables of
every trivial polymorphic class whose only virtual is an empty dtor into this one. Users include Ts4Tracker+0x08, the
16-byte elements of 88267630 (`{vptr, u32, u32, u8}`) and the service members at +0x24/0x34/0x44/0x54 of
88212040 (fam3_service_dtor.cpp). Model each user as its own small class with `virtual ~X() {}`. Do not give them a
shared base.

## Ts4PlayerState sub-objects (8866D110, open)

- +0x40C: a sub-object with floats at +0x3C and +0x40 (U asm 8866D110).
- +0x9A0 move_state: a vec4 at +0x20 and an id at +0x5C (absolute +0x9FC) (U asm 8866D110).
- 8866D110 is 10 off: drafts/q5s_cls_8866D110_nearmiss.cpp. The dead `addi r9,r11,0x40c` is still missing.

## Codegen rules learned

- `#pragma function(memcpy)` must be active where the inline `Ts4Matrix44::operator=` is defined; classes.h does
  this. Otherwise cl expands the 0x40 copy into an ldu/stdu loop.
- Use an explicit `void Set(const T&)` member, not a compiler-generated or `T&`-returning operator=. Returning
  *this changes the saved registers and can turn the call into a tail call.
- Two matched functions in one TU where one calls the other: mark the callee `TS4_NOINLINE`.
- In C++, a named `extern const float` zero is reloaded after every float store because of aliasing. A literal
  0.0f is CSE'd, and the checker accepts `__real@00000000` against the pool label 0x8814B440. The 1.0f at
  script_constants+0xF70 must stay `g_ts4_script_constants[0]`.
- A rel-array count compared as unsigned produces cmplw; `n > 0` on the int copy stays cmpwi.
- `__forceinline` is needed for the template's Assign: cl did not inline it five times on its own.
- Under /O2, cl inlines a non-inline member defined in the same TU (Tracker ctor -> Reset).
