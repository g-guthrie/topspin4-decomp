
typedef unsigned int u32;
typedef struct Slot { u32 handle; u32 b; char pad[0x200]; } Slot;
extern int lbl_88D4BD18;
extern u32 lbl_88D45A80;
extern Slot lbl_88D3EB60[25];
extern char lbl_880F0A98[];
extern int ts4_if_call_seq_u32__imp_ExThreadObjectType_8857B508(u32 h, u32 *code);
extern void ts4_if_get_u32_lbl_88C32048_8857A1E0(u32 h);
extern u32 ts4_loop_call_seq_fn_88563230_88884B20(void *start, void *param, void *name, u32 stack);
extern void fn_8857B598(u32 h, int pri);
extern u32 ts4_fn_886EBD98(void *p);
/* 0x886F54D8: store the worker parameter; if a worker thread is still alive (exit code 0x103 STILL_ACTIVE) return 1, else release its slot and handle, start a new worker thread at priority 5 */
int ts4_restart_worker_thread_886F54D8(int v)
{
    int *g = &lbl_88D4BD18;
    u32 code;
    lbl_88D4BD18 = v;
    if (v == -1) return 0;
    if (lbl_88D45A80) {
        Slot *s;
        ts4_if_call_seq_u32__imp_ExThreadObjectType_8857B508(lbl_88D45A80, &code);
        if (code == 0x103) return 1;
        for (s = lbl_88D3EB60; s != lbl_88D3EB60 + 25; s++) {
            if (lbl_88D45A80 == s->handle) {
                s->handle = 0;
                s->b = 0;
                break;
            }
        }
        ts4_if_get_u32_lbl_88C32048_8857A1E0(lbl_88D45A80);
    }
    *g = v;
    lbl_88D45A80 = ts4_loop_call_seq_fn_88563230_88884B20(ts4_fn_886EBD98, g, lbl_880F0A98, 0x20000);
    fn_8857B598(lbl_88D45A80, 5);
    return 0;
}
