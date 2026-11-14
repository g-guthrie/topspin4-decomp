/* Swing_DLL.xex 0x888A27C0-0x888A2924, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"

#ifdef _MSC_VER
#define D9_FORCEINLINE __forceinline
#else
#define D9_FORCEINLINE inline
#endif

extern const char lbl_880D05F8[];
extern int ts4_if_get_u32_off10_888A2700 HPARAMS;
extern int ts4_if_get_u32_off10_888A2760 HPARAMS;

static D9_FORCEINLINE int common(PS state, int tok)
{
    D8_COMMON(state, tok);
}

/* Expat xmlrole doctype1. */
int ts4_xmlrole_doctype1_888A27C0 HPARAMS
{
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 3;
    case 25:
        state->handler = fn_888A2458;
        return 7;
    case TS4_XML_TOK_DECL_CLOSE:
        state->handler = fn_888A1178;
        return 8;
    case TS4_XML_TOK_NAME:
        if (D8_NAME_MATCHES(enc, ptr, end, lbl_880D05F8 + 0x14)) {
            state->handler = ts4_if_get_u32_off10_888A2700;
            return 3;
        }
        if (D8_NAME_MATCHES(enc, ptr, end, lbl_880D05F8)) {
            state->handler = ts4_if_get_u32_off10_888A2760;
            return 3;
        }
        break;
    }
    return common(state, tok);
}
