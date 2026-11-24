/* Loader_DLL.xex 0x8314E1E8-0x8314E26C, 0x831759A8-0x83175A2C, 0x83188540-0x831885C4, 0x8318A518-0x8318A59C, 0x8314E408-0x8314E490, executable version 0.0.0.3. */

struct L40Lock {
    virtual void s0(); virtual void s1(); virtual void Enter(); virtual void s3(); virtual void s4();
    virtual void Leave();
};
struct L40Mgr { char pad[0x2c]; L40Lock lk; };

struct L40Sink {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual void s9(void *);
};
struct L40Src {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10();
    virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25();
    virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30();
    virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40();
    virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
    virtual void s46(); virtual void s47();
    virtual L40Sink *s48();
};
struct L40Info { char pad[0xbc]; int a; int b; };

extern "C" int ts4l_get_info_8314E1E8(L40Info *o, int *out)
{
    if (o == 0) return 0x80070057;
    if (out == 0) return 0x80070057;
    *out = 0;
    out[0] = o->a;
    out[1] = o->b;
    ((L40Src *)o)->s48()->s9(out);
    return 0;
}

struct L40Dev {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11();
    virtual int s12(unsigned int);
};
struct L40Owner {
    char pad[0x34]; L40Mgr *mgr; char pad2[0x90 - 0x38]; L40Dev *dev; char pad3[0xd4 - 0x94]; unsigned int cur;
};

extern "C" int ts4l_set_current_831759A8(L40Owner *o, unsigned int v)
{
    int hr;
    o->mgr->lk.Enter();
    hr = 0;
    if (v != o->cur) {
        hr = o->dev->s12(v);
        if (hr >= 0) o->cur = v;
    }
    o->mgr->lk.Leave();
    return hr;
}

struct L40Slot { L40Dev *obj; };
struct L40Node { L40Slot *slot; L40Node *next; };
struct L40List { char pad[0x2c]; L40Node *head; };
struct L40Item {
    virtual void s0(); virtual int s1(int, void *);
};
struct L40Slot2 { L40Item *obj; };
struct L40Node2 { L40Slot2 *slot; L40Node2 *next; };
struct L40List2 { char pad[0x2c]; L40Node2 *head; };

extern "C" int ts4l_visit_all_83188540(L40List2 *l, void *arg)
{
    L40Node2 *n, *cur;
    L40Slot2 *s;
    int hr;
    n = l->head;
    hr = 0;
    while (n != 0) {
        if (hr < 0) break;
        cur = n;
        if (cur != 0) {
            n = cur->next;
            s = cur->slot;
        } else {
            s = 0;
        }
        hr = s->obj->s1(0, arg);
    }
    return hr;
}

struct L40Q {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(int, int);
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10();
    virtual void s11(); virtual void s12();
    virtual unsigned int s13();
};
struct L40G {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10();
    virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25();
    virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30();
    virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40();
    virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
    virtual void s46(); virtual void s47();
    virtual L40Q *s48();
};
extern "C" L40G *lbl_835312C4;

extern "C" void ts4l_notify_8314E408(int a, int b)
{
    if (lbl_835312C4 != 0) {
        int z = lbl_835312C4->s48()->s13();
        lbl_835312C4->s48()->s5(a, z == 0 ? b : 0);
    }
}

extern "C" long _InterlockedDecrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement)
#endif
struct L40Peer { virtual void s0(); virtual void Release(); };
struct L40Ref { char pad0[4]; L40Peer *peer; char pad1[8]; long refs; };
extern "C" void fn_83145F40(L40Ref *);
extern "C" void fn_83120540(L40Ref *);

extern "C" long ts4l_release_83146030(L40Ref *o)
{
    long c = _InterlockedDecrement(&o->refs);
    if (c == 0) {
        if (o->peer != 0) ((L40Peer *)(unsigned long long)o->peer)->Release();
        fn_83145F40(o);
        fn_83120540(o);
        return 0;
    }
    return c;
}

struct L40Rel3 {
    virtual void s0(); virtual void s1(); virtual void s2();
    virtual void *s3(int);
};
struct L40Rel14 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void *s14(int);
};
extern "C" char lbl_83531690[];
extern "C" void ts4l_pool_free_8316F200(void *);
extern "C" void fn_8316F0A8(void *);
extern "C" void ts4l_pool_free_83183080(void *);

extern "C" long ts4l_release_83170F60(L40Rel3 *o)
{
    long c = _InterlockedDecrement((volatile long *)((char *)o + 4));
    if ((unsigned long)c == 0) {
        ts4l_pool_free_8316F200(o ? o->s3(0) : 0);
        fn_8316F0A8(lbl_83531690);
    }
    return c;
}

extern "C" long ts4l_release_83183418(L40Rel14 *o)
{
    long c = _InterlockedDecrement((volatile long *)((char *)o + 0x1c));
    if ((unsigned long)c == 0) {
        ts4l_pool_free_83183080(o ? o->s14(0) : 0);
        fn_8316F0A8(lbl_83531690);
    }
    return c;
}

struct L40Item2 { virtual void s0(); virtual void s1(); virtual void s2(int); };
struct L40Node3 { L40Item2 *item; L40Node3 *next; };
struct L40Locked { char pad[0x70]; L40Lock lk; char pad2[0x22c - 0x74]; L40Node3 *head; };

extern "C" void ts4l_notify_all_8316FF48(L40Locked *o, int a)
{
    L40Node3 *n, *cur;
    L40Item2 *it;
    o->lk.Enter();
    n = o->head;
    for (;;) {
        cur = n;
        if (cur != 0) {
            n = cur->next;
            it = cur->item;
        } else {
            it = 0;
        }
        if (it == 0) break;
        it->s2(a);
    }
    o->lk.Leave();
}

struct L40Res2 { virtual void s0(); virtual void s1(); virtual void *s2(); };
struct L40Prov {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
    virtual L40Res2 *s50();
};
extern "C" void ts4l_interlocked_830AAAC0(void *);

extern "C" int ts4l_get_resource_8314DE00(L40Prov *p, void **out)
{
    L40Res2 *r;
    void *v;
    *out = 0;
    if (p != 0) {
        r = p->s50();
        if (r == 0) return 0x80300030;
        v = r->s2();
        *out = v;
        if (v != 0) {
            ts4l_interlocked_830AAAC0(v);
            return 0;
        }
    }
    return 0x80070057;
}

extern "C" void ts4l_notify_8314E490(int a)
{
    if (lbl_835312C4 != 0) {
        if (a == 0) {
            if (lbl_835312C4->s48()->s13() != 0) return;
        }
        lbl_835312C4->s48()->s8();
    }
}

struct L40Cb { virtual void s0(); virtual void s1(); };
struct L40Swap { char pad[0x10]; void *p10; };
extern "C" int fn_8314F8D8(L40Swap *, L40Cb **, int);
extern "C" L40Cb *lbl_835312BC;

extern "C" int ts4l_swap_callback_83150518(L40Swap *o)
{
    L40Cb *tmp;
    int hr;
    tmp = 0;
    if (o == 0) return 0x80070057;
    if (o->p10 == 0) return 0x80070057;
    hr = fn_8314F8D8(o, &tmp, 1);
    if (hr < 0) return hr;
    if (lbl_835312BC != 0) lbl_835312BC->s1();
    lbl_835312BC = tmp;
    return 0;
}

struct L40Lk2 { char pad[0x1c]; L40Lock lk; char pad2[0x48 - 0x20]; void *cs; char pad3[0x180 - 0x4c]; int v180; };
extern "C" int fn_8319E918(void *, int, int, int *);
extern "C" int fn_83180D18(L40Lk2 *, int, int);
extern "C" void ts4l_call_seq_RtlEnterCriticalSection_831808E8(void *);

extern "C" int ts4l_locked_op_83181908(L40Lk2 *o, int a, int *pb)
{
    int hr;
    o->lk.Enter();
    hr = fn_8319E918(o->cs, a, o->v180, pb);
    if (hr >= 0) {
        hr = fn_83180D18(o, 0, *pb);
        if (hr >= 0) ts4l_call_seq_RtlEnterCriticalSection_831808E8(o->cs);
    }
    o->lk.Leave();
    return hr;
}

struct L40Obs { virtual void s0(); virtual void s1(); };
struct L40ObsNode { L40Obs *obs; L40ObsNode *next; };
struct L40Bcast {
    char pad[0x78]; int v78; char pad2[4]; int v80; char pad3[0x150 - 0x84]; L40ObsNode *head;
    char pad4[0x29c - 0x154]; int v29c;
};
extern "C" void ts4l_if_call_seq_RtlEnterCriticalSection_8319DBA0(L40Bcast *);

extern "C" void ts4l_broadcast_8319DDB8(L40Bcast *o, int flag)
{
    L40ObsNode *n, *cur;
    L40Obs *ob;
    if (o->v80 != 0) {
        ts4l_if_call_seq_RtlEnterCriticalSection_8319DBA0(o);
        o->v29c = 0;
        if (flag != 0) {
            n = o->head;
            o->v80 = 0;
            while (n != 0) {
                cur = n;
                if (cur != 0) {
                    n = cur->next;
                    ob = cur->obs;
                } else {
                    ob = 0;
                }
                ob->s1();
            }
        } else {
            o->v80 = 1;
        }
        o->v78 = 0;
    }
}
