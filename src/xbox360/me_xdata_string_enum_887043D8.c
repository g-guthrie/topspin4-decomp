/* 0x887043D8: resolve the xdata view (type hash 0x7009C65D) of a handle, read its string value
 * through vtable slot 0x50 and map it onto an enum stored at +0x78; unknown strings leave the field unchanged. */
typedef unsigned int u32; typedef unsigned char u8;
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
typedef struct XNode { void **vt; } XNode;
/* 12-byte reference record filled by ts4_handle_forward_88150770 (frame size needs the third word). */
typedef struct { XNode *node; u32 offset; u32 extra; } XRef;
typedef struct { u32 a, b, c, d; } Handle16;
void ts4_handle_forward_88150770(XRef *out, Handle16 *h, u32 *type_hash);
extern const char lbl_880F0124[];
extern const char lbl_880F012C[];
extern const char lbl_880F0138[];
typedef const char *(*XGetStr)(XNode *, XRef *, u32, int);
static __forceinline u8 xref_invalid(XRef *r) { return r->node == 0 || r->offset == 0xFFFFF; }
typedef struct { char pad[0x78]; int mode; } Owner;
void fn_887043D8(Owner *o, Handle16 *handle) {
  u32 k = 0x7009C65Du; XRef r; const char *s; int m;
  ts4_handle_forward_88150770(&r, handle, &k);
  if (xref_invalid(&r)) return;
  s = ((XGetStr)r.node->vt[0x50/4])(r.node, &r, r.offset, 1);
  if (strcmp(s, lbl_880F0124) == 0) m = 0;
  else if (strcmp(s, lbl_880F012C) == 0) m = 37;
  else if (strcmp(s, lbl_880F0138) == 0) m = 1;
  else return;
  o->mode = m;
}
