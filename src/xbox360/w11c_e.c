/* W11C LTCG-route match. Context: flags(/Ob1):src/xbox360/ga1_gameplay_a.c, --include ts4_find_last_id_prev_8865E330 (f1 survives the calls). */
extern const float g_ts4_event_value;
extern int ts4_find_last_id_prev_8865E330(void *self);
struct W11El { float f0; unsigned char p[0x2c]; };
struct W11T24 { unsigned char p[0x5a0]; struct W11El *els; };
struct W11T5c { unsigned char p[0x24]; struct W11T24 *t24; };
struct W11T48 { unsigned char p[0x5c]; struct W11T5c *t5c; };
struct W11T0c { unsigned char p[0x48]; struct W11T48 *t48; };
struct W11Sub { unsigned char p[0x60]; };
struct W11Obj { unsigned char p[0x60]; };
struct W11Self { unsigned char p[4]; struct W11Obj *o; unsigned char p2[4]; struct W11T0c *t0c; };
float ts4_lookup_best_value_8865E388(struct W11Self *s)
{
    float r = g_ts4_event_value;
    struct W11Obj *o = s->o;
    int a = ts4_find_last_id_prev_8865E330(o);
    int b = ts4_find_last_id_prev_8865E330((char *)o + 0x60);
    int idx = (a < b) ? b : a;
    if (idx != -1)
        r = s->t0c->t48->t5c->t24->els[idx].f0;
    return r;
}
