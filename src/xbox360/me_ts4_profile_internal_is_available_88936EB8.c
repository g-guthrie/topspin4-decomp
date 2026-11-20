/* 0x88936EB8: Finds the profile entry with the given index in the online state list at +0x1c and returns 1 if its state is 2, or state 1 when requireFull is 0; returns 0 otherwise or when absent. */
/* Matched on /Oc (agAH). State test as an inline helper returning an int result cast to u8 (keeps the separate li/clrlwi tails); requireFull tested as !requireFull. */
typedef struct ProfileEntry { int unk0; int index; int state; } ProfileEntry;
typedef struct ProfileList { int unk0; ProfileEntry **begin; ProfileEntry **end; } ProfileList;
typedef struct OnlineState { char pad[0x1c]; ProfileList *profiles; } OnlineState;
static __forceinline unsigned char Profile_IsAvailable(ProfileEntry *f, unsigned char requireFull)
{
    int r;
    if (f->state == 2 || (f->state == 1 && !requireFull))
        r = 1;
    else
        r = 0;
    return (unsigned char)r;
}
unsigned char ts4_profile_internal_is_available(OnlineState *o, int profileIndex, unsigned char requireFull)
{
    ProfileEntry **it;
    ProfileEntry **end = o->profiles->end;
    for (it = o->profiles->begin; it != end; it++) {
        if (profileIndex == (*it)->index)
            return Profile_IsAvailable(*it, requireFull);
    }
    return 0;
}
