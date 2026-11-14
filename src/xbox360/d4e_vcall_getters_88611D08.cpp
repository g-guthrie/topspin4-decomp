/* Swing_DLL.xex 0x88611D08-0x8887A5C0, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern "C" {
extern char lbl_8814B440[];
}
extern "C" ts4_word fn_8864E9F8(...);
extern "C" ts4_word ts4_if_get_fn_88804058_888083C0(...);


struct Vk_88809230 {
    virtual ts4_word s0(ts4_word);
    virtual void d1();
    virtual void d2();
    virtual ts4_word s3();
};
#define Vk Vk_88809230
extern "C" {
/* 0x88809230 */
ts4_word ts4_if_get_ts4_if_get_fn_88804058_888083C0_88809230(ts4_word a0)
{
    ts4_word p10;
    ts4_word t2;
    ts4_word t6;
    ts4_word t9;

    ts4_if_get_fn_88804058_888083C0();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    ((Vk *)(ts4_word)t2)->s3();
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    p10 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        t9 = ((Vk *)(ts4_word)t6)->s0((ts4_word)1);
        p10 = (ts4_word)t9;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    return p10;
}
}
#undef Vk

struct Vk_8887A540 {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual ts4_word s7(ts4_word, ts4_word);
};
#define Vk Vk_8887A540
extern "C" {
/* 0x8887A540 */
ts4_word ts4_if_get_u32_offc_8887A540(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word loc60[18];
    ts4_word loc50[4];
    ts4_word t1;
    float t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p7 = (ts4_word)a0;
    if (((ts4_word)t1 != 0 && (ts4_word)a1 != 0) && (ts4_word)a2 != 0) {
        ((Vk *)(ts4_word)a0)->s7((ts4_word)a2, (ts4_word)(ts4_word)&loc60[0]);
        t5 = *(float *)lbl_8814B440;
        *(float *)((char *)loc50 + 0) = t5;
        *(float *)((char *)loc50 + 4) = t5;
        *(float *)((char *)loc50 + 8) = t5;
        t6 = fn_8864E9F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
        p7 = (ts4_word)t6;
    }
    return p7;
}
}
#undef Vk
