
typedef unsigned int u32; typedef unsigned char u8;
typedef struct { float x, y, z; } V3;
typedef struct { char pad[0x40]; float t; } X20;
typedef struct { char pad[0x20]; X20 *x20; } X5C;
typedef struct { char pad[0x328]; u8 b328; } X30;
typedef struct { char pad[0x30]; X30 *x30; char p34[0x5c-0x34]; X5C *x5c; } X48;
typedef struct { char pad[0x2c]; int mode; } X4C;
typedef struct { char pad[0x1068]; u32 h; } X74;
typedef struct { char pad[0x48]; X48 *x48; X4C *x4c; char p50[0x74-0x50]; X74 *x74; } P;
typedef struct { char pad[0x1c]; P *p; } O;
extern u8 ts4_if_get_u32_off1c_8866BA40(O *o);
#include "vx1_vector.h"
extern __vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, P *p);
extern float g_ts4_script_constants[];
void ts4_select_approach_hash_886782D0(O *o) {
    P *p = o->p;
    u32 h;
    if (p->x4c->mode == 2) {
        if (ts4_if_get_u32_off1c_8866BA40(o)) h = 0xBF5D35B1; else h = 0xA4AAC6D8;
    } else if (p->x48->x30->b328) {
        float t = o->p->x48->x5c->x20->t;
        __vector4 v;
        u8 near = t < ((float *)ts4_if_get_u32_off4c_8865EC70(&v, o->p))[0] - g_ts4_script_constants[0x3c];
        X74 *d = p->x74;
        if (near) h = 0xD32429A6; else h = 0xA4AAC6D8;
        d->h = h;
        return;
    } else h = 0xA4AAC6D8;
    p->x74->h = h;
}
