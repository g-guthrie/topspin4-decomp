/* Loader_DLL.xex 0x832881F0-0x8328B1B3, executable version 0.0.0.3.
 * Handle-pool destructors: drain the free list through the owner's
 * callback, release both arrays and the lock, then free the pool. */

typedef struct { int *data; unsigned cap; unsigned size; } Vec;
typedef struct { void *lock; Vec a; Vec b; int x1c; unsigned x20; void *owner; } Obj;

extern void ts4_if_get_u32_off3c_8328B5B8(void *, unsigned);
extern void ts4_tailcall_fn_832863B0_8328B5B0(void *, unsigned);
extern void ts4l_if_call_seq_u32_off0_8333E5D8(void *);
extern void ts4_tailcall_fn_8340D830_832863B0(void *);
extern void ts4_fn_8328B3F0(void *, void *);
extern void fn_833E74C0(void *);

#ifdef _MSC_VER
#define TS4L_INLINE static __forceinline
#else
#define TS4L_INLINE static inline
#endif

TS4L_INLINE unsigned vpop(Vec *v)
{
    unsigned r;
    if (v->size == 0)
        return 0;
    v->size--;
    r = (unsigned)v->data[v->size];
    v->data[v->size] = 0;
    return r;
}

void ts4l_pool_destroy_832881F0(Obj *o)
{
    unsigned e;
    if (o == 0)
        return;
    if (o->x1c != -1) {
        e = vpop(&o->a);
        vpop(&o->b);
        while (e != 0) {
            ts4_if_get_u32_off3c_8328B5B8((char *)o->owner + 8, e);
            e = vpop(&o->a);
            vpop(&o->b);
        }
    }
    ts4l_if_call_seq_u32_off0_8333E5D8(&o->a);
    ts4l_if_call_seq_u32_off0_8333E5D8(&o->b);
    if (o->lock != 0) {
        ts4_tailcall_fn_8340D830_832863B0(o->lock);
        o->lock = 0;
    }
    ts4_fn_8328B3F0((char *)o->owner + 8, o);
    fn_833E74C0(o);
}

void ts4l_pool_destroy_832888F8(Obj *o)
{
    unsigned e;
    if (o == 0)
        return;
    if (o->x1c != -1) {
        e = vpop(&o->a);
        vpop(&o->b);
        while (e != 0) {
            ts4_if_get_u32_off3c_8328B5B8((char *)o->owner + 8, e);
            e = vpop(&o->a);
            vpop(&o->b);
        }
    }
    ts4l_if_call_seq_u32_off0_8333E5D8(&o->a);
    ts4l_if_call_seq_u32_off0_8333E5D8(&o->b);
    if (o->lock != 0) {
        ts4_tailcall_fn_8340D830_832863B0(o->lock);
        o->lock = 0;
    }
    ts4_fn_8328B3F0((char *)o->owner + 8, o);
    fn_833E74C0(o);
}

void ts4l_pool_destroy_83288FD8(Obj *o)
{
    unsigned e;
    if (o == 0)
        return;
    if (o->x1c != -1) {
        e = vpop(&o->a);
        vpop(&o->b);
        while (e != 0) {
            ts4_tailcall_fn_832863B0_8328B5B0((char *)o->owner + 8, e);
            e = vpop(&o->a);
            vpop(&o->b);
        }
    }
    ts4l_if_call_seq_u32_off0_8333E5D8(&o->a);
    ts4l_if_call_seq_u32_off0_8333E5D8(&o->b);
    if (o->lock != 0) {
        ts4_tailcall_fn_8340D830_832863B0(o->lock);
        o->lock = 0;
    }
    ts4_fn_8328B3F0((char *)o->owner + 8, o);
    fn_833E74C0(o);
}

void ts4l_pool_destroy_832896C0(Obj *o)
{
    unsigned e;
    if (o == 0)
        return;
    if (o->x1c != -1) {
        e = vpop(&o->a);
        vpop(&o->b);
        while (e != 0) {
            ts4_tailcall_fn_832863B0_8328B5B0((char *)o->owner + 8, e);
            e = vpop(&o->a);
            vpop(&o->b);
        }
    }
    ts4l_if_call_seq_u32_off0_8333E5D8(&o->a);
    ts4l_if_call_seq_u32_off0_8333E5D8(&o->b);
    if (o->lock != 0) {
        ts4_tailcall_fn_8340D830_832863B0(o->lock);
        o->lock = 0;
    }
    ts4_fn_8328B3F0((char *)o->owner + 8, o);
    fn_833E74C0(o);
}

void ts4l_pool_destroy_83289DA8(Obj *o)
{
    unsigned e;
    if (o == 0)
        return;
    if (o->x1c != -1) {
        e = vpop(&o->a);
        vpop(&o->b);
        while (e != 0) {
            ts4_if_get_u32_off3c_8328B5B8((char *)o->owner + 8, e);
            e = vpop(&o->a);
            vpop(&o->b);
        }
    }
    ts4l_if_call_seq_u32_off0_8333E5D8(&o->a);
    ts4l_if_call_seq_u32_off0_8333E5D8(&o->b);
    if (o->lock != 0) {
        ts4_tailcall_fn_8340D830_832863B0(o->lock);
        o->lock = 0;
    }
    ts4_fn_8328B3F0((char *)o->owner + 8, o);
    fn_833E74C0(o);
}
