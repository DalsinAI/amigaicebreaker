IceBreaker 2.2.1 for AmigaOS 3.x
================================

IceBreaker (Matthew Miller), the JezzBall-style action puzzle game: melt
lines across the iceberg to box the bouncing penguins into ever smaller
pieces, until 80% of it is gone; a penguin hitting a line in progress
costs a life. Themes change the pictures and sounds. For AmigaOS 3.x on a
68040 or 68060 with an FPU and an RTG screen, on OpenGPU's SDL 1.2
(sdl12-compat).

Base: icebreaker_2.2.1.orig.tar.xz from Debian (sha256
330a80d42141796432b07aa2ab1b7211323c55be9588d1b3f59f042b2e55be22), with
Debian's patches (2.2.1-3) as the second commit. Branch
team2/icebreaker-amiga.

Status: plays in the lab (Instance-45 on GFOpenUp 0.8.19, 6 November
2026): the intro, the first start's welcome, level 1 (a line melted, the
iceberg cleared by 2%, a penguin hitting a line and a life lost), and the
window's close gadget back to the Shell, the settings written to
icebreaker.cfg. The lab is muted, so the sounds were not heard there.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- GFOpenUp 0.8.18 or later (LIBS:OpenGPU/SDL2.module). Everything else is
  in the program.


How to play
-----------

Open the IceBreaker icon, or run IceBreaker from a Shell. It opens a small
window. The left mouse button melts a line from where the pointer is; the
right button switches between up-and-down and sideways lines. MENU (or M)
has the options, the themes and the high scores; P pauses. The window's
close gadget quits. ReadMe-upstream in the drawer is upstream's README,
ReadMe-themes how to make a theme. The pictures, sounds and themes are in
the drawer's data/; the settings and high scores are icebreaker.cfg and
icebreaker.scores in the drawer.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers and the OpenGPU kit
(see the Makefile's head). The drawer is dist/IceBreaker (and
dist/IceBreaker.info).


What was changed
----------------

- icebreaker.h, icebreaker.c: on AmigaOS the settings, high scores and
  their lock file are in the drawer (icebreaker.cfg, icebreaker.scores,
  icebreaker.lck), the player's name is $USER (or "Penguin"), random() is
  rand(); no getpwuid() (amiga/include/pwd.h only for the header).
- lock.c: one user, so the lock file is made if missing and locking always
  succeeds (libnix has no fcntl() locks; the high scores could not be
  saved).
- amiga/amiga_paths.c (-Wl,--wrap=fopen, open, opendir, stat, mkdir and
  chdir, from the Berusky and Heroes ports): the game joins "PROGDIR:" and
  a name with "/", and to AmigaDOS ":/" is the parent drawer; it is folded.
- amiga/Makefile.amigaos builds upstream's makefile's sources, the data at
  PROGDIR:data.
- No SDL_mixer 1.2 for OpenGPU's SDL 1.2: the Team's
  amiga/sdl_mixer_lite.c (WAV), from the Circus Linux! port; libmikmod
  comes with it (amiga/libmikmod) though the game has no music.
- amiga/stack.c: 256 KB of stack.


Licences
--------

IceBreaker, its pictures, themes and sounds: GPL 2 or later (COPYING.txt;
upstream's README: the sounds were made for it or taken from
freely-licensed sources, the penguin drawn after Pingus's). libmikmod: LGPL
2 or later (COPYING-libmikmod.txt). The Amiga files (amiga/): the AmiCradle
Team, GPL 2 or later, except the mixer, which comes from the Team's Wizznic
port and is GPL 3 or later, so the program as built here is GPL 3 or
later; the icon is upstream's icebreaker_128.png, made smaller.
