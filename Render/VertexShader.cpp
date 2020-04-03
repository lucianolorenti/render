#include "VertexShader.h"

VertexShader::VertexShader(arma::mat44 & projection_matrix) :
    m_projection_matrix(projection_matrix)
{

}

void VertexShader::apply(const arma::vec4 &in)
{
    arma::vec4 vec = m_projection_matrix * in;
    vec = 0.5*((vec + arma::vec4{1, 1, 0, 0}));
    this->m_projected_vertices.push_back(vec);
}

const std::vector<arma::vec4> &VertexShader::projectedVertices() const
{
    return m_projected_vertices;
}
