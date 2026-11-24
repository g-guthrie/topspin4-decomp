/* 0x8859BB40: returns (unsigned)(n * scale + 1.0) + 1 when up is set, else (unsigned)(n * scale + 0.5). */
/* Matched on /O1 (agAB). Unsigned result gives fctidz; /O1 keeps f0 reuse. */
extern const double lbl_880038D0;
extern const double lbl_88007B20;
unsigned int fn_8859BB40(unsigned int n, float scale, int up)
{
    float f = (float)n * scale;
    if (up)
        return (unsigned int)(f + lbl_880038D0) + 1;
    return (unsigned int)(f + lbl_88007B20);
}
