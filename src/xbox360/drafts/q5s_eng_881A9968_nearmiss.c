/* nearmiss: 20 off (LTCG /Oc, --include fn_881AA1A8 --context src/xbox360/me_ts4_vector40_assign_881AA1A8.c).
 * Copy loop of 0x18-byte {float x,y,z; Vec40 items} calling the matched vector40 operator= per element. Target keeps
 * dest-first in a 4th saved register (r28) for `stfsx` of z; struct copy, helper and C++ operator= forms all fail.
 * Blocker: the element type is a C++ class with an inline operator= (float members + vector member); needs the
 * shared vector40 class type in include/ts4 before a member-wise operator= can be written faithfully. */
typedef struct Item40 { int w[10]; } Item40;
typedef struct Vec40 { Item40 *begin; Item40 *end; Item40 *cap; } Vec40;
typedef struct E24F { float x, y, z; Vec40 items; } E24F;
Vec40 *fn_881AA1A8(Vec40 *dst, const Vec40 *src);
E24F *ts4_copy_e24f_881A9968(E24F *first, E24F *last, E24F *dest)
{
    int n;
    for (n = last - first; n > 0; --n, ++dest, ++first) {
        dest->x = first->x;
        dest->y = first->y;
        dest->z = first->z;
        fn_881AA1A8(&dest->items, &first->items);
    }
    return dest;
}
