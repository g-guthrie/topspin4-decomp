/* agentA2 2026-11-18: still 3 best: block cam local, rig before anchor; chained g->rig->cam forms 4. */
/* NEAR MISS (3 instructions): the reloaded camera pointer is allocated to r4 instead of r11. */
/* 0x88661D28 / 0x886624C8: points the scene's camera target at the current court anchor and clears its
 * pending shot slot; the second variant also selects the named camera preset. */
typedef struct Anchor Anchor;
typedef struct Court { char p[0x28]; Anchor *anchor; } Court;
typedef struct Venue { char p[0x5c]; Court *court; } Venue;
typedef struct Cam { char p[0x410]; Anchor *follow; char p2[0x42c - 0x414]; int shot; char p3[0x544 - 0x430]; Anchor *target; } Cam;
typedef struct Rig { char p[0x28]; Cam *cam; } Rig;
typedef struct Hud { char p[0x9fc]; unsigned int preset; } Hud;
typedef struct Game { char p[0x48]; Venue *venue; char p2[0x60 - 0x4c]; Rig *rig; char p3[0x74 - 0x64]; Hud *hud; } Game;
typedef struct Ctl { int pad; Game *g; } Ctl;
void ts4_aim_camera_at_anchor_88661D28(Ctl *c)
{
    Game *g = c->g;
    Anchor *a = g->venue->court->anchor;
    Rig *r = g->rig;
    Cam *cam;
    r->cam->target = a;
    cam = r->cam;
    cam->shot = -1;
    cam->follow = a;
}
