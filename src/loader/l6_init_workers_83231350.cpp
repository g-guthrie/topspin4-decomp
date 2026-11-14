/* Loader_DLL.xex 0x83231350-0x8323163C, executable version 0.0.0.3. */
struct ts4l_link {
    void *next;
    void *prev;
};

struct ts4l_event {
    unsigned char set;
    int count;
    ts4l_link link;
};

static inline void ts4l_event_init(ts4l_event *e, int set, int count)
{
    ts4l_link *l = &e->link;
    e->set = (unsigned char)set;
    e->count = count;
    l->next = l;
    l->prev = l;
}

struct ts4l_params {
    unsigned a0;
    unsigned a4;
    int has_priorities;
    int prio_c;
    int prio_10;
    int prio_14;
    int prio_18;
};

struct ts4l_worker_init {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual void v14();
    virtual void v15();
    virtual int v16(unsigned a);
    virtual int v17(unsigned a);
    unsigned char pad04[0x54 - 4];
    ts4l_event events[8];
    unsigned char pad_d4[0x108 - 0xd4];
    void *thread108;
    void *thread10c;
    void *thread110;
    void *thread114;
};

extern "C" {
void *fn_8340C7F8(void *attr, unsigned stack, void *start, void *param, unsigned flags, void *id);
void fn_8340CCA0(void *h, int prio);
void fn_83230698(void);
void fn_832306C8(void);
void fn_832306F8(void);
void fn_83230728(void);
}

extern "C" int ts4l_init_workers_83231350(ts4l_worker_init *self, ts4l_params *p)
{
    int hr;
    int a;
    int b;
    int c;
    int d;

    hr = self->v13();
    if (hr < 0)
        goto fail;
    ts4l_event_init(&self->events[0], 1, 0);
    ts4l_event_init(&self->events[1], 1, 0);
    ts4l_event_init(&self->events[2], 1, 0);
    ts4l_event_init(&self->events[3], 1, 0);
    ts4l_event_init(&self->events[4], 0, 1);
    ts4l_event_init(&self->events[5], 0, 1);
    ts4l_event_init(&self->events[6], 0, 1);
    ts4l_event_init(&self->events[7], 0, 1);
    self->thread108 = fn_8340C7F8(0, 0x10000, (void *)fn_83230698, self, 4, 0);
    if (self->thread108 == 0)
        hr = self->v8();
    if (hr < 0)
        goto fail;
    self->thread10c = fn_8340C7F8(0, 0x10000, (void *)fn_832306C8, self, 4, 0);
    if (self->thread10c == 0)
        hr = self->v8();
    if (hr < 0)
        goto fail;
    self->thread110 = fn_8340C7F8(0, 0x10000, (void *)fn_832306F8, self, 4, 0);
    if (self->thread110 == 0)
        hr = self->v8();
    if (hr < 0)
        goto fail;
    self->thread114 = fn_8340C7F8(0, 0x10000, (void *)fn_83230728, self, 4, 0);
    if (self->thread114 == 0)
        hr = self->v8();
    if (hr < 0)
        goto fail;
    if (p->has_priorities != 0) {
        a = p->prio_c;
        b = p->prio_10;
        c = p->prio_14;
        d = p->prio_18;
    } else {
        a = 3;
        b = 1;
        c = 3;
        d = 2;
    }
    fn_8340CCA0(self->thread10c, b);
    fn_8340CCA0(self->thread114, d);
    fn_8340CCA0(self->thread108, a);
    fn_8340CCA0(self->thread110, c);
    hr = self->v16(p->a0);
    if (hr < 0)
        goto fail;
    hr = self->v17(p->a4);
    if (hr >= 0)
        return hr;
fail:
    self->v13();
    return hr;
}
