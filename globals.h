#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>

enum {
    kDebug_ERROR = 0,
    kDebug_WARN,
    kDebug_INFO,
    kDebug_VERBOSE
};

extern int _framesPerSec;
extern bool _loadState;
extern bool _saveState;
extern int _slotState;
extern bool _takeScreenshot;
extern int _screenshot;
extern SDL_Window* window;
extern SDL_GLContext glContext;

#endif // GLOBALS_H