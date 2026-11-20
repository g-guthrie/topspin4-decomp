/* Loader_DLL.xex 0x8320F0C8-0x83215FD8, executable version 0.0.0.3.
 * Tagged list walkers: validate the owner's tag, then call a user callback for
 * every node until it returns non-zero. */
typedef unsigned (*Ts4lNodeFn)(int, int, void *);
typedef struct Ts4lListNode { struct Ts4lListNode *next; int aux; int value; } Ts4lListNode;
typedef struct { Ts4lListNode *first; int aux; } Ts4lListLink;
typedef struct { char pad[0x40]; int tag; } Ts4lListOwner;
typedef struct { char pad[0x10]; Ts4lListLink *head; char pad2[0x2c]; int tag; } Ts4lListOwnerH;


unsigned ts4l_list_walk_8320F0C8(Ts4lListOwner *owner, Ts4lListLink **head, int ctx, Ts4lNodeFn fn)
{
    Ts4lListLink link;
    unsigned r;

    if (owner == 0 || fn == 0 || owner->tag != 0x4c665175)
        return 0x57;
    link = **head;
    while (link.first) {
        r = fn(ctx, link.first->value, link.first);
        if (r != 0)
            return r;
        link = *(Ts4lListLink *)link.first;
    }
    return 0;
}

unsigned ts4l_list_walk_83213878(Ts4lListOwner *owner, Ts4lListLink **head, int ctx, Ts4lNodeFn fn)
{
    Ts4lListLink link;
    unsigned r;

    if (owner == 0 || fn == 0 || owner->tag != 0x4c465051)
        return 0x57;
    link = **head;
    while (link.first) {
        r = fn(ctx, link.first->value, link.first);
        if (r != 0)
            return r;
        link = *(Ts4lListLink *)link.first;
    }
    return 0;
}

unsigned ts4l_list_walk_83215F40(Ts4lListOwner *owner, Ts4lListLink **head, int ctx, Ts4lNodeFn fn)
{
    Ts4lListLink link;
    unsigned r;

    if (owner == 0 || fn == 0 || owner->tag != 0x4c464854)
        return 0x57;
    link = **head;
    while (link.first) {
        r = fn(ctx, link.first->value, link.first);
        if (r != 0)
            return r;
        link = *(Ts4lListLink *)link.first;
    }
    return 0;
}

unsigned ts4l_list_walk_owner_83210BB0(Ts4lListOwnerH *owner, int ctx, Ts4lNodeFn fn)
{
    Ts4lListLink link;
    unsigned r;

    if (owner == 0 || fn == 0 || owner->tag != 0x4c665175)
        return 0x57;
    link = *owner->head;
    while (link.first) {
        r = fn(ctx, link.first->value, link.first);
        if (r != 0)
            return r;
        link = *(Ts4lListLink *)link.first;
    }
    return 0;
}

unsigned ts4l_list_walk_owner_83215C20(Ts4lListOwnerH *owner, int ctx, Ts4lNodeFn fn)
{
    Ts4lListLink link;
    unsigned r;

    if (owner == 0 || fn == 0 || owner->tag != 0x4c465051)
        return 0x57;
    link = *owner->head;
    while (link.first) {
        r = fn(ctx, link.first->value, link.first);
        if (r != 0)
            return r;
        link = *(Ts4lListLink *)link.first;
    }
    return 0;
}
