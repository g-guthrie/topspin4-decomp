/* Loader_DLL.xex 0x83456300-0x83456398, 0x83456398-0x83456430 (libjpeg backing-store file read/write), executable version 0.0.0.3. */
typedef unsigned long u32;
struct Ts4lErr;
struct Ts4lCinfo;
struct Ts4lErrMgr {
    void (*error_exit)(Ts4lCinfo *c);
    void *emit;
    u32 pad[3];
    int msg_code;
    int parm0;
};
struct Ts4lCinfo { Ts4lErrMgr *err; };
struct Ts4lBackFile { u32 a; u32 b; u32 c; void *file; };
extern "C" int fn_8346B460(void *file, u32 off, u32 whence);
extern "C" u32 ts4_tailcall_fn_8346B268_8346B378(void *buf, u32 sz, u32 n, void *file);
extern "C" u32 fn_833E7D50(void *buf, u32 sz, u32 n, void *file);
extern "C" void ts4l_bf_read_83456300(Ts4lCinfo *c, Ts4lBackFile *f, void *buf, u32 off, u32 n)
{
    if (fn_8346B460(f->file, off, 0)) { c->err->msg_code = 0x41; c->err->error_exit(c); }
    if (ts4_tailcall_fn_8346B268_8346B378(buf, 1, n, f->file) != n) { c->err->msg_code = 0x40; c->err->error_exit(c); }
}
extern "C" void ts4l_bf_write_83456398(Ts4lCinfo *c, Ts4lBackFile *f, void *buf, u32 off, u32 n)
{
    if (fn_8346B460(f->file, off, 0)) { c->err->msg_code = 0x41; c->err->error_exit(c); }
    if (fn_833E7D50(buf, 1, n, f->file) != n) { c->err->msg_code = 0x42; c->err->error_exit(c); }
}
