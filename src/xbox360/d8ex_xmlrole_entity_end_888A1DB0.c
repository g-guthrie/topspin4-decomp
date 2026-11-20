/* Swing_DLL.xex 0x888A1DB0-0x888A1E30, executable version 0.0.0.3. */
#include "d8ex_xmlrole.h"
#ifndef _MSC_VER
#define __forceinline inline
#endif

static __forceinline int common(PS state, int tok)
{
    if (!state->document_entity && tok == TS4_XML_TOK_PARAM_ENTITY_REF)
        return TS4_XML_ROLE_INNER_PARAM_ENTITY_REF;
    state->handler = ts4_fn_888A09C0;
    return TS4_XML_ROLE_ERROR;
}

int ts4_xmlrole_entity_end_888A1DB0 HPARAMS
{
    D8_UNUSED_ARGS;
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 11;
    case TS4_XML_TOK_DECL_CLOSE:
        D8_SET_TOP_LEVEL(state);
        return 15;
    }
    return common(state, tok);
}
