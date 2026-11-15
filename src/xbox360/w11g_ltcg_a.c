extern const float g_ts4_event_value;
struct W11B { unsigned char pad[0xb4]; int xb4; };
struct W11A { unsigned char pad[0x44]; struct W11B *p44; };
struct W11M { unsigned char pad[8]; struct W11A *p8; };
struct W11F { unsigned char pad[0x76]; unsigned char b76, b77, b78, b79, b7a, b7b; };
struct W11P { unsigned char pad[0x74]; unsigned char *p74; };
struct W11Q { unsigned char pad[8]; struct W11P *p8; };
struct W11O { unsigned char pad[0x1c]; struct W11M *p1c; };
extern float fn_8861E598(void *p, float a, float b);
void ts4_set_segment_flags_886821A0(struct W11O *o, float a, float b, float c)
{
    float zero = g_ts4_event_value;
    float r = fn_8861E598(&o->p1c->p8->p44->xb4, zero, a + b + c);
    struct W11F *f = (struct W11F *)(((struct W11Q *)o->p1c)->p8->p74 + 0x40c);
    f->b79 = 0; f->b7a = 0; f->b7b = 0; f->b76 = 0; f->b77 = 0; f->b78 = 0;
    if (r > zero && r < a) { f->b7a = 1; f->b77 = 1; }
    if (a < r && r < a + b) { f->b7b = 1; f->b78 = 1; }
    {
        float ab = a + b;
        if (ab < r && r < ab + c) { f->b79 = 1; f->b76 = 1; }
    }
}
