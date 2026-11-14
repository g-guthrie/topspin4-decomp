/* Loader_DLL.xex 0x83146CE0-0x83146D4C, 0x83147990-0x831479FC, 0x83147A00-0x83147A6C, 0x83147C20-0x83147C8C, 0x8314EC00-0x8314EC78, 0x8314F630-0x8314F6A8, 0x8315F080-0x8315F0F8, 0x831528E0-0x83152958, executable version 0.0.0.3. */
extern "C" long _InterlockedDecrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement)
#endif
struct L46Ref { void *vt; long refs; };
struct L46Ref4 { void *vt; long pad[3]; long refs; };
extern "C" void fn_83120540(void *);
extern "C" char lbl_83002270[];

extern "C" long ts4l_release_83146CE0(L46Ref *o)
{
    long c = _InterlockedDecrement(&o->refs);
    if (c == 0) {
        if (o != 0) {
            o->vt = lbl_83002270;
            fn_83120540(o);
        }
        return 0;
    }
    return c;
}

extern "C" char lbl_83002920[];

extern "C" long ts4l_release_83147990(L46Ref *o)
{
    long c = _InterlockedDecrement(&o->refs);
    if (c == 0) {
        if (o != 0) {
            o->vt = lbl_83002920;
            fn_83120540(o);
        }
        return 0;
    }
    return c;
}

extern "C" char lbl_83002904[];

extern "C" long ts4l_release_83147A00(L46Ref *o)
{
    long c = _InterlockedDecrement(&o->refs);
    if (c == 0) {
        if (o != 0) {
            o->vt = lbl_83002904;
            fn_83120540(o);
        }
        return 0;
    }
    return c;
}

extern "C" char lbl_8300293C[];

extern "C" long ts4l_release_83147C20(L46Ref4 *o)
{
    long c = _InterlockedDecrement(&o->refs);
    if (c == 0) {
        if (o != 0) {
            o->vt = lbl_8300293C;
            fn_83120540(o);
        }
        return 0;
    }
    return c;
}

extern "C" void ts4l_if_call_seq_u32_off8_8314EA48(void *);

extern "C" long ts4l_release_8314EC00(char *o)
{
    long c = _InterlockedDecrement((volatile long *)(o + 4));
    if (c == 0) {
        if (o != 0) {
            ts4l_if_call_seq_u32_off8_8314EA48(o);
            fn_83120540(o);
        }
    }
    return c;
}

extern "C" void ts4l_if_addr_lbl_83003F5C_83149E08(void *);

extern "C" long ts4l_release_8314F630(char *o)
{
    long c = _InterlockedDecrement((volatile long *)(o + 4));
    if (c == 0) {
        if (o != 0) {
            ts4l_if_addr_lbl_83003F5C_83149E08(o);
            fn_83120540(o);
        }
    }
    return c;
}

extern "C" void ts4l_if_addr_lbl_830055D8_8315E7A8(void *);

extern "C" long ts4l_release_8315F080(char *o)
{
    long c = _InterlockedDecrement((volatile long *)(o + 4));
    if (c == 0) {
        if (o != 0) {
            ts4l_if_addr_lbl_830055D8_8315E7A8(o);
            fn_83120540(o);
        }
    }
    return c;
}

extern "C" void fn_83151598(void *);

extern "C" long ts4l_release_831528E0(char *o)
{
    long c = _InterlockedDecrement((volatile long *)(o + 128));
    if (c == 0) {
        if (o != 0) {
            fn_83151598(o);
            fn_83120540(o);
        }
    }
    return c;
}

