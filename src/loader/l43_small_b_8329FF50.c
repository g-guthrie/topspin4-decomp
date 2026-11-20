/* Loader_DLL.xex 0x831C0FC0-0x83464B80, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
extern int ts4_if_call_seq_NtSetEvent_8340AED8(void *h);
extern void *fn_833E3AD0(void *d, const void *s, u32 n);
extern int lbl_8303CD78[];
void ts4l_signal_slot_8329FF50(char *p, int i){ void *h=((void**)p)[i+0xe6]; if(h) ts4_if_call_seq_NtSetEvent_8340AED8(h); }
void ts4l_sub_bias_83393AB0(short *p, int n){ int i; for(i=0;i<n;i++) p[i]=p[i]-0x80; }
void ts4l_zero7_833D5030(u32 *p){ int i; for(i=0;i<7;i++) p[i]=0; }
void ts4l_zero7_8327FA70(u64 *p, u32 v){ u64 *q=p; int i=7; while(i--) *q++=0; ((u32*)p)[0xb]=v; }
void ts4l_store_be24_832548D0(int a, u8 *base, int unused, int i){ u8 *o=base+i*3; int b=a>>8; int c=b>>8; (void)unused; o[2]=(u8)a; o[1]=(u8)b; o[0]=(u8)c; }
int ts4l_scale_table_8329A338(int a, u32 b){ return (lbl_8303CD78[b&0x3f]*a+0x20000)>>18; }
void *ts4l_copy_back_831C0FC0(char *d, char *s, int n){ int m=(n/2)*4; return fn_833E3AD0(d-m, s+m, m); }
