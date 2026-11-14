/* Swing_DLL.xex 0x888A1200-0x888A1274, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

int ts4_xmlrole_decl_close_888A1200 HPARAMS
{
    D8_UNUSED_ARGS;
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return state->role_none;
    case TS4_XML_TOK_DECL_CLOSE:
        D8_SET_TOP_LEVEL(state);
        return state->role_none;
    }
    D8_COMMON(state, tok);
}
