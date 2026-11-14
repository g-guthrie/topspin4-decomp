/* SM2: forwarding thunks, tiny predicates and fill helpers. */
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;

extern void fn_886DCFF8(void *a, void *b);
extern void fn_886CDB48(void *a, int b);
extern void fn_886CC560(void *a, int b, int c);
extern void fn_8852CB30(int a, int b, int c, int d);
extern void fn_8860DCF8(void *a, int b, int c, int d);
extern void fn_886DEDD8(void *a, int b, float x, float y);
extern void fn_886DFA60(float f, void *a, int b, int c, int d);
extern void fn_885459F8(void *a, void *b);
extern void fn_886CF1E0(void *a, int b, int c, int d);
extern void fn_8861E598(void *a, float x, float y);
extern void fn_885BDF38(int a, int b, int c, int d);
extern void fn_885651F8(void *a);
extern void fn_884E0220(void *a);
extern void fn_886E75E8(void *a);
extern void RtlLeaveCriticalSection(void *cs);
extern void fn_886CE120(void);
extern void *ts4_forward_88421460(void *a, int b, int c);
extern void fn_886D0EB0(void *a);
extern void fn_886DBF40(void *a, void *b, int c, int d, int e, int f);
extern char lbl_880F3794[];
extern unsigned lbl_88D45AF4;
extern void fn_88404660(int a, int b, void *c, int d, int e);
extern void fn_884047A0(int a, int b, void *c, int d, int e);
extern void fn_884CE440(int a, int b, void *c, int d, int e);
extern void ts4_if_call_seq_fn_8841E4A0_884CE798(int a, int b, void *c, int d, int e);
extern char lbl_88B3C430[];
extern char lbl_88D26F54[];

void ts4_call_with_two_fields_886E1840(char *p) { fn_886DCFF8(*(void **)(p + 0x154), *(void **)(p + 0x150)); }
void ts4_call_with_field28_zero_886D1DB8(char *p) { fn_886CDB48(*(void **)(p + 0x28), 0); }
void ts4_call_with_first_word_886CC678(int *p, int x) { fn_886CC560(p, *p, x); }
#define DROP_ARGS_FWD(NAME) \
    void NAME(int a, int b, int c, int d, int e) { fn_8852CB30(b, b, c, e); }
void ts4_call_with_fields_886E1828(char *p) { fn_886DEDD8(*(void **)(p + 0x154), *(int *)(p + 0x168), *(float *)(p + 0x174), *(float *)(p + 0x178)); }
void ts4_call_with_scaled_index_88546268(char *p, const int *idx) { fn_885459F8(p, *(char **)(p + 0xa0) + *idx * 16); }
void ts4_call_with_deref_and_offset_886CF500(char *p, int a, const int *b) { fn_886CF1E0(p, a, *b, *b + *(int *)(p + 4) * 4); }
void ts4_call_with_u16_fields_885A99F0(char *p, int b) { fn_885BDF38(*(unsigned short *)(p + 6), *(unsigned short *)(p + 4), b, 0); }
void ts4_call_with_header_word_885690C8(char *p) { if (p) fn_885651F8(((void **)((unsigned long)p & ~3ul))[-1]); }
#define CALL_IF_FIELD_NEG(NAME, OFF) \
    void NAME(char *p) { void *q = *(void **)(p - (OFF)); if (q) fn_884E0220(q); }
CALL_IF_FIELD_NEG(ts4_call_if_field_m50_884A23F8, 0x50)
CALL_IF_FIELD_NEG(ts4_call_if_field_m54_884A2438, 0x54)
CALL_IF_FIELD_NEG(ts4_call_if_field_m5c_884A2568, 0x5c)
void ts4_call_if_field1c_886E7780(char *p) { if (*(int *)(p + 0x1c) != 0) fn_886E75E8(p + 0x20); }
/* delete-style virtual call: slot 0 with flag 1 */
#define VDELETE(NAME) \
    void NAME(void **p) { if (p) ((void (*)(void *, int))(*(void ***)p)[0])(p, 1); }
VDELETE(ts4_virtual_delete_88466A38)
VDELETE(ts4_virtual_delete_8848C128)
VDELETE(ts4_virtual_delete_8860F008)
void ts4_leave_critical_section_8846AA70(char *p)
{
    char *q = *(char **)(p + 0xa8);
    if (q) {
        *(ts4_s64 *)(q + 0x20) = -1;
        RtlLeaveCriticalSection(q);
    }
}
void ts4_call_if_global_886D29F0(void) { if (lbl_88D45AF4) fn_886CE120(); }
void *ts4_forward_if_nonnull_88478620(int a, int b, void *c, int d) { void *r = c; (void)a; (void)b; if (r) r = ts4_forward_88421460(r, 0, d); return r; }
void ts4_set_vtable_call_886D48E0(char *p) { *(char **)p = lbl_880F3794; fn_886D0EB0(p + 0x30); }
void ts4_call_with_first_word_shift_886DC090(char *p, int b, int c, int d, int e) { fn_886DBF40(p, *(void **)p, c, b, d, e); }
#define LBL_ARG_FWD(NAME, LBL, CALLEE) \
    void NAME(int a, int b, int c, int d) { CALLEE(a, b, LBL, c, d); }
LBL_ARG_FWD(ts4_call_with_lbl_88404788, lbl_88B3C430, fn_88404660)
LBL_ARG_FWD(ts4_call_with_lbl_88404940, lbl_88B3C430, fn_884047A0)
LBL_ARG_FWD(ts4_call_with_lbl_884CE728, lbl_88D26F54, fn_884CE440)
LBL_ARG_FWD(ts4_call_with_lbl_884CE870, lbl_88D26F54, ts4_if_call_seq_fn_8841E4A0_884CE798)

void ts4_set_is_01_88411CF8(unsigned char *out, int v) { *out = (v == 0 || v == 1); }
void ts4_set_is_digit_88429010(unsigned char *out, int v) { *out = (v >= 0x30 && v <= 0x39); }
char ts4_to_lower_88421030(char c) { if (c >= 'A' && c <= 'Z') c += 0x20; return c; }
char ts4_to_upper_88421010(char c) { if (c >= 'a' && c <= 'z') c -= 0x20; return c; }
unsigned char ts4_in_range_884D18C0(int v, int lo, int hi) { return v >= lo && v < hi; }
void ts4_set_u32_less_88423198(unsigned char *out, const unsigned *a, const unsigned *b) { *out = *a < *b; }
void ts4_set_u32_less_88540440(unsigned char *out, const char *a, const char *b) { *out = *(const unsigned *)(a + 0xc0) < *(const unsigned *)(b + 0xc0); }
unsigned ts4_u32_greater_886EB260(const unsigned *a, const unsigned *b) { return *b < *a; }
void ts4_set_wrap_byte_8847FBC8(unsigned char *p) { p[0xa] = (unsigned char)(((p[8] + p[9] + 5) & 0x3f) << 2); }
float ts4_negate_if_id_886597A8(int unused, int id, float x) { (void)unused; if (id == (int)0xa2eda1e7) return -x; return x; }
unsigned ts4_div_add_88413598(const char *p, unsigned n) { return n / *(unsigned *)(p + 0x28) + *(unsigned *)(p + 0x58); }
unsigned ts4_div_add_8840B5B8(const char *p, unsigned n) { return n / *(unsigned *)(p + 0x28) + *(unsigned *)(p + 0x60); }
