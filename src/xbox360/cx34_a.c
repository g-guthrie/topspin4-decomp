/* CW34 part a: camera / minigame / publisher small objects (0x888AA8D0-0x888C0000). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#define CX34_U32(p, o) (*(u32 *)((char *)(p) + (o)))
#define CX34_F32(p, o) (*(float *)((char *)(p) + (o)))
#define CX34_I32(p, o) (*(int *)((char *)(p) + (o)))
#define CX34_U8(p, o) (*(u8 *)((char *)(p) + (o)))
#define CX34_PTR(p, o) (*(char **)((char *)(p) + (o)))

extern char lbl_880D6B70[];
extern float lbl_8814B440;
extern float lbl_880D06B4;
extern float g_ts4_script_constants[];
extern u32 *fn_881ABC10(u32 *first, u32 *last, u32 *key);
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern double fn_88564BF8(double y, double x);
extern void fn_888ADBA8(float a, float b);

/* 0x888AD540: reset a range object: vtable, 0, 0xFFFFF, 0 */
typedef struct Cx34RangeObj { char *vt; u32 a; u32 b; u32 c; } Cx34RangeObj;
void ts4_init_range_obj_888AD540(Cx34RangeObj *o)
{
    volatile Cx34RangeObj *v = o;
    v->vt = lbl_880D6B70;
    v->a = 0;
    v->c = 0;
    o->b = 0xFFFFF;
}

/* 0x888AD5E0: erase the first entry equal to key from the pointer vector at +0xBC */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_ptr_vec_erase_key_888AD5E0(char *self, u32 key)
{
    char *v = self + 0xbc;
    u32 *end = (u32 *)CX34_PTR(self, 0xc0);
    u32 *p = fn_881ABC10((u32 *)CX34_PTR(v, 0), end, &key);
    if (end != p) {
        u32 *nx = p + 1;
        u32 *e = (u32 *)CX34_PTR(v, 4);
        if (nx != e) fn_88562DC0(p, nx, (u32)((char *)e - (char *)nx));
        CX34_PTR(v, 4) = (char *)CX34_PTR(v, 4) - 4;
    }
}

/* 0x888AD6F0: store the angles (atan2) between two point pairs */
void ts4_update_angles_888AD6F0(char *self)
{
    float a = CX34_F32(self, 0x40) - CX34_F32(self, 0x34);
    float b = CX34_F32(self, 0x38) - CX34_F32(self, 0x2c);
    float c, d;
    CX34_F32(self, 0xf4) = (float)fn_88564BF8(a, b);
    c = CX34_F32(self, 0x3c) - CX34_F32(self, 0x30);
    d = CX34_F32(self, 0x40) - CX34_F32(self, 0x34);
    CX34_F32(self, 0xf0) = (float)fn_88564BF8(d, c);
}

/* 0x888ADCD0 */
void ts4_load_pair_by_index_888ADCD0(char *self)
{
    u32 i = CX34_U8(self, 0xb5);
    CX34_F32(self, 0x98) = **(float **)((char *)self + (i + 0x18) * 8);
    CX34_F32(self, 0xa0) = **(float **)((char *)self + (i << 3) + 0xc4);
    CX34_U8(self, 0x35) = 1;
}

/* 0x888ADF70 / 0x888AE070: byte of the self-relative record at +8 */
u8 ts4_rec_byte_ec_888ADF70(char *self)
{
    char *r = CX34_PTR(self, 8);
    r = r + *(int *)r;
    return CX34_U8(r, 0xec);
}
u8 ts4_rec_byte_c0_888AE070(char *self)
{
    char *r = CX34_PTR(self, 8);
    r = r + *(int *)r;
    return CX34_U8(r, 0xc0);
}

#ifdef _MSC_VER
#define CX34_PAD6 int pd0 = 0; int pd1 = 0; int pd2 = 0; int pd3 = 0; int pd4 = 0; int pd5 = 0;
#else
#define CX34_PAD6
#endif
#define CX34_VT(o, slot) ((*(void ***)(o))[(slot) / 4])
typedef void (*Cx34Fn0)(void *);
typedef void (*Cx34Fn1)(void *, int);
typedef void (*Cx34FnP)(void *, void *);
typedef void (*Cx34FnF)(void *, float);
typedef void (*Cx34FnFF)(void *, float, float);
typedef u8 (*Cx34FnB)(void *);
typedef u32 *(*Cx34FnRet)(u32 *, void *);

/* element range copy used by the vector-clear idiom (tail pointer = copy(last, last, first)) */
static __inline u32 *cx34_copy(u32 *first, u32 *last, u32 *dst)
{
    int n = last - first;
    u32 *s = first;
    u32 *p = dst;
    while (n > 0) {
        *p = *s;
        n--;
        p++;
        s++;
    }
    return p;
}
extern void *fn_88562DC0(void *dst, void *src, u32 n);
static __inline u32 *cx34_move(u32 *first, u32 *last, u32 *dst)
{
    if (first == last) {
        return dst;
    } else {
        u32 n = (u32)((char *)last - (char *)first);
        dst = (u32 *)fn_88562DC0(dst, first, n);
        return (u32 *)((char *)dst + n);
    }
}

/* 0x888AD658: destroy and delete every object in the pointer vector at +0x34, then clear it */
void ts4_delete_all_ptr_vec_888AD658(char *self)
{
    u32 **e = (u32 **)CX34_PTR(self, 0x38);
    char *v = self + 0x34;
    u32 **p = (u32 **)CX34_PTR(v, 0);
    for (; p != e; p++) {
        ((Cx34Fn0)CX34_VT(*p, 0x14))(*p);
        if (*p) ((Cx34Fn1)CX34_VT(*p, 0))(*p, 1);
    }
    CX34_PTR(v, 4) = (char *)cx34_move((u32 *)CX34_PTR(v, 4), (u32 *)CX34_PTR(v, 4), (u32 *)CX34_PTR(v, 0));
}

/* 0x888AD760: clear the u32 vector at +0x1c, zero three words and release the owned object at +0xEC */
void ts4_reset_and_release_ec_888AD760(char *self)
{
    char *v = self + 0x1c;
    CX34_PTR(v, 4) = (char *)cx34_copy((u32 *)CX34_PTR(v, 4), (u32 *)CX34_PTR(v, 4), (u32 *)CX34_PTR(v, 0));
    CX34_U32(self, 0x6c) = 0;
    CX34_U32(self, 0x70) = 0;
    CX34_U32(self, 0x74) = 0;
    if (CX34_I32(self, 0xec)) {
        ((Cx34Fn0)CX34_VT(CX34_PTR(self, 0xec), 0x14))(CX34_PTR(self, 0xec));
        if (CX34_PTR(self, 0xec)) ((Cx34Fn1)CX34_VT(CX34_PTR(self, 0xec), 0))(CX34_PTR(self, 0xec), 1);
        CX34_PTR(self, 0xec) = 0;
    }
}

/* 0x888AD818: replace the owned child at +0x64, attach it and enable its three flags */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_set_child_64_888AD818(char *self, char *child)
{
    if (child) {
        if (CX34_PTR(self, 0x64)) ((Cx34Fn0)CX34_VT(CX34_PTR(self, 0x64), 0x4c))(CX34_PTR(self, 0x64));
        CX34_PTR(self, 0x64) = child;
        ((Cx34Fn0)CX34_VT(child, 0x48))(child);
        CX34_U8(CX34_PTR(self, 0x64), 0x34) = 1;
        CX34_U8(CX34_PTR(self, 0x64), 0x35) = 1;
        CX34_U8(CX34_PTR(self, 0x64), 0x36) = 1;
    }
}


/* 0x888ADDC8 */
void ts4_update_angles_b8_888ADDC8(char *self)
{
    float a = CX34_F32(self, 0xa0) - CX34_F32(self, 0x94);
    float b = CX34_F32(self, 0x98) - CX34_F32(self, 0x8c);
    float c, d;
    CX34_F32(self, 0xbc) = (float)fn_88564BF8(a, b);
    c = CX34_F32(self, 0x9c) - CX34_F32(self, 0x90);
    d = CX34_F32(self, 0xa0) - CX34_F32(self, 0x94);
    CX34_F32(self, 0xb8) = (float)fn_88564BF8(d, c);
}

/* 0x888ADE38 */
void ts4_clear_vec_80_888ADE38(char *self)
{
    char *v = self + 0x80;
    CX34_U8(self, 0xf1) = 0;
    CX34_PTR(v, 4) = (char *)cx34_copy((u32 *)CX34_PTR(v, 4), (u32 *)CX34_PTR(v, 4), (u32 *)CX34_PTR(v, 0));
}


extern char *ts4_find_child_by_id_888AD568(char *self, u32 *key);
/* 0x888AD568: find the child whose id (vslot 0x24) equals *key in the pointer vector at +0x28 */
#ifdef _MSC_VER
__declspec(noinline)
#endif
char *ts4_find_child_by_id_888AD568(char *self, u32 *key)
{
    u32 **e = (u32 **)CX34_PTR(self, 0x2c);
    u32 **p = (u32 **)CX34_PTR(self, 0x28);
    u32 tmp[2];
    for (; p != e; p++) {
        u32 *c = *p;
        if ((int)c[2] != 0) {
            u32 *r = ((Cx34FnRet)CX34_VT(c, 0x24))(tmp, c);
            if (*key == *r) return (char *)*p;
        }
    }
    return 0;
}


/* 0x888AE358..0x888AE788: forward a call to the child of the service at +0x10 identified by key */
void ts4_child_set_u8_888AE358(char *self, u32 key, u8 val)
{
    char *svc = CX34_PTR(self, 0x10);
    if (svc) {
        u32 id = key;
        char *o = ts4_find_child_by_id_888AD568(svc, &id);
        if (o) ((Cx34FnP)CX34_VT(o, 0x68))(o, &val);
    }
}
void ts4_child_set_float_7c_888AE470(char *self, u32 key, float v)
{
    char *svc = CX34_PTR(self, 0x10);
    if (svc) {
        u32 id = key;
        char *o = ts4_find_child_by_id_888AD568(svc, &id);
        if (o) ((Cx34FnF)CX34_VT(o, 0x7c))(o, v);
    }
}
void ts4_child_set_float_78_888AE4D0(char *self, u32 key, float v)
{
    char *svc = CX34_PTR(self, 0x10);
    if (svc) {
        u32 id = key;
        char *o = ts4_find_child_by_id_888AD568(svc, &id);
        if (o) ((Cx34FnF)CX34_VT(o, 0x78))(o, v);
    }
}
void ts4_child_set_float_74_888AE530(char *self, u32 key, float v)
{
    char *svc = CX34_PTR(self, 0x10);
    if (svc) {
        u32 id = key;
        char *o = ts4_find_child_by_id_888AD568(svc, &id);
        if (o) ((Cx34FnF)CX34_VT(o, 0x74))(o, v);
    }
}
void ts4_child_set_float_60_888AE6C8(char *self, u32 key, float v)
{
    char *svc = CX34_PTR(self, 0x10);
    if (svc) {
        u32 id = key;
        char *o = ts4_find_child_by_id_888AD568(svc, &id);
        if (o) ((Cx34FnF)CX34_VT(o, 0x60))(o, v);
    }
}
typedef void (*Cx34FnIFFF)(void *, int, float, float, float);
void ts4_child_set_mode_xyz_888AE590(char *self, u32 key, int mode, float x, float y, float z)
{
    char *svc = CX34_PTR(self, 0x10);
    if (svc) {
        u32 id = key;
        char *o = ts4_find_child_by_id_888AD568(svc, &id);
        if (o) {
            ((Cx34Fn1)CX34_VT(o, 0x6c))(o, mode);
            ((Cx34FnF)CX34_VT(o, 0x74))(o, x);
            ((Cx34FnF)CX34_VT(o, 0x78))(o, y);
            ((Cx34FnF)CX34_VT(o, 0x7c))(o, z);
        }
    }
}
void ts4_child_set_pair_58_888AE788(char *self, u32 key, float *a, float *b)
{
    char *svc = CX34_PTR(self, 0x10);
    if (svc) {
        u32 id = key;
        char *o = ts4_find_child_by_id_888AD568(svc, &id);
        if (o) ((Cx34FnFF)CX34_VT(o, 0x58))(o, *a, *b);
    }
}

extern void fn_881898E8(void *vec, void *elem);
/* 0x888AE990: add key to the pointer vector at +0xBC unless it is already present */
void ts4_ptr_vec_add_unique_888AE990(char *self, u32 key)
{
    char *v = self + 0xbc;
    u32 *end = (u32 *)CX34_PTR(self, 0xc0);
    u32 *p = fn_881ABC10((u32 *)CX34_PTR(self, 0xbc), end, &key);
    if (end == p) fn_881898E8(v, &key);
}

extern char *lbl_88D45B1C;
extern char *lbl_88D45964;
extern float lbl_880C960C;
extern void ts4_vector_grow_append_scalar4_88174A38(void *vec, void *where, void *val);
extern void fn_881705B0(void *vec, int n);
extern void ts4_object_finalize(void *);
extern u32 fn_88608590(u32 a, u32 b);
extern u32 lbl_88C6BAD0[];
extern u32 lbl_88C6BA40[];
extern u32 lbl_88C6B9E8[];
extern u32 lbl_88C6B958[];

/* 0x888AE1E8: step the child index at +0x28 when the current service record has flag 0x40 set */
void ts4_advance_child_index_888AE1E8(char *self)
{
    char *g = CX34_PTR(lbl_88D45B1C, 0x234);
    int idx = CX34_I32(self, 0x38);
    int sel;
    int n;
    int cur;
    if (idx < CX34_I32(g, 0x34)) {
        sel = ((int *)CX34_PTR(g, 0x30))[idx];
        if (sel == -1) sel = CX34_I32(g, 0x1c);
    } else {
        sel = CX34_I32(g, 0x1c);
    }
    if ((*(u16 *)(CX34_PTR(g, 0x3c) + sel * 0xc4 + 0x44) & 0x40) != 0x40) return;
    n = (CX34_I32(self, 0x20) - CX34_I32(self, 0x1c)) >> 2;
    cur = CX34_I32(self, 0x28);
    if (cur >= n) {
        CX34_I32(self, 0x28) = 0;
    } else {
        CX34_I32(self, 0x28) = cur + 1;
    }
}


/* 0x888AECD0 / 0x888AED50 / 0x888AEFA8 / 0x888AF028: map a name to its index in a hash table, or the table size */
#define CX34_HASH_INDEX(NAME, TBL, N) \
u32 NAME(u32 name) \
{ \
    u32 i = 0; \
    u32 h = fn_88608590(0, name); \
    u32 *p = (TBL); \
    u32 k; \
    for (k = 0; k < (N) * 4; k += 4) { \
        if (h == *p) return i; \
        i++; \
        p++; \
    } \
    return (N); \
}
CX34_HASH_INDEX(ts4_hash_table_index15_888AECD0, lbl_88C6BAD0, 15)
CX34_HASH_INDEX(ts4_hash_table_index36_888AED50, lbl_88C6BA40, 36)
CX34_HASH_INDEX(ts4_hash_table_index22_888AEFA8, lbl_88C6B9E8, 22)
CX34_HASH_INDEX(ts4_hash_table_index36_888AF028, lbl_88C6B958, 36)




extern void ts4_ptr_vec_erase_key_888AD5E0(char *svc, u32 key);



/* 0x888AF650: push a word onto the u32 vector at +0x1c */
void ts4_push_back_1c_888AF650(char *self, u32 v)
{
    char *vec = self + 0x1c;
    u32 *end = (u32 *)CX34_PTR(vec, 4);
    if (end != (u32 *)CX34_PTR(vec, 8)) {
        if (end) *end = v;
        CX34_PTR(vec, 4) = CX34_PTR(vec, 4) + 4;
    } else {
        ts4_vector_grow_append_scalar4_88174A38(vec, end, &v);
    }
}


extern char lbl_880DC550[];

extern void ts4_destroy_owned_object(void *);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
extern void ts4_vec204_move_tail_881B9148(void *p);
extern void *fn_88617D88(void *self);
extern void fn_8816D1A8(void *p);
extern void *fn_888B1AE0(void *self);
extern void fn_888B0E38(void *self);
extern char lbl_880DC64C[];
extern char lbl_880DC9BC[];
extern char lbl_880DC5DC[];

/* 0x888B1BF8: destroy and delete every object of the vector at +0x1c, then reset */
void ts4_destroy_all_children_888B1BF8(char *self)
{
    typedef struct Cx34PVec { char **first; char **last; } Cx34PVec;
    CX34_PAD6
    Cx34PVec *v = (Cx34PVec *)(self + 0x1c);
    int n = v->last - v->first;
    int i;
    for (i = 0; i < n; i++) {
        char *o = v->first[i];
        char *d;
        ((Cx34Fn0)CX34_VT(o, 0xc))(o);
        d = v->first[i];
        if (d) ((Cx34Fn1)CX34_VT(d, 0))(d, 1);
    }
    CX34_PTR(v, 4) = (char *)cx34_move((u32 *)CX34_PTR(v, 4), (u32 *)CX34_PTR(v, 4), (u32 *)CX34_PTR(v, 0));
    CX34_U32(self, 0x30) = 0;
    CX34_U8(self, 8) = 0;
    ts4_vec204_move_tail_881B9148(self + 0x10);
}



/* 0x888B8E48 */
void ts4_destroy_camera_set_888B8E48(char *self)
{
    char *v = self + 0x1c;
    CX34_U32(self, 0) = (u32)(unsigned long)lbl_880DC9BC;
    CX34_PTR(v, 4) = (char *)cx34_copy((u32 *)CX34_PTR(v, 4), (u32 *)CX34_PTR(v, 4), (u32 *)CX34_PTR(v, 0));
    *(volatile u32 *)((char *)self + 0x70) = 0;
    *(volatile u32 *)((char *)self + 0xec) = 0;
    *(volatile u32 *)((char *)self + 0x6c) = 0;
    *(volatile u32 *)((char *)self + 0x74) = 0;
    ts4_destroy_owned_object(*(char *volatile *)(self + 0x140));
    ts4_destroy_owned_object(CX34_PTR(self, 0x134));
    ts4_destroy_owned_object(CX34_PTR(self, 0x128));
    ts4_destroy_owned_object(CX34_PTR(self, 0x11c));
    ts4_destroy_owned_object(CX34_PTR(self, 0x110));
    if (CX34_PTR(v, 0)) ts4_destroy_owned_object(CX34_PTR(v, 0));
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}


#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif
typedef struct Cx34NameEnt { const char *name; int val; } Cx34NameEnt;
extern Cx34NameEnt lbl_88C6AEB4[];


extern void fn_888B9460(void *self);
extern void ts4_set_child_64_888AD818(char *self, char *child);
extern void ts4_if_set_u32_off0_8862BE08(void *out, u32 v);
typedef u32 *(*Cx34FnRet2)(u32 *, void *);

static __inline char *cx34_find_by_id44(char *svc, u32 id)
{
    char *found = 0;
    char **e = (char **)CX34_PTR(svc, 0x38);
    char **p = (char **)CX34_PTR(svc, 0x34);
    for (; p != e; p++) {
        if (id == CX34_U32(*p, 0x44)) {
            found = *p;
            break;
        }
    }
    return found;
}
/* 0x888BB5A8: find (creating it when missing) the child with id and hand it the child found by key */
void ts4_bind_child_by_id_888BB5A8(char *self, u32 id, u32 key)
{
    char *found = 0;
    if (CX34_PTR(self, 0x10)) {
        found = cx34_find_by_id44(CX34_PTR(self, 0x10), id);
        if (found == 0) {
            fn_888B9460(self);
            found = cx34_find_by_id44(CX34_PTR(self, 0x10), id);
            if (found == 0) return;
        }
        ts4_set_child_64_888AD818(found, ts4_find_child_by_id_888AD568(CX34_PTR(self, 0x10), &key));
    }
}

/* 0x888AF8A0: collect the children matching two ids into out; returns the count */
int ts4_collect_children_by_ids_888AF8A0(char *self, u32 *ida, u32 *idb, char *out)
{
    u32 **p;
    u32 **e;
    u32 t0[1];
    u32 t1[1];
    ts4_object_finalize(out);
    fn_881705B0(out, (CX34_I32(self, 0x2c) - CX34_I32(self, 0x28)) >> 2);
    e = (u32 **)CX34_PTR(self, 0x2c);
    p = (u32 **)CX34_PTR(self, 0x28);
    for (; p != e; p++) {
        u32 *c = *p;
        if ((int)c[2] != 0) {
            u32 *r = ((Cx34FnRet2)CX34_VT(c, 0x2c))(t0, c);
            if (*ida == *r) {
                u32 *c2 = *p;
                u32 *r2 = ((Cx34FnRet2)CX34_VT(c2, 0x28))(t1, c2);
                if (*idb == *r2) fn_881898E8(out, p);
            }
        }
    }
    return (CX34_I32(out, 4) - CX34_I32(out, 0)) >> 2;
}

/* 0x888BF898: fetch four sub-handles from the resource service into +0xB8.. */
extern char lbl_880DC0D0[];
extern char lbl_880DC128[];
extern char lbl_880DC180[];
extern char lbl_880DC1D8[];
extern void fn_888BD828(void *self);
void ts4_load_four_handles_888BF898(char *self)
{
    char *ids[4];
    u32 *dst;
    int i;
    fn_888BD828(self);
    if (CX34_I32(self, 8) == 0) return;
    ids[0] = lbl_880DC0D0;
    ids[1] = lbl_880DC128;
    ids[2] = lbl_880DC180;
    ids[3] = lbl_880DC1D8;
    dst = (u32 *)(self + 0xb4);
    for (i = 0; i < 4; i++) {
        u32 tmp[2];
        char *o;
        ts4_if_set_u32_off0_8862BE08(tmp, (u32)(unsigned long)ids[i]);
        o = (char *)(unsigned long)tmp[0];
        *++dst = ((u32 (*)(void *, void *, u32, u32))CX34_VT(o, 0x28))(o, tmp, tmp[1], 4);
    }
}

extern char *fn_888AF5C0(char *self);
extern char lbl_880DC6F0[];

/* 0x888ADD08: advance the current slot index at +0xB5 (wrapping through +0xE8/+0xE9) and reload the pair */
void ts4_next_slot_888ADD08(char *self)
{
    u32 i = CX34_U8(self, 0xb5);
    u8 j;
    if (i >= CX34_U8(self, 0xe8)) {
        u32 m = CX34_U8(self, 0xe9);
        i = (i < m) ? m : 0;
    } else {
        i = i + 1;
    }
    j = (u8)i;
    CX34_U8(self, 0xb5) = j;
    CX34_F32(self, 0x9c) = lbl_880D06B4;
    CX34_F32(self, 0x98) = **(float **)((char *)self + (j + 0x18) * 8);
    CX34_F32(self, 0xa0) = **(float **)((char *)self + (j << 3) + 0xc4);
    CX34_U8(self, 0x35) = 1;
}

extern void ts4_update_angles_b8_888ADDC8(char *self);

