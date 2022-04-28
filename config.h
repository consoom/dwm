/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 4;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 4;       /* vert inner gap between windows */
static const unsigned int gappoh    = 4;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 4;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=12", "JoyPixels:pixelsize=11:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=12";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

#define TERMINAL "st"

typedef struct {
       const char *name;
       const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
//const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "ranger", NULL };
//const char *spcmd3[] = {"keepassxc", NULL };
static Sp scratchpads[] = {
       /* name          cmd  */
       {"spterm",      spcmd1},
       //{"spranger",    spcmd2},
       //{"keepassxc",   spcmd3},
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance      title     tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,         NULL,     0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,         NULL,     1 << 8,    0,          0,          -1,        -1 },
	{ "St",      NULL,         NULL,     0,         0,          1,           0,        -1 },
        { NULL,      "spterm",	   NULL,     SPTAG(0),  1,	    1,           0,        -1 },
        //{ NULL,    "spfm",	   NULL,     SPTAG(1),  1,	    0,           0,	   -1 },
        //{ NULL,    "keepassxc",  NULL,     SPTAG(2),  0,          0,           0,	   -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default: master on left, slaves on right */
	{ "TTT",      bstack }, /* master on top, slaves on bottom */
	{ "[@]",      spiral }, /* fibonacci */
	{ "[\\]",     dwindle }, /* decreasing right and leftward */
	{ "[M]",      monocle }, /* only one visible window */
	{ "H[]",      deck }, /* master on left, only one visible slave window on the right, à la monocle */
	{ "###",      nrowgrid }, /* grid view, customizable number of rows by changing number of master windows */
	{ "|M|",      centeredmaster }, /* master in the middle, slaves leftward and rightward */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* helper for spawning shell-less commands; no middleman needed */
#define SPAWN(...) { .v = (const char*[]){ __VA_ARGS__, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_equal,  incrgaps,       {.i = +1 } },
	{ MODKEY,                       XK_minus,  incrgaps,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_minus,  togglegaps,     {0} },
	{ MODKEY|ShiftMask,             XK_equal,  defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_F1,     setlayout,      {.v = &layouts[0]} }, /* tile */
	{ MODKEY,                       XK_F2,     setlayout,      {.v = &layouts[1]} }, /* bstack */
	{ MODKEY,                       XK_F3,     setlayout,      {.v = &layouts[2]} }, /* spiral */
	{ MODKEY,                       XK_F4,     setlayout,      {.v = &layouts[3]} }, /* dwindle */
	{ MODKEY,                       XK_F5,     setlayout,      {.v = &layouts[4]} }, /* monocle */
	{ MODKEY,                       XK_F6,     setlayout,      {.v = &layouts[5]} }, /* deck */
	{ MODKEY,                       XK_F7,     setlayout,      {.v = &layouts[6]} }, /* nrowgrid */
	{ MODKEY,                       XK_F8,     setlayout,      {.v = &layouts[7]} }, /* centered master */
	{ MODKEY,                       XK_F9,     setlayout,      {.v = &layouts[8]} }, /* floating */
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_y,      togglescratch,  {.ui = 0 } },
	{ MODKEY|ShiftMask,		XK_s,      togglesticky,   {0} },
	{ MODKEY|ShiftMask,             XK_F5,     xrdb,           {.v = NULL } },

	// program shortcuts
	{ MODKEY,			XK_w,      spawn,	   SHCMD("$BROWSER") },
	{ MODKEY,	                XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_grave,  spawn,          {.v = dmenucmd } },

	// audio controls
	{ 0, XF86XK_AudioMute,		spawn,     SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,    SHCMD("pamixer -i 5; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,     SHCMD("pamixer -d 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY, XF86XK_AudioRaiseVolume,	spawn,     SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY, XF86XK_AudioLowerVolume,	spawn,     SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY, XF86XK_AudioMute,		spawn,     SHCMD("pamixer --set-volume 100; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioPause,		spawn,     SPAWN("playerctl", "play-pause") },
	{ 0, XF86XK_AudioPlay,		spawn,     SPAWN("playerctl", "play-pause") },
	{ 0, XF86XK_AudioStop,		spawn,     SPAWN("playerctl", "stop") },
	{ 0, XF86XK_AudioPrev,		spawn,     SPAWN("playerctl", "previous") },
	{ 0, XF86XK_AudioNext,		spawn,     SPAWN("playerctl", "next") },

	// screenshot shortcuts
	{ MODKEY, XK_p,			spawn,     SHCMD("maim --select --hidecursor | xclip -selection clipboard -t image/png") },
	{ MODKEY|ShiftMask, XK_p,	spawn,     SHCMD("maim | xclip -selection clipboard -t image/png") },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_Delete, quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

