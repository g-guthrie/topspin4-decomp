/* 0x88399768: below weight 0.5 at +0x28, clears the two 8-entry 0x1C-byte blocks and the two 4-entry 0x10-byte blocks */
/* Matched on /Oc (agAH). Float literal 0.5f (lbl_8802E958 holds 0.5); paired calls per index in two counted loops. */
typedef struct F7 { float v[7]; } F7;
typedef struct F4 { float v[4]; } F4;
typedef struct T { char p[0x28]; float weight; F7 a[8]; F7 b[8]; F4 c[4]; F4 d[4]; } T;
extern void ts4_zero_floats_10_883B1D28(F7 *p);
extern void ts4_zero_floats_4_883B1DA8(F4 *p);
void fn_88399768(T *t)
{
    int i;
    if (t->weight < 0.5f) {
        for (i = 0; i < 8; i++) {
            ts4_zero_floats_10_883B1D28(&t->a[i]);
            ts4_zero_floats_10_883B1D28(&t->b[i]);
        }
        for (i = 0; i < 4; i++) {
            ts4_zero_floats_4_883B1DA8(&t->c[i]);
            ts4_zero_floats_4_883B1DA8(&t->d[i]);
        }
    }
}
