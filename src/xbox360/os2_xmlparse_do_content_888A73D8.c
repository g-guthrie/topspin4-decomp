/* Derived from Expat 1.95.6 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Swing_DLL.xex 0x888A73D8-0x888A8194.
 * Family OS2: Expat xmlparse.c doContent (XML_NS build, UTF-8 output): the element-content state machine. One
 * function per file (fn_check resolves $LN labels by name). */
#include "d9ex_xmlparse.h"

#ifdef _MSC_VER
#pragma intrinsic(memcmp)
#else
#include <string.h>
#endif

extern void ts4_xml_report_default_888A4278(d9_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s,
                                            const char *end);
extern void ts4_xml_pool_clear_888A38C8(ts4_xml_string_pool *pool);
extern int ts4_xml_epilog_processor_888A65C0(d9_xml_parser *parser, const char *s, const char *end,
                                             const char **next_ptr);
extern int ts4_if_call_seq_u32_off90_888A7320(d9_xml_parser *parser, const char *s, const char *end,
                                              const char **next_ptr);
extern int ts4_xml_do_cdata_section_888A4630(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                             const char **start_ptr, const char *end, const char **next_ptr);
extern const char *ts4_xml_get_context_888A3D88(d9_xml_parser *parser);
extern int ts4_xml_report_pi_888A5A78(d9_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *start,
                                      const char *end);
extern int ts4_xml_report_comment_888A59B8(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                          const char *start, const char *end);
extern int ts4_xmltok_utf8_encode_88891790(int c, char *buf);
extern void *ts4_xml_lookup_888A5060(ts4_xml_hash_table *table, const char *name, unsigned int create_size);

/* addBinding is static in the original xmlparse.c too: same-file copy, kept out of line (0x888A4938). */
#define OS2_LOCAL_ADD_BINDING 1
#ifdef _MSC_VER
__declspec(noinline)
#endif
static int ts4_xml_add_binding_888A4938(d9_xml_parser *parser, ts4_xml_prefix *prefix, const void *att_id,
                                        const char *uri, ts4_xml_binding **bindings_ptr)
{
    ts4_xml_binding *b;
    int len;

    if (*uri == '\0' && prefix->name)
        return 2;

    for (len = 0; uri[len]; len++)
        ;
    if (parser->namespace_separator)
        len++;
    if (parser->free_binding_list) {
        b = parser->free_binding_list;
        if (len > b->uri_alloc) {
            char *temp = (char *)parser->realloc_fcn(b->uri, sizeof(char) * (len + 24));
            if (temp == 0)
                return 1;
            b->uri = temp;
            b->uri_alloc = len + 24;
        }
        parser->free_binding_list = b->next_tag_binding;
    } else {
        b = (ts4_xml_binding *)parser->malloc_fcn(sizeof(ts4_xml_binding));
        if (!b)
            return 1;
        b->uri = (char *)parser->malloc_fcn(sizeof(char) * (len + 24));
        if (!b->uri) {
            parser->free_fcn(b);
            return 1;
        }
        b->uri_alloc = len + 24;
    }
    b->uri_len = len;
    memcpy(b->uri, uri, len * sizeof(char));
    if (parser->namespace_separator)
        b->uri[len - 1] = parser->namespace_separator;
    b->prefix = (const char *)prefix;
    b->att_id = (void *)att_id;
    b->prev_prefix_binding = prefix->binding;
    if (*uri == '\0' && prefix == &parser->dtd->default_prefix)
        prefix->binding = 0;
    else
        prefix->binding = b;
    b->next_tag_binding = *bindings_ptr;
    *bindings_ptr = b;
    if (parser->start_namespace_decl_handler)
        ((void (*)(void *, const char *, const char *))parser->start_namespace_decl_handler)(
            parser->handler_arg, prefix->name, prefix->binding ? uri : 0);
    return 0;
}

/* storeAtts is static in the original xmlparse.c: a same-file copy (kept out of line) shows the compiler that it does
 * not retain the addresses of doContent's locals. */
#ifdef _MSC_VER
#define OS2_STORE_ATTS_LINKAGE static __declspec(noinline)
#else
#define OS2_STORE_ATTS_LINKAGE static
#endif
#include "os2_xmlparse_store_atts_888A68C8.c"

/* handler casts: the shared header keeps most handler slots as void pointers */
typedef void (*os2_start_element_fn)(void *, const char *, const char **);
typedef void (*os2_end_element_fn)(void *, const char *);
typedef void (*os2_skipped_entity_fn)(void *, const char *, int);
typedef int (*os2_external_entity_ref_fn)(void *, const char *, const char *, const char *, const char *);
typedef void (*os2_end_ns_decl_fn)(void *, const char *);
typedef void (*os2_start_cdata_fn)(void *);

#define OS2_ATTS_PTR(p) ((const char **)(p)->atts)

int os2_xml_do_content_888A73D8(d9_xml_parser *parser, int start_tag_level, const struct ts4_xml_encoding *enc,
                                const char *s, const char *end, const char **next_ptr)
{
    ts4_xml_dtd *const dtd = parser->dtd;
    const char **event_pp;
    const char **event_end_pp;
    if (enc == parser->encoding) {
        event_pp = &parser->event_ptr;
        event_end_pp = &parser->event_end_ptr;
    } else {
        event_pp = &(parser->open_internal_entities->internal_event_ptr);
        event_end_pp = &(parser->open_internal_entities->internal_event_end_ptr);
    }
    *event_pp = s;
    for (;;) {
        const char *next = s;
        int tok = enc->scanners[1](enc, s, end, &next);
        *event_end_pp = next;
        switch (tok) {
        case -3: /* XML_TOK_TRAILING_CR */
            if (next_ptr) {
                *next_ptr = s;
                return 0;
            }
            *event_end_pp = end;
            if (parser->character_data_handler) {
                char c = 0xA;
                parser->character_data_handler(parser->handler_arg, &c, 1);
            } else if (parser->default_handler)
                ts4_xml_report_default_888A4278(parser, enc, s, end);
            if (start_tag_level == 0)
                return 3;
            if (parser->tag_level != start_tag_level)
                return 13;
            return 0;
        case -4: /* XML_TOK_NONE */
            if (next_ptr) {
                *next_ptr = s;
                return 0;
            }
            if (start_tag_level > 0) {
                if (parser->tag_level != start_tag_level)
                    return 13;
                return 0;
            }
            return 3;
        case 0: /* XML_TOK_INVALID */
            *event_pp = next;
            return 4;
        case -1: /* XML_TOK_PARTIAL */
            if (next_ptr) {
                *next_ptr = s;
                return 0;
            }
            return 5;
        case -2: /* XML_TOK_PARTIAL_CHAR */
            if (next_ptr) {
                *next_ptr = s;
                return 0;
            }
            return 6;
        case 9: /* XML_TOK_ENTITY_REF */
        {
            const char *name;
            d9_entity *entity;
            char ch = (char)enc->predefined_entity_name(enc, s + enc->min_bytes_per_char,
                                                        next - enc->min_bytes_per_char);
            if (ch) {
                if (parser->character_data_handler)
                    parser->character_data_handler(parser->handler_arg, &ch, 1);
                else if (parser->default_handler)
                    ts4_xml_report_default_888A4278(parser, enc, s, next);
                break;
            }
            name = os2_pool_store_string(&dtd->pool, enc, s + enc->min_bytes_per_char, next - enc->min_bytes_per_char);
            if (!name)
                return 1;
            entity = (d9_entity *)ts4_xml_lookup_888A5060(&dtd->general_entities, name, 0);
            dtd->pool.ptr = dtd->pool.start;
            if (!dtd->has_param_entity_refs || dtd->standalone) {
                if (!entity)
                    return 11;
                else if (!entity->is_internal)
                    return 24;
            } else if (!entity) {
                if (parser->skipped_entity_handler)
                    ((os2_skipped_entity_fn)parser->skipped_entity_handler)(parser->handler_arg, name, 0);
                else if (parser->default_handler)
                    ts4_xml_report_default_888A4278(parser, enc, s, next);
                break;
            }
            if (entity->open)
                return 12;
            if (entity->notation)
                return 15;
            if (entity->text_ptr) {
                int result;
                d9_open_entity open_entity;
                if (!parser->default_expand_internal_entities) {
                    if (parser->skipped_entity_handler)
                        ((os2_skipped_entity_fn)parser->skipped_entity_handler)(parser->handler_arg, entity->name, 0);
                    else if (parser->default_handler)
                        ts4_xml_report_default_888A4278(parser, enc, s, next);
                    break;
                }
                entity->open = 1;
                open_entity.next = parser->open_internal_entities;
                parser->open_internal_entities = &open_entity;
                open_entity.entity = entity;
                open_entity.internal_event_ptr = 0;
                open_entity.internal_event_end_ptr = 0;
                result = os2_xml_do_content_888A73D8(parser, parser->tag_level, parser->internal_encoding,
                                                     (char *)entity->text_ptr,
                                                     (char *)(entity->text_ptr + entity->text_len), 0);
                entity->open = 0;
                parser->open_internal_entities = open_entity.next;
                if (result)
                    return result;
            } else if (parser->external_entity_ref_handler) {
                const char *context;
                entity->open = 1;
                context = ts4_xml_get_context_888A3D88(parser);
                entity->open = 0;
                if (!context)
                    return 1;
                if (!((os2_external_entity_ref_fn)parser->external_entity_ref_handler)(
                        parser->external_entity_ref_handler_arg, context, entity->base, entity->system_id,
                        entity->public_id))
                    return 21;
                parser->temp_pool.ptr = parser->temp_pool.start;
            } else if (parser->default_handler)
                ts4_xml_report_default_888A4278(parser, enc, s, next);
            break;
        }
        case 2: /* XML_TOK_START_TAG_NO_ATTS */
        case 1: /* XML_TOK_START_TAG_WITH_ATTS */
        {
            d9_tag *tag;
            int result;
            char *to_ptr;
            if (parser->free_tag_list) {
                tag = parser->free_tag_list;
                parser->free_tag_list = parser->free_tag_list->parent;
            } else {
                tag = (d9_tag *)parser->malloc_fcn(sizeof(d9_tag));
                if (!tag)
                    return 1;
                tag->buf = (char *)parser->malloc_fcn(32);
                if (!tag->buf) {
                    parser->free_fcn(tag);
                    return 1;
                }
                tag->buf_end = tag->buf + 32;
            }
            tag->bindings = 0;
            tag->parent = parser->tag_stack;
            parser->tag_stack = tag;
            tag->name_local_part = 0;
            tag->name_prefix = 0;
            tag->raw_name = s + enc->min_bytes_per_char;
            tag->raw_name_length = enc->name_length(enc, tag->raw_name);
            ++parser->tag_level;
            {
                const char *raw_name_end = tag->raw_name + tag->raw_name_length;
                const char *from_ptr = tag->raw_name;
                to_ptr = tag->buf;
                for (;;) {
                    int buf_size;
                    int conv_len;
                    enc->utf8_convert(enc, &from_ptr, raw_name_end, &to_ptr, tag->buf_end - 1);
                    conv_len = to_ptr - tag->buf;
                    if (from_ptr == raw_name_end) {
                        tag->name_str_len = conv_len;
                        break;
                    }
                    buf_size = (tag->buf_end - tag->buf) << 1;
                    {
                        char *temp = (char *)parser->realloc_fcn(tag->buf, buf_size);
                        if (temp == 0)
                            return 1;
                        tag->buf = temp;
                        tag->buf_end = temp + buf_size;
                        to_ptr = temp + conv_len;
                    }
                }
            }
            tag->name_str = tag->buf;
            *to_ptr = 0;
            result = os2_xml_store_atts_888A68C8(parser, enc, s, (os2_tag_name *)&tag->name_str, &tag->bindings);
            if (result)
                return result;
            if (parser->start_element_handler)
                ((os2_start_element_fn)parser->start_element_handler)(parser->handler_arg, tag->name_str,
                                                                      OS2_ATTS_PTR(parser));
            else if (parser->default_handler)
                ts4_xml_report_default_888A4278(parser, enc, s, next);
            ts4_xml_pool_clear_888A38C8(&parser->temp_pool);
            break;
        }
        case 4: /* XML_TOK_EMPTY_ELEMENT_NO_ATTS */
        case 3: /* XML_TOK_EMPTY_ELEMENT_WITH_ATTS */
        {
            const char *raw_name = s + enc->min_bytes_per_char;
            int result;
            ts4_xml_binding *bindings = 0;
            unsigned char no_elm_handlers = 1;
            os2_tag_name name;
            name.str = os2_pool_store_string(&parser->temp_pool, enc, raw_name,
                                             raw_name + enc->name_length(enc, raw_name));
            if (!name.str)
                return 1;
            parser->temp_pool.start = parser->temp_pool.ptr;
            result = os2_xml_store_atts_888A68C8(parser, enc, s, &name, &bindings);
            if (result)
                return result;
            parser->temp_pool.start = parser->temp_pool.ptr;
            if (parser->start_element_handler) {
                ((os2_start_element_fn)parser->start_element_handler)(parser->handler_arg, name.str,
                                                                      OS2_ATTS_PTR(parser));
                no_elm_handlers = 0;
            }
            if (parser->end_element_handler) {
                if (parser->start_element_handler)
                    *event_pp = *event_end_pp;
                ((os2_end_element_fn)parser->end_element_handler)(parser->handler_arg, name.str);
                no_elm_handlers = 0;
            }
            if (no_elm_handlers && parser->default_handler)
                ts4_xml_report_default_888A4278(parser, enc, s, next);
            ts4_xml_pool_clear_888A38C8(&parser->temp_pool);
            while (bindings) {
                ts4_xml_binding *b = bindings;
                if (parser->end_namespace_decl_handler)
                    ((os2_end_ns_decl_fn)parser->end_namespace_decl_handler)(parser->handler_arg,
                                                                             ((ts4_xml_prefix *)b->prefix)->name);
                bindings = bindings->next_tag_binding;
                b->next_tag_binding = parser->free_binding_list;
                parser->free_binding_list = b;
                ((ts4_xml_prefix *)b->prefix)->binding = b->prev_prefix_binding;
            }
        }
            if (parser->tag_level == 0)
                return ts4_xml_epilog_processor_888A65C0(parser, next, end, next_ptr);
            break;
        case 5: /* XML_TOK_END_TAG */
            if (parser->tag_level == start_tag_level)
                return 13;
            else {
                int len;
                const char *raw_name;
                d9_tag *tag = parser->tag_stack;
                parser->tag_stack = tag->parent;
                tag->parent = parser->free_tag_list;
                parser->free_tag_list = tag;
                raw_name = s + enc->min_bytes_per_char * 2;
                len = enc->name_length(enc, raw_name);
                if (len != tag->raw_name_length || memcmp(tag->raw_name, raw_name, len) != 0) {
                    *event_pp = raw_name;
                    return 7;
                }
                --parser->tag_level;
                if (parser->end_element_handler) {
                    const char *local_part;
                    const char *prefix;
                    char *uri;
                    local_part = tag->name_local_part;
                    if (parser->ns && local_part) {
                        uri = (char *)tag->name_str + tag->name_uri_len;
                        while (*local_part)
                            *uri++ = *local_part++;
                        prefix = (char *)tag->name_prefix;
                        if (parser->ns_triplets && prefix) {
                            *uri++ = parser->namespace_separator;
                            while (*prefix)
                                *uri++ = *prefix++;
                        }
                        *uri = 0;
                    }
                    ((os2_end_element_fn)parser->end_element_handler)(parser->handler_arg, tag->name_str);
                } else if (parser->default_handler)
                    ts4_xml_report_default_888A4278(parser, enc, s, next);
                while (tag->bindings) {
                    ts4_xml_binding *b = tag->bindings;
                    if (parser->end_namespace_decl_handler)
                        ((os2_end_ns_decl_fn)parser->end_namespace_decl_handler)(parser->handler_arg,
                                                                                 ((ts4_xml_prefix *)b->prefix)->name);
                    tag->bindings = tag->bindings->next_tag_binding;
                    b->next_tag_binding = parser->free_binding_list;
                    parser->free_binding_list = b;
                    ((ts4_xml_prefix *)b->prefix)->binding = b->prev_prefix_binding;
                }
                if (parser->tag_level == 0)
                    return ts4_xml_epilog_processor_888A65C0(parser, next, end, next_ptr);
            }
            break;
        case 10: /* XML_TOK_CHAR_REF */
        {
            int n = enc->char_ref_number(enc, s);
            if (n < 0)
                return 14;
            if (parser->character_data_handler) {
                char buf[4];
                void (*h)(void *, const char *, int) = parser->character_data_handler;
                h(parser->handler_arg, buf, ts4_xmltok_utf8_encode_88891790(n, buf));
            } else if (parser->default_handler)
                ts4_xml_report_default_888A4278(parser, enc, s, next);
        }
            break;
        case 12: /* XML_TOK_XML_DECL */
            return 17;
        case 7: /* XML_TOK_DATA_NEWLINE */
            if (parser->character_data_handler) {
                char c = 0xA;
                parser->character_data_handler(parser->handler_arg, &c, 1);
            } else if (parser->default_handler)
                ts4_xml_report_default_888A4278(parser, enc, s, next);
            break;
        case 8: /* XML_TOK_CDATA_SECT_OPEN */
        {
            int result;
            if (parser->start_cdata_section_handler)
                ((os2_start_cdata_fn)parser->start_cdata_section_handler)(parser->handler_arg);
            else if (parser->default_handler)
                ts4_xml_report_default_888A4278(parser, enc, s, next);
            result = ts4_xml_do_cdata_section_888A4630(parser, enc, &next, end, next_ptr);
            if (!next) {
                parser->processor = ts4_if_call_seq_u32_off90_888A7320;
                return result;
            }
        }
            break;
        case -5: /* XML_TOK_TRAILING_RSQB */
            if (next_ptr) {
                *next_ptr = s;
                return 0;
            }
            if (parser->character_data_handler) {
                if (!enc->is_utf8) {
                    char *data_ptr = parser->data_buf;
                    enc->utf8_convert(enc, &s, end, &data_ptr, parser->data_buf_end);
                    parser->character_data_handler(parser->handler_arg, parser->data_buf, data_ptr - parser->data_buf);
                } else
                    parser->character_data_handler(parser->handler_arg, s, end - s);
            } else if (parser->default_handler)
                ts4_xml_report_default_888A4278(parser, enc, s, end);
            if (start_tag_level == 0) {
                *event_pp = end;
                return 3;
            }
            if (parser->tag_level != start_tag_level) {
                *event_pp = end;
                return 13;
            }
            return 0;
        case 6: /* XML_TOK_DATA_CHARS */
            if (parser->character_data_handler) {
                if (!enc->is_utf8) {
                    for (;;) {
                        char *data_ptr = parser->data_buf;
                        enc->utf8_convert(enc, &s, next, &data_ptr, parser->data_buf_end);
                        *event_end_pp = s;
                        parser->character_data_handler(parser->handler_arg, parser->data_buf,
                                                       data_ptr - parser->data_buf);
                        if (s == next)
                            break;
                        *event_pp = s;
                    }
                } else
                    parser->character_data_handler(parser->handler_arg, s, next - s);
            } else if (parser->default_handler)
                ts4_xml_report_default_888A4278(parser, enc, s, next);
            break;
        case 11: /* XML_TOK_PI */
            if (!ts4_xml_report_pi_888A5A78(parser, enc, s, next))
                return 1;
            break;
        case 13: /* XML_TOK_COMMENT */
            if (!ts4_xml_report_comment_888A59B8(parser, enc, s, next))
                return 1;
            break;
        default:
            if (parser->default_handler)
                ts4_xml_report_default_888A4278(parser, enc, s, next);
            break;
        }
        *event_pp = s = next;
    }
}
