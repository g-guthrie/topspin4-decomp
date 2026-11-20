/* 0x883FBEB0: applies an optional target value (slot 1, signed null test), and when the embedded clock's current item changed reschedules by the new sound's length (bank slot 3, sound slot 10) or clears the due stamp; 0x21 if the sound is missing */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Clk Clk;
typedef struct ClkVt { void *f0, *f1, *f2; void *(*cur)(Clk *c); } ClkVt;
struct Clk { ClkVt *vt; };
typedef struct Snd Snd;
typedef struct SndVt { void *f[10]; unsigned int (*length)(Snd *s); } SndVt;
struct Snd { SndVt *vt; };
typedef struct Bank Bank;
typedef struct BankVt { void *f0, *f1, *f2; Snd *(*find)(Bank *b, void *id); } BankVt;
struct Bank { BankVt *vt; };
typedef struct Tgt Tgt;
typedef struct TgtVt { void *f0; int (*set)(Tgt *g, void *v); } TgtVt;
struct Tgt { TgtVt *vt; };
typedef struct Arg { Tgt *tgt; void *val; } Arg;
typedef struct Cfg { char pad[0x1c]; void *manual; } Cfg;
typedef struct T {
    char pad0[0x14];
    Cfg *cfg;
    char pad1[0x20 - 0x18];
    Clk clk;
    char pad2[0x88 - 0x24];
    u64 due;
} T;
Bank *ts4_get_u32_lbl_88CAC9A8_883E63C0(void);
int ts4_schedule_due_883FB6B8(T *t, u64 delay);

int fn_883FBEB0(T *t, Arg *a)
{
    Clk *c = &t->clk;
    void *prev, *cur;
    prev = c->vt->cur(c);
    if (PTR_INT(a->tgt) != 0 && a->val) {
        int r = a->tgt->vt->set(a->tgt, a->val);
        if (r)
            return r;
    }
    cur = c->vt->cur(c);
    if (cur != prev) {
        if (cur && !t->cfg->manual) {
            Bank *bk = ts4_get_u32_lbl_88CAC9A8_883E63C0();
            Snd *s = bk->vt->find(bk, cur);
            if (!s)
                return 0x21;
            ts4_schedule_due_883FB6B8(t, s->vt->length(s));
        } else {
            t->due = 0;
        }
    }
    return 0;
}
