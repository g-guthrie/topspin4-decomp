/* CW32 LTCG-route helper (caller of ts4_format_text). */
typedef unsigned int u32;

extern char lbl_880DEF5C[];
void *ts4_memset(void *p, int c, u32 n);
int ts4_format_text(char *dst, u32 size, const char *fmt, ...);

/* 0x888852B0 */
void ts4_format_text_slot_888852B0(char *t, int a, char *buf)
{
    ts4_memset(buf, 0, 0x200);
    ts4_format_text(buf, 0x1FF, lbl_880DEF5C, t + 0x4D, a);
}
