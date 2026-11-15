/* CW11 LTCG route (C++), context: src/xbox360/cw1_ctx_format_text.c (varargs shape of ts4_format_text). Built with /Oc.
   0x8860D750: dump the node list under the owner's lock through the sink's write slot. Node flags are an MSB-first bitfield (30-bit size, skip, flag). */
typedef unsigned int u32;
typedef unsigned char u8;
extern "C" void RtlEnterCriticalSection(void *cs);
extern "C" void RtlLeaveCriticalSection(void *cs);
extern "C" int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern "C" void *ts4_memset(void *, int, u32);
extern "C" const char lbl_880F7128[];
extern "C" const char lbl_880F7130[];
extern "C" const char lbl_880F7184[];
extern "C" const char lbl_880F71C4[];
extern "C" const char lbl_880F71E4[];
struct Cx11Lock {
    u32 w0; u8 cs[0x1c];
    void enter() { RtlEnterCriticalSection(cs); }
    void leave() { RtlLeaveCriticalSection(cs); }
};
struct Cx11Sink { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void write(const char *s, int n); };
struct Cx11DNode { Cx11DNode *next; u32 w4; u32 size : 30; u32 skip : 1; u32 a : 1; };
struct Cx11DHead { Cx11DNode *first; };
struct Cx11Dump { u8 pad[0x44]; Cx11Lock lock; u8 pad2[0x180 - 0x44 - sizeof(Cx11Lock)]; Cx11DHead *head; };
extern "C" void ts4_dump_nodes_8860D750(Cx11Dump *o, Cx11Sink *log)
{
    char buf[0x400];
    Cx11Lock *l = &o->lock;
    int n;
    u32 i;
    Cx11DNode *node;
    l->enter();
    ts4_memset(buf, 0, 0x400);
    n = ts4_format_text(buf, 0x400, lbl_880F7130, lbl_880F7128);
    log->write(buf, n - 1);
    i = 0;
    node = o->head->first;
    while (node != 0) {
        if (!(u8)node->skip) {
            u32 sz = node->size;
            n = ts4_format_text(buf, 0x400, lbl_880F7184, i, node, sz);
            log->write(buf, n - 1);
            n = ts4_format_text(buf, 0x400, lbl_880F71C4);
            log->write(buf, n - 1);
            i++;
        }
        node = node->next;
    }
    n = ts4_format_text(buf, 0x400, lbl_880F71E4);
    log->write(buf, n - 1);
    l->leave();
}

/* 0x8860C6A0: dump the arena's circular block chain (sentinel at 0x178, first block at 0x180) under the lock */
struct Cx11DBlock { u8 pad[8]; Cx11DBlock *next; u32 fc; u32 f10; u32 f14; };
struct Cx11DArena { u8 pad[0x44]; Cx11Lock lock; u8 pad2[0x178 - 0x44 - sizeof(Cx11Lock)]; u8 sentinel[8]; Cx11DBlock *first; };
extern "C" void ts4_dump_chain_8860C6A0(Cx11DArena *o, Cx11Sink *log)
{
    char buf[0x400];
    Cx11Lock *l = &o->lock;
    int n;
    Cx11DBlock *node;
    Cx11DBlock *end;
    l->enter();
    n = ts4_format_text(buf, 0x400, lbl_880F7130, lbl_880F7128);
    log->write(buf, n - 1);
    end = (Cx11DBlock *)o->sentinel;
    for (node = o->first; end != node; node = node->next) {
        n = ts4_format_text(buf, 0x400, lbl_880F7184, node->f14, node->f10, node->fc);
        log->write(buf, n - 1);
        n = ts4_format_text(buf, 0x400, lbl_880F71C4);
        log->write(buf, n - 1);
    }
    n = ts4_format_text(buf, 0x400, lbl_880F71E4);
    log->write(buf, n - 1);
    l->leave();
}
