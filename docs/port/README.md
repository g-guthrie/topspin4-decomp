# Asset and presentation formats

The reimplementation under `port/core` and `port/web` was removed on 2026-11-14 (owner decision): a
from-scratch port cannot be pixel exact. The last commit that contains it is `8683c81`.

What stays here is the format knowledge that work produced. It applies to the real game as well:

| note | covers |
|---|---|
| [venues-and-crowd.md](venues-and-crowd.md) | venue scenes, court lines, crowd records, behaviour graphs |
| [ui.md](ui.md) | RUI scenes, Lua 5.0 scripts, actions, fonts, screen flow, HUD |
| [presentation-and-audio.md](presentation-and-audio.md) | FMOD event and bank formats, TV camera, cutscene catalogue |
| [players.md](players.md) | character models, outfits, animation clips |
| [clip-map.md](clip-map.md) | animation record to clip links |

Sections of these notes that describe `port/web` viewers or `port/core` describe removed code.
The decoders and exporters are in `tools/port/` and `tools/ts4_*.py`.
