/* Loader_DLL.xex 0x831A05C0-0x831A072C, executable version 0.0.0.3. */
/* Two sibling request-post thunks: lock the owner, allocate and fill a request, queue it, unlock. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern char lbl_83531690[];
ts4_word fn_8316F128();
ts4_word ts4l_pool_release_8319FD00();
ts4_word ts4_get_u32_off0_831A1230();

/* Loader_DLL.xex 0x831A05C0: if_get u32@0xc, u32@0x0, u32@0x8, vcall, lbl_83531690, fn_8316F128 */
ts4_word ts4_if_get_u32_offc_831A05C0(ts4_word a0, ts4_word a1)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t5;
    ts4_word t7;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)20, (ts4_word)((546766848) | 6), (ts4_word)0);
    if ((int)t5 == 0) {
        p10 = (ts4_word)((2147942400) | 14);
    } else {
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)11;
        *(ts4_word *)((char *)(ts4_word)(t5) + 12) = (ts4_word)(a0 + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 16) = (ts4_word)a1;
        t7 = ts4_get_u32_off0_831A1230((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)t5);
        if ((int)t7 < 0) {
            ts4l_pool_release_8319FD00((ts4_word)t5);
        }
        p10 = (ts4_word)t7;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 20))))((ts4_word)t12);
    return p10;
}

/* Loader_DLL.xex 0x831A0678: if_get u32@0xc, u32@0x0, u32@0x8, vcall, lbl_83531690, fn_8316F128 */
ts4_word ts4_if_get_u32_offc_831A0678(ts4_word a0, ts4_word a1)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t5;
    ts4_word t7;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)20, (ts4_word)((546766848) | 6), (ts4_word)0);
    if ((int)t5 == 0) {
        p10 = (ts4_word)((2147942400) | 14);
    } else {
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)12;
        *(ts4_word *)((char *)(ts4_word)(t5) + 12) = (ts4_word)(a0 + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 16) = (ts4_word)a1;
        t7 = ts4_get_u32_off0_831A1230((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)t5);
        if ((int)t7 < 0) {
            ts4l_pool_release_8319FD00((ts4_word)t5);
        }
        p10 = (ts4_word)t7;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 20))))((ts4_word)t12);
    return p10;
}
