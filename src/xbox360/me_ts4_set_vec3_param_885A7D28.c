/* 0x885A7D28: Copies a 12-byte {x,y,z} parameter into +0xfc when size == 12 and returns 0; otherwise returns 0x80070057 (E_INVALIDARG). */
/* Matched on /Oc /Os (agAH). Built /Os (on /Oc the copy registers rotate, 4 off). Single hr variable with the error branch first; struct assignment. */
typedef struct Vec3i { int x, y, z; } Vec3i;
typedef struct Emitter { char pad[0xfc]; Vec3i v; } Emitter;
long fn_885A7D28(Emitter *e, const Vec3i *src, unsigned int size)
{
    long hr = 0;
    if (size != sizeof(Vec3i))
        hr = 0x80070057;
    else
        e->v = *src;
    return hr;
}
