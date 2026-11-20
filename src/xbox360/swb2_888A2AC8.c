/* Family SWB2 (jump-table switch). */
typedef struct Tok Tok;
typedef int (*TokHandler)(Tok *, int);
struct Tok {
    TokHandler handler;          /* 0x00 */
    int pad4, pad8, padc;
    int depth;                   /* 0x10 */
};
typedef struct Reader Reader;
struct Reader {
    char pad[0x1c];
    int (*match)(Reader *, const unsigned short *, void *, const void *);  /* 0x1c */
    char pad2[0x44 - 0x20];
    int offset;                  /* 0x44 */
};

extern char lbl_880D0568[];
int ts4_dispatch_token_888A2990(Tok *t, int c);
int fn_888A2928(Tok *t, int c);
int ts4_fn_888A09C0(Tok *t, int c);

int ts4_token_classify_888A2AC8(Tok *t, int op, const unsigned short *base, void *arg, Reader *r)
{
    switch (op) {
    case 15:
        t->handler = ts4_dispatch_token_888A2990;
        return 0;
    case 12:
        t->handler = ts4_dispatch_token_888A2990;
        return 1;
    case 11:
        t->handler = ts4_dispatch_token_888A2990;
        return 0x37;
    case 13:
        t->handler = ts4_dispatch_token_888A2990;
        return 0x38;
    case 14:
        return 0;
    case 16:
        if (r->match(r, base + r->offset, arg, lbl_880D0568) != 0) {
            t->handler = fn_888A2928;
            return 3;
        }
        /* fallthrough */
    default:
        if (t->depth == 0 && op == 0x1c)
            return 0x3b;
        t->handler = ts4_fn_888A09C0;
        return -1;
    case 29:
        t->handler = ts4_fn_888A09C0;
        return 2;
    }
}
