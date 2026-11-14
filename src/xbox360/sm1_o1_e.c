/* SM1 /O1 batch e. */
typedef unsigned int u32;

/* Swing_DLL.xex 0x883D1D68: one-at-a-time style hash of a byte buffer */
u32 ts4_hash_bytes_883D1D68(const unsigned char *p, u32 n) { u32 h = 0; u32 i; for (i = 0; i < n; i++) { h = (h + p[i]); h += h << 10; h ^= h >> 6; } h += h << 3; h ^= h >> 11; h += h << 15; return h; }

/* 0x882F07B8: report through the shared helper with the default descriptor and mark the object */
extern int ts4_if_call_seq_fn_882EFE60_882F0400(void *, void *, int, int);
extern char lbl_880260D0;
typedef struct Ts4Flagged558 { char pad[0x558]; u32 flags; } Ts4Flagged558;
void ts4_report_default_and_flag_882F07B8(Ts4Flagged558 *t, int a, int b) { ts4_if_call_seq_fn_882EFE60_882F0400(t, &lbl_880260D0, a, b); t->flags |= 4; }
