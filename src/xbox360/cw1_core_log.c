/* CW1: fixed-capacity log ring (Swing_DLL.xex 0x88151680). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void ts4_forward_varargs_88606270(char *dst, u32 size, const char *fmt, ...);

struct Cw1LogEntry {
    char text[0x100];
    u32 id;
    u32 arg_a;
    u32 arg_b;
    u8 used;
    u8 pad[3];
};

#pragma pack(push, 2)
struct Cw1LogIndex {
    u16 id;
    char *text;
};
#pragma pack(pop)

struct Cw1LogRing {
    u8 pad0[0x14];
    struct Cw1LogEntry entries[10];
    u32 count;
    struct Cw1LogIndex index[10];
};

/* Swing_DLL.xex 0x88151680: format a message into the next free slot and index it by id. */
void ts4_log_ring_add_88151680(struct Cw1LogRing *self, const char *fmt, u32 id, u32 arg_a, u32 arg_b)
{
    struct Cw1LogEntry *e;
    struct Cw1LogIndex *ix;

    if (self->count < 10 && id < 0x80) {
        e = &self->entries[self->count];
        ts4_forward_varargs_88606270(e->text, id, fmt);
        e->id = id;
        e->arg_a = arg_a;
        e->arg_b = arg_b;
        ix = &self->index[self->count];
        ix->text = e->text;
        ix->id = (u16)id;
        e->used = 1;
        self->count = self->count + 1;
    }
}
