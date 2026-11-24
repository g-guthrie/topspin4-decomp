/* Swing_DLL.xex 0x883636A0-0x88363764, 0x88366EA8-0x88366F6C, 0x88369D80-0x88369E44, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Ts4VwWin { char pad0[0x4f4]; u32 cur; char pad1[0x87c - 0x4f8]; u8 b87c; u8 b87d; char pad2[0x890 - 0x87e]; u32 w890; char pad3[0x8a0 - 0x894]; u32 w8a0; } Ts4VwWin;
void fn_883A3950(Ts4VwWin *w, int a);
void fn_883A3218(Ts4VwWin *w);
void ts4_if_call_seq_u32_off880_883632B8(Ts4VwWin *w, int a);
void ts4_if_call_seq_u32_off880_88366B60(Ts4VwWin *w, int a);
void ts4_if_call_seq_u32_off880_88369A38(Ts4VwWin *w, int a);
int ts4_set_target_883636A0(Ts4VwWin *w, int unused, u32 v, u32 kind)
{
    u8 moved;
    u8 a;
    u8 b;
    (void)unused;
    if (kind == 0x100) {
        fn_883A3950(w, 0);
        w->w890 = v;
        w->w8a0 = v;
        return 0;
    }
    if (kind == 2) {
        moved = 0;
        if (v == w->cur)
            return 0;
        if (v < w->cur) {
            fn_883A3950(w, 0);
            moved = 1;
        }
        while (w->cur < v)
            ts4_if_call_seq_u32_off880_883632B8(w, 1);
        if (moved) {
            a = w->b87c;
            b = w->b87d;
            fn_883A3218(w);
            w->b87c = a;
            w->b87d = b;
        }
        return 0;
    }
    return 0x19;
}

int ts4_set_target_88366EA8(Ts4VwWin *w, int unused, u32 v, u32 kind)
{
    u8 moved;
    u8 a;
    u8 b;
    (void)unused;
    if (kind == 0x100) {
        fn_883A3950(w, 0);
        w->w890 = v;
        w->w8a0 = v;
        return 0;
    }
    if (kind == 2) {
        moved = 0;
        if (v == w->cur)
            return 0;
        if (v < w->cur) {
            fn_883A3950(w, 0);
            moved = 1;
        }
        while (w->cur < v)
            ts4_if_call_seq_u32_off880_88366B60(w, 1);
        if (moved) {
            a = w->b87c;
            b = w->b87d;
            fn_883A3218(w);
            w->b87c = a;
            w->b87d = b;
        }
        return 0;
    }
    return 0x19;
}

int ts4_set_target_88369D80(Ts4VwWin *w, int unused, u32 v, u32 kind)
{
    u8 moved;
    u8 a;
    u8 b;
    (void)unused;
    if (kind == 0x100) {
        fn_883A3950(w, 0);
        w->w890 = v;
        w->w8a0 = v;
        return 0;
    }
    if (kind == 2) {
        moved = 0;
        if (v == w->cur)
            return 0;
        if (v < w->cur) {
            fn_883A3950(w, 0);
            moved = 1;
        }
        while (w->cur < v)
            ts4_if_call_seq_u32_off880_88369A38(w, 1);
        if (moved) {
            a = w->b87c;
            b = w->b87d;
            fn_883A3218(w);
            w->b87c = a;
            w->b87d = b;
        }
        return 0;
    }
    return 0x19;
}

