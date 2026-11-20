/* Swing_DLL.xex 0x888A4B00-0x888A4BDC, executable version 0.0.0.3. */
#include "d8ex_xmlparse.h"

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

/* Expat storeRawNames: copy raw tag names into the tag's own buffer. */
unsigned char ts4_xml_store_raw_names_888A4B00(d8_xml_parser *parser)
{
    d8_tag *tag = parser->tag_stack;
    while (tag) {
        int buf_size;
        int name_len = tag->name_str_len + 1;
        char *raw_name_buf = tag->buf + name_len;
        if (tag->raw_name == raw_name_buf)
            break;
        buf_size = name_len + tag->raw_name_length;
        if (buf_size > tag->buf_end - tag->buf) {
            char *temp = (char *)parser->realloc_fcn(tag->buf, buf_size);
            if (temp == 0)
                return 0;
            if (tag->name_str == tag->buf)
                tag->name_str = temp;
            if (tag->name_local_part)
                tag->name_local_part = temp + (tag->name_local_part - tag->buf);
            tag->buf = temp;
            tag->buf_end = temp + buf_size;
            raw_name_buf = temp + name_len;
        }
        memcpy(raw_name_buf, tag->raw_name, tag->raw_name_length);
        tag->raw_name = raw_name_buf;
        tag = tag->parent;
    }
    return 1;
}
