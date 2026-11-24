/* 0x8854D7F8: for message types 2/6 (body +0x20) and 4 (body +0x30) calls the handler of slot m->sub (0x50-byte slots at +0x16C8 of *ctx) with the message, body, its fields and user. */
/* Matched on /Oc (agAF). The type is copied into an int local before the switch, which gives cmpwi; switching on the byte or a cast gives cmplwi. */
typedef struct Msg Msg;
typedef struct Ctx Ctx;
typedef void (*Handler)(Msg *m, void *body, int a, int b, Ctx **ctx, int c, void *user);
typedef struct Slot { Handler fn; char p4[0x4c]; } Slot;
struct Ctx { char p[0x16c8]; Slot slots[1]; };
struct Msg { unsigned char type; unsigned char sub; char p2[6]; int c; char pc[4]; int a; int b; char p18[8]; char body20[0x10]; char body30[0x10]; };
void fn_8854D7F8(Msg *m, Ctx **ctx, void *user)
{
    int type = m->type;
    void *body;
    Handler h;
    switch (type) {
    case 2:
    case 6:
        body = m->body20;
        break;
    case 4:
        body = m->body30;
        break;
    default:
        return;
    }
    h = (*ctx)->slots[m->sub].fn;
    if (h)
        h(m, body, m->a, m->b, ctx, m->c, user);
}
