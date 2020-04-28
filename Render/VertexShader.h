#ifndef VERTEXSHADER_H
#define VERTEXSHADER_H
#include <vector>
#include <armadillo>

class VertexShader
{
public:
    VertexShader(const arma::mat44 & projection_matrix, const arma::mat44 & transformation_matrix);
    void apply(const arma::vec4 & in);
    void clean();
    const std::vector<arma::vec4> &projectedVertices() const;
private:
    const arma::mat44 & m_projection_matrix;
    const arma::mat44 & m_transformation_matrix;
    std::vector<arma::vec4> m_projected_vertices;
};

#endif // VERTEXSHADER_H
