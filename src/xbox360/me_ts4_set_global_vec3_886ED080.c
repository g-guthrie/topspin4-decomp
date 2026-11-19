/* Swing_DLL.xex 0x886ED080: store a by-value 3-word position at global+0x10+0xb8 */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
/* Stores a 3-word position (passed by value) into the global object reached through lbl_88D45AD4. */
typedef struct { unsigned w[3]; } V3;
extern char *lbl_88D45AD4;
typedef struct { char pad[0xb8]; V3 pos; } Inner_886ED080;
static __forceinline void ts4_setpos_886ED080(Inner_886ED080 *s, V3 v) { s->pos = v; }
void fn_886ED080(V3 v)
{
    ts4_setpos_886ED080((Inner_886ED080 *)(lbl_88D45AD4 + 0x10), v);
}
