/* Near miss: the conversions (extsw/std/lfd/fcfid/frsp, fctiwz) match. The final
 * `-a->off - i` comes out as add+neg; the target does an early neg, then subf.
 * Check: python3 tools/fn_check.py <this> ts4_set_scaled_offset_888C1910=0x888C1910 --flags /Oc */
extern float g_ts4_script_constants[];
struct E { char p[0x6c]; int v; };
struct D { char p[0x10]; struct E *e; };
struct C { char p[0x30]; int w, h; };
struct B { char p[0x44]; struct D *d; char q[4]; struct C *c; };
struct A { char p[4]; struct B *b; char q[0x54 - 8]; unsigned char on; char r[3]; int off; };
/* when on: e->v = -off - (int)(h * K / w), K = g_ts4_script_constants[0x314/4] */
void ts4_set_scaled_offset_888C1910(struct A *a)
{
    if (!a->on) return;
    a->b->d->e->v = -a->off - (int)((float)a->b->c->h * g_ts4_script_constants[0x314/4] / (float)a->b->c->w);
}
