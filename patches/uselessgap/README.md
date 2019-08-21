# Install

Apply the patch.

Add the following to `config.def.h`:

```
#include "patches/uselessgap/uselessgap.c"
```

In the `keys[]` array:

```
{ MODKEY,              XK_minus,    setgaps,    {.i = -1} },
{ MODKEY,              XK_equal,    setgaps,    {.i = +1} },
{ MODKEY|ShiftMask,    XK_equal,    setgaps,    {.i = 0} },
```

# Dependencies

This should be merged after the `bottomstack` branch.

# Source

https://dwm.suckless.org/patches/uselessgap

Uses the  `setgaps()` and key bindings from:

https://dwm.suckless.org/patches/fullgaps
