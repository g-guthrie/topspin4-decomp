/* GP3 active-group helpers (NM2 family), converted from drafts/gp3_small_near_misses.c. */

struct nm2_player_flags { unsigned char pad[0x84]; unsigned char *flags_84; unsigned char *flags_88; };
struct nm2_group_players { unsigned char pad[0x10]; struct nm2_player_flags **begin; struct nm2_player_flags **end; };
struct nm2_match_group { unsigned char pad[0x7c]; int active_group; };
struct nm2_rules { int mode; };
struct nm2_instance_groups {
    unsigned char pad0[0x10];
    struct nm2_group_players **groups;   /* +0x10 */
    unsigned char pad14[0x1c];
    struct nm2_match_group *match;       /* +0x30 */
    unsigned char pad34[0x44];
    struct nm2_rules *rules;             /* +0x78 */
};

/* Clear two per-player flag bytes of the active group, then toggle the group in doubles (rules->mode == 2:
 * active_group = 1 - active_group, else 0). Swing_DLL.xex 0x8865F030 */
void ts4_gp3_flip_active_group_8865F030(struct nm2_instance_groups *instance)
{
    struct nm2_group_players *group = instance->groups[instance->match->active_group];
    struct nm2_player_flags **it = group->begin;
    struct nm2_player_flags **end = group->end;
    int value = 0;

    for (; it != end; ++it) {
        if (*it != 0) {
            (*it)->flags_84[0x14] = (unsigned char)value;
            (*it)->flags_88[0xa4] = (unsigned char)value;
        }
    }
    if (instance->rules->mode != 2) {
        instance->match->active_group = value;
    } else {
        instance->match->active_group = 1 - instance->match->active_group;
    }
}
