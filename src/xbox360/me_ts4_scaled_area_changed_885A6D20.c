/* 0x885A6D20: passes w*d (+0x34, +0x3c) and whether h or d differs from lbl_88001A68 to fn_8859BB40 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
extern const float lbl_88001A68;
void fn_8859BB40(void *p, float a, int changed);
typedef struct { char pad[0x34]; float w, h, d; } O;
void ts4_scaled_area_changed_885A6D20(O *o, void *p)
{
    float a = o->w * o->d;
    fn_8859BB40(p, a, o->h != lbl_88001A68 || o->d != lbl_88001A68);
}
