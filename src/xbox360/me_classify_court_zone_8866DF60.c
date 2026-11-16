/* 0x8866DF60 (hand match; the owner's court and player pointers are re-read at every use, so
 * they are volatile-qualified): classify the player's court position against two zones of the
 * court layout: inside the first zone selects the "zone A" state; outside the second zone
 * selects the "out" state; then raise the out flag or the in flag from the resulting state. */
typedef unsigned char u8;
typedef struct Zone { float max_x; float p0; float max_z; float p1; float min_x; float p2; float min_z; float p3; } Zone;
typedef struct Court { char p[0x700]; Zone a; Zone b; } Court;
typedef struct Pl { char p[0x394]; unsigned int state; char p1[0x8e0 - 0x398]; float x; float y; float z;
    char p2[0xfa2 - 0x8ec]; u8 out_flag; u8 in_flag; } Pl;
typedef struct Obj { char p[0x2c]; Court *volatile court; char p1[0x74 - 0x30]; Pl *volatile pl; } Obj;
static __inline u8 inside(Zone *z, Pl *p) { u8 r; if (p->x < z->max_x && p->z < z->max_z && p->x > z->min_x && p->z > z->min_z) r = 1; else r = 0; return r; }
void ts4_classify_court_zone_8866DF60(Obj *o)
{
    Pl *p = o->pl;
    u8 a = inside(&o->court->a, p);
    u8 b = inside(&o->court->b, p);
    if (a && p->state != 0x71198650)
        p->state = 0x71198650;
    if (!b && p->state != 0x0F6FB110)
        o->pl->state = 0x0F6FB110;
    p = o->pl;
    if (p->state == 0x0F6FB110)
        p->out_flag = 1;
    else
        p->in_flag = 1;
}
