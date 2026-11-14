/* Swing_DLL.xex 0x8861B198-0x8861B238, executable version 0.0.0.3. */
typedef struct Src Src;
typedef struct Dst Dst;
typedef struct SrcVtbl { void *s0; int (*read)(Src *, void *, int); } SrcVtbl;
typedef struct DstVtbl { void *s[4]; void (*write)(Dst *, void *, int); } DstVtbl;
struct Src { SrcVtbl *vt; };
struct Dst { DstVtbl *vt; };
extern unsigned int lbl_88D45B38;
extern void *fn_88613268(unsigned int heap, int size, int align, int a, int b);
extern void ts4_registry_dispatch_888860A0(void *p);

int ts4_copy_stream_8861B198(Dst *dst, Src *src, int chunk)
{
    void *buf = fn_88613268(lbl_88D45B38, chunk, 1, 0, 0);
    int total = 0;
    int n;
    do {
        n = src->vt->read(src, buf, chunk);
        if (n <= 0) {
            break;
        }
        total += n;
        dst->vt->write(dst, buf, n);
    } while (n == chunk);
    ts4_registry_dispatch_888860A0(buf);
    return total;
}
