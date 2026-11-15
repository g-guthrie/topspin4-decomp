/* CX15 core b: Pam core (0x88625000-0x88640000): locked setters and stack-block builders. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
extern char *strcpy(char *, const char *);
extern char *strcat(char *, const char *);
#pragma intrinsic(strcpy, strcat)
#else
#include <string.h>
#endif
typedef struct VObj { const void *const *vt; } VObj;
typedef struct V3 { float a, b, c; } V3;
typedef struct S36FA0 { u8 pad0[0x30]; V3 f30; V3 f3c_pad; V3 f48; V3 f54; u8 pad60[0x84 - 0x60]; VObj sub; } S36FA0;

#ifdef _MSC_VER
#define CX15_INL static __forceinline
#else
#define CX15_INL static inline
#endif


extern int ts4_find_sub_88162B48(void *text, const char *sub, u32 start, u32 len);
extern char lbl_880F6350[];
extern char lbl_880F6358[];
extern char lbl_880F6364[];
/* 0x886370B8: true when the first marker is absent, or neither of the other two markers is found */
u32 ts4_markers_absent_886370B8(void *text)
{
    u32 result = 1;
    if (ts4_find_sub_88162B48(text, lbl_880F6350, 0, 4) != -1) {
        int r = ts4_find_sub_88162B48(text, lbl_880F6358, 0, 8);
        if (r == -1) r = ts4_find_sub_88162B48(text, lbl_880F6364, 0, 6);
        result = (u32)r == 0xFFFFFFFFu;
    }
    return result;
}

typedef struct S311B0 S311B0;
typedef struct Slot311B0 { S311B0 *self; } Slot311B0;
extern void *fn_88630E78(void *ctx, u32 a, Slot311B0 self_ref, u32 b, u32 flag);
struct S311B0 {
    const void *const *vt; u8 pad4[0x11]; u8 f15; u8 pad16[2]; VObj *f18; u8 pad1c[0x200];
    u32 f21c, f220, f224; u8 f228; u8 pad229[3]; u32 f22c, f230, f234, f238, f23c, f240; u8 f244;
};

extern void ts4_destroy_owned_object(void *obj);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
extern char lbl_880F6440[];
extern char lbl_880D19F0[];
extern char lbl_880E731C[];
typedef struct Own18 { void *obj; u8 pad[0x14]; } Own18;
typedef struct S39130 {
    const void *vt; u8 pad4[0x20]; void *f24; u8 pad28[0x38]; void *f60; u8 pad64[0x14]; Own18 *f78; Own18 *f7c; const void *f80pad; const void *f84;
} S39130;
extern void *lbl_88D45A28;

extern void *fn_88617D88(void *self);
extern char lbl_880F7908[];
extern char lbl_880F79D0[];
extern char lbl_880F7A28[];
typedef struct C2C390 {
    const void *vt; u8 pad4[0x18]; u32 f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44, f48, f4c, f50, f54;
    const void *f58; void *f5c; const void *f60; void *f64; u32 f68, f6c, f70;
} C2C390;

extern void ts4_io_open_request_88630F80(void *out, u32 key, void *obj, const char *path, u32 a, u32 b);
typedef struct PObj33FC0 { u8 pad[0x24]; char prefix[0x200]; u32 f224; } PObj33FC0;
/* 0x88633FC0: join the object's prefix and the given path (skipping a drive spec when a prefix exists), then run the request builder */
void *ts4_join_path_request_88633FC0(void *out, PObj33FC0 *obj, const char *path, u32 a, u32 b)
{
    char buf[0x200];
    if (obj->prefix[0] != 0 && path[1] == ':') path += 3;
    strcpy(buf, obj->prefix);
    strcat(buf, path);
    ts4_io_open_request_88630F80(out, obj->f224, obj, buf, a, b);
    return out;
}

extern void fn_88635678(void *self);
extern void fn_886345E0(void *self);
typedef struct Q36C30 { u8 pad[0x18]; void *f18; u8 pad1c[0xe]; u8 f2a; } Q36C30;
typedef struct Tgt36C30 { const void *const *vt; void *f4; } Tgt36C30;
typedef struct Reg36C30 { u8 pad[0x27c]; void *f27c; } Reg36C30;
extern Reg36C30 *lbl_88D45B1C;
typedef struct S36C30 { u8 pad[0x1c]; Tgt36C30 *f1c; u8 pad20[0xc]; int f2c; u8 pad30[0x1c]; Q36C30 *f4c; } S36C30;
/* 0x88636C30: when the target is current and idle ask it to finish (slot 2); otherwise rebind the state record to the registry's default and clear its flag */
void ts4_resolve_target_88636C30(S36C30 *self)
{
    Tgt36C30 *t = self->f1c;
    if (*(int *)&self->f1c != 0 && self->f2c == 5 && self->f4c->f18 == t->f4 && self->f4c->f2a != 1) {
        ((void (*)(Tgt36C30 *))t->vt[2])(t);
    } else {
        void *g = lbl_88D45B1C->f27c;
        if (g != 0) {
            self->f4c->f18 = g;
            fn_88635678(self);
        } else {
            fn_886345E0(self);
        }
        self->f4c->f2a = 0;
    }
}

extern void ts4_destroy_owned_object(void *obj);
extern void fn_886099A8(void *p);
extern void fn_8862BA88(void);
extern void ts4_object_finalize(void *p);
extern void ts4_if_call_seq_u32_off88_88624048(void *p);
extern void ts4_tsu_cleanup_end(void *p);
extern char lbl_880F7D24[];
extern char lbl_880F78DC[];
typedef struct Inner2EFF8 { u8 pad[0x88]; u8 f88[0xc]; u8 f94; } Inner2EFF8;
typedef struct Sub2EFF8 { const void *vt; u8 pad4[0x10]; const void *f14; } Sub2EFF8;
typedef struct S2EFF8 {
    const void *vt; Inner2EFF8 *f4; void *f8; u8 padc[0x230]; const void *f23c; u8 pad240[0x10]; const void *f250;
    u8 pad254[0x28]; const void *f27c_pad; const void *f280_pad; const void *f284; u8 pad288[0x24]; void *f2ac; u8 pad2b0[0x10]; void *f2c0;
} S2EFF8;

extern void *fn_8816D220(void *reg, u32 key);
extern void fn_881705B0(void *p, u32 n);
extern char lbl_880F8C1C[];
extern void *lbl_88D45B20;
typedef struct C29B60 {
    const void *vt; u8 pad4[0x18]; u32 f1c, f20; int f24; u32 f28; int f2c; u32 f30; void *f34;
    u32 f38, f3c, f40, f44, f48; u8 pad4c[8]; u32 f54, f58, f5c; u8 pad60[8]; u32 f68;
} C29B60;

extern void *ts4_io_run_request_88630C90(void *self, void *blk);
typedef struct Blk {
    u32 f0; u8 f4; u8 pad5[3]; u32 f8; u8 padc[0x20c - 0xc];
    u32 f20c, f210, f214, f218, f21c, f220, f224, f228, f22c, f230; u8 f234; u8 pad235[3]; u32 f238;
} Blk;

/* 0x88630D98: run the block builder in mode 3 with three caller values; return the result word */
u32 ts4_run_blk_mode3_88630D98(void *self, u32 a, u32 b, u32 c)
{
    volatile Blk blk;
    blk.f20c = a;
    ((Blk *)&blk)->f220 = b;
    blk.f210 = 0;
    blk.f228 = 0;
    blk.f230 = 0;
    blk.f238 = 0;
    blk.f0 = 0;
    blk.f4 = 0;
    blk.f234 = 0;
    blk.f22c = 0;
    blk.f8 = 3;
    blk.f214 = 0;
    blk.f218 = 0;
    blk.f224 = 0;
    blk.f21c = c;
    ts4_io_run_request_88630C90(self, (void *)&blk);
    return blk.f238;
}

/* 0x88630E08: run the block builder in mode 1 with five caller values; return the result word */
u32 ts4_run_blk_mode1_88630E08(void *self, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    volatile Blk blk;
    blk.f214 = a;
    ((Blk *)&blk)->f20c = b;
    blk.f210 = 0;
    blk.f228 = 0;
    blk.f230 = 0;
    blk.f238 = 0;
    blk.f0 = 0;
    blk.f234 = 0;
    blk.f22c = 0;
    blk.f8 = 1;
    blk.f218 = 0;
    blk.f4 = 0;
    blk.f224 = c;
    blk.f220 = d;
    blk.f21c = e;
    ts4_io_run_request_88630C90(self, (void *)&blk);
    return blk.f238;
}

extern void *ts4_assign_formatted_text(void *self, const char *text);
extern void fn_8816CAA0(void *str, const char *from);
typedef struct Str16 { char *p; u32 pad[3]; } Str16;
typedef struct PathSrc { const char *path; } PathSrc;
typedef struct P2FC08 { u8 pad[0x24]; char prefix[0x200]; VObj *f224; } P2FC08;
/* 0x8862FC08: join the object's prefix and the given path (skipping a drive spec when a prefix exists) and pass it to slot 20 of the held object */
void ts4_join_path_notify_8862FC08(P2FC08 *self, PathSrc *src)
{
    Str16 str;
    char buf[0x200];
    ts4_assign_formatted_text(&str, src->path);
    if (self->prefix[0] != 0 && src->path[1] == ':') fn_8816CAA0(&str, src->path + 3);
    strcpy(buf, self->prefix);
    strcat(buf, str.p);
    ((void (*)(VObj *, char *))self->f224->vt[20])(self->f224, buf);
    ts4_destroy_owned_object(str.p);
}

extern Str16 *ts4_bstr_concat_rev_881640A8(Str16 *out, const char *prefix, Str16 *tail);
extern void ts4_if_call_seq_u32_off0_8816D140(Str16 *out, Str16 *src);
extern int ts4_crt_chmod_88568CB0(const char *name, int mode);
extern int ts4_tailcall_fn_88567748_88567798(const char *name);
typedef struct P306C8 { u8 pad[0x222]; char prefix[0x100]; } P306C8;


extern void ts4_if_get_u32_off0_8861AB10(void *out, VObj *obj, void *self, const char *name, u32 a, u32 b);

extern void fn_886393F0(void *reg, void *obj);
typedef struct Ent18 { u8 pad[0xc]; int f0c; u8 pad10[4]; void *obj; } Ent18;
typedef struct Reg39 { u8 pad[0x78]; Ent18 *begin; Ent18 *end; } Reg39;
typedef struct Owner39 { const void *const *vt; void *f4; } Owner39;
typedef struct Hdr39 { Owner39 *own; } Hdr39;
extern Reg39 *lbl_88D45B18;
/* 0x886396E8: drop one reference to the object in the registry; when it was the last (or unregistered) tell its owner (slot 22), clean it up and remove it */
u32 ts4_release_registered_886396E8(Hdr39 *obj)
{
    u32 result = 0x13;
    if (obj != 0) {
        Reg39 *reg;
        Ent18 *it;
        Ent18 *end;
        result = 0;
        reg = lbl_88D45B18;
        it = reg->begin;
        end = reg->end;
        for (; it != end; it++) {
            if (it->obj == (void *)obj) {
                if (it->f0c > 1) {
                    Ent18 *it2 = ((volatile Reg39 *)reg)->begin;
                    Ent18 *end2 = ((volatile Reg39 *)reg)->end;
                    for (; it2 != end2; it2++) {
                        if (it2->obj == (void *)obj) {
                            it2->f0c = it2->f0c - 1;
                            break;
                        }
                    }
                    return 0;
                }
                break;
            }
        }
        {
            Owner39 *o = obj->own;
            void **tgt = (void **)o->f4;
            ((void (*)(void *, void *))(*(void ***)tgt)[22])(tgt, obj);
        }
        ts4_tsu_cleanup_end(obj);
        fn_886393F0(lbl_88D45B18, obj);
    }
    return result;
}

extern void *ts4_call_seq_ts4_memset_88622778(void *self, u32 a);
extern void ts4_keyed_name_init_8861A460(void *slot, u32 a, u32 b, u32 c);
typedef struct Slot210 { u32 f0; u8 f4; u8 pad5[0x1ff]; int f204; u8 pad208[8]; } Slot210;
typedef struct S28A20 { u8 pad[0x490]; Slot210 slots[20]; VObj sub; } S28A20;
/* 0x88628A20: under the sub-object's lock, when the id is unknown claim the first unused 0x210-byte slot for it; returns whether one was claimed */
u8 ts4_claim_free_slot_88628A20(S28A20 *self, u32 a, u32 b, u32 c)
{
    VObj *sub = &self->sub;
    u8 result;
    ((void (*)(VObj *))sub->vt[1])(sub);
    result = 0;
    if (ts4_call_seq_ts4_memset_88622778(self, b) == 0) {
        Slot210 *e = self->slots;
        for (; sub != (VObj *)e; e++) {
            u8 used = e->f0 != 0 && e->f4 != 0 && e->f204 != 0;
            if (used == 0) {
                ts4_keyed_name_init_8861A460(e, b, a, c);
                result = 1;
                break;
            }
        }
    }
    ((void (*)(VObj *))sub->vt[2])(sub);
    return result;
}

extern void ts4_vector_erase_range_88150310(void *vec, void *first, void *last);
extern void ts4_vector_erase_range_88280BA0(void *vec, void *first, void *last);
extern void ts4_object_finalize(void *p);
extern void ts4_loop_call_seq_u32_offc_88282E68(void *begin, void *end);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
extern char lbl_880F8B6C[];
typedef struct V2 { void *begin; void *end; } V2;
typedef struct S28568 { const void *vt; u8 pad4[0x18]; V2 vec; void *f24_pad; void *f28; } S28568;
/* 0x88628568: destructor body: reset the vtable, erase and finalize the sub-containers, release the owned members, then run the base teardown */
void ts4_dtor_body_88628568(S28568 *self)
{
    V2 *v = &self->vec;
    self->vt = lbl_880F8B6C;
    ts4_vector_erase_range_88280BA0(v, v->begin, v->end);
    ts4_object_finalize(&self->f28);
    if (self->f28 != 0) ts4_destroy_owned_object(self->f28);
    ts4_loop_call_seq_u32_offc_88282E68(v->begin, v->end);
    if (v->begin != 0) ts4_destroy_owned_object(v->begin);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}

extern void *fn_88562DC0(void *dst, const void *src, u32 n);
extern void ts4_loop_call_seq_u32_off0_88150378(void *begin, void *end);
extern char lbl_880F7CC0[];
extern char lbl_880D19F0[];
typedef struct S31048 {
    const void *vt; u8 pad4[0x20]; void *f24; u8 pad28[0x1424];
    const void *f144c; u8 pad1450[0x1c]; const void *f146c; u8 pad1470[0x1c]; const void *f148c;
    u8 pad1490[0x24]; V2 f14b4; u8 pad14bc[8]; V2 f14c4;
} S31048;
static void **vec_clear_copy(void **first, void **last, void **dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (void **)fn_88562DC0(dest, first, n);
        return (void **)((char *)dest + n);
    }
}
/* 0x88631048: destructor body: reset the vtable, erase and empty the two containers, release their storage and the owned member, restore the default words, run the base teardown */
void ts4_dtor_body_88631048(S31048 *self)
{
    V2 *v = &self->f14c4;
    V2 *w;
    self->vt = lbl_880F7CC0;
    ts4_vector_erase_range_88150310(v, v->begin, v->end);
    w = &self->f14b4;
    w->end = vec_clear_copy((void **)w->end, (void **)w->end, (void **)w->begin);
    ts4_loop_call_seq_u32_off0_88150378(v->begin, v->end);
    if (v->begin != 0) ts4_destroy_owned_object(v->begin);
    if (w->begin != 0) ts4_destroy_owned_object(w->begin);
    ((volatile S31048 *)self)->f148c = lbl_880D19F0;
    ((volatile S31048 *)self)->f146c = lbl_880D19F0;
    ((volatile S31048 *)self)->f144c = lbl_880D19F0;
    { void *o = ((volatile S31048 *)self)->f24; if (o != 0) ts4_destroy_owned_object(o); }
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
