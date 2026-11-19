/* NEAR MISS 0x88686B08: 16 off: register numbering only (target never takes r3 as a temp: panel in r11, flag in r4); also add order in the slot address. 6 variants + pad sweep 0..8. */
typedef struct Slot { unsigned int player; int handle; char p[6]; unsigned char dirty; char q; } Slot;   /* 0x10 */
typedef struct SlotTable { int offset; int count; } SlotTable;   /* self-relative Slot[] */
typedef struct Display { char p[0xea4]; SlotTable slots; char q[8]; unsigned char refresh; } Display;
typedef struct Flags { unsigned char visible; } Flags;
typedef struct Avatar { char p[0x1c]; int handle; } Avatar;
typedef struct Player { char p[0x40]; Flags *flags; char q[0x38]; Avatar *avatar; } Player;
typedef struct PanelState { char p[0xe]; unsigned char changed; } PanelState;
typedef struct Panel { char p[0x5c]; PanelState st; char q[0x350 - 0x5c - 0xf]; int a; int pad; int b; } Panel;
typedef struct Source { char p[0x310]; int a; int b; } Source;
typedef struct Scoring { void *vt; Player **players; char p[0x20]; Display *display; char q[4]; Source *src; char r[0x10]; Panel *panel; } Scoring;
typedef struct Owner { void *vt; Scoring *sc; } Owner;

void ts4_scoring_refresh_serve_state_886696F8(Owner *self);
void fn_88686918(Owner *self);
void fn_88675A18(Owner *self);

/* 0x88686B08: copy the panel inputs, refresh serve/HUD state, and when the panel changed rebind the display slots to each player's avatar. */
void ts4_scoring_refresh_panel_88686B08(Owner *self)
{
    Panel *panel;
    PanelState *st;
    panel = self->sc->panel;
    panel->a = self->sc->src->a;
    panel->b = self->sc->src->b;
    ts4_scoring_refresh_serve_state_886696F8(self);
    fn_88686918(self);
    fn_88675A18(self);
    st = &self->sc->panel->st;
    if (st->changed) {
        Display *d;
        SlotTable *tab;
        unsigned int k;
        st->changed = 0;
        d = self->sc->display;
        tab = &d->slots;
        d->refresh = 1;
        for (k = 0; k < 4; k++) {
            Player *p = self->sc->players[k];
            if (p) {
                Slot *found = 0;
                int handle = p->avatar->handle;
                int j;
                for (j = 0; j < tab->count; j++) {
                    Slot *e = (Slot *)((char *)tab + (j * 16 + tab->offset));
                    if (e->player == k) {
                        found = e;
                        e->handle = handle;
                        break;
                    }
                }
                if (p->flags->visible)
                    found->dirty = 0;
            }
        }
    }
}
