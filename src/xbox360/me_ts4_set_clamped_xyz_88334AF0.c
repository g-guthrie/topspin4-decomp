/* 0x88334AF0: Clamps x and y to [lbl_88001A20, lbl_88028C18] and z to [lbl_88001A20, lbl_88001A68], stores them at +0x74..+0x7c, and returns 0. */
/* Matched on /Oc (agAH). Separate ifs for x/y; an else-if for z. */
typedef struct Params { char p0[0x74]; float x; float y; float z; } Params;
extern const float lbl_88001A20;
extern const float lbl_88028C18;
extern const float lbl_88001A68;
int fn_88334AF0(Params *p, float x, float y, float z)
{
    if (x < lbl_88001A20)
        x = lbl_88001A20;
    if (y < lbl_88001A20)
        y = lbl_88001A20;
    if (x > lbl_88028C18)
        x = lbl_88028C18;
    if (y > lbl_88028C18)
        y = lbl_88028C18;
    if (z < lbl_88001A20)
        z = lbl_88001A20;
    else if (z > lbl_88001A68)
        z = lbl_88001A68;
    p->x = x;
    p->y = y;
    p->z = z;
    return 0;
}
