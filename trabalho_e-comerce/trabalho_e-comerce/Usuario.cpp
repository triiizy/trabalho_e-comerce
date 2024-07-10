#include "Usuario.hpp"

void Usuario::coletarDados() {
    std::cout << "Digite o nome: ";
    std::cin >> nome;
    std::cout << "Digite o CPF: ";
    std::cin >> cpf;
    std::cout << "Digite o email: ";
    std::cin >> email;
    std::cout << "Digite o telefone: ";
    std::cin >> telefone;
    std::cout << "Digite a senha: ";
    std::cin >> senha;
}

void Usuario::exibirUsuarios() {
    std::cout << "Nome: " << nome << "\n"
        << "CPF: " << cpf << "\n"
        << "Email: " << email << "\n"
        << "Telefone: " << telefone << "\n\n";
}

std::string Usuario::getEmail() {
    return email;
}

std::string Usuario::getSenha() {
    return senha;
}

void Usuario::adicionarFavorito(Anuncio& anuncio) {
    favoritos.push_back(anuncio);
}

void Usuario::adicionarCompra(Anuncio& anuncio) {
    compras.push_back(anuncio);
}

void Usuario::exibirFavoritos() {
    std::cout << "Favoritos:\n";
    for (auto& anuncio : favoritos) {
        anuncio.exibirAnuncio();
    }
}

void Usuario::exibirCompras() {
    std::cout << "Compras:\n";
    for (auto& anuncio : compras) {
        anuncio.exibirAnuncio();
    }
}
