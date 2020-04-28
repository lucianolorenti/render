#include <Render/Scene.h>
#include <Render/ObjLoader.h>
Scene::Scene()
{
    ObjLoader loader;
    this->addMesh(std::move(loader.load("/home/luciano/fuentes/render/objs/box.obj")));
}
void Scene::addMesh(std::unique_ptr<Mesh> mesh)
{
    this->m_mesh.push_back(std::move(mesh));
}

std::vector<std::unique_ptr<Mesh> > &Scene::meshes()
{
    return m_mesh;
}
