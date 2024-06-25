#ifndef Anuncio_h
#define Anuncio_h

#include <string>

class Anuncio {
public:
	void setPreco(float valor);

private:
	std::string titulo;
	float preco;
	std::string descricao;

};

#endif // ! Anuncio_h
