/* Swing_DLL.xex 0x8840F188-0x8840F21C, executable version 0.0.0.3. */
/* Calls through a function-pointer table indexed by the first argument. */
typedef int (*ts4_handler1)(int);
typedef int (*ts4_handler2)(int, int);
extern ts4_handler1 lbl_88B3BB88[];
extern ts4_handler2 lbl_88B3BB70[];
int ts4_dispatch_table1_8840F200(int index, int a) { return lbl_88B3BB88[index](a); }
int ts4_dispatch_table2_8840F188(int index, int a, int b) { return lbl_88B3BB70[index](a, b); }
