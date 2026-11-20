/* 0x8832B1D8: Fills the 0x2000-entry float table at +0x20000 with fn_88564550(i * lbl_8802921C) (a CRT math routine taking and returning double) and returns the object. */
/* Matched on /Oc (agAH). Step constant read into a local before the loop (kept in f31); index converted implicitly (i * step). */
extern const float lbl_8802921C;
double fn_88564550(double x);
typedef struct Table { char pad[0x20000]; float values[0x2000]; } Table;
Table *fn_8832B1D8(Table *t)
{
    int i;
    float step = lbl_8802921C;
    for (i = 0; i < 0x2000; i++)
        t->values[i] = (float)fn_88564550(i * step);
    return t;
}
