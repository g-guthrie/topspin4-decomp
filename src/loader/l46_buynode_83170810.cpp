/* Loader_DLL.xex 0x83170810-0x83170904 and 10 identical copies, executable version 0.0.0.3. */
#ifdef _MSC_VER
void __debugbreak(void);
#pragma intrinsic(__debugbreak)
#else
static void __debugbreak(void) {}
#endif
struct L46Node { void *pad; L46Node *next; };
struct L46Blk { L46Blk *chain; L46Node node; int pad[1]; };
struct L46Pool {
    L46Node *freelist;
    L46Blk *chain;
    char pad[0x18];
    unsigned long cap;
    unsigned long cnt;
};
extern "C" char lbl_83531690[];
extern "C" char lbl_830080FC[];
extern "C" void *fn_8316F128(void *, int, unsigned int, int);
extern "C" int ts4l_import_KeGetCurrentProcessType_835173B8(void);
extern "C" void ts4_call_seq_RtlInitAnsiString_8340F288(void *);

extern "C" L46Node *ts4l_pool_get_node_83170810(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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

extern "C" L46Node *ts4l_pool_get_node_83170908(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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

extern "C" L46Node *ts4l_pool_get_node_83170A00(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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

extern "C" L46Node *ts4l_pool_get_node_83170AF8(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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

extern "C" L46Node *ts4l_pool_get_node_83170BF0(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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

extern "C" L46Node *ts4l_pool_get_node_83173F28(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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

extern "C" L46Node *ts4l_pool_get_node_831797A8(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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

extern "C" L46Node *ts4l_pool_get_node_8317BE28(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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

extern "C" L46Node *ts4l_pool_get_node_831886B8(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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

extern "C" L46Node *ts4l_pool_get_node_83189D80(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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

extern "C" L46Node *ts4l_pool_get_node_8318A010(L46Pool *s)
{
    int grow;
    L46Blk *b;
    L46Node *r;
    L46Node *nn;
    L46Blk *ch;
    grow = 0;
    if (s->cnt < s->cap) {
        if (ts4l_import_KeGetCurrentProcessType_835173B8() != 2) {
            grow = 1;
        }
    }
    if (s->freelist == 0 || grow != 0) {
        if (s->cnt + 1 <= (unsigned long)-1) {
            b = (L46Blk *)fn_8316F128(lbl_83531690, 0x10, 0x20970000, 0);
            if (b != 0) {
                nn = &b->node;
                nn->next = s->freelist;
                ch = s->chain;
                s->freelist = nn;
                b->chain = ch;
                s->cnt = s->cnt + 1;
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
