#include <App.hpp>

pong::App::App()
{
    
}

pong::App::~App()
{
    delete this->console, this->p1, this->p2;
}

int pong::App::Start(int argc, char *argv[])
{
    this->console = new pong::Console(this->IsDebug(argc, argv));
    this->p1 = new pong::Player(1);
    this->p2 = new pong::Player(2);

    this->p1->StartThread();
    this->p2->StartThread();

    while (true)
    {
        console->Refresh(this->p1, this->p2);
        Sleep(100);
    }
    return 0;
}

bool pong::App::IsDebug(int argc, char *argv[])
{
    if (argc < 2) return false;
    if (!strcmp(argv[1], "-d") || !strcmp(argv[1], "--debug")) return true;
    return false;
}