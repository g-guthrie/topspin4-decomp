/* nearmiss: 2 off (Swing_DLL.xex 0x8887EB10, slot-array dtor). li r27,9 and the vtable stw are swapped.
 * Concrete blocker: the target reloads lbl_88D45B38 only after calls, which MSVC does only when the global is
 * address-taken in the LTCG link. The accessor below gets from 6 off to 2; the remaining schedule needs the real
 * writer TU of lbl_88D45B38 (stw at fn_886263E8+0x13c) in the link. perm_auto: 105 candidates, best 2.
 * Context: --include ts4_find_range_owner_8860D360 --include ts4_node_visit_8860DBC8
 *   --context flags(/Ob1):src/xbox360/cx11_core_c.c --context flags(/Ob1):src/xbox360/d7w_node_visit_8860DBC8.cpp
 *   --context src/xbox360/pp1_pool_primer.c */
typedef struct Ts4Registry { char p[0x24]; void *fallback; } Ts4Registry;
extern Ts4Registry *lbl_88D45B38;
void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
void ts4_node_visit_8860DBC8(void *entry, void *key);
void fn_885651F8(void *p);
extern const char lbl_880DF930[];
static __inline Ts4Registry **ts4_registry_slot(void) { return &lbl_88D45B38; }
typedef struct Slot { void *p; unsigned int a, b; } Slot;
typedef struct Slots { const void *vt; char pad[0x2c]; Slot slot[10]; } Slots;
void fn_8887EB10(Slots *self)
{
    int i;
    Slot *s;
    Ts4Registry *reg;
    self->vt = lbl_880DF930;
    s = &self->slot[10];
    reg = *ts4_registry_slot();
    for (i = 9; i >= 0; i--) {
        void *p = (--s)->p;
        if (p != 0) {
            if (reg != 0) {
                void *e = ts4_find_range_owner_8860D360(reg, p);
                if (e != 0) {
                    ts4_node_visit_8860DBC8(e, p);
                    reg = *ts4_registry_slot();
                } else {
                    ts4_node_visit_8860DBC8(reg->fallback, p);
                    reg = *ts4_registry_slot();
                }
            } else {
                fn_885651F8(p);
            }
        }
    }
}
