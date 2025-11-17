#ifndef COLORS_H
#define COLORS_H

// MADE USING CHAT GPT
// IT WAS DONE JUST TO MAKE THE PROGRAM LOOK A LITTLE BIT BETTER
// THAT IS WHY I THINK THAT IT SHOULD BE ALLOWED
// BUT IF IT IS NOT ALLOWED THEN I WILL REMOVE IT IN THE FINAL EVAL 😊😊

// ===============================
//      RESET
// ===============================
#define RESET       "\033[0m"
#define RESET_ALL   "\033[0m"

// ===============================
//      TEXT STYLES
// ===============================
#define BOLD        "\033[1m"
#define DIM         "\033[2m"
#define ITALIC      "\033[3m"
#define UNDERLINE   "\033[4m"
#define BLINK       "\033[5m"
#define REVERSE     "\033[7m"
#define HIDDEN      "\033[8m"

// ===============================
//      STANDARD TEXT COLORS
// ===============================
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

// ===============================
//      BRIGHT TEXT COLORS
// ===============================
#define BRIGHT_BLACK    "\033[90m"
#define BRIGHT_RED      "\033[91m"
#define BRIGHT_GREEN    "\033[92m"
#define BRIGHT_YELLOW   "\033[93m"
#define BRIGHT_BLUE     "\033[94m"
#define BRIGHT_MAGENTA  "\033[95m"
#define BRIGHT_CYAN     "\033[96m"
#define BRIGHT_WHITE    "\033[97m"

// ===============================
//      BACKGROUND COLORS
// ===============================
#define BG_BLACK        "\033[40m"
#define BG_RED          "\033[41m"
#define BG_GREEN        "\033[42m"
#define BG_YELLOW       "\033[43m"
#define BG_BLUE         "\033[44m"
#define BG_MAGENTA      "\033[45m"
#define BG_CYAN         "\033[46m"
#define BG_WHITE        "\033[47m"

// ===============================
//      BRIGHT BACKGROUNDS
// ===============================
#define BG_BRIGHT_BLACK    "\033[100m"
#define BG_BRIGHT_RED      "\033[101m"
#define BG_BRIGHT_GREEN    "\033[102m"
#define BG_BRIGHT_YELLOW   "\033[103m"
#define BG_BRIGHT_BLUE     "\033[104m"
#define BG_BRIGHT_MAGENTA  "\033[105m"
#define BG_BRIGHT_CYAN     "\033[106m"
#define BG_BRIGHT_WHITE    "\033[107m"

// ===============================
//      256 COLOR MODE
// ===============================
// Foreground:  \033[38;5;<number>m
// Background:  \033[48;5;<number>m
//
// Use like:
//     printf(ANSI256_FG(196) "Red" RESET);
//
#define ANSI256_FG(code)  "\033[38;5;" #code "m"
#define ANSI256_BG(code)  "\033[48;5;" #code "m"

// ===============================
//      TRUE COLOR (RGB)
// ===============================
// Foreground: \033[38;2;R;G;Bm
// Background: \033[48;2;R;G;Bm
//
// Use like:
// printf(RGB_FG(255,100,0) "Orange" RESET);
//
#define RGB_FG(r,g,b)     "\033[38;2;" #r ";" #g ";" #b "m"
#define RGB_BG(r,g,b)     "\033[48;2;" #r ";" #g ";" #b "m"

// ===============================
// UNDERLINE COLOR HELPERS
// ===============================
// Modern terminals support setting underline color independently
// of the text color using the `58`/`58;5`/`58;2` sequences.
// The sequence to enable an underline in a specific color is:
// - 4 => enable underline
// - 58;5;<n> => set underline color using 256-color index
// - 58;2;<r>;<g>;<b> => set underline color using RGB
//
// Example (inline):
// printf("\033[4m\033[58;5;21m" "○ " RESET);
//
// These macros produce string literals you can concatenate with
// other color/style macros.


// 256-color underline: pass a numeric code 0-255
#define UNDERLINE_256(code) "\033[4m\033[58;5;" #code "m"


// RGB underline: pass three integers for r,g,b
#define UNDERLINE_RGB(r,g,b) "\033[4m\033[58;2;" #r ";" #g ";" #b "m"


// Some convenience predefined underline colors
#define UNDERLINE_BLUE UNDERLINE_256(21)
#define UNDERLINE_CYAN UNDERLINE_256(51)
#define UNDERLINE_MAGENTA UNDERLINE_256(201)
#define UNDERLINE_RED UNDERLINE_256(196)
#define UNDERLINE_GREEN UNDERLINE_256(46)

#endif // COLORS_H
