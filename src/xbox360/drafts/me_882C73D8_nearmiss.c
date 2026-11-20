/* 0x882C73D8 near miss (agAC, /O1 plain and LTCG): 2 off, the final `li r3,0` is scheduled after `stw res,0(out)` here and before it in the target. */
typedef struct Res Res;
void *fn_88888668(unsigned size, unsigned tag);
Res *ts4_addr_lbl_88007D18_882E1C98(void *mem);
int ts4_resource_load_batc_882E21B8(Res *r, const unsigned *src, int flags);
void fn_882E0E78(Res *r);
void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *p, unsigned tag);
int ts4_create_resource_882C73D8(const unsigned *src, Res **out)
{
    Res *res = 0;
    unsigned tag;
    void *mem;
    int r;
    if (out) *out = 0;
    if (!src) return (int)0x8876086C;
    if (!out) return (int)0x8876086C;
    tag = *src;
    if ((tag & 0xFFFFFF00) == 0x102A1100 || (tag & 0xFFFF0000) == 0xFFFE0000 || (tag & 0xFFFF0000) == 0xFFFF0000) {
        mem = fn_88888668(0x20, 0x24810000);
        res = mem ? ts4_addr_lbl_88007D18_882E1C98(mem) : 0;
        if (!res) return (int)0x8007000E;
        r = ts4_resource_load_batc_882E21B8(res, src, 0);
        if (r < 0) {
            fn_882E0E78(res);
            ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(res, 0x24810000);
            return r;
        }
    }
    r = 0;
    *out = res;
    return r;
}
