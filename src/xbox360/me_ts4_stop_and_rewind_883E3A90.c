/* 0x883E3A90: when active (+5): queries the position (+0x10) from the handle at +8 (0x5F if none), resets it to {0,0} */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); then calls fn_883FBB88 with +0xC and clears active; returns the first error. */
typedef struct Pos { int lo, hi; } Pos;
typedef struct T { char f0[5]; unsigned char active; char pad[2]; void *h; int arg; Pos pos; } T;
int fn_883FBEB0(void *h, Pos *pos);
int ts4_tailcall_fn_883FBB88_883FBFB0(void *h, int arg);
int ts4_stop_and_rewind_883E3A90(T *t)
{
    int r;
    if (t->active) {
        Pos z;
        if (!t->h)
            return 0x5f;
        r = fn_883FBEB0(t->h, &t->pos);
        if (r)
            return r;
        z.lo = 0;
        z.hi = 0;
        t->pos = z;
        r = ts4_tailcall_fn_883FBB88_883FBFB0(t->h, t->arg);
        if (r)
            return r;
        t->active = 0;
    }
    return 0;
}
