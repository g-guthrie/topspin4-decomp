/* Swing_DLL.xex 0x888A39C8-0x888A3A44, executable version 0.0.0.3. */
#include "r3_xmlparse.h"

/* Expat hashTableDestroy. */
void ts4_xml_hash_destroy_888A39C8(ts4_xml_hash_table *table)
{
    unsigned int i;
    for (i = 0; i < table->size; i++) {
        void *p = table->v[i];
        if (p)
            table->mem->free_fcn(p);
    }
    if (table->v)
        table->mem->free_fcn(table->v);
}
