typedef struct { char pad[0x23c]; unsigned char enabled; } Ts4Obj23C;
/* Returns 1 unless the gate flag is set and count is non-zero. */
int ts4_gate_allows_zero_count_888C1C80(Ts4Obj23C *o, unsigned int count)
{ int r = 1; if (o->enabled) { if (count) r = 0; } return r; }