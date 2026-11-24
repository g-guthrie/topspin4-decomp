/* nearmiss: 3 off (q5s 2026-11-24); concrete blocker: the store of 0 to lbl_88D45AD0 must come after the buf load+cmplwi. C forms tried: p before store (6 off), inline release/free helpers, pointer-to-global, store in both arms. Likely a real C++ dtor (static reset in body, member buffer dtor, base dtor) but the implicit vtable/base-dtor relocations would need C++ names the symbol map lacks. */
/* Near-miss (agAP), 0x88720108, plain /Oc: 3 off. The store of 0 to lbl_88D45AD0 is scheduled before the s->buf load; the target places it after the cmplwi. */
extern void *lbl_88D45B38; extern int lbl_88D45AD0; extern char lbl_880F2A80[];
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *p, void *h);
void fn_885651F8(void *p);
typedef struct S S;
void ts4_if_call_seq_lbl_880F21E8_88720080(S *s);
struct S { void *vt; char p4[0x7c]; void *buf; char p84[4]; void *h; };
void ts4_dtor_buffer_owner_88720108(S *s){ void *p; s->vt = lbl_880F2A80; lbl_88D45AD0 = 0; p = s->buf; if (p) { if (lbl_88D45B38) ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, p, s->h); else fn_885651F8(p); } ts4_if_call_seq_lbl_880F21E8_88720080(s); }
