/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x883E3F20: rescales four 0x4C-byte rects by the new offsets from ts4_if_call_seq_fn_885640B0_883E3B10/fn_883CB860 and pushes each to the
 * sink at +0x144. Flags /O1.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_883E3F20_nearmiss.c (Q5S sweep, 2026-11-24): `It *it` is declared before `int i, r` and t->dy goes through a block-local temporary in the first loop.
 * See work/specs/Q5S/sweep_883E3F20.json for route and flags. */
typedef struct It { int x; int p4; int y; char pad[0x4C - 0xC]; } It;
typedef struct T { int p0; float scale; float ratio; int dx; int dy; It it[4]; void *sink; } T;
float ts4_if_call_seq_fn_885640B0_883E3B10(float v);
int fn_883CB860(float v);
int ts4_lookup_then_forward_88317C68(void *sink, It *it);
int ts4_rect_rescale_883E3F20(T *t, float scale)
{
    It *it;
    int i, r;
    t->scale = scale;
    for (i = 0; i < 4; ++i) {
        t->it[i].x -= t->dx;
        { int dy = t->dy; t->it[i].y -= dy; }
    }
    t->dx = fn_883CB860(ts4_if_call_seq_fn_885640B0_883E3B10(t->scale));
    t->dy = fn_883CB860(ts4_if_call_seq_fn_885640B0_883E3B10(t->ratio * t->scale));
    for (i = 0, it = t->it; i < 4; ++i, ++it) {
        it->x += t->dx;
        it->y += t->dy;
        if (t->sink) {
            r = ts4_lookup_then_forward_88317C68(t->sink, it);
            if (r) return r;
        }
    }
    return 0;
}
