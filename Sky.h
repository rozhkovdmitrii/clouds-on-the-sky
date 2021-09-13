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


    typedef std::vector<std::vector<bool>> Visited;

    void markCloudVisited(const SkyImpl & sky, int i, int j, Visited & visited) const;

    SkyImpl _skyImpl;
};



#endif //PointH
