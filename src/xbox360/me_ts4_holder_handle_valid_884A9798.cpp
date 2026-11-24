/* 0x884A9798: Returns true when the source at +0xc is set and the handle returned by ts4_get_u32_off8_884271C8(src) has a non-zero first byte. */
/* Matched on /Oc (agAH). C++: the callee returns a class with a non-trivial copy constructor, so the result comes back through a hidden pointer (addi r3,r1,0x50; lbz 0(r3)). A plain C struct comes back in registers. bool return with &&. */
#pragma warning(disable: 4190) /* C-linkage function returning a C++ class: needed for the unmangled config name */
struct Handle {
    unsigned char valid;
    unsigned char pad[3];
    Handle(const Handle &other); /* non-trivial copy: returned through a hidden pointer, as in the target */
};
extern "C" Handle ts4_get_u32_off8_884271C8(void *src);
struct Holder { char pad[0xc]; void *src; };
extern "C" bool fn_884A9798(Holder *h)
{
    return h->src != 0 && ts4_get_u32_off8_884271C8(h->src).valid != 0;
}
