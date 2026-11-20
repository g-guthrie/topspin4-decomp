/* 0x8842B940: caches the id of field lbl_880407E4 in the table reached through lbl_880E1DE4 under src (lbl_88B3D190), then stores it in element 0 of the u16 array there */
/* Matched on /Oc (agAH). Name pointer kept in a local (r29), id via an out parameter; the table chain is written inline. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_880E1DE4[];
extern const char lbl_880407E4[];
extern unsigned short lbl_88B3D190;
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern void *ts4_get_u32_off4_88428AC0(Ref *r);
extern void *ts4_get_u32_off8_88426140(void *p);
extern int ts4_find_entry_by_name_884278D0(void *tab, const char *name, unsigned int *out);
extern unsigned short *ts4_index_u16_array_at_field0_884289F8(Ref *r, int i);
void fn_8842B940(void *src)
{
    const char *name = lbl_880E1DE4;
    Ref r2;
    if (lbl_88B3D190 == 0xFFFF) {
        Ref r;
        unsigned int id;
        ts4_if_call_seq_u32_off4_88428890(&r, src, name);
        ts4_find_entry_by_name_884278D0(ts4_get_u32_off8_88426140(ts4_get_u32_off4_88428AC0(&r)), lbl_880407E4, &id);
        lbl_88B3D190 = (unsigned short)id;
    }
    ts4_if_call_seq_u32_off4_88428890(&r2, src, name);
    *ts4_index_u16_array_at_field0_884289F8(&r2, 0) = lbl_88B3D190;
}
