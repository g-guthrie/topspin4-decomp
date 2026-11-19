/* 0x8842B738: Caches the field id for lbl_88040794 in lbl_88B3D188, stores it, then copies two 16-byte vectors into further named fields. */
/* Matched on /Oc (agAH). fam.py template. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_880E1DE4[];
extern const char lbl_88040794[];
extern unsigned short lbl_88B3D188;
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern void *ts4_get_u32_off4_88428AC0(Ref *r);
extern void *ts4_get_u32_off8_88426140(void *p);
extern int ts4_find_entry_by_name_884278D0(void *tab, const char *name, unsigned int *out);
extern unsigned short *ts4_index_u16_array_at_field0_884289F8(Ref *r, int i);
typedef struct Vec4 { float x, y, z, w; } Vec4;
extern Vec4 *ts4_get_u32_off0_88428A38(Ref *r, int i);
extern const char lbl_88040784[];
extern const char lbl_88040774[];
void fn_8842B738(void *src, const Vec4 *a, const Vec4 *b)
{
    const char *name = lbl_880E1DE4;
    Ref r2, r3, r4;
    if (lbl_88B3D188 == 0xFFFF) {
        Ref r;
        unsigned int id;
        ts4_if_call_seq_u32_off4_88428890(&r, src, name);
        ts4_find_entry_by_name_884278D0(ts4_get_u32_off8_88426140(ts4_get_u32_off4_88428AC0(&r)), lbl_88040794, &id);
        lbl_88B3D188 = (unsigned short)id;
    }
    ts4_if_call_seq_u32_off4_88428890(&r2, src, name);
    *ts4_index_u16_array_at_field0_884289F8(&r2, 0) = lbl_88B3D188;
    ts4_if_call_seq_u32_off4_88428890(&r3, src, lbl_88040784);
    *ts4_get_u32_off0_88428A38(&r3, 0) = *a;
    ts4_if_call_seq_u32_off4_88428890(&r4, src, lbl_88040774);
    *ts4_get_u32_off0_88428A38(&r4, 0) = *b;
}
