/* Family SWB2 (jump-table switch). */
typedef struct Parser {
    char pad0[4];
    int arg;        /* 0x04 */
    char pad8[8];
    int state;      /* 0x10 */
} Parser;

void fn_88817390(Parser *p, int a);
void fn_88816DA0(Parser *p, int a);
void fn_88814BB8(Parser *p);
void fn_888153C0(Parser *p);
void fn_88815580(Parser *p, int a, int b, int c);
void fn_888175A0(Parser *p, int a);
void fn_88817290(Parser *p, int a);
void fn_88816788(Parser *p, int a);
void fn_888160F8(Parser *p);
void fn_88815CF8(Parser *p);
void fn_88815BD8(Parser *p);
void fn_88815288(Parser *p);
void fn_88815140(Parser *p);
void fn_88816BA8(Parser *p);

int ts4_parser_dispatch_88817680(Parser *p)
{
    int arg = p->arg;

    switch (p->state) {
    case 0x10b:
        fn_88817390(p, arg);
        break;
    case 0x116:
        fn_88816DA0(p, arg);
        break;
    case 0x104:
        fn_88814BB8(p);
        fn_888153C0(p);
        fn_88815580(p, 0x107, 0x104, arg);
        break;
    case 0x109:
        fn_888175A0(p, arg);
        break;
    case 0x111:
        fn_88817290(p, arg);
        break;
    case 0x10a:
        fn_88816788(p, arg);
        break;
    case 0x10d:
        fn_88814BB8(p);
        if (p->state == 0x10a) {
            fn_88814BB8(p);
            fn_888160F8(p);
        } else {
            fn_88815CF8(p);
        }
        break;
    case 0x112:
        fn_88815BD8(p);
        return 1;
    case 0x102:
        fn_88815288(p);
        return 1;
    case 0x103:
        fn_88815140(p);
        return 1;
    default:
        fn_88816BA8(p);
        break;
    }
    return 0;
}
