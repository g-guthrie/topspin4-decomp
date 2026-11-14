/* GP1: reward list append used by the shot-evaluation package (WP1). */

struct Gp1U32Vector {
    unsigned int *begin; /* +0x00 */
    unsigned int *end;   /* +0x04 */
    unsigned int *cap;   /* +0x08 */
};

struct Gp1RewardCollector;

void fn_88263908(struct Gp1U32Vector *vector, unsigned int *where, const unsigned int *value, int count, int flag);

struct Gp1RewardList {
    unsigned char pad0[8];
    struct Gp1U32Vector hashes; /* +0x08 */
};

/* Swing_DLL.xex 0x88673630: appends a reward/quality hash to the shot's reward list (vector push_back). */
void ts4_shot_reward_list_push_88673630(struct Gp1RewardList *self, unsigned int reward_hash)
{
    struct Gp1U32Vector *vector = &self->hashes;

    if (vector->end != vector->cap) {
        if (vector->end != 0) {
            *vector->end = reward_hash;
        }
        vector->end = vector->end + 1;
    } else {
        fn_88263908(vector, vector->end, &reward_hash, 1, 1);
    }
}
