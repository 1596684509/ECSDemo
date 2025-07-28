#include "Position.h"

Position::Position(float x, float y) : x(x), y(y) {}

bool Position::operator==(const Position& other) const {
    const float epsilon = 1e-5f;
    return std::fabs(x - other.x) < epsilon && std::fabs(y - other.y) < epsilon;
}

namespace std {
    template<>
    struct hash<Position> {
        std::size_t operator()(const Position& p) const {
            int xInt = static_cast<int>(p.x * 1000); 
            int yInt = static_cast<int>(p.y * 1000);
            return std::hash<int>()(xInt) ^ (std::hash<int>()(yInt) << 1);
        }
    };
}