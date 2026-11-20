/* Swing_DLL.xex 0x888A4EF8-0x888A4F50, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

/* Expat destroyBindings. */
void ts4_xml_destroy_bindings_888A4EF8(ts4_xml_binding *bindings, d8_xml_parser *parser)
{
    for (;;) {
        ts4_xml_binding *b = bindings;
        if (!b)
            break;
        bindings = b->next_tag_binding;
        parser->free_fcn(b->uri);
        parser->free_fcn(b);
    }
}
