#pragma once

#include <vector>
#include "render.h"
#include <string> // Add this line
class ObjExporter {
public:
    void addPolygon(const Vertex* vertices, int verticesCount, int textureIndex);
    void saveObj(const std::string& objFilename, const std::string& mtlFilename);
    void saveMtl(const std::string& mtlFilename);

private:
    struct Polygon {
        std::vector<Vertex> vertices;
        int textureIndex;
    };

    std::vector<Polygon> polygons_;
};