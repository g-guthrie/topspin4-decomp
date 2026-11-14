/* Swing_DLL.xex 0x888A5BA0-0x888A6018, executable version 0.0.0.3. */
#include "d9ex_xmlparse.h"

extern int ts4_xmltok_utf8_encode_88891790(int c, char *buf);
extern char *ts4_xml_pool_append_888A35A8(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc,
                                          const char *ptr, const char *end);
extern unsigned char ts4_xml_pool_grow_888A2F00(ts4_xml_string_pool *pool);
extern char *ts4_if_call_seq_u32_off8_888A4FE0(ts4_xml_string_pool *pool);
extern void *fn_888A5060(ts4_xml_hash_table *table, const char *name, unsigned int create_size);
extern int fn_888A5BA0(d9_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s, const char *end);

#define D9_POOL_APPEND_CHAR(pool, c) \
    (((pool)->end == (pool)->ptr && !ts4_xml_pool_grow_888A2F00(pool)) ? 0 : ((*((pool)->ptr)++ = (c)), 1))

/* Expat storeEntityValue. */
int ts4_xml_store_entity_value_888A5BA0(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                        const char *s, const char *end)
{
    ts4_xml_dtd *dtd = parser->dtd;
    ts4_xml_string_pool *pool = &dtd->entity_value_pool;
    int result = 0;
    int old_in_entity_value = parser->prolog_state.in_entity_value;

    parser->prolog_state.in_entity_value = 1;
    if (!pool->blocks) {
        if (!ts4_xml_pool_grow_888A2F00(pool))
            return 1;
    }
    for (;;) {
        const char *next;
        int tok = enc->literal_scanners[1](enc, s, end, &next);
        switch (tok) {
        case 28:
            if (parser->is_param_entity || enc != parser->encoding) {
                const char *name;
                d9_entity *entity;
                if (!ts4_xml_pool_append_888A35A8(&parser->temp_pool, enc, s + enc->min_bytes_per_char,
                                                  next - enc->min_bytes_per_char)) {
                    result = 1;
                    goto done;
                }
                name = ts4_if_call_seq_u32_off8_888A4FE0(&parser->temp_pool);
                if (!name) {
                    result = 1;
                    goto done;
                }
                entity = (d9_entity *)fn_888A5060(&dtd->param_entities, name, 0);
                parser->temp_pool.ptr = parser->temp_pool.start;
                if (!entity) {
                    dtd->keep_processing = dtd->standalone;
                    goto done;
                }
                if (entity->open) {
                    if (enc == parser->encoding)
                        parser->event_ptr = s;
                    result = 12;
                    goto done;
                }
                if (entity->system_id) {
                    if (parser->external_entity_ref_handler) {
                        dtd->param_entity_read = 0;
                        entity->open = 1;
                        if (!((int (*)(void *, const char *, const char *, const char *, const char *))
                                  parser->external_entity_ref_handler)(parser->external_entity_ref_handler_arg, 0,
                                                                       entity->base, entity->system_id,
                                                                       entity->public_id)) {
                            entity->open = 0;
                            result = 21;
                            goto done;
                        }
                        entity->open = 0;
                        if (!dtd->param_entity_read)
                            dtd->keep_processing = dtd->standalone;
                    } else {
                        dtd->keep_processing = dtd->standalone;
                    }
                } else {
                    entity->open = 1;
                    result = fn_888A5BA0(parser, parser->internal_encoding, entity->text_ptr,
                                         entity->text_ptr + entity->text_len);
                    entity->open = 0;
                    if (result)
                        goto done;
                }
                break;
            }
            parser->event_ptr = s;
            result = 10;
            goto done;
        case -4:
            result = 0;
            goto done;
        case 9:
        case 6:
            if (!ts4_xml_pool_append_888A35A8(pool, enc, s, next)) {
                result = 1;
                goto done;
            }
            break;
        case -3:
            next = s + enc->min_bytes_per_char;
        case 7:
            if (!D9_POOL_APPEND_CHAR(pool, 0xA)) {
                result = 1;
                goto done;
            }
            break;
        case 10: {
            char buf[4];
            int i;
            int n = enc->char_ref_number(enc, s);
            if (n < 0) {
                if (enc == parser->encoding)
                    parser->event_ptr = s;
                result = 14;
                goto done;
            }
            n = ts4_xmltok_utf8_encode_88891790(n, buf);
            if (!n) {
                if (enc == parser->encoding)
                    parser->event_ptr = s;
                result = 14;
                goto done;
            }
            for (i = 0; i < n; i++) {
                if (!D9_POOL_APPEND_CHAR(pool, buf[i])) {
                    result = 1;
                    goto done;
                }
            }
        } break;
        case -1:
            if (enc == parser->encoding)
                parser->event_ptr = s;
            result = 4;
            goto done;
        case 0:
            if (enc == parser->encoding)
                parser->event_ptr = next;
            result = 4;
            goto done;
        default:
            if (enc == parser->encoding)
                parser->event_ptr = s;
            result = 23;
            goto done;
        }
        s = next;
    }
done:
    parser->prolog_state.in_entity_value = old_in_entity_value;
    return result;
}
