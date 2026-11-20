/* 0x884FAFC0: looks up each id and calls slot 2 on it, stopping at a missing object or a failed HRESULT; E_INVALIDARG when nothing ran */
/* Matched on /O1 (agAH). /O1 (cr0 null test after the lookup). Sibling 884FB038 uses slot 3. */
typedef struct O O;
typedef struct OVt { void *f[2]; long (*start)(O *o); long (*stop)(O *o); } OVt;
struct O { OVt *vt; };
typedef struct Mgr Mgr;
extern O *fn_884FA750(Mgr *m, unsigned int id);
long fn_884FAFC0(Mgr *m, const unsigned int *ids, unsigned int count)
{
    long hr = 0x80070057;
    unsigned int i;
    for (i = 0; i < count; i++) {
        O *o = fn_884FA750(m, ids[i]);
        if (!o)
            break;
        hr = o->vt->start(o);
        if (hr < 0)
            break;
    }
    return hr;
}
