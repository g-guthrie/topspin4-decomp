/* Swing_DLL.xex 0x886C5DB0: reset, then clear the pair list (erase all: copy the empty tail down, end = begin). */
typedef unsigned int ts4_u32;
typedef unsigned char ts4_u8;
struct Ts4VcPair { ts4_u32 a; ts4_u32 b; };
struct Ts4VcList { struct Ts4VcPair *begin; struct Ts4VcPair *end; };
struct Ts4VcOwner { ts4_u8 pad_00[4]; ts4_u32 count; ts4_u8 pad_08[0x24]; struct Ts4VcList list; };
void ts4_clear_three_vectors_886C3978(struct Ts4VcOwner *self);

static struct Ts4VcPair *vc_copy(struct Ts4VcPair *first, struct Ts4VcPair *last, struct Ts4VcPair *dst)
{
    int n;
    for (n = (int)(last - first); n > 0; n--) {
        dst->a = first->a;
        dst->b = first->b;
        dst++;
        first++;
    }
    return dst;
}

void ts4_pair_list_reset_886C5DB0(struct Ts4VcOwner *self)
{
    struct Ts4VcList *l;
    ts4_clear_three_vectors_886C3978(self);
    l = &self->list;
    l->end = vc_copy(l->end, l->end, l->begin);
    self->count = 0;
}
