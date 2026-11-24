/* Swing_DLL.xex 0x888A3AD0-0x888A3BC8, executable version 0.0.0.3. */
#include "r3_xmlparse.h"

extern void fn_888A39C8(ts4_xml_hash_table *table);
extern void ts4_loop_get_u32_off0_888A3840(ts4_xml_string_pool *pool);

typedef struct ts4_xml_hash_iter {
    void **p;
    void **end;
} ts4_xml_hash_iter;

#ifdef _MSC_VER
#define D8_INLINE __forceinline
#else
#define D8_INLINE inline
#endif

static D8_INLINE void *hash_iter_next(ts4_xml_hash_iter *iter)
{
    while (iter->p != iter->end) {
        void *tem = *(iter->p)++;
        if (tem)
            return tem;
    }
    return 0;
}

/* Expat dtdDestroy. */
void ts4_xml_dtd_destroy_888A3AD0(ts4_xml_dtd *p, unsigned char is_document_entity, const ts4_xml_memory_suite *ms)
{
    ts4_xml_hash_iter iter;
    iter.p = p->element_types.v;
    iter.end = iter.p + p->element_types.size;
    for (;;) {
        ts4_xml_element_type *e = (ts4_xml_element_type *)hash_iter_next(&iter);
        if (!e)
            break;
        if (e->alloc_default_atts != 0)
            ms->free_fcn(e->default_atts);
    }
    fn_888A39C8(&p->general_entities);
    fn_888A39C8(&p->param_entities);
    fn_888A39C8(&p->element_types);
    fn_888A39C8(&p->attribute_ids);
    fn_888A39C8(&p->prefixes);
    ts4_loop_get_u32_off0_888A3840(&p->pool);
    ts4_loop_get_u32_off0_888A3840(&p->entity_value_pool);
    if (is_document_entity) {
        if (p->scaff_index)
            ms->free_fcn(p->scaff_index);
        if (p->scaffold)
            ms->free_fcn(p->scaffold);
    }
    ms->free_fcn(p);
}
