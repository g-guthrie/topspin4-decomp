/* 0x88376700: keeps every second byte of s in place (narrows a 16-bit string); returns s */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
char *ts4_squeeze_even_chars_88376700(char *s) { char *p, *q; if (!s) return s; p = s; q = s; while (*p) { *q++ = *p; p += 2; } *q = 0; return s; }
