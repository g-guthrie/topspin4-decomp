/* Swing_DLL.xex 0x883DD5E8: FMOD sound-bank unload of a list of entries (file string lbl_88039468 is
 * "..\src\fmod_soundbank.cpp", line 0x47b). Unless flag 0x400 is set or the bank has no stream: detaches
 * (fn_883DD108), then for each listed id whose used slot is 0 looks the sample up through the stream's source,
 * clears its owner, removes and releases it; when no slot is used anymore, closes the stream and frees the used
 * table. Returns 0x21 when ids is given without a table or the source cannot be fetched.
 * Built /O1. The virtual-member form gives the vtable-before-*ids load order of the remove call. */

struct Ts4FmodHeapMgr { int p0; void *heap; };
extern "C" Ts4FmodHeapMgr *lbl_88B3302C;
extern "C" char lbl_88039468[]; /* "..\\src\\fmod_soundbank.cpp" */

struct Ts4FmodSample {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual int release(int free_now);
    char pad[0x44 - 4];
    int owner;
};
struct Ts4FmodSource {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int remove(int id, int flags);
    virtual int find(int id, Ts4FmodSample **out);
};
struct Ts4FmodSoundBank {
    char pad0[0x18];
    unsigned int flags;
    char pad1[0x28 - 0x1c];
    void *stream;
    char pad2[0x4c - 0x2c];
    int *used;
};

extern "C" void fn_88315F10(void *heap, void *buf, const char *file, int line);
extern "C" void fn_883DD108(Ts4FmodSoundBank **bank, int a);
extern "C" int ts4_if_set_u32_off0_8832BFC0(void *stream, Ts4FmodSource **out);
extern "C" int ts4_if_get_fn_8832BFC0_88316B30(void *stream, int *out);
extern "C" int ts4_if_get_fn_8832BFC0_88317EC0(void *stream);

extern "C" int ts4_fmod_soundbank_unload_entries_883DD5E8(Ts4FmodSoundBank *t, int *ids, int n)
{
    int i, r, cnt;
    Ts4FmodSource *src;
    if (t->flags & 0x400)
        return 0;
    if (!t->stream)
        return 0;
    {
        Ts4FmodSoundBank *self = t;
        fn_883DD108(&self, 1);
    }
    if (ids) {
        if (!t->used)
            return 0x21;
        for (i = 0; i < n; i++, ids++) {
            if (t->used[*ids] == 0) {
                Ts4FmodSample *it;
                if (ts4_if_set_u32_off0_8832BFC0(t->stream, &src))
                    return 0x21;
                r = src->find(*ids, &it);
                if (r)
                    return r;
                if (it) {
                    it->owner = 0;
                    r = src->remove(*ids, 0);
                    if (r)
                        return r;
                    r = it->release(1);
                    if (r)
                        return r;
                }
            }
        }
    }
    r = ts4_if_get_fn_8832BFC0_88316B30(t->stream, &cnt);
    if (r)
        return r;
    i = 0;
    if (cnt > 0) {
        int *p = t->used;
        for (; i < cnt; i++, p++)
            if (*p)
                break;
    }
    if (i == cnt) {
        void *s = t->stream;
        t->stream = 0;
        r = ts4_if_get_fn_8832BFC0_88317EC0(s);
        if (r)
            return r;
        if (t->used)
            fn_88315F10(lbl_88B3302C->heap, t->used, lbl_88039468, 0x47b);
        t->used = 0;
    }
    return 0;
}
