/* 0x886AFC90 near miss (24 off, /Oc plain; one missing dead `mr r10,r4` before `score->b = score->f310`, everything
 * after shifted). Applies a pending match reset: runs the options defaults (0x886AC9D8) in mode 0x6D2794E5, clears
 * score/flag bytes, sets three limits to INT_MAX, f2d4 = 5, returns 1 (0 when nothing pending). Inline helper,
 * block local, accessor, restrict: no change. */
typedef struct Ts4MatchCfg { char p[0x238]; unsigned mode_hash; } Ts4MatchCfg;
typedef struct Ts4Score { char p[0x50]; int a; char p54[4]; int b; char p5c[4]; int c; char p64[0x91 - 0x64]; unsigned char f91, f92, f93, f94; char p95[0x2d4 - 0x95]; int f2d4; char p2d8[0x310 - 0x2d8]; int f310; } Ts4Score;
typedef struct Ts4Flags { char p[0x69]; unsigned char pending; char p6a[0xd4 - 0x6a]; unsigned char fd4, fd5, fd6; char pd7[5]; unsigned char fdc, fdd; char pde[8]; unsigned char fe6; char pe7[0x234 - 0xe7]; unsigned char f234; } Ts4Flags;
typedef struct Ts4Misc { char p[8]; unsigned char f8; } Ts4Misc;
typedef struct Ts4Match { char p[0x30]; Ts4Score *score; char p34[4]; Ts4MatchCfg *cfg; char p3c[8]; Ts4Flags *flags; Ts4Misc *misc; } Ts4Match;
typedef struct Ts4MatchCtl { char p[4]; Ts4Match *match; } Ts4MatchCtl;
void fn_886AC9D8(void);
int ts4_match_apply_pending(Ts4MatchCtl *self)
{
    int r = 0;
    if (self->match->flags->pending) {
        if (self->match->cfg->mode_hash == 0x6D2794E5u) fn_886AC9D8();
        r = 1;
        self->match->score->f91 = 0;
        self->match->score->f92 = 0;
        self->match->score->f93 = 0;
        self->match->score->f94 = 0;
        self->match->flags->fd4 = 0;
        self->match->flags->fd5 = 0;
        self->match->flags->fd6 = 0;
        self->match->flags->fdc = 0;
        self->match->flags->fdd = 0;
        self->match->score->a = 0x7FFFFFFF;
        self->match->score->b = 0x7FFFFFFF;
        self->match->score->c = 0x7FFFFFFF;
        self->match->score->f310 = 0;
        self->match->score->f2d4 = 5;
        { Ts4Score *__restrict sc = self->match->score; sc->b = sc->f310; }
        self->match->misc->f8 = 0;
        self->match->flags->pending = 0;
        self->match->flags->fe6 = 0;
        self->match->flags->f234 = 0;
    }
    return r;
}
