/* 0x8842C0E8: 8842B940 template (id cached in lbl_88B3D1B0) plus two bytes stored in the lbl_8804092C and lbl_88040918 fields */
/* Matched on /Oc (agAH). Generated from scratchpad agAH/fam.py. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_880E1DE4[];
extern const char lbl_88040944[];
extern unsigned short lbl_88B3D1B0;
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern void *ts4_get_u32_off4_88428AC0(Ref *r);
extern void *ts4_get_u32_off8_88426140(void *p);
extern int ts4_find_entry_by_name_884278D0(void *tab, const char *name, unsigned int *out);
extern unsigned short *ts4_index_u16_array_at_field0_884289F8(Ref *r, int i);
extern const char lbl_8804092C[];
extern const char lbl_88040918[];
extern unsigned char *ts4_get_u32_off0_88428A28(Ref *r, int i);
void fn_8842C0E8(void *src, unsigned char a, unsigned char b)
{
    const char *name = lbl_880E1DE4;
    Ref r2, r3, r4;
    if (lbl_88B3D1B0 == 0xFFFF) {
        Ref r;
        unsigned int id;
        ts4_if_call_seq_u32_off4_88428890(&r, src, name);
        ts4_find_entry_by_name_884278D0(ts4_get_u32_off8_88426140(ts4_get_u32_off4_88428AC0(&r)), lbl_88040944, &id);
        lbl_88B3D1B0 = (unsigned short)id;
    }
    ts4_if_call_seq_u32_off4_88428890(&r2, src, name);
    *ts4_index_u16_array_at_field0_884289F8(&r2, 0) = lbl_88B3D1B0;
    ts4_if_call_seq_u32_off4_88428890(&r3, src, lbl_8804092C);
    *ts4_get_u32_off0_88428A28(&r3, 0) = a;
    ts4_if_call_seq_u32_off4_88428890(&r4, src, lbl_88040918);
    *ts4_get_u32_off0_88428A28(&r4, 0) = b;
}
