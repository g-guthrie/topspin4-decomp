/* Swing_DLL.xex 0x888A1178-0x888A11FC, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

int ts4_xmlrole_prolog2_888A1178 HPARAMS
{
    D8_UNUSED_ARGS;
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 0;
    case 11:
        return 55;
    case 13:
        return 56;
    case 29:
        state->handler = ts4_fn_888A09C0;
        return 2;
    }
    D8_COMMON(state, tok);
}
