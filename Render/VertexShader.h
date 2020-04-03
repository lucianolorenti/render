#ifndef VERTEXSHADER_H
#define VERTEXSHADER_H
#include <vector>
#include <armadillo>

class VertexShader
{
public:
    VertexShader(arma::mat44 & projection_matrix);
    void apply(const arma::vec4 & in);
    const std::vector<arma::vec4> &projectedVertices() const;
private:
    arma::mat44 & m_projection_matrix;
    std::vector<arma::vec4> m_projected_vertices;
};

#endif // VERTEXSHADER_H
