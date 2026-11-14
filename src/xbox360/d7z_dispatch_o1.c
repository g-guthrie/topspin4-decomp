/* Swing_DLL.xex 0x885E40C8-0x885E40E4, executable version 0.0.0.3. */
/* Calls through the handler field of a 12-byte table entry; needs /O1. */
typedef int (*ts4_handler1)(int);
typedef struct ts4_handler_entry { int a, b; ts4_handler1 handler; } ts4_handler_entry;
extern ts4_handler_entry lbl_880C02B8[];
int ts4_dispatch_entry_handler_885E40C8(int arg, int index) { return lbl_880C02B8[index].handler(arg); }
