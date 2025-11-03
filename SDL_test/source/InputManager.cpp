#include "InputManager.h"

bool InputManager::Listen()
{
    for (std::unordered_map<Sint32, KeyState>::iterator it = _keyReferences.begin(); it != _keyReferences.end(); it++) {
        if (it->second == DOWN) {
            it->second = HOLD;
        }
        if (it->second == UP) {
            it->second = RELISE;
        }

    }

    SDL_GetMouseState(&_mouseX, &_mouseY);
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT){
            return true;
        }
        else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
           if(event.button.button == SDL_BUTTON_LEFT)
            leftClick = true;
        }
        else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
            if (event.button.button == SDL_BUTTON_LEFT)
                leftClick = false;
        }
        else if (event.type == SDL_EVENT_KEY_DOWN) {

            if (_keyReferences[event.key.key] != HOLD) {
                _keyReferences[event.key.key] = DOWN;
            }
        }

    }

    return false;
}

bool InputManager::GetEvent(Sint32 input, KeyState inputEvent)
{
    return _keyReferences[input] == inputEvent;
}

