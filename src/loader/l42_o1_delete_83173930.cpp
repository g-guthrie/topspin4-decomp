/* Loader_DLL.xex 0x83173930-0x83183388, executable version 0.0.0.3. */
/* Delete helpers (single object or array with a count cookie) for other virtual-destructor layouts. */
struct Ts4lDtor_10_3Base {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void *Dtor(int);
};
struct Ts4lDtor_10_3 {
    char pad[16];
    Ts4lDtor_10_3Base sub;
};
struct Ts4lDtor_4_0Base {
    virtual void *Dtor(int);
};
struct Ts4lDtor_4_0 {
    char pad[4];
    Ts4lDtor_4_0Base sub;
};
struct Ts4lDtor_0_1Base {
    virtual void s0();
    virtual void *Dtor(int);
};
struct Ts4lDtor_0_14Base {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void *Dtor(int);
};
extern "C" {
void *ts4l_pool_free_83173898(void *);
void *ts4l_pool_free_83180808(void *);
void *ts4l_pool_free_83183080(void *);

void *ts4l_delete_object_83173930(void *unused, int isArray, Ts4lDtor_10_3 *p)
{
    void *r;
    (void)unused;
    if (isArray == 0) {
        if (p)
            r = p->sub.Dtor(0);
        else
            r = 0;
    } else {
        if (p) {
            if (((int *)p)[-1])
                r = p->sub.Dtor(2);
            else {
                ts4l_pool_free_83173898((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return ts4l_pool_free_83173898(r);
}

void *ts4l_delete_object_83181060(void *unused, int isArray, Ts4lDtor_4_0 *p)
{
    void *r;
    (void)unused;
    if (isArray == 0) {
        if (p)
            r = p->sub.Dtor(0);
        else
            r = 0;
    } else {
        if (p) {
            if (((int *)p)[-1])
                r = p->sub.Dtor(2);
            else {
                ts4l_pool_free_83180808((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return ts4l_pool_free_83180808(r);
}

void *ts4l_delete_object_831810D0(void *unused, int isArray, Ts4lDtor_0_1Base *p)
{
    void *r;
    (void)unused;
    if (isArray == 0) {
        if (p)
            r = p->Dtor(0);
        else
            r = 0;
    } else {
        if (p) {
            if (((int *)p)[-1])
                r = p->Dtor(2);
            else {
                ts4l_pool_free_83180808((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return ts4l_pool_free_83180808(r);
}

void *ts4l_delete_object_83180FA0(void *unused, int isArray, Ts4lDtor_0_1Base *p)
{
    void *r;
    (void)unused;
    if (isArray == 0) {
        if (p)
            r = p->Dtor(0);
        else
            r = 0;
    } else {
        if (p) {
            if (((int *)p)[-2])
                r = p->Dtor(2);
            else {
                ts4l_pool_free_83180808((char *)p - 8);
                r = 0;
            }
        } else
            r = 0;
    }
    return ts4l_pool_free_83180808(r);
}

void *ts4l_delete_object_83183388(void *unused, int isArray, Ts4lDtor_0_14Base *p)
{
    void *r;
    (void)unused;
    if (isArray == 0) {
        if (p)
            r = p->Dtor(0);
        else
            r = 0;
    } else {
        if (p) {
            if (((int *)p)[-1])
                r = p->Dtor(2);
            else {
                ts4l_pool_free_83183080((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return ts4l_pool_free_83183080(r);
}
}
