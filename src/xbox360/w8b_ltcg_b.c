typedef unsigned int u32;
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern char lbl_88C47594[];
extern const char lbl_880F759C[];

struct W8bH { u32 *id; u32 w04; };
struct W8bCfgA { unsigned char pad00[0x48]; unsigned char on; unsigned char pad49[0x63 - 0x49]; unsigned char on2; };
struct W8bB { unsigned char pad00[0x28]; struct W8bCfgA *cfg; };
struct W8bC { unsigned char pad00[0x48]; struct W8bB *b; };
struct W8bD { unsigned char pad00[8]; struct W8bC *c; };
struct W8bRoot { unsigned char pad00[0x0c]; struct W8bH *begin; struct W8bH *end; unsigned char pad14[4]; struct W8bD *d; };

void ts4_print_handle_ids_88661AD0(struct W8bRoot *self)
{
    struct W8bCfgA *cfg = self->d->c->b->cfg;
    struct W8bH *p, *end;
    if (cfg->on && cfg->on2) {
        p = self->begin;
        end = self->end;
        for (; p != end; p++) {
            struct W8bH h = *p;
            if (h.id)
                ts4_format_text(lbl_88C47594, 16, lbl_880F759C, *h.id);
        }
    }
}
