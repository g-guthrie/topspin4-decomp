/* NEAR MISS (1 instruction): the game threads the empty-list branch straight to `share = 0` (skipping
 * the sum == 0 compare); this source branches to the compare. Tried if/else, ?:, guarded loop forms. */
/* 0x886C44C0: normalises the blend weights of a candidate list: every candidate's share becomes its
 * weight divided by the total weight (all shares 0 when the total is 0). */
typedef struct Cand { char p[0x88]; float weight; float share; char p2[0x98 - 0x90]; } Cand;
typedef struct CandList { char p[0xc]; Cand *begin; char p2[4]; Cand *end; } CandList;
extern float lbl_8814B440;
extern float g_ts4_script_constants[];
void f(CandList *l)
{
    Cand *c;
    Cand *b = l->begin, *e = l->end;
    float zero = lbl_8814B440;
    float sum = zero;
    float inv;
    for (c = b; c != e; c++) sum += c->weight;
    if (sum == zero) inv = zero; else inv = g_ts4_script_constants[0] / sum;
    for (c = b; c != e; c++) c->share = c->weight * inv;
}
