/* SM4: tiny forwarding wrappers, 16-byte block getters and short loops (MSVC 16.00 /O2). */
typedef long long ts4_s64;
typedef unsigned long long ts4_u64;
typedef struct { ts4_s64 a, b; } ts4_p16;

/* copy of a 16-byte block at a fixed offset returned by value */
#define GET_BLOCK(NAME, OFF) \
    struct NAME##_obj { char pad[OFF]; ts4_p16 m; }; \
    ts4_p16 NAME(struct NAME##_obj *s) { return s->m; }
GET_BLOCK(ts4_get_block_70_884E4B48, 0x70)
GET_BLOCK(ts4_get_block_80_884E4B80, 0x80)
GET_BLOCK(ts4_get_block_60_884E57E0, 0x60)
GET_BLOCK(ts4_get_block_70_884E57F8, 0x70)

/* tail call with two constant pointers appended (ts4_tail_884350B0_with_ptrs_88435168 is the handler of the sibling above) */
extern void fn_884350B0(int, int, int, void *, void *);
extern char lbl_880410F0;
extern void ts4_tail_884350B0_with_ptrs_88435168(void);
void ts4_tail_884350B0_with_ptrs_88435180(int a, int b, int c) { fn_884350B0(a, b, c, &lbl_880410F0, (void *)ts4_tail_884350B0_with_ptrs_88435168); }

/* call fn_88472530 on the object at +0xb4 of the object at +8 when both exist */
extern void fn_88472530(void *);
struct sm4_b_a { char pad[8]; struct { char pad[0xb4]; void *p; } *o; };
void ts4_call_nested_ptr_88475CF0(struct sm4_b_a *s) { if (s->o) { void *p = s->o->p; if (p) fn_88472530(p); } }

/* call fn_884A6300 on the object at +0x2c when its field at +8 is set */
extern void fn_884A6300(void *);
struct sm4_b_b { char pad[0x2c]; struct { char pad[8]; int v; } *o; };
void ts4_call_if_child_set_884AE730(struct sm4_b_b *s) { void *o = s->o; if (o && s->o->v) fn_884A6300(o); }

/* tail call with constant arguments */
extern void ts4_forward_varargs_88421058(int, int, void *, int, int, int, void *);
extern char lbl_8808C97C, lbl_8808C990;
void ts4_tail_88421058_consts_884D7A18(int a, int b) { ts4_forward_varargs_88421058(a, b, &lbl_8808C97C, 5, 5, 0, &lbl_8808C990); }

/* free the block that starts one byte-header before the pointer */
extern void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *, unsigned);
void ts4_free_with_header_885BE2C8(unsigned char *p) { if (p) ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(p - p[-1], 0x248c8000); }

/* forward the child object at +8 together with this */
extern void fn_88470870(void *, void *);
struct sm4_b_d { char pad[8]; int o; };
void ts4_forward_child_885F4990(struct sm4_b_d *s) { if (s->o) fn_88470870((void *)(unsigned long)s->o, s); }

/* bits 4..23 of the 64-bit record at index i of the table owned by the child at +4 */
struct sm4_b_f { char pad[4]; struct { char pad[0x2c]; char *t; } *p; };
unsigned ts4_get_record_field_88611490(struct sm4_b_f *s, int a, int i) { (void)a; return (unsigned)((*(ts4_u64 *)(s->p->t + i * 16) >> 4) & 0xFFFFF); }

/* returns 1 when no pending child, else calls fn_8862CC90 on it */
extern int fn_8862CC90(int);
struct sm4_b_g { char pad[0x18]; int v; };
int ts4_run_pending_or_true_8862E088(struct sm4_b_g *s) { int x = s->v; int r = 1; if (x) r = fn_8862CC90(x); return r; }

/* copy 9 words into the object at +0x1c0 */
struct sm4_b_h { char pad[0x1c0]; int a[9]; };
void ts4_copy_9_words_88639DF0(struct sm4_b_h *s, int *src) { int *d = s->a - 1; int n = 9; src--; do { *++d = *++src; } while (--n); }

/* byte at +0x49b when the flag word at +0x488 is set, else 0 */
struct sm4_b_i { char pad[0x488]; int f; char pad2[0x0f]; unsigned char b; };
unsigned char ts4_get_byte_if_flag_8863A1A0(struct sm4_b_i *s) { unsigned char r = 0; if (s->f) r = s->b; return r; }

/* address of entry i (stride 0x1c) after a self-relative offset table at +0x60 of the object at +8 */
struct sm4_b_j { char pad[8]; char *o; };
char *ts4_entry_addr_88645550(struct sm4_b_j *s, int i) { char *p = s->o + 0x60; return p + *(int *)p + i * 0x1c; }

/* wire an object up to the subsystem tables of its owner */
void ts4_link_owner_tables_8865E410(int *s, char *o) { *(char **)((char *)s + 0xc) = o; *(int *)((char *)s + 4) = *(int *)(o + 0x74) + 0xa40; *(int *)((char *)s + 8) = *(int *)(o + 0x2c) + 0xa0; }

/* forward the owner object stored just below this to a registry call with two descriptor globals */
extern void fn_884E05F0(void *, int, void *, void *);
#define FWD_OWNER_DESC(NAME, BACK, DESC, TAB) \
    extern char DESC[], TAB[]; \
    void NAME(char *self, int x) { void *p = *(void **)(self - (BACK)); if (p) fn_884E05F0(p, x, TAB, DESC); }
FWD_OWNER_DESC(ts4_forward_owner_desc_884A23D0, 0x50, lbl_880885C0, lbl_88D24600)
FWD_OWNER_DESC(ts4_forward_owner_desc_884A2410, 0x54, lbl_88086BE4, lbl_88D258F0)
FWD_OWNER_DESC(ts4_forward_owner_desc_884A2540, 0x5c, lbl_8808768C, lbl_88D25710)
