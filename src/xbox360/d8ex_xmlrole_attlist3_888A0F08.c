/* Swing_DLL.xex 0x888A0F08-0x888A0F78, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

extern int ts4_if_addr_fn_888A0F08_888A0E90 HPARAMS;

int ts4_xmlrole_attlist3_888A0F08 HPARAMS
{
    D8_UNUSED_ARGS;
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 33;
    case 19:
    case TS4_XML_TOK_NAME:
    case 41:
        state->handler = ts4_if_addr_fn_888A0F08_888A0E90;
        return 31;
    }
    D8_COMMON(state, tok);
}
