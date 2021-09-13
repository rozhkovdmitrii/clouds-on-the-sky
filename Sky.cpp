#include "Sky.h"

Sky::Sky(const Sky::SkyImpl & skyImpl) : _skyImpl(skyImpl) {}

size_t Sky::getCloudsCount() const
{
    if (_skyImpl.empty())
        return 0;
    Visited visited(_skyImpl.size(), std::vector<bool>(_skyImpl[0].size(), false));
    size_t cloudCounter = 0;
    for (int i = 0; i < _skyImpl.size(); ++i) {
        const std::string & row = _skyImpl[i];
        for (int j = 0; j < row.size(); ++j) {
            if (visited[i][j])
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

    std::_Bit_reference visitedPoint = visited[i][j];
    if (visitedPoint)
        return;
    visitedPoint = true;

    if (sky[i][j] != 'w')
        return;

    markCloudVisited(sky, i + 1, j, visited);
    markCloudVisited(sky, i - 1, j, visited);
    markCloudVisited(sky, i, j + 1, visited);
    markCloudVisited(sky, i, j - 1, visited);
}

