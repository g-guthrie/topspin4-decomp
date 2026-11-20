/* 0x884C19A0: returns c / (a * k0 * k1 / b * k2 * k3) / d with the .rdata factors lbl_8808A848/44/40 and lbl_8800444C. */
/* Near miss (agAB, /Oc /fp:precise): 1 off, the first fmuls has its operands swapped (target f1,f0). /fp:precise is
 * needed to keep the source order. Factor order, a scale helper, a constant getter, an identity helper and locals all tried. */
extern const float lbl_8808A848, lbl_8808A844, lbl_8808A840, lbl_8800444C;
float fn_884C19A0(float a, float b, float c, float d)
{
    return c / (a * lbl_8808A848 * lbl_8808A844 / b * lbl_8808A840 * lbl_8800444C) / d;
}
