/* Swing_DLL.xex 0x88163A00-0x8827AD64, executable version 0.0.0.3. */
typedef unsigned int u32;

extern void ts4_destroy_owned_object(void *object);

typedef struct Ts4Element12 { u32 words[3]; } Ts4Element12;
typedef struct Ts4Vector12 { Ts4Element12 *begin; Ts4Element12 *end; Ts4Element12 *capacity; } Ts4Vector12;
typedef struct Ts4Element16 { u32 words[4]; } Ts4Element16;
typedef struct Ts4Vector16 { Ts4Element16 *begin; Ts4Element16 *end; Ts4Element16 *capacity; } Ts4Vector16;
typedef struct Ts4Element20 { u32 words[5]; } Ts4Element20;
typedef struct Ts4Vector20 { Ts4Element20 *begin; Ts4Element20 *end; Ts4Element20 *capacity; } Ts4Vector20;
typedef struct Ts4Element24 { u32 words[6]; } Ts4Element24;
typedef struct Ts4Vector24 { Ts4Element24 *begin; Ts4Element24 *end; Ts4Element24 *capacity; } Ts4Vector24;
typedef struct Ts4Element36 { u32 words[9]; } Ts4Element36;
typedef struct Ts4Vector36 { Ts4Element36 *begin; Ts4Element36 *end; Ts4Element36 *capacity; } Ts4Vector36;

extern Ts4Element12 *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Ts4Element12 **allocator, u32 count);
extern Ts4Element16 *ts4_if_call_seq_u32_lbl_88D45B38_8827A758(Ts4Element16 **allocator, u32 count);
extern Ts4Element36 *ts4_if_call_seq_u32_lbl_88D45B38_88162A18(Ts4Element36 **allocator, u32 count);
extern Ts4Element20 *ts4_if_call_seq_u32_lbl_88D45B38_8817F480(Ts4Element20 **allocator, u32 count);
extern Ts4Element24 *ts4_if_call_seq_u32_lbl_88D45B38_881629B0(Ts4Element24 **allocator, u32 count);

void ts4_vector12_reserve_50_881AE660(Ts4Vector12 *vector)
{
    Ts4Element12 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x50) {
        Ts4Element12 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element12 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&vector->capacity, 0x50);
            Ts4Element12 *source = begin;
            Ts4Element12 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&vector->capacity, 0x50);
        }
        vector->begin = begin;
        vector->capacity = begin + 0x50;
        vector->end = begin + size;
    }
}

void ts4_vector12_reserve_4_88215790(Ts4Vector12 *vector)
{
    Ts4Element12 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x4) {
        Ts4Element12 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element12 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&vector->capacity, 0x4);
            Ts4Element12 *source = begin;
            Ts4Element12 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&vector->capacity, 0x4);
        }
        vector->begin = begin;
        vector->capacity = begin + 0x4;
        vector->end = begin + size;
    }
}

void ts4_vector12_reserve_40_88264858(Ts4Vector12 *vector)
{
    Ts4Element12 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x40) {
        Ts4Element12 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element12 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&vector->capacity, 0x40);
            Ts4Element12 *source = begin;
            Ts4Element12 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&vector->capacity, 0x40);
        }
        vector->begin = begin;
        vector->capacity = begin + 0x40;
        vector->end = begin + size;
    }
}

void ts4_vector12_reserve_9C4_88264E58(Ts4Vector12 *vector)
{
    Ts4Element12 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x9c4) {
        Ts4Element12 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element12 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&vector->capacity, 0x9c4);
            Ts4Element12 *source = begin;
            Ts4Element12 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&vector->capacity, 0x9c4);
        }
        vector->begin = begin;
        vector->capacity = begin + 0x9c4;
        vector->end = begin + size;
    }
}

void ts4_vector16_reserve_4_88178C40(Ts4Vector16 *vector)
{
    Ts4Element16 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x4) {
        Ts4Element16 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element16 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_8827A758(&vector->capacity, 0x4);
            Ts4Element16 *source = begin;
            Ts4Element16 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_8827A758(&vector->capacity, 0x4);
        }
        vector->begin = begin;
        vector->capacity = begin + 0x4;
        vector->end = begin + size;
    }
}

void ts4_vector16_reserve_40_88264528(Ts4Vector16 *vector)
{
    Ts4Element16 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x40) {
        Ts4Element16 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element16 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_8827A758(&vector->capacity, 0x40);
            Ts4Element16 *source = begin;
            Ts4Element16 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_8827A758(&vector->capacity, 0x40);
        }
        vector->begin = begin;
        vector->capacity = begin + 0x40;
        vector->end = begin + size;
    }
}

void ts4_vector16_reserve_8_8827AAF0(Ts4Vector16 *vector)
{
    Ts4Element16 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x8) {
        Ts4Element16 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element16 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_8827A758(&vector->capacity, 0x8);
            Ts4Element16 *source = begin;
            Ts4Element16 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_8827A758(&vector->capacity, 0x8);
        }
        vector->begin = begin;
        vector->capacity = begin + 0x8;
        vector->end = begin + size;
    }
}

void ts4_vector36_reserve_78_88163A00(Ts4Vector36 *vector)
{
    Ts4Element36 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x78) {
        Ts4Element36 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element36 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_88162A18(&vector->capacity, 0x78);
            Ts4Element36 *source = begin;
            Ts4Element36 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_88162A18(&vector->capacity, 0x78);
        }
        vector->begin = begin;
        vector->capacity = begin + 0x78;
        vector->end = begin + size;
    }
}

void ts4_vector20_reserve_4_881AE378(Ts4Vector20 *vector)
{
    Ts4Element20 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x4) {
        Ts4Element20 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element20 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_8817F480(&vector->capacity, 0x4);
            Ts4Element20 *source = begin;
            Ts4Element20 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_8817F480(&vector->capacity, 0x4);
        }
        vector->begin = begin;
        vector->capacity = begin + 0x4;
        vector->end = begin + size;
    }
}

void ts4_vector20_reserve_A_8827AC90(Ts4Vector20 *vector)
{
    Ts4Element20 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0xa) {
        Ts4Element20 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element20 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_8817F480(&vector->capacity, 0xa);
            Ts4Element20 *source = begin;
            Ts4Element20 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_8817F480(&vector->capacity, 0xa);
        }
        vector->begin = begin;
        vector->capacity = begin + 0xa;
        vector->end = begin + size;
    }
}

void ts4_vector24_reserve_10_882660C0(Ts4Vector24 *vector)
{
    Ts4Element24 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x10) {
        Ts4Element24 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element24 *buffer = ts4_if_call_seq_u32_lbl_88D45B38_881629B0(&vector->capacity, 0x10);
            Ts4Element24 *source = begin;
            Ts4Element24 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = ts4_if_call_seq_u32_lbl_88D45B38_881629B0(&vector->capacity, 0x10);
        }
        vector->begin = begin;
        vector->capacity = begin + 0x10;
        vector->end = begin + size;
    }
}

typedef struct Ts4Element28 { u32 words[7]; } Ts4Element28;
typedef struct Ts4Vector28 { Ts4Element28 *begin; Ts4Element28 *end; Ts4Element28 *capacity; } Ts4Vector28;
extern Ts4Element28 *fn_88278A68(Ts4Element28 **allocator, u32 count);

void ts4_vector28_reserve_1388_88170AB0(Ts4Vector28 *vector)
{
    Ts4Element28 *begin = vector->begin;

    if ((u32)(vector->capacity - begin) < 0x1388) {
        Ts4Element28 *end = vector->end;
        int size = end - begin;

        if (begin != 0) {
            Ts4Element28 *buffer = fn_88278A68(&vector->capacity, 0x1388);
            Ts4Element28 *source = begin;
            Ts4Element28 *destination = buffer;

            for (; source != end; ++source) {
                if (destination) {
                    *destination = *source;
                }
                ++destination;
            }
            begin = buffer;
            ts4_destroy_owned_object(vector->begin);
        } else {
            begin = fn_88278A68(&vector->capacity, 0x1388);
        }
        vector->begin = begin;
        vector->end = begin + size;
        vector->capacity = begin + 0x1388;
    }
}
