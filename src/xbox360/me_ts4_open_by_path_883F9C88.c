/* 0x883F9C88: splits a path at its last '/', opens the directory through vtable slot 2 and the file through the directory's slot 8 (0x25 bad args or too long, 0x5b no separator); fn_88329680 taken as a strcpy */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Dir Dir;
typedef struct DirVt { void *f[8]; int (*open)(Dir *d, const char *name, int mode, void **out); } DirVt;
struct Dir { DirVt *vt; };
typedef struct Fs Fs;
typedef struct FsVt { void *f0, *f1; int (*open_dir)(Fs *fs, const char *path, int flags, Dir **out); } FsVt;
struct Fs { FsVt *vt; };

int ts4_strlen_88329658(const char *s);
char *fn_88329680(char *dst, const char *src);

int fn_883F9C88(Fs *fs, const char *path, int mode, void **out)
{
    Dir *dir;
    char buf[0x400];
    int len, i, r;
    if (!path || !out)
        return 0x25;
    *out = 0;
    len = ts4_strlen_88329658(path);
    if (len > 0x3ff)
        return 0x25;
    fn_88329680(buf, path);
    for (i = len - 1; i; i--)
        if (buf[i] == '/')
            break;
    if (!i)
        return 0x5b;
    buf[i] = 0;
    r = fs->vt->open_dir(fs, buf, 0, &dir);
    if (r)
        return r;
    return dir->vt->open(dir, buf + i + 1, mode, out);
}
