/* CX26 LTCG part a: game core 0x881732E0-0x8818C6C0. Verified on the LTCG route only. */
typedef unsigned int u32;
typedef unsigned char u8;

extern u32 lbl_88D3E3A8;
extern void fn_88195368(void);
extern void *ts4_if_get_u32_lbl_88D3E3A4_88195D00(void *a, void *b, u32 c, u32 d);
typedef struct Cx26B { u8 pad[8]; u32 f8; u8 pad2[0x20]; u32 f2c; } Cx26B;

/* 0x8818AF00: clear +8, make sure the global is initialised, then forward through the getter */
void *ts4_get_u32_8818AF00(void *self, Cx26B *b, u32 c, u32 d)
{
    b->f8 = 0;
    if (lbl_88D3E3A8 == 0) fn_88195368();
    ts4_if_get_u32_lbl_88D3E3A4_88195D00(self, &b->f2c, c, d);
    return self;
}
