/* Swing_DLL.xex 0x884AC698-0x884AC760, executable version 0.0.0.3. */
/* Trace-instrumented dispatch: records (tag, timebase) pairs in a thread-local trace buffer. */
typedef unsigned int u32;
#ifdef _MSC_VER
unsigned __int64 __mftb(void);
#pragma intrinsic(__mftb)
#else
static inline unsigned long long __mftb(void) { return 0; }
#endif
typedef struct Rec { u32 tag; u32 stamp; u32 pad; } Rec;
typedef struct TlsBuf { u32 pad0; Rec *cur; u32 pad1; Rec *end; } TlsBuf;
extern u32 lbl_88CAD338;
extern char lbl_8803BC50[];
extern char lbl_88088AEC[];
extern char lbl_880896B0[];
typedef struct Vec { void **data; int count; } Vec;
typedef Vec *(*FnV)(void *, void *);
void fn_884B9B20(void *base, void *item);
void *KeTlsGetValue(u32 index);
#ifdef _MSC_VER
static __forceinline
#else
static inline
#endif
void trace_event(const void *tag)
{
    TlsBuf *t = (TlsBuf *)KeTlsGetValue(lbl_88CAD338);
    if (t->cur < t->end) {
        Rec *r = t->cur;
        r->tag = (u32)(unsigned long)tag;
        r->stamp = (u32)__mftb();
        t->cur = r + 1;
    }
}
typedef void (*Fn3)(void *, void *, void *);
/* Swing_DLL.xex 0x884AC698 */
void ts4_traced_dispatch_884AC698(char *self, void *arg)
{
    char *base;
    trace_event(lbl_88088AEC);
    if (*(unsigned char *)(self + 0x34) == 0) {
        trace_event(lbl_8803BC50);
        return;
    }
    base = self - 0x2c;
    (*(Fn3 *)(*(char **)base + 0x10))(base, *(void **)(self - 0x14), arg);
    trace_event(lbl_8803BC50);
}
/* Swing_DLL.xex 0x884B9D88 */
void ts4_traced_each_884B9D88(char *self, void *arg)
{
    char *base;
    Vec *v;
    int i;
    trace_event(lbl_880896B0);
    base = self - 0x28;
    v = (*(FnV *)(*(char **)base + 0xc))(base, arg);
    for (i = 0; i < v->count; i++)
        fn_884B9B20(base, v->data[i]);
    trace_event(lbl_8803BC50);
}
