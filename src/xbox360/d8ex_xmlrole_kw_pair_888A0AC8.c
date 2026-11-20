/* Swing_DLL.xex 0x888A0AC8-0x888A0BB0, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

extern const char lbl_880D05B0[];
extern int ts4_if_get_u32_off10_888A0A60 HPARAMS;
extern int ts4_if_get_u32_off10_888A0A00 HPARAMS;

int ts4_xmlrole_kw_pair_888A0AC8 HPARAMS
{
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 0;
    case TS4_XML_TOK_NAME:
        if (D8_NAME_MATCHES(enc, ptr, end, lbl_880D05B0 + 0x10)) {
            state->handler = ts4_if_get_u32_off10_888A0A60;
            return 0;
        }
        if (D8_NAME_MATCHES(enc, ptr, end, lbl_880D05B0)) {
            state->handler = ts4_if_get_u32_off10_888A0A00;
            return 0;
        }
        break;
    }
    D8_COMMON(state, tok);
}
