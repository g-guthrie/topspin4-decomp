/* Swing_DLL.xex 0x888E77E8-0x888E78B4, executable version 0.0.0.3. */
typedef struct Ts4Item12 {
    void *object;
    unsigned int extra[2];
} Ts4Item12;

typedef struct Ts4Item16 {
    void *object;
    unsigned int extra[3];
} Ts4Item16;

typedef struct Ts4VectorSet {
    Ts4Item16 *first_begin;
    Ts4Item16 *first_end;
    unsigned int first_capacity;
    Ts4Item16 *second_begin;
    Ts4Item16 *second_end;
    unsigned int second_capacity;
    Ts4Item12 *third_begin;
    Ts4Item12 *third_end;
    unsigned int third_capacity;
    void *tail_object;
    char pad[0x1c];
    void *final_object;
} Ts4VectorSet;

extern void ts4_destroy_owned_object(void *object);

void ts4_destroy_vector_set_888E77E8(Ts4VectorSet *self)
{
    Ts4Item12 *item12;
    Ts4Item12 *end12;
    Ts4Item16 *item16;
    Ts4Item16 *end16;

    ts4_destroy_owned_object(self->final_object);
    if (self->tail_object != 0) {
        ts4_destroy_owned_object(self->tail_object);
    }
    end12 = self->third_end;
    for (item12 = self->third_begin; item12 != end12; item12++) {
        ts4_destroy_owned_object(item12->object);
    }
    if (self->third_begin != 0) {
        ts4_destroy_owned_object(self->third_begin);
    }
    end16 = self->second_end;
    for (item16 = self->second_begin; item16 != end16; item16++) {
        ts4_destroy_owned_object(item16->object);
    }
    if (self->second_begin != 0) {
        ts4_destroy_owned_object(self->second_begin);
    }
    end16 = self->first_end;
    for (item16 = self->first_begin; item16 != end16; item16++) {
        ts4_destroy_owned_object(item16->object);
    }
    if (self->first_begin != 0) {
        ts4_destroy_owned_object(self->first_begin);
    }
}
