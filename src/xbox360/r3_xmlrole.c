/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "r3_xmlrole.h"

/* Keyword string tables in .rdata (Expat KW_* arrays), accessed through their base. */
extern const char lbl_880D0594[];
extern const char lbl_880D05F8[];
extern const char lbl_880D05E4[];
extern const char lbl_880D0554[];
extern const char *const lbl_88C6ADE4[8]; /* ATTLIST type keywords: CDATA, ID, IDREF, IDREFS, ENTITY, ENTITIES, NMTOKEN, NMTOKENS */

/* Handlers referenced by address (placeholders for functions outside this file). */
extern int ts4_fn_888A09C0(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A0BB0(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A1200(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A19F0(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A0F08(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A0E38(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A0C10(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A2150(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A21B0(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A16C0(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A1E30(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);
extern int fn_888A1E90(struct ts4_prolog_state *, int, const char *, const char *, const struct ts4_xml_encoding *);

#define TS4_NAME_MATCHES(enc, ptr, end, kw) ((enc)->name_matches_ascii((enc), (ptr), (end), (kw)))

/* Expat common(): inner parameter-entity ref outside the document entity, else error state. */
#define TS4_ROLE_COMMON(state, tok, error_handler) \
    do { \
        if (!(state)->document_entity && (tok) == TS4_XML_TOK_PARAM_ENTITY_REF) \
            return TS4_XML_ROLE_INNER_PARAM_ENTITY_REF; \
        (state)->handler = (error_handler); \
        return TS4_XML_ROLE_ERROR; \
    } while (0)


/* ENTITY declaration after the name: SYSTEM / PUBLIC keyword or literal value (Expat entity4 shape).
 * Parameters: function name, handler after SYSTEM, handler after PUBLIC. */
#define TS4_DEFINE_ENTITY_EXTERNAL_STATE(name, system_handler, public_handler) \
int name(struct ts4_prolog_state *state, int tok, const char *ptr, const char *end, \
         const struct ts4_xml_encoding *enc) \
{ \
    switch (tok) { \
    case TS4_XML_TOK_PROLOG_S: \
        return 11; \
    case TS4_XML_TOK_NAME: \
        if (TS4_NAME_MATCHES(enc, ptr, end, lbl_880D05F8 + 0x14)) { \
            state->handler = system_handler; \
            return 11; \
        } \
        if (TS4_NAME_MATCHES(enc, ptr, end, lbl_880D05F8)) { \
            state->handler = public_handler; \
            return 11; \
        } \
        break; \
    case TS4_XML_TOK_LITERAL: \
        state->handler = fn_888A1200; \
        state->role_none = 11; \
        return 12; \
    } \
    TS4_ROLE_COMMON(state, tok, ts4_fn_888A09C0); \
}

/* Swing_DLL.xex 0x888A1EF0 */
TS4_DEFINE_ENTITY_EXTERNAL_STATE(ts4_prolog_entity_external_or_value_888A1EF0, fn_888A1E30, fn_888A1E90)
/* Swing_DLL.xex 0x888A2210 */
TS4_DEFINE_ENTITY_EXTERNAL_STATE(ts4_prolog_entity_external_or_value_888A2210, fn_888A2150, fn_888A21B0)

/* ATTLIST attribute type: CDATA/ID/IDREF/... keyword table, NOTATION, or enumeration.
 * Swing_DLL.xex 0x888A0F78 (Expat attlist2 shape) */
int ts4_prolog_attlist_type_888A0F78(struct ts4_prolog_state *state, int tok, const char *ptr,
                                     const char *end, const struct ts4_xml_encoding *enc)
{
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 33;
    case TS4_XML_TOK_NAME: {
        int i;
        for (i = 0; i < 8; i++) {
            if (TS4_NAME_MATCHES(enc, ptr, end, lbl_88C6ADE4[i])) {
                state->handler = fn_888A0C10;
                return 23 + i;
            }
        }
        if (TS4_NAME_MATCHES(enc, ptr, end, lbl_880D05E4)) {
            state->handler = fn_888A0E38;
            return 33;
        }
        break;
    }
    case 23:
        state->handler = fn_888A0F08;
        return 33;
    }
    TS4_ROLE_COMMON(state, tok, ts4_fn_888A09C0);
}

/* ELEMENT declaration content spec: EMPTY / ANY keyword or opening group.
 * Swing_DLL.xex 0x888A1858 (Expat element1 shape) */
int ts4_prolog_element_content_spec_888A1858(struct ts4_prolog_state *state, int tok, const char *ptr,
                                             const char *end, const struct ts4_xml_encoding *enc)
{
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 39;
    case TS4_XML_TOK_NAME:
        if (TS4_NAME_MATCHES(enc, ptr, end, lbl_880D0554 + 0x24)) {
            state->handler = fn_888A1200;
            state->role_none = 39;
            return 42;
        }
        if (TS4_NAME_MATCHES(enc, ptr, end, lbl_880D0554)) {
            state->handler = fn_888A1200;
            state->role_none = 39;
            return 41;
        }
        break;
    case 23:
        state->handler = fn_888A16C0;
        state->level = 1;
        return 44;
    }
    TS4_ROLE_COMMON(state, tok, ts4_fn_888A09C0);
}
