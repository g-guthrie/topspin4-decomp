/* 0x8842B508: looks up the id of a named field in the table reached through lbl_880E1DE4 under src, sign-extended to 16 bits */
/* Matched on /Oc (agAH). Return type int with a (short) cast; a short return type adds an extra instruction. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_880E1DE4[];
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern void *ts4_get_u32_off4_88428AC0(Ref *r);
extern void *ts4_get_u32_off8_88426140(void *p);
extern int ts4_find_entry_by_name_884278D0(void *tab, const char *name, unsigned int *out);
int fn_8842B508(void *src, const char *field)
{
    Ref r;
    unsigned int id;
    ts4_if_call_seq_u32_off4_88428890(&r, src, lbl_880E1DE4);
    ts4_find_entry_by_name_884278D0(ts4_get_u32_off8_88426140(ts4_get_u32_off4_88428AC0(&r)), field, &id);
    return (short)id;
}
