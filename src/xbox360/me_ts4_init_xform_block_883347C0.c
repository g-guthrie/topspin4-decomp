/* 0x883347C0: zeroes the first nine floats and writes three unit-axis triples at +0x30, +0x48 and +0x60 */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct { float v[27]; } P;
void ts4_init_xform_block_883347C0(P *p) { p->v[0] = 0.0f; p->v[1] = 0.0f; p->v[2] = 0.0f; p->v[3] = 0.0f; p->v[4] = 0.0f; p->v[5] = 0.0f; p->v[6] = 0.0f; p->v[7] = 0.0f; p->v[8] = 0.0f; p->v[12] = 0.0f; p->v[13] = 1.0f; p->v[14] = 0.0f; p->v[18] = 0.0f; p->v[19] = 0.0f; p->v[20] = 1.0f; p->v[24] = 1.0f; p->v[25] = 0.0f; p->v[26] = 0.0f; }
