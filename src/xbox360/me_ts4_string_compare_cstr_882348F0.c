/* Swing_DLL.xex 0x882348F0: std::string-style compare({first,last}, const char *): memcmp of the shorter length, then the length order.
 * Leaf; memcmp/strlen intrinsics, std::min by reference (stack slots). */
#pragma intrinsic(memcmp, strlen)
int memcmp(const void *, const void *, unsigned int);
unsigned int strlen(const char *);
typedef struct String { char *first; char *last; } String;
static __inline const int *min_ref(const int *a, const int *b) { return *a < *b ? a : b; }
int fn_882348F0(const String *s, const char *p)
{
    int n2 = strlen(p);
    int n1 = s->last - s->first;
    int r = memcmp(s->first, p, *min_ref(&n2, &n1));
    if (r != 0) return r;
    if (n1 < n2) return -1;
    return n2 < n1;
}
