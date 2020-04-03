#include <iostream>

#include <Render/Renderer.h>
#include <iostream>

void line(int x0, int y0, int x1, int y1, arma::Cube<sf::Uint8> &img) {
    std::cout << x0 << " " << y0 << std::endl;
    std::cout << x1 << " " << y1 << std::endl;
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
    m_projection_matrix(projection_matrix(-2, 2, 2, -2, -5, 3)),
    m_vertex_shader(std::make_unique<VertexShader>(m_projection_matrix))
{

}

void Renderer::render(arma::Cube<sf::Uint8> & img, Scene &scene)
{
    for (auto & elem : scene.meshes()) {
        for (auto & vertex : elem->vertices()) {
            this->m_vertex_shader->apply(vertex);
        }
    }
    arma::vec4 size{800, 600, 1, 1};
    for (auto & elem : scene.meshes()) {
        auto &vertices = this->m_vertex_shader->projectedVertices();
        for (auto & f : elem->faces()) {
            line(vertices[f[0]] % size, vertices[f[1]] % size, img);
            line(vertices[f[1]] % size, vertices[f[2]] % size, img);
            line(vertices[f[2]] % size, vertices[f[0]] % size, img);
        }
    }

}
