/* Swing_DLL.xex 0x88438FC0 and 0x884A5A40: group-filter pair tests (Havok 5.5 physics range,
 * vtables with RTTI hkpGroupFilter / hkpGroupCollisionFilter). Both return a one-byte bool class
 * through the hidden result pointer in r3 (filter object in r4). */

/* One-byte bool returned by value through a hidden pointer (a C struct would come back in r3). */
struct Ts4FilterBool {
    bool value;
    Ts4FilterBool(bool v) : value(v) {}
};

/* Layer/system-group filter: 32 layer masks start at +0x34. */
struct Ts4GroupFilter {
    char pad_00[0x34];
    unsigned int layer_masks[32];
};

/* Group-collision filter: bool for "either info is 0" at +0x30, 32 group masks at +0x34. */
struct Ts4GroupCollisionFilter {
    char pad_00[0x30];
    bool no_group_result;
    char pad_31[3];
    unsigned int group_masks[32];
};

/* Info words: bits 16-31 system group, 10-14 "ignore subsystem id", 5-9 subsystem id, 0-4 layer.
 * Same non-zero system group: enabled unless either subsystem id equals the other's ignore id.
 * Otherwise: the layer of a selects a mask, tested against the layer bit of b. */
extern "C" Ts4FilterBool ts4_group_filter_pair_enabled_88438FC0(Ts4GroupFilter *self, unsigned int a, unsigned int b)
{
    if (((a ^ b) & 0xFFFF0000) == 0 && (a & 0xFFFF0000) != 0) {
        if ((((b >> 5) ^ a) & 0x3E0) == 0)
            return Ts4FilterBool(false);
        if ((((a >> 5) ^ b) & 0x3E0) == 0)
            return Ts4FilterBool(false);
        return Ts4FilterBool(true);
    }
    return Ts4FilterBool(0 != (self->layer_masks[a & 31] & (1u << (b & 31))));
}

#define TS4_GROUP_BIT(i) ((a & (1u << (i))) ? self->group_masks[i] : 0)

/* OR the masks of every group bit set in a (tested a byte at a time), then test against b. */
extern "C" Ts4FilterBool ts4_group_collision_filter_pair_enabled_884A5A40(Ts4GroupCollisionFilter *self, unsigned int a, unsigned int b)
{
    unsigned int m;
    if (a == 0 || b == 0)
        return Ts4FilterBool(self->no_group_result);
    m = 0;
    if (a & 0x000000FF) { m |= TS4_GROUP_BIT(0); m |= TS4_GROUP_BIT(1); m |= TS4_GROUP_BIT(2); m |= TS4_GROUP_BIT(3); m |= TS4_GROUP_BIT(4); m |= TS4_GROUP_BIT(5); m |= TS4_GROUP_BIT(6); m |= TS4_GROUP_BIT(7); }
    if (a & 0x0000FF00) { m |= TS4_GROUP_BIT(8); m |= TS4_GROUP_BIT(9); m |= TS4_GROUP_BIT(10); m |= TS4_GROUP_BIT(11); m |= TS4_GROUP_BIT(12); m |= TS4_GROUP_BIT(13); m |= TS4_GROUP_BIT(14); m |= TS4_GROUP_BIT(15); }
    if (a & 0x00FF0000) { m |= TS4_GROUP_BIT(16); m |= TS4_GROUP_BIT(17); m |= TS4_GROUP_BIT(18); m |= TS4_GROUP_BIT(19); m |= TS4_GROUP_BIT(20); m |= TS4_GROUP_BIT(21); m |= TS4_GROUP_BIT(22); m |= TS4_GROUP_BIT(23); }
    if (a & 0xFF000000) { m |= TS4_GROUP_BIT(24); m |= TS4_GROUP_BIT(25); m |= TS4_GROUP_BIT(26); m |= TS4_GROUP_BIT(27); m |= TS4_GROUP_BIT(28); m |= TS4_GROUP_BIT(29); m |= TS4_GROUP_BIT(30); m |= TS4_GROUP_BIT(31); }
    return Ts4FilterBool((m & b) != 0);
}
