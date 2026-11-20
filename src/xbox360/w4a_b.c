#include "w4a_types.h"

struct B_O { W4A_PAD(0x14c); int *arr; int pad; int n; };
struct B_S { W4A_PAD(0x1c); struct B_O *o; };

W4A_INLINE int *b_elem(int *a, int i) { return &a[i]; }

/* Swing_DLL.xex 0x886C4F20 */
void ts4_decay_counters_886C4F20(struct B_S *s)
{
    int i;
    for (i = 0; i < s->o->n; i++) {
        if (s->o->arr[i] > 0)
            (*b_elem(s->o->arr, i))--;
    }
}
