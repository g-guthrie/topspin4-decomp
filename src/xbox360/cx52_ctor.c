/* SC2: constructors and inline-constructor factories whose store order and constant materialisation order were
   matched with the SC1 store-scheduling rule: each run of stores is split into sub-objects, each initialised by its
   own `static __inline` helper called on `(char *)o + K` (accesses through different pointer values keep source
   order, accesses through `o` are scheduled freely). The grouping per function was found by sweeping partitions of
   the target's store sequence (work/cx52/gen2.py). Plain route, no flags. */
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
extern char lbl_880E4CE8[];
extern u32 lbl_88C6C204;
extern char lbl_880E3F20[];

/* Swing_DLL.xex 0x887E9600 */
static __inline void cx52_i887E9600_0(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880E4BA0;
    W(s, 4) = (u32)0;
    W(s, 8) = (u32)0;
}
static __inline void cx52_i887E9600_1(O *s, u32 b) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)b;
}
static __inline void cx52_i887E9600_2(O *s, u32 *a) {
    W(s, 0) = (u32)*a;
    W(s, 4) = (u32)0xDFA2AFF1;
}
void ts4_object_ctor_887E9600(O *o, u32 *a, u32 b)
{
    cx52_i887E9600_0((O *)((char *)o + 0));
    cx52_i887E9600_1((O *)((char *)o + 12), b);
    cx52_i887E9600_2((O *)((char *)o + 20), a);
    W(o, 28) = (u32)0;
}

/* Swing_DLL.xex 0x887EA150 */
static __inline void cx52_i887EA150_3(O *s, u32 b) {
    B(s, 0) = (u8)0;
    W(s, 4) = (u32)b;
    W(s, 8) = (u32)lbl_88C6C204;
}
static __inline void cx52_i887EA150_4(O *s) {
    W(s, 0) = (u32)0xDFA2AFF1;
    W(s, 4) = (u32)0;
}
void ts4_object_ctor_887EA150(O *o, u32 b)
{
    W(o, 0) = (u32)(unsigned long)lbl_880E4BA0;
    W(o, 4) = (u32)0;
    W(o, 8) = (u32)0;
    cx52_i887EA150_3((O *)((char *)o + 12), b);
    cx52_i887EA150_4((O *)((char *)o + 24));
    W(o, 0) = (u32)(unsigned long)lbl_880E4CE8;
}

/* Swing_DLL.xex 0x887FC040 */
static __inline void cx52_i887FC040_0(O *s) {
    W(s, 0) = (u32)0;
    W(s, 12) = (u32)0;
}
static __inline void cx52_i887FC040_2(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
static __inline void cx52_i887FC040_3(O *s) {
    W(s, 0) = (u32)(unsigned long)lbl_880E3F20;
    W(s, 32) = (u32)0;
}
static __inline void cx52_i887FC040_7(O *s) {
    W(s, 0) = (u32)0;
    W(s, 8) = (u32)0;
}
static __inline void cx52_i887FC040_8(O *s) {
    W(s, 12) = (u32)0xFFFFF;
    W(s, 0) = (u32)0;
}
static __inline void cx52_i887FC040_9(O *s) {
    W(s, 0) = (u32)0;
    W(s, 4) = (u32)0;
}
void ts4_object_ctor_887FC040(O *o)
{
    cx52_i887FC040_0((O *)((char *)o + 4));
    W(o, 20) = (u32)0;
    cx52_i887FC040_2((O *)((char *)o + 24));
    cx52_i887FC040_3((O *)((char *)o + 0));
    W(o, 36) = (u32)0;
    W(o, 8) = (u32)-1;
    W(o, 12) = (u32)-1;
    cx52_i887FC040_7((O *)((char *)o + 52));
    cx52_i887FC040_8((O *)((char *)o + 44));
    cx52_i887FC040_9((O *)((char *)o + 64));
}
