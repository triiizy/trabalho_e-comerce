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
    std::cout << "Digite a descri��o do produto: ";
    std::cin >> descricao;
    std::cout << "Digite o pre�o do produto: ";
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
            std::cout << "Parab�ns pela sua compra!\n";
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
        std::cout << "Voltando aos an�ncios.\n";
    }
}

void anunciosPredefinidos() {
    anuncios.push_back(Anuncio("Celular", "Celular de �ltima gera��o", 1500.00));
    anuncios.push_back(Anuncio("Computador", "Computador potente para jogos", 3000.00));
    anuncios.push_back(Anuncio("Livro", "Livro interessante sobre programa��o", 50.00));
    anuncios.push_back(Anuncio("Ma��", "Ma�� fresca e suculenta", 2.00));
    anuncios.push_back(Anuncio("Cachorro", "Cachorro fofo e brincalh�o", 500.00));
}

void areaPrincipal(Usuario& usuario) {
    int opcao;
    do {
        std::cout << "Bem-vindo � �rea principal do e-commerce!\n";
        std::cout << "Aqui voc� ver� os conte�dos principais.\n";
        std::cout << "1. Visualizar an�ncios\n";
        std::cout << "2. Criar um novo an�ncio\n";
        std::cout << "3. Visualizar suas compras\n";
        std::cout << "4. Visualizar seus favoritos\n";
        std::cout << "Escolha uma op��o (0 para sair): ";
        std::cin >> opcao;

        if (opcao == 1) {
            for (int i = 0; i < anuncios.size(); ++i) {
                std::cout << i + 1 << ". " << anuncios[i].getTitulo() << "\n";
            }
            std::cout << "Escolha um an�ncio para visualizar (ou 0 para voltar): ";
            int escolha;
            std::cin >> escolha;
            if (escolha > 0 && escolha <= anuncios.size()) {
                visualizarAnuncio(anuncios[escolha - 1], usuario);
            }
            else {
                std::cout << "Voltando para a �rea principal.\n";
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
            std::cout << "Op��o inv�lida.\n";
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
    std::cout << "Por favor, realize o seu cadastro caso n�o tenha um ainda.\n" << std::endl;
    std::cout << "O usu�rio possui cadastro?\n\nDigite 's' para ir direto para o Login.\nDigite 'n' para realizar o cadastro: \n";
    std::cin >> codigoCadastro;

    if (codigoCadastro == 'n') {
        usuario.coletarDados();
        usuarios.push_back(usuario);
        std::cout << "Cadastro realizado com sucesso!\n";
        usuario.exibirUsuarios();
        areaPrincipal(usuario);
    }
    else if (codigoCadastro == 's') {
        std::cout << "\nVoc� escolheu fazer o login." << std::endl;
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
            std::cout << "\nLogin n�o encontrado.\n";
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
                    std::cout << "At� logo!\n";
                }
            }
        }
    }
    else {
        std::cout << "C�digo inv�lido" << std::endl;
    }

    return 0;
}
