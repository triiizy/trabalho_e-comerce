#include "Compra.hpp"

Compra::Compra(Anuncio* anuncio, double frete)
    : anuncio(anuncio), frete(frete) {}

Anuncio* Compra::getAnuncio() {
    return anuncio;
}

double Compra::getFrete() {
    return frete;
}
