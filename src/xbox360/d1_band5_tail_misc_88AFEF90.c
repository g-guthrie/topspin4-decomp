/* Swing_DLL.xex 0x88AFEF90-0x88AFF4B8, executable version 0.0.0.3. */
typedef struct Ts4Guarded {
    void *vtable;
    char critical_section[0x24];
    int first;
    int second;
} Ts4Guarded;

typedef struct Ts4Holder {
    void *vtable;
    void *held;
} Ts4Holder;

extern Ts4Guarded lbl_88C6D960;
extern char lbl_880D19F0[];
extern Ts4Holder lbl_88D4AB10;
extern char lbl_880DCF20[];

extern void RtlEnterCriticalSection(void *section);
extern void RtlLeaveCriticalSection(void *section);
extern void fn_8816B1C8(int first, int second, char flag);
extern void fn_8857A1E0(void *held);

#if 0
static void ts4_clear_flag(char *flag)
{
    *flag = 0;
}

void ts4_guarded_reset_88AFEF90(void)
{
    char flag;

    RtlEnterCriticalSection(lbl_88C6D960.critical_section);
    ts4_clear_flag(&flag);
    fn_8816B1C8(lbl_88C6D960.first, lbl_88C6D960.second, flag);
    RtlLeaveCriticalSection(lbl_88C6D960.critical_section);
    lbl_88C6D960.vtable = lbl_880D19F0;
}
#endif

void ts4_holder_destroy_88AFF060(void)
{
    lbl_88D4AB10.vtable = lbl_880DCF20;
    if (lbl_88D4AB10.held != 0) {
        fn_8857A1E0(lbl_88D4AB10.held);
        lbl_88D4AB10.held = 0;
    }
}

#if 0
typedef struct Ts4Releasable Ts4Releasable;
typedef struct Ts4ReleasableVtable {
    void *slots[2];
    void (*release)(void *owner);
} Ts4ReleasableVtable;
struct Ts4Releasable {
    Ts4ReleasableVtable **owner;
    void *reserved[2];
    volatile long count;
};

extern Ts4Releasable *lbl_88D4D8E4;

extern long _InterlockedDecrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement)
#endif

void ts4_release_shared_88AFF268(void)
{
    Ts4Releasable *shared = (Ts4Releasable *)((char *)lbl_88D4D8E4 - 0x10);

    if (!_InterlockedDecrement(&shared->count)) {
        (*shared->owner)->release(shared->owner);
    }
}
#endif

typedef struct Ts4Pending {
    void *item;
    int reserved;
    int extra;
} Ts4Pending;

extern Ts4Pending lbl_88D492B0;
extern void *lbl_88D45B38;
extern void ts4_if_call_seq_fn_881F04B8_886131F0(void *owner, void *item, int extra);
extern void fn_885651F8(void *item);

void ts4_flush_pending_88AFF328(void)
{
    if (lbl_88D492B0.item == 0) {
        return;
    }
    if (lbl_88D45B38 != 0) {
        ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, lbl_88D492B0.item, lbl_88D492B0.extra);
        return;
    }
    fn_885651F8(lbl_88D492B0.item);
}

typedef struct Ts4BigBlock {
    void *vtable;
    char reserved0[0x55c0 - 4];
    char member_a[0x468];
    void *member_vtable;
    char reserved1[0x5ffc - 0x5a28 - 4];
    char member_b[4];
} Ts4BigBlock;

extern Ts4BigBlock lbl_88C6E268;
extern char lbl_88028D18[];
extern char lbl_88028B5C[];
extern char lbl_880C1320[];
extern void ts4_addr_lbl_880292C8_8832E758(void *member);
extern void ts4_if_call_seq_u32_off4_88316460(void *member, void *name, int flags);
