/* W9D: 0x88658B90 (LTCG, ctx cw1_ctx_format_text.c). b is a 12-byte handle, a is 8 bytes: gives the 0x2c0 frame. */
typedef unsigned char u8;
typedef unsigned int u32;
struct D1Out { u32 v; u32 pad; };
struct D1Obj;
struct D1Big { u32 v; u32 x, y; };
struct D1Vt { char pad[0x1c]; void (*slot7)(struct D1Obj *o, int a, int b); };
struct D1Obj { struct D1Vt *vt; };
struct D1S { char p[4]; int w4; char p2[8]; int w10; int w14; int w18; int h; char p3[0x30-0x20]; u8 flag; };
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern char lbl_880C8F28[];
extern struct D1Out *ts4_query_handle_88655800(struct D1Out *out, const u8 *flag, const char *key);
extern void ts4_assign_formatted_text(struct D1Big *dst, const char *src);
extern struct D1Out *fn_88655718(struct D1Out *out, const u8 *flag, struct D1Big *key);
extern void ts4_destroy_owned_object(void *p);
extern void fn_88657658(struct D1S *s);
int ts4_load_handle_88658B90(struct D1S *s, u8 reuse)
{
    char buf[0x200];
    struct D1Out a; struct D1Big b;
    ts4_format_text(buf, 0x200, lbl_880C8F28, s->w4, s->w10);
    if (reuse == 0)
        s->h = ts4_query_handle_88655800(&a, &s->flag, buf)->v;
    if (s->h != 0) {
        ((struct D1Obj *)(unsigned long)s->h)->vt->slot7((struct D1Obj *)(unsigned long)s->h, 0, 1);
    } else {
        ts4_assign_formatted_text(&b, buf);
        fn_88655718(&a, &s->flag, &b);
        s->h = a.v;
        ts4_destroy_owned_object((void *)(unsigned long)b.v);
        if (s->h == 0) return 0;
        s->w14 = 0;
        fn_88657658(s);
    }
    return 1;
}
