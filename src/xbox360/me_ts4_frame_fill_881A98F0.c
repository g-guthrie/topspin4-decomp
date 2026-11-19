/* 0x881A98F0: Fills [first, last) of 40-byte frames (three Vec3 plus a float) with copies of *val. */
/* Matched on /Oc /O2 (agAH). The Vec3 members must be copied through a small out-of-line-looking Vec3 copy helper; a whole-struct assignment gives a word-copy loop and member assignment drops the base-pointer adds. */
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Frame { Vec3 a; Vec3 b; Vec3 c; float w; } Frame;

static void Vec3_Copy(Vec3 *d, const Vec3 *s) { d->x = s->x; d->y = s->y; d->z = s->z; }
void fn_881A98F0(Frame *first, Frame *last, const Frame *val)
{
    for (; first != last; ++first) {
        Vec3_Copy(&first->a, &val->a);
        Vec3_Copy(&first->b, &val->b);
        Vec3_Copy(&first->c, &val->c);
        first->w = val->w;
    }
}
