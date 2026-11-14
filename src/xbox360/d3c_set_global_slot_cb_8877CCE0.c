/* Swing_DLL.xex 0x8877CCE0-0x8877CF20, executable version 0.0.0.3. */
typedef unsigned int u32;

typedef struct Ts4ScriptArg {
    char pad[8];
    u32 **src1;
    u32 idx1;
    u32 **src2;
    u32 idx2;
} Ts4ScriptArg;

typedef struct Ts4ValueSlot {
    char pad[0x10];
    int val;
} Ts4ValueSlot;

extern char *lbl_88D45894;
extern double ts4_lua_tonumber_88822420(u32 *obj, u32 idx);

/* Script callback: evaluates two script values; the first selects (by id 0xf5bf4f97) which of two
   global slots receives the integer value of the second. */
#define TS4_SET_GLOBAL_SLOT_CB(NAME, OFF_A, OFF_B) \
    u32 NAME(void *unused, Ts4ScriptArg *a) \
    { \
        u32 key = (u32)ts4_lua_tonumber_88822420(*a->src1, a->idx1); \
        (void)unused; \
        if (lbl_88D45894 != 0) { \
            int v = (int)ts4_lua_tonumber_88822420(*a->src2, a->idx2); \
            if (key == 0xf5bf4f97) (*(Ts4ValueSlot **)(lbl_88D45894 + OFF_A))->val = v; \
            else (*(Ts4ValueSlot **)(lbl_88D45894 + OFF_B))->val = v; \
        } \
        return 0; \
    }

TS4_SET_GLOBAL_SLOT_CB(ts4_set_global_slot_cb_8877CCE0, 68, 76) /* 0x8877CCE0 */
TS4_SET_GLOBAL_SLOT_CB(ts4_set_global_slot_cb_8877CD80, 64, 72) /* 0x8877CD80 */
TS4_SET_GLOBAL_SLOT_CB(ts4_set_global_slot_cb_8877CE80, 52, 56) /* 0x8877CE80 */
