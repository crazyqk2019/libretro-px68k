#ifndef LIBRETRO_CORE_OPTIONS_INTL_H__
#define LIBRETRO_CORE_OPTIONS_INTL_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* https://support.microsoft.com/en-us/kb/980263 */
#pragma execution_character_set("utf-8")
#pragma warning(disable:4566)
#endif

#include <libretro.h>

/*
 ********************************
 * VERSION: 1.3
 ********************************
 *
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_JAPANESE */

/* RETRO_LANGUAGE_FRENCH */

struct retro_core_option_definition option_def_fr[] = {

   {
      "px68k_menufontsize",
      "Taille de la police du menu",
      NULL,
      {
         { "normale", NULL },
         { "grande",  NULL },
         { NULL,     NULL },
      },
      "normale"
   },
   {
      "px68k_cpuspeed",
      "Vitesse du CPU",
      "Configurez la vitesse du processeur. Peut être utilisé pour ralentir les jeux trop rapides ou pour accélérer les temps de chargement des disquettes.",
      {
         { "10Mhz",       NULL },
         { "16Mhz",       NULL },
         { "25Mhz",       NULL },
         { "33Mhz (OC)",  NULL },
         { "66Mhz (OC)",  NULL },
         { "100Mhz (OC)", NULL },
         { "150Mhz (OC)", NULL },
         { "200Mhz (OC)", NULL },
         { NULL,          NULL },
      },
      "10Mhz"
   },
   {
      "px68k_ramsize",
      "Taille de la RAM (Redémare)",
      "Définit la quantité de RAM à utiliser par le système.",
      {
         { "1MB",  NULL },
         { "2MB",  NULL },
         { "3MB",  NULL },
         { "4MB",  NULL },
         { "5MB",  NULL },
         { "6MB",  NULL },
         { "7MB",  NULL },
         { "8MB",  NULL },
         { "9MB",  NULL },
         { "10MB", NULL },
         { "11MB", NULL },
         { "12MB", NULL },
         { NULL,   NULL },
      },
      "2MB"
   },
   {
      "px68k_analog",
      "Utiliser l'Analogique",
      NULL,
      {
         { "désactivé", NULL },
         { "activé",  NULL },
         { NULL,       NULL },
      },
      "désactivé"
   },
   {
      "px68k_joytype1",
      "Type de Manette du J1",
      "Défini le type de manette du joueur 1.",
      {
         { "Défaut (2 Boutons)",  NULL },
         { "CPSF-MD (8 Boutons)",  NULL },
         { "CPSF-SFC (8 Boutons)", NULL },
         { NULL,                   NULL },
      },
      "Default (2 Buttons)"
   },
   {
      "px68k_joytype2",
      "Type de Joypad du J2",
      "Défini le type de manette du joueur 2.",
      {
         { "Défaut (2 Boutons)",  NULL },
         { "CPSF-MD (8 Boutons)",  NULL },
         { "CPSF-SFC (8 Boutons)", NULL },
         { NULL,                   NULL },
      },
      "Défaut (2 Boutons)"
   },
   {
      "px68k_joy1_select",
      "Mappage de la manette du J1",
      "Attribue une touche du clavier au bouton SELECT de la manette, car certains jeux utilisent ces touches comme boutons Démarrer ou Insérer une pièce.",
      {
         { "Défaut", NULL },
         { "XF1",     NULL },
         { "XF2",     NULL },
         { "XF3",     NULL },
         { "XF4",     NULL },
         { "XF5",     NULL },
         { "OPT1",    NULL },
         { "OPT2",    NULL },
         { "F1",      NULL },
         { "F2",      NULL },
         { NULL,      NULL },
      },
      "Défaut"
   },
   {
      "px68k_adpcm_vol",
      "Volume ADPCM",
      "Règlage du volume du canal audio ADPCM.",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { "13", NULL },
         { "14", NULL },
         { "15", NULL },
         { NULL, NULL },
      },
      "15"
   },
   {
      "px68k_opm_vol",
      "Volume OPM",
      "Règlage du volume du canal audio OPM.",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { "13", NULL },
         { "14", NULL },
         { "15", NULL },
         { NULL, NULL },
      },
      "12"
   },
#ifndef NO_MERCURY
   {
      "px68k_mercury_vol",
      "Volume Mercury",
      "Règlage du volume du canal sonore Mercury.",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { "13", NULL },
         { "14", NULL },
         { "15", NULL },
         { NULL, NULL },
      },
      "13"
   },
#endif
   {
      "px68k_disk_drive",
      "Échange de disques sur le lecteur",
      "Par défaut, l'interface native de RetroArch, d'échange de disque dans le menu, échange le disque dans le lecteur FDD1. Modifiez cette option pour échanger des disques dans le lecteur FDD0.",
      {
         { "FDD1", NULL },
         { "FDD0", NULL },
         { NULL,   NULL },
      },
      "FDD1"
   },
   {
      "px68k_disk_path",
      "Enregistrer les chemins d'accès aux disques",
      "Lorsqu'elle est activée, les chemins d'accès aux disques précédemment chargés seront enregistrés pour chaque lecteur, puis chargés automatiquement au démarrage. Lorsqu'elle est désactivé, FDD et HDD commencent à vide.",
      {
         { "activé",  NULL },
         { "désactivé", NULL },
         { NULL,       NULL },
      },
      "activé"
   },

   /* from PX68K Menu */
   {
      "px68k_joy_mouse",
      "Manette /sourie",
      "Sélectionner la [sourie] ou la [manette] pour contrôler le pointeur de sourie dans les jeux..",
      {
         { "Sourie",    NULL},
         { "Manette", NULL}, /* unimplemented yet */
         { NULL,       NULL },
      },
      "Manette"
   },
   {
      "px68k_vbtn_swap",
      "Echange des boutons",
      "Echange le BOUTON1 et le BOUTON2 quand une manette 2 boutons est sélectionné.",
      {
         { "BOUTON1 BOUTON2", NULL},
         { "BOUTON2 BOUTON1", NULL},
         { NULL,          NULL },
      },
      "BOUTON1 BOUTON2"
   },
   {
      "px68k_no_wait_mode",
      "Mode sans attente",
      "Lorsque ce mode est [activé], le cœur s'exécute aussi vite que possible. Cela peut provoquer une désynchronisation audio mais permet une avance rapide. Il est recommandé de définir ce paramètre à [désactivé].",
      {
         { "désactivé", NULL},
         { "activé",  NULL},
         { NULL,       NULL },
      },
      "désactivé"
   },
   {
      "px68k_frameskip",
      "Saut d'images",
      "Choisissez le nombre d'images à ignorer pour améliorer les performances au détriment de la fluidité visuelle.",
      {
         { "Toutes les images",      NULL },
         { "1/2 image",       NULL },
         { "1/3 image",       NULL },
         { "1/4 image",       NULL },
         { "1/5 image",       NULL },
         { "1/6 image",       NULL },
         { "1/8 image",       NULL },
         { "1/16 image",      NULL },
         { "1/32 image",      NULL },
         { "1/60 image",      NULL },
         { "Auto image Skip", NULL },
         { NULL,   NULL },
      },
      "Toutes les images"
   },

   { NULL, NULL, NULL, {{0}}, NULL }
};

/* RETRO_LANGUAGE_SPANISH */

/* RETRO_LANGUAGE_GERMAN */

/* RETRO_LANGUAGE_ITALIAN */

/* RETRO_LANGUAGE_DUTCH */

/* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */

/* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */

/* RETRO_LANGUAGE_RUSSIAN */

/* RETRO_LANGUAGE_KOREAN */

/* RETRO_LANGUAGE_CHINESE_TRADITIONAL */

/* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
struct retro_core_option_definition option_defs_chs[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "px68k_menufontsize",
      "菜单字体大小",
      NULL,
      {
         { "normal", "正常" },
         { "large",  "大字体" },
         { NULL,     NULL },
      },
      "normal"
   },
   {
      "px68k_cpuspeed",
      "CPU速度",
      "设置CPU速度，可以用来减慢运行过快的游戏或者加速软盘载入。",
      {
         { "10Mhz",       NULL },
         { "16Mhz",       NULL },
         { "25Mhz",       NULL },
         { "33Mhz (OC)",  NULL },
         { "66Mhz (OC)",  NULL },
         { "100Mhz (OC)", NULL },
         { "150Mhz (OC)", NULL },
         { "200Mhz (OC)", NULL },
         { NULL,          NULL },
      },
      "10Mhz"
   },
   {
      "px68k_ramsize",
      "内存大小（需重启）",
      "设置系统内存大小。",
      {
         { "1MB",  NULL },
         { "2MB",  NULL },
         { "3MB",  NULL },
         { "4MB",  NULL },
         { "5MB",  NULL },
         { "6MB",  NULL },
         { "7MB",  NULL },
         { "8MB",  NULL },
         { "9MB",  NULL },
         { "10MB", NULL },
         { "11MB", NULL },
         { "12MB", NULL },
         { NULL,   NULL },
      },
      "2MB"
   },
   {
      "px68k_analog",
      "使用模拟摇杆",
      NULL,
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL,       NULL },
      },
      "disabled"
   },
   {
      "px68k_joytype1",
      "P1手柄类型",
      "设置玩家1的手柄类型。",
      {
         { "Default (2 Buttons)",  "缺省（2键）" },
         { "CPSF-MD (8 Buttons)",  "CPSF-MD（8键）" },
         { "CPSF-SFC (8 Buttons)", "CPSF-SFC（8键）" },
         { NULL,                   NULL },
      },
      "Default (2 Buttons)"
   },
   {
      "px68k_joytype2",
      "P2手柄类型",
      "设置玩家2的手柄类型。",
      {
         { "Default (2 Buttons)",  "缺省（2键）" },
         { "CPSF-MD (8 Buttons)",  "CPSF-MD（8键）" },
         { "CPSF-SFC (8 Buttons)", "CPSF-SFC（8键）" },
         { NULL,                   NULL },
      },
      "Default (2 Buttons)"
   },
   {
      "px68k_joy1_select",
      "P1手柄选择键映射",
      "设置一个键盘按键为手柄的选择键，有些游戏用这些键作为开始或者投币键。",
      {
         { "Default", "缺省" },
         { "XF1",     NULL },
         { "XF2",     NULL },
         { "XF3",     NULL },
         { "XF4",     NULL },
         { "XF5",     NULL },
         { "OPT1",    NULL },
         { "OPT2",    NULL },
         { "F1",      NULL },
         { "F2",      NULL },
         { NULL,      NULL },
      },
      "Default"
   },
   {
      "px68k_adpcm_vol",
      "ADPCM音量",
      "设置ADPCM音频通道的音量。",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { "13", NULL },
         { "14", NULL },
         { "15", NULL },
         { NULL, NULL },
      },
      "15"
   },
   {
      "px68k_opm_vol",
      "OPM音量",
      "设置OPM音频通道的音量。",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { "13", NULL },
         { "14", NULL },
         { "15", NULL },
         { NULL, NULL },
      },
      "12"
   },
#ifndef NO_MERCURY
   {
      "px68k_mercury_vol",
      "Mercury音量",
      "设置Mercury音频通道的音量。",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { "11", NULL },
         { "12", NULL },
         { "13", NULL },
         { "14", NULL },
         { "15", NULL },
         { NULL, NULL },
      },
      "13"
   },
#endif
   {
      "px68k_disk_drive",
      "Swap Disks on Drive",
      "缺省情况下，在RetroArch菜单中使用磁盘交换功能会交换FDD1软驱中的磁盘。\n"
	  "更改此选项可交换FDD0软件中的磁盘。",
      {
         { "FDD1", NULL },
         { "FDD0", NULL },
         { NULL,   NULL },
      },
      "FDD1"
   },
   {
      "px68k_disk_path",
      "保存磁盘路径",
      "如果启用，每个驱动器之前载入的磁盘路径会保存，下次启动时自动载入。\n"
	  "如果禁用，软驱和硬盘启动时为空。",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL,       NULL },
      },
      "enabled"
   },

   /* from PX68K Menu */
   {
      "px68k_joy_mouse",
      "手柄/鼠标",
      "选择[鼠标]或[手柄]控制游戏内鼠标指针。",
      {
         { "Mouse",    "鼠标"},
         { "Joystick", "手柄（暂未实现）"}, /* unimplemented yet */
         { NULL,       NULL },
      },
      "Mouse"
   },
   {
      "px68k_vbtn_swap",
      "按键交换",
      "使用2键手柄时，交换TRIG1和TRIG2键。",
      {
         { "TRIG1 TRIG2", NULL},
         { "TRIG2 TRIG1", NULL},
         { NULL,          NULL },
      },
      "TRIG1 TRIG2"
   },
   {
      "px68k_no_wait_mode",
      "无等待模式",
      "设为启用时，内核以尽可能快的速度运行。\n"
	  "可能导致音频不同步，但是允许快进。建议设为禁用。",
      {
         { "disabled", NULL},
         { "enabled",  NULL},
         { NULL,       NULL },
      },
      "disabled"
   },
   {
      "px68k_frameskip",
      "跳帧",
      "选择跳过的帧数，以牺牲画面流畅度换取性能提升。",
      {
         { "Full Frame",      "无跳帧" },
         { "1/2 Frame",       "跳过1/2帧" },
         { "1/3 Frame",       "跳过1/3帧" },
         { "1/4 Frame",       "跳过1/4帧" },
         { "1/5 Frame",       "跳过1/5帧" },
         { "1/6 Frame",       "跳过1/6帧" },
         { "1/8 Frame",       "跳过1/8帧" },
         { "1/16 Frame",      "跳过1/16帧" },
         { "1/32 Frame",      "跳过1/32帧" },
         { "1/60 Frame",      "跳过1/60帧" },
         { "Auto Frame Skip", "自动跳帧" },
         { NULL,   NULL },
      },
      "Full Frame"
   },

   { NULL, NULL, NULL, {{0}}, NULL }
};

/* RETRO_LANGUAGE_ESPERANTO */

/* RETRO_LANGUAGE_POLISH */

/* RETRO_LANGUAGE_VIETNAMESE */

/* RETRO_LANGUAGE_ARABIC */

/* RETRO_LANGUAGE_GREEK */

/* RETRO_LANGUAGE_TURKISH */

#ifdef __cplusplus
}
#endif

#endif
