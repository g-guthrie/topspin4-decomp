/* Swing_DLL.xex 0x888A8698-0x888A8844, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

extern int ts4_if_call_seq_u32_off90_888A70B0(d8_xml_parser *parser, const char *s, const char *end,
                                              const char **next_ptr);
extern int fn_888A8340(d8_xml_parser *parser, int is_general_text_entity, const char *s, const char *next);
extern int fn_888A8698(d8_xml_parser *parser, const char *s, const char *end, const char **next_ptr);

/* Expat externalEntityInitProcessor3. */
int ts4_xml_ext_entity_init3_888A8698(d8_xml_parser *parser, const char *start, const char *end,
                                      const char **end_ptr)
{
    const char *next = start;
    int tok = parser->encoding->scanners[1](parser->encoding, start, end, &next);
    switch (tok) {
    case 12: {
        int result = fn_888A8340(parser, 1, start, next);
        if (result != 0)
            return result;
        start = next;
    } break;
    case -1:
        if (end_ptr) {
            *end_ptr = start;
            return 0;
        }
        parser->event_ptr = start;
        return 5;
    case -2:
        if (end_ptr) {
            *end_ptr = start;
            return 0;
        }
        parser->event_ptr = start;
        return 6;
    }
    parser->processor = ts4_if_call_seq_u32_off90_888A70B0;
    parser->tag_level = 1;
    return ts4_if_call_seq_u32_off90_888A70B0(parser, start, end, end_ptr);
}

/* Expat externalEntityInitProcessor2. Swing_DLL.xex 0x888A8778 */
int ts4_xml_ext_entity_init2_888A8778(d8_xml_parser *parser, const char *start, const char *end,
                                      const char **end_ptr)
{
    const char *next = start;
    int tok = parser->encoding->scanners[1](parser->encoding, start, end, &next);
    switch (tok) {
    case 14:
        if (next == end && end_ptr) {
            *end_ptr = next;
            return 0;
        }
        start = next;
        break;
    case -1:
        if (end_ptr) {
            *end_ptr = start;
            return 0;
        }
        parser->event_ptr = start;
        return 5;
    case -2:
        if (end_ptr) {
            *end_ptr = start;
            return 0;
        }
        parser->event_ptr = start;
        return 6;
    }
    parser->processor = fn_888A8698;
    return fn_888A8698(parser, start, end, end_ptr);
}
