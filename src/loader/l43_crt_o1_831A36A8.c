/* Loader_DLL.xex 0x831A36A8-0x833F5438, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern int fn_833FA6D0(void *f);
typedef struct { u8 *ptr; int cnt; } Ts4lFile;
u16 ts4l_popcount16_831A36A8(u32 x){ u16 n=0; while(x){ n++; x&=x-1; } return n; }
int ts4l_getc_833EB3C8(Ts4lFile *f){ return --f->cnt>=0 ? 0xff & *f->ptr++ : fn_833FA6D0(f); }
u32 ts4l_wcsnlen_833F5438(u16 *s,u32 n){ u32 i=0; while(i<n && *s){ i++; s++; } return i; }
int ts4l_getc_833EC780(Ts4lFile *f){ return --f->cnt>=0 ? 0xff & *f->ptr++ : fn_833FA6D0(f); }
