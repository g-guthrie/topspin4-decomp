/* Swing_DLL.xex 0x88432B08: Ts4Elem8Table::Ts4Elem8Table(const Ts4Elem8Vec &src): default-initialises the table
 * (0x88423CE0) and inserts every {key, value} pair of src with 0x88423660.
 * Matched on /Oc as a constructor taking src by reference: the element address is `add r11, r11(items), r30(offset)`;
 * as an extern "C" function (self, src) the operands come out (offset, items) (docs/agents/regalloc.md C1). */
struct Ts4Elem8 { int key; int value; };
struct Ts4Elem8Vec { Ts4Elem8 *items; int count; };

extern "C" {
void fn_88423CE0(void *table);                       /* default 16-entry init, returns the table */
void fn_88423660(void *table, int key, int value);  /* insert */
}

struct Ts4Elem8Table {
    Ts4Elem8 *data;
    int capFlags;
    int mask;

    Ts4Elem8Table(const Ts4Elem8Vec &src);
};

Ts4Elem8Table::Ts4Elem8Table(const Ts4Elem8Vec &src)
{
    fn_88423CE0(this);
    for (int i = 0; i < src.count; i++)
        fn_88423660(this, src.items[i].key, src.items[i].value);
}
