/* 0x88329768: upper-cases an ASCII string in place and returns it */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
char *ts4_str_upper_88329768(char *s) { char *p = s; if (*p) { do { if (*p >= 'a' && *p <= 'z') *p -= 0x20; } while (*++p); } return s; }
