/* Loader_DLL.xex 0x83100080-0x83100350, executable version 0.0.0.3. */
typedef struct { void *data; int count; int cap; } Vec;
extern void fn_83120540(void *p);

void ts4l_vec_free_83100080(Vec *v)
{
    int i;

    if (v->data != 0) {
        for (i = 0; i < v->count; i++) {
        }
        fn_83120540(v->data);
        v->data = 0;
    }
    v->count = 0;
    v->cap = 0;
}

void ts4l_vec_free_83100120(Vec *v)
{
    int i;

    if (v->data != 0) {
        for (i = 0; i < v->count; i++) {
        }
        fn_83120540(v->data);
        v->data = 0;
    }
    v->count = 0;
    v->cap = 0;
}

void ts4l_vec_free_831002E0(Vec *v)
{
    int i;

    if (v->data != 0) {
        for (i = 0; i < v->count; i++) {
        }
        fn_83120540(v->data);
        v->data = 0;
    }
    v->count = 0;
    v->cap = 0;
}

void ts4l_vec_free_83100350(Vec *v)
{
    int i;

    if (v->data != 0) {
        for (i = 0; i < v->count; i++) {
        }
        fn_83120540(v->data);
        v->data = 0;
    }
    v->count = 0;
    v->cap = 0;
}
