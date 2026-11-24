/* Swing_DLL.xex 0x888A1AF8-0x888A1B9C, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

int ts4_xmlrole_notation4_888A1AF8 HPARAMS
{
    D8_UNUSED_ARGS;
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 17;
    case TS4_XML_TOK_LITERAL:
        state->handler = fn_888A1200;
        state->role_none = 17;
        return 19;
    case TS4_XML_TOK_DECL_CLOSE:
        D8_SET_TOP_LEVEL(state);
        return 20;
    }
    D8_COMMON(state, tok);
}
