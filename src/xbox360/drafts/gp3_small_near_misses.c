/*
 * GP3 near misses (not compiled): semantically verified small helpers that fn_check rejects.
 * Each comment says what still differs. The structure types are the ones used in gp3_types.h / gp0_types.h.
 */
struct Gp3U32Vector { unsigned int *begin, *end, *cap; };
void fn_88263908(struct Gp3U32Vector *vector, unsigned int *where, const unsigned int *value, int count, int flag);

struct Gp3RewardCollector2 {
    unsigned char pad0[0x14];
    struct Gp3U32Vector tag_hashes;  /* +0x14 */
    struct Gp3U32Vector players;     /* +0x20 */
};

/* Swing_DLL.xex 0x886965E0: queue one (tag hash, player index) lookup request.
 * fn_check: frame 0x60 vs 0x70 (the original keeps a 16-byte unused local), and its second argument lives in r30;
 * C++ `push_back(unsigned value)` method form gets the instruction order right but not the spill slots (24 instrs differ). */
void gp3_tag_queue_request_886965E0(struct Gp3RewardCollector2 *self, unsigned int tag_hash, unsigned int player_index)
{
    if (self->tag_hashes.end != self->tag_hashes.cap) {
        if (self->tag_hashes.end != 0) {
            *self->tag_hashes.end = tag_hash;
        }
        self->tag_hashes.end = self->tag_hashes.end + 1;
    } else {
        fn_88263908(&self->tag_hashes, self->tag_hashes.end, &tag_hash, 1, 1);
    }
    if (self->players.end != self->players.cap) {
        if (self->players.end != 0) {
            *self->players.end = player_index;
        }
        self->players.end = self->players.end + 1;
    } else {
        fn_88263908(&self->players, self->players.end, &player_index, 1, 1);
    }
}

/* Swing_DLL.xex 0x8865F030: clear two per-player flag bytes of the active group, then toggle the group in doubles
 * (rules->mode == 2: match->active_group = 1 - active_group, else 0).
 * fn_check: 13 instrs differ: the original shares ONE register for the zero stored to the flags and the new group value. */
struct Gp3PlayerFlags { unsigned char pad[0x84]; unsigned char *flags_84; unsigned char *flags_88; };
struct Gp3GroupPlayers { unsigned char pad[0x10]; struct Gp3PlayerFlags **begin; struct Gp3PlayerFlags **end; };
struct Gp3MatchGroup { unsigned char pad[0x7c]; int active_group; };
struct Gp3Rules2 { int mode; };
struct Gp3InstanceGroups { unsigned char pad0[0x10]; struct Gp3GroupPlayers **groups; unsigned char pad14[0x1c];
                           struct Gp3MatchGroup *match; unsigned char pad34[0x44]; struct Gp3Rules2 *rules; };

void gp3_flip_active_group_8865F030(struct Gp3InstanceGroups *instance)
{
    struct Gp3GroupPlayers *group = instance->groups[instance->match->active_group];
    struct Gp3PlayerFlags **it;
    int value = 0;

    for (it = group->begin; it != group->end; ++it) {
        if (*it != 0) {
            (*it)->flags_84[0x14] = (unsigned char)value;
            (*it)->flags_88[0xa4] = (unsigned char)value;
        }
    }
    if (instance->rules->mode == 2) {
        value = 1 - instance->match->active_group;
    }
    instance->match->active_group = value;
}

/* Swing_DLL.xex 0x8866E250: first player of the active group whose command record has `scheduled == 1`; out = its frame.
 * records live at (char *)&match->u70 + match->u70.rel + player.index * 0xE0; scheduled byte +0xDC, frame +0xD8.
 * fn_check: identical logic, different register allocation (original keeps the flag byte in r31 and the begin pointer masked with clrrwi). */

/* Swing_DLL.xex 0x886A39A8: if either candidate-set dirty byte (sets+0x20 / sets+0x80) is set: rebuild both sets
 * (fn_8868B4E8(planner+0x28, sets), fn_8868B4E8(planner+0x28, sets+0x60), fn_8868BD80, fn_8869B0A8) and clear both bytes.
 * fn_check: the original reloads planner->sets (+0x2C) for the first call instead of reusing the register of the condition. */
