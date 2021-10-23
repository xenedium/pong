#include <App.hpp>

pong::App::App(int argc, char *argv[])
{
    this->console = new pong::Console(pong::App::IsDebug(argc, argv));
    this->p1 = new pong::Player(1);
    this->p2 = new pong::Player(2);
}

pong::App::~App()
{
    delete this->console;
    delete this->p1;
    delete this->p2;
}

int pong::App::Start()
{

    this->p1->StartThread();
    this->p2->StartThread();

    while (true)
    {
        console->Refresh(this->p1, this->p2);
        Sleep(100);
    }

}

bool pong::App::IsDebug(int argc, char *argv[])
{
    if (argc < 2) return false;
    if (!strcmp(argv[1], "-d") || !strcmp(argv[1], "--debug")) return true;
    return false;
}