#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Usuario.hpp"
#include "Anuncio.hpp"

std::vector<Usuario> usuarios;
std::vector<Anuncio> anuncios;


void criarAnuncio() {

    std::string titulo, descricao;
    double preco;

    std::cout << "\nDigite o nome do produto: ";
    std::cin >> titulo;
    std::cout << "\nDigite a descrição do produto: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, descricao);
    std::cout << "\nDigite o preço do produto: ";
    std::cin >> preco;

    Anuncio anuncio(titulo, descricao, preco);
    anuncios.push_back(anuncio);

    std::cout << "\nAnuncio criado com sucesso!\n";
}

void visualizarAnuncio(Anuncio& anuncio, Usuario& usuario) {
    anuncio.exibirAnuncio();
    std::cout << "\nDeseja comprar este produto? (s/n): ";
    char opcao;
    std::cin >> opcao;
    if (opcao == 's') {
        double valorTotal = anuncio.getPreco() + anuncio.getFrete();
        std::cout << "\nValor total (produto + frete): " << valorTotal << "\n";
        std::cout << "\nDeseja confirmar a compra? (s/n): ";
        std::cin >> opcao;
        if (opcao == 's') {
            std::cout << "\nParabéns pela sua compra!\n";
            usuario.adicionarCompra(anuncio);
        }
        else {
            std::cout << "\nCompra cancelada.\n";
        }
    }

    std::cout << "\nDeseja favoritar este produto? (s/n): \n";
    std::cin >> opcao;
    if (opcao == 's') {
        usuario.adicionarFavorito(anuncio);
        std::cout << "\nProduto adicionado aos favoritos.\n";
    }
    else {
        std::cout << "\nVoltando aos anúncios.\n";
    }
}

void anunciosPredefinidos() {
    anuncios.push_back(Anuncio("Celular", "Celular de última geração", 1500.00));
    anuncios.push_back(Anuncio("Computador", "Computador potente para jogos", 3000.00));
    anuncios.push_back(Anuncio("Livro", "Livro interessante sobre programação", 50.00));
    anuncios.push_back(Anuncio("Maçã", "Maçã fresca e suculenta", 2.00));
    anuncios.push_back(Anuncio("Cachorro", "Cachorro fofo e brincalhão", 500.00));
}

void areaPrincipal(Usuario& usuario) {
    int opcao;
    do {
        std::cout << "\n------------Bem-vindo à área principal do e-commerce!-----------------\n";
        std::cout << "Aqui você verá os conteúdos principais.\n";
        std::cout << "1. Visualizar anúncios\n";
        std::cout << "2. Criar um novo anúncio\n";
        std::cout << "3. Visualizar suas compras\n";
        std::cout << "4. Visualizar seus favoritos\n";
        std::cout << "Escolha uma opção (0 para sair): ";
        std::cin >> opcao;

        if (opcao == 1) {
            for (int i = 0; i < anuncios.size(); ++i) {
                std::cout << i + 1 << ". " << anuncios[i].getTitulo() << "\n";
            }
            std::cout << "Escolha um anúncio para visualizar (ou 0 para voltar): ";
            int escolha;
            std::cin >> escolha;
            if (escolha > 0 && escolha <= anuncios.size()) {
                visualizarAnuncio(anuncios[escolha - 1], usuario);
            }
            else {
                std::cout << "Voltando para a área principal.\n";
            }
        }
        else if (opcao == 2) {
            criarAnuncio();
        }
        else if (opcao == 3) {
            usuario.exibirCompras();
        }
        else if (opcao == 4) {
            usuario.exibirFavoritos();
        }
        else if (opcao != 0) {
            std::cout << "\nOpção inválida.\n";
        }
    } while (opcao != 0);
}


int main() {

    bool loginSucesso;
    char codigoCadastro, tentarNovamente;
    Usuario usuario;

    anunciosPredefinidos();
    std::cout << "Bem-vindo ao Ecommerce!!!\n" << std::endl;
    std::cout << "\nPor favor, realize o seu cadastro:\n" << std::endl;
    std::cout << "\nDigite 'n' para realizar o cadastro: \n";
    std::cin >> codigoCadastro;

    if (codigoCadastro == 'n') {
        usuario.coletarDados();
        usuarios.push_back(usuario);
        std::cout << "Cadastro realizado com sucesso!\n";
        usuario.exibirUsuarios();
        areaPrincipal(usuario);
    }
   
    else {
        std::cout << "Código inválido" << std::endl;
    }

    return 0;
}
