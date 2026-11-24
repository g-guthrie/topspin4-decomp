/* Swing_DLL.xex 0x8847AAF8-0x88485B38, executable version 0.0.0.3. */
#ifdef _MSC_VER
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float a, float b, float c) { return a >= 0 ? b : c; }
#endif
extern float lbl_88001A20;
extern float lbl_88001A68;
extern void ts4_counted_ref_release_88475B08(void *p);
typedef struct Ts4PtrList { void **items; int count; } Ts4PtrList;
typedef struct Ts4HolderA { char pad[8]; Ts4PtrList list; } Ts4HolderA;
void ts4_list_remove_swap_8847EB88(Ts4HolderA *o, int i)
{
    Ts4PtrList *l = &o->list;
    ts4_counted_ref_release_88475B08(l->items[i]);
    l->count = l->count - 1;
    l->items[i] = l->items[l->count];
}
void ts4_set_inv_scale_8847AAF8(float *o, const float *m)
{
    float b = m[5];
    float a = m[0];
    float c = m[10];
    float inv = lbl_88001A20;
    float mx = __fself(a - b, a, b);
    mx = __fself(mx - c, mx, c);
    if (mx > lbl_88001A20) {
        inv = lbl_88001A68 / mx;
    }
    o[0x30] = inv;
    o[0x31] = inv;
    o[0x32] = inv;
}
void ts4_set_inv_scale_88485AF0(float *o, const float *m)
{
    float b = m[5];
    float a = m[0];
    float c = m[10];
    float inv = lbl_88001A20;
    float mx = __fself(a - b, a, b);
    mx = __fself(mx - c, mx, c);
    if (mx > lbl_88001A20) {
        inv = lbl_88001A68 / mx;
    }
    o[0x30] = inv;
    o[0x31] = inv;
    o[0x32] = inv;
}
