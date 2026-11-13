/*
 * GP1 draft (near match): fn_88667720 and fn_88667C98.
 * fn_88667720 (0x88667720): 34 of 97 instructions differ, only register scheduling of the first two
 * counter blocks (drop and lob) differs; the logic is identical. fn_88667C98 (0x88667C98): the original
 * addresses the tail block as `&contact + 0x80` kept in a register; the compiler folds it here (offsets
 * 0xe4/0x174 instead of 0x54(r11)/0x64(r9)), so 41 instructions differ.
 */
/* GP1: per-player shot-type / stroke-side counters of the shot-evaluation package (WP1). */

/* crc32 hashes of the shot labels, compared against ShotRecord::shot_type / stroke_side.
   crc32 = zlib crc32 of the ASCII name (verified, see work/gameplay-notes/gp1.md). */
#define GP1_HASH_DROPSHOT 0x990377a5u  /* "DropShot" */
#define GP1_HASH_LOB      0xc718daaau  /* "Lob" */
#define GP1_HASH_SLICE    0xfc6f57a1u  /* "Slice" */
#define GP1_HASH_TOPSPIN  0xd9fa1b37u  /* "TopSpin" */
#define GP1_HASH_FLAT     0xf578057au  /* "Flat" */
#define GP1_HASH_SMASH    0x7eb30f90u  /* "Smash" */
#define GP1_HASH_SERVICE  0x2e20a34eu  /* "Service" */
#define GP1_HASH_FOREHAND 0xe630e16bu  /* "Forehand" */
#define GP1_HASH_BACKHAND 0x45fffb93u  /* "Backhand" */

/* Per player statistics record, stride 0x134, stored behind a self-relative offset. */
struct Gp1PlayerStats {
    unsigned char pad0[0x7c];
    int backhand_count;  /* +0x7c */
    int forehand_count;  /* +0x80 */
    unsigned char pad1[0xa8 - 0x84];
    int topspin_count;   /* +0xa8 */
    int slice_count;     /* +0xac */
    int flat_count;      /* +0xb0 */
    int lob_count;       /* +0xb4 */
    int drop_count;      /* +0xb8 */
    unsigned char pad2[0x134 - 0xbc];
};

/* Self-relative array header: the first word at the field address is the byte offset
   (from the field address) of the element storage. */
struct Gp1RelArray {
    int offset;  /* byte offset from this header to the element storage */
};

struct Gp1MatchStats {
    unsigned char pad0[0x5c];
    struct Gp1RelArray players; /* +0x5c */
};

struct Gp1ShotRecordA {
    unsigned char pad00[0xe4];
    unsigned char valid;           /* +0xe4 */
    unsigned char pad0[0x16c - 0xe5];
    unsigned int stroke_side_hash; /* +0x16c */
    unsigned char pad1[0x174 - 0x170];
    unsigned int shot_type_hash;   /* +0x174 */
    unsigned char pad2[0x19d - 0x178];
    unsigned char is_special;      /* +0x19d */
    unsigned char pad3[0x220 - 0x19e];
    int hitter_index;              /* +0x220 */
};

struct Gp1PlayerNode {
    unsigned char pad0[0x28];
    int player_index; /* +0x28 */
};

struct Gp1PlayerRef {
    unsigned char pad0[0x4c];
    struct Gp1PlayerNode *node; /* +0x4c */
};

struct Gp1ShotEvaluatorA {
    unsigned char pad0[0x20];
    struct Gp1ShotRecordA *shot;      /* +0x20 */
    unsigned char pad1[0x28 - 0x24];
    struct Gp1MatchStats *stats;      /* +0x28 */
};

#ifdef _MSC_VER
#define GP1_INLINE __forceinline
#else
#define GP1_INLINE static inline
#endif

GP1_INLINE struct Gp1PlayerStats *gp1_stats_at(struct Gp1RelArray *array, int index)
{
    return (struct Gp1PlayerStats *)((char *)array + (array->offset + index * 0x134));
}

#define GP1_PLAYER_STATS(match, index) gp1_stats_at(&(match)->players, (index))

/* Swing_DLL.xex 0x88667720: counts the finished shot by type (drop, lob, slice, topspin, flat) for the hitter. */
void ts4_shot_stats_count_shot_type_88667720(struct Gp1ShotEvaluatorA *self, struct Gp1PlayerRef *player)
{
    struct Gp1ShotRecordA *shot = self->shot;
    unsigned int shot_type = shot->shot_type_hash;
    int index = player->node->player_index;

    if (shot_type == GP1_HASH_DROPSHOT) {
        GP1_PLAYER_STATS(self->stats, index)->drop_count = GP1_PLAYER_STATS(self->stats, index)->drop_count + 1;
        return;
    }
    if (shot_type == GP1_HASH_LOB) {
        GP1_PLAYER_STATS(self->stats, index)->lob_count = GP1_PLAYER_STATS(self->stats, index)->lob_count + 1;
        return;
    }
    if (shot->is_special != 0) {
        return;
    }
    if (shot->stroke_side_hash == GP1_HASH_SERVICE) {
        return;
    }
    if (shot_type == GP1_HASH_SLICE) {
        GP1_PLAYER_STATS(self->stats, index)->slice_count = GP1_PLAYER_STATS(self->stats, index)->slice_count + 1;
    } else if (shot_type == GP1_HASH_TOPSPIN) {
        GP1_PLAYER_STATS(self->stats, index)->topspin_count = GP1_PLAYER_STATS(self->stats, index)->topspin_count + 1;
    } else if (shot_type == GP1_HASH_FLAT) {
        GP1_PLAYER_STATS(self->stats, index)->flat_count = GP1_PLAYER_STATS(self->stats, index)->flat_count + 1;
    }
}

/* View of the shot record used by the stroke-side counter: a contact block at +0x90 whose tail at +0x110
   holds the classification hashes and the hitter index. */
struct Gp1ShotTail {
    unsigned char pad0[0x5c];
    unsigned int stroke_side_hash; /* +0x5c  (record +0x16c) */
    unsigned char pad1[0x64 - 0x60];
    unsigned int shot_type_hash;   /* +0x64  (record +0x174) */
    unsigned char pad2[0x110 - 0x68];
    int hitter_index;              /* +0x110 (record +0x220) */
};

struct Gp1ShotContact {
    unsigned char pad0[0x54];
    unsigned char valid;           /* +0x54  (record +0xe4) */
    unsigned char pad1[0x80 - 0x55];
    struct Gp1ShotTail tail;       /* +0x80  (record +0x110) */
};

struct Gp1ShotRecordB {
    unsigned char pad0[0x90];
    struct Gp1ShotContact contact; /* +0x90 */
};

struct Gp1ShotEvaluatorB {
    unsigned char pad0[0x20];
    struct Gp1ShotRecordB *shot;   /* +0x20 */
    unsigned char pad1[0x28 - 0x24];
    struct Gp1MatchStats *stats;   /* +0x28 */
};

/* Swing_DLL.xex 0x88667C98: counts the finished shot as forehand or backhand for the hitter (smashes excluded). */
void ts4_shot_stats_count_stroke_side_88667C98(struct Gp1ShotEvaluatorB *self)
{
    struct Gp1ShotContact *contact = &self->shot->contact;
    struct Gp1ShotTail *tail = &contact->tail;
    unsigned int shot_type;
    unsigned int stroke_side;
    int index;
    int *counter;

    if (contact->valid == 0) {
        return;
    }
    shot_type = tail->shot_type_hash;
    index = tail->hitter_index;
    if (shot_type == GP1_HASH_SMASH) {
        return;
    }
    stroke_side = tail->stroke_side_hash;
    if (stroke_side == GP1_HASH_FOREHAND) {
        counter = &gp1_stats_at(&self->stats->players, index)->forehand_count;
        *counter = *counter + 1;
    } else if (stroke_side == GP1_HASH_BACKHAND) {
        counter = &gp1_stats_at(&self->stats->players, index)->backhand_count;
        *counter = *counter + 1;
    }
}
