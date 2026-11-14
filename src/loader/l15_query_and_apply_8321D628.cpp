/* Loader_DLL.xex 0x8321D628-0x8321D9C8, executable version 0.0.0.3.
 * COM-style helper: fetch a child interface from the object, look up a second
 * interface on it, pass that to a worker, then release both references. */
struct Ts4lRefC { virtual void a0(); virtual void a1(); virtual unsigned long Release(); };
struct Ts4lRefB {
    virtual void b0();
    virtual void b1();
    virtual unsigned long Release();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual int Lookup(int, Ts4lRefC **, int);
};
struct Ts4lHost {
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual void h7();
    virtual void h8();
    virtual void h9();
    virtual void h10();
    virtual void h11();
    virtual void h12();
    virtual void h13();
    virtual void h14();
    virtual void h15();
    virtual void h16();
    virtual void h17();
    virtual void h18();
    virtual void h19();
    virtual void h20();
    virtual void h21();
    virtual void h22();
    virtual void h23();
    virtual void h24();
    virtual void h25();
    virtual void h26();
    virtual void h27();
    virtual void h28();
    virtual int GetChild(Ts4lRefB **);
};

extern "C" {
int fn_8321FA78(Ts4lRefC *, int);
int fn_8321ED40(Ts4lRefC *, int);
int fn_8321FC30(Ts4lRefC *, int);
int fn_8321ED80(Ts4lRefC *, int);

int ts4l_query_and_apply_8321D628(Ts4lHost *self, int arg)
{
    Ts4lRefB *b = 0;
    Ts4lRefC *c = 0;
    int hr = self->GetChild(&b);
    if (hr >= 0) {
        if (b)
            hr = b->Lookup(0, &c, 0);
        if (hr >= 0 && c)
            hr = fn_8321FA78(c, arg);
    }
    if (b) {
        b->Release();
        b = 0;
    }
    if (c)
        c->Release();
    return hr;
}

int ts4l_query_and_apply_8321D710(Ts4lHost *self, int arg)
{
    Ts4lRefB *b = 0;
    Ts4lRefC *c = 0;
    int hr = self->GetChild(&b);
    if (hr >= 0) {
        if (b)
            hr = b->Lookup(0, &c, 0);
        if (hr >= 0 && c)
            hr = fn_8321ED40(c, arg);
    }
    if (b) {
        b->Release();
        b = 0;
    }
    if (c)
        c->Release();
    return hr;
}

int ts4l_query_and_apply_8321D7F8(Ts4lHost *self, int arg)
{
    Ts4lRefB *b = 0;
    Ts4lRefC *c = 0;
    int hr = self->GetChild(&b);
    if (hr >= 0) {
        if (b)
            hr = b->Lookup(0, &c, 0);
        if (hr >= 0 && c)
            hr = fn_8321FC30(c, arg);
    }
    if (b) {
        b->Release();
        b = 0;
    }
    if (c)
        c->Release();
    return hr;
}

int ts4l_query_and_apply_8321D8E0(Ts4lHost *self, int arg)
{
    Ts4lRefB *b = 0;
    Ts4lRefC *c = 0;
    int hr = self->GetChild(&b);
    if (hr >= 0) {
        if (b)
            hr = b->Lookup(0, &c, 0);
        if (hr >= 0 && c)
            hr = fn_8321ED80(c, arg);
    }
    if (b) {
        b->Release();
        b = 0;
    }
    if (c)
        c->Release();
    return hr;
}

}
