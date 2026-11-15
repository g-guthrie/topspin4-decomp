/* CW41 part d (built with /Oc): camera / minigame / publisher small objects (0x888D8000-0x88900000). */
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
extern void ts4_if_call_seq_u32_off1c_888F1930(void *self, u32 v);
extern void ts4_if_addr_lbl_88D4BD24_888C61C0(void *self, u32 v);

/* 0x888F6390 */
void ts4_advance_selection_888F6390(char *self)
{
    char *p = CX41_PTR(self, 0x1c);
    if (p != 0 && CX41_U32(CX41_PTR(self, 0x60), 0x26c) == 0x39A2A9F0u && CX41_U8(CX41_PTR(self, 0x20), 0x54) == 0) {
        u32 n = (u32)((CX41_PTR(p, 0x88) - CX41_PTR(p, 0x84)) / 0x84);
        if (n != 0) {
            CX41_U32(CX41_PTR(self, 0x60), 0x268) = CX41_U32(CX41_PTR(self, 0x60), 0x268) + 1;
            if (CX41_U32(CX41_PTR(self, 0x60), 0x268) >= n) CX41_U32(CX41_PTR(self, 0x60), 0x268) = 0;
        }
        ts4_if_call_seq_u32_off1c_888F1930(self, CX41_U32(CX41_PTR(self, 0x60), 0x268));
    }
    CX41_U8(CX41_PTR(self, 0x60), 0x38) = 1;
    ts4_if_addr_lbl_88D4BD24_888C61C0(self, 0);
}
