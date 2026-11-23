/* CW32: game-side small helpers (Swing_DLL.xex 0x88878FA0-0x88891678). Default flags. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
#ifdef _MSC_VER
#define CX32_INL static __forceinline
#else
#define CX32_INL static inline
#endif

extern float lbl_8814B440;
extern int lbl_880C9DCC[];
extern int lbl_88C6BDF8[];

void *ts4_find_service(u32 id);
void fn_88800D40(void);
void *fn_88562DC0(void *dst, void *src, int n);
u32 ts4_crc32_cstr_seed_88608590(int a, u32 b);
void fn_8887CB88(void *p);
void fn_88472130(void *p);
void fn_88471F10(void *p);
void fn_881898E8(void *dst, void *src);
void fn_88881B20(void *p);
void ts4_if_call_seq_u32_off8_88473208(void *p, int a, int b, int c);
void ts4_if_call_seq_u32_off8_884742C0(void *p);
void fn_8846F580(void *a, void *b, int c, int d);
int fn_88581AA0(int a, int b, int c, int d);
int ts4_if_tailcall_MmSetAddressProtect_8857B148(int a, int b, int c, int d);

/* ---- scalar deleting thunk: this - 12, virtual slot 0 with flag 1 (0x88879070) ---- */
typedef struct CxObj { void (**vt)(struct CxObj *, int); } CxObj;
void ts4_delete_thunk_adjust12_88879070(char *p)
{
    CxObj *o = (CxObj *)(p - 12);
    if (o) o->vt[0](o, 1);
}

/* ---- call a child's virtual slot 3 with the default float (0x888791B8) ---- */
typedef struct CxVF { void (**vt)(struct CxVF *, float); } CxVF;
typedef struct CxT54 { char pad[0x54]; CxVF *o; } CxT54;
void ts4_call_child_vslot3_default_888791B8(CxT54 *t)
{
    CxVF *o = t->o;
    o->vt[3](o, lbl_8814B440);
}

/* ---- 16-bit flag test (0x888845D0) ---- */
typedef struct CxT8 { char pad[8]; u16 flags; } CxT8;
int ts4_test_flags_u16_888845D0(CxT8 *t, u64 mask)
{
    return (t->flags & mask) != 0;
}

/* ---- 3-entry table lookup with default 4 (0x888841B0) ---- */
int ts4_lookup_small_table_888841B0(int i)
{
    int r = 4;
    if (i < 3) r = lbl_880C9DCC[i];
    return r;
}

/* ---- child reference count release / acquire (0x88879BA8, 0x88879BD0) ---- */
typedef struct CxEnt {
    void **vt; int f4; int f8; int fc;
    void *sub10; u32 key14; int f18; int f1c; int f20; int f24; int f28; int f2c; int f30;
    int refs34;
} CxEnt;
void ts4_release_child_ref_88879BA8(CxEnt *e)
{
    if (e->sub10) {
        e->refs34--;
        fn_88472130(e->sub10);
    }
}
void ts4_acquire_child_ref_88879BD0(CxEnt *e)
{
    if (e->sub10) {
        e->refs34++;
        fn_88471F10(e->sub10);
    }
}

/* ---- forward a by-address argument to a sub-list (0x8887C098, 0x8887C0D0) ---- */
void ts4_add_to_list_28_8887C098(char *t, void *a)
{
    if (a) fn_881898E8(t + 0x28, &a);
}
void ts4_add_to_list_1c_8887C0D0(char *t, void *a)
{
    if (a) fn_881898E8(t + 0x1c, &a);
}

/* ---- pointer-vector helpers (0x8887E110 free all, 0x8887E1A8 remove by key, 0x88879D28 clear two) ---- */
typedef struct CxDel { void (**vt)(struct CxDel *, int); } CxDel;
typedef struct CxItem { CxDel d; int f4; u32 f8; } CxItem;
typedef struct CxVec { CxItem **begin; CxItem **end; } CxVec;
typedef struct CxPtrVec { int pad0; CxVec v; } CxPtrVec;

CX32_INL CxItem **cx_move(CxItem **first, CxItem **last, CxItem **dst)
{
    int n;
    if (first == last) return dst;
    n = (char *)last - (char *)first;
    return (CxItem **)((char *)fn_88562DC0(dst, first, n) + n);
}
CX32_INL void cx_vclear(CxVec *v) { v->end = cx_move(v->end, v->end, v->begin); }

void ts4_free_all_entries_8887E110(CxPtrVec *o)
{
    CxVec *v = &o->v;
    CxItem **p;
    for (p = v->begin; p != o->v.end; p++) {
        fn_8887CB88(*p);
        if (*p) (*p)->d.vt[0](&(*p)->d, 1);
    }
    v->end = cx_move(v->end, v->end, v->begin);
}

void ts4_remove_entry_by_key_8887E1A8(CxPtrVec *o, u32 *key)
{
    u32 id = ts4_crc32_cstr_seed_88608590(0, *key);
    CxVec *v = &o->v;
    CxItem **p;
    for (p = v->begin; p != o->v.end; p++) {
        CxItem *it = *p;
        if (it->f8 == id) {
            fn_8887CB88(it);
            if (*p) (*p)->d.vt[0](&(*p)->d, 1);
            {
                CxItem **src = p + 1;
                if (src != v->end)
                    fn_88562DC0(p, src, (char *)v->end - (char *)src);
            }
            v->end--;
            return;
        }
    }
}

typedef struct CxMv { char pad[0x1c]; CxVec a; CxItem **dummy; CxVec b; } CxMv;
void ts4_clear_two_vectors_88879D28(CxMv *t)
{
    cx_vclear(&t->a);
    cx_vclear(&t->b);
}

/* ---- nested walks that call virtual slots 0x30 then 0x2c / 0x24 (0x8887A018, 0x8887A0D0) ---- */
typedef struct CxVO { void **vt; } CxVO;
typedef struct CxGrp { char pad[0x28]; CxVO **begin; CxVO **end; } CxGrp;
struct CxCont { char pad[0x40]; CxGrp **begin; CxGrp **end; };
typedef struct CxHold { char pad[0x1c]; struct CxCont *cont; } CxHold;
CX32_INL u8 cx_vc30(CxVO *o, int a) { return ((u8 (*)(CxVO *, int))o->vt[0x30 / 4])(o, a); }

void ts4_notify_groups_8887A018(CxHold *t, int a)
{
    struct CxCont *c = t->cont;
    if (c) {
        CxGrp **g = c->begin;
        if (g != c->end) {
            do {
                CxGrp *grp = *g;
                if (grp) {
                    CxVO **q = grp->begin;
                    while (q != grp->end) {
                        if (cx_vc30(*q, a))
                            ((void (*)(CxVO *, int))(*q)->vt[0x2c / 4])(*q, a);
                        q++;
                    }
                }
                g++;
            } while (g != t->cont->end);
        }
    }
}

void ts4_notify_groups_8887A0D0(CxHold *t, int a)
{
    struct CxCont *c = t->cont;
    if (c) {
        CxGrp **g = c->begin;
        if (g != c->end) {
            do {
                CxGrp *grp = *g;
                if (grp) {
                    CxVO **q = grp->begin;
                    while (q != grp->end) {
                        if (cx_vc30(*q, a))
                            ((void (*)(CxVO *, int))(*q)->vt[0x24 / 4])(*q, a);
                        q++;
                    }
                }
                g++;
            } while (g != t->cont->end);
        }
    }
}

/* ---- set sub-object to state 4 (0x8887C9A8) ---- */
typedef struct CxStat {
    char pad[0x10];
    struct { char pad[8]; void *p8; char pad2[0x1e]; u16 s2a; u32 w2c; } *p10;
    char pad14[0x34]; u32 w48; char pad4c[8]; u32 w54; u32 w58; char pad5c[0xc]; u8 b68;
} CxStat;
void ts4_set_state_4_8887C9A8(CxStat *t)
{
    if (t->p10) {
        ts4_if_call_seq_u32_off8_88473208(t->p10, 1, 1, 0);
        t->p10->s2a = 4;
        t->b68 = 0;
        ts4_if_call_seq_u32_off8_884742C0(t->p10);
        t->p10->w2c = t->w48;
        fn_8846F580(t->p10->p8, t->p10, 0, 1);
        t->w58 = t->w54;
    }
}

/* ---- index update (0x88881E28) ---- */
typedef struct CxX { char pad[8]; void *p8; int fc; int f10; } CxX;
typedef struct CxY96 { char pad[0x96]; u16 s96; } CxY96;
typedef struct CxZ { char pad[0xc]; CxY96 *p; } CxZ;
void ts4_update_index_88881E28(CxX *t, CxZ *a)
{
    fn_88881B20(t->p8);
    a->p->s96 = t->f10 + 0xFFFF;
}

/* ---- access flags to protection bits (0x88884280) and table-backed dispatch (0x88884740) ---- */
int ts4_map_access_flags_88884280(int mode, u32 flags)
{
    int r = 0;
    if (mode == 2) r = 0x400;
    else if (mode == 3) r = 0x200;
    if ((flags & 1) != 0 && (flags & 2) == 0) return r | 2;
    return r | 4;
}

int ts4_protect_with_table_88884740(int a, int b, int idx, u32 mode)
{
    int v;
    if (mode == 0) {
        v = 4;
        if (idx < 3) v = lbl_880C9DCC[idx];
        return fn_88581AA0(a, b, v, 0);
    }
    v = 4;
    if (idx < 3) v = lbl_880C9DCC[idx];
    return ts4_if_tailcall_MmSetAddressProtect_8857B148(a, b, v, mode);
}

/* ---- call virtual slot 13 four times on consecutive words (0x8888A710) ---- */
typedef struct CxV13 { void (**vt)(struct CxV13 *, int *); } CxV13;
void ts4_call_vslot13_x4_8888A710(CxV13 *o)
{
    int *p = lbl_88C6BDF8;
    int n = 4;
    do {
        o->vt[13](o, p);
        p++;
    } while (--n);
}
