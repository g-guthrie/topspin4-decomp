/* Swing_DLL.xex 0x888A8340-0x888A8610, executable version 0.0.0.3. */
#include "d9ex_xmlparse.h"

extern int fn_8889B480(int is_general_text_entity, const struct ts4_xml_encoding *enc, const char *ptr, const char *end,
                       const char **eventp, const char **version, const char **version_end, const char **encoding_name,
                       const struct ts4_xml_encoding **new_encoding, int *standalone);
extern int fn_8889B4F0(int is_general_text_entity, const struct ts4_xml_encoding *enc, const char *ptr, const char *end,
                       const char **eventp, const char **version, const char **version_end, const char **encoding_name,
                       const struct ts4_xml_encoding **new_encoding, int *standalone);
extern char *ts4_xml_pool_append_888A35A8(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc,
                                          const char *ptr, const char *end);
extern char *ts4_if_call_seq_u32_off8_888A4FE0(ts4_xml_string_pool *pool);
extern void fn_888A4278(d9_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s, const char *end);
extern int ts4_xml_handle_unknown_encoding_888A81F8(d9_xml_parser *parser, const char *encoding_name);

/* Expat poolClear (kept in this file so the caller can keep values in volatile registers across it). */
#ifdef _MSC_VER
__declspec(noinline)
#endif
static void ts4_xml_pool_clear_888A38C8(ts4_xml_string_pool *pool)
{
    if (!pool->free_blocks) {
        pool->free_blocks = pool->blocks;
    } else {
        ts4_xml_block *p = pool->blocks;
        while (p) {
            ts4_xml_block *tem = p->next;
            p->next = pool->free_blocks;
            pool->free_blocks = p;
            p = tem;
        }
    }
    pool->blocks = 0;
    pool->start = 0;
    pool->ptr = 0;
    pool->end = 0;
}

static D9_INLINE char *store_string(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc, const char *ptr,
                                    const char *end)
{
    if (!ts4_xml_pool_append_888A35A8(pool, enc, ptr, end))
        return 0;
    return ts4_if_call_seq_u32_off8_888A4FE0(pool);
}

/* Expat processXmlDecl. */
int ts4_xml_process_xml_decl_888A8340(d9_xml_parser *parser, int is_general_text_entity, const char *s,
                                      const char *next)
{
    const char *encoding_name = 0;
    const char *stored_enc_name = 0;
    const struct ts4_xml_encoding *new_encoding = 0;
    const char *version = 0;
    const char *version_end;
    const char *stored_version = 0;
    int standalone = -1;

    if (!(parser->ns ? fn_8889B480 : fn_8889B4F0)(is_general_text_entity, parser->encoding, s, next,
                                                   &parser->event_ptr, &version, &version_end, &encoding_name,
                                                   &new_encoding, &standalone))
        return 2;
    if (!is_general_text_entity && standalone == 1) {
        parser->dtd->standalone = 1;
        if (parser->param_entity_parsing == 1)
            parser->param_entity_parsing = 0;
    }
    if (parser->xml_decl_handler) {
        if (encoding_name) {
            stored_enc_name = store_string(&parser->temp2_pool, parser->encoding, encoding_name,
                                           encoding_name + parser->encoding->name_length(parser->encoding, encoding_name));
            if (!stored_enc_name)
                return 1;
            parser->temp2_pool.start = parser->temp2_pool.ptr;
        }
        if (version) {
            stored_version = store_string(&parser->temp2_pool, parser->encoding, version,
                                          version_end - parser->encoding->min_bytes_per_char);
            if (!stored_version)
                return 1;
        }
        ((void (*)(void *, const char *, const char *, int))parser->xml_decl_handler)(
            parser->handler_arg, stored_version, stored_enc_name, standalone);
    } else if (parser->default_handler) {
        fn_888A4278(parser, parser->encoding, s, next);
    }
    if (!parser->protocol_encoding_name) {
        if (new_encoding) {
            if (new_encoding->min_bytes_per_char != parser->encoding->min_bytes_per_char) {
                parser->event_ptr = encoding_name;
                return 19;
            }
            parser->encoding = new_encoding;
        } else if (encoding_name) {
            int result;
            if (!stored_enc_name) {
                stored_enc_name = store_string(&parser->temp2_pool, parser->encoding, encoding_name,
                                               encoding_name + parser->encoding->name_length(parser->encoding, encoding_name));
                if (!stored_enc_name)
                    return 1;
            }
            result = ts4_xml_handle_unknown_encoding_888A81F8(parser, stored_enc_name);
            ts4_xml_pool_clear_888A38C8(&parser->temp2_pool);
            if (result == 18)
                parser->event_ptr = encoding_name;
            return result;
        }
    }
    if (stored_enc_name || stored_version)
        ts4_xml_pool_clear_888A38C8(&parser->temp2_pool);
    return 0;
}
