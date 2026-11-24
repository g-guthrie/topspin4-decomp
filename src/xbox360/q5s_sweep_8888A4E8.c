/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8888A4E8: start the worker: clear state, create its event (0x8857B6D8), spawn the thread on fn_88889D20
 * with a 128 KB stack, set it to processor 4 (0x8857B598), then resume it.
 * Body unchanged from the equivalent-tier source named below (Q5S sweep, 2026-11-24): byte-exact now, see
 * work/specs/Q5S/sweep_8888A4E8.json for route and flags. */
/* from eq_q5_gameplay_small_e.c */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Q5Worker { u32 thread; u32 event; u32 w8; u8 bc; char padd[7]; u8 b14; } Q5Worker;
extern u32 fn_8857B6D8(u32 a, u32 b, u32 c, u32 d);
extern char lbl_880DF04C[];
extern void fn_88889D20(void);
extern u32 ts4_loop_call_seq_fn_88563230_88884B20(void *fn, void *arg, void *name, u32 stack);
extern void fn_8857B598(u32 thread, u32 processor);
extern void ts4_resume_thread(u32 thread);

void ts4_worker_start_8888A4E8(Q5Worker *w)
{
    u32 t;
    w->w8 = 0;
    w->bc = 0;
    w->b14 = 0;
    w->event = fn_8857B6D8(0, 0, 0, 0);
    t = ts4_loop_call_seq_fn_88563230_88884B20((void *)fn_88889D20, w, lbl_880DF04C, 0x20000);
    w->thread = t;
    fn_8857B598(t, 4);
    ts4_resume_thread(w->thread);
}
