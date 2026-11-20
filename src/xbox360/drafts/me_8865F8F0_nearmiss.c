/* NEAR MISS 0x8865F8F0: 62 off (0x11c vs 0x128): target schedules the profile/table loads between the float stores without reloads; our loads stay before the stores. 7 variants (locals, struct copy, __restrict, LTCG). */
typedef struct Entry { char p[0x18]; float applied; char q[8]; float pending; char r[0x140 - 0x28]; } Entry;  /* 0x140 */
typedef struct RelEntries { int offset; } RelEntries;   /* self-relative Entry[] */
typedef struct Profile { char p[0x104]; RelEntries entries; } Profile;
typedef struct Player { char p[0x44]; Profile *profile; } Player;
typedef struct Tuning { char p[0xf20]; float curve[24]; } Tuning;
typedef struct Game { char p[0x14]; int current; char q[0x30]; Player *player; char r[0x28]; Tuning *tuning; } Game;
typedef struct Commit {
    Game *game; char p[0x154];
    float *dst_a; float *dst_b; const float *src_a; const float *src_b;
    float curve[24];
} Commit;

/* 0x8865F8F0: commit staged values: the two indirect floats, the 24-point curve into the tuning block, and the current entry's pending value. */
void ts4_commit_staged_8865F8F0(Commit *c)
{
    Game *g = c->game;
    const float *sa = c->src_a;
    float *da = c->dst_a;
    const float *sb = c->src_b;
    float *db = c->dst_b;
    Tuning *tun = g->tuning;
    RelEntries *tab;
    *da = *sa;
    *db = *sb;
    tab = &g->player->profile->entries;
    tun->curve[0] = c->curve[0];
    tun->curve[1] = c->curve[1];
    tun->curve[2] = c->curve[2];
    tun->curve[3] = c->curve[3];
    tun->curve[4] = c->curve[4];
    tun->curve[5] = c->curve[5];
    tun->curve[6] = c->curve[6];
    tun->curve[7] = c->curve[7];
    tun->curve[8] = c->curve[8];
    tun->curve[9] = c->curve[9];
    tun->curve[10] = c->curve[10];
    tun->curve[11] = c->curve[11];
    tun->curve[12] = c->curve[12];
    tun->curve[13] = c->curve[13];
    tun->curve[14] = c->curve[14];
    tun->curve[15] = c->curve[15];
    tun->curve[16] = c->curve[16];
    tun->curve[17] = c->curve[17];
    tun->curve[18] = c->curve[18];
    tun->curve[19] = c->curve[19];
    tun->curve[20] = c->curve[20];
    tun->curve[21] = c->curve[21];
    tun->curve[22] = c->curve[22];
    tun->curve[23] = c->curve[23];
    ((Entry *)((char *)tab + tab->offset))[g->current].applied = ((Entry *)((char *)tab + tab->offset))[g->current].pending;
}
