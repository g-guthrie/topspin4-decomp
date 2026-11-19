/* Swing_DLL.xex 0x881731B0: Shuts down and deletes every child in the pointer vector at +0x2c, clears the vector (cw4 memmove copy idiom), and on the last release calls fn_8890CBD0 on the app's +0x114 object.
 * /Oc. Loop end re-read each pass; the clear is 'v->last = copy(v->last, v->last, v->first)' with the fn_88562DC0 memmove. */
typedef struct Child Child;
typedef struct ChildVt {
    void (*destroy)(Child *, int);
    void *s1, *s2;
    void (*shutdown)(Child *);
} ChildVt;
struct Child { const ChildVt *vt; };
typedef struct ChildVec { Child **first; Child **last; } ChildVec;
typedef struct Manager { unsigned char pad[0x2c]; ChildVec children; } Manager;
typedef struct App { unsigned char pad[0x114]; void *audio; } App;

extern int lbl_88D49364;
extern App *lbl_88D45A4C;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void fn_8890CBD0(void *p);

static __forceinline Child **copy_ptrs(Child **first, Child **last, Child **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Child **)fn_88562DC0(dest, first, n);
        return (Child **)((char *)dest + n);
    }
}

void fn_881731B0(Manager *m)
{
    Child **it;
    ChildVec *v = &m->children;
    for (it = m->children.first; it != m->children.last; it++) {
        (*it)->vt->shutdown(*it);
        if (*it) (*it)->vt->destroy(*it, 1);
    }
    v->last = copy_ptrs(v->last, v->last, v->first);
    if (--lbl_88D49364 == 0) fn_8890CBD0(lbl_88D45A4C->audio);
}
