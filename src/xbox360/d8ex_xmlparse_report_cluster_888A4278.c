/* Swing_DLL.xex 0x888A38C8-0x888A5BA0 (report/pool helpers compiled together), executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

extern char *ts4_xml_pool_append_888A35A8(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc,
                                          const char *ptr, const char *end);
extern char *ts4_if_call_seq_u32_off8_888A4FE0(ts4_xml_string_pool *pool);

#ifdef _MSC_VER
__declspec(noinline)
#endif
/* Expat poolClear. */
void ts4_xml_pool_clear_888A38C8(ts4_xml_string_pool *pool)
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

#ifdef _MSC_VER
__declspec(noinline)
#endif
/* Expat reportDefault. */
void ts4_xml_report_default_888A4278(d8_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                     const char *s, const char *end)
{
    if (!enc->is_utf8) {
        const char **event_pp;
        const char **event_end_pp;
        if (enc == parser->encoding) {
            event_pp = &parser->event_ptr;
            event_end_pp = &parser->event_end_ptr;
        } else {
            event_pp = &parser->open_internal_entities->internal_event_ptr;
            event_end_pp = &parser->open_internal_entities->internal_event_end_ptr;
        }
        do {
            char *data_ptr = parser->data_buf;
            enc->utf8_convert(enc, &s, end, &data_ptr, parser->data_buf_end);
            *event_end_pp = s;
            parser->default_handler(parser->handler_arg, parser->data_buf, (int)(data_ptr - parser->data_buf));
            *event_pp = s;
        } while (s != end);
    } else {
        parser->default_handler(parser->handler_arg, s, (int)(end - s));
    }
}

#ifdef _MSC_VER
__declspec(noinline)
#endif
/* Expat normalizeLines: CR and CR LF become LF in place. */
void ts4_xml_normalize_lines_888A4348(char *s)
{
    char *p;
    for (;; s++) {
        if (*s == 0)
            return;
        if (*s == 0xD)
            break;
    }
    p = s;
    do {
        if (*s == 0xD) {
            *p++ = 0xA;
            if (*++s == 0xA)
                s++;
        } else {
            *p++ = *s++;
        }
    } while (*s);
    *p = 0;
}

static D8_INLINE char *store_string(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc, const char *ptr,
                                    const char *end)
{
    if (!ts4_xml_pool_append_888A35A8(pool, enc, ptr, end))
        return 0;
    return ts4_if_call_seq_u32_off8_888A4FE0(pool);
}

/* Expat reportComment. */
int ts4_xml_report_comment_888A59B8(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *start,
                                    const char *end)
{
    char *data;
    if (!parser->comment_handler_fn) {
        if (parser->default_handler)
            ts4_xml_report_default_888A4278(parser, enc, start, end);
        return 1;
    }
    data = store_string(&parser->temp_pool, enc, start + enc->min_bytes_per_char * 4,
                        end - enc->min_bytes_per_char * 3);
    if (!data)
        return 0;
    ts4_xml_normalize_lines_888A4348(data);
    parser->comment_handler_fn(parser->handler_arg, data);
    ts4_xml_pool_clear_888A38C8(&parser->temp_pool);
    return 1;
}

/* Expat reportProcessingInstruction. */
int ts4_xml_report_pi_888A5A78(d8_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *start,
                               const char *end)
{
    const char *target;
    char *data;
    const char *tem;
    if (!parser->processing_instruction_handler) {
        if (parser->default_handler)
            ts4_xml_report_default_888A4278(parser, enc, start, end);
        return 1;
    }
    start += enc->min_bytes_per_char * 2;
    tem = start + enc->name_length(enc, start);
    target = store_string(&parser->temp_pool, enc, start, tem);
    if (!target)
        return 0;
    parser->temp_pool.start = parser->temp_pool.ptr;
    data = store_string(&parser->temp_pool, enc, enc->skip_s(enc, tem), end - enc->min_bytes_per_char * 2);
    if (!data)
        return 0;
    ts4_xml_normalize_lines_888A4348(data);
    parser->processing_instruction_handler(parser->handler_arg, target, data);
    ts4_xml_pool_clear_888A38C8(&parser->temp_pool);
    return 1;
}
