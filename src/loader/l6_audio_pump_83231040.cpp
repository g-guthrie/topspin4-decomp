/* Loader_DLL.xex 0x83231040-0x83231348, executable version 0.0.0.3. */
typedef unsigned long ts4l_uptr;

struct ts4l_item {
    virtual void v0();
    virtual void v1();
    virtual void release();
};

struct ts4l_buffer {
    virtual void v0();
    virtual void v1();
    virtual void release();
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
    virtual void v18(void *view);
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
    virtual int v30(void *target, void **out);
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34(unsigned a, unsigned b);
};

struct ts4l_view {
    virtual void v0();
    virtual void v1();
    virtual void release();
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
    virtual void v14(int a);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual int v21();
};

struct ts4l_source {
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
    virtual void v15(int a, void **out, int b);
    virtual void v16();
    virtual void v17(int a, void **out, int b);
    virtual void v18(unsigned *a, unsigned *b);
};

struct ts4l_worker {
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
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual int v65();
    unsigned char pad04[0x2c - 4];
    ts4l_source *source;
    unsigned char pad30[0xf8 - 0x30];
    unsigned limit_f8;
    unsigned char pad_fc[0x10c - 0xfc];
    void *event10c;
};

extern "C" {
unsigned fn_8322EC18(ts4l_item *p);
ts4l_view *fn_8322ECB8(ts4l_item *p);
void fn_8322EE08(ts4l_item *p);
void fn_8340CA48(void *h);
}

extern "C" void ts4l_audio_pump_83231040(ts4l_worker *self)
{
    ts4l_buffer *buf;
    ts4l_item *item;
    ts4l_view *view;
    void *out;
    unsigned n;
    unsigned x, y;
    int hr;

    if ((self->v65() & 4) != 0)
        goto finish;
fetch:
    self->source->v15(0, (void **)&buf, 0);
    if (buf == 0)
        goto next;
    self->source->v17(0, (void **)&item, 0);
    if ((self->v65() & 6) != 0)
        goto cleanup;
process:
    buf->v3();
    n = fn_8322EC18(item);
    if (n > self->limit_f8) {
        view = fn_8322ECB8(item);
        view->v14(1);
        self->source->v18(&x, &y);
        buf->v34(x, y);
        buf->v18(view);
        hr = buf->v30((char *)(ts4l_uptr)(unsigned)view->v21() - 8, &out);
        if (hr < 0) {
            view->release();
            buf->v5();
            self->v24();
            goto cleanup;
        }
        view->release();
        fn_8322EE08(item);
        buf->v5();
        self->v52();
        if (out == 0)
            goto cleanup;
    } else {
        buf->v5();
        self->v42();
    }
    if ((self->v65() & 6) == 0)
        goto process;
cleanup:
    buf->v20();
    if (buf != 0) {
        buf->release();
        buf = 0;
    }
    if (item != 0) {
        item->release();
        item = 0;
    }
next:
    if ((self->v65() & 4) == 0) {
        self->v54();
        fn_8340CA48(self->event10c);
        if ((self->v65() & 4) == 0)
            goto fetch;
    }
finish:
    self->v54();
}
