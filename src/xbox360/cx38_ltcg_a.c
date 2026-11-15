/* CW38 ltcg part a: callers of ts4_format_text in 0x887CC000-0x887CD000. LTCG route, context cw1_ctx_format_text.c. */
typedef unsigned int u32;
typedef unsigned char u8;

extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned);
#pragma function(memcpy)
#else
#include <string.h>
#endif
extern void fn_887CC988(void *, char *, int);
extern char lbl_880EA29C[];

void ts4_format_copy_887CCA38(char *self, u32 *a, int n)
{
    char buf[0x200];
    ts4_format_text(buf, 0x200, lbl_880EA29C, a[0], n);
    memcpy(self + 0x228, a, 0x134);
    fn_887CC988(self, buf, n);
}
