/* Swing_DLL.xex 0x8843F310-0x885527C8, executable version 0.0.0.3. */
typedef unsigned long u32;
struct Ts4VwVisitor {
    virtual void s0();
    virtual void begin(const char *label, int flag, void *obj);
    virtual void array(const char *label, int flag, u32 a, u32 b, u32 c);
    virtual void value(const char *label, int flag, u32 v);
    virtual void s4(); virtual void s5();
    virtual void end();
    void *ctx;
};
struct Ts4VwDescA { char pad[0x10]; u32 f10; char pad1[0x34 - 0x14]; u32 f34; };
struct Ts4VwDesc1 { char pad[0x34]; u32 base; u32 count; int cap; };
struct Ts4VwDescB { char pad[0x10]; u32 base; u32 count; int cap; };
struct Ts4VwDescC { char pad[0x50]; char *ptr1; u32 n1; char *ptr2; u32 n2; char pad2[0x70 - 0x60]; };
struct Ts4VwDescD { char pad[0x40]; u32 base1; u32 n1; int cap1; char pad2[4]; u32 base2; u32 n2; int cap2; };
extern "C" {
extern const char lbl_88081B8C[];
extern const char lbl_88081B7C[];
extern const char lbl_88081AE8[];
extern const char lbl_88081AE0[];
extern const char lbl_88081BA0[];
extern const char lbl_88081C00[];
extern const char lbl_88081D24[];
extern const char lbl_880D3B6C[];
extern const char lbl_88081D1C[];
extern const char lbl_88081D58[];
extern const char lbl_88081D50[];
void ts4_describe_88444918(Ts4VwDescA *d, Ts4VwVisitor *v)
{
    v->begin(lbl_88081D24, 1, d);
    v->value(lbl_880D3B6C, 1, d->f34);
    v->value(lbl_88081D1C, 1, d->f10);
    v->end();
}
void ts4_describe_88444FA8(Ts4VwDescB *d, Ts4VwVisitor *v)
{
    int cap;
    v->begin(lbl_88081D58, 1, d);
    cap = d->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88081D50, 1, d->base, d->count << 5, cap << 5);
    v->end();
}
void ts4_describe_8843F310(Ts4VwDescD *d, Ts4VwVisitor *v)
{
    int c;
    v->begin(lbl_88081AE8, 1, d);
    c = d->cap1;
    if ((c & (int)0x80000000) == 0)
        v->array(lbl_88081AE0, 1, d->base1, d->n1 * 3 << 4, (c & 0x3fffffff) * 3 << 4);
    c = d->cap2;
    if ((c & (int)0x80000000) == 0)
        v->array(lbl_88081AE0, 1, d->base2, d->n2 << 4, c << 4);
    v->end();
}
}

struct Ts4VwDescE { char pad[0xc0]; u32 base; u32 n; int cap; };
struct Ts4VwDescF { char pad[0x150]; u32 base; u32 n; int cap; };
struct Ts4VwDescG { char pad[0x8c]; u32 base; u32 n; int cap; };
struct Ts4VwDescH { char pad[0x20]; u32 base; u32 n; int cap; };
extern "C" {
void fn_884774D0(void *obj, Ts4VwVisitor *v);
extern const char lbl_88086F98[];
extern const char lbl_88086F88[];
extern const char lbl_880871BC[];
extern const char lbl_880871B0[];
extern const char lbl_8808A828[];
extern const char lbl_88044F84[];
extern const char lbl_8808E958[];
void ts4_describe_88477EF8(Ts4VwDescE *d, Ts4VwVisitor *v)
{
    int cap;
    v->begin(lbl_88086F98, 2, d);
    fn_884774D0(d, v);
    cap = d->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88086F88, 8, d->base, d->n << 2, cap << 2);
    v->end();
}
void ts4_describe_88482F10(Ts4VwDescF *d, Ts4VwVisitor *v)
{
    int cap;
    v->begin(lbl_880871BC, 2, d);
    fn_884774D0(d, v);
    cap = d->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_880871B0, 8, d->base, d->n << 2, cap << 2);
    v->end();
}
void ts4_describe_884C0738(Ts4VwDescG *d, Ts4VwVisitor *v)
{
    int cap;
    v->begin(0, 1, d);
    cap = d->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_8808A828, 1, d->base, d->n * 5 << 3, (cap & 0x3fffffff) * 5 << 3);
    v->end();
}
void ts4_describe_885526C0(Ts4VwDescH *d, Ts4VwVisitor *v)
{
    int cap;
    v->begin(lbl_88044F84, 1, d);
    cap = d->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_8808E958, 1, d->base, d->n, cap & 0x3fffffff);
    v->end();
}
}

struct Ts4VwElem16 { u32 a, b, c, d; };
struct Ts4VwDescI { char pad[0x18]; Ts4VwElem16 *base; int n; int cap; };
extern "C" {
extern const char lbl_88081C80[];
extern const char lbl_88081958[];
extern const char lbl_880818C4[];
}

struct Ts4VwDescJ { char pad[0x44]; u32 *base; int n; int cap; };
struct Ts4VwHdr { short s0; unsigned short h2; };
struct Ts4VwDescK { char pad[0x20]; u32 base; u32 n; int cap; char pad2[0x3c - 0x2c]; Ts4VwHdr *hdr; };
struct Ts4VwEntL { char pad[0x10]; u32 base; u32 n; int cap; };
struct Ts4VwDescL { char pad[0x10]; Ts4VwEntL **items; int n; };
extern "C" {
extern const char lbl_88081964[];
extern const char lbl_880874A0[];
extern const char lbl_88087494[];
extern const char lbl_8808A820[];
void ts4_describe_8848BB78(Ts4VwDescK *d, Ts4VwVisitor *v)
{
    int cap;
    v->begin(0, 8, d);
    v->array(lbl_880874A0, 8, (u32)d->hdr, d->hdr->h2, 0);
    cap = d->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88087494, 8, d->base, d->n, cap & 0x3fffffff);
    v->end();
}
void ts4_describe_884C0178(Ts4VwDescL *d, Ts4VwVisitor *v)
{
    int i;
    v->begin(0, 2, d);
    for (i = 0; i < d->n; i++) {
        Ts4VwEntL *e = d->items[i];
        int cap = e->cap;
        if ((cap & (int)0x80000000) == 0)
            v->array(lbl_8808A820, 2, e->base, e->n << 5, cap << 5);
    }
    v->end();
}
void ts4_describe_88442F88(Ts4VwDesc1 *d, Ts4VwVisitor *v)
{
    int cap;
    v->begin(lbl_88081BA0, 1, d);
    cap = d->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88081C00, 1, d->base, d->count * 0x38, (cap & 0x3fffffff) * 0x38);
    v->end();
}
}

struct Ts4VwDescM { char pad[0x150]; u32 *base; int n; int cap; };
extern "C" {
extern const char lbl_88087060[];
extern const char lbl_88087054[];
extern const char lbl_880EE0E4[];
void ts4_describe_8847A348(Ts4VwDescM *d, Ts4VwVisitor *v)
{
    int cap;
    int i;
    v->begin(lbl_88087060, 2, d);
    fn_884774D0(d, v);
    cap = d->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88087054, 8, (u32)d->base, d->n << 3, cap << 3);
    for (i = 0; i < d->n; i++)
        v->value(lbl_880EE0E4, 8, d->base[i * 2]);
    v->end();
}
}

struct Ts4VwInnerN { char pad0[8]; u32 b3; u32 n3; int c3; u32 b1; u32 n1; int c1; u32 b2; u32 n2; int c2; };
struct Ts4VwDescN { char pad[0x18]; Ts4VwInnerN *in; u32 tail; };
extern "C" {
extern const char lbl_88081A1C[];
extern const char lbl_880EE678[];
extern const char lbl_88081A10[];
void ts4_describe_8843D0E8(Ts4VwDescN *d, Ts4VwVisitor *v)
{
    Ts4VwInnerN *in;
    int cap;
    v->begin(lbl_88081A1C, 1, d);
    in = d->in;
    cap = in->c1;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_880EE678, 1, in->b1, in->n1 << 2, cap << 2);
    in = d->in;
    cap = in->c2;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_880EE678, 1, in->b2, in->n2 << 2, cap << 2);
    in = d->in;
    cap = in->c3;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_880EE678, 1, in->b3, in->n3 << 2, cap << 2);
    v->value(lbl_88081A10, 1, d->tail);
    v->end();
}
}

struct Ts4VwDescO { char pad[0x18]; u32 b1; u32 n1; int c1; u32 b2; u32 n2; int c2; u32 b3; u32 n3; int c3; };
extern "C" {
extern const char lbl_88081DD8[];
extern const char lbl_88081DCC[];
extern const char lbl_88081DC0[];
extern const char lbl_88081DB4[];
void ts4_describe_884468D0(Ts4VwDescO *d, Ts4VwVisitor *v)
{
    int cap;
    v->begin(lbl_88081DD8, 1, d);
    cap = d->c1;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88081DCC, 1, d->b1, d->n1 << 4, cap << 4);
    cap = d->c2;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88081DC0, 1, d->b2, d->n2 << 4, cap << 4);
    cap = d->c3;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88081DB4, 1, d->b3, d->n3, cap & 0x3fffffff);
    v->end();
}
}

struct Ts4VwArr { u32 base; u32 n; int cap; };
struct Ts4VwDescP { char pad[0x30]; };
extern "C" {
extern const char lbl_88081FC4[];
extern const char lbl_88081FB8[];
void fn_8852E0C0(Ts4VwArr *a, void *ctx, Ts4VwVisitor *v);
void ts4_describe_8844CFB0(Ts4VwDescP *d, Ts4VwVisitor *v)
{
    int cap;
    Ts4VwArr *a = (Ts4VwArr *)d;
    v->begin(lbl_88081FC4, 8, d);
    a = (Ts4VwArr *)((char *)a + 0x30);
    cap = a->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88081FB8, 8, a->base, a->n << 2, cap << 2);
    fn_8852E0C0(a, v->ctx, v);
}
}

extern "C" {
extern const char lbl_88081C80[];
extern const char lbl_88081958[];
extern const char lbl_880818C4[];
extern const char lbl_88081964[];
void ts4_describe_88444598(Ts4VwDescI *d, Ts4VwVisitor *v)
{
    int cap;
    int i;
    v->begin(lbl_88081C80, 1, d);
    cap = *(volatile int *)&d->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88081958, 1, (u32)d->base, d->n << 4, cap << 4);
    for (i = 0; i < d->n; i++)
        v->value(lbl_880818C4, 1, d->base[i].a);
    v->end();
}
void ts4_describe_8843BCD0(Ts4VwDescJ *d, Ts4VwVisitor *v)
{
    int cap;
    int i;
    v->begin(lbl_88081964, 1, d);
    cap = *(volatile int *)&d->cap;
    if ((cap & (int)0x80000000) == 0)
        v->array(lbl_88081958, 1, (u32)d->base, d->n << 2, cap << 2);
    for (i = 0; i < d->n; i++)
        v->value(lbl_880818C4, 1, d->base[i]);
    v->end();
}
}
