/* nearmiss: 3 off (LTCG /Oc, context pp1_pool_primer.c + d1_big5_find_entry.c --include ts4_find_entry_by_alt_id_8888C3C0).
 * All three are COMMUTE diffs of the self-relative index add: target `add rD, IV, offset` (loop induction value first),
 * ours `add rD, offset, IV`, for teams[i], team.players[j] and players[k]. players[idx] (non-IV) is right only with the
 * `char *p` local in operator[]. Tried: Data()[i], four other operator[] spellings, u32 index/offset, (int)sizeof,
 * per-iteration game local (10 off), C macro forms (41 off). Blocker: no source lever found for rule C1 ordering
 * of a strength-reduced IV against a load; regalloc_mutate search stopped at coordinator request (CPU).
 * 0x8888D120 (pres): caches per-team and per-slot player entries: by_team[j][i] / by_slot[k] = find(players[...].id). */
typedef unsigned int u32;
template <class T> struct WdRel { int offset; u32 count; u32 cap;
    T *Data() { return (T *)((char *)this + offset); }
    T &operator[](int i) { char *p = (char *)this; return *(T *)(p + offset + i * sizeof(T)); } };
struct WdPlayer { char pad[0x10]; u32 id; char pad2[0xc]; };
struct WdTeam { WdRel<int> players; int pad; };
struct WdGame { char pad[0x214]; WdRel<WdPlayer> players; WdRel<WdTeam> teams; u32 w22c; char pad2[8]; u32 w238; char pad3[0x13c0 - 0x23c]; char table[1]; };
struct WdSelf { char pad[0x28]; WdGame *game; char pad2[0x70 - 0x2c]; void *by_team[2][2]; void *by_slot[4]; };
extern "C" void *ts4_find_entry_by_alt_id_8888C3C0(u32 id, void *table);

extern "C" void fn_8888D120(WdSelf *self)
{
    int n, i, j;
    if (self->game->w22c != 0xCD0B222F || self->game->w238 == 0xFB595DB2)
        n = 2;
    else
        n = 1;
    for (i = 0; i < 2; i++)
        for (j = 0; j < n; j++)
            self->by_team[j][i] = ts4_find_entry_by_alt_id_8888C3C0(self->game->players[self->game->teams[i].players[j]].id, self->game->table);
    for (i = 0; i < 4; i++)
        self->by_slot[i] = ts4_find_entry_by_alt_id_8888C3C0(self->game->players[i].id, self->game->table);
}
