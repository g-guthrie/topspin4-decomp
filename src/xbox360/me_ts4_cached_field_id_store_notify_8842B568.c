/* 0x8842B568: 8842B940 template (id cached in lbl_88B3D180) plus an int stored in the lbl_88040724 field, then forwarded with that field to the sink's slot-5 setter */
/* Matched on /Oc (agAH). Generated from scratchpad agAH/fam.py; the sink vcall is written inline. */
typedef struct Ref { void *a; void *b; } Ref;
extern const char lbl_880E1DE4[];
extern const char lbl_88040734[];
extern unsigned short lbl_88B3D180;
extern Ref *ts4_if_call_seq_u32_off4_88428890(Ref *out, void *src, const char *name);
extern void *ts4_get_u32_off4_88428AC0(Ref *r);
extern void *ts4_get_u32_off8_88426140(void *p);
extern int ts4_find_entry_by_name_884278D0(void *tab, const char *name, unsigned int *out);
extern unsigned short *ts4_index_u16_array_at_field0_884289F8(Ref *r, int i);
extern const char lbl_88040724[];
extern int *ts4_get_u32_off0_88428988(Ref *r, int i);
extern void *ts4_get_u32_off0_88428980(Ref *r);
typedef struct Sink Sink;
typedef struct SinkVt { void *f[5]; void (*set)(Sink *s, int v, void *p); } SinkVt;
struct Sink { SinkVt *vt; };
void fn_8842B568(void *src, int value, Sink *sink)
{
    const char *name = lbl_880E1DE4;
    Ref r2, r3;
    if (lbl_88B3D180 == 0xFFFF) {
        Ref r;
        unsigned int id;
        ts4_if_call_seq_u32_off4_88428890(&r, src, name);
        ts4_find_entry_by_name_884278D0(ts4_get_u32_off8_88426140(ts4_get_u32_off4_88428AC0(&r)), lbl_88040734, &id);
        lbl_88B3D180 = (unsigned short)id;
    }
    ts4_if_call_seq_u32_off4_88428890(&r2, src, name);
    *ts4_index_u16_array_at_field0_884289F8(&r2, 0) = lbl_88B3D180;
    ts4_if_call_seq_u32_off4_88428890(&r3, src, lbl_88040724);
    *ts4_get_u32_off0_88428988(&r3, 0) = value;
    sink->vt->set(sink, value, ts4_get_u32_off0_88428980(&r3));
}
