/* Swing_DLL.xex 0x8848C7A8-0x8848E248, executable version 0.0.0.3. */
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
void *KeTlsGetValue(u32 index);
/* Appends a (tag, timebase) record to the thread-local trace buffer when it has room. */
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
typedef struct Vec { void **data; int count; } Vec;
typedef struct Vec16 { void **data; unsigned short count; } Vec16;
extern char lbl_88087568[];
extern char lbl_88087574[];
extern char lbl_88087580[];
extern char lbl_8808758C[];
extern char lbl_880875E0[];
extern char lbl_88087638[];
extern char lbl_88087644[];
extern char lbl_88087654[];
void fn_8848C218(void *v);
void fn_8848CB28(void *v);

#define EACH_BODY(V, CALLEE, LABEL, SLOT, CALL) \
    for (i = (V)->count - 1; i >= 0; i--) { \
        if ((V)->data[i] != 0) { \
            TRACE_EVENT(LABEL); \
            CALL; \
            TRACE_EVENT(lbl_8803BC50); \
        } \
    } \
    CALLEE(V);

#define VM(V, SLOT) (*(void ***)(V)->data[i])[(SLOT) / 4]

/* Records the owner in a result slot, then runs virtual method SLOT on each element of a 16-bit-counted pointer vector, traced. */
#define T2(NAME, OFF, OUTOFF, LABEL, SLOT, CALLEE) \
void NAME(char *self, char *out) \
{ \
    Vec16 *v; \
    int i; \
    *(char **)(out + (OUTOFF)) = self; \
    v = (Vec16 *)(self + (OFF)); \
    EACH_BODY(v, CALLEE, LABEL, SLOT, ((void (*)(void *, void *))VM(v, SLOT))(v->data[i], out)) \
}

/* Clears a result slot, then runs virtual method SLOT on each element of a pointer vector, traced. */
#define T3(NAME, OFF, OUTOFF, LABEL, SLOT, CALLEE) \
void NAME(char *self, char *out) \
{ \
    Vec *v; \
    int i; \
    *(int *)(out + (OUTOFF)) = 0; \
    v = (Vec *)(self + (OFF)); \
    EACH_BODY(v, CALLEE, LABEL, SLOT, ((void (*)(void *, void *))VM(v, SLOT))(v->data[i], out)) \
}

/* Runs virtual method SLOT with two forwarded arguments on each element of a pointer vector, traced. */
#define T4(NAME, OFF, LABEL, SLOT, CALLEE) \
void NAME(char *self, void *a, void *b) \
{ \
    Vec *v; \
    int i; \
    v = (Vec *)(self + (OFF)); \
    EACH_BODY(v, CALLEE, LABEL, SLOT, ((void (*)(void *, void *, void *))VM(v, SLOT))(v->data[i], a, b)) \
}

/* Same, forwarding the owner and one argument. */
#define T5(NAME, OFF, LABEL, SLOT, CALLEE) \
void NAME(char *self, void *a) \
{ \
    Vec *v; \
    int i; \
    v = (Vec *)(self + (OFF)); \
    EACH_BODY(v, CALLEE, LABEL, SLOT, ((void (*)(void *, void *, void *))VM(v, SLOT))(v->data[i], self, a)) \
}

T2(ts4_traced_t2_8848C7A8, 0x1f0, 0xc, lbl_88087568, 0x0, fn_8848C218)
T2(ts4_traced_t2_8848C888, 0x1f0, 0x8, lbl_88087574, 0x4, fn_8848C218)
T2(ts4_traced_t2_8848C968, 0x1f0, 0x10, lbl_88087580, 0x8, fn_8848C218)
T2(ts4_traced_t2_8848CA48, 0x1f0, 0x8, lbl_8808758C, 0xc, fn_8848C218)
T3(ts4_traced_t3_8848D488, 0x174, 0xc, lbl_88087568, 0x0, fn_8848CB28)
T3(ts4_traced_t3_8848D568, 0x174, 0x8, lbl_88087574, 0x4, fn_8848CB28)
T3(ts4_traced_t3_8848D648, 0x174, 0x10, lbl_88087580, 0x8, fn_8848CB28)
T3(ts4_traced_t3_8848D728, 0x174, 0x8, lbl_880875E0, 0xc, fn_8848CB28)
T4(ts4_traced_t4_8848DFA8, 0x15c, lbl_88087638, 0x4, fn_8848CB28)
T4(ts4_traced_t4_8848E088, 0x168, lbl_88087644, 0x4, fn_8848CB28)
T4(ts4_traced_t4_8848E168, 0x180, lbl_88087654, 0x4, fn_8848CB28)
T5(ts4_traced_t5_8848DDE8, 0x144, lbl_88087638, 0x4, fn_8848CB28)
T5(ts4_traced_t5_8848DEC8, 0x150, lbl_88087644, 0x4, fn_8848CB28)
