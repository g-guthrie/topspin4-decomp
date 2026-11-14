/* Family LG1: path list loader (region 0x889586A0). Builds ten paths "<base><suffix>" from the base text
 * at owner+0xB8 and hands each to virtual slot 0x40/4 of the object at owner+0x60. Text objects own
 * their buffer (released with ts4_destroy_owned_object). */

typedef struct lg1_text {
    char *buffer;
    int pad[3];
} lg1_text;

typedef struct lg1_sink lg1_sink;
typedef struct lg1_sink_vtbl {
    void *slots[16];
    void (*add)(lg1_sink *self, lg1_text *path); /* +0x40 */
} lg1_sink_vtbl;
struct lg1_sink {
    lg1_sink_vtbl *vtbl;
};

typedef struct lg1_path_owner {
    char pad0[0x60];
    lg1_sink *sink;  /* +0x60 */
    char pad64[0x54];
    const char *base; /* +0xB8 */
} lg1_path_owner;

extern void ts4_assign_formatted_text(void *object, const char *text);
extern void ts4_destroy_owned_object(void *owned);
extern lg1_text *fn_88164000(lg1_text *out, lg1_text *left, const char *right);
extern void ts4_if_call_seq_u32_off0_8816D140(lg1_text *out, lg1_text *from);
extern const char lbl_880D3584[];
extern const char lbl_880D4540[];
extern const char lbl_880D4554[];
extern const char lbl_880D4564[];
extern const char lbl_880D4574[];
extern const char lbl_880D4588[];
extern const char lbl_880D4598[];
extern const char lbl_880D45A8[];
extern const char lbl_880D45B8[];
extern const char lbl_880D45C8[];

/* Hand the ten derived paths to the sink; returns 1. Swing_DLL.xex 0x88958F10 */
int ts4_path_list_add_all_88958F10(lg1_path_owner *owner)
{
    lg1_text base;
    lg1_text joined0, path0;
    lg1_text joined1, path1;
    lg1_text joined2, path2;
    lg1_text joined3, path3;
    lg1_text joined4, path4;
    lg1_text joined5, path5;
    lg1_text joined6, path6;
    lg1_text joined7, path7;
    lg1_text joined8, path8;
    lg1_text joined9, path9;

    ts4_assign_formatted_text(&base, owner->base);
    ts4_if_call_seq_u32_off0_8816D140(&path0, fn_88164000(&joined0, &base, lbl_880D3584));
    owner->sink->vtbl->add(owner->sink, &path0);
    ts4_destroy_owned_object(path0.buffer);
    ts4_destroy_owned_object(joined0.buffer);
    ts4_if_call_seq_u32_off0_8816D140(&path1, fn_88164000(&joined1, &base, lbl_880D4540));
    owner->sink->vtbl->add(owner->sink, &path1);
    ts4_destroy_owned_object(path1.buffer);
    ts4_destroy_owned_object(joined1.buffer);
    ts4_if_call_seq_u32_off0_8816D140(&path2, fn_88164000(&joined2, &base, lbl_880D4554));
    owner->sink->vtbl->add(owner->sink, &path2);
    ts4_destroy_owned_object(path2.buffer);
    ts4_destroy_owned_object(joined2.buffer);
    ts4_if_call_seq_u32_off0_8816D140(&path3, fn_88164000(&joined3, &base, lbl_880D4564));
    owner->sink->vtbl->add(owner->sink, &path3);
    ts4_destroy_owned_object(path3.buffer);
    ts4_destroy_owned_object(joined3.buffer);
    ts4_if_call_seq_u32_off0_8816D140(&path4, fn_88164000(&joined4, &base, lbl_880D4574));
    owner->sink->vtbl->add(owner->sink, &path4);
    ts4_destroy_owned_object(path4.buffer);
    ts4_destroy_owned_object(joined4.buffer);
    ts4_if_call_seq_u32_off0_8816D140(&path5, fn_88164000(&joined5, &base, lbl_880D4588));
    owner->sink->vtbl->add(owner->sink, &path5);
    ts4_destroy_owned_object(path5.buffer);
    ts4_destroy_owned_object(joined5.buffer);
    ts4_if_call_seq_u32_off0_8816D140(&path6, fn_88164000(&joined6, &base, lbl_880D4598));
    owner->sink->vtbl->add(owner->sink, &path6);
    ts4_destroy_owned_object(path6.buffer);
    ts4_destroy_owned_object(joined6.buffer);
    ts4_if_call_seq_u32_off0_8816D140(&path7, fn_88164000(&joined7, &base, lbl_880D45A8));
    owner->sink->vtbl->add(owner->sink, &path7);
    ts4_destroy_owned_object(path7.buffer);
    ts4_destroy_owned_object(joined7.buffer);
    ts4_if_call_seq_u32_off0_8816D140(&path8, fn_88164000(&joined8, &base, lbl_880D45B8));
    owner->sink->vtbl->add(owner->sink, &path8);
    ts4_destroy_owned_object(path8.buffer);
    ts4_destroy_owned_object(joined8.buffer);
    ts4_if_call_seq_u32_off0_8816D140(&path9, fn_88164000(&joined9, &base, lbl_880D45C8));
    owner->sink->vtbl->add(owner->sink, &path9);
    ts4_destroy_owned_object(path9.buffer);
    ts4_destroy_owned_object(joined9.buffer);
    ts4_destroy_owned_object(base.buffer);
    return 1;
}
