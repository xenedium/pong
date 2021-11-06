#ifndef APP_HPP_INCLUDED
#define APP_HPP_INCLUDED

#include <Console.hpp>

namespace pong
{
    class App
    {
    private:
        static bool IsDebug(int argc, char *argv[]);
        pong::Console *console;
        pong::Player *p1, *p2;
    public:
        App(int argc, char *argv[]);
        ~App();
        [[noreturn]] int Start();
    };
    
} // namespace pong


#endif