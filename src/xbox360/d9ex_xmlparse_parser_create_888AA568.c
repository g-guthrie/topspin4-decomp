/* Swing_DLL.xex 0x888AA568-0x888AA8CC, executable version 0.0.0.3. */
#include "d9ex_xmlparse.h"

extern void *ts4_crt_nh_malloc_88565258(unsigned int size);
extern void *fn_88565320(void *p, unsigned int size);
extern void fn_885651F8(void *p);
extern const char *ts4_xml_pool_copy_string_888A3358(ts4_xml_string_pool *pool, const char *s);
extern void ts4_if_call_seq_fn_88894BA8_88899BF0(void *init_encoding, const struct ts4_xml_encoding **enc, const char *name);
extern int ts4_token_classify_888A2AC8(struct ts4_prolog_state *state, int tok, const char *ptr, const char *end,
                                       const struct ts4_xml_encoding *enc);
extern int ts4_if_call_seq_fn_888A8610_888AA518(d9_xml_parser *parser, const char *s, const char *end,
                                                const char **next_ptr);
extern char lbl_880F7604[];
extern char lbl_880CF518[];
extern ts4_xml_dtd *ts4_if_get_u32_off0_888A3BC8(void *mem);
extern void ts4_xml_parser_init_888AA568(d9_xml_parser *parser);
extern void ts4_xml_parser_free_888A7110(d9_xml_parser *parser);

static D9_INLINE void pool_init(ts4_xml_string_pool *pool, const ts4_xml_memory_suite *ms)
{
    pool->blocks = 0;
    pool->free_blocks = 0;
    pool->start = 0;
    pool->ptr = 0;
    pool->end = 0;
    pool->mem = ms;
}

static D9_INLINE void prolog_state_init(struct ts4_prolog_state *state)
{
    state->handler = ts4_token_classify_888A2AC8;
    state->document_entity = 1;
    state->include_level = 0;
    state->in_entity_value = 0;
}

#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_xml_parser_init_888AA568(d9_xml_parser *parser)
{
    parser->processor = ts4_if_call_seq_fn_888A8610_888AA518;
    prolog_state_init(&parser->prolog_state);
    parser->protocol_encoding_name = ts4_xml_pool_copy_string_888A3358(&parser->temp_pool, lbl_880F7604);
    parser->cur_base = 0;
    ts4_if_call_seq_fn_88894BA8_88899BF0(parser->init_encoding, &parser->encoding, 0);
    parser->user_data = 0;
    parser->handler_arg = 0;
    parser->start_element_handler = 0;
    parser->end_element_handler = 0;
    parser->character_data_handler = 0;
    parser->processing_instruction_handler = 0;
    parser->comment_handler_fn = 0;
    parser->start_cdata_section_handler = 0;
    parser->end_cdata_section_handler = 0;
    parser->default_handler = 0;
    parser->start_doctype_decl_handler = 0;
    parser->end_doctype_decl_handler = 0;
    parser->unparsed_entity_decl_handler = 0;
    parser->notation_decl_handler = 0;
    parser->start_namespace_decl_handler = 0;
    parser->end_namespace_decl_handler = 0;
    parser->not_standalone_handler = 0;
    parser->external_entity_ref_handler = 0;
    parser->external_entity_ref_handler_arg = parser;
    parser->skipped_entity_handler = 0;
    parser->element_decl_handler = 0;
    parser->attlist_decl_handler = 0;
    parser->entity_decl_handler = 0;
    parser->xml_decl_handler = 0;
    parser->buffer_ptr = parser->buffer;
    parser->buffer_end = parser->buffer;
    parser->parse_end_byte_index = 0;
    parser->parse_end_ptr = 0;
    parser->decl_element_type = 0;
    parser->decl_attribute_id = 0;
    parser->decl_entity = 0;
    parser->doctype_name = 0;
    parser->doctype_sysid = 0;
    parser->doctype_pubid = 0;
    parser->decl_attribute_type = 0;
    parser->decl_notation_name = 0;
    parser->decl_notation_public_id = 0;
    parser->decl_attribute_is_cdata = 0;
    parser->decl_attribute_is_id = 0;
    parser->line_number = 0;
    parser->column_number = 0;
    parser->error_code = 0;
    parser->event_ptr = 0;
    parser->event_end_ptr = 0;
    parser->position_ptr = 0;
    parser->open_internal_entities = 0;
    parser->default_expand_internal_entities = 1;
    parser->tag_level = 0;
    parser->tag_stack = 0;
    parser->inherited_bindings = 0;
    parser->n_specified_atts = 0;
    parser->unknown_encoding_mem = 0;
    parser->unknown_encoding_release = 0;
    parser->unknown_encoding_data = 0;
    parser->parent_parser = 0;
    parser->is_param_entity = 0;
    parser->use_foreign_dtd = 0;
    parser->param_entity_parsing = 0;
}

/* Expat parserCreate (default encoding, no namespace separator). */
d9_xml_parser *ts4_xml_parser_create_888AA6C0(const ts4_xml_memory_suite *ms)
{
    d9_xml_parser *parser;

    if (ms) {
        parser = (d9_xml_parser *)ms->malloc_fcn(sizeof(d9_xml_parser));
        if (parser) {
            void *(*m)(unsigned int) = ms->malloc_fcn;
            void *(*r)(void *, unsigned int) = ms->realloc_fcn;
            void (*f)(void *) = ms->free_fcn;
            parser->free_fcn = f;
            parser->malloc_fcn = m;
            parser->realloc_fcn = r;
        }
    } else {
        parser = (d9_xml_parser *)ts4_crt_nh_malloc_88565258(sizeof(d9_xml_parser));
        if (parser) {
            parser->malloc_fcn = (void *(*)(unsigned int))ts4_crt_nh_malloc_88565258;
            parser->realloc_fcn = fn_88565320;
            parser->free_fcn = fn_885651F8;
        }
    }
    if (!parser)
        return parser;
    parser->buffer = 0;
    parser->buffer_lim = 0;
    parser->atts_size = 16;
    parser->atts = parser->malloc_fcn(0x100);
    if (!parser->atts) {
        parser->free_fcn(parser);
        return 0;
    }
    parser->data_buf = (char *)parser->malloc_fcn(0x400);
    if (!parser->data_buf) {
        parser->free_fcn(parser->atts);
        parser->free_fcn(parser);
        return 0;
    }
    parser->data_buf_end = parser->data_buf + 0x400;
    parser->dtd = ts4_if_get_u32_off0_888A3BC8(&parser->malloc_fcn);
    if (!parser->dtd) {
        parser->free_fcn(parser->data_buf);
        parser->free_fcn(parser->atts);
        parser->free_fcn(parser);
        return 0;
    }
    parser->free_binding_list = 0;
    parser->free_tag_list = 0;
    parser->group_size = 0;
    parser->group_connector = 0;
    parser->unknown_encoding_handler = 0;
    parser->unknown_encoding_handler_data = 0;
    parser->namespace_separator = '!';
    parser->ns = 0;
    parser->ns_triplets = 0;
    pool_init(&parser->temp_pool, (const ts4_xml_memory_suite *)&parser->malloc_fcn);
    pool_init(&parser->temp2_pool, (const ts4_xml_memory_suite *)&parser->malloc_fcn);
    ts4_xml_parser_init_888AA568(parser);
    if (!parser->protocol_encoding_name) {
        ts4_xml_parser_free_888A7110(parser);
        return 0;
    }
    parser->internal_encoding = (const struct ts4_xml_encoding *)lbl_880CF518;
    return parser;
}
