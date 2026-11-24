/* 0x88954118: For each 12-byte item, joins item name, lbl_880D35C0 and the loader root path into a 256-byte buffer, then calls fn_88950A30 with lbl_880D371C, the name and that path. */
/* Matched on /Oc (agAH). Plain loop; the buffer is 256 bytes (frame 0x190). */
typedef struct Result { int code; int limit; int extra; } Result;
typedef struct Item { const char *name; int a; int b; } Item;
typedef struct ItemVec { Item *begin; Item *end; } ItemVec;
typedef struct Dir { char p0[0x24]; const char *path; } Dir;
typedef struct DirRef { Dir *dir; } DirRef;
typedef struct Loader { char p0[0x538]; DirRef *root; } Loader;
extern const char lbl_880D35C0[];
extern const char lbl_880D371C[];
extern void ts4_concat3_881642B0(char *dst, const char *a, const char *b, const char *c);
extern Result *fn_88950A30(Result *out, const char *what, const char *name, const char *path);
void fn_88954118(Loader *ld, ItemVec *v)
{
    Item *it;
    for (it = v->begin; it != v->end; it++) {
        char path[256];
        Result r;
        ts4_concat3_881642B0(path, it->name, lbl_880D35C0, ld->root->dir->path);
        fn_88950A30(&r, lbl_880D371C, it->name, path);
    }
}
