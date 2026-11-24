/* Swing_DLL.xex 0x884390B8 and 0x884A5F20: shape-key collision filter entry points of the group
 * filters (Havok 5.5 physics range; vtables 0x8808085C hkpGroupFilter, 0x88087C54
 * hkpGroupCollisionFilter). `self` is the shape-collection-filter interface at +0x10 inside the
 * filter object. The shape container's slot-4 virtual maps the shape key to the child's filter
 * info; that and body a's info (+0x20) go to the pair test of the full filter.
 * Matches on the LTCG route only: the link must see the pair test's body (with /Ob1) to know it
 * returns the hidden result pointer in r3, which removes the final `mr r3`. */

struct Ts4FilterBool {
    bool value;
    Ts4FilterBool(bool v) : value(v) {}
};
struct Ts4GroupFilter;
struct Ts4GroupCollisionFilter;

struct Ts4ShapeContainer {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual unsigned int child_filter_info(unsigned int key);
};

struct Ts4CdBody {
    char pad_00[0x20];
    unsigned int filter_info;
};

extern "C" Ts4FilterBool ts4_group_filter_pair_enabled_88438FC0(Ts4GroupFilter *self, unsigned int a, unsigned int b);
extern "C" Ts4FilterBool ts4_group_collision_filter_pair_enabled_884A5A40(Ts4GroupCollisionFilter *self, unsigned int a, unsigned int b);

extern "C" Ts4FilterBool ts4_group_filter_shape_key_enabled_884390B8(char *self, Ts4CdBody *a, void *b,
                                                                      Ts4ShapeContainer *container, unsigned int key)
{
    (void)b;
    return ts4_group_filter_pair_enabled_88438FC0((Ts4GroupFilter *)(self - 0x10), a->filter_info,
                                                  container->child_filter_info(key));
}

extern "C" Ts4FilterBool ts4_group_collision_filter_shape_key_enabled_884A5F20(char *self, Ts4CdBody *a, void *b,
                                                                               Ts4ShapeContainer *container, unsigned int key)
{
    (void)b;
    return ts4_group_collision_filter_pair_enabled_884A5A40((Ts4GroupCollisionFilter *)(self - 0x10), a->filter_info,
                                                            container->child_filter_info(key));
}
