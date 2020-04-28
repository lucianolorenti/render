#include <iostream>

#include <Render/Renderer.h>
#include <iostream>

void line(int x0, int y0, int x1, int y1, arma::Cube<sf::Uint8> &img) {
    for (float t=0.; t<1.; t+=.01) {
        int x = x0 + (x1-x0)*t;
        int y = y0 + (y1-y0)*t;
        img(0, x, y) = 255;
        img(1, x, y) = 255;
        img(2, x, y) = 255;
        img(3, x, y) = 125;
    }
}

void line(const arma::vec4 & v1, const arma::vec4 & v2, arma::Cube<sf::Uint8> &img)
{
    line(v1[0], v1[1], v2[0], v2[1], img)  ;
}

arma::mat44 projection_matrix(float left, float right, float top, float bottom, float near, float far)
{
    return arma::mat44{
        {2*near/(right-left), 0, -(right+left)/(right-left), 0},
        {0, 2*near/(top-bottom), -(top+bottom)/(top-bottom), 0},
        {0, 0, -(far + near)/(far-near), -(2*far*near)/(far-near)},
        {0, 0, 1, 0}
    };
}
Renderer::Renderer() :
    m_projection_matrix(projection_matrix(-15, 15, 15, -15, -5, 3)),
    m_transformation_matrix(arma::mat44(arma::fill::eye)),
    m_vertex_shader(std::make_unique<VertexShader>(m_projection_matrix, m_transformation_matrix))
{

}
arma::mat44 rotate(float angle, float v1, float v2, float v3)
{
    (void) v1;
    (void) v2;
    (void) v3;
    return arma::mat44{
        {1, 0, 0, 0},
        {0, cos(angle), -sin(angle), 0},
        {0, sin(angle), cos(angle), 0},
        {0, 0, 0, 1}};
}
void Renderer::render(arma::Cube<sf::Uint8> & img, Scene &scene)
{

    this->m_vertex_shader->clean();
    angle += 0.0001;
    m_transformation_matrix = rotate(angle, 1, 0 ,0);
    for (auto & elem : scene.meshes()) {
        for (auto & vertex : elem->vertices()) {
            this->m_vertex_shader->apply(vertex);
        }
    }

    for (auto & elem : scene.meshes()) {
        auto &vertices = this->m_vertex_shader->projectedVertices();
        for (auto & f : elem->faces()) {
            line(vertices[f[0]], vertices[f[1]], img);
            line(vertices[f[1]], vertices[f[2]], img);
            line(vertices[f[2]], vertices[f[0]], img);
        }
    }

}
