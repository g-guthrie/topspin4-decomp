/* CX37: text accessors, Swing_DLL.xex 0x8895xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void ts4_assign_formatted_text(void *dst, const char *text);
extern void ts4_destroy_owned_object(void *p);
extern u8 lbl_880C1320[];

typedef struct Cx37TxtSrc { u8 pad[0x3c]; char *p3c; } Cx37TxtSrc;
#define CX37_TXT(NAME, ADDR, OFF) \
    void *NAME##_##ADDR(void *dst, Cx37TxtSrc *src) \
    { \
        if (src->p3c) { \
            int *q = (int *)(src->p3c + (OFF)); \
            if (*q != -1) { \
                ts4_assign_formatted_text(dst, (const char *)q + *q); \
                return dst; \
            } \
        } \
        ts4_assign_formatted_text(dst, (const char *)lbl_880C1320); \
        return dst; \
    }
CX37_TXT(ts4_text_at_10, 88957D88, 0x10)
CX37_TXT(ts4_text_at_28, 88957EA0, 0x28)
CX37_TXT(ts4_text_at_10b, 88958038, 0x10)
CX37_TXT(ts4_text_at_4c, 88958150, 0x4c)

#if 0 /* near miss, not byte-identical */
/* 0x88958480: text at +0x10, copied through a temporary */
void *ts4_text_copy_at_10_88958480(void *dst, Cx37TxtSrc *src)
{
    void *tmp;
    void *t;
    if (src->p3c) {
        int *q = (int *)(src->p3c + 0x10);
        if (*q != -1) {
            ts4_assign_formatted_text(&tmp, (const char *)q + *q);
            goto done;
        }
    }
    ts4_assign_formatted_text(&tmp, (const char *)lbl_880C1320);
done:
    t = tmp;
    ts4_assign_formatted_text(dst, (const char *)t);
    ts4_destroy_owned_object(t);
    return dst;
}
#endif

typedef struct Cx37TxtG { u8 pad[0x50]; char *s50; } Cx37TxtG;
extern Cx37TxtG *lbl_88D45888;
#if 0 /* near miss, not byte-identical */
/* 0x8895B610 */
void *ts4_text_global_8895B610(void *dst)
{
    Cx37TxtG *g = lbl_88D45888;
    if (g == 0) {
        ts4_assign_formatted_text(dst, (const char *)lbl_880C1320);
    } else {
        void *tmp;
        void *t;
        ts4_assign_formatted_text(&tmp, g->s50);
        t = tmp;
        ts4_assign_formatted_text(dst, (const char *)t);
        ts4_destroy_owned_object(t);
    }
    return dst;
}
#endif
