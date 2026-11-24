/* nearmiss: 24 off (LTCG); head register numbering (want s=r10 set=r9 gtw=r8) and the hud load must come before the format load in the else branch. Needs match.h fields at +0x40 (rules config, format at +0x78) and +0x4C (shot records), not added yet. Open. */
#include "include/ts4/ts4.h"
#include "include/ts4/scoring.h"
struct Cfg { char pad[0x78]; unsigned int format; };
struct MV { char pad[0x40]; Cfg *cfg; Ts4GameplayInterface *hud; char p48[4]; void *shots; };
extern "C" void ts4_reset_shot_records_88674D58(void *o);
static Ts4ScorePlayer *ts4_score_players(Ts4ScoreState *s){ return (Ts4ScorePlayer *)((char *)s + s->players_rel); }
static Ts4SetEntry *ts4_score_set_entry(Ts4ScorePlayer *p, int set){ return (Ts4SetEntry *)((char *)p + p->sets.offset) + set; }
static MV *mv(Ts4Scoring *self) { return (MV *)self->match; }
static Ts4ScorePlayer *ts4_score_player(Ts4ScoreState *s, int i){ return (Ts4ScorePlayer *)((char *)s + s->players_rel) + i; }
static bool both_at(Ts4ScoreState *s, int n){ int i; for (i = 0; i < 2; i++) if (ts4_score_set_entry(ts4_score_player(s, i), s->cur_set)->games != n) return false; return true; }
static bool both_at2(Ts4ScorePlayer *p, int set, int n){ return ts4_score_set_entry(&p[0], set)->games == n && ts4_score_set_entry(&p[1], set)->games == n; }
extern "C" void f(Ts4Scoring *self)
{
    Ts4ScoreState *s = ts4_rules_score(self->rules);
    Ts4ScorePlayer *p0 = (Ts4ScorePlayer *)((char *)s + self->rules->players_rel);
    Ts4ScorePlayer *p1 = p0 + 1;
    int set = self->rules->cur_set;
    if (ts4_score_set_entry(p0, set)->games == self->games_to_win && ts4_score_set_entry(p1, set)->games == self->games_to_win) {
        if (!s->tiebreak) {
            s->tiebreak = 1;
            mv(self)->hud->point_target = 7;
        }
    } else {
        s->tiebreak = 0;
        int t = 1;
        if (mv(self)->cfg->format != 0x4035E2DFu) t = 4;
        mv(self)->hud->point_target = t;
    }
    ts4_reset_shot_records_88674D58(mv(self)->shots);
}
