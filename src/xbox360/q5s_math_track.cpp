/*
 * 0x88870500: reads the position (first three floats) of key `key` from a key track and returns true;
 * track 0 is the set's own key array, track n > 0 is element n-1 of the set's sub-track vector at +0x84
 * (elements 0x84 bytes, key array pointer first). Out-of-range track returns false.
 * Only caller: 0x888C6310 (fk_025.c), which passes the object at +0x1C. Semantics beyond that are open,
 * so the types stay private.
 *
 * Codegen: C++ is needed. The vector operator[] returning a reference gives the `clrrwi r10,r8,0` copy of
 * begin, and size() as `end - begin` loads +0x88 before +0x84. The index `track - 1` must be a named local,
 * otherwise it folds into a -0x84 displacement.
 */
struct Q5sKey { float x, y, z; char pad0c[0xc]; };          /* 0x18 bytes */
struct Q5sV3 { float x, y, z; };

template <class T> struct Q5sVec {
    T *b; T *e; T *c;
    unsigned int size() const { return e - b; }
    T &operator[](unsigned int i) { return b[i]; }
};

struct Q5sTrack { Q5sKey *keys; char pad04[0x80]; };        /* 0x84 bytes */
struct Q5sTrackSet {
    Q5sKey *keys;                                           /* +0x00 track 0 */
    char pad04[0x80];
    Q5sVec<Q5sTrack> tracks;                                /* +0x84 tracks 1.. */
};

static inline void q5s_key_pos(Q5sV3 *out, const Q5sKey &k)
{
    out->x = k.x; out->y = k.y; out->z = k.z;
}

extern "C" bool ts4_track_key_pos_get_88870500(Q5sTrackSet *s, Q5sV3 *out, unsigned int track, int key)
{
    if (track == 0) {
        q5s_key_pos(out, s->keys[key]);
        return true;
    }
    unsigned int i = track - 1;
    if (i < s->tracks.size()) {
        q5s_key_pos(out, s->tracks[i].keys[key]);
        return true;
    }
    return false;
}
