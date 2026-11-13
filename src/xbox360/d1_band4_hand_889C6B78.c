/* Swing_DLL.xex 0x889C6B78-0x889C6BA4, executable version 0.0.0.3. */

extern void fn_8864DFF0(void *);
extern void fn_888860A0(void *);
extern int ts4_if_call_seq_u32_off44_8864BB40(void *);
extern int ts4_tailcall_fn_88582F30_8857A128(void *, int);
extern void fn_889C67F0(void *, float *);
extern void fn_8822D3D0(void);
extern void fn_88563470(void (*)(void));
extern void ts4_tailcall_fn_88224B38_88AFF3D0(void);

typedef struct Vec28 { char pad[0x28]; char **begin; char **end; } Vec28;
void ts4_copy_float_call_889C6B78(void *self, float *p)
{
    float v = *p;
    fn_889C67F0(self, &v);
}

typedef struct Node6FE0 { int a; int key; } Node6FE0;
typedef struct ByteBuf { int size; } ByteBuf;
typedef struct ByteReader { ByteBuf *buf; int pad; int pos; } ByteReader;
typedef struct Rec14 { int a; int zero; int b; int c; int d; } Rec14;
typedef struct Writer14 { Rec14 *rec; int pad; int len; } Writer14;
