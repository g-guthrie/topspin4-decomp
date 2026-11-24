/* C++ retry (agentB, 2026-11-18): real virtuals (exists 17, remove 15, open 13 returning FileHolder by value, query 10, write 4, close 22) and BS as a class with ctor/dtor temporaries: 87 off, same 0x30 hole below the locals (frame 0x1E0 vs 0x210). */
/* 0x886DA840 near miss (87 off, /Oc plain C; most of the diff is a uniform +0x30 stack offset). Dumps every entry's
 * label + localized name to a file (path lbl_880F36E4, deleted first if present; format lbl_880F36F8, kind 0x3583143C -> 1
 * else 2). Target frame 0x210 vs our 0x1E0: 0x30 bytes below the 8-byte file holder at 0x80 that the code never touches.
 * Tried: separate BS locals (layout now matches apart from the offset), C++, LTCG, unused 0x30 locals (dropped); line[0x130] gives the right 0x210 frame but the slack lands above, not at 0x50-0x80 (86 off), so the hole is below the small locals (outgoing-arg area?).
 * Other residue: the entry-range begin/end inline reloads r->offset; the format pointer and hash constants are hoisted. */
typedef unsigned int u32; typedef unsigned char u8;
void *memcpy(void *d, const void *s, unsigned int n);
unsigned int strlen(const char *s);
#pragma intrinsic(memcpy, strlen)
struct BS { char *first; char *last; char *cap; };
typedef struct File File;
typedef struct FileHolder { File *file; int extra; } FileHolder;
struct FileVt { void *s[4]; void (*write)(File *f, const char *buf, u32 len); };
typedef struct Closer Closer;
struct CloserVt { void *s[22]; void (*close)(Closer *c, FileHolder *h); };
struct Closer { struct CloserVt *vt; };
struct File { struct FileVt *vt; Closer *owner; };
typedef struct Fs Fs;
struct FsVt { void *s[13]; void (*open)(FileHolder *out, Fs *fs, struct BS *path, int mode, int flags); void *s14;
    void (*remove)(Fs *fs, struct BS *path); void *s16; u8 (*exists)(Fs *fs, const char *path); };
struct Fs { struct FsVt *vt; };
typedef struct Names Names;
struct NamesVt { void *s[10]; void (*query)(Names *n, u32 key, struct BS *out); };
struct Names { struct NamesVt *vt; };
typedef struct Reg { char _0[0x224]; Fs *fs; char _228[0x10]; Names *names; } Reg;
extern Reg *lbl_88D45B1C;
extern const char lbl_880F36E4[];
extern const char lbl_880F36F8[];
void ts4_assign_formatted_text(struct BS *dst, const char *src);
void ts4_destroy_owned_object(void *p);
void fn_8816D1A8(struct BS *s);
int ts4_format_text(char *dst, u32 size, const char *fmt, ...);
typedef struct Entry { char _0[0x1C]; u32 kind; char _20[0x64]; u32 name_key; const char *label; } Entry;
typedef struct EntryRange { int offset; int count; } EntryRange;
typedef struct Db { char _0[0x50]; EntryRange entries; } Db;
typedef struct Data { char _0[0xC]; Db *db; } Data;
typedef struct Game { char _0[0x18]; Data *data; } Game;
typedef struct Dumper { char _0[0x28]; Game *game; } Dumper;
static __inline Entry *er_begin(EntryRange *r) { Entry *p = 0; if (r->offset != -1) p = (Entry *)((char *)r + r->offset); return p; }
static __inline Entry *er_end(EntryRange *r) { Entry *p = 0; if (r->offset != -1) p = (Entry *)((char *)r + (r->count * sizeof(Entry) + r->offset)); return p; }
void ts4_dump_entry_labels_886DA840(Dumper *self)
{
    struct BS name;
    FileHolder fh;
    char path[14];
    struct BS del_path;
    struct BS open_path;
    char line[0x100];
    memcpy(path, lbl_880F36E4, sizeof(path));
    if (lbl_88D45B1C->fs->vt->exists(lbl_88D45B1C->fs, path)) {
        ts4_assign_formatted_text(&del_path, path);
        lbl_88D45B1C->fs->vt->remove(lbl_88D45B1C->fs, &del_path);
        ts4_destroy_owned_object(del_path.first);
    }
    {
        ts4_assign_formatted_text(&open_path, path);
        lbl_88D45B1C->fs->vt->open(&fh, lbl_88D45B1C->fs, &open_path, 2, 0);
        ts4_destroy_owned_object(open_path.first);
    }
    if (fh.file) {
        EntryRange *r = &self->game->data->db->entries;
        Entry *end = er_end(r);
        Entry *e;
        for (e = er_begin(r); e != end; e++) {
            if (e->label) {
                u32 kind = e->kind;
                fn_8816D1A8(&name);
                lbl_88D45B1C->names->vt->query(lbl_88D45B1C->names, e->name_key, &name);
                ts4_format_text(line, sizeof(line), lbl_880F36F8, e->label, name.first, kind == 0x3583143Cu ? 1 : 2);
                fh.file->vt->write(fh.file, line, strlen(line));
                ts4_destroy_owned_object(name.first);
            }
        }
        fh.file->owner->vt->close(fh.file->owner, &fh);
    }
}
