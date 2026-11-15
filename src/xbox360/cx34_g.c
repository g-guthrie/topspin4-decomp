/* CW34 part g: functions with a constant divide (built with /Oc), 0x888C0000-0x888D8000. */
typedef unsigned int u32;
typedef unsigned char u8;
#define CX34_U32(p, o) (*(u32 *)((char *)(p) + (o)))
#define CX34_I32(p, o) (*(int *)((char *)(p) + (o)))
#define CX34_U8(p, o) (*(u8 *)((char *)(p) + (o)))
#define CX34_PTR(p, o) (*(char **)((char *)(p) + (o)))

/* 0x888C2A38 */
u8 ts4_get_flag_54_by_index_888C2A38(char *self, u32 n)
{
    char *p = CX34_PTR(self, 0x1c);
    if (p != 0) {
        char *r = p;
        if (n != 0) {
            char *b = CX34_PTR(p, 0x84);
            char *e = CX34_PTR(p, 0x88);
            u32 k = n - 1;
            if (k >= (u32)((e - b) / 0x84)) return 0;
            r = b + k * 0x84;
        }
        return CX34_U8(r, 0x54);
    }
    return 0;
}



extern void ts4_vec204_move_tail_881B9148(void *p);
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#pragma function(memcpy)
#endif
typedef struct Cx34E240 { char d[0xf0]; } Cx34E240;
typedef struct Cx34E56 { char d[0x38]; } Cx34E56;
#define CX34_CLEAR_VEC(NAME, ET, VOFF, OWN) \
static __inline ET *NAME(ET *first, ET *last, ET *dst) \
{ \
    int n = last - first; \
    ET *s = first; \
    ET *p = dst; \
    while (n > 0) { \
        *p = *s; \
        n--; \
        s++; \
        p++; \
    } \
    return p; \
}
CX34_CLEAR_VEC(cx34_copy240, Cx34E240, 0x3c, 0)
CX34_CLEAR_VEC(cx34_copy56, Cx34E56, 0x1c, 0)

/* 0x888C7FD8 */
void ts4_reset_list_and_vec240_888C7FD8(char *self)
{
    char *v;
    CX34_U8(self, 8) = 0;
    ts4_vec204_move_tail_881B9148(self + 0x10);
    v = self + 0x3c;
    CX34_PTR(v, 4) = (char *)cx34_copy240((Cx34E240 *)CX34_PTR(v, 4), (Cx34E240 *)CX34_PTR(v, 4), (Cx34E240 *)CX34_PTR(v, 0));
}

/* 0x888CB7A0 */
void ts4_reset_vec56_and_list_888CB7A0(char *self)
{
    char *v = self + 0x1c;
    CX34_PTR(v, 4) = (char *)cx34_copy56((Cx34E56 *)CX34_PTR(v, 4), (Cx34E56 *)CX34_PTR(v, 4), (Cx34E56 *)CX34_PTR(v, 0));
    CX34_U8(self, 8) = 0;
    ts4_vec204_move_tail_881B9148(self + 0x10);
}

extern u8 fn_8886FED0(char *o, u32 id, u32 *a, u32 *b, u32 *c);
