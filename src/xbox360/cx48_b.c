/* CW48 part b: link-record style constructors (vtable lbl_880E4BA0 base, 0xDFA2AFF1 key), plain route. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Cx48Obj { char b[0x100]; } O;
#define W(o, off) (*(u32 *)((char *)(o) + (off)))
#define B(o, off) (*(u8 *)((char *)(o) + (off)))
extern char lbl_880E4BA0[];
extern char lbl_880EF334[], lbl_880EF59C[], lbl_880EF5B8[], lbl_880EF69C[], lbl_880EF648[], lbl_880EF680[], lbl_880EF52C[], lbl_880EF548[], lbl_880EF664[];
extern u32 lbl_88C6C914, lbl_88C6C8F0, lbl_88C6C8E8, lbl_88C6C93C, lbl_88C6C938, lbl_88C6C92C, lbl_88C6C90C, lbl_88C6C910, lbl_88C6C8EC;

static __inline void cx48_s0(O *s) { W(s, 4) = 0; W(s, 0) = (u32)(unsigned long)lbl_880E4BA0; }
static __inline void cx48_s2(O *s, u32 a) { B(s, 0) = 0; W(s, 4) = a; }
static __inline void cx48_s3(O *s) { W(s, 0) = 0xDFA2AFF1u; W(s, 4) = 0; }

#define CX48_CTOR(NAME, VT, G, TAIL) \
void NAME(O *o, u32 a) \
{ \
    cx48_s0((O *)((char *)o + 0)); \
    W(o, 8) = 0; \
    cx48_s2((O *)((char *)o + 12), a); \
    W(o, 0x14) = G; \
    cx48_s3((O *)((char *)o + 24)); \
    W(o, 0) = (u32)(unsigned long)VT; \
    TAIL; \
}
CX48_CTOR(ts4_link_ctor_8877A3A0, lbl_880EF334, lbl_88C6C914, (void)0)
CX48_CTOR(ts4_link_ctor_8877A4E0, lbl_880EF59C, lbl_88C6C8F0, (void)0)
CX48_CTOR(ts4_link_ctor_8877A5A8, lbl_880EF5B8, lbl_88C6C8E8, (void)0)
CX48_CTOR(ts4_link_ctor_8877A270, lbl_880EF69C, lbl_88C6C93C, W(o, 0x20) = 0)
CX48_CTOR(ts4_link_ctor_8877A2D0, lbl_880EF648, lbl_88C6C938, W(o, 0x20) = 0)
CX48_CTOR(ts4_link_ctor_8877A330, lbl_880EF680, lbl_88C6C92C, W(o, 0x20) = 0)
CX48_CTOR(ts4_link_ctor_8877A468, lbl_880EF52C, lbl_88C6C90C, W(o, 0x28) = 7)
CX48_CTOR(ts4_link_ctor_8877A400, lbl_880EF548, lbl_88C6C910, (W(o, 0x20) = 0, W(o, 0x28) = 7))
CX48_CTOR(ts4_link_ctor_8877A540, lbl_880EF664, lbl_88C6C8EC, (W(o, 0x20) = 0, W(o, 0x24) = 0, W(o, 0x28) = 0))

extern char lbl_880EF580[];
extern u32 lbl_88C6C8F4;
void ts4_link_ctor_8877E050(O *o)
{
    cx48_s0((O *)((char *)o + 0));
    W(o, 8) = 0;
    cx48_s2((O *)((char *)o + 12), 0);
    W(o, 0x14) = lbl_88C6C8F4;
    cx48_s3((O *)((char *)o + 24));
    W(o, 0) = (u32)(unsigned long)lbl_880EF580;
    W(o, 0x20) = 0;
    W(o, 0x24) = 0;
    W(o, 0x28) = 0;
    W(o, 0x2c) = 0;
}
