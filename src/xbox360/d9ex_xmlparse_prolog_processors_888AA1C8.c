/* Swing_DLL.xex 0x888AA1C8-0x888AA490, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

extern int fn_888A8898(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s, const char *end,
                       int tok, const char *next, const char **next_ptr);
extern int fn_888A8340(d8_xml_parser *parser, int is_general_text_entity, const char *s, const char *next);
extern int fn_888A5BA0(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s, const char *end);
extern int fn_888A67E8(d8_xml_parser *parser, const char *s, const char *end, const char **next_ptr);
extern int fn_888AA1C8(d8_xml_parser *parser, const char *s, const char *end, const char **next_ptr);

/* Expat prologProcessor. */
int ts4_xml_prolog_processor_888AA1C8(d8_xml_parser *parser, const char *s, const char *end, const char **next_ptr)
{
    const char *next = s;
    int tok = parser->encoding->scanners[0](parser->encoding, s, end, &next);
    return fn_888A8898(parser, parser->encoding, s, end, tok, next, next_ptr);
}

/* Expat externalParEntProcessor. */
int ts4_xml_external_par_ent_processor_888AA228(d8_xml_parser *parser, const char *s, const char *end,
                                                const char **next_ptr)
{
    const char *next = s;
    int tok = parser->encoding->scanners[0](parser->encoding, s, end, &next);
    if (tok <= 0) {
        if (next_ptr && tok != 0) {
            *next_ptr = s;
            return 0;
        }
        switch (tok) {
        case -2:
            return 6;
        case -1:
            return 5;
        case 0:
            return 4;
        }
    } else if (tok == 14) {
        s = next;
        tok = parser->encoding->scanners[0](parser->encoding, s, end, &next);
    }
    parser->processor = fn_888AA1C8;
    return fn_888A8898(parser, parser->encoding, s, end, tok, next, next_ptr);
}

/* Expat entityValueInitProcessor. */
int ts4_xml_entity_value_init_processor_888AA328(d8_xml_parser *parser, const char *s, const char *end,
                                                 const char **next_ptr)
{
    const char *start = s;
    const char *next = start;
    int tok;

    for (;;) {
        tok = parser->encoding->scanners[0](parser->encoding, start, end, &next);
        if (tok <= 0) {
            if (next_ptr && tok != 0) {
                *next_ptr = s;
                return 0;
            }
            switch (tok) {
            case -2:
                return 6;
            case -1:
                return 5;
            case 0:
                return 4;
            }
            return fn_888A5BA0(parser, parser->encoding, s, end);
        } else if (tok == 12) {
            int result = fn_888A8340(parser, 0, start, next);
            if (result != 0)
                return result;
            if (next_ptr)
                *next_ptr = next;
            parser->processor = fn_888A67E8;
            return fn_888A67E8(parser, next, end, next_ptr);
        } else if (tok == 14 && next == end && next_ptr) {
            *next_ptr = next;
            return 0;
        }
        start = next;
    }
}
