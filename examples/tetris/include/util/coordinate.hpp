#pragma once

struct Coodinate_t
{
    int x, y;

    void rota()
    {
        int tmp = this->x;
        this->x = -this->y;
        this->y = tmp;
    }
};