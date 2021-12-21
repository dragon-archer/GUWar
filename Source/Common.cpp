#include <Common.h>

namespace GU
{
    double dist(const QPoint& p1, const QPoint& p2)
    {
        return sqrt((p1.x() - p2.x()) * (p1.x() - p2.x()) + (p1.y() - p2.y()) * (p1.y() - p2.y()));
    }
}
