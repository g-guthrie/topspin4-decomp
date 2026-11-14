/* SM4: manual vtable dispatch (the vtable pointer is loaded once and reused for two slots). */
typedef int (*Ts4Fn1)(void *);
typedef int (*Ts4Fn4)(void *, int, int, int);

/* result of slot 21 is passed as the third argument to slot 36 */
#define VCALL_21_THEN_36(NAME) \
    int NAME(void *self, int a, int b) \
    { \
        void **vt = *(void ***)self; \
        return ((Ts4Fn4)vt[36])(self, a, ((Ts4Fn1)vt[21])(self), b); \
    }
VCALL_21_THEN_36(ts4_vcall_21_then_36_88606580)
VCALL_21_THEN_36(ts4_vcall_21_then_36_88606600)
VCALL_21_THEN_36(ts4_vcall_21_then_36_886066F0)
