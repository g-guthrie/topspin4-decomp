/* W11D LTCG route, context: src/xbox360/cw1_ctx_format_text.c, src/xbox360/pp1_pool_primer.c. Built with /Oc. */
typedef unsigned int w11d_u32;
typedef unsigned char w11d_u8;
typedef struct W11dText { w11d_u32 s; w11d_u32 pad[3]; } W11dText;
struct W11dObj { unsigned char pad00[0x9c]; void *path; unsigned char pada0[4]; float rate; };
struct W11dCfg { unsigned char pad00[0x48]; w11d_u8 on; unsigned char pad49[0x63 - 0x49]; w11d_u8 on2; };
struct W11dSelf { struct W11dObj **begin; struct W11dObj **end; };
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern void fn_8816D1A8(W11dText *t);
extern void ts4_resolve_path_text_8862F920(void *path, W11dText *out);
extern void ts4_destroy_owned_object(w11d_u32 s);
extern const char lbl_880F3850[];
/* Swing_DLL.xex 0x886B63B8: for each object, resolve its path text and print it with its rate */
void ts4_print_entry_rates_886B63B8(struct W11dSelf *self, struct W11dCfg *cfg)
{
    if (cfg->on && cfg->on2) {
        struct W11dObj **p = self->begin;
        struct W11dObj **end = self->end;
        for (; p != end; p++) {
            struct W11dObj *o = *p;
            struct { W11dText name; char buf[0x80]; } loc;
            fn_8816D1A8(&loc.name);
            ts4_resolve_path_text_8862F920(o->path, &loc.name);
            ts4_format_text(loc.buf, 0x80, lbl_880F3850, loc.name.s, (double)o->rate);
            ts4_destroy_owned_object(loc.name.s);
        }
    }
}
