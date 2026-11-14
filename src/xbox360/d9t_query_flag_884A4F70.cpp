/* Swing_DLL.xex 0x884A4F70-0x884A5134, executable version 0.0.0.3. */
struct Ts4Flag { unsigned char b; Ts4Flag() {} };
struct Ts4Sub884A4F70 { virtual Ts4Flag m0(); virtual Ts4Flag m1(); };
struct Ts4Obj884A4F70 { char pad[0xc]; Ts4Sub884A4F70 sub; };
struct Ts4Arg884A4F70 { char pad[0x28]; Ts4Obj884A4F70 *obj; };
extern "C" Ts4Flag ts4_query_flag_884A4F70(Ts4Arg884A4F70 *a)
{
    Ts4Flag r;
    r.b = (a->obj == 0 || a->obj->sub.m1().b != 0);
    return r;
}
struct Ts4Sub884A5058 { virtual Ts4Flag m0(); virtual Ts4Flag m1(); };
struct Ts4Obj884A5058 { char pad[0x10]; Ts4Sub884A5058 sub; };
struct Ts4Arg884A5058 { char pad[0x24]; Ts4Obj884A5058 *obj; };
extern "C" Ts4Flag ts4_query_flag_884A5058(Ts4Arg884A5058 *a)
{
    Ts4Flag r;
    r.b = (a->obj == 0 || a->obj->sub.m0().b != 0);
    return r;
}
struct Ts4Sub884A50C8 { virtual Ts4Flag m0(); virtual Ts4Flag m1(); };
struct Ts4Obj884A50C8 { char pad[0x14]; Ts4Sub884A50C8 sub; };
struct Ts4Arg884A50C8 { char pad[0x20]; Ts4Obj884A50C8 *obj; };
extern "C" Ts4Flag ts4_query_flag_884A50C8(Ts4Arg884A50C8 *a)
{
    Ts4Flag r;
    r.b = (a->obj == 0 || a->obj->sub.m1().b != 0);
    return r;
}
