#include "AABB.h"

bool AABB::ChechOverLapingPoint(Vector2 point)
{

    bool insideX = point.x >= _topLeft.x && point.x <= _topLeft.x + _size.x;
    bool insideY = point.y >= _topLeft.y && point.y <= _topLeft.y + _size.y;


    return insideX && insideY;
}

bool AABB::ChechOverLapingAABB(const AABB* other)
{
    bool intersactionX = false;
    intersactionX |= _topLeft.x >= other->_topLeft.x && _topLeft.x <= other->_topLeft.x + other->_size.x; //si la meva punta dreta esta entre la punta drete del otehr i la punta esquerradel other hi ha colisio
    intersactionX |= _topLeft.x <= other->_topLeft.x && other->_topLeft.x <= _topLeft.x + _size.x; //mateixa loguica pero des del punt de vista del other (si el other entra per la antra vanda dreta)

    bool intersactionY = false;
    intersactionY |= _topLeft.y >= other->_topLeft.y && _topLeft.y <= other->_topLeft.y + other->_size.y; //mateix proses pero miran la part de dal i la de vaix.
    intersactionY |= _topLeft.y <= other->_topLeft.y && other->_topLeft.y <= _topLeft.y + _size.y;

    return intersactionX && intersactionY;
}
