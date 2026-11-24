/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x886DC610: forward a pending entry to 0x886DBF40, then remove it from the 0x98-byte pending vector by
 * moving the last entry into its place (pop_back).
 * Body unchanged from the equivalent-tier source named below (Q5S sweep, 2026-11-24): byte-exact now, see
 * work/specs/Q5S/sweep_886DC610.json for route and flags. */
/* from eq_q5_gameplay_small_e.c */
typedef unsigned int u32;
typedef struct Q5Pend98 { char b[0x98]; } Q5Pend98;
typedef struct Q5PendItem { u32 w0; u32 w4; } Q5PendItem;
typedef struct Q5PendSrc { u32 w0; Q5PendItem *item; } Q5PendSrc;
typedef struct Q5PendCfgC { char pad[0xc]; char *pc; } Q5PendCfgC;
typedef struct Q5PendCfg40 { char pad[0x40]; u32 w40; } Q5PendCfg40;
typedef struct Q5PendEnv {
    char pad0[0x10];
    Q5PendCfg40 *cfg;   /* +0x10 */
    char pad14[4];
    Q5PendCfgC *cfg_c;  /* +0x18 */
    char pad1c[0x28c - 0x1c];
    u32 w28c;           /* +0x28c */
} Q5PendEnv;
typedef struct Q5PendList { char pad0[8]; Q5PendEnv *env; char padc[8]; Q5Pend98 *end; } Q5PendList;
extern void fn_886DBF40(void *a, u32 b, void *c, u32 d, int e, u32 f);
extern void ts4_shot_rec_copy_886C6660(Q5Pend98 *dst, const Q5Pend98 *src);

void ts4_pending_take_886DC610(Q5PendList *self, Q5Pend98 *entry)
{
    Q5PendEnv *env = self->env;
    Q5PendItem *it = ((Q5PendSrc *)entry)->item;
    Q5Pend98 *last;
    fn_886DBF40(&it->w4, it->w4, env->cfg_c->pc + 0x60, env->cfg->w40, -1, env->w28c);
    last = self->end - 1;
    if (entry != last)
        ts4_shot_rec_copy_886C6660(entry, last);
    self->end = last;
}
