/* Swing_DLL.xex 0x888A3940-0x888A3984, executable version 0.0.0.3. */
#include "r3_xmlparse.h"

typedef struct ts4_xml_hash_iter {
    void **p;
    void **end;
} ts4_xml_hash_iter;

/* Expat hashTableIterNext. */
void *ts4_xml_hash_iter_next_888A3940(ts4_xml_hash_iter *iter)
{
    while (iter->p != iter->end) {
        void **q = iter->p++;
        void *tem = *q;
        if (tem)
            return tem;
    }
    return 0;
}
