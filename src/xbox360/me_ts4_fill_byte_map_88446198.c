/* 0x88446198: for every word of the array at +0xC (count +0x10) stores its low byte into the byte map at o+0x20, indexed by the word >> 8. */
/* Matched on /Oc (agAB). Index-first lwzx from a loop-body local it = t->items (the byte store reloads the base, as a call does). */
typedef struct T { char pad[0xc]; unsigned int *items; int n; } T;
typedef struct O { char pad[0x20]; unsigned char *map; } O;
void fn_88446198(T *t, O *o)
{
    int i;
    for (i = 0; i < t->n; i++) {
        unsigned int *it = t->items;
        o->map[it[i] >> 8] = (unsigned char)it[i];
    }
}
