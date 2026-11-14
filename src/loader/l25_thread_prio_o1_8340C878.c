/* Loader_DLL.xex 0x8340C878-0x8340C978, 0x8340CC00-0x8340CC70, executable version 0.0.0.3. */
/* Kernel thread helpers (Win32-style wrappers over NT objects): set/get base priority with the +-15 to +-16 mapping, and a thread link check. */
typedef unsigned long ts4l_u32;

extern int ts4l_import_ObReferenceObjectByHandle_83517548(ts4l_u32 handle, ts4l_u32 type, void *object);
extern void ts4l_import_ObDereferenceObject_83517568(void *object);
extern int ts4l_import_KeSetBasePriorityThread_83517508(void *thread, int priority);
extern int ts4l_import_KeQueryBasePriorityThread_83517AD8(void *thread);
extern void ts4_tailcall_fn_8340F088_834141B8(int status);
extern char __imp_ExThreadObjectType[];

typedef struct { char pad[0x154]; void *link; } Ts4lKThread;

/* SetThreadPriority: 15 and -15 (time critical / idle) map to the kernel's 16 and -16. */
int ts4l_set_thread_priority_8340C878(ts4l_u32 handle, int prio)
{
    void *t;
    int p;
    int st = ts4l_import_ObReferenceObjectByHandle_83517548(handle, *(ts4l_u32 *)__imp_ExThreadObjectType, &t);
    if (st >= 0) {
        p = prio;
        if (p == 15) p = 16;
        else if (p == -15) p = -16;
        ts4l_import_KeSetBasePriorityThread_83517508(t, p);
        ts4l_import_ObDereferenceObject_83517568(t);
        return 1;
    }
    ts4_tailcall_fn_8340F088_834141B8(st);
    return 0;
}

/* GetThreadPriority: inverse mapping, THREAD_PRIORITY_ERROR_RETURN (0x7fffffff) on failure. */
int ts4l_get_thread_priority_8340C8F8(ts4l_u32 handle)
{
    void *t;
    int p;
    int q;
    int r;
    int st = ts4l_import_ObReferenceObjectByHandle_83517548(handle, *(ts4l_u32 *)__imp_ExThreadObjectType, &t);
    if (st >= 0) {
        q = ts4l_import_KeQueryBasePriorityThread_83517AD8(t);
        p = q;
        if (p == 16) p = 15;
        else if (p == -16) p = -15;
        r = p;
        ts4l_import_ObDereferenceObject_83517568(t);
        return r;
    }
    ts4_tailcall_fn_8340F088_834141B8(st);
    return 0x7fffffff;
}

/* Report whether the thread's list link points anywhere other than at itself. */
int ts4l_thread_link_set_8340CC00(ts4l_u32 handle, int *out)
{
    Ts4lKThread *t;
    int st = ts4l_import_ObReferenceObjectByHandle_83517548(handle, *(ts4l_u32 *)__imp_ExThreadObjectType, &t);
    if (st >= 0) {
        *out = t->link != &t->link;
        ts4l_import_ObDereferenceObject_83517568(t);
        return 1;
    }
    ts4_tailcall_fn_8340F088_834141B8(st);
    return 0;
}
