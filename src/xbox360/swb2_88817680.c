/* Family SWB2 (jump-table switch). */
typedef struct Parser {
    char pad0[4];
    int arg;        /* 0x04 */
    char pad8[8];
    int state;      /* 0x10 */
} Parser;

void fn_88817390(Parser *p, int a);
void lua2_whilestat_88816DA0(Parser *p, int a);
void lua2_next_88814BB8(Parser *p);
void lua2_block_888153C0(Parser *p);
void lua2_check_match_88815580(Parser *p, int a, int b, int c);
void lua2_forstat_888175A0(Parser *p, int a);
void lua2_repeatstat_88817290(Parser *p, int a);
void lua2_funcstat_88816788(Parser *p, int a);
void fn_888160F8(Parser *p);
void lua2_localstat_88815CF8(Parser *p);
void lua2_retstat_88815BD8(Parser *p);
void lua2_breakstat_88815288(Parser *p);
void lua2_continuestat_88815140(Parser *p);
void lua2_exprstat_88816BA8(Parser *p);

int ts4_parser_dispatch_88817680(Parser *p)
{
    int arg = p->arg;

    switch (p->state) {
    case 0x10b:
        fn_88817390(p, arg);
        break;
    case 0x116:
        lua2_whilestat_88816DA0(p, arg);
        break;
    case 0x104:
        lua2_next_88814BB8(p);
        lua2_block_888153C0(p);
        lua2_check_match_88815580(p, 0x107, 0x104, arg);
        break;
    case 0x109:
        lua2_forstat_888175A0(p, arg);
        break;
    case 0x111:
        lua2_repeatstat_88817290(p, arg);
        break;
    case 0x10a:
        lua2_funcstat_88816788(p, arg);
        break;
    case 0x10d:
        lua2_next_88814BB8(p);
        if (p->state == 0x10a) {
            lua2_next_88814BB8(p);
            fn_888160F8(p);
        } else {
            lua2_localstat_88815CF8(p);
        }
        break;
    case 0x112:
        lua2_retstat_88815BD8(p);
        return 1;
    case 0x102:
        lua2_breakstat_88815288(p);
        return 1;
    case 0x103:
        lua2_continuestat_88815140(p);
        return 1;
    default:
        lua2_exprstat_88816BA8(p);
        break;
    }
    return 0;
}
