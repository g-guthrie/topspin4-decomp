/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef R3_XMLROLE_H
#define R3_XMLROLE_H
#include "r3_xmltok.h"

/* Expat xmlrole.c style prolog state machine (token -> role). */
struct ts4_prolog_state;
typedef int (*ts4_prolog_handler)(struct ts4_prolog_state *state, int tok, const char *ptr,
                                  const char *end, const struct ts4_xml_encoding *enc);

struct ts4_prolog_state {
    ts4_prolog_handler handler;   /* +0x00 */
    unsigned int level;           /* +0x04 */
    int role_none;                /* +0x08 */
    unsigned int include_level;   /* +0x0C */
    int document_entity;          /* +0x10 */
    int in_entity_value;          /* +0x14 */
};

/* Expat XML_TOK_* codes used by the prolog handlers. */
#define TS4_XML_TOK_PROLOG_S 15
#define TS4_XML_TOK_DECL_CLOSE 17
#define TS4_XML_TOK_NAME 18
#define TS4_XML_TOK_POUND_NAME 20
#define TS4_XML_TOK_LITERAL 27
#define TS4_XML_TOK_PARAM_ENTITY_REF 28

#define TS4_XML_ROLE_ERROR (-1)
#define TS4_XML_ROLE_INNER_PARAM_ENTITY_REF 59
#endif
