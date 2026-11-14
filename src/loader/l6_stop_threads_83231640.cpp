/* Loader_DLL.xex 0x83231640-0x832318E8, executable version 0.0.0.3. */
struct ts4l_listener {
    virtual void v0();
    virtual void v1();
    virtual void release();
};

struct ts4l_worker_owner {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69(int a);
    virtual int v70(int a);
    unsigned char pad04[0x2c - 4];
    ts4l_listener *listener;
    void *tls30;
    unsigned char pad34[0x108 - 0x34];
    void *thread108;
    void *thread10c;
    void *thread110;
    void *thread114;
};

extern "C" {
void fn_8340CE10(void *h);
unsigned fn_8340CE50(void *h, unsigned ms);
void fn_8340A360(void *h);
void fn_830AAAE8(void *p);
}

extern "C" int ts4l_stop_workers_83231640(ts4l_worker_owner *self)
{
    self->v69(4);
    self->v70(4);
    if (self->v61() != 1 || self->v62() != 1) {
        self->v24();
        if (self->thread108 != 0) {
            fn_8340CE10(self->thread108);
            self->v45();
        }
        if (self->thread10c != 0) {
            fn_8340CE10(self->thread10c);
            self->v46();
        }
        if (self->thread110 != 0) {
            fn_8340CE10(self->thread110);
            self->v47();
        }
        if (self->thread114 != 0) {
            fn_8340CE10(self->thread114);
            self->v48();
        }
    }
    if (self->thread108 != 0) {
        do {
            fn_8340CE10(self->thread108);
            self->v49();
        } while (fn_8340CE50(self->thread108, 1) == 0x102);
        fn_8340A360(self->thread108);
        self->thread108 = 0;
    }
    if (self->thread10c != 0) {
        do {
            fn_8340CE10(self->thread10c);
            self->v50();
        } while (fn_8340CE50(self->thread10c, 1) == 0x102);
        fn_8340A360(self->thread10c);
        self->thread10c = 0;
    }
    if (self->thread110 != 0) {
        do {
            fn_8340CE10(self->thread110);
            self->v51();
        } while (fn_8340CE50(self->thread110, 1) == 0x102);
        fn_8340A360(self->thread110);
        self->thread110 = 0;
    }
    if (self->thread114 != 0) {
        do {
            fn_8340CE10(self->thread114);
            self->v52();
        } while (fn_8340CE50(self->thread114, 1) == 0x102);
        fn_8340A360(self->thread114);
        self->thread114 = 0;
    }
    if (self->tls30 != 0) {
        fn_830AAAE8(self->tls30);
        self->tls30 = 0;
    }
    if (self->listener != 0) {
        self->listener->release();
        self->listener = 0;
    }
    self->v39();
    return 0;
}
