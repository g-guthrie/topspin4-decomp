/* 0x88800758: constructor. Runs the base constructor fn_88617D88, installs the vtable, sets the float at +0x90 from
 * a constant, clears the fields from +0x1C to +0xC0, sets the byte flag at +0xA0 to 1 and clears +0x8C4/+0x8C8. */
typedef struct Self88800758 {
    void *vt; char p4[0x18]; int m1c; int m20[28]; float f90; int m94, m98; char p9c[4];
    unsigned char ba0; char pa1[3]; int ma4[6]; int mbc, mc0; char pc4[0x800]; int m8c4; unsigned char b8c8;
} Self88800758;
extern char lbl_880E3A8C[];
extern const float lbl_8814B910;
void fn_88617D88(Self88800758 *s);
Self88800758 *fn_88800758(Self88800758 *s)
{
    fn_88617D88(s);
    s->vt = lbl_880E3A8C;
    s->m1c = 0;
    s->f90 = lbl_8814B910;
    s->m20[0] = 0; s->m20[1] = 0; s->m20[2] = 0; s->m20[3] = 0; s->m20[4] = 0; s->m20[5] = 0; s->m20[6] = 0; s->m20[7] = 0; s->m20[8] = 0; s->m20[9] = 0; s->m20[10] = 0; s->m20[11] = 0; s->m20[12] = 0; s->m20[13] = 0; s->m20[14] = 0; s->m20[15] = 0; s->m20[16] = 0; s->m20[17] = 0; s->m20[18] = 0; s->m20[19] = 0; s->m20[20] = 0; s->m20[21] = 0; s->m20[22] = 0; s->m20[23] = 0; s->m20[24] = 0; s->m20[25] = 0; s->m20[26] = 0; s->m20[27] = 0;
    s->m94 = 0; s->m98 = 0;
    s->ba0 = 1;
    s->ma4[0] = 0; s->ma4[1] = 0; s->ma4[2] = 0; s->ma4[3] = 0; s->ma4[4] = 0; s->ma4[5] = 0;
    s->m8c4 = 0; s->b8c8 = 0;
    s->mbc = 0; s->mc0 = 0;
    return s;
}
