#pragma once

#define COLUMNS 25
#define ROWS 15

#include <unordered_map>

#include <lib/Moon/template/cmp/cmp.tpp>

#include "../util/coordinate.hpp"

struct SpriteBoardCmp_t : Moon::Core::Component_t<SpriteBoardCmp_t>
{
    std::vector<bool> boxes;

    SpriteBoardCmp_t() {}

    explicit SpriteBoardCmp_t(Moon::Alias::EntityId eid)
      : Moon::Core::Component_t<SpriteBoardCmp_t>(eid)
    {

        boxes.resize((COLUMNS * ROWS) + (ROWS * 2));
    }

    bool fullColumn(int column)
    {
        for (size_t i = 0; i < ROWS; i++) {
            if (!this->boxes[column * ROWS + i])
                return false;
        }
        return true;
    }

    void collaps(int column)
    {
        for (int j = COLUMNS; j > 0; j--) {
            for (int i = 0; i < ROWS; i++) {
                this->boxes[j * ROWS + i] = this->boxes[(j - 1) * ROWS + i];
            }
        }
        for (int i = 0; i < ROWS; i++) {
            this->boxes[0 * ROWS + i] = false;
        }
    }

    void addCoordinate(int x, int y) { this->boxes[y * ROWS + x] = true; }
};