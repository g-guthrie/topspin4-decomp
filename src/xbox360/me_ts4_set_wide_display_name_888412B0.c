/* Swing_DLL.xex 0x888412B0: join the two name fields, widen, and store up to 64 wide characters
 * bounded copy as do/break/while; strlen intrinsic converted to int for the strncat room */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
void *memcpy(void *d, const void *s, unsigned int n);

typedef struct WideStr {
    u16 *first;
    u16 *last;
    u16 *end;
} WideStr;

typedef struct NameSource {
    u8 pad00[0x20];
    char first[0x40];  /* +0x20 */
    char last[0x40];   /* +0x60 */
} NameSource;

typedef struct NameTarget {
    u8 pad000[0xA04];
    u16 display[0x40]; /* +0xA04 */
} NameTarget;

extern char *ts4_crt_strncat_88564EF0(char *dst, const char *src, u32 n);
extern void fn_88608150(const char *src, u16 *dst, int count);
extern void fn_881AB4F0(WideStr *s, const u16 *text);
extern void *ts4_memset(void *d, int c, u32 n);
extern void ts4_destroy_owned_object(void *p);

void fn_888412B0(NameSource *src, NameTarget *dst)
{
    char name[0x40];
    u16 wide[0x40];
    WideStr str;
    const char *s = src->first;
    char *d = name;
    u32 len;

    do {
        if (*s == 0)
            break;
        *d++ = *s++;
    } while (d != name + 0x3F);
    *d = 0;
    ts4_crt_strncat_88564EF0(name, src->last, 0x3F - (int)strlen(name));
    fn_88608150(name, wide, 0x40);
    fn_881AB4F0(&str, wide);
    ts4_memset(dst->display, 0, 0x80);
    len = str.last - str.first;
    if (len < 0x40)
        memcpy(dst->display, wide, len * 2);
    ts4_destroy_owned_object(str.first);
}
