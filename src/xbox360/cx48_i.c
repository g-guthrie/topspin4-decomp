/* CW48 part i: constructors found by the SC2 grouping sweep, plain route. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Cx48Obj { char b[0x1000]; } O;
#define W(o, off) (*(u32 *)((char *)(o) + (off)))
#define B(o, off) (*(u8 *)((char *)(o) + (off)))
extern char lbl_880EFE08[];
extern void fn_88617D88(void *o);
extern char lbl_880EFD64[];
extern char lbl_880EFD8C[];
extern char lbl_880EFDE0[];
extern void fn_8816D1A8(void *p);

/* 0x88773B30 */
static __inline void sc2_i88773B30_1(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88773B30_3(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88773B30_5(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)40;
    W(s, 8) = (u32)40;
    W(s, 12) = (u32)100;
    W(s, 16) = (u32)0;
    W(s, 20) = (u32)0;
}
static __inline void sc2_i88773B30_6(O *s) {
    B(s, 0) = (u8)0;
    B(s, 1) = (u8)0;
    B(s, 2) = (u8)1;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88773B30_9(O *s) {
    W(s, 0) = (u32)0;
    W(s, 8) = (u32)0;
}
static __inline void sc2_i88773B30_10(O *s) {
    W(s, 0) = (u32)1048575;
    W(s, 12) = (u32)0;
    B(s, 16) = (u8)0;
}
O *ts4_object_ctor_88773B30(O *o)
{
    fn_88617D88(o);
    W(o, 0) = (u32)(u32)(unsigned long)lbl_880EFE08;
    sc2_i88773B30_1((O *)((char *)o + 28));
    W(o, 36) = (u32)0;
    sc2_i88773B30_3((O *)((char *)o + 40));
    W(o, 48) = (u32)0;
    sc2_i88773B30_5((O *)((char *)o + 52));
    sc2_i88773B30_6((O *)((char *)o + 76));
    W(o, 88) = (u32)0;
    W(o, 84) = (u32)1048575;
    sc2_i88773B30_9((O *)((char *)o + 92));
    sc2_i88773B30_10((O *)((char *)o + 96));
    return o;
}

/* 0x88772FD8 */
static __inline void sc2_i88772FD8_1(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88772FD8_3(O *s) {
    B(s, 0) = (u8)0;
    B(s, 1) = (u8)0;
}
static __inline void sc2_i88772FD8_5(O *s) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)3066451557;
}
static __inline void sc2_i88772FD8_10(O *s) {
    W(s, 0) = (u32)0;
    W(s, 8) = (u32)0;
    W(s, 4) = (u32)1048575;
}
O *ts4_object_ctor_88772FD8(O *o)
{
    W(o, 4) = (u32)0;
    sc2_i88772FD8_1((O *)((char *)o + 8));
    W(o, 16) = (u32)0;
    sc2_i88772FD8_3((O *)((char *)o + 20));
    W(o, 24) = (u32)0;
    sc2_i88772FD8_5((O *)((char *)o + 28));
    W(o, 0) = (u32)(u32)(unsigned long)lbl_880EFDE0;
    fn_8816D1A8((char *)o + 36);
    fn_8816D1A8((char *)o + 48);
    fn_8816D1A8((char *)o + 64);
    sc2_i88772FD8_10((O *)((char *)o + 76));
    W(o, 60) = (u32)0;
    return o;
}

/* 0x88773218 */
static __inline void sc2_i88773218_1(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88773218_3(O *s) {
    B(s, 0) = (u8)0;
    B(s, 1) = (u8)0;
}
static __inline void sc2_i88773218_5(O *s) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)3066451557;
}
static __inline void sc2_i88773218_8(O *s) {
    W(s, 0) = (u32)0;
    W(s, 8) = (u32)0;
}
static __inline void sc2_i88773218_9(O *s) {
    W(s, 8) = (u32)0;
    W(s, 0) = (u32)1048575;
}
static __inline void sc2_i88773218_10(O *s) {
    W(s, 4) = (u32)0;
    W(s, 0) = (u32)1048575;
}
static __inline void sc2_i88773218_11(O *s) {
    W(s, 0) = (u32)0;
    W(s, 8) = (u32)0;
    W(s, 4) = (u32)1048575;
}
static __inline void sc2_i88773218_12(O *s) {
    W(s, 0) = (u32)0;
    W(s, 8) = (u32)0;
}
static __inline void sc2_i88773218_15(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i88773218_16(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
O *ts4_object_ctor_88773218(O *o)
{
    W(o, 4) = (u32)0;
    sc2_i88773218_1((O *)((char *)o + 8));
    W(o, 16) = (u32)0;
    sc2_i88773218_3((O *)((char *)o + 20));
    W(o, 24) = (u32)0;
    sc2_i88773218_5((O *)((char *)o + 28));
    W(o, 0) = (u32)(u32)(unsigned long)lbl_880EFD8C;
    fn_8816D1A8((char *)o + 36);
    sc2_i88773218_8((O *)((char *)o + 48));
    sc2_i88773218_9((O *)((char *)o + 52));
    sc2_i88773218_10((O *)((char *)o + 64));
    sc2_i88773218_11((O *)((char *)o + 72));
    sc2_i88773218_12((O *)((char *)o + 84));
    W(o, 88) = (u32)1048575;
    W(o, 112) = (u32)0;
    sc2_i88773218_15((O *)((char *)o + 116));
    sc2_i88773218_16((O *)((char *)o + 124));
    W(o, 136) = (u32)0;
    W(o, 132) = (u32)1048575;
    return o;
}

/* 0x887732E8 */
static __inline void sc2_i887732E8_1(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void sc2_i887732E8_3(O *s) {
    B(s, 0) = (u8)0;
    B(s, 1) = (u8)0;
}
static __inline void sc2_i887732E8_5(O *s) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)3066451557;
}
static __inline void sc2_i887732E8_10(O *s) {
    W(s, 0) = (u32)0;
    W(s, 8) = (u32)0;
}
static __inline void sc2_i887732E8_12(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
    W(s, 8) = (u32)0;
}
O *ts4_object_ctor_887732E8(O *o)
{
    W(o, 4) = (u32)0;
    sc2_i887732E8_1((O *)((char *)o + 8));
    W(o, 16) = (u32)0;
    sc2_i887732E8_3((O *)((char *)o + 20));
    W(o, 24) = (u32)0;
    sc2_i887732E8_5((O *)((char *)o + 28));
    W(o, 0) = (u32)(u32)(unsigned long)lbl_880EFD64;
    fn_8816D1A8((char *)o + 36);
    fn_8816D1A8((char *)o + 48);
    fn_8816D1A8((char *)o + 60);
    sc2_i887732E8_10((O *)((char *)o + 72));
    W(o, 76) = (u32)1048575;
    sc2_i887732E8_12((O *)((char *)o + 84));
    return o;
}
