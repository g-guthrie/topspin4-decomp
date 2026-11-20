/* Derived from Expat 1.95.6 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Swing_DLL.xex 0x888A8898-0x888AA1C8.
 * Family OS2: Expat xmlparse.c doProlog (XML_DTD + XML_NS build, UTF-8 output): the prolog/DTD state machine.
 * The upstream text is kept and the Expat parser members are mapped onto the shared parser layout with macros,
 * as xmlparse.c itself does. One function per file (fn_check resolves $LN labels by name). */
#include "d9ex_xmlparse.h"

#define XML_DTD 1
typedef char XML_Char;
typedef unsigned char XML_Bool;
#define XML_TRUE ((XML_Bool)1)
#define XML_FALSE ((XML_Bool)0)
#define NULL 0
#define XML_T(x) x
#define PTRCALL
#define XML_TOK_TRAILING_RSQB -5
#define XML_TOK_NONE -4
#define XML_TOK_TRAILING_CR -3
#define XML_TOK_PARTIAL_CHAR -2
#define XML_TOK_PARTIAL -1
#define XML_TOK_INVALID 0
#define XML_TOK_START_TAG_WITH_ATTS 1
#define XML_TOK_START_TAG_NO_ATTS 2
#define XML_TOK_EMPTY_ELEMENT_WITH_ATTS 3
#define XML_TOK_EMPTY_ELEMENT_NO_ATTS 4
#define XML_TOK_END_TAG 5
#define XML_TOK_DATA_CHARS 6
#define XML_TOK_DATA_NEWLINE 7
#define XML_TOK_CDATA_SECT_OPEN 8
#define XML_TOK_ENTITY_REF 9
#define XML_TOK_CHAR_REF 10
#define XML_TOK_PI 11
#define XML_TOK_XML_DECL 12
#define XML_TOK_COMMENT 13
#define XML_TOK_BOM 14
#define XML_TOK_PROLOG_S 15
#define XML_TOK_DECL_OPEN 16
#define XML_TOK_DECL_CLOSE 17
#define XML_TOK_NAME 18
#define XML_TOK_NMTOKEN 19
#define XML_TOK_POUND_NAME 20
#define XML_TOK_OR 21
#define XML_TOK_PERCENT 22
#define XML_TOK_OPEN_PAREN 23
#define XML_TOK_CLOSE_PAREN 24
#define XML_TOK_OPEN_BRACKET 25
#define XML_TOK_CLOSE_BRACKET 26
#define XML_TOK_LITERAL 27
#define XML_TOK_PARAM_ENTITY_REF 28
#define XML_TOK_INSTANCE_START 29
#define XML_TOK_NAME_QUESTION 30
#define XML_TOK_NAME_ASTERISK 31
#define XML_TOK_NAME_PLUS 32
#define XML_TOK_COND_SECT_OPEN 33
#define XML_TOK_COND_SECT_CLOSE 34
#define XML_TOK_CLOSE_PAREN_QUESTION 35
#define XML_TOK_CLOSE_PAREN_ASTERISK 36
#define XML_TOK_CLOSE_PAREN_PLUS 37
#define XML_TOK_COMMA 38
#define XML_TOK_ATTRIBUTE_VALUE_S 39
#define XML_TOK_CDATA_SECT_CLOSE 40
#define XML_TOK_PREFIXED_NAME 41
#define XML_TOK_IGNORE_SECT 42

enum XML_Error {
  XML_ERROR_NONE,
  XML_ERROR_NO_MEMORY,
  XML_ERROR_SYNTAX,
  XML_ERROR_NO_ELEMENTS,
  XML_ERROR_INVALID_TOKEN,
  XML_ERROR_UNCLOSED_TOKEN,
  XML_ERROR_PARTIAL_CHAR,
  XML_ERROR_TAG_MISMATCH,
  XML_ERROR_DUPLICATE_ATTRIBUTE,
  XML_ERROR_JUNK_AFTER_DOC_ELEMENT,
  XML_ERROR_PARAM_ENTITY_REF,
  XML_ERROR_UNDEFINED_ENTITY,
  XML_ERROR_RECURSIVE_ENTITY_REF,
  XML_ERROR_ASYNC_ENTITY,
  XML_ERROR_BAD_CHAR_REF,
  XML_ERROR_BINARY_ENTITY_REF,
  XML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF,
  XML_ERROR_MISPLACED_XML_PI,
  XML_ERROR_UNKNOWN_ENCODING,
  XML_ERROR_INCORRECT_ENCODING,
  XML_ERROR_UNCLOSED_CDATA_SECTION,
  XML_ERROR_EXTERNAL_ENTITY_HANDLING,
  XML_ERROR_NOT_STANDALONE,
  XML_ERROR_UNEXPECTED_STATE,
  XML_ERROR_ENTITY_DECLARED_IN_PE,
  XML_ERROR_FEATURE_REQUIRES_XML_DTD,
  XML_ERROR_CANT_CHANGE_FEATURE_ONCE_PARSING
};
enum {
  XML_ROLE_ERROR = -1,
  XML_ROLE_NONE = 0,
  XML_ROLE_XML_DECL,
  XML_ROLE_INSTANCE_START,
  XML_ROLE_DOCTYPE_NONE,
  XML_ROLE_DOCTYPE_NAME,
  XML_ROLE_DOCTYPE_SYSTEM_ID,
  XML_ROLE_DOCTYPE_PUBLIC_ID,
  XML_ROLE_DOCTYPE_INTERNAL_SUBSET,
  XML_ROLE_DOCTYPE_CLOSE,
  XML_ROLE_GENERAL_ENTITY_NAME,
  XML_ROLE_PARAM_ENTITY_NAME,
  XML_ROLE_ENTITY_NONE,
  XML_ROLE_ENTITY_VALUE,
  XML_ROLE_ENTITY_SYSTEM_ID,
  XML_ROLE_ENTITY_PUBLIC_ID,
  XML_ROLE_ENTITY_COMPLETE,
  XML_ROLE_ENTITY_NOTATION_NAME,
  XML_ROLE_NOTATION_NONE,
  XML_ROLE_NOTATION_NAME,
  XML_ROLE_NOTATION_SYSTEM_ID,
  XML_ROLE_NOTATION_NO_SYSTEM_ID,
  XML_ROLE_NOTATION_PUBLIC_ID,
  XML_ROLE_ATTRIBUTE_NAME,
  XML_ROLE_ATTRIBUTE_TYPE_CDATA,
  XML_ROLE_ATTRIBUTE_TYPE_ID,
  XML_ROLE_ATTRIBUTE_TYPE_IDREF,
  XML_ROLE_ATTRIBUTE_TYPE_IDREFS,
  XML_ROLE_ATTRIBUTE_TYPE_ENTITY,
  XML_ROLE_ATTRIBUTE_TYPE_ENTITIES,
  XML_ROLE_ATTRIBUTE_TYPE_NMTOKEN,
  XML_ROLE_ATTRIBUTE_TYPE_NMTOKENS,
  XML_ROLE_ATTRIBUTE_ENUM_VALUE,
  XML_ROLE_ATTRIBUTE_NOTATION_VALUE,
  XML_ROLE_ATTLIST_NONE,
  XML_ROLE_ATTLIST_ELEMENT_NAME,
  XML_ROLE_IMPLIED_ATTRIBUTE_VALUE,
  XML_ROLE_REQUIRED_ATTRIBUTE_VALUE,
  XML_ROLE_DEFAULT_ATTRIBUTE_VALUE,
  XML_ROLE_FIXED_ATTRIBUTE_VALUE,
  XML_ROLE_ELEMENT_NONE,
  XML_ROLE_ELEMENT_NAME,
  XML_ROLE_CONTENT_ANY,
  XML_ROLE_CONTENT_EMPTY,
  XML_ROLE_CONTENT_PCDATA,
  XML_ROLE_GROUP_OPEN,
  XML_ROLE_GROUP_CLOSE,
  XML_ROLE_GROUP_CLOSE_REP,
  XML_ROLE_GROUP_CLOSE_OPT,
  XML_ROLE_GROUP_CLOSE_PLUS,
  XML_ROLE_GROUP_CHOICE,
  XML_ROLE_GROUP_SEQUENCE,
  XML_ROLE_CONTENT_ELEMENT,
  XML_ROLE_CONTENT_ELEMENT_REP,
  XML_ROLE_CONTENT_ELEMENT_OPT,
  XML_ROLE_CONTENT_ELEMENT_PLUS,
  XML_ROLE_PI,
  XML_ROLE_COMMENT,

  XML_ROLE_TEXT_DECL,
  XML_ROLE_IGNORE_SECT,
  XML_ROLE_INNER_PARAM_ENTITY_REF,

  XML_ROLE_PARAM_ENTITY_REF
};
enum XML_Content_Type { XML_CTYPE_EMPTY = 1, XML_CTYPE_ANY, XML_CTYPE_MIXED, XML_CTYPE_NAME, XML_CTYPE_CHOICE, XML_CTYPE_SEQ };
enum XML_Content_Quant { XML_CQUANT_NONE, XML_CQUANT_OPT, XML_CQUANT_REP, XML_CQUANT_PLUS };

typedef struct XML_cp XML_Content;
struct XML_cp {
    enum XML_Content_Type type;
    enum XML_Content_Quant quant;
    char *name;
    unsigned int numchildren;
    XML_Content *children;
};

typedef d9_xml_parser *XML_Parser;
typedef const struct ts4_xml_encoding ENCODING;
typedef d9_entity ENTITY;
#define textPtr text_ptr
#define textLen text_len
#define systemId system_id
#define publicId public_id
typedef ts4_xml_element_type ELEMENT_TYPE;
typedef ts4_xml_attribute_id ATTRIBUTE_ID;
typedef ts4_xml_dtd DTD;

/* Expat parser members */
#define _dtd (parser->dtd)
#define encoding (parser->encoding)
#define eventPtr (parser->event_ptr)
#define eventEndPtr (parser->event_end_ptr)
#define openInternalEntities (parser->open_internal_entities)
#define tempPool (parser->temp_pool)
#define prologState (parser->prolog_state)
#define handlerArg (parser->handler_arg)
#define processor (parser->processor)
#define isParamEntity (parser->is_param_entity)
#define useForeignDTD (parser->use_foreign_dtd)
#define paramEntityParsing (parser->param_entity_parsing)
#define parentParser (parser->parent_parser)
#define curBase (parser->cur_base)
#define groupSize (parser->group_size)
#define groupConnector (*(char **)&parser->group_connector)
#define doctypeName (parser->doctype_name)
#define doctypeSysid (parser->doctype_sysid)
#define doctypePubid (parser->doctype_pubid)
#define declEntity (parser->decl_entity)
#define declElementType (parser->decl_element_type)
#define declAttributeId (parser->decl_attribute_id)
#define declAttributeIsCdata (parser->decl_attribute_is_cdata)
#define declAttributeIsId (parser->decl_attribute_is_id)
#define declAttributeType (parser->decl_attribute_type)
#define declNotationName (parser->decl_notation_name)
#define declNotationPublicId (parser->decl_notation_public_id)
typedef void (*XML_StartDoctypeDeclHandler)(void *, const char *, const char *, const char *, int);
typedef void (*XML_EndDoctypeDeclHandler)(void *);
typedef int (*XML_ExternalEntityRefHandler)(void *, const char *, const char *, const char *, const char *);
typedef int (*XML_NotStandaloneHandler)(void *);
typedef void (*XML_SkippedEntityHandler)(void *, const char *, int);
typedef void (*XML_ElementDeclHandler)(void *, const char *, XML_Content *);
typedef void (*XML_AttlistDeclHandler)(void *, const char *, const char *, const char *, const char *, int);
typedef void (*XML_EntityDeclHandler)(void *, const char *, int, const char *, int, const char *, const char *,
                                     const char *, const char *);
typedef void (*XML_UnparsedEntityDeclHandler)(void *, const char *, const char *, const char *, const char *,
                                             const char *);
typedef void (*XML_NotationDeclHandler)(void *, const char *, const char *, const char *, const char *);
#define startDoctypeDeclHandler ((XML_StartDoctypeDeclHandler)parser->start_doctype_decl_handler)
#define endDoctypeDeclHandler ((XML_EndDoctypeDeclHandler)parser->end_doctype_decl_handler)
#define externalEntityRefHandler ((XML_ExternalEntityRefHandler)parser->external_entity_ref_handler)
#define externalEntityRefHandlerArg (parser->external_entity_ref_handler_arg)
#define notStandaloneHandler ((XML_NotStandaloneHandler)parser->not_standalone_handler)
#define skippedEntityHandler ((XML_SkippedEntityHandler)parser->skipped_entity_handler)
#define elementDeclHandler ((XML_ElementDeclHandler)parser->element_decl_handler)
#define attlistDeclHandler ((XML_AttlistDeclHandler)parser->attlist_decl_handler)
#define entityDeclHandler ((XML_EntityDeclHandler)parser->entity_decl_handler)
#define unparsedEntityDeclHandler ((XML_UnparsedEntityDeclHandler)parser->unparsed_entity_decl_handler)
#define notationDeclHandler ((XML_NotationDeclHandler)parser->notation_decl_handler)
#define defaultHandler (parser->default_handler)
#define defaultExpandInternalEntities (parser->default_expand_internal_entities)
#define MALLOC(s) (parser->malloc_fcn((s)))
#define REALLOC(p, s) (parser->realloc_fcn((p), (s)))
#define contentProcessor ts4_if_call_seq_u32_off90_888A8198
#define ignoreSectionProcessor os2_xml_ignore_section_processor_888A4598

/* The function-local static strings of doProlog are statics of one translation unit, addressed from one base register
 * (the last one, "("): the base is the symbol the original relocates against, the rest are fixed offsets. */

/* DTD / open-entity member names */
#define generalEntities general_entities
#define documentEntity document_entity
#define hasParamEntityRefs has_param_entity_refs
#define paramEntities param_entities
#define keepProcessing keep_processing
#define paramEntityRead param_entity_read
#define scaffIndex scaff_index
#define scaffLevel scaff_level
#define scaffCount scaff_count
#define contentStringLen content_string_len
#define entityValuePool entity_value_pool
#define internalEventPtr internal_event_ptr
#define internalEventEndPtr internal_event_end_ptr

/* encoding methods */
#define XmlPrologTok(enc, ptr, end, nextTokPtr) ((enc)->scanners[0]((enc), (ptr), (end), (nextTokPtr)))
#define XmlTokenRole(state, tok, ptr, end, enc) ((state)->handler((state), (tok), (ptr), (end), (enc)))
#define XmlIsPublicId(enc, ptr, end, badPtr) ((enc)->is_public_id((enc), (ptr), (end), (badPtr)))
#define XmlPredefinedEntityName(enc, ptr, end) ((enc)->predefined_entity_name((enc), (ptr), (end)))
#define minBytesPerChar min_bytes_per_char

/* pool macros */
#define poolStart(pool) ((pool)->start)
#define poolDiscard(pool) ((pool)->ptr = (pool)->start)
#define poolFinish(pool) ((pool)->start = (pool)->ptr)
#define poolLength(pool) ((pool)->ptr - (pool)->start)
#define poolAppendChar(pool, c) \
    (((pool)->ptr == (pool)->end && !ts4_xml_pool_grow_888A2F00(pool)) ? 0 : ((*((pool)->ptr)++ = (c)), 1))
#define poolClear ts4_xml_pool_clear_888A38C8
#define poolAppend ts4_xml_pool_append_888A35A8
#define poolAppendString ts4_xml_pool_append_string_888A3100
#define lookup ts4_xml_lookup_888A5060
#define normalizePublicId ts4_xml_normalize_public_id_888A3CF0
#define getElementType ts4_xml_get_element_type_888A7270
#define getAttributeId ts4_xml_get_attribute_id_888A5608
#define defineAttribute ts4_xml_define_attribute_888A4120
#define storeAttributeValue ts4_xml_store_attribute_value_888A6508
#define storeEntityValue ts4_xml_store_entity_value_888A5BA0
#define nextScaffoldPart ts4_xml_next_scaffold_part_888A2DB8
#define build_model ts4_xml_build_model_888A4F50
#define processXmlDecl ts4_xml_process_xml_decl_888A8340
#define processInternalParamEntity ts4_xml_process_internal_param_entity_888A43C8
#define doIgnoreSection ts4_xml_do_ignore_section_888A4460
#define reportDefault ts4_xml_report_default_888A4278
#define reportProcessingInstruction ts4_xml_report_pi_888A5A78
#define reportComment ts4_xml_report_comment_888A59B8

extern unsigned char ts4_xml_pool_grow_888A2F00(ts4_xml_string_pool *pool);
extern void ts4_xml_pool_clear_888A38C8(ts4_xml_string_pool *pool);
extern char *ts4_xml_pool_append_888A35A8(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc, const char *ptr,
                                          const char *end);
extern char *ts4_if_call_seq_u32_off8_888A4FE0(ts4_xml_string_pool *pool);
extern char *ts4_xml_pool_append_string_888A3100(ts4_xml_string_pool *pool, const char *s);
extern void *ts4_xml_lookup_888A5060(ts4_xml_hash_table *table, const char *name, unsigned int create_size);
/* normalizePublicId is a static leaf function of the original xmlparse.c: the compiler knows from its body that it
 * leaves the argument register alone, so a same-file copy (kept out of line) is needed. */
#ifdef _MSC_VER
__declspec(noinline)
#endif
static void ts4_xml_normalize_public_id_888A3CF0(char *publicId)
{
    char *p = publicId;
    char *s = publicId;
    for (; *s; s++) {
        switch (*s) {
        case 0x20:
        case 0xD:
        case 0xA:
            if (p != publicId && p[-1] != 0x20)
                *p++ = 0x20;
            break;
        default:
            *p++ = *s;
        }
    }
    if (p != publicId && p[-1] == 0x20)
        --p;
    *p = 0;
}
extern ts4_xml_element_type *ts4_xml_get_element_type_888A7270(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                                               const char *ptr, const char *end);
extern ts4_xml_attribute_id *ts4_xml_get_attribute_id_888A5608(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                                               const char *start, const char *end);
extern int ts4_xml_define_attribute_888A4120(ts4_xml_element_type *type, ts4_xml_attribute_id *att_id,
                                             unsigned char is_cdata, unsigned char is_id, const char *value,
                                             d9_xml_parser *parser);
extern int ts4_xml_store_attribute_value_888A6508(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                                  unsigned char is_cdata, const char *ptr, const char *end,
                                                  ts4_xml_string_pool *pool);
extern int ts4_xml_store_entity_value_888A5BA0(d9_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s,
                                               const char *end);
extern int ts4_xml_next_scaffold_part_888A2DB8(d9_xml_parser *parser);
extern XML_Content *ts4_xml_build_model_888A4F50(d9_xml_parser *parser);
extern int ts4_xml_process_xml_decl_888A8340(d9_xml_parser *parser, int is_general_text_entity, const char *s,
                                             const char *next);
extern int ts4_xml_process_internal_param_entity_888A43C8(d9_xml_parser *parser, ENTITY *entity);
extern int ts4_xml_do_ignore_section_888A4460(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                              const char **start_ptr, const char *end, const char **next_ptr);
extern void ts4_xml_report_default_888A4278(d9_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s,
                                            const char *end);
extern int ts4_xml_report_pi_888A5A78(d9_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *start,
                                      const char *end);
extern int ts4_xml_report_comment_888A59B8(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                          const char *start, const char *end);
extern int ts4_if_call_seq_u32_off90_888A8198(d9_xml_parser *parser, const char *s, const char *end,
                                              const char **next_ptr);
extern int os2_xml_ignore_section_processor_888A4598(d9_xml_parser *parser, const char *start, const char *end,
                                                     const char **end_ptr);

#ifdef _MSC_VER
#define OS2_FORCEINLINE static __forceinline
#else
#define OS2_FORCEINLINE static inline
#endif
/* Expat poolStoreString */
OS2_FORCEINLINE char *os2_pool_store_string(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc,
                                            const char *ptr, const char *end)
{
    if (!ts4_xml_pool_append_888A35A8(pool, enc, ptr, end))
        return 0;
    return ts4_if_call_seq_u32_off8_888A4FE0(pool);
}
#define poolStoreString os2_pool_store_string

/* The strings below are statics of the original translation unit; the compiler takes the base register from the symbol
 * table, so statics must precede them in the section (two stand-ins) and every string must exist. */
#ifdef _MSC_VER
#define OS2_PRE_UNUSED
#else
#define OS2_PRE_UNUSED __attribute__((unused))
#endif
static const char OS2_PRE_UNUSED os2_pre_a[4] = {'A','B','C',0};
static const char OS2_PRE_UNUSED os2_pre_b[4] = {'D','E','F',0};
static const XML_Char lbl_880D0640[] = { '#', 0 };
#define externalSubsetName lbl_880D0640
static const XML_Char lbl_880D0644[] = { 'C','D','A','T','A',0 };
#define atypeCDATA lbl_880D0644
static const XML_Char lbl_880D064C[] = { 'I','D',0 };
#define atypeID lbl_880D064C
static const XML_Char lbl_880D0650[] = { 'I','D','R','E','F',0 };
#define atypeIDREF lbl_880D0650
static const XML_Char lbl_880D0658[] = { 'I','D','R','E','F','S',0 };
#define atypeIDREFS lbl_880D0658
static const XML_Char lbl_880D0660[] = { 'E','N','T','I','T','Y',0 };
#define atypeENTITY lbl_880D0660
static const XML_Char lbl_880D0668[] = { 'E','N','T','I','T','I','E','S',0 };
#define atypeENTITIES lbl_880D0668
static const XML_Char lbl_880D0674[] = { 'N','M','T','O','K','E','N',0 };
#define atypeNMTOKEN lbl_880D0674
static const XML_Char lbl_880D067C[] = { 'N','M','T','O','K','E','N','S',0 };
#define atypeNMTOKENS lbl_880D067C
static const XML_Char lbl_880D0688[] = { 'N','O','T','A','T','I','O','N','(',0 };
#define notationPrefix lbl_880D0688
static const XML_Char lbl_880D0694[] = { '|', 0 };
#define enumValueSep lbl_880D0694
static const XML_Char lbl_880D0698[] = { '(', 0 };
#define enumValueStart lbl_880D0698

int os2_xml_do_prolog_888A8898(XML_Parser parser,
         const ENCODING *enc,
         const char *s,
         const char *end,
         int tok,
         const char *next,
         const char **nextPtr)
{

  DTD * const dtd = _dtd;  /* save one level of indirection */

  const char **eventPP;
  const char **eventEndPP;
  enum XML_Content_Quant quant;

  if (enc == encoding) {
    eventPP = &eventPtr;
    eventEndPP = &eventEndPtr;
  }
  else {
    eventPP = &(openInternalEntities->internalEventPtr);
    eventEndPP = &(openInternalEntities->internalEventEndPtr);
  }
  for (;;) {
    int role;
    XML_Bool handleDefault = XML_TRUE;
    *eventPP = s;
    *eventEndPP = next;
    if (tok <= 0) {
      if (nextPtr != 0 && tok != XML_TOK_INVALID) {
        *nextPtr = s;
        return XML_ERROR_NONE;
      }
      switch (tok) {
      case XML_TOK_INVALID:
        *eventPP = next;
        return XML_ERROR_INVALID_TOKEN;
      case XML_TOK_PARTIAL:
        return XML_ERROR_UNCLOSED_TOKEN;
      case XML_TOK_PARTIAL_CHAR:
        return XML_ERROR_PARTIAL_CHAR;
      case XML_TOK_NONE:
#ifdef XML_DTD
        if (enc != encoding)
          return XML_ERROR_NONE;
        if (isParamEntity) {
          if (XmlTokenRole(&prologState, XML_TOK_NONE, end, end, enc)
              == XML_ROLE_ERROR)
            return XML_ERROR_SYNTAX;
          return XML_ERROR_NONE;
        }
#endif /* XML_DTD */
        return XML_ERROR_NO_ELEMENTS;
      default:
        tok = -tok;
        next = end;
        break;
      }
    }
    role = XmlTokenRole(&prologState, tok, s, next, enc);
    switch (role) {
    case XML_ROLE_XML_DECL:
      {
        enum XML_Error result = processXmlDecl(parser, 0, s, next);
        if (result != XML_ERROR_NONE)
          return result;
        enc = encoding;
        handleDefault = XML_FALSE;
      }
      break;
    case XML_ROLE_DOCTYPE_NAME:
      if (startDoctypeDeclHandler) {
        doctypeName = poolStoreString(&tempPool, enc, s, next);
        if (!doctypeName)
          return XML_ERROR_NO_MEMORY;
        poolFinish(&tempPool);
        doctypePubid = NULL;
        handleDefault = XML_FALSE;
      }
      doctypeSysid = NULL; /* always initialize to NULL */
      break;
    case XML_ROLE_DOCTYPE_INTERNAL_SUBSET:
      if (startDoctypeDeclHandler) {
        startDoctypeDeclHandler(handlerArg, doctypeName, doctypeSysid,
                                doctypePubid, 1);
        doctypeName = NULL;
        poolClear(&tempPool);
        handleDefault = XML_FALSE;
      }
      break;
#ifdef XML_DTD
    case XML_ROLE_TEXT_DECL:
      {
        enum XML_Error result = processXmlDecl(parser, 1, s, next);
        if (result != XML_ERROR_NONE)
          return result;
        enc = encoding;
        handleDefault = XML_FALSE;
      }
      break;
#endif /* XML_DTD */
    case XML_ROLE_DOCTYPE_PUBLIC_ID:
#ifdef XML_DTD
      useForeignDTD = XML_FALSE;
#endif /* XML_DTD */
      dtd->hasParamEntityRefs = XML_TRUE;
      if (startDoctypeDeclHandler) {
        doctypePubid = poolStoreString(&tempPool, enc,
                                       s + enc->minBytesPerChar,
                                       next - enc->minBytesPerChar);
        if (!doctypePubid)
          return XML_ERROR_NO_MEMORY;
        poolFinish(&tempPool);
        handleDefault = XML_FALSE;
      }
#ifdef XML_DTD
      declEntity = (ENTITY *)lookup(&dtd->paramEntities,
                                    externalSubsetName,
                                    sizeof(ENTITY));
      if (!declEntity)
        return XML_ERROR_NO_MEMORY;
#endif /* XML_DTD */
      /* fall through */
    case XML_ROLE_ENTITY_PUBLIC_ID:
      if (!XmlIsPublicId(enc, s, next, eventPP))
        return XML_ERROR_SYNTAX;
      if (dtd->keepProcessing && declEntity) {
        XML_Char *tem = poolStoreString(&dtd->pool,
                                        enc,
                                        s + enc->minBytesPerChar,
                                        next - enc->minBytesPerChar);
        if (!tem)
          return XML_ERROR_NO_MEMORY;
        normalizePublicId(tem);
        declEntity->publicId = tem;
        poolFinish(&dtd->pool);
        if (entityDeclHandler)
          handleDefault = XML_FALSE;
      }
      break;
    case XML_ROLE_DOCTYPE_CLOSE:
      if (doctypeName) {
        startDoctypeDeclHandler(handlerArg, doctypeName,
                                doctypeSysid, doctypePubid, 0);
        poolClear(&tempPool);
        handleDefault = XML_FALSE;
      }
      /* doctypeSysid will be non-NULL in the case of a previous
         XML_ROLE_DOCTYPE_SYSTEM_ID, even if startDoctypeDeclHandler
         was not set, indicating an external subset
      */
#ifdef XML_DTD
      if (doctypeSysid || useForeignDTD) {
        dtd->hasParamEntityRefs = XML_TRUE; /* when docTypeSysid == NULL */
        if (paramEntityParsing && externalEntityRefHandler) {
          ENTITY *entity = (ENTITY *)lookup(&dtd->paramEntities,
                                            externalSubsetName,
                                            sizeof(ENTITY));
          if (!entity)
            return XML_ERROR_NO_MEMORY;
          if (useForeignDTD)
            entity->base = curBase;
          dtd->paramEntityRead = XML_FALSE;
          if (!externalEntityRefHandler(externalEntityRefHandlerArg,
                                        0,
                                        entity->base,
                                        entity->systemId,
                                        entity->publicId))
            return XML_ERROR_EXTERNAL_ENTITY_HANDLING;
          if (dtd->paramEntityRead &&
              !dtd->standalone &&
              notStandaloneHandler &&
              !notStandaloneHandler(handlerArg))
            return XML_ERROR_NOT_STANDALONE;
          /* end of DTD - no need to update dtd->keepProcessing */
        }
        useForeignDTD = XML_FALSE;
      }
#endif /* XML_DTD */
      if (endDoctypeDeclHandler) {
        endDoctypeDeclHandler(handlerArg);
        handleDefault = XML_FALSE;
      }
      break;
    case XML_ROLE_INSTANCE_START:
#ifdef XML_DTD
      /* if there is no DOCTYPE declaration then now is the
         last chance to read the foreign DTD
      */
      if (useForeignDTD) {
        dtd->hasParamEntityRefs = XML_TRUE;
        if (paramEntityParsing && externalEntityRefHandler) {
          ENTITY *entity = (ENTITY *)lookup(&dtd->paramEntities,
                                            externalSubsetName,
                                            sizeof(ENTITY));
          if (!entity)
            return XML_ERROR_NO_MEMORY;
          entity->base = curBase;
          dtd->paramEntityRead = XML_FALSE;
          if (!externalEntityRefHandler(externalEntityRefHandlerArg,
                                        0,
                                        entity->base,
                                        entity->systemId,
                                        entity->publicId))
            return XML_ERROR_EXTERNAL_ENTITY_HANDLING;
          if (dtd->paramEntityRead &&
              !dtd->standalone &&
              notStandaloneHandler &&
              !notStandaloneHandler(handlerArg))
            return XML_ERROR_NOT_STANDALONE;
          /* end of DTD - no need to update dtd->keepProcessing */
        }
      }
#endif /* XML_DTD */
      processor = contentProcessor;
      return contentProcessor(parser, s, end, nextPtr);
    case XML_ROLE_ATTLIST_ELEMENT_NAME:
      declElementType = getElementType(parser, enc, s, next);
      if (!declElementType)
        return XML_ERROR_NO_MEMORY;
      goto LN_checkAttListDeclHandler;
    case XML_ROLE_ATTRIBUTE_NAME:
      declAttributeId = getAttributeId(parser, enc, s, next);
      if (!declAttributeId)
        return XML_ERROR_NO_MEMORY;
      declAttributeIsCdata = XML_FALSE;
      declAttributeType = NULL;
      declAttributeIsId = XML_FALSE;
      goto LN_checkAttListDeclHandler;
    case XML_ROLE_ATTRIBUTE_TYPE_CDATA:
      declAttributeIsCdata = XML_TRUE;
      declAttributeType = atypeCDATA;
      goto LN_checkAttListDeclHandler;
    case XML_ROLE_ATTRIBUTE_TYPE_ID:
      declAttributeIsId = XML_TRUE;
      declAttributeType = atypeID;
      goto LN_checkAttListDeclHandler;
    case XML_ROLE_ATTRIBUTE_TYPE_IDREF:
      declAttributeType = atypeIDREF;
      goto LN_checkAttListDeclHandler;
    case XML_ROLE_ATTRIBUTE_TYPE_IDREFS:
      declAttributeType = atypeIDREFS;
      goto LN_checkAttListDeclHandler;
    case XML_ROLE_ATTRIBUTE_TYPE_ENTITY:
      declAttributeType = atypeENTITY;
      goto LN_checkAttListDeclHandler;
    case XML_ROLE_ATTRIBUTE_TYPE_ENTITIES:
      declAttributeType = atypeENTITIES;
      goto LN_checkAttListDeclHandler;
    case XML_ROLE_ATTRIBUTE_TYPE_NMTOKEN:
      declAttributeType = atypeNMTOKEN;
      goto LN_checkAttListDeclHandler;
    case XML_ROLE_ATTRIBUTE_TYPE_NMTOKENS:
      declAttributeType = atypeNMTOKENS;
    LN_checkAttListDeclHandler:
      if (dtd->keepProcessing && attlistDeclHandler)
        handleDefault = XML_FALSE;
      break;
    case XML_ROLE_ATTRIBUTE_ENUM_VALUE:
    case XML_ROLE_ATTRIBUTE_NOTATION_VALUE:
      if (dtd->keepProcessing && attlistDeclHandler) {
        const XML_Char *prefix;
        if (declAttributeType) {
          prefix = enumValueSep;
        }
        else {
          prefix = (role == XML_ROLE_ATTRIBUTE_NOTATION_VALUE
                    ? notationPrefix
                    : enumValueStart);
        }
        if (!poolAppendString(&tempPool, prefix))
          return XML_ERROR_NO_MEMORY;
        if (!poolAppend(&tempPool, enc, s, next))
          return XML_ERROR_NO_MEMORY;
        declAttributeType = tempPool.start;
        handleDefault = XML_FALSE;
      }
      break;
    case XML_ROLE_IMPLIED_ATTRIBUTE_VALUE:
    case XML_ROLE_REQUIRED_ATTRIBUTE_VALUE:
      if (dtd->keepProcessing) {
        if (!defineAttribute(declElementType, declAttributeId,
                              declAttributeIsCdata, declAttributeIsId, 0,
                              parser))
          return XML_ERROR_NO_MEMORY;
        if (attlistDeclHandler && declAttributeType) {
          if (*declAttributeType == XML_T('(')
              || (*declAttributeType == XML_T('N')
                  && declAttributeType[1] == XML_T('O'))) {
            /* Enumerated or Notation type */
            if (!poolAppendChar(&tempPool, XML_T(')'))
                || !poolAppendChar(&tempPool, XML_T('\0')))
              return XML_ERROR_NO_MEMORY;
            declAttributeType = tempPool.start;
            poolFinish(&tempPool);
          }
          *eventEndPP = s;
          attlistDeclHandler(handlerArg, declElementType->name,
                             declAttributeId->name, declAttributeType,
                             0, role == XML_ROLE_REQUIRED_ATTRIBUTE_VALUE);
          poolClear(&tempPool);
          handleDefault = XML_FALSE;
        }
      }
      break;
    case XML_ROLE_DEFAULT_ATTRIBUTE_VALUE:
    case XML_ROLE_FIXED_ATTRIBUTE_VALUE:
      if (dtd->keepProcessing) {
        const XML_Char *attVal;
        enum XML_Error result
          = storeAttributeValue(parser, enc, declAttributeIsCdata,
                                s + enc->minBytesPerChar,
                                next - enc->minBytesPerChar,
                                &dtd->pool);
        if (result)
          return result;
        attVal = poolStart(&dtd->pool);
        poolFinish(&dtd->pool);
        /* ID attributes aren't allowed to have a default */
        if (!defineAttribute(declElementType, declAttributeId,
                             declAttributeIsCdata, XML_FALSE, attVal, parser))
          return XML_ERROR_NO_MEMORY;
        if (attlistDeclHandler && declAttributeType) {
          if (*declAttributeType == XML_T('(')
              || (*declAttributeType == XML_T('N')
                  && declAttributeType[1] == XML_T('O'))) {
            /* Enumerated or Notation type */
            if (!poolAppendChar(&tempPool, XML_T(')'))
                || !poolAppendChar(&tempPool, XML_T('\0')))
              return XML_ERROR_NO_MEMORY;
            declAttributeType = tempPool.start;
            poolFinish(&tempPool);
          }
          *eventEndPP = s;
          attlistDeclHandler(handlerArg, declElementType->name,
                             declAttributeId->name, declAttributeType,
                             attVal,
                             role == XML_ROLE_FIXED_ATTRIBUTE_VALUE);
          poolClear(&tempPool);
          handleDefault = XML_FALSE;
        }
      }
      break;
    case XML_ROLE_ENTITY_VALUE:
      if (dtd->keepProcessing) {
        enum XML_Error result = storeEntityValue(parser, enc,
                                            s + enc->minBytesPerChar,
                                            next - enc->minBytesPerChar);
        if (declEntity) {
          declEntity->textPtr = poolStart(&dtd->entityValuePool);
          declEntity->textLen = poolLength(&dtd->entityValuePool);
          poolFinish(&dtd->entityValuePool);
          if (entityDeclHandler) {
            *eventEndPP = s;
            entityDeclHandler(handlerArg,
                              declEntity->name,
                              declEntity->is_param,
                              declEntity->textPtr,
                              declEntity->textLen,
                              curBase, 0, 0, 0);
            handleDefault = XML_FALSE;
          }
        }
        else
          poolDiscard(&dtd->entityValuePool);
        if (result != XML_ERROR_NONE)
          return result;
      }
      break;
    case XML_ROLE_DOCTYPE_SYSTEM_ID:
#ifdef XML_DTD
      useForeignDTD = XML_FALSE;
#endif /* XML_DTD */
      dtd->hasParamEntityRefs = XML_TRUE;
      if (startDoctypeDeclHandler) {
        doctypeSysid = poolStoreString(&tempPool, enc,
                                       s + enc->minBytesPerChar,
                                       next - enc->minBytesPerChar);
        if (doctypeSysid == NULL)
          return XML_ERROR_NO_MEMORY;
        poolFinish(&tempPool);
        handleDefault = XML_FALSE;
      }
#ifdef XML_DTD
      else
        /* use externalSubsetName to make doctypeSysid non-NULL
           for the case where no startDoctypeDeclHandler is set */
        doctypeSysid = externalSubsetName;
#endif /* XML_DTD */
      if (!dtd->standalone
#ifdef XML_DTD
          && !paramEntityParsing
#endif /* XML_DTD */
          && notStandaloneHandler
          && !notStandaloneHandler(handlerArg))
        return XML_ERROR_NOT_STANDALONE;
#ifndef XML_DTD
      break;
#else /* XML_DTD */
      if (!declEntity) {
        declEntity = (ENTITY *)lookup(&dtd->paramEntities,
                                      externalSubsetName,
                                      sizeof(ENTITY));
        if (!declEntity)
          return XML_ERROR_NO_MEMORY;
        declEntity->publicId = NULL;
      }
      /* fall through */
#endif /* XML_DTD */
    case XML_ROLE_ENTITY_SYSTEM_ID:
      if (dtd->keepProcessing && declEntity) {
        declEntity->systemId = poolStoreString(&dtd->pool, enc,
                                               s + enc->minBytesPerChar,
                                               next - enc->minBytesPerChar);
        if (!declEntity->systemId)
          return XML_ERROR_NO_MEMORY;
        declEntity->base = curBase;
        poolFinish(&dtd->pool);
        if (entityDeclHandler)
          handleDefault = XML_FALSE;
      }
      break;
    case XML_ROLE_ENTITY_COMPLETE:
      if (dtd->keepProcessing && declEntity && entityDeclHandler) {
        *eventEndPP = s;
        entityDeclHandler(handlerArg,
                          declEntity->name,
                          declEntity->is_param,
                          0,0,
                          declEntity->base,
                          declEntity->systemId,
                          declEntity->publicId,
                          0);
        handleDefault = XML_FALSE;
      }
      break;
    case XML_ROLE_ENTITY_NOTATION_NAME:
      if (dtd->keepProcessing && declEntity) {
        declEntity->notation = poolStoreString(&dtd->pool, enc, s, next);
        if (!declEntity->notation)
          return XML_ERROR_NO_MEMORY;
        poolFinish(&dtd->pool);
        if (unparsedEntityDeclHandler) {
          *eventEndPP = s;
          unparsedEntityDeclHandler(handlerArg,
                                    declEntity->name,
                                    declEntity->base,
                                    declEntity->systemId,
                                    declEntity->publicId,
                                    declEntity->notation);
          handleDefault = XML_FALSE;
        }
        else if (entityDeclHandler) {
          *eventEndPP = s;
          entityDeclHandler(handlerArg,
                            declEntity->name,
                            0,0,0,
                            declEntity->base,
                            declEntity->systemId,
                            declEntity->publicId,
                            declEntity->notation);
          handleDefault = XML_FALSE;
        }
      }
      break;
    case XML_ROLE_GENERAL_ENTITY_NAME:
      {
        if (XmlPredefinedEntityName(enc, s, next)) {
          declEntity = NULL;
          break;
        }
        if (dtd->keepProcessing) {
          const XML_Char *name = poolStoreString(&dtd->pool, enc, s, next);
          if (!name)
            return XML_ERROR_NO_MEMORY;
          declEntity = (ENTITY *)lookup(&dtd->generalEntities, name,
                                        sizeof(ENTITY));
          if (!declEntity)
            return XML_ERROR_NO_MEMORY;
          if (declEntity->name != name) {
            poolDiscard(&dtd->pool);
            declEntity = NULL;
          }
          else {
            poolFinish(&dtd->pool);
            declEntity->publicId = NULL;
            declEntity->is_param = XML_FALSE;
            /* if we have a parent parser or are reading an internal parameter
               entity, then the entity declaration is not considered "internal"
            */
            declEntity->is_internal = !(parentParser || openInternalEntities);
            if (entityDeclHandler)
              handleDefault = XML_FALSE;
          }
        }
        else {
          poolDiscard(&dtd->pool);
          declEntity = NULL;
        }
      }
      break;
    case XML_ROLE_PARAM_ENTITY_NAME:
#ifdef XML_DTD
      if (dtd->keepProcessing) {
        const XML_Char *name = poolStoreString(&dtd->pool, enc, s, next);
        if (!name)
          return XML_ERROR_NO_MEMORY;
        declEntity = (ENTITY *)lookup(&dtd->paramEntities,
                                           name, sizeof(ENTITY));
        if (!declEntity)
          return XML_ERROR_NO_MEMORY;
        if (declEntity->name != name) {
          poolDiscard(&dtd->pool);
          declEntity = NULL;
        }
        else {
          poolFinish(&dtd->pool);
          declEntity->publicId = NULL;
          declEntity->is_param = XML_TRUE;
          /* if we have a parent parser or are reading an internal parameter
             entity, then the entity declaration is not considered "internal"
          */
          declEntity->is_internal = !(parentParser || openInternalEntities);
          if (entityDeclHandler)
            handleDefault = XML_FALSE;
        }
      }
      else {
        poolDiscard(&dtd->pool);
        declEntity = NULL;
      }
#else /* not XML_DTD */
      declEntity = NULL;
#endif /* XML_DTD */
      break;
    case XML_ROLE_NOTATION_NAME:
      declNotationPublicId = NULL;
      declNotationName = NULL;
      if (notationDeclHandler) {
        declNotationName = poolStoreString(&tempPool, enc, s, next);
        if (!declNotationName)
          return XML_ERROR_NO_MEMORY;
        poolFinish(&tempPool);
        handleDefault = XML_FALSE;
      }
      break;
    case XML_ROLE_NOTATION_PUBLIC_ID:
      if (!XmlIsPublicId(enc, s, next, eventPP))
        return XML_ERROR_SYNTAX;
      if (declNotationName) {  /* means notationDeclHandler != NULL */
        XML_Char *tem = poolStoreString(&tempPool,
                                        enc,
                                        s + enc->minBytesPerChar,
                                        next - enc->minBytesPerChar);
        if (!tem)
          return XML_ERROR_NO_MEMORY;
        normalizePublicId(tem);
        declNotationPublicId = tem;
        poolFinish(&tempPool);
        handleDefault = XML_FALSE;
      }
      break;
    case XML_ROLE_NOTATION_SYSTEM_ID:
      if (declNotationName && notationDeclHandler) {
        const XML_Char *systemId
          = poolStoreString(&tempPool, enc,
                            s + enc->minBytesPerChar,
                            next - enc->minBytesPerChar);
        if (!systemId)
          return XML_ERROR_NO_MEMORY;
        *eventEndPP = s;
        notationDeclHandler(handlerArg,
                            declNotationName,
                            curBase,
                            systemId,
                            declNotationPublicId);
        handleDefault = XML_FALSE;
      }
      poolClear(&tempPool);
      break;
    case XML_ROLE_NOTATION_NO_SYSTEM_ID:
      if (declNotationPublicId && notationDeclHandler) {
        *eventEndPP = s;
        notationDeclHandler(handlerArg,
                            declNotationName,
                            curBase,
                            0,
                            declNotationPublicId);
        handleDefault = XML_FALSE;
      }
      poolClear(&tempPool);
      break;
    case XML_ROLE_ERROR:
      switch (tok) {
      case XML_TOK_PARAM_ENTITY_REF:
        return XML_ERROR_PARAM_ENTITY_REF;
      case XML_TOK_XML_DECL:
        return XML_ERROR_MISPLACED_XML_PI;
      default:
        return XML_ERROR_SYNTAX;
      }
#ifdef XML_DTD
    case XML_ROLE_IGNORE_SECT:
      {
        enum XML_Error result;
        if (defaultHandler)
          reportDefault(parser, enc, s, next);
        handleDefault = XML_FALSE;
        result = doIgnoreSection(parser, enc, &next, end, nextPtr);
        if (!next) {
          processor = ignoreSectionProcessor;
          return result;
        }
      }
      break;
#endif /* XML_DTD */
    case XML_ROLE_GROUP_OPEN:
      if (prologState.level >= groupSize) {
        if (groupSize) {
          char *temp = (char *)REALLOC(groupConnector, groupSize *= 2);
          if (temp == NULL)
            return XML_ERROR_NO_MEMORY;
          groupConnector = temp;
          if (dtd->scaffIndex) {
            int *temp = (int *)REALLOC(dtd->scaffIndex,
                          groupSize * sizeof(int));
            if (temp == NULL)
              return XML_ERROR_NO_MEMORY;
            dtd->scaffIndex = temp;
          }
        }
        else {
          groupConnector = (char *)MALLOC(groupSize = 32);
          if (!groupConnector)
            return XML_ERROR_NO_MEMORY;
        }
      }
      groupConnector[prologState.level] = 0;
      if (dtd->in_eldecl) {
        int myindex = nextScaffoldPart(parser);
        if (myindex < 0)
          return XML_ERROR_NO_MEMORY;
        dtd->scaffIndex[dtd->scaffLevel] = myindex;
        dtd->scaffLevel++;
        dtd->scaffold[myindex].type = XML_CTYPE_SEQ;
        if (elementDeclHandler)
          handleDefault = XML_FALSE;
      }
      break;
    case XML_ROLE_GROUP_SEQUENCE:
      if (groupConnector[prologState.level] == '|')
        return XML_ERROR_SYNTAX;
      groupConnector[prologState.level] = ',';
      if (dtd->in_eldecl && elementDeclHandler)
        handleDefault = XML_FALSE;
      break;
    case XML_ROLE_GROUP_CHOICE:
      if (groupConnector[prologState.level] == ',')
        return XML_ERROR_SYNTAX;
      if (dtd->in_eldecl
          && !groupConnector[prologState.level]
          && (dtd->scaffold[dtd->scaffIndex[dtd->scaffLevel - 1]].type
              != XML_CTYPE_MIXED)
          ) {
        dtd->scaffold[dtd->scaffIndex[dtd->scaffLevel - 1]].type
            = XML_CTYPE_CHOICE;
        if (elementDeclHandler)
          handleDefault = XML_FALSE;
      }
      groupConnector[prologState.level] = '|';
      break;
    case XML_ROLE_PARAM_ENTITY_REF:
#ifdef XML_DTD
    case XML_ROLE_INNER_PARAM_ENTITY_REF:
      /* PE references in internal subset are
         not allowed within declarations      */
      if (prologState.documentEntity &&
          role == XML_ROLE_INNER_PARAM_ENTITY_REF)
        return XML_ERROR_PARAM_ENTITY_REF;
      dtd->hasParamEntityRefs = XML_TRUE;
      if (!paramEntityParsing)
        dtd->keepProcessing = dtd->standalone;
      else {
        const XML_Char *name;
        ENTITY *entity;
        name = poolStoreString(&dtd->pool, enc,
                                s + enc->minBytesPerChar,
                                next - enc->minBytesPerChar);
        if (!name)
          return XML_ERROR_NO_MEMORY;
        entity = (ENTITY *)lookup(&dtd->paramEntities, name, 0);
        poolDiscard(&dtd->pool);
        /* first, determine if a check for an existing declaration is needed;
           if yes, check that the entity exists, and that it is internal,
           otherwise call the skipped entity handler
        */
        if (prologState.documentEntity &&
            (dtd->standalone
             ? !openInternalEntities
             : !dtd->hasParamEntityRefs)) {
          if (!entity)
            return XML_ERROR_UNDEFINED_ENTITY;
          else if (!entity->is_internal)
            return XML_ERROR_ENTITY_DECLARED_IN_PE;
        }
        else if (!entity) {
          dtd->keepProcessing = dtd->standalone;
          /* cannot report skipped entities in declarations */
          if ((role == XML_ROLE_PARAM_ENTITY_REF) && skippedEntityHandler) {
            skippedEntityHandler(handlerArg, name, 1);
            handleDefault = XML_FALSE;
          }
          break;
        }
        if (entity->open)
          return XML_ERROR_RECURSIVE_ENTITY_REF;
        if (entity->textPtr) {
          enum XML_Error result;
          result = processInternalParamEntity(parser, entity);
          if (result != XML_ERROR_NONE)
            return result;
          handleDefault = XML_FALSE;
          break;
        }
        if (externalEntityRefHandler) {
          dtd->paramEntityRead = XML_FALSE;
          entity->open = XML_TRUE;
          if (!externalEntityRefHandler(externalEntityRefHandlerArg,
                                        0,
                                        entity->base,
                                        entity->systemId,
                                        entity->publicId)) {
            entity->open = XML_FALSE;
            return XML_ERROR_EXTERNAL_ENTITY_HANDLING;
          }
          entity->open = XML_FALSE;
          handleDefault = XML_FALSE;
          if (!dtd->paramEntityRead) {
            dtd->keepProcessing = dtd->standalone;
            break;
          }
        }
        else {
          dtd->keepProcessing = dtd->standalone;
          break;
        }
      }
#endif /* XML_DTD */
      if (!dtd->standalone &&
          notStandaloneHandler &&
          !notStandaloneHandler(handlerArg))
        return XML_ERROR_NOT_STANDALONE;
      break;

    /* Element declaration stuff */

    case XML_ROLE_ELEMENT_NAME:
      if (elementDeclHandler) {
        declElementType = getElementType(parser, enc, s, next);
        if (!declElementType)
          return XML_ERROR_NO_MEMORY;
        dtd->scaffLevel = 0;
        dtd->scaffCount = 0;
        dtd->in_eldecl = XML_TRUE;
        handleDefault = XML_FALSE;
      }
      break;

    case XML_ROLE_CONTENT_ANY:
    case XML_ROLE_CONTENT_EMPTY:
      if (dtd->in_eldecl) {
        if (elementDeclHandler) {
          XML_Content * content = (XML_Content *) MALLOC(sizeof(XML_Content));
          if (!content)
            return XML_ERROR_NO_MEMORY;
          content->quant = XML_CQUANT_NONE;
          content->name = NULL;
          content->numchildren = 0;
          content->children = NULL;
          content->type = ((role == XML_ROLE_CONTENT_ANY) ?
                           XML_CTYPE_ANY :
                           XML_CTYPE_EMPTY);
          *eventEndPP = s;
          elementDeclHandler(handlerArg, declElementType->name, content);
          handleDefault = XML_FALSE;
        }
        dtd->in_eldecl = XML_FALSE;
      }
      break;

    case XML_ROLE_CONTENT_PCDATA:
      if (dtd->in_eldecl) {
        dtd->scaffold[dtd->scaffIndex[dtd->scaffLevel - 1]].type
            = XML_CTYPE_MIXED;
        if (elementDeclHandler)
          handleDefault = XML_FALSE;
      }
      break;

    case XML_ROLE_CONTENT_ELEMENT:
      quant = XML_CQUANT_NONE;
      goto LN_elementContent;
    case XML_ROLE_CONTENT_ELEMENT_OPT:
      quant = XML_CQUANT_OPT;
      goto LN_elementContent;
    case XML_ROLE_CONTENT_ELEMENT_REP:
      quant = XML_CQUANT_REP;
      goto LN_elementContent;
    case XML_ROLE_CONTENT_ELEMENT_PLUS:
      quant = XML_CQUANT_PLUS;
    LN_elementContent:
      if (dtd->in_eldecl) {
        ELEMENT_TYPE *el;
        const XML_Char *name;
        int nameLen;
        const char *nxt = (quant == XML_CQUANT_NONE
                           ? next
                           : next - enc->minBytesPerChar);
        int myindex = nextScaffoldPart(parser);
        if (myindex < 0)
          return XML_ERROR_NO_MEMORY;
        dtd->scaffold[myindex].type = XML_CTYPE_NAME;
        dtd->scaffold[myindex].quant = quant;
        el = getElementType(parser, enc, s, nxt);
        if (!el)
          return XML_ERROR_NO_MEMORY;
        name = el->name;
        dtd->scaffold[myindex].name = name;
        nameLen = 0;
        for (; name[nameLen++]; );
        dtd->contentStringLen +=  nameLen;
        if (elementDeclHandler)
          handleDefault = XML_FALSE;
      }
      break;

    case XML_ROLE_GROUP_CLOSE:
      quant = XML_CQUANT_NONE;
      goto LN_closeGroup;
    case XML_ROLE_GROUP_CLOSE_OPT:
      quant = XML_CQUANT_OPT;
      goto LN_closeGroup;
    case XML_ROLE_GROUP_CLOSE_REP:
      quant = XML_CQUANT_REP;
      goto LN_closeGroup;
    case XML_ROLE_GROUP_CLOSE_PLUS:
      quant = XML_CQUANT_PLUS;
    LN_closeGroup:
      if (dtd->in_eldecl) {
        if (elementDeclHandler)
          handleDefault = XML_FALSE;
        dtd->scaffLevel--;
        dtd->scaffold[dtd->scaffIndex[dtd->scaffLevel]].quant = quant;
        if (dtd->scaffLevel == 0) {
          if (!handleDefault) {
            XML_Content *model = build_model(parser);
            if (!model)
              return XML_ERROR_NO_MEMORY;
            *eventEndPP = s;
            elementDeclHandler(handlerArg, declElementType->name, model);
          }
          dtd->in_eldecl = XML_FALSE;
          dtd->contentStringLen = 0;
        }
      }
      break;
      /* End element declaration stuff */

    case XML_ROLE_PI:
      if (!reportProcessingInstruction(parser, enc, s, next))
        return XML_ERROR_NO_MEMORY;
      handleDefault = XML_FALSE;
      break;
    case XML_ROLE_COMMENT:
      if (!reportComment(parser, enc, s, next))
        return XML_ERROR_NO_MEMORY;
      handleDefault = XML_FALSE;
      break;
    case XML_ROLE_NONE:
      switch (tok) {
      case XML_TOK_BOM:
        handleDefault = XML_FALSE;
        break;
      }
      break;
    case XML_ROLE_DOCTYPE_NONE:
      if (startDoctypeDeclHandler)
        handleDefault = XML_FALSE;
      break;
    case XML_ROLE_ENTITY_NONE:
      if (dtd->keepProcessing && entityDeclHandler)
        handleDefault = XML_FALSE;
      break;
    case XML_ROLE_NOTATION_NONE:
      if (notationDeclHandler)
        handleDefault = XML_FALSE;
      break;
    case XML_ROLE_ATTLIST_NONE:
      if (dtd->keepProcessing && attlistDeclHandler)
        handleDefault = XML_FALSE;
      break;
    case XML_ROLE_ELEMENT_NONE:
      if (elementDeclHandler)
        handleDefault = XML_FALSE;
      break;
    } /* end of big switch */

    if (handleDefault && defaultHandler)
      reportDefault(parser, enc, s, next);

    s = next;
    tok = XmlPrologTok(enc, s, end, &next);
  }
  /* not reached */
}

