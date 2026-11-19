/* 0x888B0FF8: constructor. Runs the base constructor fn_888AF5C0, sets the vtable, clears the
   state block at +0x80..+0xa4 (floats to the shared zero) and sets the type hash 0x85F95371 at +0xa8. */
typedef unsigned int u32;
typedef struct HashObj { const void *vt; char pad[0x7c]; u32 f80, f84, f88, f8c, f90, f94;
    float f98, f9c; unsigned char fa0; float fa4; u32 hash; } HashObj;
extern char *fn_888AF5C0(char *self);
extern const char lbl_880DC780[];
extern float g_ts4_event_value;
HashObj *ts4_hash_obj_ctor_888B0FF8(HashObj *o)
{
    fn_888AF5C0((char *)o);
    o->vt = lbl_880DC780;
    o->f80 = 0; o->f84 = 0; o->f88 = 0; o->f8c = 0; o->f94 = 0;
    o->f98 = g_ts4_event_value; o->f9c = g_ts4_event_value; o->fa0 = 0; o->fa4 = g_ts4_event_value;
    { u32 *h = &o->hash; *h = 0; o->hash = 0x85F95371; }
    return o;
}
