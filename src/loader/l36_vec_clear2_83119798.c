/* Loader_DLL.xex 0x83119798-0x831458C0, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Item { u32 a; u32 b; u32 c; };
struct Vec { struct Item *items; void *extra; int count; int cap; };
extern void ts4l_if_call_seq_u32_off0_8310A790(struct Item *it, int arg);
extern void fn_83120540(void *p);

void ts4l_vec_clear_83119798(struct Vec *v)
{
    int i;
    if (v->items != 0) {
        for (i = 0; i < v->count; i++) {
            ts4l_if_call_seq_u32_off0_8310A790(v->items + i, 0);
        }
        fn_83120540(v->items);
        v->items = 0;
    }
    if (v->extra != 0) {
        fn_83120540(v->extra);
        v->extra = 0;
    }
    v->count = 0;
    v->cap = 0;
}

void ts4l_vec_clear_8311D3F8(struct Vec *v)
{
    int i;
    if (v->items != 0) {
        for (i = 0; i < v->count; i++) {
            ts4l_if_call_seq_u32_off0_8310A790(v->items + i, 0);
        }
        fn_83120540(v->items);
        v->items = 0;
    }
    if (v->extra != 0) {
        fn_83120540(v->extra);
        v->extra = 0;
    }
    v->count = 0;
    v->cap = 0;
}

void ts4l_vec_clear_8311EDD0(struct Vec *v)
{
    int i;
    if (v->items != 0) {
        for (i = 0; i < v->count; i++) {
            ts4l_if_call_seq_u32_off0_8310A790(v->items + i, 0);
        }
        fn_83120540(v->items);
        v->items = 0;
    }
    if (v->extra != 0) {
        fn_83120540(v->extra);
        v->extra = 0;
    }
    v->count = 0;
    v->cap = 0;
}

void ts4l_vec_clear_8313FCF0(struct Vec *v)
{
    int i;
    if (v->items != 0) {
        for (i = 0; i < v->count; i++) {
            ts4l_if_call_seq_u32_off0_8310A790(v->items + i, 0);
        }
        fn_83120540(v->items);
        v->items = 0;
    }
    if (v->extra != 0) {
        fn_83120540(v->extra);
        v->extra = 0;
    }
    v->count = 0;
    v->cap = 0;
}

void ts4l_vec_clear_831458C0(struct Vec *v)
{
    int i;
    if (v->items != 0) {
        for (i = 0; i < v->count; i++) {
            ts4l_if_call_seq_u32_off0_8310A790(v->items + i, 0);
        }
        fn_83120540(v->items);
        v->items = 0;
    }
    if (v->extra != 0) {
        fn_83120540(v->extra);
        v->extra = 0;
    }
    v->count = 0;
    v->cap = 0;
}
