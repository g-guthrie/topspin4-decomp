/* 0x885C8A18: reset. Zeroes the 0x130-byte block (memset), zeroes the first 0x78 bytes again, then clears the words
 * from +0x78 to +0x128 field by field with the float at +0x80 set from a constant. */
void *memset(void *d, int c, unsigned int n);
typedef struct Self885C8A18 { char head[0x78]; int m78, m7c; float f80; int m84[25]; int me8, mec; int mf0[15]; char p12c[4]; } Self885C8A18;
extern const float lbl_88001A20;
void fn_885C8A18(Self885C8A18 *s)
{
    memset(s, 0, 0x130);
    memset(s, 0, 0x78);
    s->m78 = 0; s->m7c = 0;
    s->f80 = lbl_88001A20;
    s->m84[0] = 0; s->m84[1] = 0; s->m84[2] = 0; s->m84[3] = 0; s->m84[4] = 0; s->m84[5] = 0; s->m84[6] = 0; s->m84[7] = 0; s->m84[8] = 0; s->m84[9] = 0; s->m84[10] = 0; s->m84[11] = 0; s->m84[12] = 0; s->m84[13] = 0; s->m84[14] = 0; s->m84[15] = 0; s->m84[16] = 0; s->m84[17] = 0; s->m84[18] = 0; s->m84[19] = 0; s->m84[20] = 0; s->m84[21] = 0; s->m84[22] = 0; s->m84[23] = 0; s->m84[24] = 0;
    s->mec = 0; s->me8 = 0;
    s->mf0[0] = 0; s->mf0[1] = 0; s->mf0[2] = 0; s->mf0[3] = 0; s->mf0[4] = 0; s->mf0[5] = 0; s->mf0[6] = 0; s->mf0[7] = 0; s->mf0[8] = 0; s->mf0[9] = 0; s->mf0[10] = 0; s->mf0[11] = 0; s->mf0[12] = 0; s->mf0[13] = 0; s->mf0[14] = 0;
}
