/* 0x883E42E0: if active (+8), returns the error from vtable slot 1 of the device at +0x10, else 0. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare. */
struct Dev;
typedef struct DVT { int (*s[2])(struct Dev *d); } DVT;
typedef struct Dev { DVT *vt; } Dev;
typedef struct T { char pad[8]; void *active; char pad2[4]; Dev *dev; } T;
int ts4_dev_call_slot1_883E42E0(T *t)
{
    if (t->active) {
        int r = t->dev->vt->s[1](t->dev);
        if (r)
            return r;
    }
    return 0;
}
