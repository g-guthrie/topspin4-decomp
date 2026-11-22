/* Q5 gameplay: current-node swap (0x88886458) and the dirty-disc pad thread (0x888BFC20).
 * Both byte-match with the default flags. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define Q5_NORETURN __declspec(noreturn)
#else
#define Q5_NORETURN __attribute__((noreturn))
#endif

/* ---- 0x88886458: install a new current node. The old node is returned when it
 * is ready; otherwise it is handed back to the manager. Both selections reset. */
typedef struct Q5Node { u8 b0; u8 ready; } Q5Node;
typedef struct Q5NodeOwner {
    char pad0[0xc];
    Q5Node *cur;        /* +0x0c */
    char pad10[8];
    void *mgr;          /* +0x18 */
    char pad1c[0x250 - 0x1c];
    int sel0;           /* +0x250 */
    int sel1;           /* +0x254 */
} Q5NodeOwner;
extern u32 ts4_get_u32_off148c_88614300(void *mgr, Q5Node *n);

Q5Node *ts4_node_swap_88886458(Q5NodeOwner *o, Q5Node *next)
{
    Q5Node *n = o->cur;
    Q5Node *res = 0;
    if (n) {
        if (n->ready)
            res = n;
        else
            ts4_get_u32_off148c_88614300(o->mgr, n);
    }
    o->cur = next;
    o->sel0 = -1;
    o->sel1 = -1;
    return res;
}

/* ---- 0x888BFC20: thread body started by 0x888C2290. Finds the first of the
 * first three controllers that answers XamInputGetState and shows the
 * dirty-disc error UI for it (0x8857A700 does not return); with none, it calls
 * 0x885827E0(0) and exits with 0. */
typedef struct Q5PadState { u32 w[4]; } Q5PadState;
extern u32 ts4_tailcall_XamInputGetState_8857B170(u32 user, Q5PadState *state);
extern Q5_NORETURN void fn_8857A700(u32 user);
extern void ts4_tailcall_fn_885827E0_88563110(u32 code);

u32 ts4_dirty_disc_thread_888BFC20(void)
{
    u32 i;
    Q5PadState st;
    for (i = 0; i < 3; i++) {
        if (ts4_tailcall_XamInputGetState_8857B170(i, &st) == 0)
            fn_8857A700(i);
    }
    ts4_tailcall_fn_885827E0_88563110(0);
    return 0;
}
