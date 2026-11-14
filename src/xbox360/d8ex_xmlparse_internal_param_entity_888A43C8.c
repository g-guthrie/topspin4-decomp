/* Swing_DLL.xex 0x888A43C8-0x888A4460, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

extern int fn_888A8898(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s, const char *end,
                       int tok, const char *next, const char **next_ptr);

/* Expat processInternalParamEntity (run doProlog over an internal parameter entity's text). */
int ts4_xml_process_internal_param_entity_888A43C8(d8_xml_parser *parser, d8_entity *entity)
{
    const char *s;
    const char *end;
    const char *next;
    int tok;
    int result;
    d8_open_entity open_entity;

    entity->open = 1;
    open_entity.next = parser->open_internal_entities;
    parser->open_internal_entities = &open_entity;
    open_entity.entity = entity;
    open_entity.internal_event_ptr = 0;
    open_entity.internal_event_end_ptr = 0;
    s = entity->text_ptr;
    end = entity->text_ptr + entity->text_len;
    tok = parser->internal_encoding->scanners[0](parser->internal_encoding, s, end, &next);
    result = fn_888A8898(parser, parser->internal_encoding, s, end, tok, next, 0);
    entity->open = 0;
    parser->open_internal_entities = open_entity.next;
    return result;
}
