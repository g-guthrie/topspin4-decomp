/* Swing_DLL.xex 0x88584AE0: find a free 4 KB page (88584868), mark it used (885847C8), bump its use count, return page and info
 * /O1; info pointer copied to a local before the increment so the out-pointer stores do not force a reload */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct PageInfo { u32 pad0; u8 useCount; } PageInfo;
typedef struct PagePool { u8 pad[0x34]; u8 *pages; } PagePool;

int fn_88584868(PagePool *pool, u32 a, u32 b, u32 *index, PageInfo **info);
void fn_885847C8(PagePool *pool, u32 index, int count);

int fn_88584AE0(PagePool *pool, u32 a, u32 b, u8 **page, PageInfo **info)
{
    PageInfo *pi;
    u32 index;
    int ok = fn_88584868(pool, a, b, &index, &pi);
    if (ok) {
        u8 *p = pool->pages + (index << 12);
        PageInfo *q;
        fn_885847C8(pool, index, 1);
        q = pi;
        q->useCount++;
        *page = p;
        *info = q;
    }
    return ok;
}
