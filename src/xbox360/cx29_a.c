/* Swing_DLL.xex game core 0x8818C6C0-0x8819C000 (CW29). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
typedef unsigned int cx_uptr;
#else
typedef unsigned long cx_uptr;
#endif

char *fn_8819B5F8(char **self, u32 newlen);
void *fn_88562DC0(void *dst, const void *src, u32 n);

/* 0x8819BD70: out = substring of src starting at start with count characters (both clamped) */
u32 ts4_if_get_u32_offc_8819B6C0(void *);
char **ts4_string_assign_alloc_8819B060(char **out, const char *src, u32 len, void *a);
char **ts4_string_mid_8819BD70(char **out, char **src, int start, int count)
{
    char *s = *src;
    int len;
    if (start < 0) start = 0;
    if (count < 0) count = 0;
    len = ((int *)s)[-3];
    if (start + count > len) count = len - start;
    if (start > len) count = 0;
    if (start == 0 && count == len) {
        *out = (char *)(cx_uptr)ts4_if_get_u32_offc_8819B6C0(s - 0x10) + 0x10;
    } else {
        ts4_string_assign_alloc_8819B060(out, s + start, count, ((void **)s)[-4]);
    }
    return out;
}

/* 0x8819AAB8: build a wide string from a wide C string with the default owner */
struct cx_owner_vt { void *s[4]; void *(*alloc)(void *self); };
struct cx_owner_o { struct cx_owner_vt *vt; };
extern struct cx_owner_o *lbl_88D3E414;
struct cx_owner_o *fn_8819A9D8(void);
u16 *fn_8819C528(u16 **self, u32 len);
u16 **ts4_wstring_from_wide_8819AAB8(u16 **self, const u16 *src)
{
    u32 len = 0;
    struct cx_owner_o *o;
    u16 *buf;
    const u16 *q;
    u16 *d;
    const u16 *p = src;
    if (*p != 0) {
        do {
            p++;
            len++;
        } while (*p != 0);
    }
    o = lbl_88D3E414;
    if (o == 0)
        o = fn_8819A9D8();
    *self = (u16 *)((u8 *)o->vt->alloc(o) + 0x10);
    buf = fn_8819C528(self, len);
    q = src;
    d = buf;
    while (*q != 0) {
        *d = *q;
        q++;
        d++;
    }
    {
        u16 *r = *self;
        ((u32 *)r)[-3] = len;
        r[len] = 0;
    }
    return self;
}

/* 0x8819BA78: strip trailing then leading whitespace (ctype class test) */
int ts4_addr_lbl_88C317A0_88567870(int c);
char **ts4_string_trim_8819BA78(char **self)
{
    char *p = *self;
    char *last = 0;
    if (*p != 0) {
        do {
            if (ts4_addr_lbl_88C317A0_88567870((u8)*p) != 0) {
                if (last == 0)
                    last = p;
            } else {
                last = 0;
            }
            p++;
        } while (*p != 0);
        if (last != 0) {
            int n = (int)(last - *self);
            fn_8819B5F8(self, n);
            ((int *)*self)[-3] = n;
            (*self)[n] = 0;
        }
    }
    p = *self;
    if (ts4_addr_lbl_88C317A0_88567870((u8)*p) != 0) {
        do {
            p++;
        } while (ts4_addr_lbl_88C317A0_88567870((u8)*p) != 0);
    }
    if (p != *self) {
        int off = (int)(p - *self);
        char *nb = fn_8819B5F8(self, ((int *)*self)[-3]);
        int len = ((int *)*self)[-3] - off;
        fn_88562DC0(nb, nb + off, len + 1);
        ((int *)*self)[-3] = len;
        (*self)[len] = 0;
    }
    return self;
}
