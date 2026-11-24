/* Loader_DLL.xex 0x8316E370-0x8319D680, executable version 0.0.0.3. */

struct L28FN { void *key; L28FN *next; };

struct L28FL8316E3F8 { char pad[24]; L28FN *head; };

typedef int (*L28Cmp)(void *, void *);

struct L28FL8316E4D0 { char pad[24]; L28FN *head; };

struct L28FL8316E580 { char pad[24]; L28FN *head; };

struct L28FL8316E608 { char pad[24]; L28FN *head; };

struct L28FL83174EC8 { char pad[24]; L28FN *head; };

struct L28FL83189260 { char pad[24]; L28FN *head; };

struct L28FL8316E370 { char pad[204]; L28FN *head; };

struct L28FL83174E40 { char pad[204]; L28FN *head; };

struct L28FL831809C8 { char pad[204]; L28FN *head; };

struct L28FL8319D680 { char pad[204]; L28FN *head; };

extern "C" L28FN *ts4l_list_find_8316E3F8(L28FL8316E3F8 *l, void *key, L28Cmp cmp, L28FN *start)
{
    L28FN *n;
    n = start ? start->next : l->head;
    if (cmp) {
        while (n) {
            if (!cmp(n->key, key)) return n;
            n = n->next;
        }
    } else {
        while (n) {
            if (n->key == key) return n;
            n = n->next;
        }
    }
    return 0;
}

extern "C" L28FN *ts4l_list_find_8316E4D0(L28FL8316E4D0 *l, void *key, L28Cmp cmp, L28FN *start)
{
    L28FN *n;
    n = start ? start->next : l->head;
    if (cmp) {
        while (n) {
            if (!cmp(n->key, key)) return n;
            n = n->next;
        }
    } else {
        while (n) {
            if (n->key == key) return n;
            n = n->next;
        }
    }
    return 0;
}

extern "C" L28FN *ts4l_list_find_8316E580(L28FL8316E580 *l, void *key, L28Cmp cmp, L28FN *start)
{
    L28FN *n;
    n = start ? start->next : l->head;
    if (cmp) {
        while (n) {
            if (!cmp(n->key, key)) return n;
            n = n->next;
        }
    } else {
        while (n) {
            if (n->key == key) return n;
            n = n->next;
        }
    }
    return 0;
}

extern "C" L28FN *ts4l_list_find_8316E608(L28FL8316E608 *l, void *key, L28Cmp cmp, L28FN *start)
{
    L28FN *n;
    n = start ? start->next : l->head;
    if (cmp) {
        while (n) {
            if (!cmp(n->key, key)) return n;
            n = n->next;
        }
    } else {
        while (n) {
            if (n->key == key) return n;
            n = n->next;
        }
    }
    return 0;
}

extern "C" L28FN *ts4l_list_find_83174EC8(L28FL83174EC8 *l, void *key, L28Cmp cmp, L28FN *start)
{
    L28FN *n;
    n = start ? start->next : l->head;
    if (cmp) {
        while (n) {
            if (!cmp(n->key, key)) return n;
            n = n->next;
        }
    } else {
        while (n) {
            if (n->key == key) return n;
            n = n->next;
        }
    }
    return 0;
}

extern "C" L28FN *ts4l_list_find_83189260(L28FL83189260 *l, void *key, L28Cmp cmp, L28FN *start)
{
    L28FN *n;
    n = start ? start->next : l->head;
    if (cmp) {
        while (n) {
            if (!cmp(n->key, key)) return n;
            n = n->next;
        }
    } else {
        while (n) {
            if (n->key == key) return n;
            n = n->next;
        }
    }
    return 0;
}

extern "C" L28FN *ts4l_list_find_8316E370(L28FL8316E370 *l, void *key, L28Cmp cmp, L28FN *start)
{
    L28FN *n;
    n = start ? start->next : l->head;
    if (cmp) {
        while (n) {
            if (!cmp(n->key, key)) return n;
            n = n->next;
        }
    } else {
        while (n) {
            if (n->key == key) return n;
            n = n->next;
        }
    }
    return 0;
}

extern "C" L28FN *ts4l_list_find_83174E40(L28FL83174E40 *l, void *key, L28Cmp cmp, L28FN *start)
{
    L28FN *n;
    n = start ? start->next : l->head;
    if (cmp) {
        while (n) {
            if (!cmp(n->key, key)) return n;
            n = n->next;
        }
    } else {
        while (n) {
            if (n->key == key) return n;
            n = n->next;
        }
    }
    return 0;
}

extern "C" L28FN *ts4l_list_find_831809C8(L28FL831809C8 *l, void *key, L28Cmp cmp, L28FN *start)
{
    L28FN *n;
    n = start ? start->next : l->head;
    if (cmp) {
        while (n) {
            if (!cmp(n->key, key)) return n;
            n = n->next;
        }
    } else {
        while (n) {
            if (n->key == key) return n;
            n = n->next;
        }
    }
    return 0;
}

extern "C" L28FN *ts4l_list_find_8319D680(L28FL8319D680 *l, void *key, L28Cmp cmp, L28FN *start)
{
    L28FN *n;
    n = start ? start->next : l->head;
    if (cmp) {
        while (n) {
            if (!cmp(n->key, key)) return n;
            n = n->next;
        }
    } else {
        while (n) {
            if (n->key == key) return n;
            n = n->next;
        }
    }
    return 0;
}
