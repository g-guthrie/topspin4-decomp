/* Swing_DLL.xex 0x886ECAE0: set the active viewport count; slot i gets index i and enabled = (i < count), 4 slots. */
typedef struct Ts4ViewSlots {
    char pad[0x15630];
    unsigned char index[4];     /* +0x15630 */
    unsigned char enabled[4];   /* +0x15634 */
    unsigned char count;        /* +0x15638 */
} Ts4ViewSlots;
void ts4_set_view_count_886ECAE0(Ts4ViewSlots *d, unsigned char n)
{
    unsigned char i;
    d->count = n;
    for (i = 0; i < 4; i++) {
        d->index[i] = i;
        d->enabled[i] = i < n;
    }
}
