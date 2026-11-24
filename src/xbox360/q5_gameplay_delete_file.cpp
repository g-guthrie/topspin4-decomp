/* Q5 gameplay: file-system wrapper that deletes a file and reports success as bool. */
extern "C" int fn_8857B778(const char *path); /* 0x8857B778: DeleteFileA-style (NtOpenFile + delete disposition) */

struct Q5FileSys {
    virtual bool remove(const char *path);
};

/* Swing_DLL.xex 0x88884488 */
bool Q5FileSys::remove(const char *path)
{
    return 0 != fn_8857B778(path);
}
