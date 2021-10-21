#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <Windows.h>
#include <utility>

namespace pong
{
    class Player
    {
    private: 
        HANDLE hThread;
    public:
        Player(uint8_t player);
        ~Player();
        void StartThread();
        uint8_t pos;
    };
    void OnP1KeysPressed(uint8_t *pos);
    void OnP2KeysPressed(uint8_t *pos);
    
} // namespace pong


#endif