#include <App.hpp>

pong::App::App()
{
    
}

pong::App::~App()
{
    
}

int pong::App::Start(int argc, char *argv[])
{
    auto console = new pong::Console(this->IsDebug(argc, argv));
    
    return 0;
}

bool pong::App::IsDebug(int argc, char *argv[])
{
    if (argc < 2) return false;
    if (!strcmp(argv[1], "-d") || !strcmp(argv[1], "--debug")) return true;
    return false;
}