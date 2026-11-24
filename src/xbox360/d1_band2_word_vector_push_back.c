/* Swing_DLL.xex family of word vector push_back helpers, executable version 0.0.0.3. */
typedef struct Ts4WordVector {
    unsigned int *data;
    int size;
    unsigned int capacity;
} Ts4WordVector;

void fn_8841C678(Ts4WordVector *vector, int grow_by);

void ts4_push_back_word_8841C248(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x14);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C498(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0xf0);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C508(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x114);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C578(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0xfc);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C5E8(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x108);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C658(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x12c);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C6C8(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x150);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C738(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x138);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C7A8(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x144);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C818(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x168);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C888(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x15c);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C8F8(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x174);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C968(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x120);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_8846C9D8(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x180);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_884773F0(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x8c);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_88477460(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x80);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_884ADCD8(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x8);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_884AF018(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x8);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_884B2040(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x8);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_884CC258(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x1c);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_884CD0D0(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x8);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void ts4_push_back_word_884DB2E0(char *owner, unsigned int value)
{
    Ts4WordVector *vector = (Ts4WordVector *)(owner + 0x8);
    if (vector->size == (int)(vector->capacity & 0x3FFFFFFF)) {
        fn_8841C678(vector, 4);
    }
    vector->data[vector->size] = value;
    vector->size++;
}
