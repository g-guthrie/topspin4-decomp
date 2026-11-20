/* Swing_DLL.xex 0x883651A0: fills a static 0x7C-byte plugin descriptor (name label, version 0x10100, kind, flags, callback thunks)
 * and returns it; the stores follow the target order with two adjacent pairs swapped, as in 88359310. agAE: /Oc. */
typedef struct PluginDesc { unsigned int w[31]; } PluginDesc;
extern PluginDesc lbl_88B36730;
void *ts4_memset(void *p, int v, unsigned int n);
extern const char lbl_8802B72C[];
void ts4_adjust_minus_28_thunk_88365188(void);
void ts4_adjust_minus_28_thunk_88363768(void);
void ts4_adjust_minus_28_thunk_88363BE8(void);
void ts4_query_prop_883A3758(void);
void ts4_adjust_minus_28_thunk_88363780(void);
void ts4_query_prop_883A37C8(void);
void ts4_set_item_level_883A3858(void);
void ts4_get_word_31c_883A3828(void);
void ts4_get_child_float_adj1c_883A38C0(void);
void ts4_thunk_adj1c_set_float_883A3910(void);
void ts4_get_float_off868_adj1c_883A3930(void);
void fn_883A3B70(void);
void ts4_thunk_adj1c_arg1_88363798(void);
PluginDesc *fn_883651A0(void)
{
    PluginDesc *d = &lbl_88B36730;
    ts4_memset(d, 0, sizeof(PluginDesc));
    d->w[0] = (unsigned int)lbl_8802B72C;
    d->w[1] = 0x10100;
    d->w[3] = 0x702;
    d->w[2] = 0x1;
    d->w[4] = (unsigned int)ts4_adjust_minus_28_thunk_88365188;
    d->w[5] = (unsigned int)ts4_adjust_minus_28_thunk_88363768;
    d->w[6] = (unsigned int)ts4_adjust_minus_28_thunk_88363BE8;
    d->w[7] = (unsigned int)ts4_query_prop_883A3758;
    d->w[8] = (unsigned int)ts4_adjust_minus_28_thunk_88363780;
    d->w[9] = (unsigned int)ts4_query_prop_883A37C8;
    d->w[23] = (unsigned int)ts4_get_word_31c_883A3828;
    d->w[24] = (unsigned int)ts4_set_item_level_883A3858;
    d->w[25] = (unsigned int)ts4_get_child_float_adj1c_883A38C0;
    d->w[29] = (unsigned int)ts4_thunk_adj1c_set_float_883A3910;
    d->w[30] = (unsigned int)ts4_get_float_off868_adj1c_883A3930;
    d->w[26] = (unsigned int)fn_883A3B70;
    d->w[27] = (unsigned int)ts4_thunk_adj1c_arg1_88363798;
    d->w[16] = 0x15;
    d->w[17] = 0x8ac;
    return d;
}
