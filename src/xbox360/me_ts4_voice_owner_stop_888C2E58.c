/* Swing_DLL.xex 0x888C2E58: Swing_DLL.xex 0x888C2E58: Detaches and deletes every object in the vector at +0x268 and empties it; if a voice is active, releases its channel descriptor from the global mixer (lbl_88D4592C->+0x2C, vtable +0x24), stops and deletes the voice; closes the channel at +0x8 and clears the voice state.
 * /Oc. Mixer pointer read before the descriptor call, its vtable after: separate desc local. */
typedef struct Obj Obj;
typedef struct ObjVtbl {
    void (*destroy)(Obj *self, int flags);   /* 0x00 */
    void *slots[2];
    void (*detach)(Obj *self);               /* 0x0c */
    void *slot10;
    void (*stop)(Obj *self);                 /* 0x14 */
} ObjVtbl;
struct Obj { const ObjVtbl *vt; };
typedef struct ObjVec { Obj **first; Obj **last; Obj **end; } ObjVec;
typedef struct Channel Channel;
typedef struct ChannelVtbl {
    void *slots[5];
    void (*close)(Channel *self);                    /* 0x14 */
    void *slots18[(0x4c - 0x18) / 4];
    char *(*get_desc)(Channel *self, int index);     /* 0x4c */
} ChannelVtbl;
struct Channel { const ChannelVtbl *vt; };
typedef struct Mixer Mixer;
typedef struct MixerVtbl { void *slots[0x24 / 4]; void (*release)(Mixer *self, void *desc, int flag); /* 0x24 */ } MixerVtbl;
struct Mixer { const MixerVtbl *vt; };
typedef struct Audio { char pad[0x2c]; Mixer *mixer; } Audio;
typedef struct Owner {
    char pad[8];
    Channel channel;        /* 0x08 */
    char padc[0x5c - 0xc];
    Obj *voice;             /* 0x5c */
    int voice_id;           /* 0x60 */
    unsigned char playing;  /* 0x64 */
    char pad65[0x268 - 0x65];
    ObjVec objs;            /* 0x268 */
} Owner;
extern Audio *lbl_88D4592C;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
static __forceinline Obj **copy_ptrs(Obj **first, Obj **last, Obj **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Obj **)fn_88562DC0(dest, first, n);
        return (Obj **)((char *)dest + n);
    }
}
void fn_888C2E58(Owner *o)
{
    ObjVec *v = &o->objs;
    Obj **it, **end = o->objs.last;
    for (it = v->first; end != it; it++) {
        (*it)->vt->detach(*it);
        if (*it)
            (*it)->vt->destroy(*it, 1);
    }
    v->last = copy_ptrs(v->last, v->last, v->first);
    if (o->voice) {
        Mixer *m = lbl_88D4592C->mixer;
        char *desc = o->channel.vt->get_desc(&o->channel, 0);
        m->vt->release(m, desc + 0xc, 1);
        o->voice->vt->stop(o->voice);
        if (o->voice)
            o->voice->vt->destroy(o->voice, 1);
    }
    o->channel.vt->close(&o->channel);
    o->voice = 0;
    o->voice_id = 0;
    o->playing = 0;
}
