/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l25_thread_prio_o1_8340C878.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Kernel thread helpers (Win32-style wrappers over NT objects): set/get base priority with the +-15 to +-16 mapping, and a thread link check. */
typedef unsigned long ts4_u32;

typedef struct { char pad[0x154]; void *link; } Ts4lKThread;

/* SetThreadPriority: 15 and -15 (time critical / idle) map to the kernel's 16 and -16. */

/* GetThreadPriority: inverse mapping, THREAD_PRIORITY_ERROR_RETURN (0x7fffffff) on failure. */

/* Report whether the thread's list link points anywhere other than at itself. */

extern int ObReferenceObjectByHandle(ts4_u32 handle, ts4_u32 type, void *object);
extern void ObDereferenceObject(void *object);
extern int KeSetBasePriorityThread(void *thread, int priority);
extern void ts4_forward_record_status(int status);
extern char __imp_ExThreadObjectType[];
extern int KeQueryBasePriorityThread(void *thread);

/* Swing_DLL.xex 0x8857B3C8 */
int ts4_set_thread_priority_8857B3C8(ts4_u32 handle, int prio)
{
    void *t;
    int p;
    int st = ObReferenceObjectByHandle(handle, *(ts4_u32 *)__imp_ExThreadObjectType, &t);
    if (st >= 0) {
        p = prio;
        if (p == 15) p = 16;
        else if (p == -15) p = -16;
        KeSetBasePriorityThread(t, p);
        ObDereferenceObject(t);
        return 1;
    }
    ts4_forward_record_status(st);
    return 0;
}

/* Swing_DLL.xex 0x8857B448 */
int ts4_get_thread_priority_8857B448(ts4_u32 handle)
{
    void *t;
    int p;
    int q;
    int r;
    int st = ObReferenceObjectByHandle(handle, *(ts4_u32 *)__imp_ExThreadObjectType, &t);
    if (st >= 0) {
        q = KeQueryBasePriorityThread(t);
        p = q;
        if (p == 16) p = 15;
        else if (p == -16) p = -15;
        r = p;
        ObDereferenceObject(t);
        return r;
    }
    ts4_forward_record_status(st);
    return 0x7fffffff;
}

