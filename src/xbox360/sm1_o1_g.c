/* SM1 /O1 batch g. */
typedef unsigned int u32;

/* Swing_DLL.xex 0x883FFA40: push a value into a ring buffer; false when full */
typedef struct Ts4Ring { int pad[2]; u32 *buf; u32 cap; u32 count; u32 head; } Ts4Ring;
int ts4_ring_push_883FFA40(Ts4Ring *t, u32 v) { u32 cap = t->cap; u32 n = t->count; if (n >= cap) return 0; t->buf[(t->head + n) % cap] = v; t->count = t->count + 1; return 1; }

/* 0x883FDB60: state 0 -> false, state 1 -> callee returns zero, otherwise true */
extern int fn_883E2D98(int);
typedef struct Ts4State20 { char pad[0x20]; int state; } Ts4State20;
int ts4_state_check_883FDB60(Ts4State20 *t, int a) { int s = t->state; if (s == 0) return 0; if (s == 1) return (unsigned char)fn_883E2D98(a) == 0; return 1; }

/* 0x883FF908: finalize the owned object through vtable slot 1; clear the pointer on success */
typedef struct Ts4VOwn { int (**vt)(); } Ts4VOwn;
typedef struct Ts4OwnerPtr { Ts4VOwn *obj; } Ts4OwnerPtr;
int ts4_finalize_owned_and_clear_883FF908(Ts4OwnerPtr *t) { Ts4VOwn *p = t->obj; if (p) { int r = ((int (*)(Ts4VOwn *))p->vt[1])(p); if (r != 0) return r; } t->obj = 0; return 0; }

/* 0x882C35D0: run two steps; the second only when the first succeeded, and report only failures */
extern int fn_882C28B0(void *, void *);
extern int fn_882C2AF8(void *, void *);
int ts4_two_step_report_failure_882C35D0(void *t, char *b) { int r = fn_882C28B0(t, b + 8); if (r >= 0) { r = fn_882C2AF8(t, b); r = r & (r >> 31); } return r; }

/* 0x883FF5F8: fetch a 64-bit pair from the context's service and copy it to the output */
extern int ts4_if_call_seq_fn_88309DB8_883095F8(void *, int *, int *);
typedef struct Ts4SvcOwner { char pad[4]; struct { char pad[0xc]; void *service; } *ctx; } Ts4SvcOwner;
typedef struct Ts4IntPair { int a, b; } Ts4IntPair;
int ts4_fetch_pair_883FF5F8(Ts4SvcOwner *t, Ts4IntPair *out) { Ts4IntPair tmp; int r; if (out == 0) return 0x25; r = ts4_if_call_seq_fn_88309DB8_883095F8(t->ctx->service, &tmp.a, &tmp.b); if (r == 0) *out = tmp; return r; }
