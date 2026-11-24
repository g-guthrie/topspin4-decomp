/* Loader_DLL.xex 0x83224AA8-0x83224B24, executable version 0.0.0.3. */
/* Arm a timer-like object: stop it, record the 64-bit target and mark it armed, then start and wait. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
struct Ts4lTimer {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void Stop();
    virtual void v4();
    virtual void Wait();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void Start();
    char pad[0x128];
    volatile ts4l_u64 target;
    int pad2;
    volatile int armed;
};
extern "C" int ts4l_arm_timer_83224AA8(Ts4lTimer *t, ts4l_u64 v)
{
    t->Stop();
    t->armed = 1;
    t->target = v;
    t->Start();
    t->Wait();
    return 0;
}
