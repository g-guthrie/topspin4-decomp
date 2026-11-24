/* CW16 part b: game core, functions with divides (built with /Oc). */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Cw16Page { u8 pad[0x64]; u32 used; u8 pad2[0xfd8 - 0x68]; } Cw16Page;
typedef struct Cw16PagePool { u8 pad[0x50]; u32 count; Cw16Page *pages; u8 pad58[0x18]; u32 full; u32 per; u32 rem; } Cw16PagePool;

/* 0x88233820: record the page array and element count; every full page holds 39 entries, the last partial page the remainder */
void ts4_page_pool_init_88233820(Cw16PagePool *self, Cw16Page *pages, u32 count)
{
    self->count = count;
    self->pages = pages;
    self->full = 0;
    self->per = 0;
    self->rem = 0;
    if (count != 0) {
        u32 q = count / 39;
        u32 r = count % 39;
        u32 i;
        if (q != 0) for (i = 0; i < q; i++) pages[i].used = 39;
        if (r != 0) pages[q].used = r;
        self->full = q;
        self->rem = r;
        self->per = 39;
    }
}
