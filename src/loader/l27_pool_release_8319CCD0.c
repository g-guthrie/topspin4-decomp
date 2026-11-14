/* Loader_DLL.xex 0x8319CCD0-0x8320C103, executable version 0.0.0.3.
 * Slab-pool block release: toggle the slot bit under the pool lock and
 * subtract the payload size from the global statistics. */
typedef struct { char *base; unsigned size; unsigned mask; } Hdr;
extern char lbl_83531690[];
extern void RtlEnterCriticalSection(void *);
extern void RtlLeaveCriticalSection(void *);

void ts4l_pool_release_8319CCD0(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_8319D868(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_8319F538(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_8319FD00(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_831A0A58(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_831A1198(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_831A1B40(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_831A2020(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_831BAF50(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_831F2E18(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_831F3568(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_831F3B08(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_831F45E8(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}

void ts4l_pool_release_8320C070(unsigned *p)
{
    unsigned off = p[-1];
    unsigned tag = p[-2];
    char *base = (char *)p - off;
    char *hp = base - 8;
    unsigned psz = (*(Hdr **)hp)->size - 8;
    Hdr *h;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    h = *(Hdr **)(base - 8);
    h->mask ^= 1u << ((unsigned)(hp - h->base) / h->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    *(unsigned *)(lbl_83531690 + 0x10) -= psz;
    *(unsigned *)(lbl_83531690 + 0x14 + (tag & 0x1fff) * 4) -= psz;
}
