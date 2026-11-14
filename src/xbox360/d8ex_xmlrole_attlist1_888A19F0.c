/* Swing_DLL.xex 0x888A19F0-0x888A1A90, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

int ts4_xmlrole_attlist1_888A19F0 HPARAMS
{
    D8_UNUSED_ARGS;
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 33;
    case TS4_XML_TOK_DECL_CLOSE:
        D8_SET_TOP_LEVEL(state);
        return 33;
    case TS4_XML_TOK_NAME:
    case 41:
        state->handler = ts4_prolog_attlist_type_888A0F78;
        return 22;
    }
    D8_COMMON(state, tok);
}
