/* 0x884957C0: Stores in *out whether blocks (plus one if the cursor is at the start) 128-byte blocks fit in the ring space between cursor and limit, less 16 bytes. */
/* Near miss (agAH): 3 off: cmpw operand order and two register swaps (tried several comparison forms). */
typedef struct Ring { char pad[0xc]; char *start; char *limit; char *cursor; } Ring;
void fn_884957C0(unsigned char *out, Ring *r, void *unused, int blocks)
{
    int avail = r->limit - r->cursor;
    if (r->cursor == r->start)
        blocks++;
    {
        unsigned char fits = 0;
        if (blocks * 128 <= avail - 16)
            fits = 1;
        *out = fits;
    }
}
