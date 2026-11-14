/* PC4 batch B: functions reading the script float-constant pool (Swing_DLL.xex). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

/* Pool declared per translation unit: only this form reproduces the original addressing. */
static const float g_ts4_script_constants[668] = {1.0f};
#define POOLD(byteoff) (*(const double *)((const char *)g_ts4_script_constants + (byteoff)))

extern u8 lbl_88D4583D;
extern u64 fn_885637C0(int);
extern void ts4_call_seq_fn_8856CE60_885640E0(u32);
extern int fn_88564110(void);
extern int lib3_lua_tostring_88822888(void *L, int idx);
extern void lib3_luaL_typerror_8882E950(void *L, int idx, int arg);
extern void lua3_lua_settop_888246A8(void *L);
extern void ts4_lua_pushnumber_888240B8(void *L, double n);
extern void lib3_lua_pushcclosure_88823E00(void *L, void *fn, int n);
extern void lib3_gfind_aux_88828338(void);
extern void fn_888313E0(void);
extern int fn_888348A0(void *L, int idx);
extern char lbl_880C9684[];
extern float lbl_8814B440;
extern char lbl_880DC810[];
extern void fn_888AF5C0(void *self);

extern double ts4_lua_tonumber_88822420(void *L, int idx);
extern int lib3_lua_isnumber_88822650(void *L, int idx);

/* 0x8882EA98: read a Lua number; if it equals pool double 0x58 and arg is not set, apply default slot 3. */
double ts4_lua_opt_number_default_8882EA98(void *L, int idx)
{
    double v = ts4_lua_tonumber_88822420(L, idx);
    if (v == POOLD(0x58) && !lib3_lua_isnumber_88822650(L, idx))
        lib3_luaL_typerror_8882E950(L, idx, *(int *)(lbl_880C9684 + 0xC));
    return v;
}


#define POOLF(i) g_ts4_script_constants[i]

/* 0x888C4708: classify x against pool thresholds into a (kind, hash) pair; only when flag is zero. */
void ts4_classify_range_hash_888C4708(float x, u8 flag, int *kind, u32 *hash)
{
    *kind = 0;
    *hash = 0xF489E4D9u;
    if (flag != 0)
        return;
    if (x >= POOLF(14) && x < POOLF(227)) {
        *kind = 1;
        *hash = 0x8CDA49A8u;
        return;
    }
    if ((x >= POOLF(227) && x < POOLF(285)) || (x > POOLF(171) && x <= POOLF(67))) {
        *kind = 2;
        *hash = 0x625E2078u;
        return;
    }
    if (x >= POOLF(285) && x <= POOLF(171)) {
        *kind = 2;
        *hash = 0x39445A7Eu;
        return;
    }
    if (x > POOLF(67) && x <= POOLF(0)) {
        *kind = 0;
        *hash = 0xB0DA3179u;
        return;
    }
}


extern void fn_88939288(void *self, u32 *out, int n);

extern void fn_888ADBA8(float a, float b);
extern void fn_888C1910(void *self);

/* 0x8893C808: read a counter via fn_88939288(self,&v,10) and store it scaled by pool double 0x768 as float. */
void *ts4_read_scaled_counter_8893C808(void *self, float *out)
{
    u32 v = 0;
    fn_88939288(self, &v, 10);
    *out = (float)((double)v * POOLD(0x768));
    return self;
}

/* 0x888C1990: store (int)(b * pool[15] / a) at +0x58 using ints at +0x30/+0x34 of the nested object; then update. */
void ts4_store_scaled_ratio_and_update_888C1990(char *self)
{
    char *obj = *(char **)(*(char **)(self + 4) + 0x4C);
    *(int *)(self + 0x58) = (int)((float)*(int *)(obj + 0x34) * g_ts4_script_constants[15] / (float)*(int *)(obj + 0x30));
    fn_888C1910(self);
}

extern void fn_889393C0(void *self, u32 value, int n);

typedef struct pc4_mode_holder {
    char pad_00[0xC];
    int mode;            /* 0x0C */
} pc4_mode_holder;

/* 0x8893C880: if 0 <= x <= pool[0], set a value scaled by pool double 0x338; otherwise default mode to 3 if unset. */
void *ts4_set_scaled_or_default_mode_8893C880(pc4_mode_holder *self, float x)
{
    if (x >= lbl_8814B440 && x <= g_ts4_script_constants[0]) {
        fn_889393C0(self, (u32)(x * POOLD(0x338)), 10);
    } else if (self->mode == 0) {
        self->mode = 3;
    }
    return self;
}
