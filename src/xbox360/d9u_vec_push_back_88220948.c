/* Swing_DLL.xex 0x88220948-0x88220AA8, executable version 0.0.0.3. */
typedef struct Ts4E20 { unsigned w[5]; } Ts4E20;
typedef struct Ts4V20 { unsigned pad; Ts4E20 *end; unsigned pad2; Ts4E20 *cap; } Ts4V20;
extern void fn_88225DE8(Ts4V20 *v, Ts4E20 *pos, const Ts4E20 *x);
void ts4_vec20_push_back_88220948(Ts4V20 *v, const Ts4E20 *x)
{
    if (v->end != v->cap) {
        if (v->end) { *v->end = *x; }
        ++v->end;
    } else {
        fn_88225DE8(v, v->end, x);
    }
}
typedef struct Ts4E24 { unsigned w[6]; } Ts4E24;
typedef struct Ts4V24 { unsigned pad; Ts4E24 *end; unsigned pad2; Ts4E24 *cap; } Ts4V24;
extern void fn_88152A70(Ts4V24 *v, Ts4E24 *pos, const Ts4E24 *x);
void ts4_vec24_push_back_88220A58(Ts4V24 *v, const Ts4E24 *x)
{
    if (v->end != v->cap) {
        if (v->end) { *v->end = *x; }
        ++v->end;
    } else {
        fn_88152A70(v, v->end, x);
    }
}
