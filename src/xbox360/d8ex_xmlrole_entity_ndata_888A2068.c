/* Swing_DLL.xex 0x888A2068-0x888A2150, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

extern const char lbl_880D05C8[];
extern int ts4_if_get_u32_off10_888A2000 HPARAMS;

int ts4_xmlrole_entity_ndata_888A2068 HPARAMS
{
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 11;
    case TS4_XML_TOK_DECL_CLOSE:
        D8_SET_TOP_LEVEL(state);
        return 15;
    case TS4_XML_TOK_NAME:
        if (D8_NAME_MATCHES(enc, ptr, end, lbl_880D05C8)) {
            state->handler = ts4_if_get_u32_off10_888A2000;
            return 11;
        }
        break;
    }
    D8_COMMON(state, tok);
}
