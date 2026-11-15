/* CX43 part d: net/lobby helpers, Swing_DLL.xex 0x889Axxxx-0x889Bxxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX43_INL static __forceinline
extern unsigned int strlen(const char *);
#else
#define CX43_INL static inline
#include <string.h>
#endif
typedef struct Cx43SvcB { u8 pad[0x1b1]; u8 b1b1; u8 pad1[2]; u32 w1b4; u32 w1b8; } Cx43SvcB;
typedef struct Cx43Sess { u8 pad[0x3c]; Cx43SvcB *p3c; } Cx43Sess;
extern Cx43Sess *g_ts4_session_context;

/* 0x889BD188 */
extern void fn_889BCE40(const char *s);
extern void fn_889BD0B8(void *self);
void ts4_apply_name_889BD188(void *self, const char *s, u8 flag)
{
    if (s != 0 && strlen(s) != 0)
        fn_889BCE40(s);
    if (flag != 0)
        fn_889BD0B8(self);
}

/* 0x889B11B0 */
extern void fn_88938660(void *o);
extern char lbl_880D1FB4[];
typedef struct Cx43Rec { void *vt; u8 pad[0x30]; u8 b34; u8 pad1[3]; u8 b38; u8 pad2[3]; u32 w3c, w40; u8 b44; u8 pad3[3]; u32 w48, w4c, w50, w54, w58, w5c, w60, w64; } Cx43Rec;
#if 0 /* near miss, not byte-identical */
Cx43Rec *ts4_ctor_889B11B0(Cx43Rec *o)
{
    fn_88938660(o);
    o->b34 = 0;
    o->b38 = 0;
    o->vt = lbl_880D1FB4;
    o->w3c = 0;
    o->w40 = (u32)-1;
    o->b44 = 0;
    o->w48 = (u32)-1;
    o->w4c = (u32)-1;
    o->w50 = (u32)-1;
    o->w54 = 0;
    o->w58 = 0;
    o->w5c = (u32)-1;
    o->w60 = (u32)-1;
    o->w64 = 0;
    return o;
}
#endif

/* 0x889BCA90 */
extern u32 fn_8857C8C8(void);
extern void fn_88884A58(void *p);
extern u32 lbl_88D3CD40;
extern u32 lbl_88D459B4;
extern u32 lbl_88D45B14;
#if 0 /* near miss, not byte-identical */
void ts4_set_defaults_889BCA90(void)
{
    u32 a[6];
    lbl_88D3CD40 = fn_8857C8C8();
    lbl_88D459B4 = 0x14;
    a[1] = 0x14;
    lbl_88D45B14 = 0xdc;
    a[0] = 0x396684A0;
    a[2] = 0x891542DA;
    a[3] = 0xC8;
    a[4] = 0xBAC5C692;
    a[5] = 8;
    fn_88884A58(a);
}
#endif

/* 0x889ADEC8 */
extern void fn_889ADA40(void *self);
extern u8 fn_889A0740(void *self);
extern void ts4_cx42_d_8899C668(void *self);
#if 0 /* near miss, not byte-identical */
void ts4_check_done_889ADEC8(void *self)
{
    fn_889ADA40(self);
    if (fn_889A0740(self) != 0) {
        Cx43SvcB *t = g_ts4_session_context->p3c;
        t->w1b4 = 0xA0BDE62E;
        t->w1b8 = 0;
        t->b1b1 = 1;
        ts4_cx42_d_8899C668(self);
    }
}
#endif

/* 0x889AC440 */
typedef struct Cx43Lock { void **vt; } Cx43Lock;
typedef struct Cx43State { u8 pad[0x1c]; u8 *p1c; } Cx43State;
extern Cx43State *g_ts4_session_state;
extern u32 fn_88154230(void *st, u32 key);
extern void ts4_loop_get_u32_off8_8861DDB0(void *o, u32 v);
void ts4_locked_set_889AC440(void)
{
    u32 h = fn_88154230(g_ts4_session_state, 0x322598DE);
    Cx43State *st = g_ts4_session_state;
    u8 **pp = &st->p1c;
    Cx43Lock *lk = (Cx43Lock *)(*pp + 8);
    ((void (*)(void *))lk->vt[1])(lk);
    ts4_loop_get_u32_off8_8861DDB0(*pp, h);
    ((void (*)(void *))lk->vt[2])(lk);
}
