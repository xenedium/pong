#include <Player.hpp>

[[noreturn]] void pong::OnP1KeysPressed(uint8_t *pos)
{
    while (true)
    {
        Sleep(70);
        if (GetAsyncKeyState(0x45))
            if (*pos < 10) (*pos)++;

        if (GetAsyncKeyState(0x44))
            if (*pos > 1) (*pos)--;
    }
}

[[noreturn]] void pong::OnP2KeysPressed(uint8_t *pos)
{
    while (true)
    {
        Sleep(70);
        if (GetAsyncKeyState(VK_UP))
            if (*pos < 10) (*pos)++;

        if (GetAsyncKeyState(VK_DOWN))
            if (*pos > 1) (*pos)--;
    }
}

pong::Player::Player(uint8_t player)
{
    this->pos = 5;
    if ( (this->hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) (player == 1 ? &pong::OnP1KeysPressed : &pong::OnP2KeysPressed), &this->pos , CREATE_SUSPENDED,
                                       nullptr)) == INVALID_HANDLE_VALUE) exit(EXIT_FAILURE);
}

pong::Player::~Player()
{
    CloseHandle(this->hThread);
}

void pong::Player::StartThread()
{
    if (ResumeThread(this->hThread) == (DWORD) -1) exit(EXIT_FAILURE);
}
