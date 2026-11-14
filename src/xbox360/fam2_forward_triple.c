/* Family FAM2: forwarders of a 12-byte by-value argument (Swing_DLL.xex); same shape as
   d1_band3_forward_triple_886A4948.c. */
struct TS4Triple {
    unsigned int first;
    unsigned int second;
    unsigned int third;
};
void fn_88627EC0(void *object, struct TS4Triple value);
void fn_88628688(void *object, struct TS4Triple value);
void fn_88628C48(void *object, struct TS4Triple value);

/* Pass the object and the by-value triple straight on to the target. */
#define TS4_FORWARD_TRIPLE(A, TARGET) \
void ts4_forward_triple_##A(void *object, struct TS4Triple value); \
void ts4_forward_triple_##A(void *object, struct TS4Triple value) \
{ \
    TARGET(object, value); \
}

/* Swing_DLL.xex addresses */
TS4_FORWARD_TRIPLE(88213698, fn_88627EC0)
TS4_FORWARD_TRIPLE(8827F718, fn_88628688)
TS4_FORWARD_TRIPLE(886281C0, fn_88627EC0)
TS4_FORWARD_TRIPLE(88628658, fn_88627EC0)
TS4_FORWARD_TRIPLE(88628C18, fn_88627EC0)
TS4_FORWARD_TRIPLE(88628E40, fn_88627EC0)
TS4_FORWARD_TRIPLE(8862AD48, fn_88628C48)
TS4_FORWARD_TRIPLE(886587F8, fn_88627EC0)
