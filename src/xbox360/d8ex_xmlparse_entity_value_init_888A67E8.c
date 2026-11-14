/* Swing_DLL.xex 0x888A67E8-0x888A68C8, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

extern int fn_888A5BA0(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s, const char *end);

/* Scan to the end of an entity value, then store it (Expat entityValueInitProcessor shape). */
int ts4_xml_entity_value_init_888A67E8(d8_xml_parser *parser, const char *s, const char *end, const char **next_ptr)
{
    const struct ts4_xml_encoding *enc = parser->encoding;
    const char *next = s;
    int tok = enc->scanners[0](enc, s, end, &next);
    while (tok > 0)
        tok = enc->scanners[0](enc, next, end, &next);
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
    return fn_888A5BA0(parser, enc, s, end);
}
