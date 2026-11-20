/* Swing_DLL.xex 0x888A4630-0x888A4938, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

extern void fn_888A4278(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s, const char *end);

/* Expat doCdataSection. */
int ts4_xml_do_cdata_section_888A4630(d8_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                      const char **start_ptr, const char *end, const char **next_ptr)
{
    const char *s = *start_ptr;
    const char **event_pp;
    const char **event_end_pp;

    if (enc == parser->encoding) {
        event_pp = &parser->event_ptr;
        *event_pp = s;
        event_end_pp = &parser->event_end_ptr;
    } else {
        event_pp = &parser->open_internal_entities->internal_event_ptr;
        event_end_pp = &parser->open_internal_entities->internal_event_end_ptr;
    }
    *event_pp = s;
    *start_ptr = 0;
    for (;;) {
        const char *next;
        int tok = enc->scanners[2](enc, s, end, &next);
        *event_end_pp = next;
        switch (tok) {
        case 40:
            if (parser->end_cdata_section_handler)
                parser->end_cdata_section_handler(parser->handler_arg);
            else if (parser->default_handler)
                fn_888A4278(parser, enc, s, next);
            *start_ptr = next;
            return 0;
        case 7:
            if (parser->character_data_handler) {
                char c = 0xA;
                parser->character_data_handler(parser->handler_arg, &c, 1);
            } else if (parser->default_handler) {
                fn_888A4278(parser, enc, s, next);
            }
            break;
        case 6:
            if (parser->character_data_handler) {
                if (!enc->is_utf8) {
                    for (;;) {
                        char *data_ptr = parser->data_buf;
                        enc->utf8_convert(enc, &s, next, &data_ptr, parser->data_buf_end);
                        *event_end_pp = next;
                        parser->character_data_handler(parser->handler_arg, parser->data_buf,
                                                       (int)(data_ptr - parser->data_buf));
                        if (s == next)
                            break;
                        *event_pp = s;
                    }
                } else {
                    parser->character_data_handler(parser->handler_arg, s, (int)(next - s));
                }
            } else if (parser->default_handler) {
                fn_888A4278(parser, enc, s, next);
            }
            break;
        case 0:
            *event_pp = next;
            return 4;
        case -2:
            if (next_ptr) {
                *next_ptr = s;
                return 0;
            }
            return 6;
        case -1:
        case -4:
            if (next_ptr) {
                *next_ptr = s;
                return 0;
            }
            return 20;
        default:
            *event_pp = next;
            return 23;
        }
        *event_pp = s = next;
    }
}
