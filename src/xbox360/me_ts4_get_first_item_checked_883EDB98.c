/* 0x883EDB98: 0x25 for a null out; otherwise fetches the first list item through fn_883ED740 and stores it on success.
   LTCG only (agT): out kept in r9 across the call; needs /Ob1 (r8 without it); context is the matched callee. */
typedef struct List List;
int fn_883ED740(List *l, void **out);
int ts4_get_first_item_checked_883EDB98(List *l, void **out)
{
    void *item;
    int r;
    if (!out)
        return 0x25;
    r = fn_883ED740(l, &item);
    if (r)
        return r;
    *out = item;
    return r;
}
