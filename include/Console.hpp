#ifndef CONSOLE_HPP_INCLUDED
#define CONSOLE_HPP_INCLUDED

#include <Windows.h>
#include <string>
#include <iostream> 
#include <sstream>

namespace pong      
{
    class Console
    {
    private:
       void gtxy(short x, short y);
       CONSOLE_SCREEN_BUFFER_INFOEX consoleInfo;
       HANDLE hConsoleOutput;
       HWND hWindowConsole;
       std::stringstream ssm;
       void Flushssm();
    public:
        Console(bool debug);
        ~Console();
    };
    
    
    
}   


#endif