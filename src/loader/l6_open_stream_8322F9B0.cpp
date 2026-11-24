/* Loader_DLL.xex 0x8322F9B0-0x8322FD2C, executable version 0.0.0.3. */
struct ts4l_obj {
    virtual void v0();
    virtual void v1();
    virtual void release();
    virtual void add_ref();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual int v21(int a);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual int v31(int a, int *out);
};

struct ts4l_src {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(void **a, void **b, int c);
    virtual int v16(void **a, void **b, int c);
    virtual void v17(void **a, void **b, int c);
};

struct ts4l_owner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    unsigned char pad04[0x2c - 4];
    ts4l_src *source;
};

extern "C" {
void fn_8322EE70(ts4l_obj *p);
void fn_83224AA8(ts4l_src *s, int v);
}

extern "C" int ts4l_open_stream_8322F9B0(ts4l_owner *self, int arg, int *out)
{
    ts4l_obj *p1;
    ts4l_obj *p2;
    ts4l_obj *p3;
    ts4l_obj *p4;
    ts4l_obj *p5;
    ts4l_obj *p6;
    int value;
    int hr;

    value = 0;
    p6 = 0;
    p5 = 0;
    p1 = 0;
    p3 = 0;
    p4 = 0;
    p2 = 0;
    self->v3();
    self->source->v17((void **)&p6, (void **)&p5, 0);
    self->source->v15((void **)&p1, (void **)&p3, 0);
    hr = self->source->v16((void **)&p4, (void **)&p2, 0);
    if (p1 != 0)
        p1->add_ref();
    if (p3 != 0)
        p3->add_ref();
    if (p4 != 0)
        p4->add_ref();
    if (p2 != 0)
        p2->add_ref();
    if (p3 != 0) {
        hr = p3->v31(arg, &value);
        arg = value;
    }
    if (hr >= 0) {
        if (p1 != 0)
            hr = p1->v31(arg, &value);
        if (hr >= 0) {
            if (p5 != 0) {
                hr = p2->v21(4);
                fn_8322EE70(p5);
            }
            if (hr >= 0)
                fn_83224AA8(self->source, value);
        }
    }
    self->v50();
    self->v49();
    if (p2 != 0)
        p2->v5();
    if (p4 != 0)
        p4->v5();
    if (p3 != 0)
        p3->v5();
    if (p1 != 0)
        p1->v5();
    self->v5();
    if (out != 0)
        *out = value;
    if (p4 != 0) {
        p4->release();
        p4 = 0;
    }
    if (p2 != 0) {
        p2->release();
        p2 = 0;
    }
    if (p1 != 0) {
        p1->release();
        p1 = 0;
    }
    if (p3 != 0) {
        p3->release();
        p3 = 0;
    }
    if (p6 != 0) {
        p6->release();
        p6 = 0;
    }
    if (p5 != 0)
        p5->release();
    return hr;
}
