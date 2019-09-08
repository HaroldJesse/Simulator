#ifndef OBJECTLOADER_HPP
#define OBJECTLOADER_HPP

#include "SimGlobals.hpp"

class ObjectLoader : public Qt3DCore::QEntity
{
public:
    explicit ObjectLoader(Qt3DCore::QNode *parent = 0);
    ~ObjectLoader();

};

#endif // OBJECTLOADER_HPP
