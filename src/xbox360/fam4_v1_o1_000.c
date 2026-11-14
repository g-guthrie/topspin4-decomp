/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset.
   FAM4 variants: void returns, repeated member reads (MSVC turns the
   re-read of a tested pointer into `clrrwi rX,rY,0`), the inlined
   reference-counted string release of fam4_refstr.h. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern char __imp_KeCertMonitorData[];
extern char __imp_KeDebugMonitorData[];
extern char fn_882A5C50[];
extern char fn_882A5CF0[];
extern char lbl_8808F798[];
extern char lbl_88D2F130[];
extern char ts4_get_u8_off2abf_882A4F40[];
ts4_word fn_88316808(ts4_word, float, float, float, ts4_word);
ts4_word ts4_if_call_seq_u32_off0_884F5220();
ts4_word ts4_if_call_seq_u32_off4_884F5A80();
ts4_word fn_885651F8();
ts4_word fn_8858B180();
ts4_word fn_88593C30();
ts4_word fn_88594848();
ts4_word fn_8859AD58();
ts4_word fn_8859C1C8();
ts4_word fn_8859D5A8();
ts4_word fn_885A5568();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_if_call_seq_fn_88309DB8_88309438();
ts4_word ts4_if_call_seq_fn_88594848_88594940();
ts4_word ts4_if_call_seq_fn_88594848_88594F78();
ts4_word ts4_if_call_seq_fn_885A5568_885B6468();
ts4_word ts4_if_get_fn_8832BFC0_883168A8();
ts4_word ts4_lookup_then_forward_88317468();
ts4_word ts4_pool_free_885B72F0();
ts4_word ts4_tailcall_MmFreePhysicalMemory_8857B158();
ts4_word ts4_vcall_member_slot0_88598CF8();

/* Swing_DLL.xex 0x882A5ED0: if_get u32@__imp_KeCertMonitorData, u32@0x0, u32@0x0, u32@__imp_KeDebugMonitorData, u32@0x0, u32@__imp_KeDebugMonitorData */
void ts4_if_get_u32__imp_KeCertMonitorData_882A5ED0(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t11;
    ts4_word t7;
    ts4_word t15;
    ts4_word t16;
    ts4_word t21;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeCertMonitorData)) + 0);
    if ((ts4_word)t2 != 0) {
        t11 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
        if ((ts4_word)t11 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))(t11))((ts4_word)28, (ts4_word)(ts4_word)fn_882A5C50);
        }
    } else {
        t7 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
        if ((ts4_word)t7 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t7) + 24))))((ts4_word)28, (ts4_word)(ts4_word)fn_882A5C50);
        }
    }
    t15 = *(ts4_word *)__imp_KeDebugMonitorData;
    loc50[1] = (ts4_word)a0;
    loc50[0] = (ts4_word)(ts4_word)ts4_get_u8_off2abf_882A4F40;
    t16 = *(ts4_word *)((char *)(ts4_word)(t15) + 0);
    if ((ts4_word)t16 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t16) + 24))))((ts4_word)66, (ts4_word)(ts4_word)&loc50[0]);
    }
    t21 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
    if ((ts4_word)t21 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t21) + 24))))((ts4_word)89, (ts4_word)(ts4_word)fn_882A5CF0);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 21840) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 21844) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 21848) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x883EEA28: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_883EEA28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ((void (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)((int)a1 * (int)a2), (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    return;
}

/* Swing_DLL.xex 0x883FF658: if_get ts4_if_get_fn_8832BFC0_883168A8, fn_88316808, u32@0x4, u32@0xc, ts4_if_call_seq_fn_88309DB8_88309438, u32@0x4c */
void ts4_if_get_ts4_if_get_fn_8832BFC0_883168A8_883FF658(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc58[1];
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc5c[1];
    int t1;
    float t2;
    float t3;
    int t5;
    int t8;
    ts4_word t9;
    ts4_word t10;
    int t13;
    ts4_word t14;
    ts4_word t15;

    t1 = ts4_if_get_fn_8832BFC0_883168A8((ts4_word)a1, (ts4_word)(ts4_word)&loc5c[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    if ((int)t1 == 0) {
        t2 = *(float *)((char *)loc50 + 0);
        t3 = *(float *)((char *)loc54 + 0);
        loc58[0] = (ts4_word)0;
        t5 = fn_88316808((ts4_word)a1, (*(float *)((char *)loc5c + 0)), t3, t2, (ts4_word)0);
        if ((int)t5 == 0) {
            t8 = ts4_if_call_seq_fn_88309DB8_88309438((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 12)), (ts4_word)-1, (ts4_word)a1, (ts4_word)1, (ts4_word)a2);
            if ((int)t8 == 0) {
                t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
                t10 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
                t13 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 28))))((ts4_word)t9, (ts4_word)t10);
                if ((int)t13 == 0) {
                    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
                    t15 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
                    ts4_lookup_then_forward_88317468((ts4_word)t15, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t14) + 16)));
                }
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x884F3F40: if_get u32@0x24, u32@0x24, u32@0x3c, u32@0x3c, u32@0x0, u32@0x48 */
void ts4_if_get_u32_off24_884F3F40(ts4_word a0)
{
    int t2;
    ts4_word t4;
    ts4_word t12;

    if ((ts4_word)a0 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        if ((int)t2 == 1) {
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
            if ((ts4_word)t4 != 0) {
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 72))))((ts4_word)t4);
                *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
            }
            ts4_if_call_seq_u32_off4_884F5A80((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)));
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
        if ((ts4_word)t12 != 0) {
            ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t12, (ts4_word)((1636433920) | 3));
            *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
        }
        ts4_if_call_seq_u32_off0_884F5220((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)((1636433920) | 32785));
    }
    return;
}

/* Swing_DLL.xex 0x8856CEA0: if_call_seq u32@0x24, u32@0x24, fn_885651F8, u32@0x2c, fn_885651F8, u32@0x34 */
void ts4_if_call_seq_u32_off24_8856CEA0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;
    ts4_word t17;
    ts4_word t20;
    ts4_word t23;

    if ((ts4_word)a0 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        if ((ts4_word)t2 != 0) {
            fn_885651F8((ts4_word)t2);
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        if ((ts4_word)t5 != 0) {
            fn_885651F8((ts4_word)t5);
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        if ((ts4_word)t8 != 0) {
            fn_885651F8((ts4_word)t8);
        }
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
        if ((ts4_word)t11 != 0) {
            fn_885651F8((ts4_word)t11);
        }
        t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
        if ((ts4_word)t14 != 0) {
            fn_885651F8((ts4_word)t14);
        }
        t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        if ((ts4_word)t17 != 0) {
            fn_885651F8((ts4_word)t17);
        }
        t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
        if ((ts4_word)t20 != 0) {
            fn_885651F8((ts4_word)t20);
        }
        t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
        if ((ts4_word)t23 != (ts4_word)(ts4_word)lbl_8808F798) {
            fn_885651F8((ts4_word)t23);
        }
        fn_885651F8((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x88581C90: if_tail fn_8858B180, ts4_tailcall_MmFreePhysicalMemory_8857B158 */
void ts4_if_tail_fn_8858B180_88581C90(ts4_word a0, ts4_word a1)
{
    if ((int)(a1 & 0x80000000) != 0) {
        if ((ts4_word)a0 == 0) {
            return;
        }
        ts4_tailcall_MmFreePhysicalMemory_8857B158((ts4_word)a0);
        return;
    }
    fn_8858B180((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x88594FF8: if_call_seq fn_88594848, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
void ts4_if_call_seq_fn_88594848_88594FF8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t3;

    if ((ts4_word)a1 == 0) {
        ts4_if_call_seq_fn_88594848_88594940((ts4_word)a0, (ts4_word)a2);
    } else {
        t1 = fn_88594848((ts4_word)a0);
        if ((ts4_word)t1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a2;
            *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
            t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
            if ((ts4_word)t3 != 0) {
                *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t1;
            } else {
                *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
            }
            *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t1;
            *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) + 1);
        }
    }
    return;
}

/* Swing_DLL.xex 0x8859C7A8: if_get ts4_vcall_member_slot0_88598CF8, fn_8859C1C8, u32@-0x58, u32@0x4, u32@0x8, vcall */
void ts4_if_get_ts4_vcall_member_slot0_88598CF8_8859C7A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    ts4_vcall_member_slot0_88598CF8((ts4_word)a0, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)a2 != 0) {
        t2 = fn_8859C1C8((ts4_word)(a0 + -140), (ts4_word)a2);
        if ((int)t2 < 0) {
            t3 = *(ts4_word *)((char *)(ts4_word)(a0) + -88);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 4))) + 8))))((ts4_word)(t3 + 4), (ts4_word)t2);
        }
    }
    return;
}

/* Swing_DLL.xex 0x8859E118: if_call_seq fn_8859D5A8, lbl_88D2F130, fn_88593C30, ts4_if_call_seq_fn_88594848_88594F78, u32@0x0, u32@0x4 */
void ts4_if_call_seq_fn_8859D5A8_8859E118(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;

    t1 = fn_8859D5A8((ts4_word)(a0 + 500));
    if ((int)t1 != 0) {
        t2 = fn_88593C30((ts4_word)(ts4_word)lbl_88D2F130, (ts4_word)12, (ts4_word)((546766848) | 2), (ts4_word)0);
        if ((int)t2 != 0) {
            t3 = ts4_if_call_seq_fn_88594848_88594F78((ts4_word)(a0 + 540), (ts4_word)t2);
            if ((ts4_word)t3 == 0) {
                ts4_pool_free_885B72F0((ts4_word)t2);
            } else {
                *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
                *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 32));
                t7 = fn_8859AD58((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 472)), (ts4_word)0);
                *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t7;
            }
        }
        ts4_pool_free_885B72F0((ts4_word)t1);
    }
    return;
}

/* Swing_DLL.xex 0x885AA5F0: get u32@0x18, memcpy, u32@0x0, u32@0x4, u32@0x8, u32@0x18 */
void ts4_get_u32_off18_885AA5F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    memcpy((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)a1, (ts4_word)12);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)0, (ts4_word)a2, (ts4_word)t6, (ts4_word)((((int)t5 * (int)t4) + 3) << 2));
    return;
}

/* Swing_DLL.xex 0x885B64E8: if_call_seq fn_885A5568, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
void ts4_if_call_seq_fn_885A5568_885B64E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t3;

    if ((ts4_word)a1 == 0) {
        ts4_if_call_seq_fn_885A5568_885B6468((ts4_word)a0, (ts4_word)a2);
    } else {
        t1 = fn_885A5568((ts4_word)a0);
        if ((ts4_word)t1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a2;
            *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
            t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
            if ((ts4_word)t3 != 0) {
                *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t1;
            } else {
                *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)t1;
            }
            *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t1;
            *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 212)) + 1);
        }
    }
    return;
}

/* Swing_DLL.xex 0x885CF390: if_get u32@0xb8, u32@0xc0, u32@0x108, u32@0x0, u32@0x8 */
void ts4_if_get_u32_offb8_885CF390(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 264);
    if ((ts4_word)t3 == 0) {
        return;
    }
    ((void (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3);
    return;
}

/* Swing_DLL.xex 0x889D1D28: if_get u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_889D1D28(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return;
    }
    ((void (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    return;
}
