/* near-miss: 32 off, size 0x98 vs 0xa8 (target re-reads keys begin/end after the checks, clrrwi copy of begin; C and C++ helper forms give identical code) */
/* ME: position a track-key cursor at frame n (pick.py throughput). Swing_DLL.xex 0x886609E0 */
struct Ts4TrackKey { unsigned char pad_00[0x24]; int frame; /* +0x24 */ unsigned char pad_28[8]; }; /* 0x30 */
struct Ts4TrackKeys { struct Ts4TrackKey *begin; struct Ts4TrackKey *end; };
struct Ts4TrackData { unsigned char pad_000[0x5A0]; struct Ts4TrackKeys keys; /* +0x5A0 */ };
struct Ts4Track {
    unsigned char pad_00[0x88];
    struct Ts4TrackData *data;   /* +0x88 */
    int id;                      /* +0x8C */
};
struct Ts4TrackCursor {
    int index;                   /* +0x0 */
    struct Ts4Track *track;      /* +0x4 */
    float t;                     /* +0x8 */
    int id;                      /* +0xC */
};

void ts4_track_cursor_seek_886609E0(struct Ts4TrackCursor *c, struct Ts4Track *track, int frame)
{
    struct Ts4TrackKeys *keys;
    int i;
    c->track = track;
    c->index = 0;
    c->t = 0.0f;
    c->id = track ? track->id : 0;
    keys = &track->data->keys;
    if (keys->begin == keys->end)
        return;
    i = frame - keys->begin->frame;
    if (i < 0)
        return;
    if (i >= keys->end - keys->begin)
        return;
    {
        struct Ts4TrackCursor n;
        n.index = i;
        n.track = track;
        n.t = 0.0f;
        n.id = track->id;
        *c = n;
    }
}
