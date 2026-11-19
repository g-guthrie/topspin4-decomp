/* 0x882DD460: COM-style QueryInterface: clears *out, accepts the IIDs lbl_88007DCC and lbl_88007DAC (inline 16-byte memcmp) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); stores this and AddRefs (slot 1) on a hit, else returns E_NOINTERFACE (0x80004002). */
typedef struct Guid { unsigned char b[16]; } Guid;
extern const Guid lbl_88007DCC;
extern const Guid lbl_88007DAC;
int memcmp(const void *a, const void *b, unsigned n);
#pragma intrinsic(memcmp)
typedef struct U U;
typedef struct UVt { void *qi; unsigned (*addref)(U *u); } UVt;
struct U { UVt *vt; };
int ts4_query_interface_882DD460(U *u, const Guid *riid, void **out)
{
    *out = 0;
    if (memcmp(riid, &lbl_88007DCC, 16) == 0) {
        *out = u;
    } else if (memcmp(riid, &lbl_88007DAC, 16) == 0) {
        *out = u;
    } else {
        return 0x80004002;
    }
    u->vt->addref(u);
    return 0;
}
