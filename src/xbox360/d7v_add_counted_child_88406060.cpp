/* Swing_DLL.xex 0x88406060-0x884060F0, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ts4V9Counted {
    virtual void *destroy(int flags);
    unsigned short live;
    short refs;
};
struct Ts4V9Vec {
    Ts4V9Counted **data;
    int count;
    u32 cap;
};
struct Ts4V9Owner { char pad0[8]; char sub[8]; Ts4V9Vec vec; };
extern "C" {
void fn_8841C678(Ts4V9Vec *vec, int n);
void fn_88408B78(Ts4V9Counted *item, void *sub);

void ts4_add_counted_child_88406060(Ts4V9Owner *o, Ts4V9Counted *item)
{
    Ts4V9Vec *v = &o->vec;
    if (v->count == (int)(v->cap & 0x3FFFFFFF))
        fn_8841C678(v, 4);
    v->data[v->count] = item;
    v->count = v->count + 1;
    if (item->live != 0)
        item->refs = item->refs + 1;
    fn_88408B78(item, o != 0 ? (void *)o->sub : (void *)0);
}
}
