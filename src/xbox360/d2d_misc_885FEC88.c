/* Swing_DLL.xex 0x885FEC88-0x886034F0, executable version 0.0.0.3. */
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
extern char lbl_880F9604[];
extern void fn_8864DFF0(u32 a, u32 b);
extern void *fn_8899F760(u32 size);
extern char lbl_880F95F0[];
extern char lbl_880F95DC[];
extern char lbl_880F95C8[];
extern char lbl_880F95B4[];
extern char lbl_880F95A0[];
extern char lbl_880F958C[];
extern char lbl_880F9578[];
extern char *fn_88603F38(void *o, u32 off);
extern u32 fn_88603D78(char *dst, const char *s);
extern char lbl_880F9560[];
extern char lbl_880F954C[];
extern char lbl_880F9538[];
extern char lbl_880F9524[];
extern char lbl_880F9510[];
extern char lbl_880F94FC[];
extern char lbl_880F94E8[];
extern char lbl_880F94D4[];
extern char lbl_880F94C0[];
extern char lbl_880F94AC[];
extern char lbl_880F9498[];

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; char pad20[2]; u32 f20; u32 f24; u32 f28; u32 f2c; u16 f30; char pad34[2]; u32 f34; u32 f38; u32 f3c; u16 f40; } O_885FEC88;
O_885FEC88 *ts4_create_object_44_885FEC88(u32 a, u32 b)
{
    O_885FEC88 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEC88 *)fn_8899F760(68);
    if (o != 0) {
        o->f4 = 0;
        o->fa = a;
        o->fb = b;
        o->f0 = (u32)(unsigned long)lbl_880F9604;
        o->f8 = 0;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        o->f12 = 0;
        o->f14 = 0;
        o->f16 = 0;
        o->f18 = 0;
        o->f1a = 0;
        o->f1c = 0;
        o->f24 = 0;
        o->f20 = 0;
        o->f2c = 0;
        o->f28 = 0;
        o->f30 = 0;
        o->f34 = 0;
        o->f38 = 0;
        o->f3c = 0;
        o->f40 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u32 f10; u16 f14; } O_885FED40;
O_885FED40 *ts4_create_object_18_885FED40(u32 a, u32 b)
{
    O_885FED40 *o;
    fn_8864DFF0(a, b);
    o = (O_885FED40 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F95F0;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; char pad18[2]; u32 f18; char pad20[4]; u64 f20; } O_885FEDC0;
O_885FEDC0 *ts4_create_object_28_885FEDC0(u32 a, u32 b)
{
    O_885FEDC0 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEDC0 *)fn_8899F760(40);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F95DC;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        o->f12 = 0;
        o->f14 = 0;
        o->f18 = 0;
        o->f20 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; } O_885FEE50;
O_885FEE50 *ts4_create_object_10_885FEE50(u32 a, u32 b)
{
    O_885FEE50 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEE50 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F95C8;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; } O_885FEEC8;
O_885FEEC8 *ts4_create_object_10_885FEEC8(u32 a, u32 b)
{
    O_885FEEC8 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEEC8 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F95B4;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; } O_885FEF40;
O_885FEF40 *ts4_create_object_10_885FEF40(u32 a, u32 b)
{
    O_885FEF40 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEF40 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F95A0;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u32 f14; u32 f18; } O_885FEFB8;
O_885FEFB8 *ts4_create_object_1c_885FEFB8(u32 a, u32 b)
{
    O_885FEFB8 *o;
    fn_8864DFF0(a, b);
    o = (O_885FEFB8 *)fn_8899F760(28);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F958C;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f18 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u32 f10; } O_88600C58;
O_88600C58 *ts4_create_object_14_88600C58(u32 a, u32 b)
{
    O_88600C58 *o;
    fn_8864DFF0(a, b);
    o = (O_88600C58 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9578;
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

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; } O_88601BE8;
int ts4_write_record_88601BE8(O_88601BE8 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    *(u16 *)p = o->f10;
    p += 2;
    *(u16 *)p = o->f12;
    p += 2;
    *(u16 *)p = o->f14;
    p += 2;
    *(u16 *)p = o->f16;
    p += 2;
    *(u16 *)p = o->f18;
    p += 2;
    *(u16 *)p = o->f1a;
    p += 2;
    *(u16 *)p = o->f1c;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u32 fc; u32 f10; u32 f14; u16 f18; } O_88601CC8;
int ts4_write_record_88601CC8(O_88601CC8 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->fc;
    p += 4;
    *(u32 *)p = o->f10;
    p += 4;
    *(u32 *)p = o->f14;
    p += 4;
    *(u16 *)p = o->f18;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; char pad10[2]; u32 f10; u32 f14; } O_88601D30;
int ts4_write_record_88601D30(O_88601D30 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u32 *)p = o->f10;
    p += 4;
    *(u32 *)p = o->f14;
    p += 4;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; char pad14[2]; u32 f14; u32 f18; } O_88601D90;
int ts4_write_record_88601D90(O_88601D90 *o, u32 off)
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
    *(u32 *)p = o->f18;
    p += 4;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u32 f18; u32 f1c; } O_88601E50;
int ts4_write_record_88601E50(O_88601E50 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    *(u16 *)p = o->f10;
    p += 2;
    *(u16 *)p = o->f12;
    p += 2;
    *(u16 *)p = o->f14;
    p += 2;
    *(u16 *)p = o->f16;
    p += 2;
    *(u32 *)p = o->f18;
    p += 4;
    *(u32 *)p = o->f1c;
    p += 4;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u32 fc; u32 f10; u16 f14; } O_88601ED8;
int ts4_write_record_88601ED8(O_88601ED8 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->fc;
    p += 4;
    *(u32 *)p = o->f10;
    p += 4;
    *(u16 *)p = o->f14;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; u16 f1e; u32 f20; u32 f24; u32 f28; u32 f2c; u32 f30; } O_88601F38;
int ts4_write_record_88601F38(O_88601F38 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    *(u16 *)p = o->f10;
    p += 2;
    *(u16 *)p = o->f12;
    p += 2;
    *(u16 *)p = o->f14;
    p += 2;
    *(u16 *)p = o->f16;
    p += 2;
    *(u16 *)p = o->f18;
    p += 2;
    *(u16 *)p = o->f1a;
    p += 2;
    *(u16 *)p = o->f1c;
    p += 2;
    *(u16 *)p = o->f1e;
    p += 2;
    *(u32 *)p = o->f20;
    p += 4;
    *(u32 *)p = o->f24;
    p += 4;
    *(u32 *)p = o->f28;
    p += 4;
    *(u32 *)p = o->f2c;
    p += 4;
    *(u32 *)p = o->f30;
    p += 4;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u32 fc; u16 f10; } O_88601FF8;
int ts4_write_record_88601FF8(O_88601FF8 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->fc;
    p += 4;
    *(u16 *)p = o->f10;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; } O_88602370;
O_88602370 *ts4_create_object_20_88602370(u32 a, u32 b)
{
    O_88602370 *o;
    fn_8864DFF0(a, b);
    o = (O_88602370 *)fn_8899F760(32);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9560;
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
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; } O_88602408;
O_88602408 *ts4_create_object_10_88602408(u32 a, u32 b)
{
    O_88602408 *o;
    fn_8864DFF0(a, b);
    o = (O_88602408 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F954C;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u32 f14; u16 f18; } O_88602480;
O_88602480 *ts4_create_object_1c_88602480(u32 a, u32 b)
{
    O_88602480 *o;
    fn_8864DFF0(a, b);
    o = (O_88602480 *)fn_8899F760(28);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9538;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f18 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u32 f10; u32 f14; } O_88602500;
O_88602500 *ts4_create_object_18_88602500(u32 a, u32 b)
{
    O_88602500 *o;
    fn_8864DFF0(a, b);
    o = (O_88602500 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9524;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; char pad14[2]; u32 f14; u32 f18; } O_88602580;
O_88602580 *ts4_create_object_1c_88602580(u32 a, u32 b)
{
    O_88602580 *o;
    fn_8864DFF0(a, b);
    o = (O_88602580 *)fn_8899F760(28);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9510;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f18 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; } O_88602608;
O_88602608 *ts4_create_object_10_88602608(u32 a, u32 b)
{
    O_88602608 *o;
    fn_8864DFF0(a, b);
    o = (O_88602608 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F94FC;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u32 f18; u32 f1c; } O_88602680;
O_88602680 *ts4_create_object_20_88602680(u32 a, u32 b)
{
    O_88602680 *o;
    fn_8864DFF0(a, b);
    o = (O_88602680 *)fn_8899F760(32);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F94E8;
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
        o->f1c = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; u16 f14; } O_88602710;
O_88602710 *ts4_create_object_18_88602710(u32 a, u32 b)
{
    O_88602710 *o;
    fn_8864DFF0(a, b);
    o = (O_88602710 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F94D4;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; u16 f1e; u32 f20; u32 f24; u32 f28; u32 f2c; u32 f30; } O_88602790;
O_88602790 *ts4_create_object_34_88602790(u32 a, u32 b)
{
    O_88602790 *o;
    fn_8864DFF0(a, b);
    o = (O_88602790 *)fn_8899F760(52);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F94C0;
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
        o->f28 = 0;
        o->f2c = 0;
        o->f30 = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u16 f10; } O_88602840;
O_88602840 *ts4_create_object_14_88602840(u32 a, u32 b)
{
    O_88602840 *o;
    fn_8864DFF0(a, b);
    o = (O_88602840 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F94AC;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; } O_886028B8;
O_886028B8 *ts4_create_object_c_886028B8(u32 a, u32 b)
{
    O_886028B8 *o;
    fn_8864DFF0(a, b);
    o = (O_886028B8 *)fn_8899F760(12);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9498;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        return o;
    }
    return 0;
}

typedef struct { char padc[12]; u16 fc; u16 fe; u32 f10; u32 f14; u32 f18; u32 f1c; u32 f20; u32 f24; u32 f28; u32 f2c; u32 f30; u32 f34; u32 f38; u32 f3c; u32 f40; u32 f44; } O_886033A0;
int ts4_write_record_886033A0(O_886033A0 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    *(u32 *)p = o->f10;
    p += 4;
    *(u32 *)p = o->f14;
    p += 4;
    *(u32 *)p = o->f18;
    p += 4;
    *(u32 *)p = o->f1c;
    p += 4;
    *(u32 *)p = o->f20;
    p += 4;
    *(u32 *)p = o->f24;
    p += 4;
    *(u32 *)p = o->f28;
    p += 4;
    *(u32 *)p = o->f2c;
    p += 4;
    *(u32 *)p = o->f30;
    p += 4;
    *(u32 *)p = o->f34;
    p += 4;
    *(u32 *)p = o->f38;
    p += 4;
    *(u32 *)p = o->f3c;
    p += 4;
    *(u32 *)p = o->f40;
    p += 4;
    *(u32 *)p = o->f44;
    p += 4;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u32 fc; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; } O_88603468;
int ts4_write_record_88603468(O_88603468 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->fc;
    p += 4;
    *(u16 *)p = o->f10;
    p += 2;
    *(u16 *)p = o->f12;
    p += 2;
    *(u16 *)p = o->f14;
    p += 2;
    *(u16 *)p = o->f16;
    p += 2;
    *(u16 *)p = o->f18;
    p += 2;
    *(u16 *)p = o->f1a;
    p += 2;
    *(u16 *)p = o->f1c;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; u16 f1e; u32 f20; u32 f24; } O_886034F0;
int ts4_write_record_886034F0(O_886034F0 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    *(u16 *)p = o->f10;
    p += 2;
    *(u16 *)p = o->f12;
    p += 2;
    *(u16 *)p = o->f14;
    p += 2;
    *(u16 *)p = o->f16;
    p += 2;
    *(u16 *)p = o->f18;
    p += 2;
    *(u16 *)p = o->f1a;
    p += 2;
    *(u16 *)p = o->f1c;
    p += 2;
    *(u16 *)p = o->f1e;
    p += 2;
    *(u32 *)p = o->f20;
    p += 4;
    *(u32 *)p = o->f24;
    p += 4;
    return (int)(unsigned long)(p - off);
}
