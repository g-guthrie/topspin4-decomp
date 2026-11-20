/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family OS2: Expat xmlparse.c ignoreSectionProcessor (XML_DTD build). */
#include "d9ex_xmlparse.h"

extern void ts4_xml_report_default_888A4278(d9_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s, const char *next);

/* doIgnoreSection is static in the original xmlparse.c: a local copy, kept out of line, lets the compiler see that
 * it does not retain the address of start. */
#ifdef _MSC_VER
__declspec(noinline)
#endif
int ts4_xml_do_ignore_section_888A4460(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                       const char **start_ptr, const char *end, const char **next_ptr)
{
    const char *next;
    int tok;
    const char *s = *start_ptr;
    const char **event_pp;
    const char **event_end_pp;
    if (enc == parser->encoding) {
        event_pp = &parser->event_ptr;
        *event_pp = s;
        event_end_pp = &parser->event_end_ptr;
    } else {
        event_pp = &(parser->open_internal_entities->internal_event_ptr);
        event_end_pp = &(parser->open_internal_entities->internal_event_end_ptr);
    }
    *event_pp = s;
    *start_ptr = 0;
    tok = enc->scanners[3](enc, s, end, &next);
    *event_end_pp = next;
    switch (tok) {
    case 33:
        if (parser->default_handler)
            ts4_xml_report_default_888A4278(parser, enc, s, next);
        *start_ptr = next;
        return 0;
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
        return 2;
    default:
        *event_pp = next;
        return 23;
    }
}
extern int os2_xml_do_prolog_888A8898(d9_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s, const char *end,
                       int tok, const char *next, const char **next_ptr);
extern int ts4_xml_prolog_processor_888AA1C8(d9_xml_parser *parser, const char *s, const char *end,
                                             const char **next_ptr);

/* Swing_DLL.xex 0x888A4598 */
int os2_xml_ignore_section_processor_888A4598(d9_xml_parser *parser, const char *start, const char *end,
                                              const char **end_ptr)
{
    int result = ts4_xml_do_ignore_section_888A4460(parser, parser->encoding, &start, end, end_ptr);
    if (start) {
        const char *next = start;
        int tok;
        parser->processor = ts4_xml_prolog_processor_888AA1C8;
        tok = parser->encoding->scanners[0](parser->encoding, start, end, &next);
        return os2_xml_do_prolog_888A8898(parser, parser->encoding, start, end, tok, next, end_ptr);
    }
    return result;
}
