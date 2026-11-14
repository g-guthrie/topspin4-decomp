/* Loader_DLL.xex 0x8316F680-0x83170680, executable version 0.0.0.3. */
/* Delete helpers for objects whose destructor lives in a secondary base at +4 (vtable slot 19). */
struct Ts4lDtorSub {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18();
    virtual void *Dtor(int);
};
struct Ts4lDtorObj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void *Dtor(int);
};
struct Ts4lDtorOwner {
    int pad;
    Ts4lDtorSub sub;
};
extern "C" {
void *ts4l_pool_free_8316F200(void *);

void *ts4l_delete_object_83170610(void *unused, int isArray, Ts4lDtorOwner *p)
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
                ts4l_pool_free_8316F200((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return ts4l_pool_free_8316F200(r);
}

void *ts4l_delete_object_83170470(void *unused, int isArray, Ts4lDtorOwner *p)
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
                ts4l_pool_free_8316F200((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return ts4l_pool_free_8316F200(r);
}

void *ts4l_delete_object_83170680(void *unused, int isArray, Ts4lDtorOwner *p)
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
                ts4l_pool_free_8316F200((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return ts4l_pool_free_8316F200(r);
}

void *ts4l_delete_object_8316F680(void *unused, int isArray, Ts4lDtorObj *p)
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
                ts4l_pool_free_8316F200((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return ts4l_pool_free_8316F200(r);
}
}
