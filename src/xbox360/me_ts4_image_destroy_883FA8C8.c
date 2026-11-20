/* Swing_DLL.xex 0x883FA8C8: frees the image pixels (+0x14) and, for kind 2, the palette (+0x1C) through the given allocator (vtable
 * slot 2) or the global heap, then frees the image itself (file lbl_8803A06C, lines 0x44/0x49/0x4C). agAE: /O1. */
typedef struct Globals { char pad[4]; void *heap; } Globals;
extern Globals *lbl_88B3302C;
extern const char lbl_8803A06C[];
void fn_88315F10(void *heap, void *buf, const char *file, int line);
typedef struct Allocator Allocator;
typedef struct AllocatorVt { void *slots[2]; void (*free)(Allocator *a, void *p, const char *file, int line); } AllocatorVt;
struct Allocator { AllocatorVt *vt; };
typedef struct Image { char pad[0x14]; void *pixels; int kind; void *palette; } Image;
static __inline void heap_free(Allocator *a, void *p, const char *file, int line)
{
    if (a) a->vt->free(a, p, file, line);
    else fn_88315F10(lbl_88B3302C->heap, p, file, line);
}
int fn_883FA8C8(Image *img, Allocator *a)
{
    if (img->pixels) heap_free(a, img->pixels, lbl_8803A06C, 0x44);
    if (img->kind == 2 && img->palette) heap_free(a, img->palette, lbl_8803A06C, 0x49);
    fn_88315F10(lbl_88B3302C->heap, img, lbl_8803A06C, 0x4c);
    return 0;
}
