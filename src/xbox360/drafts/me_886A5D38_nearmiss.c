/* rough draft 0x886A5D38 (ME agent B): 209 off (/Oc). For each tracked item: save body pose blocks (+0xF20 9 floats,
 * +0xF44 15 floats), run the move sequences and the rate update, copy the resulting pose into the controller, then
 * restore the saved pose and limits. Target keeps several float constants in f27-f31 (savefpr). Untuned. */
typedef unsigned char U8;
extern float g_ts4_event_value;
extern const float g_ts4_script_constants[];
typedef struct Pose9 { float v[9]; } Pose9;
typedef struct Pose15 { float v[15]; } Pose15;
typedef struct Body { char p[0xf20]; Pose9 cur; Pose15 aux; } Body;
typedef struct Flags { char p[0x98]; U8 b98, b99, b9a, b9b; char p9c[0xd4 - 0x9c]; U8 d4, d5; char pd6[0xdc - 0xd6]; U8 dc; } Flags;
typedef struct Mode { int kind; } Mode;
typedef struct Live { char p[0x40]; struct { char p[0x8d]; U8 tracking; } *opts; Flags *flags; char p48[0x78 - 0x48]; Mode *mode; } Live;
typedef struct Speeds { char p[0x624]; float normal, fast, slow; } Speeds;
typedef struct Player { char p[0x2c]; Speeds *speeds; char p30[0x48 - 0x30]; Live *live; char p4c[0x74 - 0x4c]; Body *body; } Player;
typedef struct Ctl { Player *pl; char p4[0x48 - 4]; char seqA[0x8c - 0x48]; char seqB[0x158 - 0x8c]; float *a; float *b; float *a_out; float *b_out; Pose9 cur; Pose15 aux; } Ctl;
typedef struct Item { char p[0x40]; U8 *disabled; char p44[0x6c - 0x44]; Ctl *ctl; } Item;
typedef struct List { char p[4]; Item **begin; Item **end; } List;
void ts4_loop_call_seq_u32_off2c_8890E988(void *seq);
void fn_8866EE48(Ctl *c, float rate);
void fn_88690540(void);
void ts4_set_range_progress_8865F858(Ctl *c);
void fn_886A5D38(List *self)
{
    Item **it;
    float ev = g_ts4_event_value, one = g_ts4_script_constants[0];
    for (it = self->begin; it != self->end; it++) {
        Ctl *c;
        Live *lv;
        Body *body;
        float a, b, rate;
        Pose9 s9;
        Pose15 s15;
        Flags *fl;
        U8 busy;
        if (!*it || *(*it)->disabled)
            continue;
        c = (*it)->ctl;
        lv = c->pl->live;
        if (lv->mode->kind != 2 || !lv->opts->tracking)
            continue;
        body = c->pl->body;
        a = *c->a;
        b = *c->b;
        s9 = body->cur;
        s15 = body->aux;
        fl = lv->flags;
        busy = fl->b99 ? 1 : fl->b98 ? 0 : fl->b9b ? 1 : 0;
        if (!busy) {
            if (!fl->d5 && !fl->d4)
                ts4_loop_call_seq_u32_off2c_8890E988(c->seqA);
            else
                body->aux.v[8] = s15.v[14];
            ts4_loop_call_seq_u32_off2c_8890E988(c->seqB);
        }
        fl = c->pl->live->flags;
        rate = fl->d5 ? c->pl->speeds->slow : fl->dc ? c->pl->speeds->fast : c->pl->speeds->normal;
        if (rate == ev)
            rate = one;
        fn_8866EE48(c, rate);
        fn_88690540();
        c->pl->body->cur.v[2] = ev;
        *c->a_out = *c->a;
        *c->b_out = *c->b;
        c->cur = body->cur;
        c->aux = body->aux;
        *c->a = a;
        *c->b = b;
        body->cur = s9;
        body->aux = s15;
        ts4_set_range_progress_8865F858(c);
    }
}
