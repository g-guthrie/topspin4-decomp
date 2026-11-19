/* 0x8842C4F0: Caches a field id from the named-entry table in a u16 cache (0xFFFF = unset), stores it, then writes 4 byte and 3 float values to further named fields. */
/* Matched on /Oc (agAH). fam.py template. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_880E1DE4[];
extern const char lbl_880409F8[];
extern unsigned short lbl_88B3D1BC;
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern void *ts4_get_u32_off4_88428AC0(Ref *r);
extern void *ts4_get_u32_off8_88426140(void *p);
extern int ts4_find_entry_by_name_884278D0(void *tab, const char *name, unsigned int *out);
extern unsigned short *ts4_index_u16_array_at_field0_884289F8(Ref *r, int i);
extern const char lbl_88040870[];
extern const char lbl_880409E8[];
extern const char lbl_880409DC[];
extern const char lbl_880409C4[];
extern const char lbl_88040974[];
extern const char lbl_88040968[];
extern const char lbl_88040950[];
extern unsigned char *ts4_get_u32_off0_88428A28(Ref *r, int i);
extern float *ts4_get_u32_off0_884289B8(Ref *r, int i);
void fn_8842C4F0(void *src, unsigned char byte0, unsigned char byte1, unsigned char byte2, unsigned char byte3, float value0, float value1, float value2)
{
    const char *name = lbl_880E1DE4;
    Ref r2, r3, r4, r5, r6, r7, r8, r9;
    if (lbl_88B3D1BC == 0xFFFF) {
        Ref r;
        unsigned int id;
        ts4_if_call_seq_u32_off4_88428890(&r, src, name);
        ts4_find_entry_by_name_884278D0(ts4_get_u32_off8_88426140(ts4_get_u32_off4_88428AC0(&r)), lbl_880409F8, &id);
        lbl_88B3D1BC = (unsigned short)id;
    }
    ts4_if_call_seq_u32_off4_88428890(&r2, src, name);
    *ts4_index_u16_array_at_field0_884289F8(&r2, 0) = lbl_88B3D1BC;
    ts4_if_call_seq_u32_off4_88428890(&r3, src, lbl_88040870);
    *ts4_get_u32_off0_88428A28(&r3, 0) = byte0;
    ts4_if_call_seq_u32_off4_88428890(&r4, src, lbl_880409E8);
    *ts4_get_u32_off0_88428A28(&r4, 0) = byte1;
    ts4_if_call_seq_u32_off4_88428890(&r5, src, lbl_880409DC);
    *ts4_get_u32_off0_88428A28(&r5, 0) = byte2;
    ts4_if_call_seq_u32_off4_88428890(&r6, src, lbl_880409C4);
    *ts4_get_u32_off0_88428A28(&r6, 0) = byte3;
    ts4_if_call_seq_u32_off4_88428890(&r7, src, lbl_88040974);
    *ts4_get_u32_off0_884289B8(&r7, 0) = value0;
    ts4_if_call_seq_u32_off4_88428890(&r8, src, lbl_88040968);
    *ts4_get_u32_off0_884289B8(&r8, 0) = value1;
    ts4_if_call_seq_u32_off4_88428890(&r9, src, lbl_88040950);
    *ts4_get_u32_off0_884289B8(&r9, 0) = value2;
}
