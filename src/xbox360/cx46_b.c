/* CX46 part b: functions with a divide (need /Oc), Pam Display renderer 0x88720000-0x88740000. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX46_INL static __forceinline
#else
#define CX46_INL static inline
#endif
#define W(p, o) (*(u32 *)((char *)(p) + (o)))

typedef struct Cx46Vec { char *first; char *last; } Cx46Vec;
extern void fn_8825EFC8(char *dst, char *src);
extern void fn_88233678(char *a, char *b);
extern void ts4_if_call_seq_u32_off0_88224160(void *p);

/* 0x8872E1D8: clear a vector of 0x14-byte records from its own end, then release the allocator */
void ts4_rec14_vec_clear_8872E1D8(Cx46Vec *v)
{
    char *s = v->last;
    char *p = v->first;
    int n = (v->last - s) / 0x14;
    while (n > 0) {
        fn_8825EFC8(p, s);
        W(p, 0x10) = W(s, 0x10);
        n--;
        p += 0x14;
        s += 0x14;
    }
    fn_88233678(p, v->last);
    v->last = p;
    ts4_if_call_seq_u32_off0_88224160(v);
}
