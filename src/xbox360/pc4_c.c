/* PC4 batch C: Lua string-library helpers reading the script float-constant pool (Swing_DLL.xex). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Pool declared per translation unit: only this form reproduces the original addressing. */
static const float g_ts4_script_constants[668] = {1.0f};
#define POOLD(byteoff) (*(const double *)((const char *)g_ts4_script_constants + (byteoff)))

extern const char *lib3_luaL_checklstring_8882EB20(void *L, int idx, u32 *len);
extern const char *lib3_luaL_checklwstring_8882EA30(void *L, int idx, u32 *len);
extern double ts4_lua_opt_number_default_8882EA98(void *L, int idx);
/* Raises a Lua argument error; does not return. */
#ifdef _MSC_VER
__declspec(noreturn)
#endif
extern void lib3_luaL_argerror_8882E6B8(void *L, int idx, const void *msg);
extern char lbl_880E1A6C[];
extern void ts4_lua_pushnumber_888240B8(void *L, double n);

/* Lua state fields used by the "argument 2 present" test. */
typedef struct pc4_lua_state {
    char pad_00[0xC];
    char *top;       /* 0x0C */
    char *base;      /* 0x10 */
} pc4_lua_state;

/* 0x8882A178: string.byte-style: push byte at 1-based (negative = from end) position arg 2 (default pool 0x78). */
int ts4_lua_string_byte_8882A178(pc4_lua_state *L)
{
    u32 len;
    const u8 *s = (const u8 *)lib3_luaL_checklstring_8882EB20(L, 1, &len);
    char *arg = L->base + 0x10;
    double d;
    int pos;
    int none = (arg >= L->top) || (arg == 0) || (*(int *)arg <= 0); /* arg 2 absent or nil */
    if (none)
        d = POOLD(0x78);
    else
        d = ts4_lua_opt_number_default_8882EA98(L, 2);
    pos = (int)d;
    if (pos < 0)
        pos += len + 1;
    if (pos > 0 && (u32)pos <= len) {
        ts4_lua_pushnumber_888240B8(L, (double)s[pos - 1]);
        return 1;
    }
    return 0;
}

/* 0x88832558: same for 16-bit characters. */
int ts4_lua_wstring_byte_88832558(pc4_lua_state *L)
{
    u32 len;
    const u16 *s = (const u16 *)lib3_luaL_checklwstring_8882EA30(L, 1, &len);
    char *arg = L->base + 0x10;
    double d;
    int pos;
    int none = (arg >= L->top) || (arg == 0) || (*(int *)arg <= 0); /* arg 2 absent or nil */
    if (none)
        d = POOLD(0x78);
    else
        d = ts4_lua_opt_number_default_8882EA98(L, 2);
    pos = (int)d;
    if (pos < 0)
        pos += len + 1;
    if (pos > 0 && (u32)pos <= len) {
        ts4_lua_pushnumber_888240B8(L, (double)s[pos - 1]);
        return 1;
    }
    lib3_luaL_argerror_8882E6B8(L, 2, lbl_880E1A6C);
    return 0;
}

extern void ts4_call_seq_fn_8881C130_8881C200(void *L);

typedef struct pc4_lua_global {
    char pad_00[0x28];
    u32 threshold;   /* 0x28 */
    u32 used;        /* 0x2C */
} pc4_lua_global;

typedef struct pc4_lua_state2 {
    char pad_00[0xC];
    char *top;       /* 0x0C */
    char *base;      /* 0x10 */
    pc4_lua_global *g; /* 0x14 */
} pc4_lua_state2;

/* 0x8882D2A0: set a threshold (likely the collector threshold) from arg 1 (default pool 0x58), scaled by 1024; collect if over. */
int ts4_lua_set_threshold_from_arg_8882D2A0(pc4_lua_state2 *L)
{
    int none = ((char *)L->base >= L->top) || (L->base == 0) || (*(int *)L->base <= 0);
    double d;
    u32 v;
    if (none)
        d = POOLD(0x58);
    else
        d = ts4_lua_opt_number_default_8882EA98(L, 1);
    v = (u32)(int)d;
    if (v > 0x3FFFFFu)
        L->g->threshold = (u32)-1;
    else
        L->g->threshold = v << 10;
    if (L->g->used >= L->g->threshold)
        ts4_call_seq_fn_8881C130_8881C200(L);
    return 0;
}

