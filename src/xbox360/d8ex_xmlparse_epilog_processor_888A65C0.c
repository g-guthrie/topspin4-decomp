/* Swing_DLL.xex 0x888A65C0-0x888A67E4, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

extern int fn_888A65C0(d8_xml_parser *parser, const char *s, const char *end, const char **next_ptr);
extern void ts4_xml_report_default_888A4278(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s,
                                            const char *end);
extern int ts4_xml_report_pi_888A5A78(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *start,
                                      const char *end);
extern int ts4_xml_report_comment_888A59B8(d8_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                           const char *start, const char *end);

/* Expat epilogProcessor: after the document element only white space, comments and PIs are allowed. */
int ts4_xml_epilog_processor_888A65C0(d8_xml_parser *parser, const char *s, const char *end, const char **next_ptr)
{
    parser->event_ptr = s;
    parser->processor = fn_888A65C0;
    for (;;) {
        const char *next = 0;
        int tok = parser->encoding->scanners[0](parser->encoding, s, end, &next);
        parser->event_end_ptr = next;
        switch (tok) {
        case -15:
            if (parser->default_handler) {
                parser->event_end_ptr = next;
                ts4_xml_report_default_888A4278(parser, parser->encoding, s, next);
            }
            if (next_ptr)
                *next_ptr = next;
            return 0;
        case -4:
            if (next_ptr)
                *next_ptr = s;
            return 0;
        case 15:
            if (parser->default_handler)
                ts4_xml_report_default_888A4278(parser, parser->encoding, s, next);
            break;
        case 11:
            if (!ts4_xml_report_pi_888A5A78(parser, parser->encoding, s, next))
                return 1;
            break;
        case 13:
            if (!ts4_xml_report_comment_888A59B8(parser, parser->encoding, s, next))
                return 1;
            break;
        case 0:
            parser->event_ptr = next;
            return 4;
        case -1:
            if (!next_ptr)
                return 5;
            *next_ptr = s;
            return 0;
        case -2:
            if (!next_ptr)
                return 6;
            *next_ptr = s;
            return 0;
        default:
            return 9;
        }
        parser->event_ptr = s = next;
    }
}
