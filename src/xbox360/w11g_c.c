typedef struct X { char p[0x54]; int w54; } X;
typedef struct Y { char p[0x32a]; unsigned char b32a; } Y;
typedef struct A { char p[0x30]; Y *y; char p34[0x44 - 0x34]; X *x; } A;
typedef struct L { char p[0xb8]; int wb8; } L;
typedef struct B { char p[0x24]; L *l; int w28; int w2c; } B;
typedef struct Arg { char p[0x18]; int w18; char p1c[0x48 - 0x1c]; A *a; B *b; } Arg;
typedef struct Self { char p[8]; void *w8; void *wc; void *w10; } Self;
void *ts4_pick_target_88660F70(Self *self, Arg *arg)
{
    A *a = arg->a;
    B *b = arg->b;
    int same = (b->w28 - a->x->w54) == 0;
    int c1 = a->y->b32a != 0 && (unsigned char)same == 0 && b->l->wb8 == arg->w18;
    int c2 = b->w2c == 2 && a->y->b32a != 0 && (unsigned char)same == 0 && b->l->wb8 == arg->w18;
    void *r = 0;
    if ((unsigned char)c1) r = self->wc;
    if (r == 0) { if ((unsigned char)c2) r = self->w10; }
    if (r != 0) return r;
    return self->w8;
}
