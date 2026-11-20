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
extern char lbl_880E4BA0[];
extern char lbl_880EF648[];
extern u32 lbl_88C6C938;
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
extern char lbl_880EF564[];
extern u32 lbl_88C6C908;
extern char lbl_880EF318[];
extern u32 lbl_88C6C900;
extern char lbl_880EF2FC[];
extern u32 lbl_88C6C904;
extern char lbl_880EF350[];
extern u32 lbl_88C6C8F8;
extern void fn_88617D88(void *o);
extern void ts4_object_finalize(void *p);
extern void *lbl_88D45958;
extern char lbl_880DB904[];

/* Swing_DLL.xex 0x882159B0 */
static __inline void sc2_i882159B0_0(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
}
static __inline void sc2_i882159B0_2(O *s, u32 a) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)a;
    W(s, 8) = (u32)lbl_88C6C938;
}
static __inline void sc2_i882159B0_3(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i882159B0_4(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880EF648;
    W(s, 32) = (u32)0;
}
O *ts4_object_new_882159B0(u32 a)
{
    O *o;
    o = (O *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x24, 4, 0, 2);
    if (o != 0) {
    sc2_i882159B0_0((O *)((char *)o + 0));
    W(o, 8) = (u32)0;
    sc2_i882159B0_2((O *)((char *)o + 12), a);
    sc2_i882159B0_3((O *)((char *)o + 24));
    sc2_i882159B0_4((O *)((char *)o + 0));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88218858 */
static __inline void sc2_i88218858_0(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
    W(s, 8) = (u32)0;
}
static __inline void sc2_i88218858_4(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88218858_5(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880EF564;
    W(s, 36) = (u32)0;
    W(s, 40) = (u32)0;
    W(s, 44) = (u32)0;
}
static __inline void sc2_i88218858_6(O *s) {
    W(s, 16) = (u32)0;
    W(s, 20) = (u32)0;
    W(s, 24) = (u32)0;
    W(s, 0) = (u32)7;
}
O *ts4_object_new_88218858(u32 *p)
{
    O *o;
    o = (O *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x3c, 4, 0, 2);
    if (o != 0) {
        u32 a = *p;
    sc2_i88218858_0((O *)((char *)o + 0));
    B(o, 12) = (u8)0;
    W(o, 16) = (u32)a;
    W(o, 20) = (u32)lbl_88C6C908;
    sc2_i88218858_4((O *)((char *)o + 24));
    sc2_i88218858_5((O *)((char *)o + 0));
    sc2_i88218858_6((O *)((char *)o + 32));
    } else {
        o = 0;
    }
    return o;
}

/* Swing_DLL.xex 0x88218928 */
static __inline void sc2_i88218928_0(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
    W(s, 8) = (u32)0;
}
static __inline void sc2_i88218928_4(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88218928_5(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880EF318;
    W(s, 36) = (u32)0;
    W(s, 40) = (u32)0;
    W(s, 44) = (u32)0;
}
static __inline void sc2_i88218928_6(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
    W(s, 8) = (u32)0;
    W(s, 12) = (u32)0;
}
O *ts4_object_new_88218928(u32 *p)
{
    O *o;
    o = (O *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x40, 4, 0, 2);
    if (o != 0) {
        u32 a = *p;
    sc2_i88218928_0((O *)((char *)o + 0));
    B(o, 12) = (u8)0;
    W(o, 16) = (u32)a;
    W(o, 20) = (u32)lbl_88C6C900;
    sc2_i88218928_4((O *)((char *)o + 24));
    sc2_i88218928_5((O *)((char *)o + 0));
    sc2_i88218928_6((O *)((char *)o + 48));
    W(o, 32) = (u32)7;
    } else {
        o = 0;
    }
    return o;
}

/* Swing_DLL.xex 0x88218A00 */
static __inline void sc2_i88218A00_0(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
    W(s, 8) = (u32)0;
}
static __inline void sc2_i88218A00_4(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88218A00_5(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880EF2FC;
    W(s, 36) = (u32)0;
    W(s, 40) = (u32)0;
    W(s, 44) = (u32)0;
}
static __inline void sc2_i88218A00_6(O *s) {
    W(s, 16) = (u32)0;
    W(s, 20) = (u32)0;
    W(s, 24) = (u32)0;
    W(s, 0) = (u32)7;
}
O *ts4_object_new_88218A00(u32 *p)
{
    O *o;
    o = (O *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x3c, 4, 0, 2);
    if (o != 0) {
        u32 a = *p;
    sc2_i88218A00_0((O *)((char *)o + 0));
    B(o, 12) = (u8)0;
    W(o, 16) = (u32)a;
    W(o, 20) = (u32)lbl_88C6C904;
    sc2_i88218A00_4((O *)((char *)o + 24));
    sc2_i88218A00_5((O *)((char *)o + 0));
    sc2_i88218A00_6((O *)((char *)o + 32));
    } else {
        o = 0;
    }
    return o;
}

/* Swing_DLL.xex 0x88218AD0 */
static __inline void sc2_i88218AD0_0(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
    W(s, 8) = (u32)0;
}
static __inline void sc2_i88218AD0_4(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1u;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88218AD0_5(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880EF350;
    W(s, 32) = (u32)0;
    W(s, 52) = (u32)0;
    W(s, 40) = (u32)0;
}
static __inline void sc2_i88218AD0_6(O *s) {
    W(s, 8) = (u32)0;
    W(s, 12) = (u32)0;
    W(s, 0) = (u32)7;
}
O *ts4_object_new_88218AD0(u32 *p)
{
    O *o;
    o = (O *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x38, 4, 0, 2);
    if (o != 0) {
        u32 a = *p;
    sc2_i88218AD0_0((O *)((char *)o + 0));
    B(o, 12) = (u8)0;
    W(o, 16) = (u32)a;
    W(o, 20) = (u32)lbl_88C6C8F8;
    sc2_i88218AD0_4((O *)((char *)o + 24));
    sc2_i88218AD0_5((O *)((char *)o + 0));
    sc2_i88218AD0_6((O *)((char *)o + 36));
    } else {
        o = 0;
    }
    return o;
}

/* Swing_DLL.xex 0x888D03A0 */
static __inline void sc2_i888D03A0_1(O *s) {
    W(s, 0) = (u32)0;
    W(s, 8) = (u32)0;
    W(s, 4) = (u32)0xFFFFF;
}
static __inline void sc2_i888D03A0_3(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
O *ts4_object_ctor_888D03A0(O *o)
{
    fn_88617D88(o);
    W(o, 0) = (u32)(unsigned long)lbl_880DB904;
    sc2_i888D03A0_1((O *)((char *)o + 40));
    W(o, 52) = (u32)0;
    sc2_i888D03A0_3((O *)((char *)o + 56));
    lbl_88D45958 = o;

    W(o, 28) = (u32)-1;
    W(o, 32) = (u32)0;
    ts4_object_finalize((char *)o + 0x34);

    return o;
}
