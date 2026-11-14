/* SM2: small accessors, null-guarded forwarding tail calls and bit tests. */
typedef long long ts4_s64;
typedef struct ts4_pair64 { ts4_s64 a, b; } ts4_pair64;

extern void ts4_destroy_owned_object(void *object);
extern void ts4_set_u32_off8_8847FA60(void *p, unsigned v);
extern void ts4_tailcall_NetDll_closesocket_884F0258(int s);
extern void ts4_mat34_scale_rows_8864E5A8(void *a, float x, float y, float z);
extern void fn_886D0808(void *p);
extern void fn_88566E40(void *p);
extern void fn_88472530(void *p);

/* store a float at float index (i + 0x2d) */
void ts4_set_float_idx_2d_88606CD0(char *p, int i, float v) { ((float *)p)[i + 0x2d] = v; }
/* float field at +0x50 returned as its raw bit pattern */
unsigned ts4_get_float_bits_50_886EC440(const char *p) { float f = *(const float *)(p + 0x50); return *(unsigned *)&f; }
/* forward a float vec3 by components */
void ts4_call_with_vec3_8864EF50(void *a, const float *v) { ts4_mat34_scale_rows_8864E5A8(a, v[0], v[1], v[2]); }
void ts4_set_byte_nested_a34_88660CE0(const char *s, char v) { *(char *)(*(char **)(*(char **)(s + 0x30) + 0x74) + 0xa34) = v; }
unsigned char ts4_pack_or_shl1_8840F170(unsigned char a, int b) { return (unsigned char)((b << 1) | a); }
unsigned ts4_get_u32_by_is_zero_8865A278(const char *p, unsigned v) { return ((const unsigned *)*(const char **)(p + 0x10))[v == 0]; }
float ts4_swap_float_stride8_88554430(char *a, int i, float v) { float t = *(float *)(a + i * 8); *(float *)(a + i * 8) = v; return t; }
void ts4_if_state1_forward_886D0898(const char *p) { if (*p == 1) fn_886D0808((void *)p); }
void ts4_if_set_u32_off8_8846A380(char *p) { if (p) ts4_set_u32_off8_8847FA60(p, *(unsigned *)(p + 8)); }
void ts4_destroy_field0_886CFA08(char *p) { if (*(void **)p) ts4_destroy_owned_object(*(void **)p); }
void ts4_destroy_field14_886291C8(char *p) { if (*(void **)(p + 0x14)) ts4_destroy_owned_object(*(void **)(p + 0x14)); }
void ts4_destroy_field24_886C93B0(char *p) { if (*(void **)(p + 0x24)) ts4_destroy_owned_object(*(void **)(p + 0x24)); }
void ts4_close_socket_if_valid_8864DF18(char *p) { if (*(int *)(p + 4) != -1) ts4_tailcall_NetDll_closesocket_884F0258(*(int *)(p + 4)); }
void ts4_call_if_field8_88425088(char *p) { if (*(void **)(p + 8)) fn_88566E40(*(void **)(p + 8)); }
void ts4_call_if_fielda8_8846C160(char *p) { if (*(void **)(p + 0xa8)) fn_88472530(*(void **)(p + 0xa8)); }
