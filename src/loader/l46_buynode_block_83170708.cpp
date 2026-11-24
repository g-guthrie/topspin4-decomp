/* Loader_DLL.xex 0x83170708-0x8317080C, executable version 0.0.0.3. */
#ifdef _MSC_VER
void __debugbreak(void);
#pragma intrinsic(__debugbreak)
#else
static void __debugbreak(void) {}
#endif
struct L46BNode { void *pad; L46BNode *next; void *pad2; };
struct L46BBlk { L46BBlk *chain; L46BNode nodes[16]; };
struct L46BPool {
    L46BNode *freelist;
    L46BBlk *chain;
    char pad[0xcc];
    unsigned long cap;
    unsigned long cnt;
};
extern "C" char lbl_83531690[];
extern "C" char lbl_830080FC[];
extern "C" void *fn_8316F128(void *, int, unsigned int, int);
extern "C" int ts4l_import_KeGetCurrentProcessType_835173B8(void);
extern "C" void ts4_call_seq_RtlInitAnsiString_8340F288(void *);

extern "C" L46BNode *ts4l_pool_get_block_83170708(L46BPool *s)
{
    int grow;
    int i;
    L46BBlk *b;
    L46BNode *r;
    L46BNode *nn;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 16 <= (unsigned long)-1) {
            b = (L46BBlk *)fn_8316F128(lbl_83531690, 0xc4, 0x20970000, 0);
            if (b != 0) {
                nn = b->nodes;
                for (i = 0; i < 16; i++) {
                    nn->next = s->freelist;
                    s->freelist = nn;
                    nn++;
                }
                b->chain = s->chain;
                s->cnt = s->cnt + 16;
                s->chain = b;
            }
        } else {
            ts4_call_seq_RtlInitAnsiString_8340F288(lbl_830080FC);
            __debugbreak();
        }
    }
    r = s->freelist;
    if (r != 0) {
        s->freelist = r->next;
    } else {
        r = 0;
    }
    return r;
}

extern "C" L46BNode *ts4l_pool_get_block_83173E20(L46BPool *s)
{
    int grow;
    int i;
    L46BBlk *b;
    L46BNode *r;
    L46BNode *nn;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 16 <= (unsigned long)-1) {
            b = (L46BBlk *)fn_8316F128(lbl_83531690, 0xc4, 0x20970000, 0);
            if (b != 0) {
                nn = b->nodes;
                for (i = 0; i < 16; i++) {
                    nn->next = s->freelist;
                    s->freelist = nn;
                    nn++;
                }
                b->chain = s->chain;
                s->cnt = s->cnt + 16;
                s->chain = b;
            }
        } else {
            ts4_call_seq_RtlInitAnsiString_8340F288(lbl_830080FC);
            __debugbreak();
        }
    }
    r = s->freelist;
    if (r != 0) {
        s->freelist = r->next;
    } else {
        r = 0;
    }
    return r;
}

extern "C" L46BNode *ts4l_pool_get_block_831760C8(L46BPool *s)
{
    int grow;
    int i;
    L46BBlk *b;
    L46BNode *r;
    L46BNode *nn;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 16 <= (unsigned long)-1) {
            b = (L46BBlk *)fn_8316F128(lbl_83531690, 0xc4, 0x20970000, 0);
            if (b != 0) {
                nn = b->nodes;
                for (i = 0; i < 16; i++) {
                    nn->next = s->freelist;
                    s->freelist = nn;
                    nn++;
                }
                b->chain = s->chain;
                s->cnt = s->cnt + 16;
                s->chain = b;
            }
        } else {
            ts4_call_seq_RtlInitAnsiString_8340F288(lbl_830080FC);
            __debugbreak();
        }
    }
    r = s->freelist;
    if (r != 0) {
        s->freelist = r->next;
    } else {
        r = 0;
    }
    return r;
}

extern "C" L46BNode *ts4l_pool_get_block_8317C168(L46BPool *s)
{
    int grow;
    int i;
    L46BBlk *b;
    L46BNode *r;
    L46BNode *nn;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 16 <= (unsigned long)-1) {
            b = (L46BBlk *)fn_8316F128(lbl_83531690, 0xc4, 0x20970000, 0);
            if (b != 0) {
                nn = b->nodes;
                for (i = 0; i < 16; i++) {
                    nn->next = s->freelist;
                    s->freelist = nn;
                    nn++;
                }
                b->chain = s->chain;
                s->cnt = s->cnt + 16;
                s->chain = b;
            }
        } else {
            ts4_call_seq_RtlInitAnsiString_8340F288(lbl_830080FC);
            __debugbreak();
        }
    }
    r = s->freelist;
    if (r != 0) {
        s->freelist = r->next;
    } else {
        r = 0;
    }
    return r;
}

struct L46CNode { void *pad; L46CNode *next; void *pad2; };
struct L46CBlk { L46CBlk *chain; L46CNode nodes[8]; };
struct L46CPool {
    L46CNode *freelist;
    L46CBlk *chain;
    char pad[0x6c];
    unsigned long cap;
    unsigned long cnt;
};

extern "C" L46CNode *ts4l_pool_get_block_8317C060(L46CPool *s)
{
    int grow;
    int i;
    L46CBlk *b;
    L46CNode *r;
    L46CNode *nn;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 8 <= (unsigned long)-1) {
            b = (L46CBlk *)fn_8316F128(lbl_83531690, 0x64, 0x20970000, 0);
            if (b != 0) {
                nn = b->nodes;
                for (i = 0; i < 8; i++) {
                    nn->next = s->freelist;
                    s->freelist = nn;
                    nn++;
                }
                b->chain = s->chain;
                s->cnt = s->cnt + 8;
                s->chain = b;
            }
        } else {
            ts4_call_seq_RtlInitAnsiString_8340F288(lbl_830080FC);
            __debugbreak();
        }
    }
    r = s->freelist;
    if (r != 0) {
        s->freelist = r->next;
    } else {
        r = 0;
    }
    return r;
}
