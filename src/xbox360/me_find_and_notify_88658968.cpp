/* 0x88658968 (hand match). */
typedef unsigned char u8;
extern "C" void ts4_assign_formatted_text(void *object, const char *text);
extern "C" void ts4_destroy_owned_object(void *p);
extern "C" const char lbl_880F5098[];
struct Text { void *p; int q[2]; };
struct Handle;
struct Target { virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3(); virtual void t4(); virtual void t5(); virtual void t6(); virtual void t7(); virtual void t8(); virtual void t9(); virtual void t10(); virtual void t11(); virtual void t12(); virtual void t13(); virtual void t14(); virtual void t15(); virtual void t16(); virtual void t17(); virtual void t18(); virtual void t19(); virtual void t20(); virtual void t21(); virtual void f58(Handle *); };
struct Entry { void *p0; Target *f4; };
struct Handle { Entry *p; int x; };
struct Mgr { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual Handle f34(Text *, int, int); virtual void f38(); virtual void f3c(Text *); };
struct Root { char p[0x220]; Mgr *f220; };
extern "C" Root *lbl_88D45B1C;
struct Self { u8 b0; };
Self *ts4_find_and_notify_88658968(Self *s){ Mgr *m = lbl_88D45B1C->f220; Text t; 
 ts4_assign_formatted_text(&t, lbl_880F5098);
 Handle h = m->f34(&t, 2, 0);
 if (h.p != 0) { s->b0 = 1; h.p->f4->f58(&h); m->f3c(&t); } else { s->b0 = 0; }
 ts4_destroy_owned_object(t.p);
 return s; }
