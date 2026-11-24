/* Loader_DLL.xex 0x83400BA0-0x83400C00, executable version 0.0.0.3. */
/* Lazily compute and cache the sum of two child objects' sizes (negative means not yet computed). */
struct Ts4lSized { virtual int GetSize(); };
struct Ts4lCombined { int pad; Ts4lSized *a; Ts4lSized *b; int total; };
extern "C" int ts4l_cached_total_83400BA0(Ts4lCombined *s)
{
    if (s->total < 0) {
        s->total = s->b->GetSize() + s->a->GetSize();
    }
    return s->total;
}
