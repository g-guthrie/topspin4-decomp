// Swing_DLL.xex 0x884EC070: Ts4LockedWriter::WriteItems(a): under the writer lock, writes the
// item count and then each item to the stream, clears the lock owner and leaves the section.
// Callers 884EC0E8 / 884EC238 / 884EC308 call it on (their this - 8), i.e. from a sub-object
// method on the full object. Matched /Oc as a C++ member: as a C function the item load comes
// out `lwzx r4,r30(offset),r11(items)` instead of the target's items-first order (`this` is
// numbered differently from a first parameter, regalloc.md C1).
struct Ts4WriterLock {
    char cs[0x20];  // +0x00 critical section
    long long owner; // +0x20
};
struct Ts4Stream;
struct Ts4ItemArray {
    void **items; // +0x0
    int count;    // +0x4
};
extern "C" {
void fn_88472530(Ts4WriterLock *l);
void ts4_stream_write_i32_a_88427418(Ts4Stream *s, int v);
void fn_884ED278(Ts4Stream *s, void *item);
void RtlLeaveCriticalSection(void *cs);
}
struct Ts4LockedWriter {
    char f_00[0xc];
    Ts4Stream *stream;   // +0x0C
    Ts4WriterLock *lock; // +0x10
    void WriteItems(Ts4ItemArray *a);
};

void Ts4LockedWriter::WriteItems(Ts4ItemArray *a)
{
    fn_88472530(lock);
    ts4_stream_write_i32_a_88427418(stream, a->count);
    for (int i = 0; i < a->count; i++)
        fn_884ED278(stream, a->items[i]);
    Ts4WriterLock *l = lock;
    l->owner = -1;
    RtlLeaveCriticalSection(l);
}
