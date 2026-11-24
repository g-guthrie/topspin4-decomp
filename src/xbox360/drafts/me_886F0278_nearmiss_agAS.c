/* nearmiss (q5s 2026-11-24): 2 off; lwz lbl_88D45AD4 must precede slwi r10,r5,5; C++ Query::Run member, pads 0-9 (C and C++) unchanged */
/* agAS near-miss (2 off, plain /Oc): the target loads lbl_88D45AD4 before the slwi of the slot index. Tried local slot pointer, local float, explicit byte offset, LTCG ctx=[]. */
#include "vx1_vector.h"
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Slot { char p[0x40]; char body[0xe0]; } Slot;
typedef struct Bank { char p[0x24]; Slot *slots; } Bank;
typedef struct Sys { char p[0x2c]; Bank *bank; } Sys;
typedef struct Probe { char p[0x1c]; float radius; char p20[0x1c]; Vec3 pos; } Probe;
extern Sys *lbl_88D45AD4;
void *memcpy(void *d, const void *s, unsigned int n);
#pragma function(memcpy)
void fn_886EE828(void *slot, const __vector4 *p, float r, unsigned int *out);
int fn_886F0278(unsigned int *state, int idx, Probe *p)
{
    if (*state == 0) {
        __vector4 t, v;
        memcpy(&t, &p->pos, 12);
        v = t;
        fn_886EE828(lbl_88D45AD4->bank->slots[idx].body, &v, p->radius, state);
    }
    return *state != 2;
}
