#include <Player.hpp>

[[noreturn]] void pong::Player::OnP1KeysPressed(Player *player)
{
    while (true)
    {
        Sleep(70);
        if (GetAsyncKeyState(0x45))
            player->Up();

        if (GetAsyncKeyState(0x44))
            player->Down();
    }
}

[[noreturn]] void pong::Player::OnP2KeysPressed(Player *player)
{
    while (true)
    {
        Sleep(70);
        if (GetAsyncKeyState(VK_UP))
            player->Up();

        if (GetAsyncKeyState(VK_DOWN))
            player->Down();
    }
}

void pong::Player::Up()
{
    if (this->pos < 10)
        this->pos++;
}

void pong::Player::Down()
{
    if (this->pos > 1)
        this->pos--;
}

uint8_t pong::Player::GetPos()
{
    return this->pos;
}

pong::Player::Player(uint8_t player)
{
    void *func = &pong::Player::OnP1KeysPressed;
    this->pos = 5;
    if ( (this->hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) (player == 1 ? &pong::Player::OnP1KeysPressed : &pong::Player::OnP2KeysPressed), this , CREATE_SUSPENDED,
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

void pong::Player::PauseThread()
{
    
}
