# My build of dwm

My personal build of dwm

## About
I use this repository as a way to version control any changes I make to my window manager. My window manager contains keybindings and other customizations that are adopted to my own workflow, and thus, aren't usable for everyone. You might however take inspiration out this build or contribute and suggest improvements. A lot of keybindings and general tools in this build rely on other programs and configurations that I keep track of in my [dotfiles repository](https://github.com/consoom/comfydots).

## Patches done to dwm
This build of dwm is based on [dwm 6.3](https://dl.suckless.org/dwm/dwm-6.3.tar.gz) (2022-01-07) and modified with patches and other changes of the sourcecode. I have kept all *.diff* files I used to patch dwm in [master/patches](https://github.com/consoom/dwm/tree/master/patches):

- [actualfullscreen](https://github.com/consoom/dwm/blob/master/patches/dwm-actualfullscreen-20211013-cb3f58a.diff) ([source](https://dwm.suckless.org/patches/actualfullscreen/)) — allows windows to get into fullscreen with a toggle
- [attachasideandbelow](https://github.com/consoom/dwm/blob/master/patches/dwm-attachasideandbelow-20200702-f04cac6.diff) ([source](https://dwm.suckless.org/patches/attachasideandbelow/)) — attaches newly spawned windows below the selected window, as a slave
- [noborderselflickerfix](https://github.com/consoom/dwm/blob/master/patches/dwm-noborderselflickerfix-2022042627-d93ff48803f0.diff) ([source](https://dwm.suckless.org/patches/noborder/)) — removes the border around a window if there is only one visible
- [scratchpads](https://github.com/consoom/dwm/blob/master/patches/dwm-scratchpads-20200414-728d397b.diff) ([source](https://dwm.suckless.org/patches/scratchpads/)) — adds scratchpad-like functionality, configurable in config.h
- [statuscmd](https://github.com/consoom/dwm/blob/master/patches/dwm-statuscmd-20210405-67d76bd.diff) ([source](https://dwm.suckless.org/patches/statuscmd/)) — makes it possible to signal button presses on the statusbar to programs like [dwmblocks](https://github.com/consoom/dwmblocks)
- [sticky](https://github.com/consoom/dwm/blob/master/patches/dwm-sticky-6.1.diff) ([source](https://dwm.suckless.org/patches/sticky/)) — adds the ability to toggle windows to be displayed in all tags, and return to its original tag when turned off
- [swallow](https://github.com/consoom/dwm/blob/master/patches/dwm-swallow-20201211-61bb8b2.diff) ([source](https://dwm.suckless.org/patches/swallow/)) — makes certain programs "swallowable" by a terminal application
- [vanitygaps](https://github.com/consoom/dwm/blob/master/patches/dwm-vanitygaps-6.2.diff) ([source](https://dwm.suckless.org/patches/vanitygaps/)) — adds gaps and new layouts to dwm
- [xrdb](https://github.com/consoom/dwm/blob/master/patches/dwm-xrdb-6.2.diff) ([source](https://dwm.suckless.org/patches/xrdb/)) — makes it possible to dynamically reload the colors used in dwm via xrdb

## Layouts
This build includes the following layouts:
- *tile* — default layout: masters on left, slaves on right
- *bstack* — masters on top, slaves on bottom
- *spiral* — fibonacci spiral
- *dwindle* — fibonacci variation
- *monocle* — only one visible window
- *deck* — masters on left, only one visible slave window on the right; à la monocle
- *nrowgrid* — grid view, customizable number of rows by changing the number of master windows
- *centeredmaster* — masters in the middle, slaves leftward and rightward
- *floating* — no tiling at all

The keybindings for the layouts can be found [on this page in the keybindings section](https://github.com/consoom/dwm#layout-keybindings).

## Installation
I don't recommend using my personal build without changing the configuration, as it's adopted to satisfy my own workflow. It's supposed to be installed and used  together with my [dotfiles](https://github.com/consoom/comfydots). Here are the install instructions:
```
$ git clone https://github.com/consoom/dwm
$ cd dwm
$ sudo make clean install
```
**Important: you need to install `libxft-bgra` (available in the AUR on arch), otherwise dwm will crash. This is caused by an issue in the normal libxft package that breaks rendering colored characters. [Read more](https://gitlab.freedesktop.org/xorg/lib/libxft/-/merge_requests/1).**

## Keybindings

### General keybindings
| **Modifier**            | **Key**   | **Action**                                        |
|-------------------------|-----------|---------------------------------------------------|
|           Mod           |     b     | Toggle bar                                        |
|           Mod           |     j     | Go to next window on stack                        |
|           Mod           |     k     | Go to previous window on stack                    |
|           Mod           |     i     | Increase the amount of masters                    |
|           Mod           |     d     | Decrease the amount of masters                    |
|           Mod           |     h     | Decrease the amount of space the masters takes up |
|           Mod           |     l     | Increase the amount of space the masters takes up |
|       Mod + Shift       |   Return  | Make selected window a master                     |
|           Mod           |     =     | Increase gaps with 1                              |
|           Mod           |     -     | Decrease gaps with 1                              |
|       Mod + Shift       |     -     | Toggle gaps                                       |
|       Mod + Shift       |     =     | Reset gap size to default                         |
|           Mod           |    Tab    | Go to previous viewed tag                         |
|       Mod + Shift       |     c     | Kill a window                                     |
|       Mod + Shift       |   Space   | Toggle floating mode for the selected window      |
|       Mod + Shift       |     f     | Toggle fullscreen for the selected window         |
|           Mod           |     y     | Open a st window in a scratchpad (for now)        |
|           Mod           |     s     | Make a window sticky                              |
|       Mod + Shift       |     F5    | Reload Xresources and change colors of dwm        |
|           Mod           |     p     | Screenshot a selection and copy to clipboard      |
|       Mod + Shift       |     p     | Screenshot the whole screen and copy to clipboard |
|     Mod (+ Control)     |    1-9    | View tag n                                        |
| Mod + Shift (+ Control) |    1-9    | Move window to tag n                              |
|           Mod           |     0     | View all open windows on all tags                 |
|       Mod + Shift       |     0     | Give the selected window all tags                 |
|       Mod + Shift       |   Delete  | Quit dwm                                          |

### Layout keybindings
| **Modifier**            | **Key**   | **Action**                                        |
|-------------------------|-----------|---------------------------------------------------|
|           Mod           |     F1    | Use tile layout                                   |
|           Mod           |     F2    | Use bstack layout                                 |
|           Mod           |     F3    | Use spiral layout                                 |
|           Mod           |     F4    | Use dwindle layout                                |
|           Mod           |     F5    | Use monocle layout                                |
|           Mod           |     F6    | Use deck layout                                   |
|           Mod           |     F7    | Use nrowgrid layout                               |
|           Mod           |     F8    | Use centered master layout                        |
|           Mod           |     F9    | Use floating layout                               |
|           Mod           |   Space   | Toggle between last used layouts                  |

### Audio keybindings
| **Modifier**            | **Key**   | **Action**                                        |
|-------------------------|-----------|---------------------------------------------------|
|          (Mod)          |  Volume + | Increase the volume with 5 (mod: ignore limit)    |
|          (Mod)          |  Volume - | Decrease the volume with 5 (mod: ignore limit)    |
|       Mod + Shift       |    Mute   | Reset the audio to 100                            |
|          None           |    Mute   | Mute the audio                                    |
|           Mod           |    Mute   | Open audio mixer                                  |
|          None           | Play/Pause| Pause or continue the audio                       |
|          None           | Next/Prev | Go to the next or previous audio                  |

### Launcher keybindings
| **Modifier**            | **Key**   | **Action**                                        |
|-------------------------|-----------|---------------------------------------------------|
|           Mod           |   Return  | Launch the terminal                               |
|           Mod           |     w     | Launch the browser                                |
|           Mod           | ` (grave) | Launch dmenu                                      |
