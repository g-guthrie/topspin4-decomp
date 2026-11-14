/* SM1 batch b: vtable thunks, this-adjusting thunks, small float setters. */
typedef unsigned long long u64;
typedef unsigned int u32;
typedef struct ts4_obj { int (**vt)(); } ts4_obj;

extern int fn_883E24D8(void *, float, float, float);
extern int fn_883E2598(void *, float);
extern int fn_883E2640(void *, float);
extern int fn_883E2790(void *, float);
extern int fn_883E2428(void *, float, float);
extern int ts4_if_call_seq_u32_off880_883632B8(void *, int);
extern int fn_88382758(void *, int, int, int);
extern int fn_883A3198(void *, int);
extern int fn_8832FA68(void *);
extern int fn_88399560(void *);
extern float lbl_88001A20;
extern float lbl_8802E93C, lbl_8802E940, lbl_8802E938, lbl_8802E930, lbl_8802E934;

/* Swing_DLL.xex 0x883F72B0: forward three floats from a config block to a callee */
typedef struct ts4_cfg_holder { int pad0; char *cfg; int pad8, padc; void *target; } ts4_cfg_holder;
int ts4_forward_cfg_vec3_883F72B0(ts4_cfg_holder *h) {
    char *c = h->cfg;
    return fn_883E24D8(h->target, *(float *)(c + 0xf8), *(float *)(c + 0xfc), *(float *)(c + 0x100));
}
int ts4_forward_cfg_float104_883F72C8(ts4_cfg_holder *h) { char *c = h->cfg; return fn_883E2598(h->target, *(float *)(c + 0x104)); }
int ts4_forward_cfg_float90_883F72D8(ts4_cfg_holder *h) { char *c = h->cfg; return fn_883E2640(h->target, *(float *)(c + 0x90)); }
int ts4_forward_cfg_float8c_883F72E8(ts4_cfg_holder *h) { char *c = h->cfg; return fn_883E2790(h->target, *(float *)(c + 0x8c)); }
int ts4_forward_cfg_vec2_883F7298(ts4_cfg_holder *h) { char *c = h->cfg; return fn_883E2428(h->target, *(float *)(c + 0xd4), *(float *)(c + 0xd8)); }

/* vtable slot thunks */
typedef struct ts4_vo { int (**vt)(struct ts4_vo *, ...); } ts4_vo;
int ts4_vcall_slot12_byte_881F34F8(void *unused, ts4_vo *o, unsigned char *c) { (void)unused; return ((int (*)(ts4_vo *, unsigned char))o->vt[0x48 / 4])(o, *c); }
int ts4_vcall_slot14_byte_881F3528(void *unused, ts4_vo *o, unsigned char *c) { (void)unused; return ((int (*)(ts4_vo *, unsigned char))o->vt[0x50 / 4])(o, *c); }
int ts4_vcall_slot9_881DD468(void *unused, ts4_vo *o, int a) { (void)unused; return ((int (*)(ts4_vo *, int))o->vt[0x24 / 4])(o, a); }

/* this-adjusting thunks (secondary base at +0x1c) */
int ts4_thunk_adj1c_arg1_88363798(char *p) { return ts4_if_call_seq_u32_off880_883632B8(p ? p - 0x1c : 0, 1); }

/* relative-offset pointer decode: -1 means null */
void *ts4_decode_rel_ptr_off10_88187760(char *p) { char *q = p + 0x10; void *r = 0; int off = *(int *)q; if (off != -1) r = q + off; return r; }
void *ts4_decode_rel_ptr_off0_881BB8A0(char *p) { char *q = p; void *r = 0; int off = *(int *)q; if (off != -1) r = q + off; return r; }
