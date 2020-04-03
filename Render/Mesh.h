#ifndef MESH_H
#define MESH_H
#include <memory>
#include <iostream>
#include <armadillo>
#include <Render/Types.h>

class Mesh {
public:
    Mesh(const std::vector<arma::vec4> & vertices, const std::vector<face> & faces);
    const std::vector<arma::vec4> & vertices() const;
    const std::vector<face> & faces() const;
private:
    std::vector<arma::vec4> m_vertices;
    std::vector<face> m_faces;
};

#endif
