/* CW32 part c: async IO job launchers and enumerate/write result writers (Swing_DLL.xex 0x88886A14-0x88887800). Default flags. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#pragma intrinsic(strcpy)
void *memset(void *p, int c, unsigned int n);
#else
#include <string.h>
#endif

extern char lbl_880DEF64[];
extern char lbl_88D3EB60[];
extern void *lbl_88D45B38;
extern struct Cx32G { char pad[0x234]; void *tbl; } *lbl_88D45B1C;

void ts4_tsu_cleanup_end(void *p);
void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);
void ts4_if_get_u32_lbl_88C32048_8857A1E0(int h);
int ts4_loop_call_seq_fn_88563230_88884B20(void *fn, void *arg, void *name, u32 stack);
void ts4_if_call_seq_u32_off0_88886CB8(void *p);
void fn_888871D0(void *p);
void ts4_copy_bytes(void *dst, const void *src, u32 n);
void fn_88568BC0(void *dst, const void *src, u32 n);
void *ts4_pad_record_find_88614938(void *a, int b);
u32 ts4_tailcall_XamContentCreateEnumerator_8857B2F0(int id, int a, int b, int c, int d, int *e, int *f);
u32 ts4_tailcall_XamEnumerate_8857A1C8(int a, int b, int c, int *d, int e);
void ts4_tailcall_fn_885827E0_88563110(int a);
int ts4_tailcall_fn_88582660_8857B840(void);
int fn_8857B848(int a, u32 b, int c, int d, int e, int f, int g);
void fn_8857BD30(int h, int a, int b, int *out, int c);
int fn_8857B778(int a);
void ts4_tailcall_XamContentFlush_8857B2E0(int a, int b);

typedef struct Cx32Slot { u32 h; int v; char pad[0x200]; } Cx32Slot;
typedef struct Cx32Job { int f0; int f4; char pad[0x100]; char name[1]; } Cx32Job;
typedef struct Cx32Node { void *svc; void *out; void *name; Cx32Job *job; } Cx32Node;
typedef struct Cx32Svc { char pad[0x20]; int f20; char pad24[0x20]; int h44; long node48; } Cx32Svc;
typedef struct Cx32Out { char pad[8]; u8 b8; } Cx32Out;

/* job launcher: copy name into the job record, register a worker thread (0x88886D48) */
void ts4_start_job_with_name_88886D48(Cx32Svc *s, Cx32Out *o, Cx32Job *j, char *name)
{
    Cx32Node *node;
    void *m;
    int h;
    int f20 = s->f20;
    j->f4 = 1;
    j->f0 = f20;
    strcpy(j->name, name);
    if (s->node48) ts4_tsu_cleanup_end((void *)s->node48);
    m = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x10, 4, 0, 2);
    if (m) {
        ((Cx32Node *)m)->svc = s;
        node = (Cx32Node *)m;
        node->out = o;
    } else {
        node = 0;
    }
    s->node48 = (long)node;
    node->name = name;
    node->job = j;
    o->b8 = 0;
    h = s->h44;
    if (h != 0) {
        Cx32Slot *e = (Cx32Slot *)lbl_88D3EB60;
        do {
            if ((u32)h == e->h) { e->h = 0; e->v = 0; break; }
            e++;
        } while (e != (Cx32Slot *)(lbl_88D3EB60 + 0x32c8));
        ts4_if_get_u32_lbl_88C32048_8857A1E0(h);
    }
    s->h44 = ts4_loop_call_seq_fn_88563230_88884B20((void *)ts4_if_call_seq_u32_off0_88886CB8, node, lbl_880DEF64, 0x20000);
}

/* job launcher with two names and a label string (0x888872B8) */
typedef struct Cx32Node2 { void *svc; void *out; void *name; Cx32Job *job; void *n10; void *n14; int n18; } Cx32Node2;
void ts4_start_job_with_two_names_888872B8(Cx32Svc *s, Cx32Out *o, Cx32Job *j, char *name1, char *name2)
{
    Cx32Node2 *node;
    void *m;
    int h;
    char *label = (char *)s + 0x4d;
    memset(j, 0, 0x134);
    ts4_copy_bytes((char *)j + 0x108, name1, 0x29);
    fn_88568BC0((char *)j + 8, name2, 0x7f);
    if (s->node48) ts4_tsu_cleanup_end((void *)s->node48);
    m = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x1c, 4, 0, 2);
    if (m) {
        ((Cx32Node2 *)m)->svc = s;
        node = (Cx32Node2 *)m;
        node->out = o;
    } else {
        node = 0;
    }
    s->node48 = (long)node;
    node->job = j;
    node->name = label;
    node->n10 = name1;
    node->n14 = name2;
    node->n18 = 1;
    o->b8 = 0;
    h = s->h44;
    if (h != 0) {
        Cx32Slot *e = (Cx32Slot *)lbl_88D3EB60;
        do {
            if ((u32)h == e->h) { e->h = 0; e->v = 0; break; }
            e++;
        } while (e != (Cx32Slot *)(lbl_88D3EB60 + 0x32c8));
        ts4_if_get_u32_lbl_88C32048_8857A1E0(h);
    }
    s->h44 = ts4_loop_call_seq_fn_88563230_88884B20((void *)fn_888871D0, node, lbl_880DEF64, 0x20000);
}

/* enumerate content and report the result record (0x888876F0) */
typedef struct Cx32Hnd { char pad[0x10]; int id; } Cx32Hnd;
typedef struct Cx32Res { int w0; int w4; u8 b8; } Cx32Res;
typedef struct Cx32CtxB { char pad[0x1c]; int f1c; char pad2[0x230]; u32 *err; } Cx32CtxB;
typedef struct Cx32OpE { Cx32CtxB *c; Cx32Res *r; int f8; int fc; int f10; int f14; } Cx32OpE;
int ts4_enumerate_content_result_888876F0(Cx32OpE *t)
{
    int l50 = 0, l54 = 0, l58 = 0;
    int zero = 0;
    int one;
    u32 rc;
    int id;
    Cx32Hnd *hd = (Cx32Hnd *)ts4_pad_record_find_88614938(lbl_88D45B1C->tbl, t->c->f1c);
    id = hd ? hd->id : -1;
    rc = ts4_tailcall_XamContentCreateEnumerator_8857B2F0(id, t->f14, t->f10, 0, t->fc, &l54, &l50);
    one = 1;
    if (rc == 0) {
        rc = ts4_tailcall_XamEnumerate_8857A1C8(l50, t->f8, l54, &l58, 0);
        if (rc != 0 && rc != 0x12) {
            Cx32Res *rr = t->r;
            *t->c->err = 0x9C1C9375u;
            if (rr) rr->w0 = one;
        }
        if (rc == 0x12) rc = zero;
    }
    t->r->w0 = rc;
    t->r->w4 = l58;
    t->r->b8 = one;
    ts4_if_get_u32_lbl_88C32048_8857A1E0(l50);
    ts4_tailcall_fn_885827E0_88563110(0);
    return 0;
}

/* write files with a disk-full retry (0x88886E60) */
typedef struct Cx32Ctx { char pad[0x250]; u32 *err; } Cx32Ctx;
typedef struct Cx32OpF { Cx32Ctx *c; Cx32Res *r; u32 count; char names[0x14c8]; int fx14d4; } Cx32OpF;
int ts4_write_files_retry_88886E60(Cx32OpF *t)
{
    int local50 = 0;
    int one = 1;
    u32 j = 0;
    int h;
    local50 = 0;
    if (t->count > 0) {
        int *pa = (int *)((char *)t + 0x1484);
        char *name = (char *)t + 0xc;
        do {
            h = fn_8857B848(*(int *)name, 0x40000000u, 0, 0, 2, 0, 0);
            local50 = 0;
            if (h == -1) goto fail;
            fn_8857BD30(h, pa[0], pa[10], &local50, 0);
            if ((u32)ts4_tailcall_fn_88582660_8857B840() == 0x70u) {
                ts4_if_get_u32_lbl_88C32048_8857A1E0(h);
                fn_8857B778(*(int *)name);
                ts4_tailcall_XamContentFlush_8857B2E0(t->fx14d4, 0);
                h = fn_8857B848(*(int *)name, 0x40000000u, 0, 0, 2, 0, 0);
                if (h == -1) goto fail;
                fn_8857BD30(h, pa[0], pa[10], &local50, 0);
            }
            ts4_if_get_u32_lbl_88C32048_8857A1E0(h);
            j++;
            pa++;
            name += 0x20c;
        } while (j < t->count);
        goto done;
fail:
        {
            Cx32Res *rr = t->r;
            *t->c->err = 0x9C1C9375u;
            if (rr) rr->w0 = one;
        }
    }
done:
    {
        int r = ts4_tailcall_fn_88582660_8857B840();
        t->r->w0 = r;
        t->r->w4 = local50;
        t->r->b8 = one;
    }
    ts4_tailcall_fn_885827E0_88563110(0);
    return 0;
}
