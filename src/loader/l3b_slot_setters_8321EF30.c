/* Loader_DLL.xex 0x8321EF30-0x83221498, executable version 0.0.0.3.
 * Per-slot register-state setters: store a bit field in a 24-byte slot and
 * set the slot's bit in a 64-bit dirty mask. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#define TS4L_BIT63 0x8000000000000000ui64
#else
typedef unsigned long long ts4l_u64;
#define TS4L_BIT63 0x8000000000000000ull
#endif

typedef struct { unsigned pad : 7; unsigned fld : 2; unsigned rest : 23; unsigned w1; unsigned w2; unsigned w3, w4, w5; } Slot8321EF30;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Slot8321EF30 slot[1]; } Obj8321EF30;

void ts4l_set_slot_field_8321EF30(Obj8321EF30 *o, int i, unsigned v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

typedef struct { unsigned w0; unsigned w1; unsigned pad : 27; unsigned fld : 2; unsigned rest : 3; unsigned w3, w4, w5; } Slot8321EFC8;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Slot8321EFC8 slot[1]; } Obj8321EFC8;

void ts4l_set_slot_field_8321EFC8(Obj8321EFC8 *o, int i, unsigned v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

typedef struct { unsigned w0; unsigned pad : 5; unsigned fld : 5; unsigned rest : 22; unsigned w2; unsigned w3, w4, w5; } Slot8321F010;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Slot8321F010 slot[1]; } Obj8321F010;

void ts4l_set_slot_field_8321F010(Obj8321F010 *o, int i, unsigned v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

typedef struct { unsigned w0; unsigned fld : 5; unsigned rest : 27; unsigned w2; unsigned w3, w4, w5; } Slot8321F058;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Slot8321F058 slot[1]; } Obj8321F058;

void ts4l_set_slot_field_8321F058(Obj8321F058 *o, int i, unsigned v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

typedef struct { unsigned w0; unsigned w1; unsigned pad : 29; unsigned fld : 1; unsigned rest : 2; unsigned w3, w4, w5; } Slot8321F0A0;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Slot8321F0A0 slot[1]; } Obj8321F0A0;

void ts4l_set_slot_field_8321F0A0(Obj8321F0A0 *o, int i, unsigned v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

typedef struct { unsigned pad : 7; unsigned fld : 2; unsigned rest : 23; unsigned w1; unsigned w2; unsigned w3, w4, w5; } Slot83221328;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Slot83221328 slot[1]; } Obj83221328;

void ts4l_set_slot_field_83221328(Obj83221328 *o, int i, unsigned v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

typedef struct { unsigned w0; unsigned w1; unsigned pad : 27; unsigned fld : 2; unsigned rest : 3; unsigned w3, w4, w5; } Slot832213C0;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Slot832213C0 slot[1]; } Obj832213C0;

void ts4l_set_slot_field_832213C0(Obj832213C0 *o, int i, unsigned v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

typedef struct { unsigned w0; unsigned pad : 5; unsigned fld : 5; unsigned rest : 22; unsigned w2; unsigned w3, w4, w5; } Slot83221408;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Slot83221408 slot[1]; } Obj83221408;

void ts4l_set_slot_field_83221408(Obj83221408 *o, int i, unsigned v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

typedef struct { unsigned w0; unsigned fld : 5; unsigned rest : 27; unsigned w2; unsigned w3, w4, w5; } Slot83221450;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Slot83221450 slot[1]; } Obj83221450;

void ts4l_set_slot_field_83221450(Obj83221450 *o, int i, unsigned v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}

typedef struct { unsigned w0; unsigned w1; unsigned pad : 29; unsigned fld : 1; unsigned rest : 2; unsigned w3, w4, w5; } Slot83221498;
typedef struct { char pad0[0x18]; ts4l_u64 dirty; char pad1[0x46c]; Slot83221498 slot[1]; } Obj83221498;

void ts4l_set_slot_field_83221498(Obj83221498 *o, int i, unsigned v)
{
    o->slot[i].fld = v;
    o->dirty |= TS4L_BIT63 >> (unsigned)(i + 32);
}
