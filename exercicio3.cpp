#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Produto {
    string codigo;
    string nome;
    double preco;
};

const int MAX_PRODUTOS = 300;
Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

void inserirProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        cout << "Limite máximo de produtos atingido." << endl;
        return;
    }
    Produto novoProduto;
    cout << "Digite o código do produto (13 caracteres): ";
    cin >> novoProduto.codigo;
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == novoProduto.codigo) {
            cout << "Produto com o mesmo código já cadastrado." << endl;
            return;
        }
    }
    cout << "Digite o nome do produto (máximo 20 caracteres): ";
    cin.ignore();
    getline(cin, novoProduto.nome);
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].nome == novoProduto.nome) {
            cout << "Produto com o mesmo nome já cadastrado." << endl;
            return;
        }
    }
    cout << "Digite o preço do produto (duas casas decimais): ";
    cin >> novoProduto.preco;
    produtos[totalProdutos] = novoProduto;
    totalProdutos++;
    cout << "Produto cadastrado com sucesso!" << endl;
}

void excluirProduto() {
    string codigo;
    cout << "Digite o código do produto a ser excluído: ";
    cin >> codigo;
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            for (int j = i; j < totalProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            totalProdutos--;
            cout << "Produto excluído com sucesso!" << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

void listarProdutos() {
    if (totalProdutos == 0) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }
    cout << "Lista de Produtos:" << endl;
    cout << "Código          Nome                 Preço" << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < totalProdutos; i++) {
        cout << setw(13) << left << produtos[i].codigo
             << setw(20) << left << produtos[i].nome
             << fixed << setprecision(2) << produtos[i].preco << endl;
    }
}

void consultarPreco() {
    string codigo;
    cout << "Digite o código do produto para consultar o preço: ";
    cin >> codigo;

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            cout << "Preço do produto: " << fixed << setprecision(2) << produtos[i].preco << endl;
            return;
        }
    }

    cout << "Produto não encontrado." << endl;
}

int main() {
    int opcao;
    while (true) {
        cout << "\nSupermercado AMCD - Consulta de Preços" << endl;
        cout << "1. Inserir novo produto" << endl;
        cout << "2. Excluir produto cadastrado" << endl;
        cout << "3. Listar todos os produtos" << endl;
        cout << "4. Consultar preço de um produto" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        switch (opcao) {
            case 1:
                inserirProduto();
                break;
            case 2:
                excluirProduto();
                break;
            case 3:
                listarProdutos();
                break;
            case 4:
                consultarPreco();
                break;
            case 5:
                cout << "Encerrando o programa." << endl;
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }
    return 0;
}
