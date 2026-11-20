/* CW41 part c: camera / minigame / publisher small objects (0x888D8000-0x88900000). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#ifndef _MSC_VER
#define __forceinline inline
#endif
#define CX41_U32(p, o) (*(u32 *)((char *)(p) + (o)))
#define CX41_I32(p, o) (*(int *)((char *)(p) + (o)))
#define CX41_U8(p, o) (*(u8 *)((char *)(p) + (o)))
#define CX41_PTR(p, o) (*(char **)((char *)(p) + (o)))

extern char *lbl_88D45B1C;

typedef void (*Cx41Cb)(void);
extern Cx41Cb lbl_88D45854, lbl_88D45858, lbl_88D4585C, lbl_88D45860, lbl_88D45864, lbl_88D45868, lbl_88D45A88;
extern void ts4_addr_lbl_88D45CC0_888D8168(void);
extern void ts4_forward_888F7138(void);
extern void ts4_init_slot_888D8110(void);
extern void fn_888DBFC0(void);
extern void ts4_addr_lbl_88D45CC0_888F7140(void);
extern void ts4_addr_lbl_88D45CC0_888FB7C8(void);
extern void fn_8817C298(void);
extern void fn_888E7AE8(void);
extern u32 fn_8857B6D8(u32 a, u32 b, u32 c, u32 d);
extern u32 ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
extern void fn_888C74F0(void);
extern u32 ts4_loop_call_seq_fn_88563230_88884B20(void (*cb)(void), u32 a, char *s, u32 n);
extern char lbl_880D79F4[];
extern char lbl_88D45CC0[];
extern char *lbl_88D45B38;

/* 0x888FB838 */
void ts4_init_slot_callbacks_888FB838(void)
{
    char *base;
    lbl_88D45860 = ts4_addr_lbl_88D45CC0_888D8168;
    lbl_88D45854 = ts4_init_slot_888D8110;
    lbl_88D45858 = fn_888DBFC0;
    lbl_88D4585C = ts4_forward_888F7138;
    lbl_88D45864 = ts4_addr_lbl_88D45CC0_888F7140;
    lbl_88D45868 = ts4_addr_lbl_88D45CC0_888FB7C8;
    lbl_88D45A88 = ts4_addr_lbl_88D45CC0_888D8168;
    fn_8817C298();
    fn_888E7AE8();
    base = lbl_88D45CC0;
    CX41_U32(base, 0x684) = fn_8857B6D8(0, 0, 0, 0);
    CX41_U32(base, 0x680) = ts4_loop_call_seq_fn_88563230_88884B20(fn_888C74F0, ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38), lbl_880D79F4, 0x20000);
}
