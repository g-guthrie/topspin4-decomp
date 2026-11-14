/* Swing_DLL.xex 0x88150310-0x88280BA0, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Elem_88150310 { u8 bytes[12]; } Elem_88150310;
typedef struct Vec_88150310 { u32 pad; Elem_88150310 *end; } Vec_88150310;
extern void fn_88150600(Elem_88150310 *dst, Elem_88150310 *src);
extern void ts4_loop_call_seq_u32_off0_88150378(Elem_88150310 *first, Elem_88150310 *last);

/* Erases [first, last): shifts the tail down element by element, destroys the leftovers and shrinks the vector. */
Elem_88150310 *ts4_vector_erase_range_88150310(Vec_88150310 *v, Elem_88150310 *first, Elem_88150310 *last)
{
    Elem_88150310 *d = first;
    int n = v->end - last;
    if (n > 0) {
        do {
            fn_88150600(d, (Elem_88150310 *)((char *)d + ((char *)last - (char *)first)));
            ++d;
        } while (--n > 0);
    }
    ts4_loop_call_seq_u32_off0_88150378(d, v->end);
    v->end = d;
    return first;
}

typedef struct Elem_88159558 { u8 bytes[52]; } Elem_88159558;
typedef struct Vec_88159558 { u32 pad; Elem_88159558 *end; } Vec_88159558;
extern void fn_8815D570(Elem_88159558 *dst, Elem_88159558 *src);
extern void fn_8815BB30(Elem_88159558 *first, Elem_88159558 *last);

/* Erases [first, last): shifts the tail down element by element, destroys the leftovers and shrinks the vector. */
Elem_88159558 *ts4_vector_erase_range_88159558(Vec_88159558 *v, Elem_88159558 *first, Elem_88159558 *last)
{
    Elem_88159558 *d = first;
    int n = v->end - last;
    if (n > 0) {
        do {
            fn_8815D570(d, (Elem_88159558 *)((char *)d + ((char *)last - (char *)first)));
            ++d;
        } while (--n > 0);
    }
    fn_8815BB30(d, v->end);
    v->end = d;
    return first;
}

typedef struct Elem_881B4740 { u8 bytes[12]; } Elem_881B4740;
typedef struct Vec_881B4740 { u32 pad; Elem_881B4740 *end; } Vec_881B4740;
extern void fn_881BD170(Elem_881B4740 *dst, Elem_881B4740 *src);
extern void ts4_loop_call_seq_u32_off0_881B68A8(Elem_881B4740 *first, Elem_881B4740 *last);

/* Erases [first, last): shifts the tail down element by element, destroys the leftovers and shrinks the vector. */
Elem_881B4740 *ts4_vector_erase_range_881B4740(Vec_881B4740 *v, Elem_881B4740 *first, Elem_881B4740 *last)
{
    Elem_881B4740 *d = first;
    int n = v->end - last;
    if (n > 0) {
        do {
            fn_881BD170(d, (Elem_881B4740 *)((char *)d + ((char *)last - (char *)first)));
            ++d;
        } while (--n > 0);
    }
    ts4_loop_call_seq_u32_off0_881B68A8(d, v->end);
    v->end = d;
    return first;
}

typedef struct Elem_881B47A8 { u8 bytes[12]; } Elem_881B47A8;
typedef struct Vec_881B47A8 { u32 pad; Elem_881B47A8 *end; } Vec_881B47A8;
extern void fn_881B7FB0(Elem_881B47A8 *dst, Elem_881B47A8 *src);
extern void ts4_loop_call_seq_u32_off4_881B6840(Elem_881B47A8 *first, Elem_881B47A8 *last);

/* Erases [first, last): shifts the tail down element by element, destroys the leftovers and shrinks the vector. */
Elem_881B47A8 *ts4_vector_erase_range_881B47A8(Vec_881B47A8 *v, Elem_881B47A8 *first, Elem_881B47A8 *last)
{
    Elem_881B47A8 *d = first;
    int n = v->end - last;
    if (n > 0) {
        do {
            fn_881B7FB0(d, (Elem_881B47A8 *)((char *)d + ((char *)last - (char *)first)));
            ++d;
        } while (--n > 0);
    }
    ts4_loop_call_seq_u32_off4_881B6840(d, v->end);
    v->end = d;
    return first;
}

typedef struct Elem_881BB8C0 { u8 bytes[36]; } Elem_881BB8C0;
typedef struct Vec_881BB8C0 { u32 pad; Elem_881BB8C0 *end; } Vec_881BB8C0;
extern void fn_881BD0F0(Elem_881BB8C0 *dst, Elem_881BB8C0 *src);
extern void fn_881BC0D0(Elem_881BB8C0 *first, Elem_881BB8C0 *last);

/* Erases [first, last): shifts the tail down element by element, destroys the leftovers and shrinks the vector. */
Elem_881BB8C0 *ts4_vector_erase_range_881BB8C0(Vec_881BB8C0 *v, Elem_881BB8C0 *first, Elem_881BB8C0 *last)
{
    Elem_881BB8C0 *d = first;
    int n = v->end - last;
    if (n > 0) {
        do {
            fn_881BD0F0(d, (Elem_881BB8C0 *)((char *)d + ((char *)last - (char *)first)));
            ++d;
        } while (--n > 0);
    }
    fn_881BC0D0(d, v->end);
    v->end = d;
    return first;
}

typedef struct Elem_88214378 { u8 bytes[44]; } Elem_88214378;
typedef struct Vec_88214378 { u32 pad; Elem_88214378 *end; } Vec_88214378;
extern void ts4_call_seq_u32_off0_882185C0(Elem_88214378 *dst, Elem_88214378 *src);
extern void fn_882196D8(Elem_88214378 *first, Elem_88214378 *last);

/* Erases [first, last): shifts the tail down element by element, destroys the leftovers and shrinks the vector. */
Elem_88214378 *ts4_vector_erase_range_88214378(Vec_88214378 *v, Elem_88214378 *first, Elem_88214378 *last)
{
    Elem_88214378 *d = first;
    int n = v->end - last;
    if (n > 0) {
        do {
            ts4_call_seq_u32_off0_882185C0(d, (Elem_88214378 *)((char *)d + ((char *)last - (char *)first)));
            ++d;
        } while (--n > 0);
    }
    fn_882196D8(d, v->end);
    v->end = d;
    return first;
}

typedef struct Elem_882143E0 { u8 bytes[624]; } Elem_882143E0;
typedef struct Vec_882143E0 { u32 pad; Elem_882143E0 *end; } Vec_882143E0;
extern void fn_882184A8(Elem_882143E0 *dst, Elem_882143E0 *src);
extern void fn_88216460(Elem_882143E0 *first, Elem_882143E0 *last);

/* Erases [first, last): shifts the tail down element by element, destroys the leftovers and shrinks the vector. */
Elem_882143E0 *ts4_vector_erase_range_882143E0(Vec_882143E0 *v, Elem_882143E0 *first, Elem_882143E0 *last)
{
    Elem_882143E0 *d = first;
    int n = v->end - last;
    if (n > 0) {
        do {
            fn_882184A8(d, (Elem_882143E0 *)((char *)d + ((char *)last - (char *)first)));
            ++d;
        } while (--n > 0);
    }
    fn_88216460(d, v->end);
    v->end = d;
    return first;
}

typedef struct Elem_88280BA0 { u8 bytes[36]; } Elem_88280BA0;
typedef struct Vec_88280BA0 { u32 pad; Elem_88280BA0 *end; } Vec_88280BA0;
extern void ts4_call_seq_u32_off0_882865B8(Elem_88280BA0 *dst, Elem_88280BA0 *src);
extern void ts4_loop_call_seq_u32_offc_88282E68(Elem_88280BA0 *first, Elem_88280BA0 *last);

/* Erases [first, last): shifts the tail down element by element, destroys the leftovers and shrinks the vector. */
Elem_88280BA0 *ts4_vector_erase_range_88280BA0(Vec_88280BA0 *v, Elem_88280BA0 *first, Elem_88280BA0 *last)
{
    Elem_88280BA0 *d = first;
    int n = v->end - last;
    if (n > 0) {
        do {
            ts4_call_seq_u32_off0_882865B8(d, (Elem_88280BA0 *)((char *)d + ((char *)last - (char *)first)));
            ++d;
        } while (--n > 0);
    }
    ts4_loop_call_seq_u32_offc_88282E68(d, v->end);
    v->end = d;
    return first;
}
