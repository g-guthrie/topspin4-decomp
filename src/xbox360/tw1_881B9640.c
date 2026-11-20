/* Swing_DLL.xex 0x881B9640: pv reserve to capacity 8 (twin ts4_pv_reserve2_88180D00 with 2) */
typedef unsigned int u32;
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void ts4_destroy_owned_object(void *p);
extern void *ts4_if_call_seq_u32_lbl_88D45B38_88162340(void *p, u32 n);

typedef struct Cx26PV { u32 *b; u32 *e; u32 *c; } Cx26PV;

void ts4_pv_reserve2_881B9640(Cx26PV *v)
{
    u32 *b = v->b;
    if ((u32)(v->c - b) < 8) {
        u32 n = v->e - b;
        u32 *nb;
        if (b != 0) {
            u32 *old_e = v->e;
            nb = (u32 *)ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->c, 8);
            if (old_e != b) fn_88562DC0(nb, b, (char *)old_e - (char *)b);
            b = nb;
            ts4_destroy_owned_object(v->b);
        } else {
            b = (u32 *)ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->c, 8);
        }
        v->b = b;
        v->c = b + 8;
        v->e = b + n;
    }
}
