/* Swing_DLL.xex 0x885FBA68-0x885FDC98, executable version 0.0.0.3. */
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
extern char lbl_880F9924[];
extern void ts4_msg_pool_service_get_8864DFF0(u32 a, u32 b);
extern void *fn_8899F760(u32 size);
extern char lbl_880F9910[];
extern char lbl_880F98FC[];
extern char lbl_880F98E8[];
extern char lbl_880F98D4[];
extern char lbl_880F98C0[];
extern char lbl_880F98AC[];
extern char lbl_880F9898[];

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; char pad14[2]; u32 f14; u32 f18; } O_885FBA68;
int ts4_write_record_885FBA68(O_885FBA68 *o, u32 off)
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

typedef struct { char padc[12]; u16 fc; char pad10[2]; u32 f10; u16 f14; u16 f16; } O_885FBAD8;
int ts4_write_record_885FBAD8(O_885FBAD8 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u32 *)p = o->f10;
    p += 4;
    *(u16 *)p = o->f14;
    p += 2;
    *(u16 *)p = o->f16;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; const char * fc; u16 f10; char pad14[2]; u32 f14; u32 f18; } O_885FBB90;
int ts4_write_record_885FBB90(O_885FBB90 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    p += fn_88603D78(p, o->fc);
    *(u16 *)p = o->f10;
    p += 2;
    *(u32 *)p = o->f14;
    p += 4;
    *(u32 *)p = o->f18;
    p += 4;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u32 f10; u32 f14; u64 f18; u64 f20; } O_885FBC20;
int ts4_write_record_885FBC20(O_885FBC20 *o, u32 off)
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
    *(u64 *)p = o->f18;
    p += 8;
    *(u64 *)p = o->f20;
    p += 8;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; const char * fc; u32 f10; u16 f14; } O_885FBC98;
int ts4_write_record_885FBC98(O_885FBC98 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    p += fn_88603D78(p, o->fc);
    *(u32 *)p = o->f10;
    p += 4;
    *(u16 *)p = o->f14;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; const char * fc; u16 f10; u16 f12; u32 f14; u32 f18; u32 f1c; u32 f20; char pad28[4]; u64 f28; u64 f30; } O_885FBCE0;
int ts4_write_record_885FBCE0(O_885FBCE0 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    p += fn_88603D78(p, o->fc);
    *(u16 *)p = o->f10;
    p += 2;
    *(u16 *)p = o->f12;
    p += 2;
    *(u32 *)p = o->f14;
    p += 4;
    *(u32 *)p = o->f18;
    p += 4;
    *(u32 *)p = o->f1c;
    p += 4;
    *(u32 *)p = o->f20;
    p += 4;
    *(u64 *)p = o->f28;
    p += 8;
    *(u64 *)p = o->f30;
    p += 8;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u32 fc; const char * f10; const char * f14; } O_885FBDA8;
int ts4_write_record_885FBDA8(O_885FBDA8 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->fc;
    p += 4;
    p += fn_88603D78(p, o->f10);
    p += fn_88603D78(p, o->f14);
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; const char * f10; const char * f14; const char * f18; u32 f1c; u32 f20; u16 f24; u16 f26; u16 f28; u16 f2a; u16 f2c; u16 f2e; u16 f30; u16 f32; u16 f34; u16 f36; u16 f38; u16 f3a; u16 f3c; u16 f3e; u32 f40; u32 f44; u32 f48; char pad50[4]; u64 f50; } O_885FBE00;
int ts4_write_record_885FBE00(O_885FBE00 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    p += fn_88603D78(p, o->f10);
    p += fn_88603D78(p, o->f14);
    p += fn_88603D78(p, o->f18);
    *(u32 *)p = o->f1c;
    p += 4;
    *(u32 *)p = o->f20;
    p += 4;
    *(u16 *)p = o->f24;
    p += 2;
    *(u16 *)p = o->f26;
    p += 2;
    *(u16 *)p = o->f28;
    p += 2;
    *(u16 *)p = o->f2a;
    p += 2;
    *(u16 *)p = o->f2c;
    p += 2;
    *(u16 *)p = o->f2e;
    p += 2;
    *(u16 *)p = o->f30;
    p += 2;
    *(u16 *)p = o->f32;
    p += 2;
    *(u16 *)p = o->f34;
    p += 2;
    *(u16 *)p = o->f36;
    p += 2;
    *(u16 *)p = o->f38;
    p += 2;
    *(u16 *)p = o->f3a;
    p += 2;
    *(u16 *)p = o->f3c;
    p += 2;
    *(u16 *)p = o->f3e;
    p += 2;
    *(u32 *)p = o->f40;
    p += 4;
    *(u32 *)p = o->f44;
    p += 4;
    *(u32 *)p = o->f48;
    p += 4;
    *(u64 *)p = o->f50;
    p += 8;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u32 f10; } O_885FC040;
int ts4_write_record_885FC040(O_885FC040 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    *(u32 *)p = o->f10;
    p += 4;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; const char * fc; } O_885FC0A0;
int ts4_write_record_885FC0A0(O_885FC0A0 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    p += fn_88603D78(p, o->fc);
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u32 fc; u32 f10; u16 f14; } O_885FC128;
int ts4_write_record_885FC128(O_885FC128 *o, u32 off)
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

typedef struct { char padc[12]; u32 fc; u32 f10; u32 f14; } O_885FC188;
int ts4_write_record_885FC188(O_885FC188 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->fc;
    p += 4;
    *(u32 *)p = o->f10;
    p += 4;
    *(u32 *)p = o->f14;
    p += 4;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; } O_885FC1E8;
int ts4_write_record_885FC1E8(O_885FC1E8 *o, u32 off)
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
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; } O_885FC258;
int ts4_write_record_885FC258(O_885FC258 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u16 *)p = o->fe;
    p += 2;
    *(u16 *)p = o->f10;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; const char * fc; const char * f10; u16 f14; u16 f16; } O_885FC4A0;
int ts4_write_record_885FC4A0(O_885FC4A0 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    p += fn_88603D78(p, o->fc);
    p += fn_88603D78(p, o->f10);
    *(u16 *)p = o->f14;
    p += 2;
    *(u16 *)p = o->f16;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; char pad20[2]; u32 f20; } O_885FC5D0;
int ts4_write_record_885FC5D0(O_885FC5D0 *o, u32 off)
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
    *(u32 *)p = o->f20;
    p += 4;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; char pad20[2]; u32 f20; u16 f24; } O_885FC668;
int ts4_write_record_885FC668(O_885FC668 *o, u32 off)
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
    *(u32 *)p = o->f20;
    p += 4;
    *(u16 *)p = o->f24;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u32 fc; u16 f10; } O_885FC7B8;
int ts4_write_record_885FC7B8(O_885FC7B8 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u32 *)p = o->fc;
    p += 4;
    *(u16 *)p = o->f10;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; char pad10[2]; u32 f10; u16 f14; } O_885FCA10;
int ts4_write_record_885FCA10(O_885FCA10 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    *(u16 *)p = o->fc;
    p += 2;
    *(u32 *)p = o->f10;
    p += 4;
    *(u16 *)p = o->f14;
    p += 2;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; char pad18[2]; u32 f18; char pad20[4]; u64 f20; } O_885FCA70;
int ts4_write_record_885FCA70(O_885FCA70 *o, u32 off)
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
    *(u32 *)p = o->f18;
    p += 4;
    *(u64 *)p = o->f20;
    p += 8;
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; const char * fc; } O_885FCAF0;
int ts4_write_record_885FCAF0(O_885FCAF0 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    p += fn_88603D78(p, o->fc);
    return (int)(unsigned long)(p - off);
}

typedef struct { char padc[12]; const char * fc; const char * f10; const char * f14; const char * f18; } O_885FCBC8;
int ts4_write_record_885FCBC8(O_885FCBC8 *o, u32 off)
{
    char *p = fn_88603F38(o, off) + off;
    p += fn_88603D78(p, o->fc);
    p += fn_88603D78(p, o->f10);
    p += fn_88603D78(p, o->f14);
    p += fn_88603D78(p, o->f18);
    return (int)(unsigned long)(p - off);
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u32 f10; } O_885FD920;
O_885FD920 *ts4_create_object_14_885FD920(u32 a, u32 b)
{
    O_885FD920 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_885FD920 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9924;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->f10 = 0;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; } O_885FD998;
O_885FD998 *ts4_create_object_18_885FD998(u32 a, u32 b)
{
    O_885FD998 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_885FD998 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9910;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u16 f10; char pad14[2]; u32 f14; u32 f18; } O_885FDA20;
O_885FDA20 *ts4_create_object_1c_885FDA20(u32 a, u32 b)
{
    O_885FDA20 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_885FDA20 *)fn_8899F760(28);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F98FC;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; char pad10[2]; u32 f10; u16 f14; u16 f16; } O_885FDAA8;
O_885FDAA8 *ts4_create_object_18_885FDAA8(u32 a, u32 b)
{
    O_885FDAA8 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_885FDAA8 *)fn_8899F760(24);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F98E8;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; } O_885FDB28;
O_885FDB28 *ts4_create_object_10_885FDB28(u32 a, u32 b)
{
    O_885FDB28 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_885FDB28 *)fn_8899F760(16);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F98D4;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        return o;
    }
    return 0;
}

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u16 f10; char pad14[2]; u32 f14; u32 f18; } O_885FDBA0;
O_885FDBA0 *ts4_create_object_1c_885FDBA0(u32 a, u32 b)
{
    O_885FDBA0 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_885FDBA0 *)fn_8899F760(28);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F98C0;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u32 fc; u16 f10; } O_885FDC20;
O_885FDC20 *ts4_create_object_14_885FDC20(u32 a, u32 b)
{
    O_885FDC20 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_885FDC20 *)fn_8899F760(20);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F98AC;
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

typedef struct { u32 f0; u32 f4; u16 f8; u8 fa; u8 fb; u16 fc; u16 fe; u32 f10; u32 f14; u64 f18; u64 f20; } O_885FDC98;
O_885FDC98 *ts4_create_object_28_885FDC98(u32 a, u32 b)
{
    O_885FDC98 *o;
    ts4_msg_pool_service_get_8864DFF0(a, b);
    o = (O_885FDC98 *)fn_8899F760(40);
    if (o != 0) {
        o->f0 = (u32)(unsigned long)lbl_880F9898;
        o->f4 = 0;
        o->f8 = 0;
        o->fa = a;
        o->fb = b;
        o->fc = 0;
        o->fe = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f18 = 0;
        o->f20 = 0;
        return o;
    }
    return 0;
}
