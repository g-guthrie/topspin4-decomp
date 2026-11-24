/* 0x88522300: replaces the first of three u16 slots equal to v with 0xFFFF */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
void ts4_clear_u16_slot_88522300(int unused, unsigned short *a, unsigned short v) { int i; for (i = 0; i < 3; i++) if (a[i] == v) { a[i] = 0xffff; return; } }
