#ifndef Compra_h
#define Compra_h

#include "Anuncio.hpp"

class Compra {
public:
    Compra(Anuncio* anuncio, double frete); // Alterado para receber um ponteiro para Anuncio

    Anuncio* getAnuncio();
    double getFrete();

private:
    Anuncio* anuncio; // Agora armazena um ponteiro para Anuncio
    double frete;
};

#endif // Compra_h