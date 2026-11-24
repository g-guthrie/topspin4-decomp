/* nearmiss: 4 off (Swing_DLL.xex 0x888AF5C0, emitter ctor, vtable 0x880DC550); i1 is the best form.
 * Diffs: li r11,0 / lis r7 order and the 1.0f lfs scheduled before stw f4. Tried: base class (C++), local zero,
 * accessor for g_ts4_event_value, constants array (worse). Concrete blocker: g_ts4_event_value has no matched
 * definition TU; its section/alignment in the link likely decides the lis scheduling. Context: pool primer only. */
typedef unsigned int u32;
extern const char lbl_880DC550[];
extern float g_ts4_event_value;

typedef struct F3 { float x, y, z; } F3;
typedef struct Flags4 { unsigned char d0, d1, d2, d3; } Flags4;
typedef struct Words7 { u32 l[7]; } Words7;
typedef struct Emit {
    const void *vt; u32 f4; int *ref; F3 a, b, c; float w; Flags4 d;
    char p38[0x24]; float f5c; Words7 l; unsigned char alt;
} Emit;
static __forceinline void set3(F3 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; }
static __forceinline void flags_init(Flags4 *f) { f->d0 = 0; f->d1 = 0; f->d2 = 0; f->d3 = 0; }
static __forceinline void words_init(Words7 *w) { w->l[0] = 0; w->l[1] = 0; w->l[2] = 0; w->l[3] = 0; w->l[4] = 0; w->l[5] = 0; w->l[6] = 0; }
static __forceinline void base_init(Emit *s) { s->f4 = 0; }
static __forceinline void body_init(Emit *s)
{
    set3(&s->a, 500.0f, 500.0f, 500.0f);
    set3(&s->b, g_ts4_event_value, g_ts4_event_value, g_ts4_event_value);
    set3(&s->c, g_ts4_event_value, 1.0f, g_ts4_event_value);
    s->d.d0 = 0;
    s->w = 0.45f;
    s->d.d1 = 0;
    s->d.d2 = 0;
    s->f5c = g_ts4_event_value;
    s->d.d3 = 0;
    words_init(&s->l);
    s->alt = 0;
}
Emit *i1(Emit *s)
{
    base_init(s);
    s->vt = lbl_880DC550;
    body_init(s);
    return s;
}
Emit *i2(Emit *s)
{
    s->f4 = 0;
    s->vt = lbl_880DC550;
    body_init(s);
    return s;
}
Emit *i3(Emit *s)
{
    base_init(s);
    s->vt = lbl_880DC550;
    set3(&s->a, 500.0f, 500.0f, 500.0f);
    set3(&s->b, g_ts4_event_value, g_ts4_event_value, g_ts4_event_value);
    set3(&s->c, g_ts4_event_value, 1.0f, g_ts4_event_value);
    s->d.d0 = 0;
    s->w = 0.45f;
    s->d.d1 = 0;
    s->d.d2 = 0;
    s->f5c = g_ts4_event_value;
    s->d.d3 = 0;
    words_init(&s->l);
    s->alt = 0;
    return s;
}
