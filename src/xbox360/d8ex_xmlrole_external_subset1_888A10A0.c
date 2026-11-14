/* Swing_DLL.xex 0x888A10A0-0x888A1154, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

int ts4_xmlrole_external_subset1_888A10A0 HPARAMS
{
    switch (tok) {
    case 33:
        state->handler = fn_888A0AC8;
        return 0;
    case 34:
        if (state->include_level == 0)
            break;
        state->include_level -= 1;
        return 0;
    case TS4_XML_TOK_PROLOG_S:
        return 0;
    case 26:
        break;
    case -4:
        if (state->include_level)
            break;
        return 0;
    default:
        return fn_888A2458(state, tok, ptr, end, enc);
    }
    D8_COMMON(state, tok);
}
