/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Shared declarations for the exact-match units in this directory; types, names
 * and field roles are reconstructions from the disassembly of the retail module.
 */
#ifndef TS4_DRAFT_REGISTRY_LOOKUP_H
#define TS4_DRAFT_REGISTRY_LOOKUP_H

typedef struct ts4_entry_iterator {
    unsigned int owner;
    unsigned int index;
} ts4_entry_iterator;

typedef struct ts4_entry_filter {
    unsigned int word;
} ts4_entry_filter;

unsigned char *fn_881AB900(void *registry, unsigned int key, ts4_entry_iterator after, ts4_entry_filter filter);

#endif
