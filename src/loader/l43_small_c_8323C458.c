/* Loader_DLL.xex 0x8323C458-0x8335D218, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
int ts4l_gcd_sub_8323C458(int a,int b){ while(a>0){ if(a<b){ int t=a; a=b; b=t; } a-=b; } return b; }
u32 ts4l_pop_slot_83287990(char *p){ u32 n=*(u32*)(p+8); u32 v; if(n==0) return 0; n--; *(u32*)(p+8)=n; v=(*(u32**)p)[n]; (*(u32**)p)[n]=0; return v; }
void ts4l_set_abs_8335D218(int *p,int a,int b,int c,int d){ if(b<0) b=-b; if(d<0) d=-d; p[6]=a; p[7]=b; p[8]=c; p[9]=d; }
void ts4l_scale_words_8326C1B8(int *p,int n,short k){ int i; for(i=0;i<n;i++) p[i]*=k; }
