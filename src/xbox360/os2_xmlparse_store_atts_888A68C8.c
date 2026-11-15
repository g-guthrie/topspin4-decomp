/* Derived from Expat 1.95.6 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Swing_DLL.xex 0x888A68C8-0x888A70AC.
 * Family OS2: Expat xmlparse.c storeAtts (XML_NS build): collects the attributes of a start tag, applies the DTD
 * defaults, expands prefixed names and the element name. */
#include "d9ex_xmlparse.h"

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

extern void *ts4_xml_lookup_888A5060(ts4_xml_hash_table *table, const char *name, unsigned int create_size);
extern const char *ts4_xml_pool_copy_string_888A3358(ts4_xml_string_pool *pool, const char *s);
extern int ts4_xml_set_element_type_prefix_888A5890(d9_xml_parser *parser, ts4_xml_element_type *element_type);
extern ts4_xml_attribute_id *ts4_xml_get_attribute_id_888A5608(d9_xml_parser *parser,
                                                               const struct ts4_xml_encoding *enc, const char *start,
                                                               const char *end);
extern int ts4_xml_store_attribute_value_888A6508(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                                  unsigned char is_cdata, const char *ptr, const char *end,
                                                  ts4_xml_string_pool *pool);
extern char *ts4_xml_pool_append_888A35A8(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc,
                                          const char *ptr, const char *end);
extern char *ts4_if_call_seq_u32_off8_888A4FE0(ts4_xml_string_pool *pool);
extern unsigned char ts4_xml_pool_grow_888A2F00(ts4_xml_string_pool *pool);
#ifndef OS2_LOCAL_ADD_BINDING
extern int ts4_xml_add_binding_888A4938(d9_xml_parser *parser, ts4_xml_prefix *prefix, const void *att_id,
                                        const char *uri, ts4_xml_binding **bindings_ptr);
#endif

/* The caller's translation unit (doContent) includes this file with a static, out-of-line linkage so that the
 * compiler sees what storeAtts does with the addresses it is given. */
#ifndef OS2_STORE_ATTS_LINKAGE
#define OS2_STORE_ATTS_LINKAGE
#endif

#define OS2_EXPAND_SPARE 24
#define OS2_INIT_ATTS_SIZE 16

/* Expat ATTRIBUTE (16 bytes) and TAG_NAME */
typedef struct os2_attribute {
    const char *name;      /* +0x00 */
    const char *value_ptr; /* +0x04 */
    const char *value_end; /* +0x08 */
    char normalized;       /* +0x0C */
} os2_attribute;

typedef struct os2_tag_name {
    const char *str;        /* +0x00 */
    const char *local_part; /* +0x04 */
    const char *prefix;     /* +0x08 */
    int str_len;            /* +0x0C */
    int uri_len;            /* +0x10 */
    int prefix_len;         /* +0x14 */
} os2_tag_name;

/* BINDING.prefix is a PREFIX pointer in Expat (the shared header types it loosely) */
#define BPREFIX(b) ((ts4_xml_prefix *)(b)->prefix)

/* Expat's `atts` is a macro for the parser member: every use reloads it */
#define OS2_ATTS(p) ((os2_attribute *)(p)->atts)

/* Expat poolAppendChar */
#define OS2_POOL_APPEND_CHAR(pool, c) \
    (((pool)->ptr == (pool)->end && !ts4_xml_pool_grow_888A2F00(pool)) ? 0 : ((*((pool)->ptr)++ = (c)), 1))
#ifdef _MSC_VER
#define OS2_FORCEINLINE static __forceinline
#else
#define OS2_FORCEINLINE static inline
#endif
/* Expat poolStoreString */
OS2_FORCEINLINE char *os2_pool_store_string(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc,
                                            const char *ptr, const char *end)
{
    if (!ts4_xml_pool_append_888A35A8(pool, enc, ptr, end))
        return 0;
    return ts4_if_call_seq_u32_off8_888A4FE0(pool);
}
#define OS2_POOL_STORE_STRING(pool, enc, a, b) os2_pool_store_string((pool), (enc), (a), (b))


OS2_STORE_ATTS_LINKAGE int os2_xml_store_atts_888A68C8(d9_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                                       const char *att_str, os2_tag_name *tag_name_ptr,
                                                       ts4_xml_binding **bindings_ptr)
{
    ts4_xml_dtd *const dtd = parser->dtd;
    ts4_xml_element_type *element_type;
    int n_default_atts;
    const char **app_atts;
    int att_index = 0;
    int prefix_len;
    int i;
    int n;
    char *uri;
    int n_prefixes = 0;
    ts4_xml_binding *binding;
    const char *local_part;

    element_type = (ts4_xml_element_type *)ts4_xml_lookup_888A5060(&dtd->element_types, tag_name_ptr->str, 0);
    if (!element_type) {
        const char *name = ts4_xml_pool_copy_string_888A3358(&dtd->pool, tag_name_ptr->str);
        if (!name)
            return 1;
        element_type = (ts4_xml_element_type *)ts4_xml_lookup_888A5060(&dtd->element_types, name,
                                                                       sizeof(ts4_xml_element_type));
        if (!element_type)
            return 1;
        if (parser->ns && !ts4_xml_set_element_type_prefix_888A5890(parser, element_type))
            return 1;
    }
    n_default_atts = element_type->n_default_atts;

    n = enc->get_atts(enc, att_str, parser->atts_size, parser->atts);
    if (n + n_default_atts > parser->atts_size) {
        int old_atts_size = parser->atts_size;
        void *temp;
        parser->atts_size = n + n_default_atts + OS2_INIT_ATTS_SIZE;
        temp = parser->realloc_fcn(parser->atts, parser->atts_size * sizeof(os2_attribute));
        if (temp == 0)
            return 1;
        parser->atts = temp;
        if (n > old_atts_size)
            enc->get_atts(enc, att_str, n, parser->atts);
    }

    app_atts = (const char **)parser->atts;
    for (i = 0; i < n; i++) {
        ts4_xml_attribute_id *att_id = ts4_xml_get_attribute_id_888A5608(
            parser, enc, OS2_ATTS(parser)[i].name, OS2_ATTS(parser)[i].name + enc->name_length(enc, OS2_ATTS(parser)[i].name));
        if (!att_id)
            return 1;
        if ((att_id->name)[-1]) {
            if (enc == parser->encoding)
                parser->event_ptr = OS2_ATTS(parser)[i].name;
            return 8;
        }
        (att_id->name)[-1] = 1;
        app_atts[att_index++] = att_id->name;
        if (!OS2_ATTS(parser)[i].normalized) {
            int result;
            unsigned char is_cdata = 1;
            if (att_id->maybe_tokenized) {
                int j;
                for (j = 0; j < n_default_atts; j++) {
                    if (att_id == element_type->default_atts[j].id) {
                        is_cdata = element_type->default_atts[j].is_cdata;
                        break;
                    }
                }
            }
            result = ts4_xml_store_attribute_value_888A6508(parser, enc, is_cdata, OS2_ATTS(parser)[i].value_ptr,
                                                            OS2_ATTS(parser)[i].value_end, &parser->temp_pool);
            if (result)
                return result;
            app_atts[att_index] = parser->temp_pool.start;
            parser->temp_pool.start = parser->temp_pool.ptr;
        } else {
            app_atts[att_index] = OS2_POOL_STORE_STRING(&parser->temp_pool, enc, OS2_ATTS(parser)[i].value_ptr, OS2_ATTS(parser)[i].value_end);
            if (app_atts[att_index] == 0)
                return 1;
            parser->temp_pool.start = parser->temp_pool.ptr;
        }
        if (att_id->prefix) {
            if (att_id->xmlns) {
                int result = ts4_xml_add_binding_888A4938(parser, att_id->prefix, att_id, app_atts[att_index],
                                                          bindings_ptr);
                if (result)
                    return result;
                --att_index;
            } else {
                att_index++;
                n_prefixes++;
                (att_id->name)[-1] = 2;
            }
        } else
            att_index++;
    }

    parser->n_specified_atts = att_index;
    if (element_type->id_att && (element_type->id_att->name)[-1]) {
        for (i = 0; i < att_index; i += 2)
            if (app_atts[i] == element_type->id_att->name) {
                parser->id_att_index = i;
                break;
            }
    } else
        parser->id_att_index = -1;

    for (i = 0; i < n_default_atts; i++) {
        const ts4_xml_default_attribute *da = element_type->default_atts + i;
        if (!(da->id->name)[-1] && da->value) {
            if (da->id->prefix) {
                if (da->id->xmlns) {
                    int result = ts4_xml_add_binding_888A4938(parser, da->id->prefix, da->id, da->value,
                                                              bindings_ptr);
                    if (result)
                        return result;
                } else {
                    (da->id->name)[-1] = 2;
                    n_prefixes++;
                    app_atts[att_index++] = da->id->name;
                    app_atts[att_index++] = da->value;
                }
            } else {
                (da->id->name)[-1] = 1;
                app_atts[att_index++] = da->id->name;
                app_atts[att_index++] = da->value;
            }
        }
    }
    app_atts[att_index] = 0;

    i = 0;
    if (n_prefixes) {
        for (; i < att_index; i += 2) {
            if (app_atts[i][-1] == 2) {
                ts4_xml_attribute_id *id;
                ((char *)(app_atts[i]))[-1] = 0;
                id = (ts4_xml_attribute_id *)ts4_xml_lookup_888A5060(&dtd->attribute_ids, app_atts[i], 0);
                if (id->prefix->binding) {
                    int j;
                    const ts4_xml_binding *b = id->prefix->binding;
                    const char *s = app_atts[i];
                    for (j = 0; j < b->uri_len; j++) {
                        if (!OS2_POOL_APPEND_CHAR(&parser->temp_pool, b->uri[j]))
                            return 1;
                    }
                    while (*s++ != ':')
                        ;
                    do {
                        if (!OS2_POOL_APPEND_CHAR(&parser->temp_pool, *s))
                            return 1;
                    } while (*s++);
                    if (parser->ns_triplets) {
                        parser->temp_pool.ptr[-1] = parser->namespace_separator;
                        s = BPREFIX(b)->name;
                        do {
                            if (!OS2_POOL_APPEND_CHAR(&parser->temp_pool, *s))
                                return 1;
                        } while (*s++);
                    }
                    app_atts[i] = parser->temp_pool.start;
                    parser->temp_pool.start = parser->temp_pool.ptr;
                }
                if (!--n_prefixes)
                    break;
            } else
                ((char *)(app_atts[i]))[-1] = 0;
        }
    }
    for (; i < att_index; i += 2)
        ((char *)(app_atts[i]))[-1] = 0;
    for (binding = *bindings_ptr; binding; binding = binding->next_tag_binding)
        ((ts4_xml_attribute_id *)binding->att_id)->name[-1] = 0;

    if (element_type->prefix) {
        binding = element_type->prefix->binding;
        if (!binding)
            return 0;
        local_part = tag_name_ptr->str;
        while (*local_part++ != ':')
            ;
    } else if (dtd->default_prefix.binding) {
        binding = dtd->default_prefix.binding;
        local_part = tag_name_ptr->str;
    } else
        return 0;
    prefix_len = 0;
    if (parser->ns && parser->ns_triplets && BPREFIX(binding)->name) {
        for (; BPREFIX(binding)->name[prefix_len++];)
            ;
    }
    tag_name_ptr->local_part = local_part;
    tag_name_ptr->uri_len = binding->uri_len;
    tag_name_ptr->prefix = BPREFIX(binding)->name;
    tag_name_ptr->prefix_len = prefix_len;
    for (i = 0; local_part[i++];)
        ;
    n = i + binding->uri_len + prefix_len;
    if (n > binding->uri_alloc) {
        d9_tag *p;
        uri = (char *)parser->malloc_fcn((n + OS2_EXPAND_SPARE) * sizeof(char));
        if (!uri)
            return 1;
        binding->uri_alloc = n + OS2_EXPAND_SPARE;
        memcpy(uri, binding->uri, binding->uri_len * sizeof(char));
        for (p = parser->tag_stack; p; p = p->parent)
            if (p->name_str == binding->uri)
                p->name_str = uri;
        parser->free_fcn(binding->uri);
        binding->uri = uri;
    }
    uri = binding->uri + binding->uri_len;
    memcpy(uri, local_part, i * sizeof(char));
    if (prefix_len) {
        uri = uri + (i - 1);
        if (parser->namespace_separator) {
            *(uri) = parser->namespace_separator;
        }
        memcpy(uri + 1, BPREFIX(binding)->name, prefix_len * sizeof(char));
    }
    tag_name_ptr->str = binding->uri;
    return 0;
}
