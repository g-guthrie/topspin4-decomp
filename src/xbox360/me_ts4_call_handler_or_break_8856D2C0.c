/* 0x8856D2C0: calls the handler stored at lbl_88D2E598 (set by 8856D2B0) with five zero arguments, or hits a debug break when none is set. */
/* Matched on /O1 (agAB). The handler is read into a local (no clrrwi copy); the cr0 compare marks /O1. */
typedef int (*Fn)(int, int, int, int, int);
extern Fn lbl_88D2E598;
void fn_8856D2C0(void)
{
    Fn f = lbl_88D2E598;
    if (f)
        f(0, 0, 0, 0, 0);
    else
        __debugbreak();
}
