typedef struct RItem { char pad[0x18]; unsigned key18; char pad2[4]; unsigned key20; } RItem;
typedef struct { RItem **first; RItem **last; char pad[4]; } RItemVec;
typedef struct { char pad[0x64]; RItemVec primary; RItemVec secondary; } RItemLists;
static unsigned ritemvec_size(RItemVec *v) { return v->last - v->first; }
static RItem *ritemvec_at(RItemVec *v, unsigned i) { return v->first[i]; }

RItem *ritem_lists_find_by_key18_8876D2C0(RItemLists *m, unsigned key)
{
    RItem *r = 0;
    unsigned i, j, n;
    n = ritemvec_size(&m->primary);
    for (i = 0; i < n; i++) {
        RItem *it = ritemvec_at(&m->primary, i);
        if (it && key == it->key18) { r = it; goto done; }
    }
    n = ritemvec_size(&m->secondary);
    for (j = 0; j < n; j++) {
        RItem *it = ritemvec_at(&m->secondary, j);
        if (it && key == it->key18) { r = it; goto done; }
    }
done:
    return r;
}
