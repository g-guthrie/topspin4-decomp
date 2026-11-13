/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "r3_xmlparse.h"
#include "r3_xmltok.h"

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

/* Recursive self-call target kept as its placeholder: other code references it too. */
extern void ts4_xml_build_content_node_888A2C58(ts4_xml_parser *parser, int src_node, ts4_xml_content *dest,
                        ts4_xml_content **contpos, char **strpos);

#define TS4_XML_CTYPE_NAME 4
#define TS4_XML_INIT_SCAFFOLD_ELEMENTS 32

/* Allocate the next content-model scaffold node and link it to its parent
 * (Expat nextScaffoldPart). Returns node index or -1 on allocation failure.
 * Swing_DLL.xex 0x888A2DB8 */
int ts4_xml_next_scaffold_part_888A2DB8(ts4_xml_parser *parser)
{
    ts4_xml_dtd *const dtd = parser->dtd;
    ts4_xml_content_scaffold *me;
    int next;

    if (!dtd->scaff_index) {
        dtd->scaff_index = (int *)parser->malloc_fcn(parser->group_size * sizeof(int));
        if (!dtd->scaff_index)
            return -1;
        dtd->scaff_index[0] = 0;
    }

    if (dtd->scaff_count >= dtd->scaff_size) {
        ts4_xml_content_scaffold *temp;
        if (dtd->scaffold) {
            temp = (ts4_xml_content_scaffold *)parser->realloc_fcn(
                dtd->scaffold, dtd->scaff_size * 2 * sizeof(ts4_xml_content_scaffold));
            if (temp == 0)
                return -1;
            dtd->scaff_size *= 2;
        } else {
            temp = (ts4_xml_content_scaffold *)parser->malloc_fcn(
                TS4_XML_INIT_SCAFFOLD_ELEMENTS * sizeof(ts4_xml_content_scaffold));
            if (temp == 0)
                return -1;
            dtd->scaff_size = TS4_XML_INIT_SCAFFOLD_ELEMENTS;
        }
        dtd->scaffold = temp;
    }
    next = dtd->scaff_count++;
    me = &dtd->scaffold[next];
    if (dtd->scaff_level) {
        ts4_xml_content_scaffold *parent = &dtd->scaffold[dtd->scaff_index[dtd->scaff_level - 1]];
        if (parent->lastchild) {
            dtd->scaffold[parent->lastchild].nextsib = next;
        }
        if (!parent->childcnt)
            parent->firstchild = next;
        parent->lastchild = next;
        parent->childcnt++;
    }
    me->firstchild = me->lastchild = me->childcnt = me->nextsib = 0;
    return next;
}

/* Copy one scaffold node (recursively) into the flat XML_Content array handed to the user
 * (Expat build_node). Swing_DLL.xex 0x888A2C58 */
void ts4_xml_build_content_node_888A2C58(ts4_xml_parser *parser, int src_node, ts4_xml_content *dest,
                                         ts4_xml_content **contpos, char **strpos)
{
    ts4_xml_dtd *const dtd = parser->dtd;
    dest->type = dtd->scaffold[src_node].type;
    dest->quant = dtd->scaffold[src_node].quant;
    if (dest->type == TS4_XML_CTYPE_NAME) {
        const char *src;
        dest->name = *strpos;
        src = dtd->scaffold[src_node].name;
        for (;;) {
            *(*strpos)++ = *src;
            if (!*src)
                break;
            src++;
        }
        dest->numchildren = 0;
        dest->children = 0;
    } else {
        unsigned int i;
        int cn;
        dest->numchildren = dtd->scaffold[src_node].childcnt;
        dest->children = *contpos;
        *contpos += dest->numchildren;
        for (i = 0, cn = dtd->scaffold[src_node].firstchild; i < dest->numchildren;
             i++, cn = dtd->scaffold[cn].nextsib) {
            ts4_xml_build_content_node_888A2C58(parser, cn, &(dest->children[i]), contpos, strpos);
        }
        dest->name = 0;
    }
}

#define TS4_XML_INIT_BLOCK_SIZE 1024

#ifdef _MSC_VER
#define TS4_FORCEINLINE __forceinline
#else
#define TS4_FORCEINLINE static inline
#endif

/* Out-of-line copy of poolGrow, called through its original placeholder where the compiler did not inline it. */
extern unsigned char ts4_xml_pool_grow_888A2F00(ts4_xml_string_pool *pool);

/* Grow the string pool so more characters fit (Expat poolGrow).
 * Swing_DLL.xex 0x888A2F00 */
#define TS4_XML_POOL_GROW_BODY \
    if (pool->free_blocks) { \
        if (pool->start == 0) { \
            pool->blocks = pool->free_blocks; \
            pool->free_blocks = pool->free_blocks->next; \
            pool->blocks->next = 0; \
            pool->start = pool->blocks->s; \
            pool->end = pool->start + pool->blocks->size; \
            pool->ptr = pool->start; \
            return 1; \
        } \
        if (pool->end - pool->start < pool->free_blocks->size) { \
            ts4_xml_block *tem = pool->free_blocks->next; \
            pool->free_blocks->next = pool->blocks; \
            pool->blocks = pool->free_blocks; \
            pool->free_blocks = tem; \
            memcpy(pool->blocks->s, pool->start, (pool->end - pool->start)); \
            pool->ptr = pool->blocks->s + (pool->ptr - pool->start); \
            pool->start = pool->blocks->s; \
            pool->end = pool->start + pool->blocks->size; \
            return 1; \
        } \
    } \
    if (pool->blocks && pool->start == pool->blocks->s) { \
        int block_size = (int)(pool->end - pool->start) * 2; \
        pool->blocks = (ts4_xml_block *)pool->mem->realloc_fcn(pool->blocks, 8 + block_size); \
        if (pool->blocks == 0) \
            return 0; \
        pool->blocks->size = block_size; \
        pool->ptr = pool->blocks->s + (pool->ptr - pool->start); \
        pool->start = pool->blocks->s; \
        pool->end = pool->start + block_size; \
    } else { \
        ts4_xml_block *tem; \
        int block_size = (int)(pool->end - pool->start); \
        if (block_size < TS4_XML_INIT_BLOCK_SIZE) \
            block_size = TS4_XML_INIT_BLOCK_SIZE; \
        else \
            block_size *= 2; \
        tem = (ts4_xml_block *)pool->mem->malloc_fcn(8 + block_size); \
        if (!tem) \
            return 0; \
        tem->size = block_size; \
        tem->next = pool->blocks; \
        pool->blocks = tem; \
        if (pool->ptr != pool->start) \
            memcpy(tem->s, pool->start, (pool->ptr - pool->start)); \
        pool->ptr = tem->s + (pool->ptr - pool->start); \
        pool->start = tem->s; \
        pool->end = tem->s + block_size; \
    } \
    return 1;

/* Inlinable copy of poolGrow (used where the compiler inlined it into callers). */
TS4_FORCEINLINE unsigned char ts4_xml_pool_grow_inline(ts4_xml_string_pool *pool)
{
    TS4_XML_POOL_GROW_BODY
}

/* Expat poolGrow. Swing_DLL.xex 0x888A2F00 */
unsigned char ts4_xml_pool_grow_888A2F00(ts4_xml_string_pool *pool)
{
    TS4_XML_POOL_GROW_BODY
}

/* Append a NUL-terminated string to the pool, growing as needed (Expat poolAppendString);
 * returns the pool start or NULL on allocation failure.
 * Swing_DLL.xex 0x888A3100 */
char *ts4_xml_pool_append_string_888A3100(ts4_xml_string_pool *pool, const char *s)
{
    while (*s) {
        if (!(((pool)->ptr == (pool)->end && !ts4_xml_pool_grow_inline(pool)) ? 0 : ((*((pool)->ptr)++ = *s), 1)))
            return 0;
        s++;
    }
    return pool->start;
}

#define TS4_XML_POOL_APPEND_CHAR(pool, c) \
    (((pool)->ptr == (pool)->end && !ts4_xml_pool_grow_inline(pool)) ? 0 : ((*((pool)->ptr)++ = (c)), 1))

/* Copy a NUL-terminated string into the pool, finish the string, return its start
 * (Expat poolCopyString).
 * Swing_DLL.xex 0x888A3358 */
const char *ts4_xml_pool_copy_string_888A3358(ts4_xml_string_pool *pool, const char *s)
{
    do {
        if (!TS4_XML_POOL_APPEND_CHAR(pool, *s))
            return 0;
    } while (*s++);
    s = pool->start;
    pool->start = pool->ptr;
    return s;
}

/* Convert and append a byte range through the encoding's UTF-8 converter, growing the pool as needed
 * (Expat poolAppend). Returns the pool start or NULL on allocation failure.
 * Swing_DLL.xex 0x888A35A8 */
char *ts4_xml_pool_append_888A35A8(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc,
                                   const char *ptr, const char *end)
{
    if (!pool->ptr && !ts4_xml_pool_grow_888A2F00(pool))
        return 0;
    for (;;) {
        enc->utf8_convert(enc, &ptr, end, &(pool->ptr), pool->end);
        if (ptr == end)
            break;
        if (!ts4_xml_pool_grow_inline(pool))
            return 0;
    }
    return pool->start;
}

#define TS4_XML_POOL_INIT(pool, ms) \
    ((pool)->blocks = 0, (pool)->free_blocks = 0, (pool)->start = 0, (pool)->ptr = 0, (pool)->end = 0, (pool)->mem = (ms))
#define TS4_XML_HASH_INIT(table, ms) \
    ((table)->size = 0, (table)->used_lim = 0, (table)->used = 0, (table)->v = 0, (table)->mem = (ms))


/* poolAppendChar through the out-of-line poolGrow. */
#define TS4_XML_POOL_APPEND_CHAR_CALL(pool, c) \
    (((pool)->ptr == (pool)->end && !ts4_xml_pool_grow_888A2F00(pool)) ? 0 : ((*((pool)->ptr)++ = (c)), 1))

/* Walk a hash table's bucket vector (Expat HASH_TABLE_ITER); evaluates to the next non-NULL entry or 0. */
#define TS4_XML_CONTEXT_SEP 0x0C

/* Build the "prefix=uri\fprefix=uri\fentity" context string for an external entity
 * parser (Expat getContext); returns the pool start or NULL on allocation failure.
 * Swing_DLL.xex 0x888A3D88 */
const char *ts4_xml_get_context_888A3D88(ts4_xml_parser *parser)
{
    ts4_xml_dtd *const dtd = parser->dtd;
    void **iter_p;
    void **iter_end;
    unsigned char need_sep = 0;

    if (dtd->default_prefix.binding) {
        int i;
        int len;
        if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, '='))
            return 0;
        len = dtd->default_prefix.binding->uri_len;
        if (parser->namespace_separator)
            len--;
        for (i = 0; i < len; i++)
            if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, dtd->default_prefix.binding->uri[i]))
                return 0;
        need_sep = 1;
    }

    iter_p = dtd->prefixes.v;
    iter_end = iter_p + dtd->prefixes.size;
    for (;;) {
        int i;
        int len;
        const char *s;
        ts4_xml_prefix *prefix = 0;
        while (iter_p != iter_end) {
            prefix = (ts4_xml_prefix *)*iter_p++;
            if (prefix)
                break;
        }
        if (!prefix)
            break;
        if (!prefix->binding)
            continue;
        if (need_sep && !TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, TS4_XML_CONTEXT_SEP))
            return 0;
        for (s = prefix->name; *s; s++)
            if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, *s))
                return 0;
        if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, '='))
            return 0;
        len = prefix->binding->uri_len;
        if (parser->namespace_separator)
            len--;
        for (i = 0; i < len; i++)
            if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, prefix->binding->uri[i]))
                return 0;
        need_sep = 1;
    }

    iter_p = dtd->general_entities.v;
    iter_end = iter_p + dtd->general_entities.size;
    for (;;) {
        const char *s;
        ts4_xml_entity *e = 0;
        while (iter_p != iter_end) {
            e = (ts4_xml_entity *)*iter_p++;
            if (e)
                break;
        }
        if (!e)
            break;
        if (!e->open)
            continue;
        if (need_sep && !TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, TS4_XML_CONTEXT_SEP))
            return 0;
        for (s = e->name; *s; s++)
            if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, *s))
                return 0;
        need_sep = 1;
    }

    if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, '\0'))
        return 0;
    return parser->temp_pool.start;
}

/* Add a default attribute to an element type declaration (Expat defineAttribute); returns 1 on success.
 * Swing_DLL.xex 0x888A4120 */
int ts4_xml_define_attribute_888A4120(ts4_xml_element_type *type, ts4_xml_attribute_id *att_id,
                                      unsigned char is_cdata, unsigned char is_id, const char *value,
                                      ts4_xml_parser *parser)
{
    ts4_xml_default_attribute *att;
    if (value || is_id) {
        int i;
        for (i = 0; i < type->n_default_atts; i++)
            if (att_id == type->default_atts[i].id)
                return 1;
        if (is_id && !type->id_att && !att_id->xmlns)
            type->id_att = att_id;
    }
    if (type->n_default_atts == type->alloc_default_atts) {
        if (type->alloc_default_atts == 0) {
            type->alloc_default_atts = 8;
            type->default_atts = (ts4_xml_default_attribute *)parser->malloc_fcn(
                type->alloc_default_atts * sizeof(ts4_xml_default_attribute));
            if (!type->default_atts)
                return 0;
        } else {
            ts4_xml_default_attribute *temp;
            int count = type->alloc_default_atts * 2;
            temp = (ts4_xml_default_attribute *)parser->realloc_fcn(
                type->default_atts, (count * sizeof(ts4_xml_default_attribute)));
            if (temp == 0)
                return 0;
            type->alloc_default_atts = count;
            type->default_atts = temp;
        }
    }
    att = type->default_atts + type->n_default_atts;
    att->id = att_id;
    att->value = value;
    att->is_cdata = is_cdata;
    if (!is_cdata)
        att_id->maybe_tokenized = 1;
    type->n_default_atts += 1;
    return 1;
}

/* Default-handler reporting helper (Expat reportDefault), placeholder callee. */
extern void fn_888A4278(ts4_xml_parser *parser, const struct ts4_xml_encoding *enc, const char *s, const char *end);

#define TS4_XML_TOK_NONE (-4)
#define TS4_XML_TOK_PARTIAL (-1)
#define TS4_XML_TOK_PARTIAL_CHAR (-2)
#define TS4_XML_TOK_IGNORE_SECT 42

/* Scan one INCLUDE/IGNORE conditional-section token (Expat doIgnoreSection); returns an XML error code.
 * Swing_DLL.xex 0x888A4460 */
int ts4_xml_do_ignore_section_888A4460(ts4_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                       const char **start_ptr, const char *end, const char **next_ptr)
{
    const char *next;
    int tok;
    const char *s = *start_ptr;
    const char **event_pp;
    const char **event_end_pp;
    if (enc == parser->encoding) {
        event_pp = &parser->event_ptr;
        *event_pp = s;
        event_end_pp = &parser->event_end_ptr;
    } else {
        event_pp = &(parser->open_internal_entities->internal_event_ptr);
        event_end_pp = &(parser->open_internal_entities->internal_event_end_ptr);
    }
    *event_pp = s;
    *start_ptr = 0;
    tok = enc->scanners[3](enc, s, end, &next);
    *event_end_pp = next;
    switch (tok) {
    case TS4_XML_TOK_IGNORE_SECT:
        if (parser->default_handler)
            fn_888A4278(parser, enc, s, next);
        *start_ptr = next;
        return 0;
    case 0:
        *event_pp = next;
        return 4;
    case TS4_XML_TOK_PARTIAL_CHAR:
        if (next_ptr) {
            *next_ptr = s;
            return 0;
        }
        return 6;
    case TS4_XML_TOK_PARTIAL:
    case TS4_XML_TOK_NONE:
        if (next_ptr) {
            *next_ptr = s;
            return 0;
        }
        return 2;
    default:
        *event_pp = next;
        return 23;
    }
}

#define TS4_XML_EXPAND_SPARE 24

/* Bind a namespace prefix to a URI and push the binding on the tag's binding list
 * (Expat addBinding); returns an XML error code.
 * Swing_DLL.xex 0x888A4938 */
int ts4_xml_add_binding_888A4938(ts4_xml_parser *parser, ts4_xml_prefix *prefix, const void *att_id,
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
            char *temp = (char *)parser->realloc_fcn(b->uri, sizeof(char) * (len + TS4_XML_EXPAND_SPARE));
            if (temp == 0)
                return 1;
            b->uri = temp;
            b->uri_alloc = len + TS4_XML_EXPAND_SPARE;
        }
        parser->free_binding_list = b->next_tag_binding;
    } else {
        b = (ts4_xml_binding *)parser->malloc_fcn(sizeof(ts4_xml_binding));
        if (!b)
            return 1;
        b->uri = (char *)parser->malloc_fcn(sizeof(char) * (len + TS4_XML_EXPAND_SPARE));
        if (!b->uri) {
            parser->free_fcn(b);
            return 1;
        }
        b->uri_alloc = len + TS4_XML_EXPAND_SPARE;
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
        parser->start_namespace_decl_handler(parser->handler_arg, prefix->name, prefix->binding ? uri : 0);
    return 0;
}

/* memmove placeholder in the original symbol table. */
extern void *fn_88562DC0(void *dest, const void *src, unsigned int count);

#define TS4_XML_CONTEXT_BYTES 1024
#define TS4_XML_INIT_BUFFER_SIZE 1024

/* Ensure at least len bytes of free input buffer, keeping up to CONTEXT_BYTES of old data
 * (Expat XML_GetBuffer); returns the write pointer or NULL on out of memory.
 * Swing_DLL.xex 0x888A4BE0 */
void *ts4_xml_get_buffer_888A4BE0(ts4_xml_parser *parser, int len)
{
    if (len > parser->buffer_lim - parser->buffer_end) {
        int needed_size = len + (int)(parser->buffer_end - parser->buffer_ptr);
        int keep = (int)(parser->buffer_ptr - parser->buffer);
        if (keep > TS4_XML_CONTEXT_BYTES)
            keep = TS4_XML_CONTEXT_BYTES;
        needed_size += keep;
        if (needed_size <= parser->buffer_lim - parser->buffer) {
            if (keep < parser->buffer_ptr - parser->buffer) {
                int offset = (int)(parser->buffer_ptr - parser->buffer) - keep;
                fn_88562DC0(parser->buffer, &parser->buffer[offset], parser->buffer_end - parser->buffer_ptr + keep);
                parser->buffer_end -= offset;
                parser->buffer_ptr -= offset;
            }
        } else {
            char *new_buf;
            int buffer_size = (int)(parser->buffer_lim - parser->buffer_ptr);
            if (buffer_size == 0)
                buffer_size = TS4_XML_INIT_BUFFER_SIZE;
            do {
                buffer_size *= 2;
            } while (buffer_size < needed_size);
            new_buf = (char *)parser->malloc_fcn(buffer_size);
            if (new_buf == 0) {
                parser->error_code = 1;
                return 0;
            }
            parser->buffer_lim = new_buf + buffer_size;
            if (parser->buffer_ptr) {
                int keep2 = (int)(parser->buffer_ptr - parser->buffer);
                if (keep2 > TS4_XML_CONTEXT_BYTES)
                    keep2 = TS4_XML_CONTEXT_BYTES;
                memcpy(new_buf, &parser->buffer_ptr[-keep2], parser->buffer_end - parser->buffer_ptr + keep2);
                parser->free_fcn(parser->buffer);
                parser->buffer = new_buf;
                parser->buffer_end = parser->buffer + (parser->buffer_end - parser->buffer_ptr) + keep2;
                parser->buffer_ptr = parser->buffer + keep2;
            } else {
                parser->buffer_end = new_buf + (parser->buffer_end - parser->buffer_ptr);
                parser->buffer_ptr = parser->buffer = new_buf;
            }
        }
    }
    return parser->buffer_end;
}

/* Placeholders for helpers outside this file. */
extern int fn_888A3A80(const char *s1, const char *s2); /* Expat keyeq */
#ifdef _MSC_VER
extern void *memset(void *dest, int value, unsigned int count); /* memset */
#endif

#define TS4_XML_HASH_INIT_SIZE 64

/* Expat hash(): h = h * 33 + byte. */
static unsigned long ts4_xml_hash(const char *s)
{
    unsigned long h = 0;
    while (*s)
        h = (h << 5) + h + (unsigned char)*s++;
    return h;
}

typedef struct ts4_xml_named {
    const char *name;
} ts4_xml_named;


/* Implicit namespace context string ("xml=http://www.w3.org/XML/1998/namespace" style) in .rdata. */
extern const char lbl_880D0614[];
/* Placeholders for sibling functions (copy string, add binding, lookup) kept at their original names. */
extern const char *ts4_xml_pool_copy_string_888A3358(ts4_xml_string_pool *pool, const char *s);
extern int ts4_xml_add_binding_888A4938(ts4_xml_parser *parser, ts4_xml_prefix *prefix, const void *att_id, const char *uri,
                       ts4_xml_binding **bindings_ptr);
extern ts4_xml_named *fn_888A5060(ts4_xml_hash_table *table, const char *name, unsigned int create_size);

#define TS4_XML_POOL_START(pool) ((pool)->start)
#define TS4_XML_POOL_LENGTH(pool) ((pool)->ptr - (pool)->start)
#define TS4_XML_POOL_DISCARD(pool) ((pool)->ptr = (pool)->start)

/* Register the implicit "xml" prefix context: split "prefix=uri\f..." and open entities
 * (Expat setContext applied to the implicit context string).
 * Swing_DLL.xex 0x888A5370 */
unsigned char ts4_xml_set_implicit_context_888A5370(ts4_xml_parser *parser)
{
    ts4_xml_dtd *const dtd = parser->dtd;
    const char *context = lbl_880D0614;
    const char *s = context;

    do {
        if (*s == TS4_XML_CONTEXT_SEP || *s == '\0') {
            ts4_xml_entity *e;
            if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, '\0'))
                return 0;
            e = (ts4_xml_entity *)fn_888A5060(&dtd->general_entities, TS4_XML_POOL_START(&parser->temp_pool), 0);
            if (e)
                e->open = 1;
            if (*s != '\0')
                s++;
            context = s;
            TS4_XML_POOL_DISCARD(&parser->temp_pool);
        } else if (*s == '=') {
            ts4_xml_prefix *prefix;
            if (TS4_XML_POOL_LENGTH(&parser->temp_pool) == 0)
                prefix = &dtd->default_prefix;
            else {
                if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, '\0'))
                    return 0;
                prefix = (ts4_xml_prefix *)fn_888A5060(&dtd->prefixes, TS4_XML_POOL_START(&parser->temp_pool),
                                                       sizeof(ts4_xml_prefix));
                if (!prefix)
                    return 0;
                if (prefix->name == TS4_XML_POOL_START(&parser->temp_pool)) {
                    prefix->name = ts4_xml_pool_copy_string_888A3358(&dtd->pool, prefix->name);
                    if (!prefix->name)
                        return 0;
                }
                TS4_XML_POOL_DISCARD(&parser->temp_pool);
            }
            for (context = s + 1; *context != TS4_XML_CONTEXT_SEP && *context != '\0'; context++)
                if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, *context))
                    return 0;
            if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, '\0'))
                return 0;
            if (ts4_xml_add_binding_888A4938(parser, prefix, 0, TS4_XML_POOL_START(&parser->temp_pool), &parser->inherited_bindings) != 0)
                return 0;
            TS4_XML_POOL_DISCARD(&parser->temp_pool);
            if (*context != '\0')
                ++context;
            s = context;
        } else {
            if (!TS4_XML_POOL_APPEND_CHAR_CALL(&parser->temp_pool, *s))
                return 0;
            s++;
        }
    } while (*context != '\0'); /* the implicit context string is never empty */
    return 1;
}

#define TS4_XML_POOL_FINISH(pool) ((pool)->start = (pool)->ptr)

/* Split an element type name at ':' and attach the namespace prefix entry
 * (Expat setElementTypePrefix); returns 1 on success, 0 on allocation failure.
 * Swing_DLL.xex 0x888A5890 */
int ts4_xml_set_element_type_prefix_888A5890(ts4_xml_parser *parser, ts4_xml_element_type *element_type)
{
    ts4_xml_dtd *const dtd = parser->dtd;
    const char *name;
    for (name = element_type->name; *name; name++) {
        if (*name == ':') {
            ts4_xml_prefix *prefix;
            const char *s;
            for (s = element_type->name; s != name; s++) {
                if (!TS4_XML_POOL_APPEND_CHAR_CALL(&dtd->pool, *s))
                    return 0;
            }
            if (!TS4_XML_POOL_APPEND_CHAR_CALL(&dtd->pool, '\0'))
                return 0;
            prefix = (ts4_xml_prefix *)fn_888A5060(&dtd->prefixes, TS4_XML_POOL_START(&dtd->pool), sizeof(ts4_xml_prefix));
            if (!prefix)
                return 0;
            if (prefix->name == TS4_XML_POOL_START(&dtd->pool))
                TS4_XML_POOL_FINISH(&dtd->pool);
            else
                TS4_XML_POOL_DISCARD(&dtd->pool);
            element_type->prefix = prefix;
        }
    }
    return 1;
}

/* Placeholders: poolAppend and the pool string terminator step of poolStoreString. */
extern char *ts4_xml_pool_append_888A35A8(ts4_xml_string_pool *pool, const struct ts4_xml_encoding *enc, const char *ptr, const char *end);
extern char *fn_888A4FE0(ts4_xml_string_pool *pool);

/* Intern an attribute name in the DTD and resolve its namespace prefix (Expat getAttributeId).
 * Swing_DLL.xex 0x888A5608 */
ts4_xml_attribute_id *ts4_xml_get_attribute_id_888A5608(ts4_xml_parser *parser, const struct ts4_xml_encoding *enc,
                                                        const char *start, const char *end)
{
    ts4_xml_dtd *const dtd = parser->dtd;
    ts4_xml_attribute_id *id;
    const char *name;
    if (!TS4_XML_POOL_APPEND_CHAR_CALL(&dtd->pool, '\0'))
        return 0;
    if (!ts4_xml_pool_append_888A35A8(&dtd->pool, enc, start, end))
        return 0;
    name = fn_888A4FE0(&dtd->pool);
    if (!name)
        return 0;
    ++name;
    id = (ts4_xml_attribute_id *)fn_888A5060(&dtd->attribute_ids, name, sizeof(ts4_xml_attribute_id));
    if (!id)
        return 0;
    if (id->name != name)
        TS4_XML_POOL_DISCARD(&dtd->pool);
    else {
        TS4_XML_POOL_FINISH(&dtd->pool);
        if (!parser->ns)
            ;
        else if (name[0] == 'x' && name[1] == 'm' && name[2] == 'l' && name[3] == 'n' && name[4] == 's' &&
                 (name[5] == '\0' || name[5] == ':')) {
            if (name[5] == '\0')
                id->prefix = &dtd->default_prefix;
            else
                id->prefix = (ts4_xml_prefix *)fn_888A5060(&dtd->prefixes, name + 6, sizeof(ts4_xml_prefix));
            id->xmlns = 1;
        } else {
            int i;
            for (i = 0; name[i]; i++) {
                if (name[i] == ':') {
                    int j;
                    for (j = 0; j < i; j++) {
                        if (!TS4_XML_POOL_APPEND_CHAR_CALL(&dtd->pool, name[j]))
                            return 0;
                    }
                    if (!TS4_XML_POOL_APPEND_CHAR_CALL(&dtd->pool, '\0'))
                        return 0;
                    id->prefix = (ts4_xml_prefix *)fn_888A5060(&dtd->prefixes, TS4_XML_POOL_START(&dtd->pool),
                                                               sizeof(ts4_xml_prefix));
                    if (id->prefix->name == TS4_XML_POOL_START(&dtd->pool))
                        TS4_XML_POOL_FINISH(&dtd->pool);
                    else
                        TS4_XML_POOL_DISCARD(&dtd->pool);
                    break;
                }
            }
        }
    }
    return id;
}


/* Encoding description filled in by an application's unknown-encoding handler (Expat XML_Encoding). */
typedef struct ts4_xml_unknown_encoding_info {
    int map[256];                       /* +0x000 */
    void *data;                         /* +0x400 */
    int (*convert)(void *, const char *); /* +0x404 */
    void (*release)(void *);            /* +0x408 */
} ts4_xml_unknown_encoding_info;

/* Placeholders: XmlInitUnknownEncoding (plain and namespace-aware). */
extern const struct ts4_xml_encoding *ts4_if_call_seq_fn_88899C70_8889B450(void *mem, int *table, int (*convert)(void *, const char *), void *user_data);
extern const struct ts4_xml_encoding *fn_88899C70(void *mem, int *table, int (*convert)(void *, const char *), void *user_data);

/* Ask the application for an unknown encoding and install it (Expat handleUnknownEncoding);
 * returns an XML error code (0 ok, 1 no memory, 18 unknown encoding).
 * Swing_DLL.xex 0x888A81F8 */
int ts4_xml_handle_unknown_encoding_888A81F8(ts4_xml_parser *parser, const char *encoding_name)
{
    if (parser->unknown_encoding_handler) {
        ts4_xml_unknown_encoding_info info;
        int i;
        for (i = 0; i < 256; i++)
            info.map[i] = -1;
        info.convert = 0;
        info.data = 0;
        info.release = 0;
        if (parser->unknown_encoding_handler(parser->unknown_encoding_handler_data, encoding_name, &info)) {
            const struct ts4_xml_encoding *enc;
            parser->unknown_encoding_mem = parser->malloc_fcn(0x778);
            if (!parser->unknown_encoding_mem) {
                if (info.release)
                    info.release(info.data);
                return 1;
            }
            enc = (parser->ns ? ts4_if_call_seq_fn_88899C70_8889B450 : fn_88899C70)(parser->unknown_encoding_mem, info.map, info.convert, info.data);
            if (enc) {
                parser->unknown_encoding_data = info.data;
                parser->unknown_encoding_release = info.release;
                parser->encoding = enc;
                return 0;
            }
        }
        if (info.release != 0)
            info.release(info.data);
    }
    return 18;
}

/* Placeholders: XmlParseXmlDecl (namespace-aware and plain). */
extern int fn_8889B480(int is_general_text_entity, const struct ts4_xml_encoding *enc, const char *ptr, const char *end,
                       const char **eventp, const char **version, const char **version_end, const char **encoding_name,
                       const struct ts4_xml_encoding **new_encoding, int *standalone);
extern int fn_8889B4F0(int is_general_text_entity, const struct ts4_xml_encoding *enc, const char *ptr, const char *end,
                       const char **eventp, const char **version, const char **version_end, const char **encoding_name,
                       const struct ts4_xml_encoding **new_encoding, int *standalone);
extern int ts4_xml_handle_unknown_encoding_888A81F8(ts4_xml_parser *parser, const char *encoding_name);


/* Placeholders: destroyBindings, poolDestroy and dtdDestroy. */
extern void fn_888A4EF8(ts4_xml_binding *bindings, ts4_xml_parser *parser);
extern void fn_888A3840(ts4_xml_string_pool *pool);
extern void fn_888A3AD0(ts4_xml_dtd *dtd, unsigned char is_document_entity, const ts4_xml_memory_suite *ms);

/* Destroy a parser object and everything it owns (Expat XML_ParserFree).
 * Swing_DLL.xex 0x888A7110 */
void ts4_xml_parser_free_888A7110(ts4_xml_parser *parser)
{
    for (;;) {
        ts4_xml_tag *p;
        if (parser->tag_stack == 0) {
            if (parser->free_tag_stack == 0)
                break;
            parser->tag_stack = parser->free_tag_stack;
            parser->free_tag_stack = 0;
        }
        p = parser->tag_stack;
        parser->tag_stack = parser->tag_stack->parent;
        parser->free_fcn(p->buf);
        fn_888A4EF8(p->bindings, parser);
        parser->free_fcn(p);
    }
    fn_888A4EF8(parser->free_binding_list, parser);
    fn_888A4EF8(parser->inherited_bindings, parser);
    fn_888A3840(&parser->temp_pool);
    fn_888A3840(&parser->temp2_pool);
    if (!parser->is_param_entity && parser->dtd)
        fn_888A3AD0(parser->dtd, (unsigned char)(parser->parent_parser == 0), (const ts4_xml_memory_suite *)&parser->malloc_fcn);
    parser->free_fcn(parser->atts);
    if (parser->group_connector)
        parser->free_fcn(parser->group_connector);
    if (parser->buffer)
        parser->free_fcn(parser->buffer);
    parser->free_fcn(parser->data_buf);
    if (parser->unknown_encoding_mem)
        parser->free_fcn(parser->unknown_encoding_mem);
    if (parser->unknown_encoding_release)
        parser->unknown_encoding_release(parser->unknown_encoding_data);
    parser->free_fcn(parser);
}
