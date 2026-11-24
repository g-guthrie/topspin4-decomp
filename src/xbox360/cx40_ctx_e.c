typedef unsigned int u32;
#ifdef _MSC_VER
__declspec(noinline)
#endif
char **ts4_find_in_range_887E9720(char ***s, u32 *key, int b, u32 c) { char **p = s[0]; char **e = s[1]; for (; p != e; p++) { char *o = *p; if (*(u32*)(o+0x14) == *key && *(int*)(o+0x10) == b && (c == 0 || c == *(u32*)(o+0x1c))) return p; } return p; }
