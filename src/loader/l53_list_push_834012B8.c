/* Loader_DLL.xex 0x834012B8-0x83401360, executable version 0.0.0.3. */
typedef struct Ts4lRec {
    void *a;
    int b;
} Ts4lRec;
typedef struct Ts4lList {
    int count;
    Ts4lRec *items[8];
} Ts4lList;
extern char lbl_835446B8[];
extern Ts4lRec *fn_834005F8(void *pool, int size, int flags);
#ifdef _MSC_VER
__forceinline
#endif
static Ts4lRec *ts4l_dup_rec(Ts4lRec *src)
{
    Ts4lRec *n = fn_834005F8(lbl_835446B8, 8, 0);
    if (n != 0) { n->a = src->a; n->b = src->b; return n; }
    return 0;
}
Ts4lList *ts4l_list_push_834012B8(Ts4lList *l, Ts4lRec *src)
{
    if (l->count != 9 && src->a != 0) {
        Ts4lRec *c = ts4l_dup_rec(src);
        if (c != 0) {
            l->count++;
            l->items[l->count] = c;
        }
    }
    return l;
}
