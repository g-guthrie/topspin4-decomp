/* Swing_DLL.xex 0x888A7270-0x888A731C, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

extern char *ts4_xml_pool_append_888A35A8(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc,
                                          const char *ptr, const char *end);
extern char *ts4_if_call_seq_u32_off8_888A4FE0(ts4_xml_string_pool *pool);
extern void *fn_888A5060(ts4_xml_hash_table *table, const char *name, unsigned int create_size);
extern int ts4_xml_set_element_type_prefix_888A5890(d8_xml_parser *parser, ts4_xml_element_type *element_type);

static D8_INLINE char *store_string(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc, const char *ptr,
                                    const char *end)
{
    if (!ts4_xml_pool_append_888A35A8(pool, enc, ptr, end))
        return 0;
    return ts4_if_call_seq_u32_off8_888A4FE0(pool);
}

/* Expat getElementType: intern an element name in the DTD. */
ts4_xml_element_type *ts4_xml_get_element_type_888A7270(d8_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                                        const char *ptr, const char *end)
{
    ts4_xml_dtd *dtd = parser->dtd;
    const char *name;
    ts4_xml_element_type *ret;

    name = store_string(&dtd->pool, enc, ptr, end);
    if (!name)
        return 0;
    ret = (ts4_xml_element_type *)fn_888A5060(&dtd->element_types, name, sizeof(ts4_xml_element_type));
    if (!ret)
        return 0;
    if (ret->name != name) {
        dtd->pool.ptr = dtd->pool.start;
    } else {
        dtd->pool.start = dtd->pool.ptr;
        if (!ts4_xml_set_element_type_prefix_888A5890(parser, ret))
            return 0;
    }
    return ret;
}
