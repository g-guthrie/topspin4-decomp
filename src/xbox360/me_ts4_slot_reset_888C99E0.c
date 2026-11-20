
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Slot { u32 v; } Slot;
typedef struct SVec { Slot **begin, **end; } SVec;
typedef struct Snd Snd;
typedef struct PVec { Snd **begin, **end; } PVec;
typedef struct O { char pad[0xac]; SVec slots; char pad2[4]; PVec snds; char pad3[0x1530 - 0xc0]; u8 dirty, dirty2; } O;
extern void fn_8887CA38(Snd *s);
static __inline u32 svec_size(SVec *v) { return v->end - v->begin; }
static __inline Slot **svec_at(SVec *v, u32 i) { return &v->begin[i]; }
static __inline u32 pvec_size(PVec *v) { return v->end - v->begin; }
static __inline Snd **pvec_at(PVec *v, u32 i) { return &v->begin[i]; }
void fn_888C99E0(O *o, u32 i)
{
    if (i < svec_size(&o->slots)) (*svec_at(&o->slots, i))->v = 0;
    if (i < pvec_size(&o->snds)) fn_8887CA38(*pvec_at(&o->snds, i));
    o->dirty = 1;
    o->dirty2 = 1;
}
