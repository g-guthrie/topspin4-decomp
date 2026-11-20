/* GA6: LTCG-only match (needs src/xbox360/ga5_a.c in the same link for fn_886C8438). */
typedef unsigned int ts4_word;

void *ts4_find_rec8c_by_keys_886C8438(void *self, unsigned key_a, unsigned key_b);
struct Ga6Held { int state; int count; };
struct Ga6HeldKey { unsigned a, b; struct Ga6Held *item; unsigned c; };
struct Ga6Held *fn_886C5230(void *self, void *rec, unsigned key);
void ga6_finish_request_886D7AE0(void *self, struct Ga6Held *item);

/* Resolve the held record for key (looking it up when not cached) and drop one hold; the last hold finishes it. */
void ga6_release_hold_886D7B88(void *self, struct Ga6HeldKey *key)
{
    struct Ga6Held *item = key->item;
    if (item == 0) {
        unsigned c = key->c;
        item = fn_886C5230(self, ts4_find_rec8c_by_keys_886C8438(self, key->a, key->b), c);
        if (item == 0)
            return;
    }
    if (item->count > 0) {
        if (item->count == 1)
            ga6_finish_request_886D7AE0(self, item);
        else
            item->count = item->count - 1;
    }
}

struct Ga6AcquireKey { unsigned a, b; unsigned char *flag; unsigned c; unsigned d; };
void fn_886CE170(void *owner, void *item, void *key, void *key_b, unsigned char *flag);

/* Find the record for key and take one more hold on it (starting it when idle); report failure through key->flag. */
void ga6_acquire_hold_886CE5B0(void *self, struct Ga6AcquireKey *key)
{
    unsigned c = key->d;
    struct Ga6Held *item = fn_886C5230(self, ts4_find_rec8c_by_keys_886C8438(self, key->a, key->b), c);
    if (item) {
        if (item->count == 0) {
            fn_886CE170(self, item, key, &key->b, key->flag);
            return;
        }
        item->count = item->count + 1;
        return;
    }
    if (key->flag)
        *key->flag = 1;
}
