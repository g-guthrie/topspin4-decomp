#!/usr/bin/env python3
"""Serve the repository root for the browser port viewer (standard library only).

  python3 tools/port/serve.py [--port 8000] [--bind 127.0.0.1]   then open  http://127.0.0.1:8000/port/web/

Equivalent to `python3 -m http.server` run from the repository root, plus: no-cache headers (so edits to port/web and
fresh exports show up on reload), the right MIME type for .wasm / .gltf, and a refusal to bind anything but loopback
unless --bind says so (the exported assets are the user's own game data and must not be shared).
"""
import argparse
import functools
import http.server
import os

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


class Handler(http.server.SimpleHTTPRequestHandler):
    extensions_map = {**http.server.SimpleHTTPRequestHandler.extensions_map,
                      ".wasm": "application/wasm", ".gltf": "model/gltf+json", ".js": "text/javascript",
                      ".json": "application/json", ".dat": "application/octet-stream"}

    def end_headers(self):
        self.send_header("Cache-Control", "no-store")
        super().end_headers()


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--port", type=int, default=8000)
    ap.add_argument("--bind", default="127.0.0.1")
    a = ap.parse_args()
    handler = functools.partial(Handler, directory=ROOT)
    with http.server.ThreadingHTTPServer((a.bind, a.port), handler) as srv:
        print("serving %s at http://%s:%d/port/web/  (Ctrl-C to stop)" % (ROOT, a.bind, a.port))
        try:
            srv.serve_forever()
        except KeyboardInterrupt:
            pass


if __name__ == "__main__":
    main()
