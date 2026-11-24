/* 0x886E3818 near miss (31 off, /Oc plain; all r30/r31 swaps plus one lwzx operand order): queries the venue
 * database for court and prop entries (fn_8892E240 with a null xdata ref {0, 0xFFFFF, 0}), binds each court with its
 * entries (fn_886E31F0, ts4_court_res_bind = 0x886CDED0) and frees both result vectors. The game shares one saved
 * zero register for the vector inits and the loop offsets and keeps self in r30. Declaration order, int/unsigned
 * count, pads 1-3: no change. */
typedef unsigned int u32;
typedef struct TS4TripleArg { u32 first, second, third; } TS4TripleArg;
typedef struct Ts4XdataRef { u32 node; u32 offset; u32 extra; } Ts4XdataRef;
typedef struct Ts4Found { TS4TripleArg handle; char rest[0x1c - 0xc]; } Ts4Found;
typedef struct Ts4FoundVec { Ts4Found *begin, *end, *cap; } Ts4FoundVec;
typedef struct Ts4Db { char p[0x40]; char courts[4]; char props[4]; } Ts4Db;
typedef struct Ts4Venue { char p[0x28]; TS4TripleArg handle; char p2[0x48 - 0x34]; Ts4Db *db; char p3[0x50 - 0x4c]; void **begin; void **end; } Ts4Venue;
void fn_8892E240(void *table, Ts4FoundVec *out, TS4TripleArg handle, Ts4XdataRef filter);
void fn_886E31F0(void *court, TS4TripleArg h);
void ts4_court_res_bind(void *court, TS4TripleArg h);
void ts4_destroy_owned_object(void *p);
static __inline Ts4XdataRef no_ref(void) { Ts4XdataRef r; r.node = 0; r.offset = 0xFFFFF; r.extra = 0; return r; }
void ts4_venue_bind_courts(Ts4Venue *self)
{
    Ts4FoundVec a, b;
    unsigned n, i;
    int pad0 = 0;
    int pad1 = 0;
    int pad2 = 0;
    a.begin = 0; a.end = 0; a.cap = 0;
    b.begin = 0; b.end = 0; b.cap = 0;
    fn_8892E240(self->db->courts, &a, self->handle, no_ref());
    fn_8892E240(self->db->props, &b, self->handle, no_ref());
    n = (int)(self->end - self->begin);
    for (i = 0; i < n; i++) {
        fn_886E31F0(self->begin[i], a.begin[i].handle);
        ts4_court_res_bind(self->begin[i], b.begin[i].handle);
    }
    if (b.begin) ts4_destroy_owned_object(b.begin);
    if (a.begin) ts4_destroy_owned_object(a.begin);
    (void)pad0;
    (void)pad1;
    (void)pad2;
}
