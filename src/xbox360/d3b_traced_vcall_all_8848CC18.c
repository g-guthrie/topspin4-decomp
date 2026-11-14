/* Swing_DLL.xex 0x8848CC18-0x8848E2E0, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
unsigned __int64 __mftb(void);
#pragma intrinsic(__mftb)
#else
static inline unsigned long long __mftb(void) { return 0; }
#endif
typedef struct Rec { u32 tag; u32 stamp; u32 pad; } Rec;
typedef struct TlsBuf { u32 pad0; Rec *cur; u32 pad1; Rec *end; } TlsBuf;
typedef struct Vec { void **data; int count; } Vec;
extern u32 lbl_88CAD338;
extern char lbl_8803BC50[];
extern char lbl_88087534[];
extern char lbl_88087540[];
extern char lbl_8808754C[];
extern char lbl_88087598[];
extern char lbl_880875A4[];
extern char lbl_880875B0[];
extern char lbl_880875BC[];
extern char lbl_880875C8[];
extern char lbl_880875D4[];
extern char lbl_88087664[];
void *KeTlsGetValue(u32 index);
void fn_8848CB28(Vec *v);

/* Calls virtual method SLOT on every non-null element of a pointer vector (last to first),
   bracketing each call with a begin/end timestamp record in the thread-local trace buffer. */
#define TRACE_EVENT(TAG) \
    do { \
        TlsBuf *t = (TlsBuf *)KeTlsGetValue(lbl_88CAD338); \
        if (t->cur < t->end) { \
            Rec *r = t->cur; \
            r->tag = (u32)(unsigned long)(TAG); \
            r->stamp = (u32)__mftb(); \
            t->cur = r + 1; \
        } \
    } while (0)

#define TRACED_VCALL_ALL(NAME, OFF, LABEL, SLOT) \
void NAME(char *self, void *arg) \
{ \
    Vec *v = (Vec *)(self + (OFF)); \
    int i; \
    for (i = v->count - 1; i >= 0; i--) { \
        if (v->data[i] != 0) { \
            TRACE_EVENT(LABEL); \
            ((void (*)(void *, void *))(*(void ***)v->data[i])[(SLOT) / 4])(v->data[i], arg); \
            TRACE_EVENT(lbl_8803BC50); \
        } \
    } \
    fn_8848CB28(v); \
}

TRACED_VCALL_ALL(ts4_traced_vcall_all_8848CC18, 0xf0, lbl_88087598, 0x4)
TRACED_VCALL_ALL(ts4_traced_vcall_all_8848CCF0, 0xf0, lbl_880875A4, 0x8)
TRACED_VCALL_ALL(ts4_traced_vcall_all_8848CDC8, 0xfc, lbl_88087534, 0x4)
TRACED_VCALL_ALL(ts4_traced_vcall_all_8848CEA0, 0xfc, lbl_88087540, 0x8)
TRACED_VCALL_ALL(ts4_traced_vcall_all_8848CF78, 0xfc, lbl_8808754C, 0xc)
TRACED_VCALL_ALL(ts4_traced_vcall_all_8848D050, 0x108, lbl_880875B0, 0x4)
TRACED_VCALL_ALL(ts4_traced_vcall_all_8848D128, 0x108, lbl_880875BC, 0x8)
TRACED_VCALL_ALL(ts4_traced_vcall_all_8848D200, 0x108, lbl_8808754C, 0xc)
TRACED_VCALL_ALL(ts4_traced_vcall_all_8848D2D8, 0x114, lbl_880875C8, 0x4)
TRACED_VCALL_ALL(ts4_traced_vcall_all_8848D3B0, 0x114, lbl_880875D4, 0x8)
TRACED_VCALL_ALL(ts4_traced_vcall_all_8848E248, 0x138, lbl_88087664, 0x8)
