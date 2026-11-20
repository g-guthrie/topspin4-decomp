/* Loader_DLL.xex 0x8322EC68-0x8322ED54, executable version 0.0.0.3.
 * Fetch the current 60-byte element of an array, call its virtual slot 1, return the element. */
struct Ts4lElem { virtual void s0(); virtual void s1(); char pad[0x38]; };


struct Ts4lSet8322EC68 { char pad0[0x30]; Ts4lElem *items; char pad1[4]; int cur; };

extern "C" Ts4lElem *ts4l_current_element_8322EC68(Ts4lSet8322EC68 *s)
{
    Ts4lElem *e = &s->items[s->cur];
    e->s1();
    return e;
}

struct Ts4lSet8322ECB8 { char pad0[0x30]; Ts4lElem *items; char pad1[8]; int cur; };

extern "C" Ts4lElem *ts4l_current_element_8322ECB8(Ts4lSet8322ECB8 *s)
{
    Ts4lElem *e = &s->items[s->cur];
    e->s1();
    return e;
}

struct Ts4lSet8322ED08 { char pad0[0x30]; Ts4lElem *items; char pad1[12]; int cur; };

extern "C" Ts4lElem *ts4l_current_element_8322ED08(Ts4lSet8322ED08 *s)
{
    Ts4lElem *e = &s->items[s->cur];
    e->s1();
    return e;
}
