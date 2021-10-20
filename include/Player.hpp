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
        void RefreshPos();
    };
    void OnP1KeysPressed(HANDLE hWritePipe);
    void OnP2KeysPressed(HANDLE hWritePipe);
    
} // namespace pong


#endif