/* Swing_DLL.xex 0x883E44E0-0x883E4568, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ts4X4Target {
    virtual void s0();
    virtual void set_value(float v);
};
struct Ts4X4Registry {
    virtual void s0(); virtual void s1(); virtual void s2();
    virtual Ts4X4Target *lookup(u32 key);
};
struct Ts4X4Obj { char pad[8]; void *handle; };
extern "C" {
Ts4X4Registry *ts4_get_u32_lbl_88CAC9A8_883E6388(Ts4X4Obj *o);
int ts4_set_target_value_883E44E0(Ts4X4Obj *o, u32 key, float value)
{
    Ts4X4Target *t;
    if (o->handle == 0)
        return 0x5f;
    t = ts4_get_u32_lbl_88CAC9A8_883E6388(o)->lookup(key);
    if (t == 0)
        return 0x60;
    t->set_value(value);
    return 0;
}
}
