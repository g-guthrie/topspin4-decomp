/* Family SWB2 (jump-table switch). */
typedef struct Tok Tok;
struct Tok {
    int (*handler)(Tok *, int);  /* 0x00 */
    int count;                   /* 0x04 */
    int pad8, padc;
    int depth;                   /* 0x10 */
};

int ts4_token_countdown_888A1278(Tok *t, int c);
int ts4_fn_888A09C0(Tok *t, int c);

int ts4_token_classify_888A1410(Tok *t, int c)
{
    switch (c) {
    case 15:
        return 0x27;
    case 23:
        t->count++;
        return 0x2c;
    case 18:
    case 41:
        t->handler = ts4_token_countdown_888A1278;
        return 0x33;
    case 30:
        t->handler = ts4_token_countdown_888A1278;
        return 0x35;
    case 31:
        t->handler = ts4_token_countdown_888A1278;
        return 0x34;
    case 32:
        t->handler = ts4_token_countdown_888A1278;
        return 0x36;
    default:
        if (t->depth == 0 && c == 0x1c)
            return 0x3b;
        t->handler = ts4_fn_888A09C0;
        return -1;
    }
}
