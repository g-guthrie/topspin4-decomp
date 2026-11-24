/* Swing_DLL.xex 0x888A4F50-0x888A4FE0, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

extern void ts4_xml_build_content_node_888A2C58(ts4_xml_parser *parser, int src_node, ts4_xml_content *dest,
                                                ts4_xml_content **contpos, char **strpos);

/* Expat build_model: allocate and fill the content model of the element declaration just parsed. */
ts4_xml_content *ts4_xml_build_model_888A4F50(d8_xml_parser *parser)
{
    ts4_xml_dtd *dtd = parser->dtd;
    ts4_xml_content *ret;
    ts4_xml_content *cpos;
    char *str;
    int alloc_size = dtd->scaff_count * sizeof(ts4_xml_content) + dtd->content_string_len;

    ret = (ts4_xml_content *)parser->malloc_fcn(alloc_size);
    if (!ret)
        return 0;
    str = (char *)&ret[dtd->scaff_count];
    cpos = &ret[1];
    ts4_xml_build_content_node_888A2C58((ts4_xml_parser *)parser, 0, ret, &cpos, &str);
    return ret;
}
