/* nearmiss: 4 off (LTCG); li r11,0 is scheduled after addi r7 (lbl_880F5118) and mr r3,r31 after the vtable store. Taking the address of lbl_88D45B08 fixed the register numbering (was 9 off). No concrete blocker found yet: open. */
#include "include/ts4/ts4.h"
extern char lbl_880F5170[];
extern char lbl_880F5118[];
extern char lbl_880D19F0[];
extern void *lbl_88D45B08;
void ts4_loop_call_seq_lbl_880D6268_8892AF80(void *p);
void ts4_destroy_owned_object(void *p);
void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *p);
typedef struct Q5dObj {
    void *vtbl;           /* +0x00 */
    char pad_04[0x20];
    void *f_24;           /* +0x24 */
    char pad_28[0x1C];
    void *owned;          /* +0x44 */
    char pad_48[0xC];
    char sub_54[4];       /* +0x54 */
} Q5dObj;
static void q5d_iface_dtor(void **sub) { *sub = lbl_880D19F0; }
static void q5d_singleton_dtor(void **self, void **inst)
{
    *self = lbl_880F5118;
    *inst = 0;
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
void ts4_stat_dtor_88658DC8(Q5dObj *self)
{
    self->vtbl = lbl_880F5170;
    ts4_loop_call_seq_lbl_880D6268_8892AF80(self->sub_54);
    if (self->owned)
        ts4_destroy_owned_object(self->owned);
    q5d_iface_dtor((void **)&self->f_24);
    q5d_singleton_dtor((void **)self, &lbl_88D45B08);
}
