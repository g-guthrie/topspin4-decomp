/* 0x888DA698: reset: clear the vector at +0x160 (erase(begin,end) via copy), reset four 0x30-byte sub-blocks, zero +0x60 and, when bound, the six external counters (agAY). Plain /Oc; Vec* local gives the dead addi. */
typedef unsigned char u8;
typedef struct Sub30 { u8 p[0x30]; } Sub30;
typedef struct Vec { void *first; void *last; } Vec;
typedef struct Obj {
    u8 pad0[0x28]; int *p28; int *p2c; int *p30; int *p34; u8 pad38[8]; int *p40; u8 pad44[8]; int *p4c;
    u8 pad50[0x10]; int x60; int pad64; Sub30 s[4]; u8 pad128[0x38]; Vec v;
} Obj;
void *fn_881A9BE8(void *first, void *last, void *dest);
void ts4_if_call_seq_u32_off18_888D7480(Sub30 *s);
void ts4_block_reset_888DA698(Obj *o)
{
    Vec *v = &o->v;
    v->last = fn_881A9BE8(v->last, v->last, v->first);
    ts4_if_call_seq_u32_off18_888D7480(&o->s[0]);
    ts4_if_call_seq_u32_off18_888D7480(&o->s[1]);
    ts4_if_call_seq_u32_off18_888D7480(&o->s[2]);
    ts4_if_call_seq_u32_off18_888D7480(&o->s[3]);
    o->x60 = 0;
    if (o->p30) {
        *o->p30 = 0; *o->p34 = 0; *o->p4c = 0; *o->p28 = 0; *o->p2c = 0; *o->p40 = 0;
    }
}
