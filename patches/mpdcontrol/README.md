# Install

Change the following line in `config.mk` to add `-lmpdclient`:

```
LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIBS} -lmpdclient
```

Add the following to `config.def.h`:

```
#include <X11/XF86keysym.h>
#include "patches/mpdcontrol/mpdcontrol.c"
```

New commands:

```
static const char *mutecmd[] = { "amixer", "sset", "Master", "toggle" };
static const char *voldncmd[] = { "amixer", "sset", "Master", "5%-" };
static const char *volupcmd[] = { "amixer", "sset", "Master", "5%+" };
```

In the `keys[]` array:

```
{ False,    XF86XK_AudioPlay,           mpdcontrol,    {0}},
{ False,    XF86XK_AudioPrev,           mpdchange,     {.i = -1 }},
{ False,    XF86XK_AudioNext,           mpdchange,     {.i = +1 }},
{ False,    XF86XK_AudioMute,           spawn,         {.v = mutecmd }},
{ False,    XF86XK_AudioRaiseVolume,    spawn,         {.v = volupcmd }},
{ False,    XF86XK_AudioLowerVolume,    spawn,         {.v = voldncmd }},
```

# Dependencies

The MPD header files.

# Source
https://dwm.suckless.org/patches/mpdcontrol