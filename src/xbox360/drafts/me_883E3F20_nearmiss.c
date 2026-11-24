/* 0x883E3F20 near miss (2 off, /O1): rescales four 0x4C-byte rects by the new offsets from fn_883E3B10/fn_883CB860 and pushes each to the sink at +0x144. */
/* Residue: in the second loop the target loads t->dx into r11 and it->x into r10; every operand order and local form gives the swap. */
typedef struct It { int x; int p4; int y; char pad[0x4C - 0xC]; } It;
typedef struct T { int p0; float scale; float ratio; int dx; int dy; It it[4]; void *sink; } T;
float fn_883E3B10(float v);
int fn_883CB860(float v);
int fn_88317C68(void *sink, It *it);
int ts4_rect_rescale_883E3F20(T *t, float scale)
{
    int i, r;
    It *it;
    t->scale = scale;
    for (i = 0; i < 4; ++i) {
        t->it[i].x -= t->dx;
        t->it[i].y -= t->dy;
    }
    t->dx = fn_883CB860(fn_883E3B10(t->scale));
    t->dy = fn_883CB860(fn_883E3B10(t->ratio * t->scale));
    for (i = 0, it = t->it; i < 4; ++i, ++it) {
        it->x += t->dx;
        it->y += t->dy;
        if (t->sink) {
            r = fn_88317C68(t->sink, it);
            if (r) return r;
        }
    }
    return 0;
}
