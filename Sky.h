#ifndef PointH
#define PointH

#include <vector>
#include <set>
#include <string>

class Sky
{
public:

    typedef std::vector<std::string> SkyImpl;

    Sky(const SkyImpl & skyImpl);


    size_t getCloudsCount() const;

private:

    struct Point
    {
        int _x;
        int _y;
        bool operator<(const Point & point) const;
        bool operator==(const Point & point) const;
    };
    typedef std::set<Point> Visited;

    void markCloudVisited(const SkyImpl & sky, int i, int j, Visited & visited) const;

    SkyImpl _skyImpl;
};



#endif //PointH
