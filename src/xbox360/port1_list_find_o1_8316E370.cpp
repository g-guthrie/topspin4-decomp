/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l28_list_find_o1_8316E370.cpp.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
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



/* Swing_DLL.xex 0x88598DB0 */
extern "C" L28FN *ts4_list_find_88598DB0(L28FL8316E370 *l, void *key, L28Cmp cmp, L28FN *start)
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

