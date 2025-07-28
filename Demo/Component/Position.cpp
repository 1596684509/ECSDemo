#include "Position.h"

Position::Position(float x, float y) : x(x), y(y) {}

bool Position::operator==(const Position& other) const {
    return x == other.x && y == other.y;
}

namespace std {
    template <>
    struct hash<Position> {
        std::size_t operator()(const Position& p) const {
            return std::hash<float>()(p.x) ^ (std::hash<float>()(p.y) << 1);
        }
    };
}