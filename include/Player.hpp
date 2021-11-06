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
        uint8_t pos;
    public:
        Player(uint8_t player);
        void Up();
        void Down();
        ~Player();
        void StartThread();
        [[noreturn]] static void OnP1KeysPressed(Player *player);
        [[noreturn]] static void OnP2KeysPressed(Player *player);
        uint8_t GetPos();
    };

    
       
} // namespace pong


#endif