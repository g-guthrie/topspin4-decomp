typedef unsigned int u32;
typedef struct Reg { char p[0x2c0]; u32 *begin; u32 *end; } Reg;
extern Reg *lbl_88D45B1C;
u32 *fn_88165170(u32 *first, u32 *last, const u32 *val);
unsigned char fn_88943390(void);
unsigned char ts4_id_registered_and_idle_8877F448(void){ u32 key; u32 *e; Reg *g; key = 0xA6F6E957; g = lbl_88D45B1C; e = g->end; if (e != fn_88165170(g->begin, e, &key) && !fn_88943390()) return 1; return 0; }