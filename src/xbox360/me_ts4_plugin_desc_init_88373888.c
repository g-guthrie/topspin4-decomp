/* Swing_DLL.xex 0x88373888: fills a static 0x7C-byte plugin descriptor (name label, version 0x10100, kind, flags, callback thunks)
 * and returns it; the stores follow the target order with two adjacent pairs swapped, as in 88359310. agAE: /Oc. */
typedef struct PluginDesc { unsigned int w[31]; } PluginDesc;
extern PluginDesc lbl_88B36B98;
void *ts4_memset(void *p, int v, unsigned int n);
extern const char lbl_8802B994[];
void ts4_adjust_minus_28_thunk_88373870(void);
void ts4_adjust_minus_28_thunk_8836F900(void);
void ts4_adjust_minus_28_thunk_88371468(void);
void ts4_adjust_minus_28_thunk_88371498(void);
void ts4_adjust_minus_28_thunk_88371480(void);
void ts4_adjust_minus_28_thunk_883714B0(void);
void ts4_adjust_minus_28_thunk_88370310(void);
void ts4_release_three_8836F918(void);
void ts4_busy_code_2d_8836F980(void);
void ts4_set_enabled_88370328(void);
PluginDesc *fn_88373888(void)
{
    PluginDesc *d = &lbl_88B36B98;
    ts4_memset(d, 0, sizeof(PluginDesc));
    d->w[0] = (unsigned int)lbl_8802B994;
    d->w[1] = 0x10100;
    d->w[3] = 0xa;
    d->w[4] = (unsigned int)ts4_adjust_minus_28_thunk_88373870;
    d->w[5] = (unsigned int)ts4_adjust_minus_28_thunk_8836F900;
    d->w[6] = (unsigned int)ts4_adjust_minus_28_thunk_88371468;
    d->w[8] = (unsigned int)ts4_adjust_minus_28_thunk_88371480;
    d->w[9] = (unsigned int)ts4_adjust_minus_28_thunk_88371498;
    d->w[10] = (unsigned int)ts4_adjust_minus_28_thunk_883714B0;
    d->w[11] = (unsigned int)ts4_adjust_minus_28_thunk_88370310;
    d->w[21] = (unsigned int)ts4_release_three_8836F918;
    d->w[22] = (unsigned int)ts4_busy_code_2d_8836F980;
    d->w[28] = (unsigned int)ts4_set_enabled_88370328;
    d->w[16] = 0x8;
    d->w[17] = 0x188;
    return d;
}
