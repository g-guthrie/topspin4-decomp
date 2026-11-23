/* nearmiss: 18 off; the target computes a dead `addi r10,r5,0xc` (&dest->c, overwritten at once) and walks
 * the source with a pointer biased to first+0xc (lwz -8/-4, lbz 0). Sub-object copy helpers, a null-checked
 * helper and C++ placement new all keep the extra `cmpwi r5,-0xc` null test or the unbiased pointer. The
 * matching-tips "DA1 dead-addi" entry lists this shape as open (no known source form). The odds improve once
 * the element class (vtable lbl_880D6B70) and its copy constructor are reconstructed, so its real copy
 * form can be tried.
 * Route: LTCG /Oc, context src/xbox360/pp1_pool_primer.c.
 *
 * Swing_DLL.xex 0x88267630: uninitialized copy of [first, last) 16-byte elements
 * {vtable lbl_880D6B70, u32 a, u32 b, u8 c} to dest; returns dest end. Sister of the matched
 * ts4_uninit_copy_e14_88270720 (cx17_core_a.c). */
typedef unsigned int u32;
typedef unsigned char u8;
extern char lbl_880D6B70[];
typedef struct Flag { u8 v; } Flag;
typedef struct E16 { const void *vt; u32 a; u32 b; Flag c; } E16;
static void flag_copy(Flag *d, const Flag *s) { if (d != 0) d->v = s->v; }
E16 *ts4_uninit_copy_e16_88267630(const E16 *first, const E16 *last, E16 *dest)
{
    for (; first != last; first++, dest++) {
        if (dest != 0) {
            dest->vt = lbl_880D6B70;
            dest->a = first->a;
            dest->b = first->b;
            flag_copy(&dest->c, &first->c);
        }
    }
    return dest;
}
