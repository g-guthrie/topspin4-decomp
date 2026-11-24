/* nearmiss: 3 off; target loads st.p into r30 right after li r3,0; C local variants same 3 off; C++ member + Str RAII puts this in r30 (worse) */
/*
 * DRAFT (not part of the matching build). 0x88774260 (0xA0): base init (fn_8876FBD0), hash the self-relative name
 * at +0x14 into +0x24, copy three words from service 0xFBFC93C6 (+0x34..0x3c) into +0x28..0x30.
 * 3 off with /Oc (also /Ox, LTCG, .cpp): target loads st.p into r30 then `mr r4`, with `li r3,0` first; MSVC loads r4
 * directly and copies to r30 after. Checked with work/army/ME/v.py chk against work/matching-b198.
 */

typedef struct { int rel; } Rel;
typedef struct { char pad[0x14]; Rel name; } Src;
typedef struct { char pad[0x24]; int h; int a,b,c; } Obj;
typedef struct { char pad[0x34]; int a,b,c; } Res;
typedef struct { char *p; unsigned n, cap; } Str;
extern char lbl_880C1320[];
void fn_8876FBD0(Obj *o, Src *s);
void ts4_assign_formatted_text(void *dst, const char *src);
int fn_88608590(int z, char *p);
void ts4_destroy_owned_object(void *p);
void *ts4_find_service(unsigned id);
void f(Obj *o, Src *s){
  Str st; Res *r; const char *n;
  fn_8876FBD0(o, s);
  { Rel *rr=&s->name; if (rr->rel != -1) n=(char*)rr+rr->rel; else n=lbl_880C1320; }
  ts4_assign_formatted_text(&st, n);
  { char *p = st.p;
  o->h = fn_88608590(0, p);
  ts4_destroy_owned_object(p); }
  r = (Res*)ts4_find_service(0xFBFC93C6);
  o->a=r->a; o->b=r->b; o->c=r->c;
}
