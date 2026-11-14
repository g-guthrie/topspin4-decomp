/* Swing_DLL.xex 0x888A1628-0x888A16C0, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

extern int ts4_if_get_u32_off10_888A15C0 HPARAMS;

int ts4_xmlrole_element6_888A1628 HPARAMS
{
    D8_UNUSED_ARGS;
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 39;
    case 21:
        state->handler = ts4_if_get_u32_off10_888A15C0;
        return 39;
    case 24:
        state->handler = fn_888A1200;
        state->role_none = 39;
        return 45;
    case 36:
        state->handler = fn_888A1200;
        state->role_none = 39;
        return 46;
    }
    D8_COMMON(state, tok);
}
