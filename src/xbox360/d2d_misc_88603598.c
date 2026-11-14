/* Swing_DLL.xex 0x88603598-0x886E6268, executable version 0.0.0.3. */
#ifndef _MSC_VER
#define __forceinline inline
#endif
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
extern char *fn_88603F38(void *o, u32 off);
extern u32 fn_88603D78(char *dst, const char *s);
extern char lbl_880F9484[];
extern void ts4_msg_pool_service_get_8864DFF0(u32 a, u32 b);
extern void *fn_8899F760(u32 size);
extern char lbl_880F9470[];
extern char lbl_880F945C[];
extern char lbl_880F9448[];
extern char lbl_880F9434[];
extern char lbl_880F9420[];
extern char lbl_880F90DC[];

typedef struct { char padc[12]; u32 fc; u16 f10; } O_88603598;
int ts4_write_record_88603598(O_88603598 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->fc;
    p += 4;
    *(u16 *)p = o->f10;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; char pad14[2]; u32 f14; u16 f18; u16 f1a; u32 f1c; u32 f20; } O_886035F0;
int ts4_write_record_886035F0(O_886035F0 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    *(u16 *)p = o->f10;
    p += 2;
    *(u32 *)p = o->f14;
    p += 4;
    *(u16 *)p = o->f18;
    p += 2;
    *(u16 *)p = o->f1a;
    p += 2;
    *(u32 *)p = o->f1c;
    p += 4;
    *(u32 *)p = o->f20;
    p += 4;
    return (int)(unsigned long)(p - off);
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; } O_88603828;
O_88603828 *ts4_create_object_10_88603828(u32 a, u32 b)
{
    O_88603828 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_88603828 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9484;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u32 f10; u32 f14; u32 f18; u32 f1c; u32 f20; u32 f24; u32 f28; u32 f2c; u32 f30; u32 f34; u32 f38; u32 f3c; u32 f40; u32 f44; } O_886038A0;
O_886038A0 *ts4_create_object_48_886038A0(u32 a, u32 b)
{
    O_886038A0 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_886038A0 *)fn_8899F760(72);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9470;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f18 = 0;
        o->f1c = 0;
        o->f20 = 0;
        o->f24 = 0;
        o->f28 = 0;
        o->f2c = 0;
        o->f30 = 0;
        o->f34 = 0;
        o->f38 = 0;
        o->f3c = 0;
        o->f40 = 0;
        o->f44 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; } O_88603950;
O_88603950 *ts4_create_object_20_88603950(u32 a, u32 b)
{
    O_88603950 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_88603950 *)fn_8899F760(32);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F945C;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f12 = 0;
        o->f14 = 0;
        o->f16 = 0;
        o->f18 = 0;
        o->f1a = 0;
        o->f1c = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; u16 f1e; u32 f20; u32 f24; } O_886039E0;
O_886039E0 *ts4_create_object_28_886039E0(u32 a, u32 b)
{
    O_886039E0 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_886039E0 *)fn_8899F760(40);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9448;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        o->f12 = 0;
        o->f14 = 0;
        o->f16 = 0;
        o->f18 = 0;
        o->f1a = 0;
        o->f1c = 0;
        o->f1e = 0;
        o->f20 = 0;
        o->f24 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u16 f10; } O_88603A80;
O_88603A80 *ts4_create_object_14_88603A80(u32 a, u32 b)
{
    O_88603A80 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_88603A80 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9434;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; char pad14[2]; u32 f14; u16 f18; u16 f1a; u32 f1c; u32 f20; } O_88603AF8;
O_88603AF8 *ts4_create_object_24_88603AF8(u32 a, u32 b)
{
    O_88603AF8 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_88603AF8 *)fn_8899F760(36);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9420;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f18 = 0;
        o->f1a = 0;
        o->f1c = 0;
        o->f20 = 0;
        return o;
    }
    return 0;
}

typedef struct { void *vt; u32 w4; u16 h8; u8 a; u8 b; u16 pad; u16 pad2; u64 q10; } O_88604430;
O_88604430 *ts4_ctor_msg_base_a_88604430(O_88604430 *o, u8 a, u8 b)
{
    o->vt = lbl_880F90DC;
    o->w4 = 0;
    o->h8 = 0;
    o->a = a;
    o->b = b;
    o->q10 = 0;
    return o;
}

typedef struct { char pad10[16]; u64 f10; } O_88604488;
int ts4_write_record_88604488(O_88604488 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u64 *)p = o->f10;
    p += 8;
    return (int)(unsigned long)(p - off);
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; char pad10[4]; u64 f10; } O_88604520;
O_88604520 *ts4_create_object_18_88604520(u32 a, u32 b)
{
    O_88604520 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_88604520 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F90DC;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->f10 = 0;
        return o;
    }
    return 0;
}

typedef struct { char p[4]; u32 a; u32 b; } R_88606068;
u32 ts4_xorshift_lcg_next_88606068(R_88606068 *r)
{
    u32 x = r->a;
    u32 y = r->b * 0x10dcd;
    r->b = y;
    x ^= x >> 15;
    x ^= x << 17;
    r->a = x;
    return y ^ x;
}

void ts4_bounded_copy_string_886061C8(char *dst, const char *src, u32 n)
{
    char *end = dst + n - 1;
    while (dst != end && *src != 0) {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = 0;
}

void ts4_slashes_to_backslashes_886068C8(char *s)
{
    while (*s) {
        if (*s == '/') *s = '\\';
        s++;
    }
}

void ts4_backslashes_to_slashes_886068F8(char *s)
{
    while (*s) {
        if (*s == '\\') *s = '/';
        s++;
    }
}

typedef struct { char p[0x64]; u32 v; } O_88608998;
void ts4_set_aligned_size_88608998(O_88608998 *o, u32 n)
{
    u32 r = n & 3;
    if (n < 4) o->v = 4;
    else if (r != 0) o->v = n - r + 4;
    else o->v = n;
}

typedef struct { char p[0x24]; char name[0x200]; } O_88608CD0;
void ts4_set_name_buffer_200_88608CD0(O_88608CD0 *o, const char *src)
{
    char *dst = o->name;
    char *end = dst + 0x1ff;
    while (dst != end && *src != 0) {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = 0;
}

typedef struct { void *a; int b; } O_8860B6F0;
u8 ts4_has_both_ptrs_8860B6F0(O_8860B6F0 *o)
{
    return o->b != 0 && o->a != 0;
}

typedef struct { u32 pad; u32 key; } I_8860B848;
typedef struct { char p[0x74]; I_8860B848 **b; I_8860B848 **e; } O_8860B848;
int ts4_vector_contains_key_at_4_8860B848(O_8860B848 *o, u32 *key)
{
    I_8860B848 **end = o->e;
    I_8860B848 **it;
    for (it = o->b; it != end; ++it)
        if (*key == (*it)->key) return 1;
    return 0;
}

typedef struct { u32 key; } K_8860C358;
typedef struct { char p[0x28]; K_8860C358 **b; K_8860C358 **e; } O_8860C358;
K_8860C358 *ts4_find_in_ptr_vector_by_first_word_28_8860C358(O_8860C358 *o, u32 key)
{
    K_8860C358 *res = 0;
    K_8860C358 **end = o->e;
    K_8860C358 **it;
    for (it = o->b; end != it; ++it) {
        if (key == (*it)->key) { res = *it; break; }
    }
    return res;
}

typedef struct { u32 key; u32 val; } P_8860E060;
typedef struct { char p[0x1c]; P_8860E060 *b; P_8860E060 *e; } O_8860E060;
u32 ts4_lookup_pair_value_by_key_8860E060(O_8860E060 *o, u32 key)
{
    u32 res = 0;
    P_8860E060 *end = o->e;
    P_8860E060 *it;
    for (it = o->b; end != it; ++it) {
        if (key == it->key) { res = it->val; break; }
    }
    return res;
}

typedef struct { char p[0x64]; u8 a; char q[0x9c-0x65]; u8 b; } O_8860E118;
u8 ts4_flag_clear_or_other_set_8860E118(O_8860E118 *o)
{
    return o->a == 0 || o->b != 0;
}

typedef struct { char p[0x34]; struct { u32 key; u32 val; } s[0x8c]; } O_8860E190;
int ts4_find_slot_by_key_8860E190(O_8860E190 *o, u32 key)
{
    int r = -1;
    int i;
    for (i = 0; i < 0x8c; i++)
        if (o->s[i].key == key) { r = i; break; }
    return r;
}

typedef struct { char p[0x10]; float v[4]; } O_8864E240;
void ts4_scale_vec4_at_10_8864E240(O_8864E240 *o, float s)
{
    o->v[0] = s * o->v[0];
    o->v[1] = s * o->v[1];
    o->v[2] = s * o->v[2];
    o->v[3] = s * o->v[3];
}

typedef struct { u32 key; } K_88655A88;
typedef struct { char p[0x44]; K_88655A88 **b; K_88655A88 **e; } O_88655A88;
K_88655A88 *ts4_find_in_ptr_vector_by_first_word_88655A88(O_88655A88 *o, u32 key)
{
    K_88655A88 **end = o->e;
    K_88655A88 **it;
    for (it = o->b; it != end; ++it)
        if ((*it)->key == key) return *it;
    return 0;
}

float ts4_int_ratio_as_float_88659778(int a, int b)
{
    return (float)a / (float)b;
}

typedef struct { int *p; } O_8865FBA8;
u8 ts4_first_value_is_negative_or_max_8865FBA8(O_8865FBA8 *o)
{
    int v = *o->p;
    return v == 0x7fffffff || v < 0;
}

typedef struct { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; u32 f1c; u32 f20; u32 f24; u32 f28; u32 f2c; u32 f30; u32 f34; u32 f38; } O_886E6268;
O_886E6268 *ts4_init_vtable_fields_obj_886E6268(O_886E6268 *o)
{
    o->f0 = 0;
    o->f4 = 0;
    o->f8 = 0;
    o->fc = 0;
    o->f10 = 0;
    o->f14 = 0;
    o->f18 = 0;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f28 = 0;
    o->f2c = 0;
    o->f30 = 0;
    o->f34 = 0;
    o->f38 = 0;
    return o;
}
