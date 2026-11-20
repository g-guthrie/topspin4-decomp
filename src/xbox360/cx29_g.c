/* Swing_DLL.xex game core 0x8818C6C0-0x8819C000 (CW29): allocator wrappers under the optional pool lock. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
typedef unsigned int cx_uptr;
#else
typedef unsigned long cx_uptr;
#endif
cx_uptr RtlEnterCriticalSection(cx_uptr);
cx_uptr RtlLeaveCriticalSection(cx_uptr);
#ifdef _MSC_VER
#pragma function(memcpy)
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

/* 0x881986C8: reallocate a block: allocate the new size through the vtable, copy the smaller extent, free the old */
struct cx_avt { void *s[5]; void *(*alloc)(void *self, u32 n, u32 flags); void (*free)(void *self, void *p); };
struct cx_aobj { struct cx_avt *vt; u8 pad[0x70]; int lockv; };
void *ts4_realloc_881986C8(struct cx_aobj *self, void *p, u32 newsize, u32 flags)
{
    int lockv;
    u8 *cs;
    u32 old;
    void *n;
    if (p == 0)
        return self->vt->alloc(self, newsize, flags);
    if (newsize == 0) {
        self->vt->free(self, p);
        return 0;
    }
    lockv = self->lockv;
    cs = (u8 *)self + 0x98;
    if (lockv == -1)
        RtlEnterCriticalSection((cx_uptr)(cs + 8));
    old = ((u32 *)p)[-2];
    if (old == newsize) {
        if (lockv == -1)
            RtlLeaveCriticalSection((cx_uptr)(cs + 8));
        return p;
    }
    n = self->vt->alloc(self, newsize, flags);
    memcpy(n, p, old < newsize ? old : newsize);
    self->vt->free(self, p);
    if (lockv == -1)
        RtlLeaveCriticalSection((cx_uptr)(cs + 8));
    return n;
}

/* 0x88190B90: look the named entry up through the global registry and run it under its saved state; true on success */
struct cx_sa_vt { void *s[4]; void *(*alloc)(void *self); };
struct cx_sa { struct cx_sa_vt *vt; };
struct cx_reg_vt { void *s0; void (*resolve)(void *self, char **name, char **a, char **b); };
struct cx_reg { struct cx_reg_vt *vt; };
struct cx_ent { u8 pad[4]; void *f4; };
struct cx_flagobj { u8 pad[0xc]; u8 f0c; };
extern struct cx_reg *lbl_88D3E37C;
struct cx_sa *fn_881519D0(void);
void ts4_assign_text_from_c_string(char **dst, const char *src);
void ts4_call_seq_u32_off0_8819AD80(char **s);
struct cx_ent *fn_8818F948(void *reg, char **a, u32 z);
u32 fn_88198CE0(void *);
u8 ts4_locked_try_8818DDB8(void *e, char **b, void *self);
u8 ts4_locked_call_8818E3F0(void *e, char **b, void *self);
u32 ts4_registry_run_88190B90(struct cx_flagobj *self, const char *name, u32 flags)
{
    struct cx_reg *reg = lbl_88D3E37C;
    char *a, *b, *tmp;
    struct cx_ent *e;
    u32 saved;
    u32 r;
    if (reg == 0)
        return 0;
    {
        struct cx_sa *o = fn_881519D0();
        a = (char *)o->vt->alloc(o) + 0x10;
    }
    {
        struct cx_sa *o = fn_881519D0();
        b = (char *)o->vt->alloc(o) + 0x10;
    }
    ts4_assign_text_from_c_string(&tmp, name);
    reg->vt->resolve(reg, &tmp, &a, &b);
    ts4_call_seq_u32_off0_8819AD80(&tmp);
    self->f0c = 0;
    e = fn_8818F948(reg, &a, 0);
    if (e == 0) {
        ts4_call_seq_u32_off0_8819AD80(&b);
        ts4_call_seq_u32_off0_8819AD80(&a);
        return 0;
    }
    saved = fn_88198CE0(e->f4);
    if ((flags & 0x1000) != 0)
        r = ts4_locked_try_8818DDB8(e, &b, self);
    else
        r = ts4_locked_call_8818E3F0(e, &b, self);
    fn_88198CE0((void *)(cx_uptr)saved);
    ts4_call_seq_u32_off0_8819AD80(&b);
    ts4_call_seq_u32_off0_8819AD80(&a);
    return r;
}
