/* Loader_DLL.xex 0x8319F6C0-0x831F4E18, executable version 0.0.0.3.
 * Deleting helpers: run the object's destructor through its vtable (flag 0 for a single
 * object, flag 2 for an array carrying an element-count cookie) and release the storage;
 * an array with a zero count is released directly from its cookie address. */
struct Ts4lDtorObj {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void *Dtor(int);
};
struct Ts4lDtorSub {
    virtual void s0();
    virtual void *Dtor(int);
};
struct Ts4lDtorWrap {
    int pad;
    Ts4lDtorSub sub;
};

extern "C" {
void *fn_831A0A58(void *);
void *fn_831F3568(void *);
void *fn_831F3B08(void *);
void *fn_831F45E8(void *);
void *fn_8319F538(void *);
void *fn_8319FD00(void *);
void *fn_831A1B40(void *);

void *ts4l_delete_object_831A0BA8(void *unused, int isArray, Ts4lDtorObj *p)
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
                fn_831A0A58((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return fn_831A0A58(r);
}

void *ts4l_delete_object_831F3768(void *unused, int isArray, Ts4lDtorObj *p)
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
                fn_831F3568((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return fn_831F3568(r);
}

void *ts4l_delete_object_831F3C18(void *unused, int isArray, Ts4lDtorObj *p)
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
                fn_831F3B08((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return fn_831F3B08(r);
}

void *ts4l_delete_object_831F4DA8(void *unused, int isArray, Ts4lDtorObj *p)
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
                fn_831F45E8((char *)p - 8);
                r = 0;
            }
        } else
            r = 0;
    }
    return fn_831F45E8(r);
}

void *ts4l_delete_sub_object_8319F6C0(void *unused, int isArray, Ts4lDtorWrap *p)
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
                fn_8319F538((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return fn_8319F538(r);
}

void *ts4l_delete_sub_object_8319FFB0(void *unused, int isArray, Ts4lDtorWrap *p)
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
                fn_8319FD00((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return fn_8319FD00(r);
}

void *ts4l_delete_sub_object_831A1C58(void *unused, int isArray, Ts4lDtorWrap *p)
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
                fn_831A1B40((char *)p - 4);
                r = 0;
            }
        } else
            r = 0;
    }
    return fn_831A1B40(r);
}

}
