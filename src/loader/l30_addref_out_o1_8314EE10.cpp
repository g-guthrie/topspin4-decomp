/* Loader_DLL.xex 0x8314EE10-0x8314F1F0, executable version 0.0.0.3. */
struct ts4l_R { virtual void m0(); };
struct ts4l_S { char pad[0x14]; ts4l_R *p; };

extern "C" int ts4l_addref_out_o1_8314EE10(ts4l_S *s, ts4l_R **out)
{
    *out = s->p;
    if (s->p != 0) {
        s->p->m0();
    }
    return 0;
}

extern "C" int ts4l_addref_out_o1_8314F000(ts4l_S *s, ts4l_R **out)
{
    *out = s->p;
    if (s->p != 0) {
        s->p->m0();
    }
    return 0;
}

extern "C" int ts4l_addref_out_o1_8314F1F0(ts4l_S *s, ts4l_R **out)
{
    *out = s->p;
    if (s->p != 0) {
        s->p->m0();
    }
    return 0;
}
