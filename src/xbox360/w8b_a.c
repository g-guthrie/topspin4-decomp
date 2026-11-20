/* W8B batch A */
typedef unsigned int u32;
extern void fn_886DBB30(void *a, float b, int n, void *first, void *second, u32 *out);

struct W8bArr { int rel; u32 count; };
struct W8bWalk {
    int rel_00; u32 w04; int count; u32 w0c; u32 w10; u32 pad14;
    struct W8bArr arr; u32 w20; u32 w24; u32 w28;
};

void ts4_walk_clamped_886DFA60(void *a, float b, struct W8bWalk *walk, int limit)
{
    u32 result = 0;
    int n = walk->count;
    struct W8bArr *arr;
    void *first;
    void *second;
    if (limit >= 0 && n >= limit)
        n = limit;
    arr = &walk->arr;
    first = (char *)walk + walk->rel_00;
    walk->w04 = 1;
    arr->count = 1;
    second = (void *)(unsigned long)(arr->rel + (u32)(unsigned long)arr);
    fn_886DBB30(a, b, n, first, second, &result);
    walk->w04 = result;
    walk->arr.count = result;
    walk->w10 = result;
    walk->w28 = result;
}
struct W8bRel { int rel; int count; };
struct W8bEnt { u32 key; float val; };

void ts4_copy_matching_values_88671028(struct W8bRel *a, struct W8bRel *b)
{
    int i, j;
    int n = a->count;
    for (i = 0; i < n; i++) {
        struct W8bEnt *e = (struct W8bEnt *)((char *)a + (i * 8 + a->rel));
        u32 key = e->key;
        for (j = 0; j < b->count; j++) {
            struct W8bEnt *f = (struct W8bEnt *)((char *)b + (j * 8 + b->rel));
            if (f->key == key) {
                f->val = e->val;
                break;
            }
        }
    }
}
