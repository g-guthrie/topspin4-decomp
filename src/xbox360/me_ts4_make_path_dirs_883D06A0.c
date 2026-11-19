/* 0x883D06A0: skips the first path component, then for each later \\ or / separator temporarily cuts the string */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); and calls fn_8857C5A0(prefix, 0) (create-directory style); always returns 0. */
int fn_8857C5A0(const char *path, void *attr);
int ts4_make_path_dirs_883D06A0(char *s)
{
    int i = 0;
    char save;
    while (s[i] && s[i] != '\\' && s[i] != '/')
        i++;
    while (s[i]) {
        for (i++; s[i]; i++)
            if (s[i] == '\\' || s[i] == '/')
                break;
        save = s[i];
        s[i] = 0;
        fn_8857C5A0(s, 0);
        s[i] = save;
    }
    return 0;
}
