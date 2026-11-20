/* 0x884D14F8: Applies a fixup table to base: pointer fixups store base+target at base+offset, then value fixups store value at base+offset. */
/* Near miss (agAH): /Oc, 1 off: the first loop computes ptrs + i*8 as add r9,r10,r9 (index first); every form tried gives ptrs-first. */
typedef struct PtrFix { unsigned int offset; unsigned int target; } PtrFix;
typedef struct ValFix { unsigned int offset; unsigned int value; unsigned int reserved; } ValFix;
typedef struct FixupTable { PtrFix *ptrs; int ptr_count; int p8; ValFix *vals; int val_count; } FixupTable;
void fn_884D14F8(const FixupTable *t, char *base)
{
    int i;
    for (i = 0; i < t->ptr_count; i++)
        {
        const PtrFix *f = &t->ptrs[i];
        *(unsigned int *)(base + f->offset) = f->target + (unsigned int)base;
    }
    for (i = 0; i < t->val_count; i++)
        {
        const ValFix *f = &t->vals[i];
        *(unsigned int *)(base + f->offset) = f->value;
    }
}
