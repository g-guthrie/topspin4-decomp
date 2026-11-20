/* Loader_DLL.xex 0x83230250-0x832302B0, executable version 0.0.0.3. */
/* AddRef-and-return accessor for an interface pointer held in a field. */
struct Ts4lRef { virtual void v0(); virtual void AddRef(); };
struct Ts4lHolder2c { char pad[0x2c]; Ts4lRef *p; };
extern "C" int ts4l_get_ref_83230250(Ts4lHolder2c *o, Ts4lRef **out)
{
    if (o->p)
        o->p->AddRef();
    *out = o->p;
    return 0;
}

