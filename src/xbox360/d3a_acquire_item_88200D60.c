/* Swing_DLL.xex 0x88200D60-0x88200DE4, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif
struct counted { void *vt; volatile long refs; };
struct list { u8 pad[0x68]; struct counted **items; };
struct owner { u8 pad[0x48]; struct list *list; u8 pad2[0x5e]; u8 single; };
void ts4_acquire_item_88200D60(struct counted **out, struct owner *self, int index)
{
    struct counted *c;
    if (self->single == 0) {
        c = self->list->items[0];
        *out = c;
        if (c != 0) {
            _InterlockedIncrement(&c->refs);
        }
    } else {
        c = self->list->items[index];
        *out = c;
        if (c != 0) {
            _InterlockedIncrement(&c->refs);
        }
    }
}
