/* Loader_DLL.xex 0x833D25E8-0x833DBBE0, executable version 0.0.0.3.
   Render-state register setters: store a value into a
   24-byte slot of the state block and set the slot's bit in a 64-bit
   dirty mask. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#define TS4L_BIT63 0x8000000000000000ui64
#else
typedef unsigned long long ts4l_u64;
#define TS4L_BIT63 0x8000000000000000ull
#endif
typedef struct { unsigned w0[3]; unsigned pad : 7; unsigned fld : 2; unsigned rest : 23; unsigned w1[2]; } Ts4lSlot1;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x460]; Ts4lSlot1 slot[1]; } Ts4lSlot1Obj;

typedef struct { unsigned w0[5]; unsigned pad : 30; unsigned fld : 2; } Ts4lSlot2;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x460]; Ts4lSlot2 slot[1]; } Ts4lSlot2Obj;

typedef struct { unsigned w0[5]; unsigned pad : 27; unsigned fld : 2; unsigned rest : 3; } Ts4lSlot3;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x460]; Ts4lSlot3 slot[1]; } Ts4lSlot3Obj;

typedef struct { unsigned w0[4]; unsigned pad : 5; unsigned fld : 5; unsigned rest : 22; unsigned w1[1]; } Ts4lSlot4;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x460]; Ts4lSlot4 slot[1]; } Ts4lSlot4Obj;

typedef struct { unsigned w0[4]; unsigned fld : 5; unsigned rest : 27; unsigned w1[1]; } Ts4lSlot5;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x460]; Ts4lSlot5 slot[1]; } Ts4lSlot5Obj;

typedef struct { unsigned w0[5]; unsigned pad : 29; unsigned fld : 1; unsigned rest : 2; } Ts4lSlot6;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x460]; Ts4lSlot6 slot[1]; } Ts4lSlot6Obj;

typedef struct { unsigned w0[1]; unsigned pad : 20; unsigned fld : 1; unsigned rest : 11; unsigned w1[4]; } Ts4lSlot7;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x460]; Ts4lSlot7 slot[1]; } Ts4lSlot7Obj;


void ts4l_set_slot_field1_833D25E8(Ts4lSlot1Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field1_833D3588(Ts4lSlot1Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field1_833D51C0(Ts4lSlot1Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field1_833D79C0(Ts4lSlot1Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field1_833DBA28(Ts4lSlot1Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field2_833D2630(Ts4lSlot2Obj *o, int i, int v)
{
    o->slot[i].fld = v != 0;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field2_833D35D0(Ts4lSlot2Obj *o, int i, int v)
{
    o->slot[i].fld = v != 0;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field2_833D5208(Ts4lSlot2Obj *o, int i, int v)
{
    o->slot[i].fld = v != 0;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field2_833D7A40(Ts4lSlot2Obj *o, int i, int v)
{
    o->slot[i].fld = v != 0;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field2_833DBA70(Ts4lSlot2Obj *o, int i, int v)
{
    o->slot[i].fld = v != 0;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field3_833D2680(Ts4lSlot3Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field3_833D3620(Ts4lSlot3Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field3_833D5258(Ts4lSlot3Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field3_833D7A90(Ts4lSlot3Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field3_833DBAC0(Ts4lSlot3Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field4_833D26C8(Ts4lSlot4Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field4_833D3668(Ts4lSlot4Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field4_833D52A0(Ts4lSlot4Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field4_833D7AD8(Ts4lSlot4Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field4_833DBB08(Ts4lSlot4Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field5_833D2710(Ts4lSlot5Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field5_833D36B0(Ts4lSlot5Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field5_833D52E8(Ts4lSlot5Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field5_833D7B20(Ts4lSlot5Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field5_833DBB50(Ts4lSlot5Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field6_833D2758(Ts4lSlot6Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field6_833D36F8(Ts4lSlot6Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field6_833D5330(Ts4lSlot6Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field6_833D7B68(Ts4lSlot6Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field6_833DBB98(Ts4lSlot6Obj *o, int i, int v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field7_833D27A0(Ts4lSlot7Obj *o, int i, int v)
{
    o->slot[i].fld = v == 0;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field7_833D3740(Ts4lSlot7Obj *o, int i, int v)
{
    o->slot[i].fld = v == 0;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field7_833D5378(Ts4lSlot7Obj *o, int i, int v)
{
    o->slot[i].fld = v == 0;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field7_833D7BB0(Ts4lSlot7Obj *o, int i, int v)
{
    o->slot[i].fld = v == 0;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

void ts4l_set_slot_field7_833DBBE0(Ts4lSlot7Obj *o, int i, int v)
{
    o->slot[i].fld = v == 0;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}
