#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/* Swing_DLL.xex 0x88800B88-0x8883EEE8, executable version 0.0.0.3. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "d6q_lua.h"

#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif

extern void ts4_lua_pushlstring_88823FC0(lua_State *L, const char *s, u32 len);
extern void ts4_lua_pushnil_88824188(lua_State *L);
extern void ts4_lua_call_8881E258(lua_State *L, TValue *func, int nresults);
extern int fn_88822738(lua_State *L, int idx);
extern void fn_888368B0(lua_State *L, int a, TValue *v);
extern const char *lbl_880C9684[];
extern char lbl_880E17A4[];
extern TS4_NORETURN int ts4_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname);
extern char lbl_880E24B8[];
extern char lbl_880C9A48[];
extern int fn_8882E0D8(void *, char *, char *);
extern void *fn_887FFFB8(void *a, int b, int c);
extern void fn_88834B28(lua_State *L, const unsigned short *s, unsigned len);
extern void *fn_881AC7D0(void *tbl, int *key);
extern void *ts4_find_record_by_key_881AC778(void *tbl, int *key);
extern const unsigned char lbl_880C970C[];
extern void fn_888208A8(lua_State *L, unsigned instr);
extern int ts4_call_seq_u32_off20_88820DD0(lua_State *L);

/* Call the function that sits n+1 slots below the top. */
static void lib3_lua_call_88822970(lua_State *L, int n, int nres)
{
    ts4_lua_call_8881E258(L, L->top - (n + 1), nres);
}

/* Truncate a double stored at +0x10 to an unsigned integer. */
static unsigned ts4_get_88836190(char *p)
{
    return (unsigned)*(double *)(p + 0x10);
}

/* lua_pushstring: nil for a null pointer, else push the string with its length. */
static void lib3_lua_pushstring_88824CC8(lua_State *L, const char *s)
{
    if (s == 0)
        ts4_lua_pushnil_88824188(L);
    else
        ts4_lua_pushlstring_88823FC0(L, s, strlen(s));
}

/* Widen a narrow string into a 16-bit string, including the terminator. */
static void lib3_lua_widen_string_8882ED68(const char *s, short *d)
{
    while (*s)
        *d++ = *s++;
    *d = 0;
}

/* Step back one cell when the cell's opcode class has the flag bit set. */
static void *lua2_getjumpcontrol_88820168(u32 *p)
{
    u32 *q = p - 1;
    if (lbl_880C970C[*q & 0x3F] & 0x80)
        return q;
    return p;
}

/* luaL_typerror with a type tag: -1 selects the "no value" name. */
static int lib3_tag_error_8882EA08(lua_State *L, int narg, int tag)
{
    const char *tname;
    if (tag == -1)
        tname = lbl_880E17A4;
    else
        tname = lbl_880C9684[tag];
    return ts4_luaL_typerror_8882E950(L, narg, tname);
}

/* Push a 16-bit string, nil for a null pointer. */
void ts4_lua_pushwstring_88834C10(lua_State *L, const unsigned short *s)
{
    const unsigned short *p;
    if (s == 0) {
        ts4_lua_pushnil_88824188(L);
        return;
    }
    p = s;
    while (*p)
        p++;
    fn_88834B28(L, s, (unsigned)(p - s));
}

/* Swap every adjacent byte pair of an n-pair buffer. */
static void lib3_swap_byte_pairs_88824DA0(unsigned char *p, unsigned n)
{
    while (n--) {
        unsigned char t = p[0];
        p[0] = p[1];
        p[1] = t;
        p += 2;
    }
}

/* Whether the value at an index has type 9 or 3. */
int ts4_lua_isnumberlike_88834940(lua_State *L, int idx)
{
    int t = fn_88822738(L, idx);
    return (t == 9 || t == 3) ? 1 : 0;
}

/* Value field of a slot unless it is in the ready state. */
int ts4_slot_value_if_ready_88838860(void *o)
{
    u8 *s = TS5_AT(u8 *, o, 0x1c);
    int r = 0;
    if (s[0x1a] != 1 || s[0x18] == 1)
        r = TS5_AT(int, s, 0x28);
    return r;
}

/* Address of the payload that follows an offset-linked record header. */
void *ts4_record_payload_ptr_88800B88(void *a, int b)
{
    char *p = (char *)fn_887FFFB8(a, b, 0) + 0x28;
    return p + TS5_AT(int, p, 0) + 0x40;
}

/* Run the table-driven handler with the two fixed tables and report success. */
static int lib3_open_string_extra_88825548(void *x)
{
    fn_8882E0D8(x, lbl_880E24B8, lbl_880C9A48);
    return 0;
}

/* Float field of the record found for a key. */
static float ts4_call_seq_u32_off24_8883EEB0(void *o, int key)
{
    return *(float *)((char *)fn_881AC7D0((char *)TS5_AT(void *, o, 0x24) + 0x74, &key) + 4);
}

/* Integer field of the record found for a key. */
static int ts4_call_seq_u32_off24_8883EEE8(void *o, int key)
{
    return TS5_AT(int, ts4_find_record_by_key_881AC778((char *)TS5_AT(void *, o, 0x24) + 0x74, &key), 4);
}

/* Whether the value at an index is a string, number or userdata. */
static int lib3_lua_isstring_88822808(lua_State *L, int idx)
{
    int t = fn_88822738(L, idx);
    return (t == 4 || t == 3 || t == 9) ? 1 : 0;
}

/* lua_setgcthreshold: scale the threshold (in KB) and collect if already over it. */
static void lib3_lua_setgcthreshold_88822848(lua_State *L, unsigned k)
{
    if (k > 0x3FFFFF)
        ((Ts4LuaGlobal *)L->l_G)->GCthreshold = (u32)-1;
    else
        ((Ts4LuaGlobal *)L->l_G)->GCthreshold = k << 10;
    TS4_CHECK_GC(L);
}

/* Call a helper with a freshly built number value. */
void ts4_call_with_number_888373B8(lua_State *L, int a, int n)
{
    TValue v;
    v.tt = 3;
    v.u.n = (double)n;
    fn_888368B0(L, a, &v);
}

/* wcsncmp over 16-bit characters. */
static int lib3_lua_wstrncmp_8882F0B0(const unsigned short *a, const unsigned short *b, unsigned n)
{
    for (; n; n--, a++, b++) {
        if (*a != *b)
            return (*a < *b) ? -1 : 1;
    }
    return 0;
}

/* luaK_codeABC: pack an instruction from its opcode and three operands, then emit it. */
static int lua2_condjump_88820FE8(lua_State *L, int op, int a, int b, int c)
{
    fn_888208A8(L, (((((a << 9) | b) << 9) | c) << 6) | op);
    return ts4_call_seq_u32_off20_88820DD0(L);
}
