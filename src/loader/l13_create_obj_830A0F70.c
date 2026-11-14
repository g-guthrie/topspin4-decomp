/* Loader_DLL.xex 0x830A0F70-0x830A1328, executable version 0.0.0.3. */
extern void *fn_833E0AB0(unsigned size);
extern void *fn_83490390(void *p);
extern void *ts4l_call_seq_lbl_83085ED4_83490318(void *p);

long ts4l_create_obj_830A0F70(void *owner, void **out)
{
    void *mem;
    char *obj;

    *out = 0;
    mem = fn_833E0AB0(0x3c);
    obj = 0;
    if (mem != 0) {
        obj = (char *)fn_83490390(mem);
    }
    if (obj == 0) {
        return 0x8007000E;
    }
    *(void **)(obj + 4) = owner;
    *out = obj;
    return 0;
}

long ts4l_create_obj_830A1328(void *owner, void **out)
{
    void *mem;
    char *obj;

    *out = 0;
    mem = fn_833E0AB0(0x70);
    obj = 0;
    if (mem != 0) {
        obj = (char *)ts4l_call_seq_lbl_83085ED4_83490318(mem);
    }
    if (obj == 0) {
        return 0x8007000E;
    }
    *(void **)(obj + 4) = owner;
    *out = obj;
    return 0;
}
