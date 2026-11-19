/* 0x883D4998: resolves "group/entry/key": finds the group by name, the entry inside it (883F8EC0), then the key via 883D7F20; returns the found value or 0. */
/* Near miss /O1 (agV): 3 off, base/index operand order of lbzx/stbx/add on rest[n] (target rest,n; ours n,rest); n[rest], helper, &path[i+1] tried. */
typedef struct Sys { char pad[0x809c]; void *ready; } Sys;
typedef struct Group Group;
typedef struct Entry Entry;
int ts4_strlen_88329658(const char *s);
Group *ts4_find_named_item_883D3B68(Sys *s, const char *name);
Entry *fn_883F8EC0(Group *g, const char *name);
int fn_883D7F20(Entry *e, const char *key, void **found, Entry **owner);

void *fn_883D4998(Sys *s, char *path)
{
    int len, i, n;
    char *rest;
    Group *g;
    Entry *e;
    void *found;
    if (!s->ready || !path)
        return 0;
    len = ts4_strlen_88329658(path);
    for (i = 0; i < len; i++)
        if (path[i] == '/')
            break;
    if (i >= len)
        return 0;
    path[i] = 0;
    rest = path + i + 1;
    for (n = ts4_strlen_88329658(rest) - 1; n > 0; n--)
        if (rest[n] == '/')
            break;
    if (n == 0)
        return 0;
    rest[n] = 0;
    g = ts4_find_named_item_883D3B68(s, path);
    if (!g)
        return 0;
    e = fn_883F8EC0(g, rest);
    if (!e)
        return 0;
    return fn_883D7F20(e, rest + n + 1, &found, 0) ? 0 : found;
}
