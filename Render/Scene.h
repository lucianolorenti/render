#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <memory>
#include <Render/Mesh.h>
class Scene {
public:
    explicit Scene();
    void addMesh(std::unique_ptr<Mesh> mesh);
    std::vector<std::unique_ptr<Mesh>>& meshes();
private:
    std::vector<std::unique_ptr<Mesh>> m_mesh;
};

#endif
