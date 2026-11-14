/* Swing_DLL.xex 0x885FDD20-0x885FEC10, executable version 0.0.0.3. */
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
extern char lbl_880F9884[];
extern void fn_8864DFF0(u32 a, u32 b);
extern void *fn_8899F760(u32 size);
extern char lbl_880F9870[];
extern char lbl_880F985C[];
extern char lbl_880F9848[];
extern char lbl_880F980C[];
extern char lbl_880F97F8[];
extern char lbl_880F97E4[];
extern char lbl_880F97D0[];
extern char lbl_880F97BC[];
extern char lbl_880F97A8[];
extern char lbl_880F9794[];
extern char lbl_880F9780[];
extern char lbl_880F976C[];
extern char lbl_880F9758[];
extern char lbl_880F9744[];
extern char lbl_880F9730[];
extern char lbl_880F971C[];
extern char lbl_880F9708[];
extern char lbl_880F96F4[];
extern char lbl_880F96E0[];
extern char lbl_880F96CC[];
extern char lbl_880F96B8[];
extern char lbl_880F96A4[];
extern char lbl_880F9690[];
extern char lbl_880F967C[];
extern char lbl_880F9668[];
extern char lbl_880F9654[];
extern char lbl_880F9640[];
extern char lbl_880F962C[];
extern char lbl_880F9618[];

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; } O_885FDD20;
O_885FDD20 *ts4_create_object_18_885FDD20(u32 a, u32 b)
{
    O_885FDD20 *o;
    fn_8864DFF0(a, b);
    o = (O_885FDD20 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9884;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u16 f10; u16 f12; u32 f14; u32 f18; u32 f1c; u32 f20; char pad28[4]; u64 f28; u64 f30; } O_885FDDA0;
O_885FDDA0 *ts4_create_object_38_885FDDA0(u32 a, u32 b)
{
    O_885FDDA0 *o;
    fn_8864DFF0(a, b);
    o = (O_885FDDA0 *)fn_8899F760(56);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9870;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
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
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; } O_885FDE38;
O_885FDE38 *ts4_create_object_10_885FDE38(u32 a, u32 b)
{
    O_885FDE38 *o;
    fn_8864DFF0(a, b);
    o = (O_885FDE38 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F985C;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u32 f14; } O_885FDEB0;
O_885FDEB0 *ts4_create_object_18_885FDEB0(u32 a, u32 b)
{
    O_885FDEB0 *o;
    fn_8864DFF0(a, b);
    o = (O_885FDEB0 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9848;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; char pad14[2]; u32 f14; u32 f18; char pad20[4]; u64 f20; } O_885FDF90;
O_885FDF90 *ts4_create_object_28_885FDF90(u32 a, u32 b)
{
    O_885FDF90 *o;
    fn_8864DFF0(a, b);
    o = (O_885FDF90 *)fn_8899F760(40);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F980C;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        o->f18 = 0;
        o->f14 = 0;
        o->f20 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u32 f10; u32 f14; u64 f18; } O_885FE018;
O_885FE018 *ts4_create_object_20_885FE018(u32 a, u32 b)
{
    O_885FE018 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE018 *)fn_8899F760(32);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F97F8;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f14 = 0;
        o->f10 = 0;
        o->f18 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u32 f10; } O_885FE098;
O_885FE098 *ts4_create_object_14_885FE098(u32 a, u32 b)
{
    O_885FE098 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE098 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F97E4;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; } O_885FE118;
O_885FE118 *ts4_create_object_10_885FE118(u32 a, u32 b)
{
    O_885FE118 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE118 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F97D0;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; } O_885FE190;
O_885FE190 *ts4_create_object_10_885FE190(u32 a, u32 b)
{
    O_885FE190 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE190 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F97BC;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; } O_885FE208;
O_885FE208 *ts4_create_object_18_885FE208(u32 a, u32 b)
{
    O_885FE208 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE208 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F97A8;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u32 f14; } O_885FE288;
O_885FE288 *ts4_create_object_18_885FE288(u32 a, u32 b)
{
    O_885FE288 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE288 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9794;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; } O_885FE308;
O_885FE308 *ts4_create_object_18_885FE308(u32 a, u32 b)
{
    O_885FE308 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE308 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9780;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        o->f12 = 0;
        o->f14 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; } O_885FE390;
O_885FE390 *ts4_create_object_14_885FE390(u32 a, u32 b)
{
    O_885FE390 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE390 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F976C;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u32 f10; } O_885FE410;
O_885FE410 *ts4_create_object_14_885FE410(u32 a, u32 b)
{
    O_885FE410 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE410 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9758;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; } O_885FE488;
O_885FE488 *ts4_create_object_18_885FE488(u32 a, u32 b)
{
    O_885FE488 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE488 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9744;
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
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; } O_885FE510;
O_885FE510 *ts4_create_object_10_885FE510(u32 a, u32 b)
{
    O_885FE510 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE510 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9730;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; } O_885FE588;
O_885FE588 *ts4_create_object_18_885FE588(u32 a, u32 b)
{
    O_885FE588 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE588 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F971C;
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
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; } O_885FE610;
O_885FE610 *ts4_create_object_10_885FE610(u32 a, u32 b)
{
    O_885FE610 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE610 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9708;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; u16 f16; } O_885FE688;
O_885FE688 *ts4_create_object_18_885FE688(u32 a, u32 b)
{
    O_885FE688 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE688 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F96F4;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; } O_885FE708;
O_885FE708 *ts4_create_object_c_885FE708(u32 a, u32 b)
{
    O_885FE708 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE708 *)fn_8899F760(12);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F96E0;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u16 f10; } O_885FE778;
O_885FE778 *ts4_create_object_14_885FE778(u32 a, u32 b)
{
    O_885FE778 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE778 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F96CC;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; } O_885FE7F0;
O_885FE7F0 *ts4_create_object_10_885FE7F0(u32 a, u32 b)
{
    O_885FE7F0 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE7F0 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F96B8;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u16 f10; } O_885FE868;
O_885FE868 *ts4_create_object_14_885FE868(u32 a, u32 b)
{
    O_885FE868 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE868 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F96A4;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; char pad20[2]; u32 f20; } O_885FE8E0;
O_885FE8E0 *ts4_create_object_24_885FE8E0(u32 a, u32 b)
{
    O_885FE8E0 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE8E0 *)fn_8899F760(36);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9690;
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
        o->f20 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; char pad20[2]; u32 f20; u16 f24; } O_885FE978;
O_885FE978 *ts4_create_object_28_885FE978(u32 a, u32 b)
{
    O_885FE978 *o;
    fn_8864DFF0(a, b);
    o = (O_885FE978 *)fn_8899F760(40);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F967C;
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
        o->f20 = 0;
        o->f24 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u32 f14; u32 f18; u32 f1c; u32 f20; u16 f24; char pad28[2]; u32 f28; } O_885FEA18;
O_885FEA18 *ts4_create_object_2c_885FEA18(u32 a, u32 b)
{
    O_885FEA18 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEA18 *)fn_8899F760(44);
    if (o != 0) {
        o->f4 = 0;
        o->fa = a;
        o->fb = b;
        o->f0 = (u32)(unsigned long)lbl_880F9668;
        o->f8 = 0;
        o->f10 = 0;
        o->fc = 0;
        o->f18 = 0;
        o->f14 = 0;
        o->f1c = 0;
        o->f20 = 0;
        o->f24 = 0;
        o->f28 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u16 f10; } O_885FEAA8;
O_885FEAA8 *ts4_create_object_14_885FEAA8(u32 a, u32 b)
{
    O_885FEAA8 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEAA8 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9654;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u32 f10; } O_885FEB20;
O_885FEB20 *ts4_create_object_14_885FEB20(u32 a, u32 b)
{
    O_885FEB20 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEB20 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9640;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; } O_885FEB98;
O_885FEB98 *ts4_create_object_10_885FEB98(u32 a, u32 b)
{
    O_885FEB98 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEB98 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F962C;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u32 f10; } O_885FEC10;
O_885FEC10 *ts4_create_object_14_885FEC10(u32 a, u32 b)
{
    O_885FEC10 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEC10 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9618;
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
