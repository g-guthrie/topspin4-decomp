/* Swing_DLL.xex 0x885CD310-0x885FB6C8, executable version 0.0.0.3. */
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
extern char lbl_880F9AA0[];
extern char lbl_880F9A8C[];
extern char lbl_880F9A3C[];
extern void fn_8864DFF0(u32 a, u32 b);
extern void *fn_8899F760(u32 size);
extern char lbl_880F9A78[];
extern char lbl_880F9A28[];
extern char lbl_880F9A14[];
extern char lbl_880F9A00[];
extern char lbl_880F99EC[];
extern char lbl_880F99D8[];
extern char lbl_880F99C4[];
extern char lbl_880F99B0[];
extern char lbl_880F999C[];
extern char lbl_880F9988[];
extern char lbl_880F9974[];
extern char lbl_880F9960[];
extern char lbl_880F994C[];
extern char lbl_880F9938[];
extern char lbl_880F9898[];
extern char lbl_880F9870[];
extern char lbl_880F9834[];
extern char lbl_880F980C[];
extern char lbl_880F97F8[];
extern char lbl_880F95DC[];

int ts4_is_id_165_to_167_885CD310(unsigned short x)
{
    return x == 0x165 || x == 0x166 || x == 0x167;
}

void ts4_scale_int_array_885D9AA8(int *a, int n, short k)
{
    int i;
    for (i = 0; i < n; i++) a[i] *= k;
}

typedef struct { int **p; int n; } A_885EADA8;
void ts4_fill_table_minus1_885EADA8(A_885EADA8 *a, int **p, int n)
{
    int i;
    a->p = p;
    a->n = n;
    for (i = 0; i < n; i++)
        (*a->p)[i] = -1;
}

unsigned int ts4_next_pow2_885EDDF0(unsigned int x)
{
    x = x - 1;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x + 1;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u64 f10; u32 f18; u32 f1c; u32 f20; } O_885F54A0;
O_885F54A0 *ts4_init_vtable_fields_obj_885F54A0(O_885F54A0 *o, u8 p1, u8 p2)
{
    o->f0 = (u32)(unsigned long)lbl_880F9AA0;
    o->f4 = 0;
    o->f8 = 0;
    o->fa = p1;
    o->fb = p2;
    o->fc = 0;
    o->f10 = 0;
    o->f20 = 0;
    o->f18 = 0;
    o->f1c = 0;
    return o;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u64 f10; u32 f18; u32 f1c; u32 f20; } O_885F5530;
O_885F5530 *ts4_init_vtable_fields_obj_885F5530(O_885F5530 *o, u8 p1, u8 p2)
{
    o->f0 = (u32)(unsigned long)lbl_880F9A8C;
    o->f4 = 0;
    o->f8 = 0;
    o->fa = p1;
    o->fb = p2;
    o->fc = 0;
    o->f10 = 0;
    o->f20 = 0;
    o->f18 = 0;
    o->f1c = 0;
    return o;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; char pad10[4]; u64 f10; u16 f18; char pad1c[2]; u32 f1c; u16 f20; u16 f22; u32 f24; u32 f28; u32 f2c; u32 f30; } O_885F57B0;
O_885F57B0 *ts4_init_vtable_fields_obj_885F57B0(O_885F57B0 *o, u8 p1, u8 p2)
{
    o->f0 = (u32)(unsigned long)lbl_880F9A3C;
    o->f4 = 0;
    o->f8 = 0;
    o->fa = p1;
    o->fb = p2;
    o->f10 = 0;
    o->f18 = 0;
    o->f1c = 0;
    o->f24 = 0;
    o->f20 = 0;
    o->f22 = 0;
    o->f28 = 0;
    o->f2c = 0;
    o->f30 = 0;
    return o;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u64 f10; u32 f18; u32 f1c; u32 f20; } O_885F71C8;
O_885F71C8 *ts4_create_object_28_885F71C8(u32 a, u32 b)
{
    O_885F71C8 *o;
    fn_8864DFF0(a, b);
    o = (O_885F71C8 *)fn_8899F760(0x28);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9AA0;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f20 = 0;
        o->f18 = 0;
        o->f1c = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u64 f10; u32 f18; u32 f1c; u32 f20; } O_885F7250;
O_885F7250 *ts4_create_object_28_885F7250(u32 a, u32 b)
{
    O_885F7250 *o;
    fn_8864DFF0(a, b);
    o = (O_885F7250 *)fn_8899F760(40);
    if (o != 0) {
        o->f4 = 0;
        o->fa = a;
        o->fb = b;
        o->f0 = (u32)(unsigned long)lbl_880F9A8C;
        o->f8 = 0;
        o->fc = 0;
        o->f10 = 0;
        o->f20 = 0;
        o->f18 = 0;
        o->f1c = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u32 f10; } O_885F72D8;
O_885F72D8 *ts4_create_object_14_885F72D8(u32 a, u32 b)
{
    O_885F72D8 *o;
    fn_8864DFF0(a, b);
    o = (O_885F72D8 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9A78;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; char pad10[4]; u64 f10; u16 f18; char pad1c[2]; u32 f1c; u16 f20; u16 f22; u32 f24; u32 f28; u32 f2c; u32 f30; } O_885F7480;
O_885F7480 *ts4_create_object_38_885F7480(u32 a, u32 b)
{
    O_885F7480 *o;
    fn_8864DFF0(a, b);
    o = (O_885F7480 *)fn_8899F760(56);
    if (o != 0) {
        o->f4 = 0;
        o->fa = a;
        o->fb = b;
        o->f0 = (u32)(unsigned long)lbl_880F9A3C;
        o->f8 = 0;
        o->f10 = 0;
        o->f18 = 0;
        o->f1c = 0;
        o->f24 = 0;
        o->f20 = 0;
        o->f22 = 0;
        o->f28 = 0;
        o->f2c = 0;
        o->f30 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; u16 f16; u32 f18; u16 f1c; u16 f1e; } O_885F7518;
O_885F7518 *ts4_create_object_20_885F7518(u32 a, u32 b)
{
    O_885F7518 *o;
    fn_8864DFF0(a, b);
    o = (O_885F7518 *)fn_8899F760(32);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9A28;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f16 = 0;
        o->f18 = 0;
        o->f1c = 0;
        o->f1e = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u32 f14; } O_885F75A8;
O_885F75A8 *ts4_create_object_18_885F75A8(u32 a, u32 b)
{
    O_885F75A8 *o;
    fn_8864DFF0(a, b);
    o = (O_885F75A8 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9A14;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u32 f14; } O_885F7628;
O_885F7628 *ts4_create_object_18_885F7628(u32 a, u32 b)
{
    O_885F7628 *o;
    fn_8864DFF0(a, b);
    o = (O_885F7628 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9A00;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; } O_885F76A8;
O_885F76A8 *ts4_create_object_18_885F76A8(u32 a, u32 b)
{
    O_885F76A8 *o;
    fn_8864DFF0(a, b);
    o = (O_885F76A8 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F99EC;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; } O_885F7728;
O_885F7728 *ts4_create_object_18_885F7728(u32 a, u32 b)
{
    O_885F7728 *o;
    fn_8864DFF0(a, b);
    o = (O_885F7728 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F99D8;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; u16 f16; } O_885F77A8;
O_885F77A8 *ts4_create_object_18_885F77A8(u32 a, u32 b)
{
    O_885F77A8 *o;
    fn_8864DFF0(a, b);
    o = (O_885F77A8 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F99C4;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f16 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; u16 f16; } O_885F7828;
O_885F7828 *ts4_create_object_18_885F7828(u32 a, u32 b)
{
    O_885F7828 *o;
    fn_8864DFF0(a, b);
    o = (O_885F7828 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F99B0;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f16 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; u16 f16; } O_885F78A8;
O_885F78A8 *ts4_create_object_18_885F78A8(u32 a, u32 b)
{
    O_885F78A8 *o;
    fn_8864DFF0(a, b);
    o = (O_885F78A8 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F999C;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f16 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; u16 f16; } O_885F7928;
O_885F7928 *ts4_create_object_18_885F7928(u32 a, u32 b)
{
    O_885F7928 *o;
    fn_8864DFF0(a, b);
    o = (O_885F7928 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9988;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f16 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; u16 f16; } O_885F79A8;
O_885F79A8 *ts4_create_object_18_885F79A8(u32 a, u32 b)
{
    O_885F79A8 *o;
    fn_8864DFF0(a, b);
    o = (O_885F79A8 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9974;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f16 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; char pad16[2]; u16 f16; } O_885F7A28;
O_885F7A28 *ts4_create_object_18_885F7A28(u32 a, u32 b)
{
    O_885F7A28 *o;
    fn_8864DFF0(a, b);
    o = (O_885F7A28 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9960;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f16 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; u16 f16; u32 f18; u32 f1c; u16 f20; u16 f22; u16 f24; u16 f26; u16 f28; u16 f2a; u16 f2c; u16 f2e; u16 f30; } O_885F7AA8;
O_885F7AA8 *ts4_create_object_34_885F7AA8(u32 a, u32 b)
{
    O_885F7AA8 *o;
    fn_8864DFF0(a, b);
    o = (O_885F7AA8 *)fn_8899F760(52);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F994C;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f16 = 0;
        o->f18 = 0;
        o->f1c = 0;
        o->f20 = 0;
        o->f22 = 0;
        o->f24 = 0;
        o->f26 = 0;
        o->f28 = 0;
        o->f2a = 0;
        o->f2c = 0;
        o->f2e = 0;
        o->f30 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; char pad18[4]; u16 f18; u16 f1a; } O_885F7B58;
O_885F7B58 *ts4_create_object_1c_885F7B58(u32 a, u32 b)
{
    O_885F7B58 *o;
    fn_8864DFF0(a, b);
    o = (O_885F7B58 *)fn_8899F760(28);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9938;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f18 = 0;
        o->f1a = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u32 f10; u32 f14; u64 f18; u64 f20; } O_885F9ED0;
O_885F9ED0 *ts4_init_vtable_fields_obj_885F9ED0(O_885F9ED0 *o, u8 p1, u8 p2)
{
    o->f0 = (u32)(unsigned long)lbl_880F9898;
    o->f4 = 0;
    o->f8 = 0;
    o->fa = p1;
    o->fb = p2;
    o->fc = 0;
    o->fe = 0;
    o->f10 = 0;
    o->f14 = 0;
    o->f18 = 0;
    o->f20 = 0;
    return o;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u16 f10; u16 f12; u32 f14; u32 f18; u32 f1c; u32 f20; char pad28[4]; u64 f28; u64 f30; } O_885F9FD0;
O_885F9FD0 *ts4_init_vtable_fields_obj_885F9FD0(O_885F9FD0 *o, u8 p1, u8 p2)
{
    o->f0 = (u32)(unsigned long)lbl_880F9870;
    o->f4 = 0;
    o->f8 = 0;
    o->fa = p1;
    o->fb = p2;
    o->fc = 0;
    o->f10 = 0;
    o->f12 = 0;
    o->f14 = 0;
    o->f18 = 0;
    o->f1c = 0;
    o->f20 = 0;
    o->f28 = 0;
    o->f30 = 0;
    return o;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u32 f10; u32 f14; u32 f18; u32 f1c; u32 f20; u16 f24; u16 f26; u16 f28; u16 f2a; u16 f2c; u16 f2e; u16 f30; u16 f32; u16 f34; u16 f36; u16 f38; u16 f3a; u16 f3c; u16 f3e; u32 f40; u32 f44; u32 f48; char pad50[4]; u64 f50; } O_885FA208;
O_885FA208 *ts4_init_vtable_fields_obj_885FA208(O_885FA208 *o, u8 p1, u8 p2)
{
    o->f0 = (u32)(unsigned long)lbl_880F9834;
    o->f4 = 0;
    o->f8 = 0;
    o->fa = p1;
    o->fb = p2;
    o->fc = 0;
    o->fe = 0;
    o->f10 = 0;
    o->f14 = 0;
    o->f18 = 0;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f26 = 0;
    o->f28 = 0;
    o->f2a = 0;
    o->f2c = 0;
    o->f2e = 0;
    o->f30 = 0;
    o->f32 = 0;
    o->f34 = 0;
    o->f36 = 0;
    o->f38 = 0;
    o->f3a = 0;
    o->f3c = 0;
    o->f3e = 0;
    o->f40 = 0;
    o->f44 = 0;
    o->f48 = 0;
    o->f50 = 0;
    return o;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; char pad14[2]; u32 f14; u32 f18; char pad20[4]; u64 f20; } O_885FA318;
O_885FA318 *ts4_init_vtable_fields_obj_885FA318(O_885FA318 *o, u8 p1, u8 p2)
{
    o->f0 = (u32)(unsigned long)lbl_880F980C;
    o->f4 = 0;
    o->f8 = 0;
    o->fa = p1;
    o->fb = p2;
    o->fc = 0;
    o->fe = 0;
    o->f10 = 0;
    o->f18 = 0;
    o->f14 = 0;
    o->f20 = 0;
    return o;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u32 f10; u32 f14; u64 f18; } O_885FA368;
O_885FA368 *ts4_init_vtable_fields_obj_885FA368(O_885FA368 *o, u8 p1, u8 p2)
{
    o->f0 = (u32)(unsigned long)lbl_880F97F8;
    o->f4 = 0;
    o->f8 = 0;
    o->fa = p1;
    o->fb = p2;
    o->fc = 0;
    o->f14 = 0;
    o->f10 = 0;
    o->f18 = 0;
    return o;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; char pad18[2]; u32 f18; char pad20[4]; u64 f20; } O_885FB6C8;
O_885FB6C8 *ts4_init_vtable_fields_obj_885FB6C8(O_885FB6C8 *o, u8 p1, u8 p2)
{
    o->f0 = (u32)(unsigned long)lbl_880F95DC;
    o->f4 = 0;
    o->f8 = 0;
    o->fa = p1;
    o->fb = p2;
    o->fc = 0;
    o->fe = 0;
    o->f10 = 0;
    o->f12 = 0;
    o->f14 = 0;
    o->f18 = 0;
    o->f20 = 0;
    return o;
}
