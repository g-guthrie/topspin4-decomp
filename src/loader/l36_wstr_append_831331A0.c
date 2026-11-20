/* Loader_DLL.xex 0x831331A0-0x83133230, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
struct WStr { u16 *buf; u32 cap; u32 len; };

extern void *fn_833E3AD0(void *d, const void *s, u32 n);
extern int fn_8311E828(struct WStr *s, u32 need);

int ts4l_wstr_append_831331A0(struct WStr *s, const u16 *src, u32 n)
{
    u32 len = s->len;
    u32 newlen = len + n;
    u32 need = newlen + 1;
    if (need > len && need > n && need < 0x7fffffff && fn_8311E828(s, need) >= 0) {
        fn_833E3AD0(s->buf + len, src, n * 2);
        s->len = newlen;
        s->buf[newlen] = 0;
        return 1;
    }
    return 0;
}
