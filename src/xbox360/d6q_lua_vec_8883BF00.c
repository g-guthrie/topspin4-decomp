/* Swing_DLL.xex 0x88838838-0x8883D1B8, executable version 0.0.0.3. */
#include "d6q_lua.h"

#ifdef _MSC_VER
#define TS6_FORCEINLINE static __forceinline
#else
#define TS6_FORCEINLINE static inline
#endif

extern int ts4_lua_toboolean_88822398(lua_State *L, int idx);
extern void *lbl_88D459E8;

/* Script instance: the Lua state pointer sits behind an indirection at +0x6c. */
typedef struct Ts6Inst {
    char pad[0x6c];
    lua_State **ls;
} Ts6Inst;

/* Global game state: two flag byte pointers. */
typedef struct Ts6GameA {
    char pad[0x60];
    char *flag;
} Ts6GameA;

typedef struct Ts6GameB {
    char pad[0x24];
    char *flag;
} Ts6GameB;

/* Script callback: store argument 1 as a boolean flag in the game state. */
int ts4_script_setflag_a_8883BF00(void *a, Ts6Inst **b)
{
    int r = ts4_lua_toboolean_88822398(*(*b)->ls, 1);
    char v = (char)(r != 0);
    ((Ts6GameA *)lbl_88D459E8)->flag[0x18] = v;
    (void)a;
    return 0;
}

/* Script callback: store argument 1 as a boolean flag in the game state (second slot). */
int ts4_script_setflag_b_8883C188(void *a, Ts6Inst **b)
{
    int r = ts4_lua_toboolean_88822398(*(*b)->ls, 1);
    char v = (char)(r != 0);
    ((Ts6GameB *)lbl_88D459E8)->flag[0] = v;
    (void)a;
    return 0;
}

/* Self-relative vector header: byte offset of the first element (-1 when empty) and count. */
typedef struct Ts6RelVec {
    int off;
    int count;
} Ts6RelVec;

typedef struct Ts6Elem88 {
    char pad[0x84];
    char flag;
    char pad2[3];
} Ts6Elem88;

typedef struct Ts6ElemF4 {
    char pad[0xf0];
    char flag;
    char pad2[3];
} Ts6ElemF4;

TS6_FORCEINLINE Ts6Elem88 *ts6_end88(Ts6RelVec *v)
{
    Ts6Elem88 *r = 0;
    if (v->off != -1)
        r = (Ts6Elem88 *)((char *)v + v->off) + v->count;
    return r;
}

TS6_FORCEINLINE Ts6Elem88 *ts6_beg88(Ts6RelVec *v)
{
    Ts6Elem88 *r = 0;
    if (v->off != -1)
        r = (Ts6Elem88 *)((char *)v + v->off);
    return r;
}

TS6_FORCEINLINE Ts6ElemF4 *ts6_endF4(Ts6RelVec *v)
{
    Ts6ElemF4 *r = 0;
    if (v->off != -1)
        r = (Ts6ElemF4 *)((char *)v + v->off) + v->count;
    return r;
}

TS6_FORCEINLINE Ts6ElemF4 *ts6_begF4(Ts6RelVec *v)
{
    Ts6ElemF4 *r = 0;
    if (v->off != -1)
        r = (Ts6ElemF4 *)((char *)v + v->off);
    return r;
}

/* Clear the flag byte of every 0x88-byte element. */
void ts4_clear_flags88_8883D0C8(Ts6RelVec *v)
{
    Ts6Elem88 *end = ts6_end88(v);
    Ts6Elem88 *p;
    for (p = ts6_beg88(v); p != end; p++)
        p->flag = 0;
}

/* Clear the flag byte of every 0xF4-byte element. */
void ts4_clear_flagsF4_8883D118(Ts6RelVec *v)
{
    Ts6ElemF4 *end = ts6_endF4(v);
    Ts6ElemF4 *p;
    for (p = ts6_begF4(v); p != end; p++)
        p->flag = 0;
}

/* Same operation as above, second copy. */
void ts4_clear_flagsF4b_8883D168(Ts6RelVec *v)
{
    Ts6ElemF4 *end = ts6_endF4(v);
    Ts6ElemF4 *p;
    for (p = ts6_begF4(v); p != end; p++)
        p->flag = 0;
}

/* Container whose pointer at +0x1c leads to a self-relative table of 0x1c-byte rows. */
typedef struct Ts6Owner {
    char pad[0x1c];
    char *table;
} Ts6Owner;

/* Copy the word that sits 8 bytes before the end of row i. */
void ts4_copy_row_word_88838838(int *out, Ts6Owner *o, int i)
{
    char *h = o->table + 0x1c;
    *out = *(int *)(h + (*(int *)h + i * 0x1c) - 8);
}
