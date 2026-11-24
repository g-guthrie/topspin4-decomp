/* 0x887EE430: destructor. Sets the vtable, clears the global instance lbl_88D45A10, tears down the
   list at +0x2b0, destroys the embedded object at +0x23c (base dtor after its vtable), tears down the
   list at +0x1dc, destroys the owned objects at +0x1b0 and +0x120 and runs the base destructor. */
typedef unsigned int u32;
typedef struct SubObj { const void *vt; } SubObj;
typedef struct BigOwner { const void *vt; u32 pad[0x47]; void *own120; u32 pad2[0x23]; void *own1b0;
    u32 pad3[0xa]; u32 list1dc[0x18]; SubObj sub23c; u32 pad4[0x1c]; u32 list2b0[4]; } BigOwner;
extern void ts4_loop_call_seq_lbl_880D6268_8892AF80(void *list);
extern void ts4_destroy_owned_object(void *p);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
extern const char lbl_880E4CC0[], lbl_880F8B94[];
extern void *lbl_88D45A10;
void ts4_big_owner_dtor_887EE430(BigOwner *o)
{
    o->vt = lbl_880E4CC0;
    lbl_88D45A10 = 0;
    ts4_loop_call_seq_lbl_880D6268_8892AF80(o->list2b0);
    o->sub23c.vt = lbl_880F8B94;
    ts4_if_call_seq_lbl_880F7EE4_88617D28(&o->sub23c);
    ts4_loop_call_seq_lbl_880D6268_8892AF80(o->list1dc);
    ts4_destroy_owned_object(o->own1b0);
    ts4_destroy_owned_object(o->own120);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(o);
}
