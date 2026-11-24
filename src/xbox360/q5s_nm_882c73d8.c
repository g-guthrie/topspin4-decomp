/* 0x882C73D8 (Swing_DLL.xex, /O1): create a resource object from a shader/token stream.
 * *out is cleared first; null src/out -> D3DERR_INVALIDCALL (0x8876086C). A stream whose first token is not
 * a recognised version tag (0x102A11xx, 0xFFFExxxx, 0xFFFFxxxx) yields S_OK with *out = NULL. Otherwise a
 * 0x20-byte object is allocated (E_OUTOFMEMORY on failure), constructed and loaded; a failed load destroys
 * and frees it and returns the load error.
 * The early `S_OK` exit for an unrecognised tag is what schedules the shared tail's `li r3,0` before the
 * `*out` store (a single fall-through tail stores first). */
typedef struct Ts4Resource Ts4Resource;
void *fn_88888668(unsigned size, unsigned tag);
Ts4Resource *ts4_addr_lbl_88007D18_882E1C98(void *mem);
int ts4_resource_load_batc_882E21B8(Ts4Resource *r, const unsigned *src, int flags);
void fn_882E0E78(Ts4Resource *r);
void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *p, unsigned tag);

#define TS4_RES_HEAP_TAG 0x24810000u

int ts4_create_resource_882C73D8(const unsigned *src, Ts4Resource **out)
{
    Ts4Resource *res = 0;
    unsigned tag;
    void *mem;
    int hr;

    if (out)
        *out = 0;
    if (!src)
        return (int)0x8876086C;
    if (!out)
        return (int)0x8876086C;
    tag = *src;
    if (!((tag & 0xFFFFFF00) == 0x102A1100 || (tag & 0xFFFF0000) == 0xFFFE0000 ||
          (tag & 0xFFFF0000) == 0xFFFF0000)) {
        *out = res;
        return 0;
    }
    mem = fn_88888668(0x20, TS4_RES_HEAP_TAG);
    res = mem ? ts4_addr_lbl_88007D18_882E1C98(mem) : 0;
    if (!res)
        return (int)0x8007000E;
    hr = ts4_resource_load_batc_882E21B8(res, src, 0);
    if (hr < 0) {
        fn_882E0E78(res);
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(res, TS4_RES_HEAP_TAG);
        return hr;
    }
    *out = res;
    return 0;
}
