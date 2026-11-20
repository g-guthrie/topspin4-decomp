/* 0x88995358: Returns whether the pointer list [+0x10, +0x14) holds a member whose 64-bit id (+0x50) equals the probe id (+0x70); 0 for a null probe. */
/* Matched on /Oc (agAH). Find helper with the end pointer read into a local first; result as int result = 0; if (p) result = 0 != find(...) (constant on the left keeps the addi r11,r10,0 copy). */
typedef struct Member { char pad[0x50]; unsigned __int64 id; } Member;
typedef struct Probe { char pad[0x70]; unsigned __int64 id; } Probe;
typedef struct Roster { char pad[0x10]; Member **begin; Member **end; } Roster;

static Member *Roster_Find(Roster *r, unsigned __int64 id)
{
    Member **end = r->end;
    Member **it;
    for (it = r->begin; it != end; it++) {
        if ((*it)->id == id)
            return *it;
    }
    return 0;
}

int fn_88995358(Roster *r, Probe *p)
{
    int result = 0;
    if (p != 0)
        result = 0 != Roster_Find(r, p->id);
    return result;
}
