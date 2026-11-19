/* 0x8890C618: stores the 4-float vector v into slot i of the 16-byte array at +0x1780 and sets bit (63 - i/4) of the 64-bit dirty mask at +0x8. */
/* Near-miss on /Oc (agAB): 1 instruction off at +0x2C. The target computes the shift count with srwi r7,r4,2; this source zero-extends to 64 bits instead (rldicl r7,r4,62,34). */
typedef struct V4 { float x, y, z, w; } V4;
typedef struct S { char p0[8]; unsigned __int64 dirty; char p[0x1780 - 0x10]; V4 v[1]; } S;
void fn_8890C618(S *__restrict s, unsigned int i, const float *__restrict v)
{
    s->v[i].x = v[0];
    s->v[i].y = v[1];
    s->v[i].z = v[2];
    s->v[i].w = v[3];
    s->dirty |= 0x8000000000000000ULL >> (i >> 2);
}
