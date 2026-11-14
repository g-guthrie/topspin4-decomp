/* HS3 hand-matched: list walkers (0x887..0x88A). */
struct HS3Node { char pad[0x24]; unsigned key24; };
struct HS3NodeList { char pad[0x40]; unsigned *begin; unsigned *end; };
struct HS3Owner { char pad[0x10]; struct HS3NodeList *list; };

void fn_88771868(void *node, unsigned msg);

/* Send message 0xfebb7184 to every node in the owner's list whose key matches *key. */
void ts4_owner_send_msg_FEBB7184_if_key_88772B30(struct HS3Owner *self, unsigned *key)
{
    struct HS3NodeList *l = self->list;
    int n;
    unsigned i;
    if (l) {
        n = l->end - l->begin;
        for (i = 0; (int)i < n; i++) {
            struct HS3Node *node = (struct HS3Node *)(unsigned long)self->list->begin[i];
            if (*key == node->key24)
                fn_88771868(node, 0xfebb7184);
        }
    }
}

/* Send message 0x1964b988 to every node in the owner's list whose key matches *key. */
void ts4_owner_send_msg_1964B988_if_key_88772AB8(struct HS3Owner *self, unsigned *key)
{
    struct HS3NodeList *l = self->list;
    int n;
    unsigned i;
    if (l) {
        n = l->end - l->begin;
        for (i = 0; (int)i < n; i++) {
            struct HS3Node *node = (struct HS3Node *)(unsigned long)self->list->begin[i];
            if (*key == node->key24)
                fn_88771868(node, 0x1964b988);
        }
    }
}
