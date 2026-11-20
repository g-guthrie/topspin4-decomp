/* 0x883ED740: writes the first item of the intrusive list at +0x18 (link at item+4) to *out, or 0 when the list is empty;
   0x25 for a null out. Matched plain /O1 (agT); keeps fn_ name (callee of 0x883EDB98). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct List { char pad[0x18]; Link head; } List;
static unsigned char list_empty(Link *h)
{
    return h->next == h && h->prev == h;
}
int fn_883ED740(List *l, void **out)
{
    Link *n;
    if (!out)
        return 0x25;
    *out = 0;
    if (!list_empty(&l->head)) {
        n = l->head.next;
        *out = n ? (char *)n - 4 : 0;
    }
    return 0;
}
