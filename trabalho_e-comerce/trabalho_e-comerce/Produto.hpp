#ifndef Produto_h
#define Produto_h

#include <string>

class Produto {
public:
    Produto(std::string nome, double preco);

    std::string getNome();

    double getPreco();

private:
    std::string nome;
    double preco;
};


#endif // Produto_h
