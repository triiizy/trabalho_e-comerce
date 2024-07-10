#include "Anuncio.hpp"


Anuncio::Anuncio(std::string titulo, std::string descricao, double preco)
    : titulo(titulo), descricao(descricao), preco(preco) {
    frete = calcularFrete();
}

void Anuncio::exibirAnuncio() {
    std::cout << "Titulo: " << titulo << "\n"
        << "Descrição: " << descricao << "\n"
        << "Preço: " << preco << "\n"
        << "Frete: " << frete << "\n";
}

double Anuncio::getPreco() {
    return preco;
}

double Anuncio::getFrete() {
    return frete;
}

std::string Anuncio::getTitulo() {
    return titulo;
}

double Anuncio::calcularFrete() {
    return (preco*5)/100;
}
