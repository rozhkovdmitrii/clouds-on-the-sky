#include "Sky.h"

Sky::Sky(const Sky::SkyImpl & skyImpl) : _skyImpl(skyImpl) {}

bool Sky::Point::operator<(const Sky::Point & point) const {
    return _x == point._x ? _y < point._y : _x < point._x;
}

bool Sky::Point::operator==(const Sky::Point & point) const {
    return _x == point._x && _y == point._y;
}

size_t Sky::getCloudsCount() const
{
    Visited visited;
    size_t cloudCounter = 0;
    for (int i = 0; i < _skyImpl.size(); ++i) {
        const std::string & row = _skyImpl[i];
        for (int j = 0; j < row.size(); ++j) {
            Point point({i, j});
            if (visited.contains(point))
                continue;
            if (row[j] == 'w') {
                ++cloudCounter;
                markCloudVisited(_skyImpl, i, j, visited);
            }
        }
    }
    visited.clear();
    return cloudCounter;
}

void Sky::markCloudVisited(const Sky::SkyImpl &sky, int i, int j, Visited & visited) const {
    if (i < 0 || i >= sky.size() || j < 0 || j >= sky[i].size())
        return;
    Point point({i, j});
    auto it = visited.lower_bound(point);
    if (it != visited.end() && *it == point)
        return;
    visited.insert(it, point);

    if (sky[i][j] != 'w')
        return;

    markCloudVisited(sky, i + 1, j, visited);
    markCloudVisited(sky, i - 1, j, visited);
    markCloudVisited(sky, i, j + 1, visited);
    markCloudVisited(sky, i, j - 1, visited);
}

