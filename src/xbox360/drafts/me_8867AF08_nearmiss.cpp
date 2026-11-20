/* near-miss 0x8867AF08 (C++ route, /Oc): 79 instructions off, size 0x178 vs 0x184. Open: key copy through stack temp, loop shape. */
/* 0x8867AF08: fills the shot-info block (hash key, flags, timing) and picks the curve segment index for the current time. */
typedef unsigned int u32;
typedef struct ShotSeg { char p[0x14]; int t_end; char p2[0x1c - 0x18]; } ShotSeg;
typedef struct ShotCurve { int seg_off; int count; } ShotCurve;
struct ShotKey { u32 h; ShotKey() {} ShotKey(u32 v) : h(v) {} ShotKey &operator=(const ShotKey &o) { h = o.h; return *this; } };
typedef struct ShotInfo {
    char p[0xe0]; ShotKey key; int time; int seg; char p2[0xf0 - 0xec]; int a24; int a2c;
    unsigned char active; unsigned char is_a; unsigned char is_b; unsigned char flag; unsigned char clear;
} ShotInfo;
typedef struct ShotDesc { char p[0xc]; u32 kind; u32 sub; char p2[0x24 - 0x14]; int a24; char p3[0x2c - 0x28]; int a2c; } ShotDesc;
typedef struct Table_881BBFF8 Table_881BBFF8;
typedef struct ShotBank { char p[0x2c]; char *tables; } ShotBank;
typedef struct ShotState {
    char p[0x20]; u32 type; int time; ShotDesc *desc; char p2[0x40 - 0x2c]; unsigned char *flag;
    char p3[0x48 - 0x44]; ShotBank *bank; char p4[0x78 - 0x4c]; ShotInfo *info;
} ShotState;
extern "C" void *ts4_find_record_by_key_881BBFF8(Table_881BBFF8 *self, const u32 *key);
extern "C" void fn_8867AF08(ShotState *s)
{
    ShotCurve *c;
    s->info->active = 1;
    if (s->type == 0xF5BF4F97u) s->info->key = ShotKey(0x3583143Cu); else s->info->key = ShotKey(0xDDDB885Du);
    s->info->is_a = (0xDA554856u - s->desc->kind) == 0;
    s->info->time = s->time;
    s->info->flag = *s->flag;
    s->info->clear = 0;
    s->info->is_b = (0x93F7AFC2u - s->desc->sub) == 0;
    s->info->a24 = s->desc->a24;
    s->info->a2c = s->desc->a2c;
    s->info->seg = 0;
    c = (ShotCurve *)ts4_find_record_by_key_881BBFF8((Table_881BBFF8 *)(s->bank->tables + 0xac), &s->info->key.h);
    if (c) {
        int i = 0;
        int n = c->count;
        int t = s->time;
        for (; i < n; i++) {
            ShotSeg *e = (ShotSeg *)((char *)c + c->seg_off) + i;
            if (t <= e->t_end) break;
        }
        if (i == n) i--;
        s->info->seg = i;
    }
}
