/* 0x885A9A08: Returns (index + 1) * fn_885BDF00(channels +6, rate +4) - 1: the last byte or frame of block index. */
/* Near miss (agAH): 1 off: mullw operand order (target mullw r11,r10(index+1),r11(n)); both operand orders, locals, int/unsigned and C++ all give mullw r11,r11,r10. */
typedef struct Track { int unk0; unsigned short rate; unsigned short channels; } Track;
unsigned short fn_885BDF00(unsigned short channels, unsigned short rate);
unsigned int fn_885A9A08(Track *t, unsigned int index)
{
    return (index + 1) * fn_885BDF00(t->channels, t->rate) - 1;
}
