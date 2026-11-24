/* 0x88481F60: stores c at +0xa2 and !c at +0xb2, then fills p->t->v (signed pointer test) with lbl_88001A20 */
/* Matched on /Oc LTCG only (work/army/ME/v.py chk). */
extern const float lbl_88001A20;
typedef struct { float v[4]; } V4;
typedef struct { char pad[0x1c]; V4 *v; } T;
typedef struct { char pad[0x28]; T *t; } P;
#define PTR_INT(p) ((int)(p))
void ts4_set_flag_reset_v4_88481F60(char *s, P *p, char c)
{
    s[0xa2] = c;
    s[0xb2] = c == 0;
    if (p && p->t) {
        V4 *v = p->t->v;
        if (PTR_INT(v) != 0) { v->v[0] = lbl_88001A20; v->v[1] = lbl_88001A20; v->v[2] = lbl_88001A20; v->v[3] = lbl_88001A20; }
    }
}
