#ifndef Anuncio_h
#define Anuncio_h

#include <iostream>
#include <string>

class Anuncio {
public:
    Anuncio(std::string titulo, std::string descricao, double preco);

    void exibirAnuncio();

    double getPreco();

    double getFrete();

    std::string getTitulo();

private:
    std::string titulo;
    std::string descricao;
    double preco;
    double frete;

    double calcularFrete();
};

#endif // Anuncio_h
