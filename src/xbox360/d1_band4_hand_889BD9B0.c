/* Swing_DLL.xex 0x889BD9B0-0x889C0DBC, executable version 0.0.0.3. */

extern int ts4_if_call_seq_u32_off44_8864BB40(void *);
extern int ts4_tailcall_fn_88582F30_8857A128(void *, int);
typedef struct Vec28 { char pad[0x28]; char **begin; char **end; } Vec28;
void ts4_clear_flags_889C0D90(Vec28 *v)
{
    char **end = v->end;
    char **it = v->begin;
    if (it != end) {
        do {
            char *o = *it++;
            o[0x530] = 0;
        } while (it != end);
    }
}
int ts4_wait_889BD9B0(void ***p)
{
    return ts4_tailcall_fn_88582F30_8857A128(**p, -1) ? -1 : 0;
}
typedef struct Node6FE0 { int a; int key; } Node6FE0;
typedef struct ByteBuf { int size; } ByteBuf;
typedef struct ByteReader { ByteBuf *buf; int pad; int pos; } ByteReader;
