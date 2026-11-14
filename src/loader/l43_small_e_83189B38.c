/* Loader_DLL.xex 0x83189B38-0x835160C0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Ts4lNode { void *data; struct Ts4lNode *a; struct Ts4lNode *b; } Ts4lNode;
extern int ts4l_import_XMsgSystemProcessCall_83517028(int a,int b,void *c,int d);
extern void ts4l_query_frequency_8340BD08(u64 *t);
void ts4l_msg_fa_833DFE80(int a){ ts4l_import_XMsgSystemProcessCall_83517028(0xfa,0x70003,&a,4); }
void ts4l_msg_fa_833DFF08(int a){ ts4l_import_XMsgSystemProcessCall_83517028(0xfa,0x70005,&a,4); }
void ts4l_msg_fa_833DFF40(int a){ ts4l_import_XMsgSystemProcessCall_83517028(0xfa,0x70006,&a,4); }
void ts4l_msg_fa_833DFF78(int a){ ts4l_import_XMsgSystemProcessCall_83517028(0xfa,0x70007,&a,4); }
