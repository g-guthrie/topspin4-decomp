/* PR3 DRAFT: CFileSystemComposite::Open (not compiled into the build).
 *
 * 0x8860E950 (0x9c) ts4_fs_composite_open_8860E950 - 7 instructions differ: path and iterator swap saved
 *   registers (r30/r31). Tried: end-first loads, vector sub-struct with begin helper, a fs local, a path copy.
 *   fn_equiv: EQUIVALENT, 159 valid trials, 100% coverage.
 *
 * What it does: vtable 0x880F7B80 slot 10. If path is non-null and non-empty, walk the child file systems
 * (vector of pointers at +0x24..+0x28) in order; for each enabled child (+0x20 byte) call its Open (slot 10,
 * same signature: out, fs, path, mode, arg) and stop at the first non-null stream. *out = stream or 0.
 * This is the search order across mounted archives, the loose-file system and the disc.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifndef _MSC_VER
#define __forceinline inline
#define __inline inline
#endif
typedef struct IoRequest {
    int status; u8 async; int op; char path[0x200]; void *result; void *event;
    u32 f214; u32 arg; u32 f21c; u32 f220; u32 f224; u32 mode; void *fs; u32 f230; u8 bresult; u32 f238;
} IoRequest;
void fn_88630C90(void *queue, IoRequest *req);


typedef struct FileSystem FileSystem;
typedef struct FsVt { void *s[10]; void **(*open)(void **, FileSystem *, const char *, u32, u32); } FsVt;
struct FileSystem { FsVt *vt; char pad[0x1c]; u8 enabled; };
typedef struct FsComposite { char pad[0x24]; FileSystem **begin; FileSystem **end; } FsComposite;

void **ts4_fs_composite_open_8860E950(void **out, FsComposite *c, const char *path, u32 a, u32 b)
{
    void *s = 0;
    if (path != 0 && *path != 0) {
        FileSystem **end = c->end;
        FileSystem **it;
        for (it = c->begin; end != it; it++) {
            if ((*it)->enabled) {
                void *tmp;
                s = *(*it)->vt->open(&tmp, *it, path, a, b);
                if (s != 0) break;
            }
        }
    }
    *out = s;
    return out;
}
