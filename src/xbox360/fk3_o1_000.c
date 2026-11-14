/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
extern long _InterlockedDecrement(volatile long *value);
extern long _InterlockedExchange(volatile long *value, long v);
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement, _InterlockedExchange, _InterlockedIncrement)
#endif

extern char g_ts4_script_constants[];
extern char lbl_88001A20[];
extern char lbl_88028EF0[];
extern char lbl_88029264[];
extern char lbl_880B4540[];
extern char lbl_880B4598[];
extern char lbl_880B9778[];
extern char lbl_880B9788[];
extern char lbl_880B97F0[];
extern char lbl_880B9958[];
extern char lbl_880B9964[];
extern char lbl_88C31510[];
extern char lbl_88C31878[];
extern char lbl_88C42CC8[];
extern char lbl_88C6E1A8[];
extern char lbl_88D2F130[];
extern char lbl_88D3EB60[];
extern char lbl_88D4DAB0[];
ts4_word ExFreePool();
ts4_word KeTlsFree();
ts4_word KeTlsSetValue();
ts4_word NtWaitForSingleObjectEx();
ts4_word ObDereferenceObject();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_88287D28();
ts4_word ts4_if_atomic_interlocked_inc_882884B8();
ts4_word ts4_if_atomic_interlocked_dec_88288530();
ts4_word fn_882A2C10();
ts4_word fn_882C7DE8();
ts4_word fn_882C9578();
ts4_word fn_88329868();
ts4_word fn_8833B4C8();
ts4_word fn_8833B648();
ts4_word fn_88563230();
ts4_word ts4_set_thread_priority_8857B3C8();
ts4_word fn_8857B598();
ts4_word fn_8857C8C8();
ts4_word fn_885846A0();
ts4_word ts4_if_atomic_interlocked_dec_88593BB0();
ts4_word ts4_pool16_init_885B5E38();
ts4_word ts4_pool_free_885B72F0();
ts4_word fn_885DC838();
ts4_word ts4_read_indexed_u32_property_885DCDA8();
ts4_word fn_885DCE58();
ts4_word fn_88883DE0();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
ts4_word fn_889D1918();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_if_call_seq_u32_off44_885DCD38();
ts4_word ts4_memset();
ts4_word ts4_record_status();
ts4_word ts4_resume_thread();

/* Swing_DLL.xex 0x882884B8: if_atomic interlocked_inc, u32@0x0, u32@0x18, ts4_if_atomic_interlocked_inc_882884B8 */
ts4_word ts4_if_atomic_interlocked_inc_882884B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedIncrement((volatile long *)(ts4_word)((a0 + 4)));
    if ((ts4_word)t1 == 1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)(t2 & 0xf) == 4) {
            if ((int)(t2 & 0x40000000) != 0) {
                ((ts4_word (*)())ts4_if_atomic_interlocked_inc_882884B8)((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
            }
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x88288530: if_atomic interlocked_dec, u32@0x0, u32@0x0, u32@0x18, ts4_if_atomic_interlocked_dec_88288530, fn_88287D28 */
ts4_word ts4_if_atomic_interlocked_dec_88288530(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedDecrement((volatile long *)(ts4_word)((a0 + 4)));
    p9 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)(t3 & 0xf) == 4) {
            if ((int)(t3 & 0x40000000) != 0) {
                ((ts4_word (*)())ts4_if_atomic_interlocked_dec_88288530)((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
            }
        }
        fn_88287D28((ts4_word)a0);
        p9 = (ts4_word)0;
    }
    return p9;
}

/* Swing_DLL.xex 0x8828C708: get g_ts4_script_constants */
ts4_word ts4_get_g_ts4_script_constants_8828C708(ts4_word a0)
{
    ts4_word locm10[1];
    float t1;
    ts4_word t3;

    t1 = *(float *)((char *)(ts4_word)(a0) + 10832);
    *(float *)((char *)locm10 + 0) = (t1 * (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 664)));
    t3 = locm10[0];
    return t3;
}

/* Swing_DLL.xex 0x8828D928: addr g_ts4_script_constants, u32@0x494 */
ts4_word ts4_addr_g_ts4_script_constants_8828D928(ts4_word a0, ts4_word a1)
{
    ts4_word locm10[2];
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1172);
    *(float *)((char *)locm10 + 0) = (-(((float)((double)((ts4_s64)(int)((int)(t1 << 23) >> 28)))) * (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 300))));
    t3 = locm10[0];
    return t3;
}

/* Swing_DLL.xex 0x8828D9D0: addr g_ts4_script_constants, u32@0x490 */
ts4_word ts4_addr_g_ts4_script_constants_8828D9D0(ts4_word a0, ts4_word a1)
{
    ts4_word locm10[2];
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1168);
    *(float *)((char *)locm10 + 0) = (((float)((double)((ts4_s64)(int)((int)(t1 << 10) >> 22)))) * (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 656)));
    t3 = locm10[0];
    return t3;
}

/* Swing_DLL.xex 0x88296E30: if_atomic interlocked_dec, u8@0x2ac0, u8@0x2ac0, fn_8857C8C8, fn_882A2C10, u32@-0x4 */
ts4_word ts4_if_atomic_interlocked_dec_88296E30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    int t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedDecrement((volatile long *)(ts4_word)((a0 + 60)));
    if ((int)t1 == 0) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 10944) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a0) + 10944)) | 16);
        fn_8857C8C8();
        fn_882A2C10((ts4_word)a0);
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + -4)), (ts4_word)(612368384));
    }
    return t1;
}

/* Swing_DLL.xex 0x882CAC00: get u16@0x3, u16@0x3, u16@0x5, u16@0x5, u16@0x8, u16@0x8 */
void ts4_get_u16_off3_882CAC00(ts4_word a0, ts4_word a1)
{
    unsigned short t1;
    unsigned short t2;
    unsigned short t3;
    unsigned short t4;
    unsigned short t5;
    unsigned short t6;

    t1 = *(unsigned short *)((char *)(ts4_word)(a1) + 3);
    *(unsigned short *)((char *)(ts4_word)(a0) + 3) = (unsigned short)(((t1 & 0xff) << 8) | ((t1) >> 8));
    t2 = *(unsigned short *)((char *)(ts4_word)(a1) + 5);
    *(unsigned short *)((char *)(ts4_word)(a0) + 5) = (unsigned short)(((t2 & 0xff) << 8) | ((t2) >> 8));
    t3 = *(unsigned short *)((char *)(ts4_word)(a1) + 8);
    *(unsigned short *)((char *)(ts4_word)(a0) + 8) = (unsigned short)(((t3 & 0xff) << 8) | ((t3) >> 8));
    t4 = *(unsigned short *)((char *)(ts4_word)(a1) + 10);
    *(unsigned short *)((char *)(ts4_word)(a0) + 10) = (unsigned short)(((t4 & 0xff) << 8) | ((t4) >> 8));
    t5 = *(unsigned short *)((char *)(ts4_word)(a1) + 12);
    *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)(((t5 & 0xff) << 8) | ((t5) >> 8));
    t6 = *(unsigned short *)((char *)(ts4_word)(a1) + 14);
    *(unsigned short *)((char *)(ts4_word)(a0) + 14) = (unsigned short)(((t6 & 0xff) << 8) | ((t6) >> 8));
    return;
}

/* Swing_DLL.xex 0x882CD180: if_call_seq memcpy, fn_882C7DE8, fn_882C9578 */
ts4_word ts4_if_call_seq_memcpy_882CD180(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word loc50[4];
    unsigned short t3;
    ts4_word t5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 >= 14) {
        memcpy((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)14);
        fn_882C7DE8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc50[0]);
        t3 = *(unsigned short *)((char *)loc50 + 0);
        if ((ts4_word)t3 == 19778 && (ts4_word)(*(ts4_word *)((char *)loc50 + 2)) <= (ts4_word)a2) {
            t5 = fn_882C9578((ts4_word)a0, (ts4_word)(a1 + 14), (ts4_word)(a2 + -14));
            p6 = (ts4_word)t5;
        } else {
            p6 = (ts4_word)((2147483648) | 16389);
        }
        p7 = (ts4_word)p6;
    } else {
        p7 = (ts4_word)((2147483648) | 16389);
    }
    return p7;
}

/* Swing_DLL.xex 0x8833B9C0: if_call_seq u32@0x6e8, u32@0x6e8, fn_8833B4C8, u32@0x6e8, fn_8833B648 */
ts4_word ts4_if_call_seq_u32_off6e8_8833B9C0(ts4_word a0, ts4_word a1)
{
    float t1;
    float t2;
    float t3;
    ts4_word t5;

    t1 = *(float *)((char *)(ts4_word)(a1) + 44);
    t2 = *(float *)lbl_88028EF0;
    if (!(t1 < t2)) {
        t3 = *(float *)lbl_88029264;
        if (t1 > t3) {
            *(float *)((char *)(ts4_word)(a1) + 44) = t3;
        }
    } else {
        *(float *)((char *)(ts4_word)(a1) + 44) = t2;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 1768);
    *(float *)((char *)(ts4_word)(t5) + 44) = (*(float *)((char *)(ts4_word)(a1) + 44));
    fn_8833B4C8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1768)));
    fn_8833B648((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1768)));
    return 0;
}

/* Swing_DLL.xex 0x883CEB28: if_get u8@0x0, u32@0x28, u8@0x0, u8@0x0, u8@0x0 */
ts4_word ts4_if_get_u8_off0_883CEB28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, float f1, float f2)
{
    float pf4;
    float pf5;
    float t1;
    float t2;
    float t3;
    ts4_word t6;

    (void)a1;
    (void)a2;
    if ((ts4_word)a3 != 0) {
        t1 = *(float *)lbl_88001A20;
        if (!(f2 < t1)) {
            *(unsigned char *)((char *)(ts4_word)(a3) + 0) = (unsigned char)0;
            t2 = *(float *)((char *)(ts4_word)(a0) + 32);
            t3 = *(float *)((char *)(ts4_word)(a0) + 24);
            if (t2 < t3) {
                pf4 = t2;
                pf5 = t3;
            } else {
                pf4 = t3;
                pf5 = t2;
            }
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
            if ((int)(t6 & 0x4) != 0) {
                if (f1 > pf4) {
                    if ((f1 + f2) > pf5) {
                        *(unsigned char *)((char *)(ts4_word)(a3) + 0) = (unsigned char)1;
                    }
                } else {
                    *(unsigned char *)((char *)(ts4_word)(a3) + 0) = (unsigned char)1;
                }
            } else {
                if ((f1 + f2) > pf4) {
                    if (!(f1 > pf5)) {
                        *(unsigned char *)((char *)(ts4_word)(a3) + 0) = (unsigned char)1;
                    }
                }
            }
            return 0;
        }
        return 37;
    }
    return 37;
}

/* Swing_DLL.xex 0x883D09D0: loop_call_seq u32@0x0, u32@0x0, u32@0x10, fn_88329868, u32@0x0, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_off0_883D09D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv2;
    ts4_word p6;
    ts4_word p7;
    int t4;

    if ((ts4_word)a1 != 0 && (ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
        lv2 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32684)) + 0));
        while ((ts4_word)lv2 != (ts4_word)((a0 + 65536) + -32684)) {
            t4 = fn_88329868((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 16)), (ts4_word)a1);
            if ((int)t4 == 0) {
                *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)lv2;
                return 0;
            }
            p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 0));
            lv2 = p6;
        }
        p7 = (ts4_word)37;
    } else {
        p7 = (ts4_word)37;
    }
    return p7;
}

/* Swing_DLL.xex 0x884F03A0: get u32@0x200, u32@0x0, u64@0x8, u32@0x200, u32@0x200 */
ts4_word ts4_get_u32_off200_884F03A0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 512);
    *(ts4_word *)((char *)(ts4_word)(((t1 << 4) + a0)) + 0) = (ts4_word)4;
    *(ts4_u64 *)((char *)(ts4_word)(((t1 << 4) + a0)) + 8) = (ts4_u64)((ts4_s64)(int)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 512);
    *(ts4_word *)((char *)(ts4_word)(a0) + 512) = (ts4_word)(t2 + 1);
    return t2;
}

/* Swing_DLL.xex 0x884F9F90: if_atomic interlocked_dec, u32@0x0, u32@0x38, vcall */
ts4_word ts4_if_atomic_interlocked_dec_884F9F90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedDecrement((volatile long *)(ts4_word)((a0 + 28)));
    if ((ts4_word)t1 == 0 && (ts4_word)a0 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)1);
    }
    return t1;
}

/* Swing_DLL.xex 0x885677A0: get u32@lbl_88C31878, u32@0xc8 */
ts4_word ts4_get_u32_lbl_88C31878_885677A0(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)(((a0 & 0xff) << 1)) + (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88C31878)) + 200)))) & 0xffff8000);
}

/* Swing_DLL.xex 0x8856F558: addr lbl_88C31510, RtlLeaveCriticalSection */
ts4_word ts4_addr_lbl_88C31510_8856F558(ts4_word a0)
{
    return RtlLeaveCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 << 3)) + (ts4_word)lbl_88C31510)));
}

/* Swing_DLL.xex 0x88582F30: loop_call_seq fn_885846A0, NtWaitForSingleObjectEx, ts4_record_status */
ts4_word ts4_loop_call_seq_fn_885846A0_88582F30(ts4_word a0, ts4_word a1, int a2)
{
    ts4_word loc50[2];
    ts4_word t1;
    int t2;

    t1 = fn_885846A0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    do {
        t2 = NtWaitForSingleObjectEx((ts4_word)a0, (ts4_word)1, (ts4_word)(a2 & 0xff), (ts4_word)t1);
        if ((int)t2 < 0) {
            ts4_record_status((ts4_word)t2);
            return -1;
        }
        if ((int)a2 == 0) {
            return t2;
        }
    } while ((int)t2 == 257);
    return t2;
}

/* Swing_DLL.xex 0x885949C0: if_atomic interlocked_dec, u32@0x0, u32@0xc, vcall, ts4_pool_free_885B72F0, lbl_88D2F130 */
ts4_word ts4_if_atomic_interlocked_dec_885949C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedDecrement((volatile long *)(ts4_word)((a0 + 4)));
    if ((ts4_word)t1 == 0) {
        if ((ts4_word)a0 != 0) {
            t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0, (ts4_word)0);
            p5 = (ts4_word)t4;
        } else {
            p5 = (ts4_word)0;
        }
        ts4_pool_free_885B72F0((ts4_word)p5);
        ts4_if_atomic_interlocked_dec_88593BB0((ts4_word)(ts4_word)lbl_88D2F130);
    }
    return t1;
}

/* Swing_DLL.xex 0x88595918: loop_call_seq u32@0x0, u32@0x4, u32@0x0, ts4_pool16_init_885B5E38 */
ts4_word ts4_loop_call_seq_u32_off0_88595918(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    c1 = (ts4_word)2;
    lv2 = (ts4_word)a0;
    do {
        *(ts4_word *)((char *)(ts4_word)(lv2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 8)) + 0) = (ts4_word)((2147418112) | 65535);
        p3 = (ts4_word)(lv2 + 8);
        lv2 = p3;
    } while (--c1 != 0);
    ts4_pool16_init_885B5E38((ts4_word)(a0 + 20));
    return a0;
}

/* Swing_DLL.xex 0x885A6980: get u32@0x18 */
void ts4_get_u32_off18_885A6980(ts4_word a0, ts4_word a1)
{
    ts4_word locm10[1];
    float t1;
    ts4_word t3;

    t1 = *(float *)((char *)(ts4_word)(a1) + 0);
    *(float *)((char *)locm10 + 0) = ((*(float *)((char *)(ts4_word)(a0) + 56)) * t1);
    t3 = locm10[0];
    *(float *)((char *)(ts4_word)(a0) + 68) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x885A6E48: if_atomic interlocked_dec, u32@0x0, u32@0x38, vcall, ts4_pool_free_885B72F0, lbl_88D2F130 */
ts4_word ts4_if_atomic_interlocked_dec_885A6E48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedDecrement((volatile long *)(ts4_word)((a0 + 28)));
    if ((ts4_word)t1 == 0) {
        if ((ts4_word)a0 != 0) {
            t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)0);
            p5 = (ts4_word)t4;
        } else {
            p5 = (ts4_word)0;
        }
        ts4_pool_free_885B72F0((ts4_word)p5);
        ts4_if_atomic_interlocked_dec_88593BB0((ts4_word)(ts4_word)lbl_88D2F130);
    }
    return t1;
}

/* Swing_DLL.xex 0x885A77B0: if_get u32@0x44, interlocked_xchg, u32@0x44, u32@0x0, u32@0x44, u32@0x0 */
void ts4_if_get_u32_off44_885A77B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word locm10[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t12;
    ts4_word t14;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 == 0) {
        t2 = _InterlockedExchange((volatile long *)(ts4_word)((a0 + 64)), (long)-1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)t2;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)t6;
    *(ts4_word *)((char *)(ts4_word)(t7) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(t7) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)locm10 + 0) = (*(float *)((char *)(ts4_word)(a1) + 4));
    t12 = locm10[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t12;
    *(float *)((char *)locm10 + 0) = (*(float *)((char *)(ts4_word)(a1) + 8));
    t14 = locm10[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t14;
    return;
}

/* Swing_DLL.xex 0x885CFA30: if_get u32@0x8, u64@0xc8, u32@0xc0, u32@0x0, u32@0x1c, vcall */
ts4_word ts4_if_get_u32_off8_885CFA30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p19;
    ts4_word p31;
    ts4_word t1;
    ts4_word t6;
    ts4_word t11;
    ts4_word t12;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;
    int t25;
    ts4_word t27;
    ts4_word t30;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x10) != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        *(ts4_u64 *)((char *)(ts4_word)(a0) + 200) = (ts4_u64)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
        if ((ts4_word)t1 != 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 252);
        if ((ts4_word)t6 != 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 28))))((ts4_word)t6);
        }
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
        if ((ts4_word)t11 != 0) {
            t12 = *(ts4_word *)((char *)(ts4_word)(t11) + 16);
            *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0)) + t12);
            t14 = *(ts4_word *)((char *)(ts4_word)(t11) + 0);
            t15 = *(ts4_word *)((char *)(ts4_word)(t11) + 16);
            t16 = *(ts4_word *)((char *)(ts4_word)(t11) + 28);
            t17 = *(ts4_word *)((char *)(ts4_word)(t11) + 24);
            if ((ts4_word)(t14 + t15) < (ts4_word)((t16 + t17) + t14)) {
                p19 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t11) + 32));
            } else {
                p19 = (ts4_word)0;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)p19;
        }
    }
    if ((int)(a1 & 0x20) != 0) {
        t25 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
        if ((int)t25 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)1;
        }
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)1;
    }
    t27 = *(ts4_word *)((char *)(ts4_word)(a0) + 264);
    p31 = (ts4_word)t27;
    if ((ts4_word)t27 != 0) {
        t30 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t27) + 0))) + 4))))((ts4_word)t27, (ts4_word)a1);
        p31 = (ts4_word)t30;
    }
    return p31;
}

/* Swing_DLL.xex 0x885DA1A8: get u32@0x1c, u32@0x28, interlocked_dec, u32@0x20, u32@0x4, ObDereferenceObject */
ts4_word ts4_get_u32_off1c_885DA1A8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    _InterlockedDecrement((volatile long *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t1) + 40)) + 16)));
    *(ts4_word *)((char *)(ts4_word)(t1) + 32) = (ts4_word)0;
    ObDereferenceObject((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t6 = ExFreePool((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x885DF7A0: if_addr ts4_if_call_seq_u32_off44_885DCD38, fn_885DCE58, lbl_88C42CC8, lbl_880B9778, u32@0xf0, vcall */
ts4_word ts4_if_addr_ts4_if_call_seq_u32_off44_885DCD38_885DF7A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word t1;

    (void)a1;
    t1 = ts4_if_call_seq_u32_off44_885DCD38((ts4_word)a0, (ts4_word)971);
    if ((ts4_word)t1 == 1) {
        if ((ts4_word)a2 != 0) {
            fn_885DCE58((ts4_word)a2, (ts4_word)37, (ts4_word)0, (ts4_word)1);
        }
        if ((ts4_word)a3 != 0 && (ts4_word)a4 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(a3))((ts4_word)a4, (ts4_word)(ts4_word)lbl_880B9778, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C42CC8) + 240)), (ts4_word)60, (ts4_word)1);
        }
        p12 = (ts4_word)1;
    } else {
        if ((ts4_word)a2 != 0) {
            fn_885DCE58((ts4_word)a2, (ts4_word)37, (ts4_word)0, (ts4_word)0);
        }
        if ((ts4_word)a3 != 0 && (ts4_word)a4 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(a3))((ts4_word)a4, (ts4_word)(ts4_word)lbl_880B9778, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C42CC8) + 240)), (ts4_word)60, (ts4_word)0);
        }
        p12 = (ts4_word)0;
    }
    return p12;
}

/* Swing_DLL.xex 0x885E1310: if_addr lbl_880B4540, lbl_880B9788, lbl_880B4598, fn_885DC838, lbl_880B9964, fn_885DC838 */
ts4_word ts4_if_addr_lbl_880B4540_885E1310(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p18;
    ts4_word t7;

    (void)a5;
    (void)a6;
    if ((ts4_word)a0 == 0) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B4598, (ts4_word)(ts4_word)lbl_880B9788, (ts4_word)504);
    }
    if ((int)a1 >= 16) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B9964, (ts4_word)(ts4_word)lbl_880B9788, (ts4_word)505);
    }
    if ((int)a1 < 0) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B9958, (ts4_word)(ts4_word)lbl_880B9788, (ts4_word)506);
    }
    t7 = ts4_read_indexed_u32_property_885DCDA8((ts4_word)a0, (ts4_word)12, (ts4_word)a1);
    if ((ts4_word)t7 != 1) {
        if ((ts4_word)a2 != 0) {
            fn_885DCE58((ts4_word)a2, (ts4_word)0, (ts4_word)a1, (ts4_word)1);
        }
        if ((ts4_word)a3 != 0 && (ts4_word)a4 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(a3))((ts4_word)a4, (ts4_word)(ts4_word)lbl_880B97F0, (ts4_word)(*(ts4_word *)lbl_88C42CC8), (ts4_word)0, (ts4_word)a1, (ts4_word)1);
        }
        p18 = (ts4_word)1;
    } else {
        if ((ts4_word)a2 != 0) {
            fn_885DCE58((ts4_word)a2, (ts4_word)0, (ts4_word)a1, (ts4_word)0);
        }
        if ((ts4_word)a3 != 0 && (ts4_word)a4 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(a3))((ts4_word)a4, (ts4_word)(ts4_word)lbl_880B97F0, (ts4_word)(*(ts4_word *)lbl_88C42CC8), (ts4_word)0, (ts4_word)a1, (ts4_word)0);
        }
        p18 = (ts4_word)0;
    }
    return p18;
}

/* Swing_DLL.xex 0x88884B20: loop_call_seq fn_88563230, lbl_88D3EB60, u32@0x0, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_loop_call_seq_fn_88563230_88884B20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv2;
    ts4_word p14;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t10;
    ts4_word t16;

    t1 = fn_88563230((ts4_word)0, (ts4_word)a3, (ts4_word)a0, (ts4_word)a1, (ts4_word)4, (ts4_word)(ts4_word)&loc50[0]);
    lv2 = (ts4_word)(ts4_word)lbl_88D3EB60;
    do {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv2) + 0);
        if ((ts4_word)t4 == 0) {
            t5 = loc50[0];
            *(ts4_word *)((char *)(ts4_word)(lv2) + 0) = (ts4_word)t1;
            *(ts4_word *)((char *)(ts4_word)(lv2) + 4) = (ts4_word)t5;
            ts4_memset((ts4_word)(lv2 + 8), (ts4_word)0, (ts4_word)512);
            ts4_set_thread_priority_8857B3C8((ts4_word)t1, (ts4_word)0);
            if ((ts4_word)a2 != 0) {
                t10 = loc50[0];
                fn_88883DE0((ts4_word)t10, (ts4_word)a2);
                fn_8857B598((ts4_word)t1, (ts4_word)2);
                ts4_resume_thread((ts4_word)t1);
                return t1;
            }
            fn_8857B598((ts4_word)t1, (ts4_word)2);
            ts4_resume_thread((ts4_word)t1);
            return t1;
        }
        p14 = (ts4_word)(lv2 + 520);
        lv2 = p14;
    } while ((ts4_word)p14 != (ts4_word)((ts4_word)lbl_88D3EB60 + 13000));
    ts4_set_thread_priority_8857B3C8((ts4_word)t1, (ts4_word)0);
    if ((ts4_word)a2 != 0) {
        t16 = loc50[0];
        fn_88883DE0((ts4_word)t16, (ts4_word)a2);
    }
    fn_8857B598((ts4_word)t1, (ts4_word)2);
    ts4_resume_thread((ts4_word)t1);
    return t1;
}

/* Swing_DLL.xex 0x889D19B8: get fn_889D1918, u32@lbl_88C6E1A8, KeTlsFree, lbl_88D4DAB0, u32@lbl_88C6E1A8, interlocked_xchg */
ts4_word ts4_get_fn_889D1918_889D19B8(void)
{
    ts4_word t3;

    fn_889D1918();
    t3 = KeTlsFree((ts4_word)(*(ts4_word *)lbl_88C6E1A8));
    *(ts4_word *)lbl_88C6E1A8 = (ts4_word)((4276813824) | 53261);
    _InterlockedExchange((volatile long *)(ts4_word)((ts4_word)lbl_88D4DAB0), (long)0);
    return t3;
}

/* Swing_DLL.xex 0x889D1A20: if_get fn_889D1918, u32@lbl_88C6E1A8, KeTlsSetValue, lbl_88D4DAB0, interlocked_xchg */
ts4_word ts4_if_get_fn_889D1918_889D1A20(void)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    fn_889D1918();
    t2 = *(ts4_word *)lbl_88C6E1A8;
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != (ts4_word)((4276813824) | 53261)) {
        t3 = KeTlsSetValue((ts4_word)t2, (ts4_word)0);
        p4 = (ts4_word)t3;
    }
    _InterlockedExchange((volatile long *)(ts4_word)((ts4_word)lbl_88D4DAB0), (long)0);
    return p4;
}
