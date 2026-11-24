/* 0x8847EBD0: releases item i of the pointer array at +0x2C through ts4_counted_ref_release_88475B08, then fills the hole with the last item */
/* Near miss (agAH): 1 off: lwzx operand order of the first load only (target offset,base). Local array pointer, pointer arithmetic and unsigned index tried. */
typedef struct PtrArr { void **items; int count; } PtrArr;
typedef struct Own { char pad[0x2c]; PtrArr list; } Own;
void ts4_counted_ref_release_88475B08(void *p);
void fn_8847EBD0(Own *o, int i)
{
    PtrArr *a = &o->list;
    ts4_counted_ref_release_88475B08(a->items[i]);
    a->count--;
    a->items[i] = a->items[a->count];
}
