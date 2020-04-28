#include "VertexShader.h"
#include <iostream>
VertexShader::VertexShader(const arma::mat44 & projection_matrix, const arma::mat44 & transformation_matrix) :
    m_projection_matrix(projection_matrix),
    m_transformation_matrix(transformation_matrix)

{

}

void VertexShader::apply(const arma::vec4 &in)
{

    arma::vec4 vec =(m_transformation_matrix*m_projection_matrix) * in;

    for (int i=0;i<=1;i++) {
        vec(i) = std::clamp(vec(i) / vec(3), -1.0, 1.0);
    }
    vec(2) /= vec(3);
    vec = 0.5*((vec + arma::vec4{1, 1, 0, 0}));
    vec %= arma::vec4{800, 600, 1, 1};
    vec(0) =  std::clamp(vec(0), 0.0, 799.0);
    vec(1) =  std::clamp(vec(1), 0.0, 599.0);
    this->m_projected_vertices.push_back(vec);
}

void VertexShader::clean()
{
    this->m_projected_vertices.clear();
}

const std::vector<arma::vec4> &VertexShader::projectedVertices() const
{
    return m_projected_vertices;
}
