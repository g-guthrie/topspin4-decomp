/* Swing_DLL.xex 0x8830EBC0: release and clear the object in the holder's slot */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
typedef struct Slot { void *obj; } Slot;
typedef struct Holder { Slot *slot; } Holder;
void fn_88321D80(void *obj);

/* Releases the object held in the holder's slot (if any) and clears the slot. */
void fn_8830EBC0(Holder *h)
{
    Slot *s = h->slot;
    if (s != 0) {
        if (s->obj != 0) {
            fn_88321D80(s->obj);
            s->obj = 0;
        }
    }
}
