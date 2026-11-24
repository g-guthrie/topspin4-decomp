/* 0x883E4000: stores scale at +8, rebases the four 0x4C-byte entries (+0x14) from the old base (+0x10) to a fresh one from fn_883CB860 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); after applying rate*scale; forwards each entry to the optional sink at +0x144, returning its error. */
typedef struct Ent { int f0, f4; int t; char pad[0x4c - 0xc]; } Ent;
typedef struct T { int f0; float rate; float scale; int f0c; int base; Ent e[4]; void *sink; } T;
void ts4_if_call_seq_fn_885640B0_883E3B10(float v);
int fn_883CB860(void);
int ts4_lookup_then_forward_88317C68(void *sink, Ent *e);
int ts4_rebase_entry_times_883E4000(T *t, float scale)
{
    int i;
    t->scale = scale;
    for (i = 0; i < 4; i++)
        t->e[i].t -= t->base;
    ts4_if_call_seq_fn_885640B0_883E3B10(t->rate * t->scale);
    t->base = fn_883CB860();
    for (i = 0; i < 4; i++) {
        t->e[i].t += t->base;
        if (t->sink) {
            int r = ts4_lookup_then_forward_88317C68(t->sink, &t->e[i]);
            if (r)
                return r;
        }
    }
    return 0;
}
