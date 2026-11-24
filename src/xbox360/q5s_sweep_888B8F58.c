/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x888B8F58: bind the handle, then read its 0xFE11D138 child into +0x34.
 * Body unchanged from the equivalent-tier source named below (Q5S sweep, 2026-11-24): byte-exact now, see
 * work/specs/Q5S/sweep_888B8F58.json for route and flags. */
/* from eq_q5_gameplay_small_d.c */
typedef unsigned int u32;
/* 12-byte xdata handle passed by value (GPR pair). */
typedef struct Q5Handle { void *tree; u32 node_id; u32 extra; } Q5Handle;
extern void *fn_88627EC0(void *object, Q5Handle h);
extern Q5Handle *ts4_handle_forward_88150770(Q5Handle *out, Q5Handle *handle, u32 *type_hash);
extern void fn_881895D0(u32 *out, Q5Handle h);
typedef struct Q5HBind34 { char pad[0x34]; u32 value; } Q5HBind34;

void ts4_bind_read_fe11d138_888B8F58(Q5HBind34 *self, Q5Handle h)
{
    Q5Handle child;
    u32 key;
    u32 v;
    fn_88627EC0(self, h);
    key = 0xfe11d138;
    ts4_handle_forward_88150770(&child, &h, &key);
    v = 0;
    fn_881895D0(&v, child);
    self->value = v;
}
