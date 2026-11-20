/* Loader_DLL.xex 0x832D52A0-0x832D5364, executable version 0.0.0.3. */
typedef struct L29E { unsigned w0; char pad[20]; } L29E;
typedef struct L29S {
    char pad0[0x88]; int w; int h;
    char pad1[0x110 - 0x90]; L29E *e;
} L29S;

extern void fn_832D1E98(L29S *s, int x, int y, unsigned m, char *a, char *b, char *c, char *d, char *e, char *f, int fy, int fx);
extern void fn_833158C8(L29S *s, int x, int y, unsigned m, char *a, char *b, char *c, char *d, char *e, char *f, int fy, int fx);

#define L29_BODY(NAME, CALL) \
void NAME(L29S *s) \
{ \
    L29E *p = s->e; \
    int x, y; \
    for (y = 0; y < s->h; y++) { \
        for (x = 0; x < s->w; x++) { \
            int yz = (y == 0); \
            L29E *q = p - *(volatile int *)&s->w; \
            int xz = (x == 0); \
            CALL(s, x, y, (p->w0 >> 8) & 7, (char *)p + 8, (char *)q + 8, (char *)p - 0x10, (char *)p + 0xe, (char *)q + 0xe, (char *)p - 0xa, yz, xz); \
            p++; \
        } \
    } \
}

L29_BODY(ts4l_mb_walk_832D52A0, fn_832D1E98)
L29_BODY(ts4l_mb_walk_83306240, fn_833158C8)
