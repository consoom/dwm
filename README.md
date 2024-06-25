# My build of dwm

My personal build of dwm

## About
I use this repository as a way to version control any changes I make to my window manager. My window manager contains keybindings and other customizations that are adopted to my own workflow, thus making it dependent on other programs and tools I use. I track all of the required tools (including this window manager itself) in my [dotfiles repository](https://github.com/consoom/comfydots) to form a coherent and reproducible desktop environment.

## Features
This build of dwm is based on [dwm 6.5](https://dl.suckless.org/dwm/dwm-6.5.tar.gz) (2024-03-19) and is modified with patches and other changes to the source code outside of patches itself. I have kept all used *.diff files* in [master/patches](https://github.com/consoom/dwm/tree/master/patches). Mentionable additions are:

- [actualfullscreen](https://github.com/consoom/dwm/blob/master/patches/dwm-actualfullscreen-20211013-cb3f58a.diff) ([source](https://dwm.suckless.org/patches/actualfullscreen/)) — allows windows to get into fullscreen with a toggle
    - [losefullscreen](https://github.com/consoom/dwm/blob/master/patches/dwm-losefullscreen-6.3.diff) ([source](https://github.com/bakkeby/patches/blob/3aa6a4587c420faabc22aaf6dc2740bb879be89d/dwm/dwm-losefullscreen-6.3.diff)) — exit fullscreen when new windows appear
- [alwayscenter](https://github.com/consoom/dwm/blob/master/patches/dwm-alwayscenter-20200625-f04cac6.diff) ([source](https://dwm.suckless.org/patches/alwayscenter/)) — makes floating windows spawn in the center
- [attachasideandbelow](https://github.com/consoom/dwm/blob/master/patches/dwm-attachasideandbelow-6.4.diff) ([source](https://dwm.suckless.org/patches/attachasideandbelow/)) — attaches newly spawned windows below the selected window, as a slave
- [hide vacant tags](https://github.com/consoom/dwm/blob/master/patches/dwm-hide_vacant_tags-6.4.diff) ([source](https://dwm.suckless.org/patches/hide_vacant_tags/)) — hides empty tags in the bar
- [removeborder](https://github.com/consoom/dwm/blob/master/patches/dwm-removeborder-20220626-d3f93c7.diff) ([source](https://dwm.suckless.org/patches/removeborder/)) — removes the border around a window if there is only one window visible
    - customizable with the "solitarygaps" rule in config.h (0 means no border/gaps when only one window is visible (default), 1 means display border/gaps anyway)
- [pertag](https://github.com/consoom/dwm/blob/master/patches/dwm-pertag_with_sel-20231003-9f88553.diff) ([source](https://dwm.suckless.org/patches/pertag/)) — keeps layout configurations seperated between tags
- [resetlayout](https://github.com/consoom/dwm/blob/master/patches/dwm-resetlayout-6.2.diff) ([source](https://dwm.suckless.org/patches/resetlayout/)) — resets the layout configuration of a tag when there is only one window left
- [scratchpads](https://github.com/consoom/dwm/blob/master/patches/dwm-scratchpads-20200414-728d397b.diff) ([source](https://dwm.suckless.org/patches/scratchpads/)) — adds scratchpad-like functionality, configurable in config.h
- [shiftview](https://github.com/consoom/dwm/blob/master/shiftview.c) ([source](https://dwm.suckless.org/patches/nextprev/)) — cycle through tags
- [stacker](https://github.com/consoom/dwm/blob/master/patches/dwm-stacker-6.2.diff) ([source](https://dwm.suckless.org/patches/stacker/)) — move/focus windows through the stack
	- the mouse cursor will be 'warped' to the center of a window upon moving/focusing a window if the mouse is used to do so
- [status2d](https://github.com/consoom/dwm/blob/master/patches/dwm-status2d-statuscmd-6.4.diff) ([source](https://git.speedie.site/speedie/patches/src/commit/fc507e92d68ce579b37190fdab9ef108bbb550f2/dwm-status2d-statuscmd-6.4.diff)) — adds text color and rectangle drawing functionality to the statusbar
    - [status2d-xrdb](https://github.com/consoom/dwm/blob/master/patches/dwm-status2d-xrdb-6.2.diff) ([source](https://dwm.suckless.org/patches/status2d/)) — makes it possible to use terminal colors in the statusbar
- [statuscmd](https://github.com/consoom/dwm/blob/master/patches/dwm-status2d-statuscmd-6.4.diff) ([source](https://git.speedie.site/speedie/patches/src/commit/fc507e92d68ce579b37190fdab9ef108bbb550f2/dwm-status2d-statuscmd-6.4.diff)) — makes it possible to signal button presses on the statusbar to programs like [dwmblocks](https://github.com/consoom/dwmblocks)
- [sticky](https://github.com/consoom/dwm/blob/master/patches/dwm-sticky-2022-12-05-d47ba0b.diff) ([source](https://dwm.suckless.org/patches/sticky/)) — adds the ability to toggle windows to be displayed on every tag, and return to its original tag when turned off
- [swallow](https://github.com/consoom/dwm/blob/master/patches/dwm-swallow-6.3.diff) ([source](https://dwm.suckless.org/patches/swallow/)) — makes certain programs 'swallowable' by a terminal application
- [vanitygaps](https://github.com/consoom/dwm/blob/master/patches/dwm-cfacts-vanitygaps-6.4_combo.diff) ([source](https://dwm.suckless.org/patches/vanitygaps/)) — adds window gaps, 'weights' and new layouts to tiling mode
- [xrdb](https://github.com/consoom/dwm/blob/master/patches/dwm-xrdb-6.4.diff) ([source](https://dwm.suckless.org/patches/xrdb/)) — makes it possible to dynamically reload the colors used in dwm via xrdb

### Layouts
This build includes keybindings for the following tiling layouts:
- *tile* — default layout: masters on left, slaves on right
- *bstack* — masters on top, slaves on bottom
- *spiral* — fibonacci spiral
- *dwindle* — fibonacci variation
- *monocle* — only one visible window
- *deck* — masters on left, only one visible slave window on the right; à la monocle
- *nrowgrid* — grid view, customizable number of rows by changing the number of master windows
- *centeredmaster* — masters in the middle, slaves leftward and rightward
- *floating* — no tiling at all

## Installation & usage
This program is supposed to be used in tandem with my [dotfiles](https://github.com/consoom/comfydots), as it relies on some other software, environment variables, configurations and the like. Although my dotfiles repository includes a bootstrapping script, I don't recommend using my personal configurations without first changing them to your own needs.

### Keybindings

#### General keybindings
| **Modifier**            | **Key**   | **Action**                                        |
|-------------------------|-----------|---------------------------------------------------|
|           Mod           |     b     | Toggle bar                                        |
|      Mod (+ Shift)      |     j     | Focus/(move window to) next window in stack       |
|      Mod (+ Shift)      |     k     | Focus/(move window to) previous window in stack   |
|      Mod (+ Shift)      |     r     | Focus/(move window to) previous selected window   |
|      Mod (+ Shift)      |     c     | Focus/(move window to) first window in stack      |
|           Mod           |     i     | Increase the amount of masters                    |
|           Mod           |     d     | Decrease the amount of masters                    |
|           Mod           |     l     | Increase the amount of space the masters takes up |
|           Mod           |     h     | Decrease the amount of space the masters takes up |
|       Mod + Shift       |     l     | Increase the weight of the selected window        |
|       Mod + Shift       |     h     | Decrease the weight of the selected window        |
|       Mod + Shift       |   Return  | Make selected window a master                     |
|           Mod           |     =     | Increase gaps with 1                              |
|           Mod           |     -     | Decrease gaps with 1                              |
|       Mod + Shift       |     -     | Toggle gaps                                       |
|       Mod + Shift       |     =     | Reset gap size to default                         |
|       Mod + Shift       |     q     | Kill a window                                     |
|       Mod + Shift       |   Space   | Toggle floating mode for the selected window      |
|       Mod + Shift       |     f     | Toggle fullscreen for the selected window         |
|           Mod           |     y     | Open a st window in a scratchpad (for now)        |
|           Mod           |     s     | Make a window sticky                              |
|       Mod + Shift       |     F5    | Reload Xresources and change colors of dwm        |
|           Mod           |     p     | Screenshot a selection and copy to clipboard      |
|       Mod + Shift       |     p     | Screenshot the whole screen and copy to clipboard |
| Mod (+Shift) (+ Control)|    1-9    | View/(move window to) tag n (control: more tags)  |
|      Mod (+ Shift)      |     0     | View/(move window to) all tags                    |
|      Mod (+ Shift)      |     ;     | View/(move window to) next tag                    |
|      Mod (+ Shift)      |     g     | View/(move window to) previous tag                |
|           Mod           |    Tab    | View previous viewed tag                          |
|       Mod + Shift       |   Delete  | Quit dwm                                          |

#### Mouse keybindings
| **Modifier**            | **Button**   | **Action**                                     |
|-------------------------|-----------|---------------------------------------------------|
|      Mod (+ Shift)      |  Previous | Focus/(move window to) next window in stack       |
|      Mod (+ Shift)      |    Next   | Focus/(move window to) previous window in stack   |

#### Layout keybindings
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

#### Audio keybindings
| **Modifier**            | **Key**   | **Action**                                        |
|-------------------------|-----------|---------------------------------------------------|
|          (Mod)          |  Volume + | Increase the volume with 5 (mod: ignore limit)    |
|          (Mod)          |  Volume - | Decrease the volume with 5 (mod: ignore limit)    |
|       Mod + Shift       |    Mute   | Reset the audio to 100                            |
|          None           |    Mute   | Mute the audio                                    |
|           Mod           |    Mute   | Open audio mixer                                  |
|          None           | Play/Pause| Pause or continue the audio                       |
|          None           | Next/Prev | Go to the next or previous audio                  |

#### Launcher keybindings
| **Modifier**            | **Key**   | **Action**                                        |
|-------------------------|-----------|---------------------------------------------------|
|           Mod           |   Return  | Launch the terminal                               |
|           Mod           |     w     | Launch the browser                                |
|           Mod           | ` (grave) | Launch dmenu                                      |
|           Mod           |   Escape  | Launch power management options                   |
