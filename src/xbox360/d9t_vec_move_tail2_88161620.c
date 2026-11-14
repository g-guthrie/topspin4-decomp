/* Swing_DLL.xex 0x88161620-0x8821FC14, executable version 0.0.0.3. */
typedef struct Ts4Elem32 { unsigned long long q[4]; } Ts4Elem32;
typedef struct Ts4Vec32 { Ts4Elem32 *begin; Ts4Elem32 *end; } Ts4Vec32;
void ts4_vec32_move_tail_8821FBC8(Ts4Vec32 *v)
{
    Ts4Elem32 *d = v->begin;
    Ts4Elem32 *last = v->end;
    Ts4Elem32 *s = last;
    int n = v->end - last;
    for (; 0 < n; --n, ++s, ++d) {
        *d = *s;
    }
    v->end = d;
}
typedef struct Ts4Elem16 { unsigned a, b; unsigned char c; unsigned d; } Ts4Elem16;
typedef struct Ts4Vec16 { Ts4Elem16 *begin; Ts4Elem16 *end; } Ts4Vec16;
void ts4_vec16_move_tail_881ADB98(Ts4Vec16 *v)
{
    Ts4Elem16 *d = v->begin;
    Ts4Elem16 *last = v->end;
    Ts4Elem16 *s = last;
    int n = v->end - last;
    for (; 0 < n; --n, ++s, ++d) {
        d->a = s->a;
        d->b = s->b;
        d->c = s->c;
        d->d = s->d;
    }
    v->end = d;
}
typedef struct Ts4E12 { unsigned a, b, c; } Ts4E12;
typedef struct Ts4V12 { Ts4E12 *begin; Ts4E12 *end; } Ts4V12;
void ts4_vec12_move_tail_88161620(Ts4V12 *v)
{
    Ts4E12 *d = v->begin;
    Ts4E12 *last = v->end;
    Ts4E12 *s = last;
    int n = v->end - last;
    for (; 0 < n; --n, ++s, ++d) {
        *d = *s;
    }
    v->end = d;
}
typedef struct Ts4E204 { unsigned char buf[0x200]; unsigned x; } Ts4E204;
typedef struct Ts4V204 { Ts4E204 *begin; Ts4E204 *end; } Ts4V204;
void ts4_vec204_move_tail_881B9148(Ts4V204 *v)
{
    Ts4E204 *d = v->begin;
    Ts4E204 *last = v->end;
    Ts4E204 *s = last;
    int n = v->end - last;
    for (; 0 < n; --n, ++s, ++d) {
        int i;
        for (i = 0; i < 0x200; i++) { d->buf[i] = s->buf[i]; }
        d->x = s->x;
    }
    v->end = d;
}
