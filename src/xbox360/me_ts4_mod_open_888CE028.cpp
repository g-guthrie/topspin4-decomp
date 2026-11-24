
typedef unsigned int u32;
struct Mod {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
  virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
  virtual void open(const char *name, int a, int b, int c, int d, int e);
  virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
  virtual u32 query(int a);
  char pad[0x50]; u32 handle;
};
extern "C" {
extern Mod *lbl_88D45908;
extern const char lbl_880D7B28[];
extern void fn_88617788(void *reg, u32 hash);
void fn_888CE028(void)
{
    Mod *m = lbl_88D45908;
    fn_88617788(m, 0x57666C4D);
    m->open(lbl_880D7B28, 0, 0, 0, 0, 0);
    m->handle = m->query(0);
}
}
