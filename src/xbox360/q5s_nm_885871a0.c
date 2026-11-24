/* Swing_DLL.xex 0x885871A0: acquire a page from the pool (fn_88584AE0) or, when none is free, create one
 * (fn_885869A8, HRESULT-style); on success set bit 0x40 in byte 7 of the page info. Built /O1.
 * fn_88584AE0 is tested with cmplwi, so its result is unsigned here (a found flag).
 * The flag is set on both the found and the created path (the found branch joins the flag store). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct PageInfo { u32 pad0; u8 useCount; u8 pad5[2]; u8 flags; } PageInfo;
typedef struct PagePool PagePool;

extern u32 fn_88584AE0(PagePool *pool, u32 key, u32 b, u8 **page, PageInfo **info);
extern long fn_885869A8(PagePool *pool, u32 key, u32 b, void *desc, u8 **page, PageInfo **info);

long ts4_page_pool_acquire_or_create_885871A0(PagePool *pool, u32 key, void *desc, u8 **page)
{
    PageInfo *info;
    long hr = 0;
    if (!fn_88584AE0(pool, key, 0, page, &info)) {
        hr = fn_885869A8(pool, key, 0, desc, page, &info);
        if (hr < 0)
            return hr;
    }
    info->flags |= 0x40;
    return hr;
}
