#ifndef Usuario_h
#define Usuario_h

#include <string>
#include <vector>
#include "Anuncio.hpp"
#include "Compra.hpp"

class Usuario {
public:
	bool comprar(Anuncio anuncio); // retorna true se for bem sucedida
	bool favoritar(Anuncio anuncio); // retorna true se for bem sucedida

private:
	std::string login;
	std::string password;
	std::string email;
	std::string phone;
	std::string addr;
	std::string cpf;
	std::vector<Anuncio> anuncios;
	std::vector<Anuncio> favoridos;
	std::vector<Compra> compras;
};

#endif