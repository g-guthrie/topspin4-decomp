/* Swing_DLL.xex 0x88157190-0x88157190, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

typedef struct Record160List {
    int data_offset;
    int count;
    int capacity;
} Record160List;

/* Appends a 160-byte record when the list has spare capacity. */
void ts4_append_record160_88157190(Record160List *self, const void *item)
{
    if (self->count < self->capacity) {
        memcpy((char *)self + self->data_offset + self->count * 0xa0, item, 0xa0);
        self->count++;
    }
}
