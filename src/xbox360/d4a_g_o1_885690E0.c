/* Swing_DLL.xex 0x885690E0-0x88569184, executable version 0.0.0.3. */
/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
typedef unsigned int ts4_u32;
#ifdef _MSC_VER
unsigned __int64 __mftb(void);
#pragma intrinsic(__mftb)
#else
static inline __attribute__((unused)) unsigned long long __mftb(void) { return 0; }
#endif
typedef struct ts4_Rec { ts4_u32 tag; ts4_u32 stamp; ts4_u32 pad; ts4_u32 tag2; } ts4_Rec;
typedef struct ts4_Rec12 { ts4_u32 tag; ts4_u32 stamp; ts4_u32 pad; } ts4_Rec12;
typedef struct ts4_TlsBuf { ts4_u32 pad0; void *cur; ts4_u32 pad1; void *end; } ts4_TlsBuf;
extern ts4_u32 lbl_88CAD338;
ts4_word KeTlsGetValue();
#define ts4_trace1(T) do { ts4_TlsBuf *tb_ = (ts4_TlsBuf *)KeTlsGetValue(lbl_88CAD338); \
    if ((ts4_Rec12 *)tb_->cur < (ts4_Rec12 *)tb_->end) { ts4_Rec12 *rc_ = (ts4_Rec12 *)tb_->cur; \
        rc_->tag = (ts4_u32)(T); rc_->stamp = (ts4_u32)__mftb(); tb_->cur = rc_ + 1; } } while (0)
#define ts4_trace2(T, U) do { ts4_TlsBuf *tb_ = (ts4_TlsBuf *)KeTlsGetValue(lbl_88CAD338); \
    if ((ts4_Rec *)tb_->cur < (ts4_Rec *)tb_->end) { ts4_Rec *rc_ = (ts4_Rec *)tb_->cur; \
        rc_->tag = (ts4_u32)(T); rc_->tag2 = (ts4_u32)(U); rc_->stamp = (ts4_u32)__mftb(); tb_->cur = rc_ + 1; } } while (0)

ts4_word fn_88565258();
ts4_word fn_8856D2C0();
ts4_word ts4_if_call_seq_fn_8856CD88_88567ED8();

/* Swing_DLL.xex 0x885690E0: if_call_seq fn_88565258, u32@-0x4, ts4_if_call_seq_fn_8856CD88_88567ED8, u32@0x0, ts4_if_call_seq_fn_8856CD88_88567ED8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88565258_885690E0(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word p6;
    ts4_word p8;
    ts4_word p12;
    ts4_word t1;
    ts4_word t10;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t5;

    t1 = (a1 + -1);
    if ((int)(t1 & a1) != 0) {
        t10 = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *(ts4_word *)((char *)(ts4_word)(t10) + 0) = (ts4_word)22;
        fn_8856D2C0((ts4_word)t10);
        p12 = (ts4_word)0;
    } else {
        p2 = (ts4_word)a1;
        if ((ts4_word)a1 <= 4) {
            p2 = (ts4_word)4;
        }
        t3 = (p2 + -1);
        t4 = (t3 + 4);
        if ((ts4_word)a0 > (ts4_word)(t4 + a0)) {
            t7 = ts4_if_call_seq_fn_8856CD88_88567ED8();
            *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)12;
            p8 = (ts4_word)0;
        } else {
            t5 = fn_88565258((ts4_word)(t4 + a0), (ts4_word)p2);
            if ((ts4_word)t5 == 0) {
                p6 = (ts4_word)0;
            } else {
                *(ts4_word *)((char *)(ts4_word)(((t5 + t4) & ~t3)) + -4) = (ts4_word)t5;
                p6 = (ts4_word)((t5 + t4) & ~t3);
            }
            p8 = (ts4_word)p6;
        }
        p12 = (ts4_word)p8;
    }
    return p12;
}
