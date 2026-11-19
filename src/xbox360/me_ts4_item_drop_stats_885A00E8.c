/* 0x885A00E8: Takes an item out of its owner stats (+0x30): active count (+0x18) minus 1, flagged count (+0x24) minus (flag at +0x80 != 0), byte total (+0x28) minus the item bytes (+0x28), then tail-calls ts4_if_get_fn_885ABDB0_885ABE30(it). */
/* Matched on /Oc /Os (agAH). Built /Os (on /Oc each statement takes fresh registers, 9-13 off); the flag test is read into an int local first. */
typedef struct Stats { char pad[0x18]; int active; char pad1c[0x24 - 0x1c]; int flagged; int bytes; } Stats;
typedef struct Item { char pad[0x28]; int bytes; char pad2c[0x30 - 0x2c]; Stats *stats; char pad34[0x80 - 0x34]; void *flag; } Item;
void ts4_if_get_fn_885ABDB0_885ABE30(Item *it);
void fn_885A00E8(Item *it)
{
    it->stats->active--;
    { int f = it->flag != 0; it->stats->flagged -= f; }
    it->stats->bytes -= it->bytes;
    ts4_if_get_fn_885ABDB0_885ABE30(it);
}
