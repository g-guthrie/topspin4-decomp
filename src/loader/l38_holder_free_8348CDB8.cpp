/* Loader_DLL.xex 0x8348CDB8-0x8348CE38, executable version 0.0.0.3. */
typedef unsigned long u32;
struct Ts4lEvt { u32 p0; u32 p4; u32 p8; u32 pc; unsigned char signaled; u32 handle; };
struct Ts4lIf { virtual void v0(); virtual void Release(u32 flags); };
struct Ts4lHolder { Ts4lEvt *evt; };
extern "C" void ts4_if_call_seq_NtSetEvent_8340AED8(u32 h);
extern "C" void fn_83488ED8(Ts4lEvt *e);
extern "C" void ts4l_holder_free_8348CDB8(Ts4lHolder *h)
{
    Ts4lEvt *e = h->evt;
    if (e) {
        if (e->signaled == 0) {
            e->signaled = 1;
            ts4_if_call_seq_NtSetEvent_8340AED8(e->handle);
        }
        fn_83488ED8(h->evt);
        if (h->evt) ((Ts4lIf *)h->evt)->Release(1);
        h->evt = 0;
    }
}
