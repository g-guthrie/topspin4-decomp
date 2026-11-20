/* 0x883E0640: converts a rate to two integer periods: for hz > 0, (int)(1/hz * K) for lbl_880291B8 and lbl_880395A0 into +8/+0xC, else zeros */
/* Near miss (agAH): 2 off (/Oc /Os): fmuls operand order only (target t,K; candidate K,t with either spelling). */
extern const float lbl_88001A20, lbl_88001A68, lbl_880291B8, lbl_880395A0;
typedef struct Rate { int pad0; int pad4; int a; int b; } Rate;
void fn_883E0640(Rate *r, float hz)
{
    if (hz > lbl_88001A20) {
        float t = lbl_88001A68 / hz;
        float fa = t * lbl_880291B8;
        float fb = t * lbl_880395A0;
        r->a = (int)fa;
        r->b = (int)fb;
    } else {
        r->a = 0;
        r->b = 0;
    }
}
