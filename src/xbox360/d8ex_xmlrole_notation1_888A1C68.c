/* Swing_DLL.xex 0x888A1C68-0x888A1D50, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

extern const char lbl_880D05F8[];
extern int ts4_if_get_u32_off10_888A1BA0 HPARAMS;
extern int ts4_if_get_u32_off10_888A1C08 HPARAMS;

int ts4_xmlrole_notation1_888A1C68 HPARAMS
{
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 17;
    case TS4_XML_TOK_NAME:
        if (D8_NAME_MATCHES(enc, ptr, end, lbl_880D05F8 + 0x14)) {
            state->handler = ts4_if_get_u32_off10_888A1BA0;
            return 17;
        }
        if (D8_NAME_MATCHES(enc, ptr, end, lbl_880D05F8)) {
            state->handler = ts4_if_get_u32_off10_888A1C08;
            return 17;
        }
        break;
    }
    D8_COMMON(state, tok);
}
