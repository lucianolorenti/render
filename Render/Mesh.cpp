#include <Render/Mesh.h>
#include <Render/ObjLoader.h>



Mesh::Mesh(const std::vector<arma::vec4> &vertices, const std::vector<face> &faces) :
    m_vertices(vertices),
    m_faces(faces)
{

}

const std::vector<arma::vec4> &Mesh::vertices() const
{
    return this->m_vertices;
}

const std::vector<face> &Mesh::faces() const
{
    return m_faces;
}
