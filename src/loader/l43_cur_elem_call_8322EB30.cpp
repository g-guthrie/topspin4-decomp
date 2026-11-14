/* Loader_DLL.xex 0x8322EB30-0x8322EBF0, executable version 0.0.0.3. */
struct Ts4lElem {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void s17(); virtual void v18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    char pad[0x3c - 4];
};
struct Ts4lSet {
    char pad0[0x30];
    Ts4lElem *elems;
    char pad1[0x40 - 0x34];
    int cur;
};
extern "C" void ts4l_cur_elem_call_8322EB30(Ts4lSet *s) { s->elems[s->cur].s17(); }
extern "C" void ts4l_cur_elem_call_8322EB70(Ts4lSet *s) { s->elems[s->cur].s19(); }
extern "C" void ts4l_cur_elem_call_8322EB90(Ts4lSet *s) { s->elems[s->cur].s20(); }
extern "C" void ts4l_cur_elem_call_8322EBB0(Ts4lSet *s) { s->elems[s->cur].s21(); }
extern "C" void ts4l_cur_elem_call_8322EBD0(Ts4lSet *s) { s->elems[s->cur].s22(); }
extern "C" void ts4l_cur_elem_call_8322EBF0(Ts4lSet *s) { s->elems[s->cur].s23(); }
