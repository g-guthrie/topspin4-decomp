/* 0x883297A8: lower-cases an ASCII string in place and returns it */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
char *ts4_str_lower_883297A8(char *s) { char *p = s; if (*p) { do { if (*p >= 'A' && *p <= 'Z') *p += 0x20; } while (*++p); } return s; }
