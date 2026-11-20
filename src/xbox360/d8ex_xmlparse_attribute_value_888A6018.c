/* Swing_DLL.xex 0x888A6018-0x888A65C0, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

extern int ts4_xmltok_utf8_encode_88891790(int c, char *buf);
extern char *ts4_xml_pool_append_888A35A8(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc,
                                          const char *ptr, const char *end);
extern unsigned char ts4_xml_pool_grow_888A2F00(ts4_xml_string_pool *pool);
extern char *ts4_if_call_seq_u32_off8_888A4FE0(ts4_xml_string_pool *pool);
extern void *fn_888A5060(ts4_xml_hash_table *table, const char *name, unsigned int create_size);
extern void ts4_xml_report_default_888A4278(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s,
                                            const char *end);
extern int fn_888A6018(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, unsigned char is_cdata,
                       const char *ptr, const char *end, ts4_xml_string_pool *pool);

#define D8_POOL_APPEND_CHAR(pool, c) \
    (((pool)->ptr == (pool)->end && !ts4_xml_pool_grow_888A2F00(pool)) ? 0 : ((*((pool)->ptr)++ = (c)), 1))

#ifdef _MSC_VER
__declspec(noinline)
#endif
/* Expat appendAttributeValue. */
int ts4_xml_append_attribute_value_888A6018(d8_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                            unsigned char is_cdata, const char *ptr, const char *end,
                                            ts4_xml_string_pool *pool)
{
    ts4_xml_dtd *dtd = parser->dtd;
    for (;;) {
        const char *next;
        int tok = enc->literal_scanners[0](enc, ptr, end, &next);
        switch (tok) {
        case -4:
            return 0;
        case 0:
            if (enc == parser->encoding)
                parser->event_ptr = next;
            return 4;
        case -1:
            if (enc == parser->encoding)
                parser->event_ptr = ptr;
            return 4;
        case 10: {
            char buf[4];
            int i;
            int n = enc->char_ref_number(enc, ptr);
            if (n < 0) {
                if (enc == parser->encoding)
                    parser->event_ptr = ptr;
                return 14;
            }
            if (!is_cdata && n == 0x20 && (pool->ptr - pool->start == 0 || pool->ptr[-1] == 0x20))
                break;
            n = ts4_xmltok_utf8_encode_88891790(n, buf);
            if (!n) {
                if (enc == parser->encoding)
                    parser->event_ptr = ptr;
                return 14;
            }
            for (i = 0; i < n; i++) {
                if (!D8_POOL_APPEND_CHAR(pool, buf[i]))
                    return 1;
            }
        } break;
        case 6:
            if (!ts4_xml_pool_append_888A35A8(pool, enc, ptr, next))
                return 1;
            break;
        case -3:
            next = ptr + enc->min_bytes_per_char;
        case 39:
        case 7:
            if (!is_cdata && (pool->ptr - pool->start == 0 || pool->ptr[-1] == 0x20))
                break;
            if (!D8_POOL_APPEND_CHAR(pool, 0x20))
                return 1;
            break;
        case 9: {
            const char *name;
            d8_entity *entity;
            char check_entity_decl;
            char ch = (char)enc->predefined_entity_name(enc, ptr + enc->min_bytes_per_char,
                                                        next - enc->min_bytes_per_char);
            if (ch) {
                if (!D8_POOL_APPEND_CHAR(pool, ch))
                    return 1;
                break;
            }
            if (!ts4_xml_pool_append_888A35A8(&parser->temp2_pool, enc, ptr + enc->min_bytes_per_char,
                                              next - enc->min_bytes_per_char))
                return 1;
            name = ts4_if_call_seq_u32_off8_888A4FE0(&parser->temp2_pool);
            if (!name)
                return 1;
            entity = (d8_entity *)fn_888A5060(&dtd->general_entities, name, 0);
            parser->temp2_pool.ptr = parser->temp2_pool.start;
            if (pool == &dtd->pool)
                check_entity_decl = (parser->prolog_state.document_entity &&
                                     (dtd->standalone ? !parser->open_internal_entities
                                                      : !dtd->has_param_entity_refs));
            else
                check_entity_decl = !dtd->has_param_entity_refs || dtd->standalone;
            if (check_entity_decl) {
                if (!entity)
                    return 11;
                else if (!entity->is_internal)
                    return 24;
            } else if (!entity) {
                if (pool == &parser->temp_pool && parser->default_handler)
                    ts4_xml_report_default_888A4278(parser, enc, ptr, next);
                break;
            }
            if (entity->open) {
                if (enc == parser->encoding)
                    parser->event_ptr = ptr;
                return 12;
            }
            if (entity->notation) {
                if (enc == parser->encoding)
                    parser->event_ptr = ptr;
                return 15;
            }
            if (!entity->text_ptr) {
                if (enc == parser->encoding)
                    parser->event_ptr = ptr;
                return 16;
            } else {
                int result;
                const char *text_end = entity->text_ptr + entity->text_len;
                entity->open = 1;
                result = fn_888A6018(parser, parser->internal_encoding, is_cdata, entity->text_ptr, text_end, pool);
                entity->open = 0;
                if (result)
                    return result;
            }
        } break;
        default:
            if (enc == parser->encoding)
                parser->event_ptr = ptr;
            return 23;
        }
        ptr = next;
    }
}

/* Expat storeAttributeValue. Swing_DLL.xex 0x888A6508 */
int ts4_xml_store_attribute_value_888A6508(d8_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                           unsigned char is_cdata, const char *ptr, const char *end,
                                           ts4_xml_string_pool *pool)
{
    int result = ts4_xml_append_attribute_value_888A6018(parser, enc, is_cdata, ptr, end, pool);
    if (result)
        return result;
    if (!is_cdata && pool->ptr - pool->start && pool->ptr[-1] == 0x20)
        --pool->ptr;
    if (!D8_POOL_APPEND_CHAR(pool, 0))
        return 1;
    return 0;
}
