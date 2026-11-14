/* Loader_DLL.xex 0x833D6C20-0x83499420, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
extern u32 lbl_83544EB4;
extern u32 ts4_get_u32__imp_KeTimeStampBundle_8340CE98(void);
extern int ts4_tailcall_fn_83413818_8340CE50(int, int);
extern int ts4_if_call_seq_NtReleaseMutant_8340D0D8(int);
extern void fn_8348B720(void *, void *, void *);

int ts4l_type_not_cd_833D6C20(char *p)
{
    u32 t = *(u8 *)(p + 0x16);
    return t != 0xc && t != 0xd;
}

/* True when the node is unmarked and its two cursors differ. */
u8 ts4l_cursors_differ_83489850(char *p)
{
    return *(u8 *)(p + 0x10) == 0 && *(int *)(p + 0xc) != *(int *)(p + 8);
}

u8 ts4l_limit_reached_834898D8(char *p)
{
    return *(int *)(p + 0x24) != 0 && *(u32 *)(p + 0x20) >= lbl_83544EB4;
}

short ts4l_clamp_s16_8348ADE0(int x)
{
    return x >= 0x7fff ? 0x7fff : (x <= -0x8000 ? -0x8000 : x);
}

void ts4l_forward_child_8348B8B8(void *a, void *b, char *c)
{
    void *x;
    (void)a;
    if (c == 0)
        return;
    x = *(void **)(c + 0x14);
    if (x == 0)
        return;
    fn_8348B720(x, b, c);
}

u8 ts4l_release_check_83488F30(char *p)
{
    u8 r;
    ts4_tailcall_fn_83413818_8340CE50(*(int *)(p + 8), -1);
    r = *(int *)(p + 4) == 2;
    ts4_if_call_seq_NtReleaseMutant_8340D0D8(*(int *)(p + 8));
    return r;
}

void ts4l_set_deadline_83489068(char *p, u32 d, int c)
{
    u32 t;
    *(int *)(p + 0x2c) = c;
    t = ts4_get_u32__imp_KeTimeStampBundle_8340CE98() + d;
    *(u32 *)(p + 0x28) = t;
    *(u32 *)(p + 0x30) = t;
}

u32 ts4l_child_field_c_8348AA00(char *p)
{
    u32 r = 0;
    if (*(u32 *)(p + 0x3c) > 0)
        r = *(u32 *)(*(char **)(p + 0x98) + 0xc);
    return r;
}

u32 ts4l_child_sum_8348A910(char *p)
{
    u32 r = 0;
    if (*(u32 *)(p + 0x3c) > 0)
        r = *(u32 *)(*(char **)(p + 0x98) + 8) + *(u32 *)(p + 0x30);
    return r;
}

void ts4l_store_clamped_8x8_83499420(u8 *dst, u16 *src, int stride)
{
    int r, i;
    for (r = 8; r != 0; r--) {
        for (i = 0; i < 8; i++) {
            u16 v = src[i];
            short s = (short)v;
            if (s < 0)
                v = 0;
            else if (s > 255)
                v = 255;
            dst[i] = (u8)v;
        }
        dst += stride;
        src += 8;
    }
}

u32 ts4l_child_field_c_8348A6B8(char *p)
{
    u32 r = 0;
    if (*(u32 *)(p + 0x3c) > 0)
        r = *(u32 *)(*(char **)(p + 0x98) + 0xc);
    return r;
}

u32 ts4l_child_sum_8348A690(char *p)
{
    u32 r = 0;
    if (*(u32 *)(p + 0x3c) > 0)
        r = *(u32 *)(*(char **)(p + 0x98) + 8) + *(u32 *)(p + 0x30);
    return r;
}

/* Clamp x to the interval [a, b]; the bounds may be given in either order. */
int ts4l_clamp_either_order_833C2CB0(int x, int a, int b)
{
    if (a < b) {
        if (x < a)
            x = a;
        if (x > b)
            x = b;
    } else {
        if (x > a)
            x = a;
        if (x < b)
            x = b;
    }
    return x;
}

int ts4l_clamp_either_order_832DE8F8(int x, int a, int b)
{
    if (a < b) {
        if (x < a)
            x = a;
        if (x > b)
            x = b;
    } else {
        if (x > a)
            x = a;
        if (x < b)
            x = b;
    }
    return x;
}

int ts4l_all_three_zero_833FC458(u32 *p)
{
    int i;
    for (i = 0; i < 3; i++)
        if (p[i] != 0)
            return 0;
    return 1;
}

/* a modulo b by repeated subtraction. */
int ts4l_mod_by_subtract_83323608(int a, int b)
{
    if (a >= 0 && b == 0)
        return 0;
    do {
        a -= b;
    } while (a >= 0);
    return a + b;
}
