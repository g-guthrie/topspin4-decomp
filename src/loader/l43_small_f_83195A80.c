/* Loader_DLL.xex 0x83195A80-0x8323A9F0, executable version 0.0.0.3. */
typedef unsigned int u32;
extern char *fn_832A8648(void);
extern void ts4_if_call_seq_u32_off2a88_830AABF0(void *p);
extern void ts4l_barrier_io_830AAC30(void *p);
extern void ts4_fn_831BB260(int a,int b,int c);
extern void fn_8318BD40(void *p);
extern void ts4_tailcall_fn_8340D830_831BB278(void *p);
extern void ts4_fn_83252290(int a,int b,int c);
extern void fn_8323A7F8(void *p);
extern void ts4_tailcall_fn_8340D830_832522A8(void *p);
int ts4l_lcg_step_83195A80(int *p){ int old=p[0]; int s=p[1]*0x19660D+0x3C6EF35F; int t; p[1]=s; t=s>>2; t=(t>>2)+t; old=t-old; p[0]=t; return old; }
int ts4l_lcg_step_8326C1E0(int *p){ int old=p[0]; int s=p[1]*0x19660D+0x3C6EF35F; int t; p[1]=s; t=s>>2; t=(t>>2)+t; old=t-old; p[0]=t; return old; }
void ts4l_notify_833547E0(void){ char *h=fn_832A8648(); if(h){ void *o=*(void**)(h+0xdac); if(o) ts4_if_call_seq_u32_off2a88_830AABF0(o); } }
void ts4l_notify_83354818(void){ char *h=fn_832A8648(); if(h){ void *o=*(void**)(h+0xdac); if(o) ts4l_barrier_io_830AAC30(o); } }
void ts4l_destroy_8318BF38(void *p){ if(p){ ts4_fn_831BB260(2,0,0); fn_8318BD40(p); ts4_tailcall_fn_8340D830_831BB278(p); } }
void ts4l_destroy_8323A9F0(void *p){ if(p){ ts4_fn_83252290(2,0,0); fn_8323A7F8(p); ts4_tailcall_fn_8340D830_832522A8(p); } }
