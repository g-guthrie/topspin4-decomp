/* 0x883C7158: queries the current position from lbl_88CAC988 +0x14 through fn_88309DB8 (returning its error) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); sets *changed when it differs from the cached position at +0xBC; zero kept in a local (f31). */
extern const float lbl_88001A20;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct G { char pad[0x14]; void *sys; } G;
extern G *lbl_88CAC988;
typedef struct T { char pad[0xbc]; Vec3 pos; } T;
int ts4_if_call_seq_fn_88309DB8_88309160(void *sys, int a, int b, Vec3 *pos, int c, int d);
int ts4_position_changed_883C7158(T *t, unsigned char *changed)
{
    Vec3 p;
    Vec3 d;
    int r;
    float zero = lbl_88001A20;
    p.x = zero;
    p.y = zero;
    p.z = zero;
    r = ts4_if_call_seq_fn_88309DB8_88309160(lbl_88CAC988->sys, 0, 0, &p, 0, 0);
    if (r)
        return r;
    d.x = p.x - t->pos.x;
    d.y = p.y - t->pos.y;
    d.z = p.z - t->pos.z;
    if (d.x == zero && d.y == zero && d.z == zero)
        *changed = 0;
    else
        *changed = 1;
    return 0;
}
