#ifdef _MSC_VER
#define HS3_INLINE __forceinline
#else
#define HS3_INLINE static inline
#endif
/* HS3 hand-matched functions, range 0x887..0x88A. */
unsigned fn_88608590(unsigned, unsigned);

struct HS3Rec134 { char pad[0x10c]; unsigned key; char pad2[0x134 - 0x110]; };
struct HS3RecVec { struct HS3Rec134 *begin, *end; };

static struct HS3Rec134 *hs3_find_key(struct HS3RecVec *vec, unsigned key)
{
    struct HS3Rec134 *it;
    for (it = vec->begin; it < vec->end; it++) {
        if (it->key == key)
            return it;
    }
    return 0;
}

/* True if any 0x134-byte record in the vector has key equal to the lookup of *name. */
int ts4_recvec_contains_key_88703538(struct HS3RecVec *vec, unsigned *name)
{
    unsigned key = fn_88608590(0, *name);
    return hs3_find_key(vec, key) != 0;
}

