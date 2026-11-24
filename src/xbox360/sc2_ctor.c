/* SC2: constructors and inline-constructor factories whose store order and constant materialisation order were
   matched with the SC1 store-scheduling rule: each run of stores is split into sub-objects, each initialised by its
   own `static __inline` helper called on `(char *)o + K` (accesses through different pointer values keep source
   order, accesses through `o` are scheduled freely). The grouping per function was found by sweeping partitions of
   the target's store sequence (work/sc2/gen2.py). Plain route, no flags. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
typedef struct Sc2Obj { char b[0x1000]; } O;
#define W(o, off) (*(u32 *)((char *)(o) + (off)))
#define H(o, off) (*(u16 *)((char *)(o) + (off)))
#define Q(o, off) (*(u64 *)((char *)(o) + (off)))
#define B(o, off) (*(u8 *)((char *)(o) + (off)))
extern void fn_88617D88(void *o);
extern char lbl_880D6DA0[];
extern char lbl_880F9A64[];
extern char lbl_880F9A50[];
extern void ts4_msg_pool_service_get_8864DFF0(void);
extern void *fn_8899F760(u32 size);
extern char lbl_880F8D78[];
extern void fn_8861B128(void *o);
extern char lbl_880F8550[];
extern char lbl_880E4BA0[];
extern char lbl_880EF4BC[];
extern u32 lbl_88C6C924;
extern void ts4_call_seq_lbl_880EF47C_88781F50(void *p);
extern char lbl_880EF484[];
extern u32 lbl_88C6C920;
extern u32 ts4_if_call_seq_u32_lbl_88D45B38_88215B88(void);
extern char lbl_880EF564[];
extern u32 lbl_88C6C908;
extern char lbl_880EF2FC[];
extern u32 lbl_88C6C904;
extern char lbl_880EF318[];
extern u32 lbl_88C6C900;
extern char lbl_880EF350[];
extern u32 lbl_88C6C8F8;
extern char lbl_880D54B0[];
extern char lbl_880D51B8[];

/* Swing_DLL.xex 0x88173C00 */
static __inline void sc2_i88173C00_1(O *s) {
    W(s, 0) = (u32)0;
    W(s, 8) = (u32)0;
}
static __inline void sc2_i88173C00_2(O *s) {
    W(s, 0) = (u32)0xFFFFF;
    W(s, 8) = (u32)0;
    W(s, 12) = (u32)0;
    W(s, 16) = (u32)0;
}
static __inline void sc2_i88173C00_3(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
    W(s, 8) = (u32)0;
}
O *ts4_object_ctor_88173C00(O *o)
{
    fn_88617D88(o);
    W(o, 0) = (u32)(unsigned long)lbl_880D6DA0;
    sc2_i88173C00_1((O *)((char *)o + 32));
    sc2_i88173C00_2((O *)((char *)o + 36));
    sc2_i88173C00_3((O *)((char *)o + 56));
    return o;
}

/* Swing_DLL.xex 0x885F5610 */
static __inline void sc2_i885F5610_2(O *s) {
    W(s, 0) = (u32)0;
    H(s, 4) = (u16)0;
}
static __inline void sc2_i885F5610_3(O *s) {
    W(s, 0) = (u32)0;
    H(s, 8) = (u16)0;
    W(s, 4) = (u32)0;
}
void ts4_object_ctor_885F5610(O *o, u8 a, u8 b)
{
    B(o, 10) = (u8)a;
    B(o, 11) = (u8)b;
    sc2_i885F5610_2((O *)((char *)o + 4));
    sc2_i885F5610_3((O *)((char *)o + 72));
    W(o, 0) = (u32)(unsigned long)lbl_880F9A64;
    {
        u64 *q = (u64 *)((char *)o + 8);
        int i = 7;
        do { q++; *q = 0; } while (--i);
    }
}

/* Swing_DLL.xex 0x885F5678 */
static __inline void sc2_i885F5678_4(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
    H(s, 36) = (u16)0;
}
static __inline void sc2_i885F5678_9(O *s) {
    Q(s, 0) = (u64)0;
    W(s, 8) = (u32)0;
}
void ts4_object_ctor_885F5678(O *o, u8 a, u8 b)
{
    B(o, 10) = (u8)a;
    B(o, 11) = (u8)b;
    W(o, 4) = (u32)0;
    H(o, 8) = (u16)0;
    sc2_i885F5678_4((O *)((char *)o + 72));
    W(o, 0) = (u32)(unsigned long)lbl_880F9A50;
    {
        u64 *q = (u64 *)((char *)o + 8);
        int i = 7;
        do { q++; *q = 0; } while (--i);
    }

    Q(o, 80) = (u64)0;
    Q(o, 88) = (u64)0;
    sc2_i885F5678_9((O *)((char *)o + 96));
}

/* Swing_DLL.xex 0x885F7350 */
static __inline void sc2_i885F7350_2(O *s) {
    W(s, 0) = (u32)0;
    H(s, 4) = (u16)0;
}
static __inline void sc2_i885F7350_3(O *s) {
    W(s, 0) = (u32)0;
    H(s, 8) = (u16)0;
    W(s, 4) = (u32)0;
}
O *ts4_object_new_885F7350(u8 a, u8 b)
{
    O *o;
    ts4_msg_pool_service_get_8864DFF0();
    o = (O *)fn_8899F760(88);
    if (o != 0) {
    B(o, 10) = (u8)a;
    B(o, 11) = (u8)b;
    sc2_i885F7350_2((O *)((char *)o + 4));
    sc2_i885F7350_3((O *)((char *)o + 72));
    W(o, 0) = (u32)(unsigned long)lbl_880F9A64;
        {
        u64 *q = (u64 *)((char *)o + 8);
        int i = 7;
        do { q++; *q = 0; } while (--i);
        }

    } else {
        o = 0;
    }
    return o;
}

/* Swing_DLL.xex 0x885F73E0 */
static __inline void sc2_i885F73E0_4(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
    H(s, 36) = (u16)0;
}
static __inline void sc2_i885F73E0_9(O *s) {
    Q(s, 0) = (u64)0;
    W(s, 8) = (u32)0;
}
O *ts4_object_new_885F73E0(u8 a, u8 b)
{
    O *o;
    ts4_msg_pool_service_get_8864DFF0();
    o = (O *)fn_8899F760(112);
    if (o != 0) {
    B(o, 10) = (u8)a;
    B(o, 11) = (u8)b;
    W(o, 4) = (u32)0;
    H(o, 8) = (u16)0;
    sc2_i885F73E0_4((O *)((char *)o + 72));
    W(o, 0) = (u32)(unsigned long)lbl_880F9A50;
        {
        u64 *q = (u64 *)((char *)o + 8);
        int i = 7;
        do { q++; *q = 0; } while (--i);
        }

    Q(o, 80) = (u64)0;
    Q(o, 88) = (u64)0;
    sc2_i885F73E0_9((O *)((char *)o + 96));
    } else {
        o = 0;
    }
    return o;
}

/* Swing_DLL.xex 0x88625738 */
static __inline void sc2_i88625738_1(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)0xFFFFF;
}
O *ts4_object_ctor_88625738(O *o)
{
    fn_88617D88(o);
    W(o, 28) = (u32)0;
    sc2_i88625738_1((O *)((char *)o + 32));
    W(o, 0) = (u32)(unsigned long)lbl_880F8D78;
    return o;
}

/* Swing_DLL.xex 0x88626638 */
static __inline void sc2_i88626638_1(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88626638_2(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880F8550;
    W(s, 48) = (u32)0;
    W(s, 52) = (u32)0;
    W(s, 56) = (u32)0;
}
static __inline void sc2_i88626638_3(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
    W(s, 8) = (u32)0;
    W(s, 12) = (u32)0;
    W(s, 16) = (u32)0;
}
O *ts4_object_ctor_88626638(O *o)
{
    fn_8861B128(o);
    W(o, 36) = (u32)0;
    sc2_i88626638_1((O *)((char *)o + 40));
    sc2_i88626638_2((O *)((char *)o + 0));
    sc2_i88626638_3((O *)((char *)o + 60));
    return o;
}

/* Swing_DLL.xex 0x88782100 */
static __inline void sc2_i88782100_4(O *s, u32 a) {
    W(s, 0) = (u32)a;
    W(s, 4) = (u32)lbl_88C6C924;
}
static __inline void sc2_i88782100_5(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
O *ts4_object_ctor_88782100(O *o, u32 a)
{
    W(o, 4) = (u32)0;
    W(o, 0) = (u32)(unsigned long)lbl_880E4BA0;
    W(o, 8) = (u32)0;
    B(o, 12) = (u8)0;
    sc2_i88782100_4((O *)((char *)o + 16), a);
    sc2_i88782100_5((O *)((char *)o + 24));
    W(o, 0) = (u32)(unsigned long)lbl_880EF4BC;
    ts4_call_seq_lbl_880EF47C_88781F50((char *)o + 0x24);

    B(o, 1608) = (u8)0;
    return o;
}

/* Swing_DLL.xex 0x88782260 */
static __inline void sc2_i88782260_0(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
}
static __inline void sc2_i88782260_2(O *s, u32 a) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)a;
}
static __inline void sc2_i88782260_4(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88782260_6(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88782260_9(O *s) {
    W(s, 0) = (u32)0xB4EE304Du;
    W(s, 4) = (u32)0;
}
O *ts4_object_ctor_88782260(O *o, u32 a)
{
    sc2_i88782260_0((O *)((char *)o + 0));
    W(o, 8) = (u32)0;
    sc2_i88782260_2((O *)((char *)o + 12), a);
    W(o, 20) = (u32)lbl_88C6C920;
    sc2_i88782260_4((O *)((char *)o + 24));
    W(o, 0) = (u32)(unsigned long)lbl_880EF484;
    sc2_i88782260_6((O *)((char *)o + 32));
    ts4_call_seq_lbl_880EF47C_88781F50((char *)o + 0x30);
    W(o, 0x2c) = ts4_if_call_seq_u32_lbl_88D45B38_88215B88();

    W(o, 32) = (u32)0x988C2590u;
    sc2_i88782260_9((O *)((char *)o + 36));
    return o;
}

/* Swing_DLL.xex 0x88782508 */
static __inline void sc2_i88782508_0(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
}
static __inline void sc2_i88782508_2(O *s, u32 a) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)a;
    W(s, 8) = (u32)lbl_88C6C908;
}
static __inline void sc2_i88782508_3(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88782508_4(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880EF564;
    W(s, 36) = (u32)0;
    W(s, 40) = (u32)0;
    W(s, 44) = (u32)0;
}
static __inline void sc2_i88782508_5(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
void ts4_object_ctor_88782508(O *o, u32 a)
{
    sc2_i88782508_0((O *)((char *)o + 0));
    W(o, 8) = (u32)0;
    sc2_i88782508_2((O *)((char *)o + 12), a);
    sc2_i88782508_3((O *)((char *)o + 24));
    sc2_i88782508_4((O *)((char *)o + 0));
    sc2_i88782508_5((O *)((char *)o + 48));
    W(o, 56) = (u32)0;
    W(o, 32) = (u32)7;
}

/* Swing_DLL.xex 0x88782618 */
static __inline void sc2_i88782618_0(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
}
static __inline void sc2_i88782618_2(O *s, u32 a) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)a;
    W(s, 8) = (u32)lbl_88C6C904;
}
static __inline void sc2_i88782618_3(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88782618_4(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880EF2FC;
    W(s, 36) = (u32)0;
    W(s, 40) = (u32)0;
    W(s, 44) = (u32)0;
}
static __inline void sc2_i88782618_5(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
void ts4_object_ctor_88782618(O *o, u32 a)
{
    sc2_i88782618_0((O *)((char *)o + 0));
    W(o, 8) = (u32)0;
    sc2_i88782618_2((O *)((char *)o + 12), a);
    sc2_i88782618_3((O *)((char *)o + 24));
    sc2_i88782618_4((O *)((char *)o + 0));
    sc2_i88782618_5((O *)((char *)o + 48));
    W(o, 56) = (u32)0;
    W(o, 32) = (u32)7;
}

/* Swing_DLL.xex 0x88782738 */
static __inline void sc2_i88782738_0(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
}
static __inline void sc2_i88782738_2(O *s, u32 a) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)a;
    W(s, 8) = (u32)lbl_88C6C900;
}
static __inline void sc2_i88782738_3(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88782738_4(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880EF318;
    W(s, 36) = (u32)0;
    W(s, 40) = (u32)0;
    W(s, 44) = (u32)0;
}
static __inline void sc2_i88782738_5(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
void ts4_object_ctor_88782738(O *o, u32 a)
{
    sc2_i88782738_0((O *)((char *)o + 0));
    W(o, 8) = (u32)0;
    sc2_i88782738_2((O *)((char *)o + 12), a);
    sc2_i88782738_3((O *)((char *)o + 24));
    sc2_i88782738_4((O *)((char *)o + 0));
    sc2_i88782738_5((O *)((char *)o + 48));
    W(o, 56) = (u32)0;
    W(o, 60) = (u32)0;
    W(o, 32) = (u32)7;
}

/* Swing_DLL.xex 0x88782830 */
static __inline void sc2_i88782830_0(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
}
static __inline void sc2_i88782830_2(O *s, u32 a) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)a;
    W(s, 8) = (u32)lbl_88C6C8F8;
}
static __inline void sc2_i88782830_3(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88782830_4(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880EF350;
    W(s, 32) = (u32)0;
    W(s, 52) = (u32)0;
    W(s, 40) = (u32)0;
}
static __inline void sc2_i88782830_5(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
void ts4_object_ctor_88782830(O *o, u32 a)
{
    sc2_i88782830_0((O *)((char *)o + 0));
    W(o, 8) = (u32)0;
    sc2_i88782830_2((O *)((char *)o + 12), a);
    sc2_i88782830_3((O *)((char *)o + 24));
    sc2_i88782830_4((O *)((char *)o + 0));
    sc2_i88782830_5((O *)((char *)o + 44));
    W(o, 36) = (u32)7;
}

/* Swing_DLL.xex 0x88951A00 */
static __inline void sc2_i88951A00_0(O *s) {
    W(s, 0) = (u32)0;
    W(s, 12) = (u32)0;
}
static __inline void sc2_i88951A00_2(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88951A00_3(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880D54B0;
    W(s, 32) = (u32)0;
    W(s, 36) = (u32)0;
}
static __inline void sc2_i88951A00_5(O *s) {
    W(s, 0) = (u32)-1;
    W(s, 64) = (u32)0;
    W(s, 72) = (u32)0;
}
static __inline void sc2_i88951A00_7(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)0;
    W(s, 8) = (u32)0;
}
O *ts4_object_ctor_88951A00(O *o)
{
    sc2_i88951A00_0((O *)((char *)o + 4));
    W(o, 20) = (u32)0;
    sc2_i88951A00_2((O *)((char *)o + 24));
    sc2_i88951A00_3((O *)((char *)o + 0));
    W(o, 8) = (u32)-1;
    sc2_i88951A00_5((O *)((char *)o + 12));
    W(o, 80) = (u32)0xFFFFF;
    sc2_i88951A00_7((O *)((char *)o + 44));
    W(o, 56) = (u32)0;
    return o;
}

/* Swing_DLL.xex 0x889528E8 */
static __inline void sc2_i889528E8_0(O *s) {
    W(s, 0) = (u32)0;
    W(s, 12) = (u32)0;
}
static __inline void sc2_i889528E8_2(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i889528E8_3(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880D51B8;
    W(s, 32) = (u32)0;
}
static __inline void sc2_i889528E8_6(O *s) {
    W(s, 0) = (u32)-1;
    W(s, 44) = (u32)0;
    W(s, 52) = (u32)0;
}
O *ts4_object_ctor_889528E8(O *o)
{
    sc2_i889528E8_0((O *)((char *)o + 4));
    W(o, 20) = (u32)0;
    sc2_i889528E8_2((O *)((char *)o + 24));
    sc2_i889528E8_3((O *)((char *)o + 0));
    W(o, 36) = (u32)0;
    W(o, 8) = (u32)-1;
    sc2_i889528E8_6((O *)((char *)o + 12));
    W(o, 60) = (u32)0xFFFFF;
    W(o, 48) = (u32)0;
    W(o, 52) = (u32)0;
    W(o, 44) = (u32)0;
    return o;
}
