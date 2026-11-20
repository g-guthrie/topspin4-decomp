/* 0x886CE120: calls ts4_append_group_bindings_886CB3A8 on +0x30 of every item in the vector at lbl_88D45AF4+0x50 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char pad[0x30]; char bind[4]; } It;
typedef struct { It **first; It **last; } Vec;
typedef struct { char pad[0x50]; Vec items; } G;
extern G *lbl_88D45AF4;
void ts4_append_group_bindings_886CB3A8(void *p);
void ts4_append_all_group_bindings_886CE120(void)
{
    Vec *v = &lbl_88D45AF4->items;
    unsigned int n = v->last - v->first, i;
    for (i = 0; i < n; i++) ts4_append_group_bindings_886CB3A8(v->first[i]->bind);
}
