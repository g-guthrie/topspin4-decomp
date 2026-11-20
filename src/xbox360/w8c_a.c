/* W8C: 0x886C66C0, animation layer index: the lookup result of the first helper, raised to the
 * topmost active layer (clamped to the last entry) unless the owner's flag at +0x55 is set.
 * LTCG route: the callee leaves r4 (last index) intact across the call. */
struct W8cVec { unsigned char pad00[4]; int *begin; int *end; };   /* +0x58 vector, begin/end at +0x5c/+0x60 */
struct W8cLayerOwner { unsigned char pad00[0x55]; unsigned char flag55; };
struct W8cLayerInner { unsigned char pad00[0x14]; struct W8cLayerOwner *owner14; };
struct W8cAnim {
    unsigned char pad00[0x18];
    float f18;
    unsigned char pad1c[4];
    struct W8cLayerInner *inner20;
    unsigned char pad24[0x58 - 0x24];
    struct W8cVec vec;
};
extern int fn_886C48C8(struct W8cVec *v, float f);
extern int ts4_anim_stack_top_active_layer_886C4638(struct W8cAnim *s, float unused);

int ts4_anim_layer_index_886C66C0(struct W8cAnim *self)
{
    int a = fn_886C48C8(&self->vec, self->f18);
    int last = (self->vec.end - self->vec.begin) - 1;
    int idx = ts4_anim_stack_top_active_layer_886C4638(self, 0.0f);
    if (!(idx < last)) idx = last;
    if (self->inner20->owner14->flag55 == 0) {
        if (a < idx) a = idx;
    }
    return a;
}
