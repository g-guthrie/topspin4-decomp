/* 0x886D8928 (hand match): when the owner's flag is set, refresh the timing pair (value, value minus the
 * current lead when positive) into both sub-objects and re-submit the node. */
typedef struct Own { char p[0x184]; unsigned char b184; } Own;
typedef struct Mid { char p[0x48]; Own *f48; } Mid;
typedef struct Link { char p[0x10]; Mid *f10; void *f14; } Link;
typedef struct Node { char p[0x70]; char f70[4]; } Node;
typedef struct Self { char p[0x12]; unsigned char b12; char p2[5]; float f18; char p3[4]; Link *f20; char p4[8]; Node *f2c; char p5[0x28]; char f58[0x1c]; char f74[4]; } Self;
void fn_882694D0(Node *n, int on);
float fn_886D62F8(Self *s);
void ts4_swan_update_held_elems_886D8078(void *sub, float *pair);
void fn_886D6AD0(void *sub, float *pair);
void fn_88649A90(Node *n, void *p);
void ts4_if_call_seq_fn_886465A0_88648590(Node *n, Own *o, void *x);
void ts4_refresh_timing_pair_886D8928(Self *s)
{
    if (s->f20->f10->f48->b184) {
        float pair[2];
        float lead, v, w;
        fn_882694D0(s->f2c, s->b12 != 0);
        lead = fn_886D62F8(s);
        v = s->f18;
        if (v > 0.0f) w = v - lead; else w = v;
        pair[0] = v; pair[1] = w;
        ts4_swan_update_held_elems_886D8078(s->f74, pair);
        fn_886D6AD0(s->f58, pair);
        fn_88649A90(s->f2c, s->f2c->f70);
        ts4_if_call_seq_fn_886465A0_88648590(s->f2c, s->f20->f10->f48, s->f20->f14);
    }
}
