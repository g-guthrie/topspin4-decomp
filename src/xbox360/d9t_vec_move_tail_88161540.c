/* Swing_DLL.xex 0x88161540-0x88220AFC, executable version 0.0.0.3. */
typedef struct Ts4Elem28 { unsigned w[7]; } Ts4Elem28;
typedef struct Ts4Vec28 { Ts4Elem28 *begin; Ts4Elem28 *end; } Ts4Vec28;
void ts4_vec28_move_tail_88161540(Ts4Vec28 *v)
{
    Ts4Elem28 *d = v->begin;
    Ts4Elem28 *last = v->end;
    Ts4Elem28 *s = last;
    int n = v->end - last;
    for (; 0 < n; --n, ++s, ++d) {
        *d = *s;
    }
    v->end = d;
}
typedef struct Ts4Elem20 { unsigned w[5]; } Ts4Elem20;
typedef struct Ts4Vec20 { Ts4Elem20 *begin; Ts4Elem20 *end; } Ts4Vec20;
void ts4_vec20_move_tail_88220998(Ts4Vec20 *v)
{
    Ts4Elem20 *d = v->begin;
    Ts4Elem20 *last = v->end;
    Ts4Elem20 *s = last;
    int n = v->end - last;
    for (; 0 < n; --n, ++s, ++d) {
        *d = *s;
    }
    v->end = d;
}
typedef struct Ts4Elem24 { unsigned w[6]; } Ts4Elem24;
typedef struct Ts4Vec24 { Ts4Elem24 *begin; Ts4Elem24 *end; } Ts4Vec24;
void ts4_vec24_move_tail_88220AA8(Ts4Vec24 *v)
{
    Ts4Elem24 *d = v->begin;
    Ts4Elem24 *last = v->end;
    Ts4Elem24 *s = last;
    int n = v->end - last;
    for (; 0 < n; --n, ++s, ++d) {
        *d = *s;
    }
    v->end = d;
}
