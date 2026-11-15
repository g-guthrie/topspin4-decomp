/* CX46 LTCG part a: Pam Display renderer, callers of ts4_format_text (context cw1_ctx_format_text.c). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct S12 { u32 a, b, c; } S12;
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern void ts4_if_set_u32_off0_8862BE08(void *out, void *in);
extern char lbl_880F1858[], lbl_880F173C[], lbl_880F1730[], lbl_880F1724[];
/* 0x88723D60: build the eight formatted name records at +0x10c from the four-by-two name templates */
void ts4_build_name_table_88723D60(char *self)
{
    u8 i;
    u8 j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            char a[0x20];
            char b[0xff];
            S12 t;
            ts4_format_text(a, 0x20, lbl_880F173C, i, j == 0 ? lbl_880F1724 : lbl_880F1730);
            ts4_format_text(b, 0xff, lbl_880F1858, a);
            ts4_if_set_u32_off0_8862BE08(&t, b);
            *(S12 *)(self + 0x10c + (i * 2 + j) * 12) = t;
        }
    }
}
