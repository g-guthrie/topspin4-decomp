/* NEAR MISS 0x88673078: 37 off (0x130 vs 0x138, LTCG): target loads *spin right after the select and reloads pr->speed for the over/under sign test (we reuse f31). 5 variants. */
double fn_88564BF8(float y, float x);   /* atan2 */
extern const float lbl_880C88DC;        /* angle offset */
extern const float g_ts4_event_value;   /* 0.0f */

typedef struct Shot { int pad; float speed; } Shot;
typedef struct RelPtr { int offset; } RelPtr;               /* self-relative, -1 = none */
typedef struct RelVec { int pad; RelPtr p; } RelVec;
static __inline int rel_valid(const RelPtr *r) { return r->offset != -1; }
static __inline const float *rel_get(const RelPtr *r) { return (const float *)((const char *)r + r->offset); }
typedef struct Pred {
    float speed; float angle; float spin; unsigned char valid; char p[3]; float t;
    float at[3]; char q[0x10]; float x0; char r[4]; float z0; char s[0x24]; float tgt[3];
} Pred;
typedef struct Tables { char p[0xb8]; float spin_slow; float spin_fast; } Tables;
typedef struct Flags { char p[0xc9]; unsigned char under; unsigned char over; } Flags;
typedef struct Ai { char p[0x2c]; Tables *tables; char q[8]; Flags *flags; } Ai;

/* 0x88673078: fill a shot prediction from the shot speed and the bearing to the aim point, then flag over/under speed. */
void ts4_ai_predict_shot_88673078(Ai *ai, const Shot *shot, Pred *pr, const RelVec *aim)
{
    if (shot && pr && rel_valid(&aim->p) && !pr->valid) {
        const float *p = rel_get(&aim->p);
        float speed = shot->speed;
        float a = (float)fn_88564BF8(p[2], p[0]);
        float b = (float)fn_88564BF8(pr->z0, pr->x0);
        const float *spin = &ai->tables->spin_slow;
        Flags *fl;
        float d;
        pr->speed = speed;
        pr->angle = a - b + lbl_880C88DC;
        if (!(speed < 200.0f))
            spin++;
        pr->spin = *spin;
        pr->at[0] = pr->tgt[0];
        pr->at[1] = pr->tgt[1];
        pr->at[2] = pr->tgt[2];
        pr->valid = 1;
        pr->t = g_ts4_event_value;
        fl = ai->flags;
        d = pr->speed - pr->tgt[0];
        if (*(unsigned short *)&d & 0x8000)
            fl->over = 1;
        else
            fl->under = 1;
    }
}
