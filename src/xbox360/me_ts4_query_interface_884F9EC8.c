/* 0x884F9EC8: COM-style QueryInterface accepting the IIDs lbl_8808D810 and lbl_8808D800 (inline 16-byte memcmp) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); stores this and AddRefs (slot 1) on a hit, else clears *out and returns E_NOINTERFACE; result kept in one local. */
typedef struct Guid { unsigned char b[16]; } Guid;
extern const Guid lbl_8808D810;
extern const Guid lbl_8808D800;
int memcmp(const void *a, const void *b, unsigned n);
#pragma intrinsic(memcmp)
typedef struct U U;
typedef struct UVt { void *qi; unsigned (*addref)(U *u); } UVt;
struct U { UVt *vt; };
int ts4_query_interface_884F9EC8(U *u, const Guid *riid, void **out)
{
    int hr = 0;
    if (memcmp(riid, &lbl_8808D810, 16) == 0) {
        *out = u;
        u->vt->addref(u);
    } else if (memcmp(riid, &lbl_8808D800, 16) == 0) {
        *out = u;
        u->vt->addref(u);
    } else {
        hr = 0x80004002;
        *out = 0;
    }
    return hr;
}
