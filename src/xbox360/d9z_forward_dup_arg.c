/* Swing_DLL.xex 0x88520F00-0x885248B0, executable version 0.0.0.3. */
/* Wrappers that drop the first argument and forward the rest (float params skip GPR slots). */
extern void fn_8852CB30(int a, float x, float y, int e);
void ts4_forward_dup_arg_88520F00(int a, int b, float x, float y, int e) { (void)a; fn_8852CB30(b, x, y, e); }
void ts4_forward_dup_arg_88521700(int a, int b, float x, float y, int e) { (void)a; fn_8852CB30(b, x, y, e); }
void ts4_forward_dup_arg_885248B0(int a, int b, float x, float y, int e) { (void)a; fn_8852CB30(b, x, y, e); }
