/* 0x883D1240 (/O1): FMOD audio system update. When enabled (+0x809C) it computes the clock
 * delta, ticks each group's voice entries (stopping at the first that reports non-zero),
 * updates every stream (returning its error), forwards to the child, clears flag 8 and
 * commits the database.
 * Matching note: the voice must be read through the inline accessor Ts4FmodVoiceEntry::getData()
 * (implicit this); reading the field directly schedules l = l->next before the voice load
 * (2 off). The outer update matches as a member or as a free function; it is a member here
 * because the original is class-based. */
extern "C" int ts4_call_seq_fn_8857B830_8831A8B8(unsigned int *now);
extern "C" int fn_883C75D0(void *voice, unsigned int dt);
extern "C" int fn_883EDEF8(void *stream, unsigned int dt);
extern "C" int ts4_forward_to_child_nonzero_883E40C0(void *child);
extern "C" int ts4_if_call_seq_fn_88309DB8_88308F90(void *db);

struct Ts4FmodLink { Ts4FmodLink *next; };

struct Ts4FmodVoiceEntry {
    Ts4FmodLink link;
    int pad04;
    void *voice;                              /* +0x08 */
    void *getData() { return voice; }
    Ts4FmodLink *getNext() { return link.next; }
};

struct Ts4FmodVoiceGroup {
    int pad00;
    Ts4FmodLink link;                         /* +0x04: node in the system's group list */
    char pad08[0x6C - 0x08];
    Ts4FmodLink entries;                      /* +0x6C */

    void tick(unsigned int dt)
    {
        Ts4FmodLink *l, *next;
        for (l = entries.next; (next = l) != &entries; ) {
            l = l->next;
            if (fn_883C75D0(((Ts4FmodVoiceEntry *)next)->getData(), dt))
                break;
        }
    }
};

struct Ts4FmodAudioSystem {
    char pad00[0x14];
    void *db;                                 /* +0x14 */
    void *child;                              /* +0x18 */
    char pad1c[0x28 - 0x1C];
    unsigned int last;                        /* +0x28 */
    char pad2c[0x8078 - 0x2C];
    Ts4FmodLink streams;                      /* +0x8078 */
    char pad807c[0x8084 - 0x807C];
    Ts4FmodLink groups;                       /* +0x8084 */
    char pad8088[0x809C - 0x8088];
    void *enabled;                            /* +0x809C */
    char pad80a0[8];
    unsigned int flags;                       /* +0x80A8 */

    int update();
};

int Ts4FmodAudioSystem::update()
{
    unsigned int now, dt;
    Ts4FmodLink *n;
    int r;
    if (enabled) {
        if (!last)
            ts4_call_seq_fn_8857B830_8831A8B8(&last);
        ts4_call_seq_fn_8857B830_8831A8B8(&now);
        dt = now >= last ? now - last : now;
        last = now;
        for (n = groups.next; n != &groups; n = n->next) {
            Ts4FmodVoiceGroup *g = n ? (Ts4FmodVoiceGroup *)((char *)n - 4) : 0;
            g->tick(dt);
        }
        for (n = streams.next; n != &streams; n = n->next) {
            r = fn_883EDEF8(n ? (char *)n - 4 : 0, dt);
            if (r)
                return r;
        }
    }
    if (child) {
        r = ts4_forward_to_child_nonzero_883E40C0(child);
        if (r)
            return r;
    }
    flags &= ~8;
    return ts4_if_call_seq_fn_88309DB8_88308F90(db);
}
