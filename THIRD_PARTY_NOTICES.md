# Third-party notices

Some reconstructed sources reproduce the behavior of open-source libraries that
were statically linked into `Swing_DLL.xex`. They were written to match the
original machine code and follow the structure of the public upstream sources,
so the upstream licenses apply to those files.

## Expat (XML parser)

Files: `src/xbox360/r3_xmlparse.c`, `r3_xmlparse.h`, `r3_xmlrole.c`,
`r3_xmlrole.h`, `r3_xmltok.h`, `r3_xmltok_normal.c`, `r3_xmltok_utf16.c`,
`r3_xmltok_unknown.c`, and the `swa_scan_*`, `swa_same_name*`,
`swa_is_public_id_*` and `swa_dispatch_token_*` sources, `swb2_expat.h`, and the
`swb2_*` tokenizer sources that carry an Expat header line, and the `ex3_xmltok_*` sources. Upstream: https://libexpat.github.io/ (1.95/2.0 era).

Copyright (c) 1998, 1999, 2000 Thai Open Source Software Center Ltd and Clark Cooper
Copyright (c) 2001, 2002, 2003, 2004, 2005, 2006 Expat maintainers.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Lua

Files: `src/xbox360/swa_lua_match_class_88824F38.c`, `ex3_lua_lzio.c`, `ex3_lua_lvm_strcmp.c`. Upstream: https://www.lua.org/

Copyright (C) 1994-2008 Lua.org, PUC-Rio.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## zlib (compression and checksums)

Files: `src/xbox360/r3_zlib_deflate.c`, `r3_zlib.h`, `ex3_zlib.h`, `ex3_zlib_trees.c`,
`ex3_zlib_deflate.c`, `ex3_zlib_inflate.c`, `ex3_zlib_inftrees.c`. Upstream: https://zlib.net/

Copyright (C) 1995-2005 Jean-loup Gailly and Mark Adler

This software is provided 'as-is', without any express or implied warranty. In
no event will the authors be held liable for any damages arising from the use
of this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter it and redistribute it freely, subject to
the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim
   that you wrote the original software. If you use this software in a product,
   an acknowledgment in the product documentation would be appreciated but is
   not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.

These reconstructions are altered versions: they are rewritten to reproduce the
compiled code in Top Spin 4 and are not the upstream sources.
