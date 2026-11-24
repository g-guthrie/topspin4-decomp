/* 0x882886B8: allocates a 0x20-byte resource header and size bytes of physical memory (fn_88888668; protection 2 when flag 4, else 3), frees the header on failure (88884DE0), and fills common/refs/fence/address/size words */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
#ifdef _MSC_VER
#define WORD_PTR(w) ((Res *)(w))
#else
#define WORD_PTR(w) ((Res *)(unsigned long)(w))
#endif
typedef struct Res { unsigned int common; unsigned int refs; char pad[0xc]; unsigned int fence; unsigned int addr; unsigned int size; } Res;
unsigned int fn_88888668(unsigned int size, unsigned int attrs);
void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *p, unsigned int attrs);
Res *ts4_create_gpu_buffer_882886B8(unsigned int size, unsigned int flags)
{
    Res *r = WORD_PTR(fn_88888668(0x20, 0x64800000));
    unsigned int common;
    unsigned int prot;
    unsigned int mem;
    if (!r)
        return 0;
    common = 0x100001;
    prot = 3;
    if (flags & 4) {
        common = 0x300001;
        prot = 2;
    }
    if (flags & 0x200)
        common |= 0x400000;
    mem = fn_88888668(size, 0x82800000 | ((prot << 28) & 0x70000000));
    if (!mem) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(r, 0x24800000);
        return 0;
    }
    r->common = common;
    r->refs = 1;
    r->fence = 0xffff0000;
    r->addr = mem | 3;
    r->size = (size & 0x03fffffc) | (r->size & 0x08000000) | 0x10000002;
    return r;
}
