/* 0x883D1488: returns 0x1F unless +0x809C is set; frees the old name at +0x20 (lbl_88B3302C heap, file lbl_880391A8, line 0x43B) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); then stores a duplicate of name (0x2C on allocation failure). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_880391A8[];
typedef struct T { char pad[0x20]; char *name; char pad2[0x809c - 0x24]; void *ready; } T;
void fn_88315F10(void *heap, void *p, const char *file, int line);
int ts4_strlen_88329658(const char *s);
char *fn_883299F0(const char *s);
int ts4_set_name_883D1488(T *t, const char *name)
{
    if (!t->ready)
        return 0x1f;
    if (t->name) {
        fn_88315F10(lbl_88B3302C->heap, t->name, lbl_880391A8, 0x43b);
        t->name = 0;
    }
    if (name) {
        /* The target really calls strlen twice and drops the second result. */
        if (ts4_strlen_88329658(name))
            ts4_strlen_88329658(name);
        t->name = fn_883299F0(name);
        return t->name ? 0 : 0x2c;
    }
    return 0;
}
