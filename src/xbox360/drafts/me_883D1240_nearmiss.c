/* 0x883D1240 near miss (2 off, /O1): audio update: when enabled (+0x809C), computes the clock delta, ticks each group's voices (stop on first error), updates every stream, the child, clears flag 8 and commits the database. */
/* Residue: in the voice loop the target loads cur->voice before l = l->next; a voice local reshapes the loop (44 off). The (next = l) != end test gives the target's rotation. */
typedef struct Link { struct Link *next; } Link;
typedef struct Ent { Link link; int p4; void *voice; } Ent;
typedef struct Grp { int p0; Link link; char p8[0x6C - 8]; Link ents; } Grp;
typedef struct T { char pad[0x14]; void *db; void *child; char p1c[0x28 - 0x1C]; unsigned int last; char p2c[0x8078 - 0x2C]; Link streams; char p807c[0x8084 - 0x807C]; Link groups; char p8088[0x809C - 0x8088]; void *enabled; char p80a0[8]; unsigned int flags; } T;
int ts4_call_seq_fn_8857B830_8831A8B8(unsigned int *now);
int fn_883C75D0(void *voice, unsigned int dt);
int fn_883EDEF8(void *s, unsigned int dt);
int ts4_forward_to_child_nonzero_883E40C0(void *c);
int ts4_if_call_seq_fn_88309DB8_88308F90(void *db);
int ts4_audio_update_883D1240(T *t)
{
    unsigned int now, dt;
    Link *n, *l, *next;
    Grp *g;
    int r;
    if (t->enabled) {
        if (!t->last) ts4_call_seq_fn_8857B830_8831A8B8(&t->last);
        ts4_call_seq_fn_8857B830_8831A8B8(&now);
        dt = now >= t->last ? now - t->last : now;
        t->last = now;
        for (n = t->groups.next; n != &t->groups; n = n->next) {
            g = n ? (Grp *)((char *)n - 4) : 0;
            for (l = g->ents.next; (next = l) != &g->ents; ) {
                l = l->next;
                if (fn_883C75D0(((Ent *)next)->voice, dt)) break;
            }
        }
        for (n = t->streams.next; n != &t->streams; n = n->next) {
            r = fn_883EDEF8(n ? (char *)n - 4 : 0, dt);
            if (r) return r;
        }
    }
    if (t->child) {
        r = ts4_forward_to_child_nonzero_883E40C0(t->child);
        if (r) return r;
    }
    t->flags &= ~8;
    return ts4_if_call_seq_fn_88309DB8_88308F90(t->db);
}
