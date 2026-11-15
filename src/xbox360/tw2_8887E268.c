/* Twin of 0x8887E1A8 (ts4_remove_entry_by_key_8887E1A8 in src/xbox360/cx32_game_a.c). */
typedef unsigned int u32;
typedef struct CxDel { void (**vt)(struct CxDel *, int); } CxDel;
typedef struct CxItem { CxDel d; int f4; u32 f8; } CxItem;
typedef struct CxVec { CxItem **begin; CxItem **end; } CxVec;
typedef struct CxPtrVec { int pad0; CxVec v; } CxPtrVec;
extern void *fn_88562DC0(void *dst, void *src, int n);
u32 fn_88608590(int a, u32 b);
void fn_8887CB88(void *p);

void ts4_remove_entry_by_key_8887E268(CxPtrVec *o, u32 *key)
{
    u32 id = fn_88608590(0, *key);
    CxVec *v = &o->v;
    CxItem **p;
    for (p = v->begin; p != o->v.end; p++) {
        CxItem *it = *p;
        if ((u32)it->f4 == id) {
            fn_8887CB88(it);
            if (*p) (*p)->d.vt[0](&(*p)->d, 1);
            {
                CxItem **src = p + 1;
                if (src != v->end)
                    fn_88562DC0(p, src, (char *)v->end - (char *)src);
            }
            v->end--;
            return;
        }
    }
}
