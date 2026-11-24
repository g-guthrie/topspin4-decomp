/* 0x8842B9C8: 8842B940 plus a float stored in element 0 of the lbl_8800FC7C field (id cached in lbl_88B3D194) */
/* Matched on /Oc (agAH). 8842B940 template with a third lookup. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_880E1DE4[];
extern const char lbl_880407F8[];
extern const char lbl_8800FC7C[];
extern unsigned short lbl_88B3D194;
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern void *ts4_get_u32_off4_88428AC0(Ref *r);
extern void *ts4_get_u32_off8_88426140(void *p);
extern int ts4_find_entry_by_name_884278D0(void *tab, const char *name, unsigned int *out);
extern unsigned short *ts4_index_u16_array_at_field0_884289F8(Ref *r, int i);
extern float *ts4_get_u32_off0_884289B8(Ref *r, int i);
void fn_8842B9C8(void *src, float value)
{
    const char *name = lbl_880E1DE4;
    Ref r2, r3;
    if (lbl_88B3D194 == 0xFFFF) {
        Ref r;
        unsigned int id;
        ts4_if_call_seq_u32_off4_88428890(&r, src, name);
        ts4_find_entry_by_name_884278D0(ts4_get_u32_off8_88426140(ts4_get_u32_off4_88428AC0(&r)), lbl_880407F8, &id);
        lbl_88B3D194 = (unsigned short)id;
    }
    ts4_if_call_seq_u32_off4_88428890(&r2, src, name);
    *ts4_index_u16_array_at_field0_884289F8(&r2, 0) = lbl_88B3D194;
    ts4_if_call_seq_u32_off4_88428890(&r3, src, lbl_8800FC7C);
    *ts4_get_u32_off0_884289B8(&r3, 0) = value;
}
