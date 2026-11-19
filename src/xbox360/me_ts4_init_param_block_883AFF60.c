/* 0x883AFF60: sets an 11-float block to {-1, 0 x9, -1} */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct { float v[11]; } P;
void ts4_init_param_block_883AFF60(P *p) { p->v[0] = -1.0f; p->v[1] = 0.0f; p->v[2] = 0.0f; p->v[3] = 0.0f; p->v[4] = 0.0f; p->v[5] = 0.0f; p->v[6] = 0.0f; p->v[7] = 0.0f; p->v[8] = 0.0f; p->v[9] = 0.0f; p->v[10] = -1.0f; }
