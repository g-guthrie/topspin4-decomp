/* 0x8898FE30: fread-style read through stream vt slot 1. On a short read, reports error 1 with a copy of the file name, closes the file and returns 0. Returns 0 with no stream, 1 on success. */
/* Matched on /Oc (agAH). The error path goes inside an != block. */
typedef struct Str { char *begin; char *end; char *cap; } Str;
typedef struct Stream Stream;
typedef struct StreamVt { void *s[1]; int (*read)(Stream *, void *, int); } StreamVt;
struct Stream { StreamVt *vt; };
typedef struct File { int p0; Str name; char p10[0xc]; Stream *stream; } File;
extern Str *ts4_if_call_seq_u32_off0_88159A58(Str *out, const Str *src);
extern void ts4_if_call_seq_lbl_88D45BB8_8898E8B0(int code, Str *name);
extern void ts4_if_get_u32_off1c_8898EDC8(File *f);
int fn_8898FE30(File *f, void *buf, int size, int count)
{
    Stream *s = f->stream;
    if (s == 0)
        return 0;
    if (s->vt->read(s, buf, size * count) / size != count) {
        Str tmp;
        ts4_if_call_seq_lbl_88D45BB8_8898E8B0(1, ts4_if_call_seq_u32_off0_88159A58(&tmp, &f->name));
        ts4_if_get_u32_off1c_8898EDC8(f);
        return 0;
    }
    return 1;
}
