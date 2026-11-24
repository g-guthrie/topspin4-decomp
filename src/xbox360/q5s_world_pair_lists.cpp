/*
 * 0x888905C0 (pres): remove every (a, b) pair from list `idx` of a session record's pair-vector array
 * (+0x08; the record is torn down by 0x88890CB0, q5s_world_session_clear.c). STLport vector<pair> with
 * erase(pos) inlined: copy the tail down one slot unless pos is the last element, then --finish.
 * LTCG route; the copy loop is STLport's `for (n = last - first; n > 0; --n)` form.
 */
typedef unsigned int u32;

struct Ts4WorldPair {
    u32 a;
    u32 b;
};

static inline Ts4WorldPair *world_pair_copy(Ts4WorldPair *first, Ts4WorldPair *last, Ts4WorldPair *result)
{
    for (int n = last - first; n > 0; --n) {
        *result = *first;
        ++first;
        ++result;
    }
    return result;
}

struct Ts4WorldPairVec {
    Ts4WorldPair *first;
    Ts4WorldPair *last;
    Ts4WorldPair *end_cap;
    Ts4WorldPair *begin() { return first; }
    Ts4WorldPair *end() { return last; }
    Ts4WorldPair *erase(Ts4WorldPair *pos)
    {
        if (pos + 1 != last)
            world_pair_copy(pos + 1, last, pos);
        --last;
        return pos;
    }
};

struct Ts4WorldPairSession {
    char pad_00[8];
    Ts4WorldPairVec *lists;                      /* +0x08 V 888905C0 88890CB0 */
};

extern "C" void ts4_pres_session_remove_pair_888905C0(Ts4WorldPairSession *self, u32 a, u32 b, int idx)
{
    Ts4WorldPair *it = self->lists[idx].begin();
    while (it != self->lists[idx].end()) {
        if (a == it->a && b == it->b)
            it = self->lists[idx].erase(it);
        else
            ++it;
    }
}
