/* SM4: table loops and small field helpers (MSVC 16.00 /O2). */
typedef long long ts4_s64;

/* copy the owner's value when the flag byte of the context is set; returns the flag */
struct sm4_g1 { char pad[0x4da]; unsigned char b; };
struct sm4_q1 { char pad[0x74c]; int v; };
struct sm4_p1 { char pad[0x2c]; struct sm4_q1 *q; char pad2[0x44]; struct sm4_g1 *g; };
struct sm4_m2 { char pad[4]; struct sm4_p1 *p; int f8; };
unsigned char ts4_latch_value_if_flag_8865AB70(struct sm4_m2 *s) { unsigned char b = s->p->g->b; if (b) s->f8 = s->p->q->v; return b; }

/* begin pointer when the (end - begin) / 12 element count is non-zero; clears a field */
struct sm4_d1 { char *b; char *e; char pad[0x818]; int f; };
char *ts4_begin_if_nonempty_88609C50(struct sm4_d1 *s) { char *r = 0; s->f = 0; if ((s->e - s->b) / 12) r = s->b; return r; }

/* out = (n * 8, n) when enabled, else (0, 0) */
struct sm4_f3 { char pad[0x1c]; int n; };
void ts4_get_bit_and_count_88485ED0(struct sm4_f3 *s, signed char b, int *out) { if (b) { int n = s->n; out[0] = n << 3; out[1] = n; } else { out[0] = 0; out[1] = 0; } }

/* (float)byte minus offset times scale */
extern float lbl_88002430, lbl_8802A584;
float ts4_byte_to_scaled_float_885BC600(unsigned char *p) { return ((float)*p - lbl_88002430) * lbl_8802A584; }

/* set two fields on every element of a pointer array */
struct sm4_a1 { char pad[0x30]; int a; char pad2[0xc]; int b; };
void ts4_init_elems_88494490(struct sm4_a1 **arr, int n) { int i; for (i = 0; i < n; i++) { struct sm4_a1 *p = arr[i]; p->a = 1; p->b = 0; } }

/* clear a byte on every element of the owner's pointer array */
struct sm4_b3 { char pad[0x0c]; struct { char pad[4]; char b; } **arr; int n; };
void ts4_clear_elem_flags_88404060(struct sm4_b3 *s) { int i; int n = s->n; for (i = 0; i < n; i++) s->arr[i]->b = 0; }

/* read a 64-bit value from a bounded buffer: returns 8 on success, -1 when too short */
int ts4_read_s64_88603C98(const ts4_s64 *src, ts4_s64 *out, unsigned *rem) { unsigned n = *rem; ts4_s64 v; if (n < 8) return -1; v = *src; *rem = n - 8; *out = v; return 8; }

/* whitespace test: space, tab, newline or carriage return */
void ts4_is_space_884DAD78(unsigned char *out, signed char c) { *out = (c == 0x20 || c == 9 || c == 10 || c == 13); }

/* pop the last 12-byte element index: returns its address or 0 when the stack is empty */
struct sm4_b { int *base; char pad[0x81c]; int n; };
char *ts4_pop_last_elem12_88609BD0(struct sm4_b *s) { char *r = 0; int n = s->n - 1; s->n = n; if (n > -1) r = (char *)s->base + n * 12; return r; }

/* true when the nested context flag is set and its id equals a constant */
struct sm4_h5 { char pad[0xac]; unsigned id; char pad2[0x27a]; unsigned char b; };
struct sm4_h6 { char pad[0x30]; struct sm4_h5 *g; };
struct sm4_h7 { char pad[0x20]; struct sm4_h6 *p; };
int ts4_is_ctx_id_match_8865EA50(struct sm4_h7 *s) { int r = 0; struct sm4_h5 *g = s->p->g; if (g->b) { if (g->id == 0xd826e563u) r = 1; } return r; }
