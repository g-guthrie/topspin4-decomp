/* SM2: small predicates, conversions, global-state helpers. */
extern void fn_8858DAA8(void *p, unsigned char a, int b);
extern int lbl_88D459BC;
extern int lbl_88D459C0;
extern const float lbl_8814B440;
extern const float lbl_8802A6AC;
extern const float lbl_8802E854;
extern unsigned lbl_88D42948[];
extern unsigned lbl_88D429F0[];
extern char *lbl_88D45A10;
extern char *lbl_88D45B1C;
extern void fn_887EEC78(void *a, void *b, int c);

void ts4_forward_if_small_kind_8858CE08(char *p)
{
    unsigned char k = *(unsigned char *)(p + 0x18);
    if ((signed char)k >= 0x20) return;
    fn_8858DAA8(p, (unsigned char)(k + 0xf0), 0);
}
void ts4_sum_globals_if_kind1_886EC958(char *p)
{
    if (*(unsigned char *)(p + 0xc) != 1) return;
    *(int *)(p + 0x2c) = lbl_88D459C0 + lbl_88D459BC;
}
float ts4_get_float_or_default_88614C28(const char *p, int i)
{
    if (*(const unsigned char *)(p + 0xc2) != 0) return ((const float *)p)[i + 0x2d];
    return lbl_8814B440;
}
float ts4_i16_to_float_885BC630(const short *p) { return (float)*p * lbl_8802A6AC; }
float ts4_i32_to_float_885BC6D0(const int *p) { return (float)*p * lbl_8802E854; }
void ts4_push_stack_886E6238(unsigned v)
{
    unsigned n = lbl_88D42948[0x31a4 / 4];
    if (n >= 0x24) return;
    lbl_88D42948[0x31a4 / 4] = n + 1;
    lbl_88D42948[n] = v;
}
int ts4_alloc_bump_8864DFB8(unsigned size)
{
    unsigned n = (size + 7) & ~7u;
    unsigned base = lbl_88D429F0[0x400 / 4];
    unsigned left = lbl_88D429F0[0x404 / 4];
    lbl_88D429F0[0x400 / 4] = base + n;
    lbl_88D429F0[0x404 / 4] = left - n;
    return (int)base;
}
void ts4_call_with_state_8862DDC0(void *a)
{
    if (lbl_88D45A10) fn_887EEC78(lbl_88D45A10, a, *(int *)(lbl_88D45B1C + 0x27c));
}
unsigned char ts4_has_nonzero_byte_886C5208(const char *p)
{
    int q = *(const int *)(p + 0x144);
    return q != 0 && *(const char *)(long)q != 0;
}
void ts4_set_both_set_884801E8(unsigned char *out, const char *p)
{
    *out = *(const unsigned *)(p + 0x18) != 0 && *(const unsigned char *)(p + 0x20) != 0;
}
unsigned char ts4_has_flag_886EF9A0(const char *p)
{
    const char *q = *(const char *const *)(p + 0xc);
    return q != 0 && q[0x3c] != 0;
}
int ts4_check_pair_8865F128(const char *p)
{
    const char *q = *(const char *const *)(p + 0x44);
    if (q[0x1c] != 0 && q[0x1d] == 0) return 1;
    return 0;
}
int ts4_map_kind_88606A30(int x)
{
    int r = 1;
    if (x == 2) r = 0;
    else if (x == 1) r = 2;
    return r;
}
