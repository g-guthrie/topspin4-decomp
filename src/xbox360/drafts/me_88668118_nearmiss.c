/* near-miss 0x88668118 (plain /Oc): 17 instructions off, same size. Open: add operand order of the relative-array index at five sites (source spelling of the index expression has no effect) and the load order of stats/server at the first lookup. */
/* 0x88668118: point-end statistics: clears the three "won by" flags, then (unless replaying or the ball is dead)
 * counts receive points, service points won, and for the point winner's opponent's last shot an unforced error
 * (flag 0xc) or winner (flag 0xd). */
typedef struct RelArr { int self_off; } RelArr;
typedef struct ShotStat { unsigned int made; unsigned int limit; int won; unsigned char error; unsigned char winner; char p[2]; } ShotStat;
typedef struct RallyStat { char p[0x34]; int receives; char p2[0x3c - 0x38]; int errors; } RallyStat;
typedef struct PointStat { char p[0x64]; int points; char p2[0x6c - 0x68]; int winners; char p3[0x134 - 0x70]; } PointStat;
typedef struct MatchStats {
    char p[0x18]; int winner; char p1[0x33 - 0x1c]; unsigned char serve_won, error_won, winner_won; char p2[0x3c - 0x36];
    RelArr shots; char p3[0x4c - 0x40]; RelArr rallies; char p4[0x5c - 0x50]; RelArr points;
} MatchStats;
typedef struct PtCourt { char p[0xa8]; int server; char p2[0xe4 - 0xac]; unsigned char replay; } PtCourt;
typedef struct PtCtx { char p[0x30]; PtCourt *court; } PtCtx;
typedef struct PtBall { char p[0x99]; unsigned char dead; } PtBall;
typedef struct PointEnd { char p[0x20]; PtBall *ball; char p2[0x28 - 0x24]; MatchStats *stats; char p3[0x34 - 0x2c]; PtCtx *ctx; } PointEnd;
static __inline ShotStat *shot_at(MatchStats *m, int i) { RelArr *a = &m->shots; return (ShotStat *)((char *)a + a->self_off) + i; }
static __inline RallyStat *rally_at(MatchStats *m, int i) { RelArr *a = &m->rallies; return (RallyStat *)((char *)a + a->self_off) + i; }
static __inline PointStat *point_at(MatchStats *m, int i) { RelArr *a = &m->points; return (PointStat *)((char *)a + a->self_off) + i; }
static __inline void inc(int *p) { (*p)++; }
void fn_88668118(PointEnd *s)
{
    PtCourt *c;
    int srv, rcv, win;
    s->stats->winner_won = 0;
    s->stats->error_won = 0;
    s->stats->serve_won = 0;
    c = s->ctx->court;
    if (c->replay) return;
    if (s->ball->dead) return;
    srv = c->server;
    rcv = srv ^ 1;
    win = s->stats->winner;
    if (shot_at(s->stats, rcv)->made > 0) {
        inc(&rally_at(s->stats, rcv)->receives);
        inc(&point_at(s->stats, rcv)->points);
    }
    if (shot_at(s->stats, rcv)->made < shot_at(s->stats, rcv)->limit) {
        inc(&shot_at(s->stats, srv)->won);
        s->stats->serve_won = 1;
    }
    if (shot_at(s->stats, win ^ 1)->made >= shot_at(s->stats, win ^ 1)->limit) return;
    if (shot_at(s->stats, win ^ 1)->error == 1) {
        inc(&rally_at(s->stats, win)->errors);
        s->stats->error_won = 1;
    }
    if (shot_at(s->stats, win ^ 1)->winner == 1) {
        inc(&point_at(s->stats, win)->winners);
        s->stats->winner_won = 1;
    }
}
