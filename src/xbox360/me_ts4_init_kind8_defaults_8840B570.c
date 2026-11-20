/* 0x8840B570: sets kind 8, id -1 and five float defaults (two pairs repeat) from .rdata constants */
/* Matched on /Oc LTCG only (work/army/ME/v.py chk). */
extern const float lbl_88001A20, lbl_880038E0, lbl_88028BDC;
typedef struct { short kind; short id; float a, b, c, d, e; } S;
void ts4_init_kind8_defaults_8840B570(S *s)
{
    s->kind = 8;
    s->id = -1;
    s->a = lbl_88001A20;
    s->b = lbl_880038E0;
    s->c = lbl_88028BDC;
    s->d = lbl_880038E0;
    s->e = lbl_88028BDC;
}
