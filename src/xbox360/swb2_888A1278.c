/* Family SWB2 (jump-table switch). */
typedef struct Tok Tok;
typedef int (*TokHandler)(Tok *, int);
struct Tok {
    TokHandler handler;          /* 0x00 */
    int count;                   /* 0x04 */
    int state;                   /* 0x08 */
    int padc;
    int depth;                   /* 0x10 */
};

int fn_888A1200(Tok *t, int c);
int ts4_token_classify_888A1410(Tok *t, int c);
int ts4_fn_888A09C0(Tok *t, int c);

#define COUNTDOWN_RET(code)                 \
    if (--t->count == 0) {                  \
        t->state = 0x27;                    \
        t->handler = fn_888A1200;           \
    }                                       \
    return code

int ts4_token_countdown_888A1278(Tok *t, int c)
{
    switch (c) {
    case 15:
        return 0x27;
    case 24:
        COUNTDOWN_RET(0x2d);
    case 36:
        COUNTDOWN_RET(0x2e);
    case 35:
        COUNTDOWN_RET(0x2f);
    case 37:
        COUNTDOWN_RET(0x30);
    case 38:
        t->handler = ts4_token_classify_888A1410;
        return 0x32;
    case 21:
        t->handler = ts4_token_classify_888A1410;
        return 0x31;
    default:
        if (t->depth == 0 && c == 0x1c)
            return 0x3b;
        t->handler = ts4_fn_888A09C0;
        return -1;
    }
}
