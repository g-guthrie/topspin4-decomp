/* Swing_DLL.xex expat xmlrole.c state functions (shared declarations). */
#ifndef D8EX_XMLROLE_H
#define D8EX_XMLROLE_H
#include "r3_xmlrole.h"

#define PS struct ts4_prolog_state *
#define ENC const struct ts4_xml_encoding *
#define HPARAMS (PS state, int tok, const char *ptr, const char *end, ENC enc)

extern int ts4_fn_888A09C0 HPARAMS;
extern int fn_888A1200 HPARAMS;
extern int fn_888A10A0 HPARAMS;
extern int fn_888A2458 HPARAMS;
extern int fn_888A1178 HPARAMS;
extern int fn_888A0AC8 HPARAMS;
extern int fn_888A19F0 HPARAMS;
extern int ts4_prolog_attlist_type_888A0F78 HPARAMS;

#define D8_UNUSED_ARGS (void)ptr; (void)end; (void)enc

#define D8_NAME_MATCHES(e, p, q, kw) ((e)->name_matches_ascii((e), (p), (q), (kw)))

#define D8_COMMON(state, tok) \
    do { \
        if (!(state)->document_entity && (tok) == TS4_XML_TOK_PARAM_ENTITY_REF) \
            return TS4_XML_ROLE_INNER_PARAM_ENTITY_REF; \
        (state)->handler = ts4_fn_888A09C0; \
        return TS4_XML_ROLE_ERROR; \
    } while (0)

#define D8_SET_TOP_LEVEL(state) \
    ((state)->handler = (state)->document_entity ? fn_888A2458 : fn_888A10A0)
#endif
