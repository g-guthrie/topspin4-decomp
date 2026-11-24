/* PR3 DRAFT: LoadArchive, the mount entry point (not compiled into the build).
 *
 * 0x88626AE8 (0x1ac) ts4_load_archive_88626AE8 - 5 instructions differ: the path load for the archive's load
 *   call is scheduled before its vtable load, and the parent test is scheduled after `mr r3` (both scheduling).
 *   Tried: result variable kept in a saved register (needed), the open call written in each arm (needed), helper
 *   for the path, parent tests as u32. fn_equiv: EQUIVALENT, 174 valid trials, 100% coverage.
 *
 * What it does (CArchiveLoader slot 10, also called directly by the script binding LoadArchive 0x88785E38, the
 * DLC and PlayerCreator loaders): key = given hash or crc of the archive name (fn_88608590);
 * svc = ts4_find_service(mount_id); fail if absent or if svc already holds key (slot 6).
 * fs = engine (lbl_88D45B1C) +0x220 when alt_fs, else +0x224 (the root file systems).
 * Resolve "<name>", "<name>.arc" or "<name>.oarc" (0x886232C8), open it on fs with mode 0x8021 (raw, prio 1) or
 * 0x21 (prio 0); create the archive object for the path (0x88623190: PackArchive or OpenArchive), set its key
 * (fn_88617788), +0x24 alt_fs, +0x25 track_pos, +0x28 mount id, call its Load (slot 23 = 0x886217C0 for packs)
 * with (stream, path, raw), attach it to svc (under parent with fn_8861A7C8, else ts4_if_call_seq_u32_off8_8817E578)
 * and set +0x20 enabled. Returns the archive or 0.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-parameter" /* self: kept for the real signature */
#define __forceinline inline
#define __inline inline
#endif

typedef struct Stream Stream;
typedef struct FileSystem FileSystem;
typedef struct FsVt {
    void *s[10];
    Stream **(*open)(Stream **, FileSystem *, const char *, u32, u32);
    void *s11[12];
    void (*load)(FileSystem *, Stream *, const char *, u8);
} FsVt;
struct FileSystem { FsVt *vt; char pad04[0x1c]; u8 enabled; char pad21[3]; u8 alt_fs; u8 track_pos; char pad26[2]; u32 mount_id; };
typedef struct Service Service;
typedef struct ServiceVt { void *s[6]; void *(*find)(Service *, u32 *); } ServiceVt;
struct Service { ServiceVt *vt; };
typedef struct Engine { char pad[0x220]; FileSystem *fs220; FileSystem *fs224; } Engine;
typedef struct SBuf { char *p; u32 w[0x41]; } SBuf;

extern Engine *lbl_88D45B1C;
u32 fn_88608590(u32 seed, const char *s);
Service *ts4_find_service(u32 id);
void ts4_sbuf_ctor_init_88281740(SBuf *s);
u8 fn_886232C8(const char *name, FileSystem *fs, SBuf *out);
FileSystem *fn_88623190(const char *path, FileSystem *fs);
void fn_88617788(FileSystem *o, u32 key);
void fn_8861A7C8(Service *svc, void *parent, u8 flag, FileSystem *child, u32 arg);
void ts4_if_call_seq_u32_off8_8817E578(Service *svc, FileSystem *child, u32 arg);

FileSystem *ts4_load_archive_88626AE8(void *self, const char *name, u32 mount_id, u32 key, u8 track_pos, u8 alt_fs,
                                      u8 raw, u32 arg8, u8 enabled, void *parent, u8 parent_flag)
{
    const u32 *pk;
    u32 k;
    Service *svc;
    FileSystem *res;
    if (key == 0) { k = fn_88608590(0, name); pk = &k; } else pk = &key;
    k = *pk;
    res = 0;
    svc = ts4_find_service(mount_id);
    if (svc != 0 && svc->vt->find(svc, &k) == 0) {
        FileSystem *fs;
        SBuf path;
        Stream *s;
        Stream *tmp;
        if (alt_fs) fs = lbl_88D45B1C->fs220; else fs = lbl_88D45B1C->fs224;
        ts4_sbuf_ctor_init_88281740(&path);
        fn_886232C8(name, fs, &path);
        if (raw) s = *fs->vt->open(&tmp, fs, path.p, 0x8021, 1);
        else s = *fs->vt->open(&tmp, fs, path.p, 0x21, 0);
        if (s != 0) {
            res = fn_88623190(path.p, fs);
            fn_88617788(res, k);
            res->alt_fs = alt_fs;
            res->track_pos = track_pos;
            res->mount_id = mount_id;
            res->vt->load(res, s, path.p, raw);
            if (parent != 0) fn_8861A7C8(svc, parent, parent_flag, res, arg8);
            else ts4_if_call_seq_u32_off8_8817E578(svc, res, arg8);
            res->enabled = enabled;
        }
    }
    return res;
}
