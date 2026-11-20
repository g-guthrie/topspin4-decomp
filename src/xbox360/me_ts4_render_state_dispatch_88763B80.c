/* 0x88763B80: under the renderer lock (lbl_88D45A4C+0x154), dispatch the per-state update on o->state (+0x14c):
 * states 1-6 have their own handler, state 7 does nothing, state 0 and unknown states run the fallback. */
typedef unsigned int u32;
extern char *lbl_88D45A4C;
typedef struct Lk { void **vt; } Lk;
typedef void (*LkFn)(void *);
extern void fn_8874E088(void *o, void *a); extern void fn_88761C68(void *o, void *a); extern void fn_8871E100(void *o, void *a);
extern void fn_8871DF58(void *o, void *a); extern void fn_8871DDB8(void *o, void *a); extern void fn_8871DB88(void *o, void *a);
extern void fn_88755480(void *o, void *a);
void ts4_render_state_dispatch_88763B80(char *o, void *a)
{
    Lk *lk = (Lk *)(lbl_88D45A4C + 0x154);
    ((LkFn)lk->vt[1])(lk);
    switch (*(u32 *)(o + 0x14c)) {
    case 0: fn_88755480(o, a); break;
    case 1: fn_8874E088(o, a); break;
    case 2: fn_88761C68(o, a); break;
    case 3: fn_8871E100(o, a); break;
    case 4: fn_8871DF58(o, a); break;
    case 5: fn_8871DDB8(o, a); break;
    case 6: fn_8871DB88(o, a); break;
    case 7: break;
    default: fn_88755480(o, a); break;
    }
    ((LkFn)lk->vt[2])(lk);
}
