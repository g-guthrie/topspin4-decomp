/* 0x88658A38 (LTCG, ctx cw1_ctx_format_text.c): format the resource key from s->w4 and id; if neither store
   (global manager store when s->flag, else the fallback store) has it, load a handle, give it the 10-byte tag and
   attach it. Sibling of ts4_load_handle_88658B90 (w9d_88658b90.c). */
typedef unsigned char u8;
typedef unsigned int u32;
struct D1Out { u32 v; u32 pad; };
struct D1Big { u32 v; u32 x, y; };
typedef struct Tag10 { char c[10]; } Tag10;
struct Res;
struct ResInner;
struct ResInnerVt { char p[0x58]; void (*attach)(struct ResInner *i, struct D1Out *h); };
struct ResInner { struct ResInnerVt *vt; };
struct ResVt { char p[0x10]; void (*set_tag)(struct Res *r, char *tag, int n); };
struct Res { struct ResVt *vt; struct ResInner *inner; };
struct Store;
struct StoreVt { char p[0x38]; void (*attach)(struct Store *s, struct D1Out *h); char q[8]; u8 (*has)(struct Store *s, const char *key); };
struct Store { struct StoreVt *vt; };
struct Mgr { char p[0x220]; struct Store *store; };
extern struct Mgr *lbl_88D45B1C;
extern struct Store *lbl_88D45B2C;
struct D1S { char p[4]; int w4; char p2[0x28]; u8 flag; };
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern char lbl_880F5080[];
extern const Tag10 lbl_880F508C;
extern void ts4_assign_formatted_text(struct D1Big *dst, const char *src);
extern struct D1Out *fn_88655718(struct D1Out *out, const u8 *flag, struct D1Big *key);
extern void ts4_destroy_owned_object(void *p);

static __inline u8 store_has(const u8 *flag, const char *key)
{
    u8 r = 0;
    if (*flag) {
        struct Store *st = lbl_88D45B1C->store;
        r = st->vt->has(st, key);
    } else if (lbl_88D45B2C) {
        r = lbl_88D45B2C->vt->has(lbl_88D45B2C, key);
    }
    return r;
}
static __inline void res_attach(const u8 *flag, struct D1Out *h)
{
    if (*flag) {
        struct ResInner *in = ((struct Res *)(unsigned long)h->v)->inner;
        in->vt->attach(in, h);
    } else if (lbl_88D45B2C) {
        lbl_88D45B2C->vt->attach(lbl_88D45B2C, h);
    }
}

void ts4_load_tagged_resource_88658A38(struct D1S *s, int id)
{
    char buf[0x200];
    struct D1Out h;
    struct D1Big b;
    ts4_format_text(buf, 0x200, lbl_880F5080, s->w4, id);
    if (!store_has(&s->flag, buf)) {
        ts4_assign_formatted_text(&b, buf);
        fn_88655718(&h, &s->flag, &b);
        ts4_destroy_owned_object((void *)(unsigned long)b.v);
        if (h.v) {
            Tag10 tag = lbl_880F508C;
            struct Res *r = (struct Res *)(unsigned long)h.v;
            r->vt->set_tag(r, tag.c, 10);
            res_attach(&s->flag, &h);
        }
    }
}
