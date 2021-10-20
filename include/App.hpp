#ifndef APP_HPP_INCLUDED
#define APP_HPP_INCLUDED

#include <Console.hpp>

namespace pong
{
    class App
    {
    private:
        bool IsDebug(int argc, char *argv[]);
        pong::Console *console;
        pong::Player *p1, *p2;
    public:
        App(/* args */);
        ~App();
        int Start(int argc, char *argv[]);
    };
    
} // namespace pong


#endif