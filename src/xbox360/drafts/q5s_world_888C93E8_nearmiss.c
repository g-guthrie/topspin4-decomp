/* nearmiss: 2 off (plain and LTCG); the f8c float store and the 0xD2C0AEC0 word store at +0xb8 are swapped. Everything
 * else is solved: `one` is loaded right after the +0x38 byte store, the f98 floats go through two non-inline set3 calls
 * (which stops the int/float store interleave), store orders of the +0x88..+0xbd block (120 perms), set2 helpers, int-store
 * through a float field all stay at 2. */
/* 0x888C93E8: reset: stamp +0x1c from the engine (+0x27c), trim the two 12-byte vectors (+0x20, +0x2c), clear flags and
 * counters, set eight floats to lbl_8814B440 and +0xb8 to 0xD2C0AEC0. */
typedef unsigned char u8; typedef unsigned int u32;
typedef struct Vec12 { void *first; void *last; void *end; } Vec12;
typedef struct Svc { char p[0x27c]; u32 now; } Svc;
extern Svc *lbl_88D45B1C;
extern const float lbl_8814B440;
void ts4_vec12_move_tail_88161620(Vec12 *v);
typedef struct T {
 char p0[0x1c]; u32 stamp; Vec12 a; Vec12 b; u8 b38; char p39[3]; u32 w3c; char p40[0x40];
 u32 w80; u32 w84; float f88; float f8c; float f90; float f94; float f98[6]; u32 wb0; u32 wb4; u32 wb8; u8 bbc; u8 bbd; char pbe[2]; u32 wc0; u32 wc4;
} T;
static void set3(float *p, float a, float b, float c){ p[0] = a; p[1] = b; p[2] = c; }
static __inline void set3i(float *p, float a, float b, float c){ p[0] = a; p[1] = b; p[2] = c; }
static void initb(u32 *p){ p[2] = 0xD2C0AEC0; ((u8 *)p)[0xc] = 0; ((u8 *)p)[0xd] = 0; p[0] = 0; p[1] = 0; }
void ts4_state_reset_888C93E8(T *t)
{
    float one;
    t->stamp = lbl_88D45B1C->now;
    ts4_vec12_move_tail_88161620(&t->a);
    ts4_vec12_move_tail_88161620(&t->b);
    t->b38 = 0;
    one = lbl_8814B440;
    t->w3c = 0;
    t->f90 = one;
    t->w80 = 0;
    t->f94 = one;
    t->w84 = 0;
    t->f88 = one;
    t->f8c = one;
t->wb8 = 0xD2C0AEC0; t->bbc = 0; t->bbd = 0; t->wb0 = 0; t->wb4 = 0; set3(&t->f98[0], one, one, one); set3(&t->f98[3], one, one, one); t->wc0 = 0; t->wc4 = 0;
}
