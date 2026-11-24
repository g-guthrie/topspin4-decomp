/* HS1 matching batch b: small leaf functions and destructors.
   MSVC 16.00.10224.00 /O2 /Oi, verified with tools/fn_check.py. */

/* Swing_DLL.xex 0x883332F0 */
/* returns 1 via out when the object has no owner, or is ready and not locked */
int ts4_get_ready_flag_883332F0(char *self, unsigned char *out)
{
    char *p = *(char **)(self + 0x180);
    if (p == 0 || ((*(unsigned int *)(*(char **)(self + 0x190) + 0x24) < *(unsigned int *)(p + 0x118) || (*(volatile unsigned int *)(self + 0x11c) & 8)) && !(*(volatile unsigned int *)(self + 0x11c) & 0x100))) {
        *out = 1;
    } else {
        *out = 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x883A37C8 */
/* query property by id (0x100/0x200/0x400) from a subobject at -0x1c */
int ts4_query_prop_883A37C8(char *self, unsigned int *out, unsigned int id)
{
    char *o = self ? self - 0x1c : 0;
    if (id == 0x100) {
        *out = *(unsigned int *)(o + 0x890);
        return 0;
    }
    if (id == 0x400) {
        *out = *(unsigned char *)(o + *(int *)(o + 0x890) + 0x21c);
        return 0;
    }
    if (id == 0x200)
        *out = *(unsigned int *)(o + 0x88c);
    return 0;
}

/* Swing_DLL.xex 0x883819B8 */
int ts4_if_get_u8_off50_88381458(char *self);
/* out = 4 when the sub-object flag query is zero; 0x25 if out is null */
int ts4_get_mode_883819B8(char *self, int *out)
{
    char *o = self ? self - 0x1c : 0;
    int r;
    if (out == 0) return 0x25;
    r = ts4_if_get_u8_off50_88381458(o);
    if (r == 0)
        *out = 4;
    return r;
}

/* Swing_DLL.xex 0x883A3758 */
/* query property by id (0x100/0x200/0x400) from a subobject at -0x1c */
int ts4_query_prop_883A3758(char *self, unsigned int *out, unsigned int id)
{
    char *o = self ? self - 0x1c : 0;
    if (id == 0x100) {
        *out = *(unsigned int *)(o + 0x588);
        return 0;
    }
    if (id == 0x400) {
        *out = *(unsigned int *)(o + 0x58c);
        return 0;
    }
    if (id == 0x200)
        *out = *(unsigned int *)(*(char **)(o + 0x210) + (unsigned int)*(unsigned char *)(o + *(int *)(o + 0x890) + 0x21c) * 8);
    return 0;
}

/* Swing_DLL.xex 0x88359B00 */
/* fold the packed nibbles of the byte at +0x27a into the counter at +0x260 (clamped to 0..0x40) */
int ts4_update_counter_88359B00(char *self)
{
    unsigned int b = *(unsigned char *)(self + 0x27a);
    int *ctx = *(int **)self;
    unsigned int lo = b & 0xf;
    if (lo == 0)
        *(int *)(self + 0x260) = *(int *)(self + 0x260) - (b >> 4);
    if ((b & ~0xfu) == 0)
        *(int *)(self + 0x260) = *(int *)(self + 0x260) + lo;
    if (*(int *)(self + 0x260) > 0x40)
        *(int *)(self + 0x260) = 0x40;
    if (*(int *)(self + 0x260) < 0)
        *(int *)(self + 0x260) = 0;
    *(unsigned char *)((char *)ctx + 0x1cc) |= 4;
    return 0;
}

/* Swing_DLL.xex 0x881AD5D0 */
extern char lbl_880E16D4[], lbl_880E165C[];
static void *lbl_88D459E8;
void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
void ts4_tsu_cleanup_end(void *self);
/* scalar-deleting destructor: reset vtables, clear instance pointer, base cleanup */
void *ts4_dtor_clear_instance_881AD5D0(void **self, unsigned int flags)
{
    *(void *volatile *)self = lbl_880E16D4;
    self[7] = lbl_880E165C;
    lbl_88D459E8 = 0;
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
    if (flags & 1)
        ts4_tsu_cleanup_end(self);
    return self;
}

/* Swing_DLL.xex 0x8821D738 */
extern char lbl_880F2918[];
static void *lbl_88D45AD8;
void ts4_if_call_seq_u32_off0_882240E8(void *p);
void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
void ts4_tsu_cleanup_end(void *self);
/* scalar-deleting destructor: reset vtable, clear instance pointer, destroy member and base */
void *ts4_dtor_clear_instance_8821D738(void **self, unsigned int flags)
{
    *(void *volatile *)self = lbl_880F2918;
    lbl_88D45AD8 = 0;
    ts4_if_call_seq_u32_off0_882240E8(self + 7);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
    if (flags & 1)
        ts4_tsu_cleanup_end(self);
    return self;
}

/* Swing_DLL.xex 0x88273880 */
extern char lbl_880F51E0[];
static void *lbl_88D45B0C;
void ts4_loop_call_seq_lbl_880D6268_8892AF80(void *p);
void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
void ts4_tsu_cleanup_end(void *self);
/* scalar-deleting destructor: reset vtable, clear instance pointer, destroy member and base */
void *ts4_dtor_clear_instance_88273880(void **self, unsigned int flags)
{
    *(void *volatile *)self = lbl_880F51E0;
    lbl_88D45B0C = 0;
    ts4_loop_call_seq_lbl_880D6268_8892AF80(self + 7);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
    if (flags & 1)
        ts4_tsu_cleanup_end(self);
    return self;
}

/* Swing_DLL.xex 0x881BD728 */
extern char g_ts4_true_string[];
extern char lbl_880D1B30[];
unsigned char ts4_script_string_equals(void *a, const char *b);
/* script value is a string (type 5) equal to one of the "true" strings */
unsigned char ts4_script_value_is_true_881BD728(int *value)
{
    return value[0] == 5 && (ts4_script_string_equals(value + 4, g_ts4_true_string) || ts4_script_string_equals(value + 4, lbl_880D1B30));
}

/* Swing_DLL.xex 0x881E3A68 */
extern char *lbl_88D41FC4;
int lib3_lua_type_88822738(void *L, int idx);
const char *lib3_lua_tostring_88822888(void *L, int idx);
void ts4_loop_call_seq_u8_off0_8819B1A8(void *obj, const char *s);
typedef struct TS4LuaArg { void **state; int idx; } TS4LuaArg;
/* script callback: if the argument is a string/number/9, pass its string to the global logger at +0x90 */
int ts4_script_log_arg_881E3A68(void *unused, char *call)
{
    TS4LuaArg *arg = (TS4LuaArg *)(call + 8);
    int t;
    (void)unused;
    t = lib3_lua_type_88822738(*arg->state, arg->idx);
    if (t == 4 || t == 3 || t == 9) {
        const char *s = lib3_lua_tostring_88822888(*arg->state, arg->idx);
        ts4_loop_call_seq_u8_off0_8819B1A8(lbl_88D41FC4 + 0x90, s);
    }
    return 0;
}

/* Swing_DLL.xex 0x8836F918 */
void ts4_if_get_u32_offe4_88309B78(void *p);
/* release the three handles held at +0x164/+0x16c/+0x174 of the outer object */
int ts4_release_three_8836F918(char *self)
{
    char *o = self ? self - 0x1c : 0;
    if (*(void **)(o + 0x164)) ts4_if_get_u32_offe4_88309B78(*(void **)(o + 0x164));
    if (*(void **)(o + 0x16c)) ts4_if_get_u32_offe4_88309B78(*(void **)(o + 0x16c));
    if (*(void **)(o + 0x174)) ts4_if_get_u32_offe4_88309B78(*(void **)(o + 0x174));
    return 0;
}

/* Swing_DLL.xex 0x8833D758 */
void *ts4_memset(void *p, int v, unsigned int n);
/* clear the two buffers of the outer object and its two counters */
int ts4_clear_buffers_8833D758(char *self)
{
    char *o = self ? self - 0x1c : 0;
    void *b = *(void **)(o + 0x14c);
    *(int *)(o + 0x164) = 0;
    *(int *)(o + 0x168) = 0;
    if (b)
        ts4_memset(b, 0, *(unsigned int *)(o + 0x15c));
    if (*(void **)(o + 0x150))
        ts4_memset(*(void **)(o + 0x150), 0, *(unsigned int *)(o + 0x160));
    return 0;
}
