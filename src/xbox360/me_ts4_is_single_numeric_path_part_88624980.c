/* Swing_DLL.xex 0x88624980: true when the path splits into one all-digit component; then posts three script lines
 * pool destructor: last=first, text[0]=0, self=p, free(first); isdigit gets (unsigned char) */
typedef unsigned int u32;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)

typedef struct NameVec { char **first; char **last; char **end; } NameVec;
typedef struct Pool { char text[0x800]; NameVec items; struct Pool *self; } Pool;
typedef struct Ctx Ctx;

Pool *fn_8827FFB8(Pool *o);
void fn_8861B800(const char *path, Pool *parts);
int ts4_addr_lbl_88C317A0_88567830(int c);
void ts4_if_call_seq_u8_off824_8861B790(Ctx *ctx, int kind, const char *text);
void ts4_destroy_owned_object(void *obj);
extern const char lbl_880E196C[];
extern const char lbl_880D3BA8[];

static __inline void pool_destroy(Pool *p)
{
    p->items.last = p->items.first;
    p->text[0] = 0;
    p->self = p;
    if (p->items.first)
        ts4_destroy_owned_object(p->items.first);
}

unsigned int fn_88624980(Ctx *ctx, const char *path)
{
    Pool parts;
    unsigned int ok = 0;
    fn_8827FFB8(&parts);
    fn_8861B800(path, &parts);
    if (parts.items.last - parts.items.first == 1) {
        const char *s = parts.items.first[0];
        unsigned int len = (int)strlen(s);
        unsigned int i = 0;
        while (i < len && ts4_addr_lbl_88C317A0_88567830((unsigned char)s[i]))
            i++;
        ok = i == len;
        if (ok == 1) {
            ts4_if_call_seq_u8_off824_8861B790(ctx, 8, lbl_880E196C);
            ts4_if_call_seq_u8_off824_8861B790(ctx, 10, path);
            ts4_if_call_seq_u8_off824_8861B790(ctx, 9, lbl_880D3BA8);
        }
    }
    pool_destroy(&parts);
    return ok;
}
