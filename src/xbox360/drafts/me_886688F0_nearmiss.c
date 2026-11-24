/* NEAR MISS (11 instructions): operand order of the index adds (i*0x134 + offset) and the best-run
 * compare differ; the reloaded offset and dead `mr` copies already match. */
/* 0x886688F0: records a won point for the current server. Skipped while a replay or challenge is
 * active, for two named match modes, or when no server is set. Bumps the server's run of points,
 * banks and resets the receiver's run, keeps the server's best run, and after three consecutive
 * points for the same side counts a streak for that player. */
typedef struct PStat { char p[0x9c]; int run; int last_run; unsigned int best_run; char p2[0xd8 - 0xa8]; int streaks; char p3[0x134 - 0xdc]; } PStat;
typedef struct PTable { int offset; } PTable;
typedef struct Stats { char p[0x5c]; PTable players; } Stats;
typedef struct Match { char p[0x99]; unsigned char challenge; char p2[0xd0 - 0x9a]; unsigned int mode; char p3[0xd7 - 0xd4]; unsigned char replay; int server; } Match;
typedef struct Tracker { char p[0x20]; Match *match; char p2[0x28 - 0x24]; Stats *stats; char p3[0x39c - 0x2c]; unsigned int consecutive[2]; } Tracker;
static __forceinline PStat *at(PTable *t, int i) { int off = t->offset; return (PStat *)((char *)t + (i * 0x134 + off)); }
void ts4_record_point_streaks_886688F0(Tracker *tr)
{
    Match *m = tr->match;
    int s = m->server;
    if (m->replay) return;
    if (m->challenge) return;
    if (m->mode == 0xC9238771 || m->mode == 0xD1335606) return;
    if (s == -1) return;
    at(&tr->stats->players, s)->run++;
    at(&tr->stats->players, 1 - s)->last_run = at(&tr->stats->players, 1 - s)->run;
    at(&tr->stats->players, 1 - s)->run = 0;
    if (at(&tr->stats->players, s)->best_run < at(&tr->stats->players, s)->run) at(&tr->stats->players, s)->best_run = at(&tr->stats->players, s)->run;
    tr->consecutive[s]++;
    tr->consecutive[1 - s] = 0;
    if (tr->consecutive[s] >= 3) at(&tr->stats->players, s)->streaks++;
}
