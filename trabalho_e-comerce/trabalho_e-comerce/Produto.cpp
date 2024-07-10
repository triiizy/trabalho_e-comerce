#include "Produto.hpp"

Produto::Produto(std::string nome, double preco)
    : nome(nome), preco(preco) {};
std::string Produto::getNome() {
    return nome;
}

double Produto::getPreco() {
    return preco;
}
