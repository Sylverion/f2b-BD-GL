#include "objexporter.h"
#include <fstream>

void ObjExporter::addPolygon(const Vertex* vertices, int verticesCount, int textureIndex) {
    Polygon polygon;
    polygon.vertices.assign(vertices, vertices + verticesCount);
    polygon.textureIndex = textureIndex;
    polygons_.push_back(polygon);
}

void ObjExporter::saveObj(const std::string& objFilename, const std::string& mtlFilename) {
    std::ofstream objFile(objFilename);
    std::ofstream mtlFile(mtlFilename);

    if (!objFile.is_open() || !mtlFile.is_open()) {
        return;
    }

    objFile << "mtllib " << mtlFilename << std::endl;

    for (const auto& polygon : polygons_) {
        objFile << "usemtl texture_" << polygon.textureIndex << std::endl;

        for (const auto& vertex : polygon.vertices) {
            objFile << "v " << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
        }

        objFile << "f";
        for (size_t i = 0; i < polygon.vertices.size(); ++i) {
            objFile << " " << i + 1;
        }
        objFile << std::endl;
    }
}

void ObjExporter::saveMtl(const std::string& mtlFilename) {
    std::ofstream mtlFile(mtlFilename);

    if (!mtlFile.is_open()) {
        return;
    }

    for (const auto& polygon : polygons_) {
        mtlFile << "newmtl texture_" << polygon.textureIndex << std::endl;
        mtlFile << "map_Kd texture_" << polygon.textureIndex << ".png" << std::endl;
    }
}