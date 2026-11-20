/* 0x883D3168: finds an entry by name (or by prefix+name+extension built with 883296A0/88329700/88329C00, taken as strncpy/strncat/strstr) and id, returning its value; 0x1F not ready, 0x25 null name, 0x17 not found */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Ent { int vt; Link link; char pad[0x11 - 0xc]; char name[0x114 - 0x11]; int value; int id; } Ent;
typedef struct Sys { char pad0[0x20]; const char *prefix; char pad1[0x8090 - 0x24]; Link head; char pad2[0x809c - 0x8098]; void *ready; } Sys;
extern const char lbl_880F6350[];
void ts4_copy_bytes_until_nul_883296A0(char *dst, const char *src, int n);
char *fn_88329700(char *dst, const char *src, unsigned int n);
char *fn_88329C00(const char *s, const char *sub);
int fn_88329868(const char *a, const char *b);

#define ENT(l) ((l) ? (Ent *)((char *)(l) - 4) : 0)

int fn_883D3168(Sys *s, const char *name, int id, int *out)
{
    char buf[0x100];
    Ent *e;
    if (!s->ready)
        return 0x1f;
    if (!name)
        return 0x25;
    for (e = ENT(s->head.next); (e ? &e->link : 0) != &s->head; e = ENT(e->link.next)) {
        if (s->prefix) {
            ts4_copy_bytes_until_nul_883296A0(buf, s->prefix, 0x100);
            fn_88329700(buf, e->name, 0x100);
            if (!fn_88329C00(buf, lbl_880F6350))
                fn_88329700(buf, lbl_880F6350, 0x100);
        }
        if ((!fn_88329868(e->name, name) || (s->prefix && !fn_88329868(buf, name))) && id == e->id) {
            if (out)
                *out = e->value;
            return 0;
        }
    }
    return 0x17;
}
