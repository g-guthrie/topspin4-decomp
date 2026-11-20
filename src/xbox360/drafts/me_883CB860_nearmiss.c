/* 0x883CB860: when x > lbl_88029648 returns (int)(x * lbl_88028DFC + (x >= 0 ? lbl_88001978 : lbl_88004444)), else -10000. */
/* Near miss (agAH): /Oc, 3 instructions off: fmadds/fctiwz register allocation (f12/f11 where the target reuses f0). */
extern const float lbl_88029648;
extern const float lbl_88001978;
extern const float lbl_88004444;
extern const float lbl_88028DFC;

int fn_883CB860(float x)
{
    if (x > lbl_88029648)
        return (int)(x * lbl_88028DFC + (x >= 0.0f ? lbl_88001978 : lbl_88004444));
    return -10000;
}
