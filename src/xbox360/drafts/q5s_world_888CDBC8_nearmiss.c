/* nearmiss: 4 off; the target reaches the list header through a clrrwi copy of the +0x8c offset (load removed late) and
 * returns through beqlr with r3 = 0 preset; inline accessor re-reads (q5_self/q5_off/q5_hd), two-path forms all keep
 * a plain add (see matching-tips clrrwi section). Compare order and return-variable form are solved. */
/* 0x888CDBC8: does the self-relative id list reached through the self-relative head at +0x8c contain id? */
typedef unsigned int u32;
typedef struct Q5RelIds { int off; u32 count; } Q5RelIds;
typedef struct Q5RelHead { int off; } Q5RelHead;
typedef struct Q5IdOwner { char pad[0x8c]; Q5RelHead ids; } Q5IdOwner;
static __inline u32 *q5_ids_begin(Q5RelIds *a) { return a->off != -1 ? (u32 *)((char *)a + a->off) : 0; }
static __inline u32 *q5_ids_end(Q5RelIds *a) { return a->off != -1 ? (u32 *)((char *)a + a->count * 4 + a->off) : 0; }
static __inline u32 *q5_ids_begin2(Q5RelIds *a) { u32 *p = 0; if (a->off != -1) p = (u32 *)((char *)a + a->off); return p; }
static __inline u32 *q5_ids_end2(Q5RelIds *a) { u32 *p = 0; if (a->off != -1) p = (u32 *)((char *)a + (a->count * 4 + a->off)); return p; }
static __inline Q5RelIds *q5_head_get(Q5RelHead *h) { return (Q5RelIds *)((char *)h + h->off); }
static __inline Q5RelIds *q5_head_get2(Q5RelHead *h) { return h->off != -1 ? (Q5RelIds *)((char *)h + h->off) : 0; }
static __inline u32 *q5_find(u32 *p, u32 *e, u32 id) { for (; p != e; p++) if (*p == id) break; return p; }
static __inline u32 *q5_find2(u32 *p, u32 *e, const u32 *id) { for (; p != e; ++p) if (*p == *id) return p; return p; }
static __inline Q5RelHead *q5_ids(Q5IdOwner *s) { return &s->ids; }
static __inline Q5RelHead *q5_self(Q5RelHead *h) { return h; }
typedef struct K { u32 v; } K;
static int q5_eq(const u32 *p, u32 id) { K k; k.v = *p; return id == k.v; }
static __inline Q5RelIds *q5_head_get3(Q5RelHead *h) { Q5RelIds *p = 0; if (h->off != -1) p = (Q5RelIds *)((char *)h + h->off); return p; }
static __inline Q5RelHead *q5_hd(Q5IdOwner *s) { return &s->ids; }
int ts4_ids_contain_888CDBC8(Q5IdOwner *self, u32 id){ int r = 0; Q5RelHead *h = &self->ids; Q5RelIds *a; u32 *e; if (h->off == -1) return 0; a = q5_head_get2(h); { u32 *p; e = q5_ids_end2(a); for (p = q5_ids_begin2(a); e != p; p++) if (id == *p) { r = 1; break; } } return r; }
