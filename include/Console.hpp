#ifndef CONSOLE_HPP_INCLUDED
#define CONSOLE_HPP_INCLUDED

#include <Windows.h>
#include <string>
#include <iostream> 
#include <sstream>
#include <Player.hpp>

namespace pong      
{
    class Console
    {
    private:
       void gtxy(short x, short y);
       CONSOLE_SCREEN_BUFFER_INFOEX consoleInfo{};
       HANDLE hConsoleOutput;
       HWND hWindowConsole;
       std::stringstream ssm;
       void FlushSsm();
    public:
        explicit Console(bool debug);
        ~Console();
        void Refresh(const pong::Player *p1, const pong::Player *p2);
    };
    
    
    
}   


#endif