/* Loader_DLL.xex 0x8346E908-0x8346EB84, executable version 0.0.0.3. */
#ifdef _MSC_VER
unsigned int _CountLeadingZeros(unsigned int);
#pragma intrinsic(_CountLeadingZeros)
void __debugbreak(void);
#pragma intrinsic(__debugbreak)
#else
static unsigned int _CountLeadingZeros(unsigned int v) { unsigned n = 0; while (n < 32 && !(v & (0x80000000u >> n))) ++n; return n; }
static void __debugbreak(void) {}
#endif
typedef unsigned long ts4l_u32;
typedef struct ts4l_pixfmt {
    int kind;
    ts4l_u32 pad4;
    ts4l_u32 bits;
    char pad0c[0x10];
    ts4l_u32 mask[4];
    ts4l_u32 shift[4];
} ts4l_pixfmt;
extern void fn_8346D990(void);
extern void fn_8346D910(void);
extern void fn_8346D870(void);
extern void fn_8346D7F0(void);
extern void fn_8346D7A0(void);
extern void fn_8346E6A0(void);
extern void fn_8346E620(void);
extern void fn_8346E588(void);
extern void fn_8346E508(void);
extern void fn_8346E4C0(void);

#define CH(i) (_CountLeadingZeros(f->mask[i] >> f->shift[i]) == 16)
typedef void (*ts4l_blit_fn)(void);

ts4l_blit_fn ts4l_select_blit_8346E908(ts4l_pixfmt *f)
{
    switch (f->bits) {
    case 8:
        return fn_8346D7A0;
    case 16:
        if (f->kind == 1 && (CH(0) || CH(1) || CH(2) || CH(3))) return fn_8346D870;
        return fn_8346D7F0;
    case 32:
        if (f->kind == 1 && (CH(0) || CH(1) || CH(2) || CH(3))) return fn_8346D990;
        return fn_8346D910;
    default:
        __debugbreak();
        return 0;
    }
}

ts4l_blit_fn ts4l_select_blit_8346EA48(ts4l_pixfmt *f)
{
    switch (f->bits) {
    case 8:
        return fn_8346E4C0;
    case 16:
        if (f->kind == 1 && (CH(0) || CH(1) || CH(2) || CH(3))) return fn_8346E588;
        return fn_8346E508;
    case 32:
        if (f->kind == 1 && (CH(0) || CH(1) || CH(2) || CH(3))) return fn_8346E6A0;
        return fn_8346E620;
    default:
        __debugbreak();
        return 0;
    }
}
