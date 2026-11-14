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
`swb2_*` tokenizer sources that carry an Expat header line, and the `ex3_xmltok_*`, `ex4_xmltok_*`, `ex5_xmltok_*`, `ex6_xmltok_*` and
`lg1_xmltok_*` sources. Upstream: https://libexpat.github.io/ (1.95/2.0 era).

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

Files: `src/xbox360/swa_lua_match_class_88824F38.c`, `ex3_lua_lzio.c`, `ex3_lua_lvm_strcmp.c`, the `lu1_*` sources, and the `lib3_lua_*` sources except `lib3_lua_wstr.c`, the `lua2_*` and `lua3_*` sources (Lua 5.0.2 with LuaPlus-style changes; `lib3_lua_wstr.c` was reconstructed from disassembly only). Upstream: https://www.lua.org/

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
`ex3_zlib_deflate.c`, `ex3_zlib_inflate.c`, `ex3_zlib_inftrees.c`, the `ex4_zlib_*` sources, `rm3_zlib_deflate.c`, and the `png2_zlib_*` sources
(a zlib 1.1.4 copy) with `png2_zlib_inf.h`. Upstream: https://zlib.net/

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

## Xenia (Xenos texture tiling and fetch-constant layout)

File: `tools/ts4_texture.py`. Its Xenos 2-D tiling and texture fetch-constant
field layout follow the public description in the Xenia emulator
(`src/xenia/gpu/xenos.h`, `TextureInfo::TiledOffset2DOuter/Inner`). Xenia is
distributed under the BSD 3-Clause license:

> Copyright (c) 2015, Ben Vanik.
> All rights reserved.
>
> Redistribution and use in source and binary forms, with or without
> modification, are permitted provided that the following conditions are met:
>
> * Redistributions of source code must retain the above copyright notice, this
>   list of conditions and the following disclaimer.
> * Redistributions in binary form must reproduce the above copyright notice,
>   this list of conditions and the following disclaimer in the documentation
>   and/or other materials provided with the distribution.
> * Neither the name of the project nor the names of its contributors may be
>   used to endorse or promote products derived from this software without
>   specific prior written permission.
>
> THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
> AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
> IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
> DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
> FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
> DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
> SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
> CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
> OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
> OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

## libpng

Files: `src/xbox360/ex6_png.h`, `ex6_png_misc.c`, `ex6_png_xform.c`, and later
`ex*_png*` and `png2_png_*` sources that carry a libpng header line (the `png2_png_*` code is
from the libpng 1.0.6 era). Upstream: http://www.libpng.org/
(1.2.x). Distributed under the libpng license:

> Copyright (c) 1998-2008 Glenn Randers-Pehrson
> (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)
> (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)
>
> The PNG Reference Library is supplied "AS IS". The Contributing Authors and
> Group 42, Inc. disclaim all warranties, expressed or implied, including,
> without limitation, the warranties of merchantability and of fitness for any
> purpose. The Contributing Authors and Group 42, Inc. assume no liability for
> direct, indirect, incidental, special, exemplary, or consequential damages,
> which may result from the use of the PNG Reference Library, even if advised
> of the possibility of such damage.
>
> Permission is hereby granted to use, copy, modify, and distribute this source
> code, or portions hereof, for any purpose, without fee, subject to the
> following restrictions:
>
> 1. The origin of this source code must not be misrepresented.
> 2. Altered versions must be plainly marked as such and must not be
>    misrepresented as being the original source.
> 3. This Copyright notice may not be removed or altered from any source or
>    altered source distribution.

## IJG JPEG library

Files: `src/xbox360/ex6_jpeg_err.c`, the `rm3_jpeg*`, `jp1_*`, `jp2_*` and `png2_jpeg_*` sources, and later `ex*_jpeg*` sources that carry
an IJG header line. Upstream: https://www.ijg.org/ (release 6b).

> This software is based in part on the work of the Independent JPEG Group.
>
> Copyright (C) 1991-1998, Thomas G. Lane. All Rights Reserved except as
> specified below. Permission is hereby granted to use, copy, modify, and
> distribute this software (or portions thereof) for any purpose, without fee,
> subject to these conditions: (1) If any part of the source code for this
> software is distributed, then this README file must be included, with this
> copyright and no-warranty notice unaltered; and any additions, deletions, or
> changes to the original files must be clearly indicated in accompanying
> documentation. (2) If only executable code is distributed, then the
> accompanying documentation must state that "this software is based in part
> on the work of the Independent JPEG Group". (3) Permission for use of this
> software is granted only if the user accepts full responsibility for any
> undesirable consequences; the authors accept NO LIABILITY for damages of any
> kind. The software is provided "AS IS", without warranty of any kind, either
> express or implied, with respect to its quality, accuracy, merchantability,
> or fitness for a particular purpose.
>
> Changes: the derived functions are rewritten to reproduce the Swing_DLL.xex
> object code; each such file is marked "Altered to match Swing_DLL.xex".

## libogg and libvorbis (Xiph.Org)

Files: the `lib2_ogg_*`, `lib2_vorbis_*` and `aud1_vorbis*` sources, `lib2_ogg.h` and
`aud1_vorbis.h`. These
reconstruct the libogg 1.2.x and libvorbis 1.2.3 copies inside the FMOD Ex
library of `Swing_DLL.xex` (allocating calls take a leading context argument).

```
Copyright (c) 2002-2010, Xiph.org Foundation

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

- Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

- Neither the name of the Xiph.org Foundation nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```

## libFLAC

Files: the `lib2_flac_*` sources (except `lib2_flac_md5.c`, below) and
`lib2_flac.h`. These reconstruct the libFLAC 1.2.1 copy inside FMOD Ex.

```
libFLAC - Free Lossless Audio Codec library
Copyright (C) 2000,2001,2002,2003,2004,2005,2006,2007  Josh Coalson

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

- Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

- Neither the name of the Xiph.org Foundation nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```

`src/xbox360/lib2_flac_md5.c` derives from libFLAC's `md5.c`, Colin Plumb's
MD5 implementation, which is in the public domain (no copyright is claimed;
see the file header).

## CELT

Files: the `aud1_celt_*` sources and `aud1_celt.h`. These reconstruct the CELT
0.6.1 copy inside FMOD Ex. Upstream: https://gitlab.xiph.org/xiph/celt

```
Copyright (C) 2007-2009 Jean-Marc Valin, CSIRO
Copyright (C) 2008 Gregory Maxwell

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

- Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

- Neither the name of the Xiph.org Foundation nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```

## trio

Files: the `lib4_trio*` sources and `lib4_trio.h`. These reconstruct the narrow
and wide copies of trio 1.10 (trio.c v1.75, trionan.c v1.26), trimmed by the
game's developer. Upstream: https://sourceforge.net/projects/ctrio/

```
Copyright (C) 1998 Bjorn Reese and Daniel Stenberg.

Permission to use, copy, modify, and distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE AUTHORS AND
CONTRIBUTORS ACCEPT NO RESPONSIBILITY IN ANY CONCEIVABLE MANNER.
```
