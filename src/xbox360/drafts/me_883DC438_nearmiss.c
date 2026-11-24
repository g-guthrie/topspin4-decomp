/* NEAR MISS (agAD, b167): /O1, 58 off but structurally right: the target keeps the -1 argument pair of 88316F00 in r29 across
 * both calls (one more saved register, which shifts every register), and it stores mode before the two zeroed sizes. */
/* Swing_DLL.xex 0x883DC438: fills an info record for a resource: name (0xFF chars), +0x48 word, the sum of the
 * handle's per-part sizes (+0x4C array, count from 88316B30), the child count, +0x50, the children with flag byte +0x11,
 * the summed child and own sizes (88316F00) and a mode (0 when flag 0x80, else 1/2 by flag 0x200). 0x25 on a null record. agAD: /O1. */
typedef struct Link { struct Link *next; } Link;
typedef struct List { int pad; Link head; } List;
typedef struct Child { int pad0[4]; unsigned char pad10, flag; char pad12[6]; void *handle; } Child;
typedef struct Res {
    char pad0[0x18]; unsigned int flags; const char *name; char pad20[8]; void *handle; List children;
    char pad34[0x14]; unsigned int f48; int *parts; unsigned int f50;
} Res;
typedef struct Info {
    char name[0x100]; unsigned int f48; int parts; unsigned int nchildren; unsigned int f50; unsigned int nflagged;
    int child_size; int own_size; int mode;
} Info;
void *ts4_memset(void *dst, int c, unsigned n);
void ts4_copy_bytes_until_nul_883296A0(char *dst, const char *src, int n);
int ts4_if_get_fn_8832BFC0_88316B30(void *h, int *count);
int ts4_if_get_fn_8832BFC0_88316F00(void *h, int a, int b, int *size, int c);

int fn_883DC438(Res *r, Info *info)
{
    Link *l;
    int n, i, e;
    int any = -1;
    unsigned int c;
    if (!info)
        return 0x25;
    ts4_memset(info, 0, 0x100);
    ts4_copy_bytes_until_nul_883296A0(info->name, r->name, 0xff);
    info->f48 = r->f48;
    info->parts = 0;
    if (r->handle && r->parts) {
        e = ts4_if_get_fn_8832BFC0_88316B30(r->handle, &n);
        if (e)
            return e;
        for (i = 0; i < n; i++)
            info->parts += r->parts[i];
    }
    c = 0;
    for (l = r->children.head.next; l != &r->children.head; l = l->next)
        c++;
    info->nchildren = c;
    info->f50 = r->f50;
    info->nflagged = 0;
    for (l = r->children.head.next; l != (&r->children ? &r->children.head : 0); l = l->next) {
        Child *ch = l ? (Child *)((char *)l - 4) : 0;
        if (ch->flag)
            info->nflagged++;
    }
    info->mode = (r->flags & 0x80) ? 0 : ((r->flags & 0x200) ? 1 : 2);
    info->child_size = 0;
    info->own_size = 0;
    if (r->handle) {
        e = ts4_if_get_fn_8832BFC0_88316F00(r->handle, any, any, &info->own_size, 0);
        if (e)
            return e;
    }
    for (l = r->children.head.next; l != (&r->children ? &r->children.head : 0); l = l->next) {
        Child *ch = l ? (Child *)((char *)l - 4) : 0;
        if (ch->handle) {
            e = ts4_if_get_fn_8832BFC0_88316F00(ch->handle, any, any, &n, 0);
            if (e)
                return e;
            info->child_size += n;
        }
    }
    return 0;
}
