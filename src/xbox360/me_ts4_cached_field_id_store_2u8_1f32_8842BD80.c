/* 0x8842BD80: Caches a field id from the named-entry table in a u16 cache (0xFFFF = unset), stores it, then writes 2 byte and 1 float values to further named fields. */
/* Matched on /Oc (agAH). fam.py template. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_880E1DE4[];
extern const char lbl_8804087C[];
extern unsigned short lbl_88B3D1A4;
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern void *ts4_get_u32_off4_88428AC0(Ref *r);
extern void *ts4_get_u32_off8_88426140(void *p);
extern int ts4_find_entry_by_name_884278D0(void *tab, const char *name, unsigned int *out);
extern unsigned short *ts4_index_u16_array_at_field0_884289F8(Ref *r, int i);
extern const char lbl_88040870[];
extern const char lbl_88040860[];
extern const char lbl_8804084C[];
extern unsigned char *ts4_get_u32_off0_88428A28(Ref *r, int i);
extern float *ts4_get_u32_off0_884289B8(Ref *r, int i);
void fn_8842BD80(void *src, unsigned char byte0, unsigned char byte1, float value0)
{
    const char *name = lbl_880E1DE4;
    Ref r2, r3, r4, r5;
    if (lbl_88B3D1A4 == 0xFFFF) {
        Ref r;
        unsigned int id;
        ts4_if_call_seq_u32_off4_88428890(&r, src, name);
        ts4_find_entry_by_name_884278D0(ts4_get_u32_off8_88426140(ts4_get_u32_off4_88428AC0(&r)), lbl_8804087C, &id);
        lbl_88B3D1A4 = (unsigned short)id;
    }
    ts4_if_call_seq_u32_off4_88428890(&r2, src, name);
    *ts4_index_u16_array_at_field0_884289F8(&r2, 0) = lbl_88B3D1A4;
    ts4_if_call_seq_u32_off4_88428890(&r3, src, lbl_88040870);
    *ts4_get_u32_off0_88428A28(&r3, 0) = byte0;
    ts4_if_call_seq_u32_off4_88428890(&r4, src, lbl_88040860);
    *ts4_get_u32_off0_88428A28(&r4, 0) = byte1;
    ts4_if_call_seq_u32_off4_88428890(&r5, src, lbl_8804084C);
    *ts4_get_u32_off0_884289B8(&r5, 0) = value0;
}
