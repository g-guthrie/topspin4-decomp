/* CX15 core a: Pam core (0x88625000-0x88640000): vcall wrappers, list searches, string join, entry release. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
extern void *ts4_call_seq_ts4_memset_88622778(void *self, u32 a);
extern void ts4_loop_get_u32_off2dd0_88614170(void *out, void *self, u32 a, u32 b);

extern void ts4_if_call_seq_u32_off4_8857A748(void *p);
typedef struct VObj { const void *const *vt; } VObj;
typedef struct S2dd0 { u8 pad[0x2dd0]; VObj sub; } S2dd0;
typedef struct GetOut { u32 v; u32 pad; } GetOut;
/* 0x88628998: under the sub-object's lock (slots 1 and 2) report whether the lookup finds anything for the id */
u8 ts4_locked_find_88628998(S2dd0 *self, u32 id)
{
    VObj *sub = &self->sub;
    u8 ok;
    GetOut out;
    ((void (*)(VObj *))sub->vt[1])(sub);
    ts4_loop_get_u32_off2dd0_88614170(&out, self, id, 0);
    ok = out.v != 0 || ts4_call_seq_ts4_memset_88622778(self, id) != 0;
    ((void (*)(VObj *))sub->vt[2])(sub);
    return ok;
}

typedef struct EObj { u8 pad[0x28]; u32 f28; } EObj;
typedef struct IdEnt { u32 id; u32 x; } IdEnt;
typedef struct Elem { EObj *obj; IdEnt *begin; IdEnt *end; u8 pad[0x14]; } Elem;
typedef struct FSelf { u8 pad[0x3f0]; Elem *begin; Elem *end; } FSelf;
/* 0x8863A9E0: find an element whose object has the same f28 as the given one and whose id list holds the key */
u8 ts4_find_elem_with_id_8863A9E0(FSelf *self, u32 key, EObj *other)
{
    Elem *end = self->end;
    Elem *it = self->begin;
    u8 found = 0;
    for (; end != it; it++) {
        if (found != 0) break;
        if (it->obj->f28 == other->f28) {
            IdEnt *pe = it->end;
            IdEnt *p = it->begin;
            for (; pe != p; p++) {
                if (key == p->id) { found = 1; break; }
            }
        }
    }
    return found;
}

typedef struct XEnt { u8 pad[8]; u32 f8; } XEnt;
typedef struct OState { u8 pad[0x488]; int f488; XEnt *f48c; u32 f490; u8 f494[7]; u8 f49b; } OState;
typedef struct OWrap { u32 pad; OState *o; } OWrap;
/* 0x8863A680: store the direction flag and move the running total by the current entry's size, up or down */
void ts4_state_step_8863A680(OWrap *self, u8 *flag)
{
    OState *o = self->o;
    if (o->f488 == 0) return;
    o->f49b = *flag;
    if (*flag != 0) o->f490 = o->f48c->f8 + o->f490;
    else o->f490 = o->f490 - o->f48c->f8;
}

typedef struct R39A20 { u8 pad[0x20]; int f20; void *f24; void *f28; } R39A20;

extern void *ts4_assign_formatted_text(void *self, const char *text);
typedef struct FmtSrc { VObj *obj; u32 f4; } FmtSrc;
/* 0x88629310: format into a 0x800-byte buffer through slot 6 of the source object, assign it to self */
void *ts4_assign_from_source_88629310(void *self, FmtSrc *src)
{
    char buf[0x800];
    ((void (*)(VObj *, FmtSrc *, u32, char *, u32))src->obj->vt[6])(src->obj, src, src->f4, buf, 0x800);
    ts4_assign_formatted_text(self, buf);
    return self;
}

extern void *fn_881A4308(void *dst, void *a, void *b);
typedef struct R3A368 { u8 pad[0x80]; u8 f80[0x40]; u8 fc0[0x40]; u8 f100[0x13c]; u8 f23c, f23d; } R3A368;
/* 0x8863A368: when the dirty flag is set rebuild the block at +0x100 from the two blocks below it, then flip the flags; return the block */
void *ts4_refresh_block_8863A368(R3A368 *self)
{
    if (self->f23c != 0) {
        fn_881A4308(self->f100, self->f80, self->fc0);
        self->f23c = 0;
        self->f23d = 1;
    }
    return self->f100;
}

typedef struct C2A190 { const void *vt; u8 pad4[0x20]; u8 f24, f25; u8 pad26[2]; u32 f28; u8 f2c[0x54]; u8 f80[1]; } C2A190;

extern void *fn_88617D88(void *self);
extern char lbl_880F7BDC[];
extern struct Reg36DC8 *lbl_88D45B1C;
typedef struct Reg36DC8 { u8 pad[0x21c]; int f21c; } Reg36DC8;
typedef struct C36DC8 { const void *vt; u8 pad4[0x18]; u8 f1c; u8 pad1d[3]; u32 f20, f24, f28; } C36DC8;



#ifdef _MSC_VER
extern char *strcpy(char *, const char *);
extern char *strcat(char *, const char *);
#pragma intrinsic(strcpy, strcat)
#else
#include <string.h>
#endif
extern u32 fn_88887BE0(char *path, u32 a, u32 b);
typedef struct PathSelf { u8 pad[0x222]; char prefix[0x100]; } PathSelf;
/* 0x88626A48: join the self prefix and the given path (skipping a drive spec when a prefix exists) and hand it on */
u32 ts4_join_path_88626A48(PathSelf *self, const char *path, u32 a, u32 b)
{
    char buf[0x200];
    if (self->prefix[0] != 0 && path[1] == ':') path += 3;
    strcpy(buf, self->prefix);
    strcat(buf, path);
    return fn_88887BE0(buf, a, b);
}

extern void *fn_886376E0(void *owner, u32 key);
extern void *lbl_88D45B18;
extern void ts4_vector_erase_range_88150310(void *vec, void *first, void *last);
extern void ts4_vec204_move_tail_881B9148(void *p);
typedef struct E12 { u32 key, b, c; } E12;
typedef struct DVec { E12 *begin; E12 *end; } DVec;
typedef struct C39600 { u8 pad0[8]; u8 f8; u8 pad9[7]; u8 f10[0xc]; DVec vec; } C39600;
/* 0x88639600: release every 12-byte entry's key to the owner, empty the vector, clear the flag and finish the sub-object */
void ts4_release_entries_88639600(C39600 *self)
{
    DVec *v = &self->vec;
    E12 *b0 = ((volatile DVec *)v)->begin;
    E12 *e0 = ((volatile DVec *)v)->end;
    int n = (int)(e0 - b0);
    int i = 0;
    for (; n != 0; n--, i++) fn_886376E0(lbl_88D45B18, v->begin[i].key);
    ts4_vector_erase_range_88150310(v, v->begin, v->end);
    self->f8 = 0;
    ts4_vec204_move_tail_881B9148(self->f10);
}

/* 0x88626A18: true when the sequence helper returned a non-null result */
u32 ts4_call_seq_nonnull_88626A18(void *a, u32 b)
{
    void *p = ts4_call_seq_ts4_memset_88622778(a, b);
    return 0 != p;
}

typedef struct W36EF0 { VObj *obj; } W36EF0;
/* 0x88636EF0: forward slot 7 of the held object with the value 2; null self gives 0x14 */
u32 ts4_forward_slot7_88636EF0(W36EF0 *self, u32 a)
{
    u32 result = 0x14;
    if (self != 0) {
        result = 0;
        ((void (*)(VObj *, u32, u32))self->obj->vt[7])(self->obj, a, 2);
    }
    return result;
}

/* 0x88636F48: ask the held object (slot 1) for a count, store it in *out; fail when it is not below the limit */
u32 ts4_query_count_88636F48(W36EF0 *self, u32 unused, u32 limit, u32 *out)
{
    u32 result = 0x13;
    (void)unused;
    if (self != 0) {
        result = 0;
        {
            u32 n = ((u32 (*)(VObj *))self->obj->vt[1])(self->obj);
            *out = n;
            if (n < limit) result = 0x16;
        }
    }
    return result;
}
