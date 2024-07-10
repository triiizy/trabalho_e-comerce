#ifndef Usuario_h
#define Usuario_h

#include <iostream>
#include <string>
#include <vector>
#include "Anuncio.hpp"

class Usuario {
public:
    void coletarDados();

    void exibirUsuarios();

    std::string getEmail();

    std::string getSenha();

    void adicionarFavorito(Anuncio& anuncio);

    void adicionarCompra(Anuncio& anuncio);

    void exibirFavoritos();

    void exibirCompras();

private:
    std::string email, nome, telefone, cpf, senha;
    std::vector<Anuncio> favoritos;
    std::vector<Anuncio> compras;
};

#endif // Usuario_h
