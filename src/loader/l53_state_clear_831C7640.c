/* Loader_DLL.xex 0x831C7640-0x831C7744, executable version 0.0.0.3. */
/* Zero-initialise a large state record (two memset calls plus explicit field clears and one float default). */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern char lbl_830009F8[];
ts4_word fn_833E3A30();

/* 0x831C7640: call_seq fn_833E3A30, fn_833E3A30, u32@0x78, u32@0x7c, u32@0x84, u32@0x88 */
ts4_word ts4_call_seq_fn_833E3A30_831C7640(ts4_word a0)
{
    ts4_word t2;
    float t3;

    fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)304);
    t2 = fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)120);
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    t3 = *(float *)lbl_830009F8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 128) = t3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 180) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 236) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 248) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 256) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 268) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 288) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 296) = (ts4_word)0;
    return t2;
}
