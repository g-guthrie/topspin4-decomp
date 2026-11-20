/* SC2: factory family at 0x88166F58-0x88167DB8. Each allocates a zeroed object from the global heap through
   ts4_node_dispatch_with_target_88613268 and inlines its constructor: +0 vtable, +4 zero, +8/+0xC = -1, the
   0x3C-ish word = 0xFFFFF, the rest zero. The store order and the `lis` order of the target are reproduced by
   splitting the words into sub-objects, each with its own `static __inline` init called on `(char *)o + K`
   (the SC1 store-scheduling rule: accesses through different pointer values keep source order). */
typedef unsigned int u32;
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
typedef struct Sc2Obj { char b[0x58]; } Sc2Obj;
#define SC2_W(o, off) (*(u32 *)((char *)(o) + (off)))
extern char lbl_880D51F8[];
extern char lbl_880D5240[];
extern char lbl_880D5288[];
extern char lbl_880D52C8[];
extern char lbl_880D5308[];
extern char lbl_880D5348[];
extern char lbl_880D5388[];
extern char lbl_880D53C8[];
extern char lbl_880D54B0[];

/* Swing_DLL.xex 0x88167258 */

static __inline void sc2_init_88167258_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167258_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167258_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88167258_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88167258_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_88167258(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x4C, 4, 0, 2);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88167258_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88167258_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88167258_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88167258_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D5288;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_88167258_10((Sc2Obj *)((char *)o + 0x44));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167310 */

static __inline void sc2_init_88167310_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167310_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167310_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88167310_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88167310_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_88167310(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x4C, 4, 0, 0);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88167310_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88167310_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88167310_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88167310_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D5288;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_88167310_10((Sc2Obj *)((char *)o + 0x44));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x881673C8 */

static __inline void sc2_init_881673C8_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_881673C8_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_881673C8_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_881673C8_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_881673C8_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_881673C8(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x4C, 4, 0, 2);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_881673C8_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_881673C8_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_881673C8_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_881673C8_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D52C8;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_881673C8_10((Sc2Obj *)((char *)o + 0x44));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167480 */

static __inline void sc2_init_88167480_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167480_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167480_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88167480_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88167480_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_88167480(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x4C, 4, 0, 0);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88167480_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88167480_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88167480_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88167480_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D52C8;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_88167480_10((Sc2Obj *)((char *)o + 0x44));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167538 */

static __inline void sc2_init_88167538_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167538_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167538_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88167538_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88167538_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_88167538(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x50, 4, 0, 2);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88167538_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88167538_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88167538_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88167538_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D5308;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_88167538_10((Sc2Obj *)((char *)o + 0x44));
        SC2_W(o, 0x4C) = (u32)0;
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x881675F0 */

static __inline void sc2_init_881675F0_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_881675F0_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_881675F0_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_881675F0_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_881675F0_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_881675F0(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x50, 4, 0, 0);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_881675F0_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_881675F0_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_881675F0_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_881675F0_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D5308;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_881675F0_10((Sc2Obj *)((char *)o + 0x44));
        SC2_W(o, 0x4C) = (u32)0;
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x881676A8 */

static __inline void sc2_init_881676A8_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_881676A8_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_881676A8_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_881676A8_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_881676A8_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_881676A8(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x4C, 4, 0, 2);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_881676A8_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_881676A8_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_881676A8_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_881676A8_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D5348;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_881676A8_10((Sc2Obj *)((char *)o + 0x44));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167760 */

static __inline void sc2_init_88167760_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167760_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167760_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88167760_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88167760_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_88167760(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x4C, 4, 0, 0);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88167760_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88167760_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88167760_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88167760_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D5348;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_88167760_10((Sc2Obj *)((char *)o + 0x44));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167818 */

static __inline void sc2_init_88167818_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167818_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167818_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88167818_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88167818_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_88167818(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x50, 4, 0, 2);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88167818_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88167818_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88167818_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88167818_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D5388;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_88167818_10((Sc2Obj *)((char *)o + 0x44));
        SC2_W(o, 0x4C) = (u32)0;
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x881678D0 */

static __inline void sc2_init_881678D0_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_881678D0_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_881678D0_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_881678D0_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_881678D0_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_881678D0(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x50, 4, 0, 0);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_881678D0_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_881678D0_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_881678D0_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_881678D0_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D5388;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_881678D0_10((Sc2Obj *)((char *)o + 0x44));
        SC2_W(o, 0x4C) = (u32)0;
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167988 */

static __inline void sc2_init_88167988_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167988_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167988_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88167988_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88167988_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_88167988(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x4C, 4, 0, 2);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88167988_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88167988_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88167988_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88167988_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D53C8;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_88167988_10((Sc2Obj *)((char *)o + 0x44));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167A40 */

static __inline void sc2_init_88167A40_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167A40_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167A40_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88167A40_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88167A40_10(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

void *ts4_factory_obj_new_88167A40(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x4C, 4, 0, 0);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88167A40_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88167A40_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88167A40_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88167A40_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x0) = (u32)(unsigned long)lbl_880D53C8;
        SC2_W(o, 0x30) = (u32)0;
        SC2_W(o, 0x34) = (u32)0;
        SC2_W(o, 0x2C) = (u32)0;
        sc2_init_88167A40_10((Sc2Obj *)((char *)o + 0x44));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88166F58 */

static __inline void sc2_init_88166F58_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88166F58_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88166F58_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88166F58_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88166F58_6(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88166F58_7(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x20) = (u32)0;
    SC2_W(s, 0x24) = (u32)0;
}

static __inline void sc2_init_88166F58_8(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)(unsigned long)lbl_880D5240;
    SC2_W(s, 0x44) = (u32)0;
    SC2_W(s, 0x54) = (u32)0;
}

void *ts4_factory_obj_new_88166F58(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x58, 4, 0, 2);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88166F58_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88166F58_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88166F58_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88166F58_5((Sc2Obj *)((char *)o + 0xC));
        sc2_init_88166F58_6((Sc2Obj *)((char *)o + 0x30));
        sc2_init_88166F58_7((Sc2Obj *)((char *)o + 0x2C));
        sc2_init_88166F58_8((Sc2Obj *)((char *)o + 0x0));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167018 */

static __inline void sc2_init_88167018_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167018_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167018_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88167018_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88167018_6(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167018_7(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x20) = (u32)0;
    SC2_W(s, 0x24) = (u32)0;
}

static __inline void sc2_init_88167018_8(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)(unsigned long)lbl_880D5240;
    SC2_W(s, 0x44) = (u32)0;
    SC2_W(s, 0x54) = (u32)0;
}

void *ts4_factory_obj_new_88167018(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x58, 4, 0, 0);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88167018_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88167018_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88167018_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88167018_5((Sc2Obj *)((char *)o + 0xC));
        sc2_init_88167018_6((Sc2Obj *)((char *)o + 0x30));
        sc2_init_88167018_7((Sc2Obj *)((char *)o + 0x2C));
        sc2_init_88167018_8((Sc2Obj *)((char *)o + 0x0));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x881670D8 */

static __inline void sc2_init_881670D8_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_881670D8_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_881670D8_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_881670D8_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_881670D8_6(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)(unsigned long)lbl_880D51F8;
    SC2_W(s, 0x30) = (u32)0;
}

static __inline void sc2_init_881670D8_7(Sc2Obj *s)
{
    SC2_W(s, 0x8) = (u32)0;
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x20) = (u32)0;
}

static __inline void sc2_init_881670D8_8(Sc2Obj *s)
{
    SC2_W(s, 0xC) = (u32)0;
    SC2_W(s, 0x0) = (u32)0;
}

void *ts4_factory_obj_new_881670D8(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x54, 4, 0, 2);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_881670D8_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_881670D8_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_881670D8_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_881670D8_5((Sc2Obj *)((char *)o + 0xC));
        sc2_init_881670D8_6((Sc2Obj *)((char *)o + 0x0));
        sc2_init_881670D8_7((Sc2Obj *)((char *)o + 0x2C));
        sc2_init_881670D8_8((Sc2Obj *)((char *)o + 0x44));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167198 */

static __inline void sc2_init_88167198_1(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167198_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167198_4(Sc2Obj *s)
{
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x0) = (u32)-1;
}

static __inline void sc2_init_88167198_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x2C) = (u32)0;
    SC2_W(s, 0x34) = (u32)0;
    SC2_W(s, 0x30) = (u32)0xFFFFF;
}

static __inline void sc2_init_88167198_6(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)(unsigned long)lbl_880D51F8;
    SC2_W(s, 0x30) = (u32)0;
}

static __inline void sc2_init_88167198_7(Sc2Obj *s)
{
    SC2_W(s, 0x8) = (u32)0;
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x1C) = (u32)0;
    SC2_W(s, 0x20) = (u32)0;
}

static __inline void sc2_init_88167198_8(Sc2Obj *s)
{
    SC2_W(s, 0xC) = (u32)0;
    SC2_W(s, 0x0) = (u32)0;
}

void *ts4_factory_obj_new_88167198(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x54, 4, 0, 0);
    if (o != 0) {
        SC2_W(o, 0x4) = (u32)0;
        sc2_init_88167198_1((Sc2Obj *)((char *)o + 0x10));
        sc2_init_88167198_2((Sc2Obj *)((char *)o + 0x18));
        SC2_W(o, 0x20) = (u32)0;
        sc2_init_88167198_4((Sc2Obj *)((char *)o + 0x8));
        sc2_init_88167198_5((Sc2Obj *)((char *)o + 0xC));
        sc2_init_88167198_6((Sc2Obj *)((char *)o + 0x0));
        sc2_init_88167198_7((Sc2Obj *)((char *)o + 0x2C));
        sc2_init_88167198_8((Sc2Obj *)((char *)o + 0x44));
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167D08 */

static __inline void sc2_init_88167D08_0(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0xC) = (u32)0;
}

static __inline void sc2_init_88167D08_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167D08_3(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)(unsigned long)lbl_880D54B0;
    SC2_W(s, 0x20) = (u32)0;
    SC2_W(s, 0x24) = (u32)0;
}

static __inline void sc2_init_88167D08_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x40) = (u32)0;
    SC2_W(s, 0x48) = (u32)0;
}

static __inline void sc2_init_88167D08_7(Sc2Obj *s)
{
    SC2_W(s, 0x4) = (u32)0;
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x8) = (u32)0;
}

void *ts4_factory_obj_new_88167D08(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x58, 4, 0, 2);
    if (o != 0) {
        sc2_init_88167D08_0((Sc2Obj *)((char *)o + 0x4));
        SC2_W(o, 0x14) = (u32)0;
        sc2_init_88167D08_2((Sc2Obj *)((char *)o + 0x18));
        sc2_init_88167D08_3((Sc2Obj *)((char *)o + 0x0));
        SC2_W(o, 0x8) = (u32)-1;
        sc2_init_88167D08_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x50) = (u32)0xFFFFF;
        sc2_init_88167D08_7((Sc2Obj *)((char *)o + 0x2C));
        SC2_W(o, 0x38) = (u32)0;
        return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167DB8 */

static __inline void sc2_init_88167DB8_0(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0xC) = (u32)0;
}

static __inline void sc2_init_88167DB8_2(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x4) = (u32)0;
}

static __inline void sc2_init_88167DB8_3(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)(unsigned long)lbl_880D54B0;
    SC2_W(s, 0x20) = (u32)0;
    SC2_W(s, 0x24) = (u32)0;
}

static __inline void sc2_init_88167DB8_5(Sc2Obj *s)
{
    SC2_W(s, 0x0) = (u32)-1;
    SC2_W(s, 0x40) = (u32)0;
    SC2_W(s, 0x48) = (u32)0;
}

static __inline void sc2_init_88167DB8_7(Sc2Obj *s)
{
    SC2_W(s, 0x4) = (u32)0;
    SC2_W(s, 0x0) = (u32)0;
    SC2_W(s, 0x8) = (u32)0;
}

void *ts4_factory_obj_new_88167DB8(void)
{
    Sc2Obj *o = (Sc2Obj *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x58, 4, 0, 0);
    if (o != 0) {
        sc2_init_88167DB8_0((Sc2Obj *)((char *)o + 0x4));
        SC2_W(o, 0x14) = (u32)0;
        sc2_init_88167DB8_2((Sc2Obj *)((char *)o + 0x18));
        sc2_init_88167DB8_3((Sc2Obj *)((char *)o + 0x0));
        SC2_W(o, 0x8) = (u32)-1;
        sc2_init_88167DB8_5((Sc2Obj *)((char *)o + 0xC));
        SC2_W(o, 0x50) = (u32)0xFFFFF;
        sc2_init_88167DB8_7((Sc2Obj *)((char *)o + 0x2C));
        SC2_W(o, 0x38) = (u32)0;
        return o;
    }
    return 0;
}
