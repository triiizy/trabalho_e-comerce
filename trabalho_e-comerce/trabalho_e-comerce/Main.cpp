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

    std::cout << "Digite o nome do produto: ";
    std::cin >> titulo;
    std::cout << "Digite a descrição do produto: ";
    std::cin >> descricao;
    std::cout << "Digite o preço do produto: ";
    std::cin >> preco;

    Anuncio anuncio(titulo, descricao, preco);
    anuncios.push_back(anuncio);

    std::cout << "Anuncio criado com sucesso!\n";
}

void visualizarAnuncio(Anuncio& anuncio, Usuario& usuario) {
    anuncio.exibirAnuncio();
    std::cout << "Deseja comprar este produto? (s/n): ";
    char opcao;
    std::cin >> opcao;
    if (opcao == 's') {
        double valorTotal = anuncio.getPreco() + anuncio.getFrete();
        std::cout << "Valor total (produto + frete): " << valorTotal << "\n";
        std::cout << "Deseja confirmar a compra? (s/n): ";
        std::cin >> opcao;
        if (opcao == 's') {
            std::cout << "Parabéns pela sua compra!\n";
            usuario.adicionarCompra(anuncio);
        }
        else {
            std::cout << "Compra cancelada.\n";
        }
    }

    std::cout << "Deseja favoritar este produto? (s/n): ";
    std::cin >> opcao;
    if (opcao == 's') {
        usuario.adicionarFavorito(anuncio);
        std::cout << "Produto adicionado aos favoritos.\n";
    }
    else {
        std::cout << "Voltando aos anúncios.\n";
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
        std::cout << "Bem-vindo à área principal do e-commerce!\n";
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
            std::cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

bool verificarLogin(std::string email, std::string senha) {
    for (auto& usuario : usuarios) {
        if (usuario.getEmail() == email && usuario.getSenha() == senha) {
            return true;
        }
    }
    return false;
}

int main() {

    bool loginSucesso;
    char codigoCadastro, tentarNovamente;
    Usuario usuario;

    anunciosPredefinidos();
    std::cout << "Bem-vindo ao Ecommerce!!!\n" << std::endl;
    std::cout << "Por favor, realize o seu cadastro caso não tenha um ainda.\n" << std::endl;
    std::cout << "O usuário possui cadastro?\n\nDigite 's' para ir direto para o Login.\nDigite 'n' para realizar o cadastro: \n";
    std::cin >> codigoCadastro;

    if (codigoCadastro == 'n') {
        usuario.coletarDados();
        usuarios.push_back(usuario);
        std::cout << "Cadastro realizado com sucesso!\n";
        usuario.exibirUsuarios();
        areaPrincipal(usuario);
    }
    else if (codigoCadastro == 's') {
        std::cout << "\nVocê escolheu fazer o login." << std::endl;
        std::string email, senha;
        std::cout << "\nDigite o email: ";
        std::cin >> email;
        std::cout << "\nDigite a senha: ";
        std::cin >> senha;

        Usuario* usuarioAtual = nullptr;

        for (auto& usuario : usuarios) {
            if (usuario.getEmail() == email && usuario.getSenha() == senha) {
                loginSucesso = true;
                usuarioAtual = &usuario;
                break;
            }
        }

        if (loginSucesso) {
            std::cout << "\nLogin realizado com sucesso!\n";
            areaPrincipal(*usuarioAtual);
        }
        else {
            std::cout << "\nLogin não encontrado.\n";
            std::cout << "\nDeseja tentar novamente? (s/n): ";
            std::cin >> tentarNovamente;

            if (tentarNovamente == 's') {
                main(); 
            }
            else {
                std::cout << "Deseja se cadastrar? (s/n): ";
                std::cin >> tentarNovamente;

                if (tentarNovamente == 's') {
                    usuario.coletarDados();
                    usuarios.push_back(usuario);
                    std::cout << "Cadastro realizado com sucesso!\n";
                    usuario.exibirUsuarios();
                    areaPrincipal(usuario);
                }
                else {
                    std::cout << "Até logo!\n";
                }
            }
        }
    }
    else {
        std::cout << "Código inválido" << std::endl;
    }

    return 0;
}
