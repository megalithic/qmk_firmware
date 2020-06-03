# megalithic (megakeys)

A macOS-specific keymap for [DZ60](https://kbdfans.cn/products/dz60-60-pcb) configured in a standard 60% ANSI layout, with a split space bar with center Hyper (F19).


### Setup

1. `brew tap osx-cross/avr; brew tap PX4/homebrew-px4; brew install avr-gcc@8; brew link --force avr-gcc@8; brew install dfu-programmer dfu-util gcc-arm-none-eabi avrdude qmk; brew cask install qmk-toolbox;`
1. `qmk clone megalithic/qmk_firmware`
1. `qmk setup`
1. `make dz60:megalithic`
1. Launch QMK Toolbox
1. Open your newly compiled `dz60_megalithic.hex`
1. Put your dz60 in DFU mode: L3 + L2 + RESET `# based on current keymap -> (LSpc + RCmd + RBackspace)`
1. Click the `Flash` button


#### References

- https://beta.docs.qmk.fm/tutorial/newbs_flashing


## Base Layer

```
,-----------------------------------------------------------------------------------------.
|  ~` |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | BS  |     |
|-----------------------------------------------------------------------------------------+
| Tab/L3 |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   |\   |
|-----------------------------------------------------------------------------------------+
| Ctrl/Esc |  A  |  S  |   D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |   Enter   |
|-----------------------------------------------------------------------------------------+
|   Shift  |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  Sh  |  U  | Del |
|-----------------------------------------------------------------------------------------+
| Hypr |  Alt  |  Cmd  |  Space/L3  | Spc/L3 |   Space   | Cmd  |  L1   |  L  |  D  |  R  |
`-----------------------------------------------------------------------------------------'
```

-   Caps Lock is LCtrl on hold, Esc on tap
-   Hold Tab to activate L3 (_FN), Tab on tap
-   Hold MSpace to activate L3 (FN keys)
-   Hold LSpace to activate L3 (FN keys)
-   Hold `L3` to activate L3
-   Hold `L2` to activate L2


## `L1` (\_ARROWS)

```
,-----------------------------------------------------------------------------------------.
|     |     |     |     |     |     |     |     |     |     |     | VDN | VUP | MTE |     |
|-----------------------------------------------------------------------------------------+
|        |     |  W→ |     |     |     |     |     |     |     | PUP | RWD | FFD |  PL/P  |
|-----------------------------------------------------------------------------------------+
|          |     |     |     |  L2  |     |  ←  |  ↓  |  ↑  |  →  |     |     |           |
|-----------------------------------------------------------------------------------------+
|           |     |     |     |     |  W← | PDN |     |     |     |     |     |     |     |
|-----------------------------------------------------------------------------------------+
|      |       |       |            |       |            |       |      |     |     |     |
`-----------------------------------------------------------------------------------------'
```

-   Vim arrows (HJKL)
-   Vim-like movement across words with W(ord), and B(eginning)
-   Vim-like movement across pages with N(ext), and P(revious)
-   Media controls (fine volume controls using Option+Shift)
-   Backspace/Del on N/M
-   Hold `F` to activate layer 2


## `L2` (\_HDUE)

```
,-----------------------------------------------------------------------------------------.
|     |     |     |     |     |     |     |     |     |     |     |     |     |     |RESET|
|-----------------------------------------------------------------------------------------+
|        |     |  W⌦ |     |     |     |     |     |     |     |     |     |     |        |
|-----------------------------------------------------------------------------------------+
|          |     |      |     |     |     |  ↖  |  ⇞  |  ⇟  |  ↘︎  |     |     |           |
|-----------------------------------------------------------------------------------------+
|             |     |     |     |     |  W⌫  |     |     |     |     |     |              |
|-----------------------------------------------------------------------------------------+
|      |       |       |            |       |            |       |      |     |     |     |
`-----------------------------------------------------------------------------------------'
```

-   Home, End, Page Up, Page Down
-   Delete word forward/back on W/B
-   RESET firmware on RBackspace


## `L3` (\_FN)

```
,-----------------------------------------------------------------------------------------.
|     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | VDN | VUP | MTE |     |
|-----------------------------------------------------------------------------------------+
|        |RGB_T|RGB_M|RGBH+|RGBH-|RGBS+|RGBS-|RGBV+|RGBV-|     |     | RWD | FFD |  PL/P  |
|-----------------------------------------------------------------------------------------+
|          |     |     |     |  L2  |     |  ←  |  ↓  |  ↑  |  →  |     |     |           |
|-----------------------------------------------------------------------------------------+
|             |     |     |     |     |     |     |     |     |     |     |               |
|-----------------------------------------------------------------------------------------+
|      |       |       |            |       |            |  L2  |      |     |      |     |
`-----------------------------------------------------------------------------------------'
```

-   F1-10
-   Media controls (fine volume controls using Option+Shift)
-   RGB (underglow) controls
  (https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md#keycodes)
-   Vim arrows (HJKL)
