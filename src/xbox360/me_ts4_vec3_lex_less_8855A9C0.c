/* 0x8855A9C0: stores in *out whether vector a orders before b lexicographically by x, then y, then z. */
/* Matched on /Oc (agAF). Each early true written as its own { *out = 1; return; } block; the bool goes through the out pointer. */
typedef struct V3 { float x, y, z; } V3;
void fn_8855A9C0(unsigned char *out, const V3 *a, const V3 *b)
{
    if (a->x < b->x) {
        *out = 1;
        return;
    }
    if (a->x == b->x && a->y < b->y) {
        *out = 1;
        return;
    }
    *out = a->x == b->x && a->y == b->y && a->z < b->z;
}
