/* Loader_DLL.xex 0x8321EF78-0x832214E0, executable version 0.0.0.3.
 * Per-slot boolean setters: store a flag in a 24-byte slot and set the
 * slot's bit in a 64-bit dirty mask. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#define TS4L_BIT63 0x8000000000000000ui64
#else
typedef unsigned long long ts4l_u64;
#define TS4L_BIT63 0x8000000000000000ull
#endif

typedef struct { unsigned w0, w1; unsigned pad : 30; unsigned fld : 2; unsigned w3, w4, w5; } Ts4lSlotLow;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Ts4lSlotLow slot[1]; } Ts4lObjLow;
typedef struct { unsigned pad : 20; unsigned fld : 1; unsigned rest : 11; unsigned w1, w2, w3, w4, w5; } Ts4lSlotBit;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x464]; Ts4lSlotBit slot[1]; } Ts4lObjBit;

void ts4l_set_slot_flag_8321EF78(Ts4lObjLow *o, int i, int v)
{
    o->slot[i].fld = (v != 0);
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_flag_83221370(Ts4lObjLow *o, int i, int v)
{
    o->slot[i].fld = (v != 0);
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_flag_8321F0E8(Ts4lObjBit *o, int i, int v)
{
    o->slot[i].fld = (v == 0);
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_flag_832214E0(Ts4lObjBit *o, int i, int v)
{
    o->slot[i].fld = (v == 0);
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}
