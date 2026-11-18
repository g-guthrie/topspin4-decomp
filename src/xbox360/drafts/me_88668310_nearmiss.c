/* agentA2 2026-11-18: skipped: commutative index-add operand order (tips: not covered when loaded off params); still 2. */
/* NEAR MISS (2 instructions): commutative operand order of two index adds (side won, receiver run)
 * is swapped. An unsigned (sizeof) side stride fixed a third site. */
/* 0x88668310: records a point won by the current server. Skipped while a replay or challenge is
 * active, for two named match modes, or when no server is set. Counts the point and service point
 * for the server's side and player, bumps both sides' and players' points-played totals, and
 * clears the receiving side's run. */
typedef struct SideStat { char p[0x28]; int played; int won; int run; char p2[0x40 - 0x34]; } SideStat;
typedef struct PStat { char p[0x54]; int played; int won; char p2[0x134 - 0x5c]; } PStat;
typedef struct STable { int offset; } STable;
typedef struct PTable { int offset; } PTable;
typedef struct Stats { char p[0x4c]; STable sides; char p2[0x5c - 0x50]; PTable players; } Stats;
typedef struct Match { char p[0x99]; unsigned char challenge; char p2[0xd0 - 0x9a]; unsigned int mode; char p3[0xd7 - 0xd4]; unsigned char replay; int server; } Match;
typedef struct Tracker { char p[0x20]; Match *match; char p2[0x28 - 0x24]; Stats *stats; } Tracker;
static __forceinline PStat *pat(PTable *t, int i) { int off = t->offset; return (PStat *)((char *)t + (i * 0x134 + off)); }
static __forceinline SideStat *sat(STable *t, int i) { int off = t->offset; return (SideStat *)((char *)t + (i * sizeof(SideStat) + off)); }
void ts4_record_server_point_88668310(Tracker *tr)
{
    Match *m = tr->match;
    int s, o;
    if (m->replay) return;
    if (m->challenge) return;
    if (m->mode == 0xC9238771 || m->mode == 0xD1335606) return;
    s = m->server;
    if (s == -1) return;
    o = s ^ 1;
    sat(&tr->stats->sides, s)->won++;
    pat(&tr->stats->players, s)->won++;
    sat(&tr->stats->sides, s)->run++;
    sat(&tr->stats->sides, s)->played++;
    pat(&tr->stats->players, s)->played++;
    sat(&tr->stats->sides, o)->played++;
    pat(&tr->stats->players, o)->played++;
    sat(&tr->stats->sides, o)->run = 0;
}
