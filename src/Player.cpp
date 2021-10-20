#include <Player.hpp>

void pong::OnP1KeysPressed(HANDLE hWritePipe)
{
    while (true)
    {
        if (GetAsyncKeyState(0x45))
            hWritePipe;

        if (GetAsyncKeyState(0x44))
            hWritePipe;
    }
}

void pong::OnP2KeysPressed(HANDLE hWritePipe)
{
    while (true)
    {
        if (GetAsyncKeyState(VK_UP))
            hWritePipe;

        if (GetAsyncKeyState(VK_DOWN))
            hWritePipe;
    }
}

pong::Player::Player(uint8_t player)
{
    this->pos = 0;
    void *lpStartAdress = player == 1 ? &pong::OnP1KeysPressed : &pong::OnP2KeysPressed;
    if ( (this->hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) lpStartAdress, (void*)0 , CREATE_SUSPENDED, NULL)) == INVALID_HANDLE_VALUE) exit(EXIT_FAILURE);
}

pong::Player::~Player()
{
    CloseHandle(this->hThread);
}

void pong::Player::StartThread()
{
    if (ResumeThread(this->hThread) == (DWORD) -1) exit(EXIT_FAILURE);
}

void pong::Player::RefreshPos()
{
    
}