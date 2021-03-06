#include <Console.hpp>

pong::Console::Console(bool debug)
{
    FreeConsole();              //free the default console and create another one
    AllocConsole();
    AttachConsole(GetCurrentProcessId());

    this->hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    this->hWindowConsole = GetConsoleWindow();
    
    SetConsoleTitleA("Pong game by Sorrow");
    ShowWindow(this->hWindowConsole, SW_SHOWMAXIMIZED);
    SetForegroundWindow(this->hWindowConsole);
    GetConsoleScreenBufferInfoEx(this->hConsoleOutput, &this->consoleInfo);
}

pong::Console::~Console()
{
    CloseHandle(this->hConsoleOutput);
    CloseHandle(this->hWindowConsole);
}

void pong::Console::gtxy(short x, short y)
{
    SetConsoleCursorPosition(this->hConsoleOutput, {x, y});
}

void pong::Console::FlushSsm()
{
    DWORD dummy;
    WriteFile(this->hConsoleOutput, this->ssm.str().c_str(), strlen(this->ssm.str().c_str()), &dummy, NULL);
    this->ssm.str("");
}

void pong::Console::Refresh(pong::Player *p1, pong::Player *p2)
{
    this->ssm << "P1: " << (int)p1->GetPos() << "\tP2: " << (int)p2->GetPos() << " \r";
    this->FlushSsm();
}