/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l10_state_setters_833D25E8.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#define TS4_BIT63 0x8000000000000000ui64
#else
typedef unsigned long long ts4_u64;
#define TS4_BIT63 0x8000000000000000ull
#endif
typedef struct { unsigned w0[3]; unsigned pad : 7; unsigned fld : 2; unsigned rest : 23; unsigned w1[2]; } Ts4lSlot1;
typedef struct { char pad0[0x18]; ts4_u64 dirty; char pad1[0x460]; Ts4lSlot1 slot[1]; } Ts4lSlot1Obj;

typedef struct { unsigned w0[5]; unsigned pad : 30; unsigned fld : 2; } Ts4lSlot2;
typedef struct { char pad0[0x18]; ts4_u64 dirty; char pad1[0x460]; Ts4lSlot2 slot[1]; } Ts4lSlot2Obj;

typedef struct { unsigned w0[5]; unsigned pad : 27; unsigned fld : 2; unsigned rest : 3; } Ts4lSlot3;
typedef struct { char pad0[0x18]; ts4_u64 dirty; char pad1[0x460]; Ts4lSlot3 slot[1]; } Ts4lSlot3Obj;

typedef struct { unsigned w0[4]; unsigned pad : 5; unsigned fld : 5; unsigned rest : 22; unsigned w1[1]; } Ts4lSlot4;
typedef struct { char pad0[0x18]; ts4_u64 dirty; char pad1[0x460]; Ts4lSlot4 slot[1]; } Ts4lSlot4Obj;

typedef struct { unsigned w0[4]; unsigned fld : 5; unsigned rest : 27; unsigned w1[1]; } Ts4lSlot5;
typedef struct { char pad0[0x18]; ts4_u64 dirty; char pad1[0x460]; Ts4lSlot5 slot[1]; } Ts4lSlot5Obj;

typedef struct { unsigned w0[5]; unsigned pad : 29; unsigned fld : 1; unsigned rest : 2; } Ts4lSlot6;
typedef struct { char pad0[0x18]; ts4_u64 dirty; char pad1[0x460]; Ts4lSlot6 slot[1]; } Ts4lSlot6Obj;

typedef struct { unsigned w0[1]; unsigned pad : 20; unsigned fld : 1; unsigned rest : 11; unsigned w1[4]; } Ts4lSlot7;
typedef struct { char pad0[0x18]; ts4_u64 dirty; char pad1[0x460]; Ts4lSlot7 slot[1]; } Ts4lSlot7Obj;



/* Swing_DLL.xex 0x886EC318 */
void ts4_set_slot_field2_886EC318(Ts4lSlot2Obj *o, int i, int v)
{
    o->slot[i].fld = v != 0;
    o->dirty |= TS4_BIT63 >> (unsigned)(i + 32);
}

/* Swing_DLL.xex 0x886ED7A0 */
void ts4_set_slot_field7_886ED7A0(Ts4lSlot7Obj *o, int i, int v)
{
    o->slot[i].fld = v == 0;
    o->dirty |= TS4_BIT63 >> (unsigned)(i + 32);
}

/* Swing_DLL.xex 0x8890C668 */
void ts4_set_slot_field7_8890C668(Ts4lSlot7Obj *o, int i, int v)
{
    o->slot[i].fld = v == 0;
    o->dirty |= TS4_BIT63 >> (unsigned)(i + 32);
}

/* Swing_DLL.xex 0x8890C7D8 */
void ts4_set_slot_field2_8890C7D8(Ts4lSlot2Obj *o, int i, int v)
{
    o->slot[i].fld = v != 0;
    o->dirty |= TS4_BIT63 >> (unsigned)(i + 32);
}

