#include <Console.hpp>

pong::Console::Console(bool debug)
{
    FreeConsole();              //free the default console and create another one
    AllocConsole();
    AttachConsole(GetCurrentProcessId());

    this->hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    this->hWindowConsole = GetConsoleWindow();
    
    SetConsoleTitleA("Pong game by Sorrow");
    GetConsoleScreenBufferInfoEx(this->hConsoleOutput, &this->consoleInfo);
    ShowWindow(this->hWindowConsole, SW_SHOWMAXIMIZED);
    
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

void pong::Console::Flushssm()
{
    DWORD dummy;
    WriteFile(this->hConsoleOutput, this->ssm.str().c_str(), strlen(this->ssm.str().c_str()), &dummy, NULL);
    this->ssm.str("");
}