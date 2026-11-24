/* 0x883C8F98: unless unchanged and not forced, clamps both values to [0, 1], stores them at +0x108/+0x10C and forwards them to the handle at q+0x18 */
/* Matched on /O1 plain only (work/army/ME/v.py chk); clamp is MAX(MIN(v, 1), 0) with macros, so MIN is evaluated twice as in the target. */
typedef struct Q { char pad[0x18]; void *h; } Q;
typedef struct T { char pad[0xAC]; Q *q; char pb0[0x108 - 0xB0]; float x, y; } T;
int ts4_fetch_then_use_two_floats_88317B38(void *h, float x, float y);
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
int ts4_set_pan_clamped_883C8F98(T *t, float x, float y, unsigned char force)
{
    int r;
    if (t->x == x && t->y == y && !force) return 0;
    x = MAX(MIN(x, 1.0f), 0.0f);
    y = MAX(MIN(y, 1.0f), 0.0f);
    t->x = x;
    t->y = y;
    if (t->q ? t->q->h : 0) {
        r = ts4_fetch_then_use_two_floats_88317B38(t->q ? t->q->h : 0, x, y);
        if (r) return r;
    }
    return 0;
}
