/* RT1 EQUIVALENT (not byte-matched; ~10 instructions of scheduling differ with /Oc).
 * Evidence: work/equiv/rt1_886629C8.json (fn_equiv: 84 valid trials of 471, coverage 100%, 15/15 blocks). */
/*
 * RT1: ShotSpecific grade fill (docs/gameplay/gp8.md s4.2, OPEN 1.5/1.9).
 * `eval` is the shot context SC: {+0 PlayerCtx *pc, +4 PlayerState *S, +0x10/+0x14 EvaluateList begin/end,
 * +0x100 chosen EvaluateList entry}. B = S + 0x66C is the grade block.
 */

struct Rt1GradePair { float a; float b; };
struct Rt1GradeQuad { float v[4]; };

struct Rt1Match { unsigned char pad0[0x32a]; unsigned char flag_32a; };

struct Rt1PlayerCtx {
    unsigned char pad0[0x18];
    unsigned int  word_18;
    unsigned char pad1[0x48 - 0x1c];
    char         *world;             /* +0x48 */
    void         *link;              /* +0x4C */
};

struct Rt1PlayerState {
    unsigned char pad0[0x3b4];
    unsigned int  grade_a;           /* +0x3B4 swing key Power */
    unsigned int  grade_b;           /* +0x3B8 swing key Control */
    unsigned char pad1[0x66c - 0x3bc];
    char blk[0x200];        /* +0x66C grade block B */
};

struct Rt1EvalEntry { unsigned char pad0[0x10]; unsigned int key; };

struct Rt1ShotEval {
    struct Rt1PlayerCtx *pc;
    struct Rt1PlayerState *state;
    unsigned char pad0[8];
    struct Rt1EvalEntry **list_begin;  /* +0x10 */
    struct Rt1EvalEntry **list_end;    /* +0x14 */
    unsigned char pad1[0x100 - 0x18];
    struct Rt1EvalEntry *chosen;       /* +0x100 */
};

struct Rt1ShotRecord {
    unsigned char pad0[4];
    char *rel;                         /* +4 self-relative record */
    unsigned char pad1[8];
    char *table;                       /* +0x10 XData record T */
};

void ts4_grade_table_pair_8826DD20(const void *table, const unsigned int *grade, void *out);
void ts4_grade_table_quad_8826DDF8(const void *table, const unsigned int *grade, void *out);
float ts4_timing_grade_factor_8865AC08(const unsigned int *grade);

#ifdef _MSC_VER
#define RT1_INLINE __inline
#else
#define RT1_INLINE inline
#endif

/* Serve/ground-stroke selector: true when the match flag is set, the current match target differs from the
 * link's, and the link's owner is this controller. Picks which of the two XData words feeds B+0x70. */
static RT1_INLINE unsigned char rt1_use_alt_word(struct Rt1PlayerCtx *pc)
{
    char *m = *(char **)(pc->world + 0x30);
    if (*(unsigned char *)(m + 0x32a) != 0) {
        char *lk = (char *)pc->link;
        if (*(int *)(m + 0xa8) != *(int *)(lk + 0x28) &&
            *(int *)(*(char **)(lk + 0x24) + 0xb8) == (int)pc->word_18)
            return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x886629C8 */
void ts4_shot_specific_fill_886629C8(struct Rt1ShotEval *eval, struct Rt1ShotRecord *rec)
{
    char *b = eval->state->blk;
    char *t = rec->table;
    struct Rt1EvalEntry *found;
    struct Rt1EvalEntry **it;
    struct Rt1EvalEntry **end;

    if (t != 0) {
        /* PERM_DECLS */
        unsigned int grade_a = eval->state->grade_a;
        unsigned int grade_b = eval->state->grade_b;
        /* PERM_DECLS_END */
        ts4_grade_table_pair_8826DD20(t, &grade_a, b + 0x50);
        ts4_grade_table_quad_8826DDF8(t + 0x28, &grade_b, b + 0x58);
        ts4_grade_table_pair_8826DD20(t + 0x78, &grade_b, b + 0x68);
        {
            float fa = ts4_timing_grade_factor_8865AC08(&grade_a);
            float fb;
            *(float *)(b + 0x12c) = fa;
            fb = ts4_timing_grade_factor_8865AC08(&grade_b);
            *(float *)(b + 0x130) = fb;
        }
        {
            unsigned char alt = rt1_use_alt_word(eval->pc);
            *(unsigned int *)(b + 0x70) = *(unsigned int *)(alt ? t + 0xa4 : t + 0xa0);
        }
    } else {
        char *base = rec->rel + 0x10;
        int off = *(int *)base;
        if (off != -1) {
            float *p = (float *)(base + off);
            *(float *)(b + 0x38) = p[0];
            *(float *)(b + 0x3c) = p[1];
            *(float *)(b + 0x40) = p[2];
            *(float *)(b + 0x44) = p[3];
            *(float *)(b + 0x48) = p[4];
            *(unsigned int *)(b + 0x4c) = ((unsigned int *)p)[5];
            *(unsigned int *)(b + 0x70) = ((unsigned int *)(base + *(int *)base))[5];
        }
    }
    *(unsigned int *)(b + 0xa0) = *(unsigned int *)(rec->rel + 0x88);
    found = 0;
    end = eval->list_end;
    it = eval->list_begin;
    for (; it != end; it++) {
        if (*(unsigned int *)(b + 0x70) == (*it)->key) { found = *it; break; }
    }
    eval->chosen = found;
}
