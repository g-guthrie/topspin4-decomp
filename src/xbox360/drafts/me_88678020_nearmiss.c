/* NEAR MISS 0x88678020: 76 off (0x144 vs 0x14c): logic right; target computes the self-relative score base twice (add r7 / add r4, plus a dead mr) and loads match before the base. 6 variants (helpers, split offset locals, LTCG). */
typedef struct Score { char p[0xc]; int a; char q[0x14]; int b; } Score;
typedef struct RelScore { int offset; } RelScore;   /* self-relative Score */
static __inline Score *score_of(RelScore *r) { return (Score *)((char *)r + r->offset); }
typedef struct Mood { char p[0x24]; RelScore score; char q[0x38]; unsigned int prev; unsigned int cur; } Mood;
typedef struct Rules { char p[0x1d4]; int length; } Rules;
typedef struct Match { char p[0x38]; Rules *rules; } Match;
typedef struct Crowd { void *vt; Match *match; Mood *mood; } Crowd;

/* 0x88678020: crowd mood from the score: tense when a side is one game from the target length or the
   combined count passes the upper mark for this match length, warm past the lower mark, else calm. */
void ts4_crowd_update_mood_88678020(Crowd *c)
{
    unsigned char tense = 0;
    unsigned char warm = 0;
    Match *m;
    RelScore *rel;
    int len, last, total, a, b;
    c->mood->prev = c->mood->cur;
    m = c->match;
    rel = &c->mood->score;
    b = score_of(rel)->b;
    a = score_of(rel)->a;
    len = m->rules->length;
    total = b + a;
    last = len - 1;
    if (a == last || b == last) {
        tense = 1;
    } else {
        switch (len) {
        case 3:
            if (total >= 2)
                warm = 1;
            break;
        case 5:
            if (total >= 7)
                tense = 1;
            else if (total >= 3)
                warm = 1;
            break;
        case 7:
            if (total >= 10)
                tense = 1;
            else if (total >= 5)
                warm = 1;
            break;
        case 20:
            if (total >= 30)
                tense = 1;
            else if (total >= 15)
                warm = 1;
            break;
        case 40:
            if (total >= 60)
                tense = 1;
            else if (total >= 30)
                warm = 1;
            break;
        }
    }
    if (tense)
        c->mood->cur = 0xC920AC38;
    else if (warm)
        c->mood->cur = 0x4850AF43;
    else
        c->mood->cur = 0x26296DD2;
}
