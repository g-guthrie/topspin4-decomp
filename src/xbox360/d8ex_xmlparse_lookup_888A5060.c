/* Swing_DLL.xex 0x888A5060-0x888A5370, executable version 0.0.0.3. */
#include "r3_xmlparse.h"

#ifdef _MSC_VER
extern void *memset(void *dest, int value, unsigned int count);
#else
#include <string.h>
#endif

#ifdef _MSC_VER
__declspec(noinline)
#endif
/* Expat keyeq(), kept in this file so the compiler knows its register use. Swing_DLL.xex 0x888A3A80 */
int ts4_xml_keyeq_888A3A80(const char *s1, const char *s2)
{
    for (; *s1 == *s2; s1++, s2++)
        if (*s1 == 0)
            return 1;
    return 0;
}

#define D8_INIT_SIZE 64

#define D8_HASH(h, s) \
    do { \
        const char *hp_ = (s); \
        (h) = 0; \
        while (*hp_) \
            (h) = (h) * 33 + (unsigned char)*hp_++; \
    } while (0)

/* Expat lookup: find (or create) a named entry in an open-addressed hash table. */
void *ts4_xml_lookup_888A5060(ts4_xml_hash_table *table, const char *name, unsigned int create_size)
{
    unsigned int i;
    unsigned long h;
    unsigned int size = table->size;
    if (size == 0) {
        unsigned int tsize;
        if (!create_size)
            return 0;
        tsize = D8_INIT_SIZE * sizeof(void *);
        table->v = (void **)table->mem->malloc_fcn(tsize);
        if (!table->v)
            return 0;
        memset(table->v, 0, tsize);
        table->size = D8_INIT_SIZE;
        table->used_lim = D8_INIT_SIZE / 2;
        D8_HASH(h, name);
        i = h & (table->size - 1);
    } else {
        unsigned long mask;
        D8_HASH(h, name);
        mask = (unsigned long)size - 1;
        i = h & mask;
        while (table->v[i]) {
            if (ts4_xml_keyeq_888A3A80(name, *(const char **)table->v[i]))
                return table->v[i];
            if (i == 0)
                i = size - 1;
            else
                --i;
        }
        if (!create_size)
            return 0;
        if (table->used == table->used_lim) {
            unsigned int new_size = size * 2;
            void **new_v = (void **)table->mem->malloc_fcn(new_size * sizeof(void *));
            if (!new_v)
                return 0;
            memset(new_v, 0, new_size * sizeof(void *));
            for (i = 0; i < table->size; i++) {
                if (table->v[i]) {
                    unsigned long h2;
                    unsigned int j;
                    D8_HASH(h2, *(const char **)table->v[i]);
                    j = h2 & (new_size - 1);
                    while (new_v[j]) {
                        if (j == 0)
                            j = new_size - 1;
                        else
                            --j;
                    }
                    new_v[j] = table->v[i];
                }
            }
            table->mem->free_fcn(table->v);
            table->v = new_v;
            table->size = new_size;
            table->used_lim = new_size / 2;
            i = h & (new_size - 1);
            while (table->v[i]) {
                if (i == 0)
                    i = new_size - 1;
                else
                    --i;
            }
        }
    }
    table->v[i] = table->mem->malloc_fcn(create_size);
    if (!table->v[i])
        return 0;
    memset(table->v[i], 0, create_size);
    *(const char **)table->v[i] = name;
    (table->used)++;
    return table->v[i];
}
