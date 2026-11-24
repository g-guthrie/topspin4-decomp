/* Loader_DLL.xex 0x831C13A0-0x83397B48, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u16 *lbl_8352CD50;
int ts4l_range_before_831C13A0(char *p){ if(*(int*)(*(char**)(p+8)+0x2c0)!=0){ return (u32)(*(u32*)(p+0x1c)+*(u32*)(p+0x20)) < (u32)(*(u32*)(p+0x14)+*(u32*)(p+0x18)); } return 0; }
int ts4l_range_before_832594B0(char *p){ if(*(int*)(*(char**)(p+8)+0x2c0)!=0){ return (u32)(*(u32*)(p+0x1c)+*(u32*)(p+0x20)) < (u32)(*(u32*)(p+0x14)+*(u32*)(p+0x18)); } return 0; }
int ts4l_interp_831C8B48(char *p,int x,int i){ int *a=(*(int***)(p+0x108))[i]; int *b=(*(int***)(p+0x104))[i]; int s=(*(int**)(p+0x128))[i]; int hi=x>>13; int lo=x&0x1fff; return ((a[hi]*lo)>>s)+b[hi]; }
int ts4l_interp_831C8B88(char *p,int x,int i){ int *a=(*(int***)(p+0x108))[i]; int *b=(*(int***)(p+0x104))[i]; int s=(*(int**)(p+0x128))[i]; int hi=x>>13; int lo=x&0x1fff; return ((a[hi]*lo)>>s)+b[hi]; }
int ts4l_interp_83263690(char *p,int x,int i){ int *a=(*(int***)(p+0x108))[i]; int *b=(*(int***)(p+0x104))[i]; int s=(*(int**)(p+0x128))[i]; int hi=x>>13; int lo=x&0x1fff; return ((a[hi]*lo)>>s)+b[hi]; }
int ts4l_interp_832636D0(char *p,int x,int i){ int *a=(*(int***)(p+0x108))[i]; int *b=(*(int***)(p+0x104))[i]; int s=(*(int**)(p+0x128))[i]; int hi=x>>13; int lo=x&0x1fff; return ((a[hi]*lo)>>s)+b[hi]; }
void ts4l_fill_info_8319CB10(char *h,int *o){ o[0]=*(int*)(h+4); o[1]=*(u16*)(h+2); o[2]=*(int*)(h+0x10); o[3]=*(u16*)(h+0xe); o[4]=(*(u16*)(h+0xe)+7)/8; o[5]=0; }
void ts4l_fill_info_83242E18(char *h,int *o){ o[0]=*(int*)(h+4); o[1]=*(u16*)(h+2); o[2]=*(int*)(h+0x10); o[3]=*(u16*)(h+0xe); o[4]=(*(u16*)(h+0xe)+7)/8; o[5]=0; }
int ts4l_median3_83397B48(int a,int b,int c){ if(a>b){ if(b>c) return b; if(a>c) return c; return a; } if(a>c) return a; if(b>c) return c; return b; }
