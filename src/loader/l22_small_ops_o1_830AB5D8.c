/* Loader_DLL.xex 0x830AB5D8-0x83486688, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
typedef __int64 ts4l_s64;
#else
typedef unsigned long long ts4l_u64;
typedef long long ts4l_s64;
#endif

unsigned ts4l_align_up_830AB5D8(unsigned a, unsigned b) { return (a + b - 1) / b * b; }
unsigned ts4l_align_up_830AE490(unsigned a, unsigned b) { return (a + b - 1) / b * b; }
int ts4l_mask64_test_830B49E0(ts4l_u64 *t, int i, ts4l_u64 m) { return (t[i] & m) != 0; }
int ts4l_mask64_test_830B6140(ts4l_u64 *t, int i, ts4l_u64 m) { return (t[i] & m) != 0; }
ts4l_u64 ts4l_range_mask64_830C0950(unsigned a, unsigned b) { unsigned lo = a >> 2; unsigned hi = (a + b - 1) >> 2; return ((ts4l_u64)((ts4l_s64)(1ull << 63) >> (hi - lo))) >> lo; }
int ts4l_bit_test_830C94E8(unsigned *bits, unsigned i) { return (bits[i >> 5] & (1u << (i & 31))) != 0; }
int ts4l_bit_test_830C9540(unsigned *bits, unsigned i) { return (bits[i >> 5] & (1u << (i & 31))) != 0; }
int ts4l_bit_test_830C95D8(unsigned *bits, unsigned i) { return (bits[i >> 5] & (1u << (i & 31))) != 0; }
ts4l_u64 ts4l_range_mask64_830D33C0(unsigned a, unsigned b) { unsigned lo = a >> 2; unsigned hi = (a + b - 1) >> 2; return ((ts4l_u64)((ts4l_s64)(1ull << 63) >> (hi - lo))) >> lo; }
int ts4l_mask64_test_830D7E00(ts4l_u64 *t, int i, ts4l_u64 m) { return (t[i] & m) != 0; }
int ts4l_mask64_test_830D9F78(ts4l_u64 *t, int i, ts4l_u64 m) { return (t[i] & m) != 0; }
unsigned ts4l_align_up_830DFC08(unsigned a, unsigned b) { return (a + b - 1) / b * b; }
ts4l_u64 ts4l_range_mask64_83158A28(unsigned a, unsigned b) { unsigned lo = a >> 2; unsigned hi = (a + b - 1) >> 2; return ((ts4l_u64)((ts4l_s64)(1ull << 63) >> (hi - lo))) >> lo; }
ts4l_u64 ts4l_range_mask64_8315E160(unsigned a, unsigned b) { unsigned lo = a >> 2; unsigned hi = (a + b - 1) >> 2; return ((ts4l_u64)((ts4l_s64)(1ull << 63) >> (hi - lo))) >> lo; }
unsigned ts4l_load_be32_831610F0(unsigned char *p) { return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]; }
unsigned ts4l_load_be32_83161120(unsigned char *p) { return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]; }
short ts4l_load_be16_83161150(unsigned char *p) { return (short)((p[0] << 8) | p[1]); }
unsigned ts4l_load_be32_83163A50(unsigned char *p) { return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]; }
unsigned ts4l_load_be32_83163A80(unsigned char *p) { return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]; }
short ts4l_load_be16_83163AB0(unsigned char *p) { return (short)((p[0] << 8) | p[1]); }
void ts4l_swap16_store_83423728(unsigned short *d, unsigned short *s) { unsigned short v = *s; *d = (unsigned short)((v >> 8) | (v << 8)); }
void ts4l_swap16_store_83486670(unsigned short *d, unsigned short *s) { unsigned short v = *s; *d = (unsigned short)((v >> 8) | (v << 8)); }
