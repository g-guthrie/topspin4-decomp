/* 0x883E4438: reads a float parameter: 0x25 for a null out, which is reset to lbl_88001A20; 0x5F without a handle (+8) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); finds key through the manager from ts4_get_u32_lbl_88CAC9A8_883E6388 (slot 3; 0x60 if missing) and stores its value (slot 2). */
extern const float lbl_88001A20;
typedef struct P P;
typedef struct PVt { void *s[2]; float (*get)(P *p); } PVt;
struct P { PVt *vt; };
typedef struct M M;
typedef struct MVt { void *s[3]; P *(*find)(M *m, int key); } MVt;
struct M { MVt *vt; };
typedef struct T { int f0, f4; void *h; } T;
M *ts4_get_u32_lbl_88CAC9A8_883E6388(void);
int ts4_get_param_float_883E4438(T *t, int key, float *out)
{
    P *p;
    M *m;
    if (!out)
        return 0x25;
    *out = lbl_88001A20;
    if (!t->h)
        return 0x5f;
    m = ts4_get_u32_lbl_88CAC9A8_883E6388();
    p = m->vt->find(m, key);
    if (!p)
        return 0x60;
    *out = p->vt->get(p);
    return 0;
}
