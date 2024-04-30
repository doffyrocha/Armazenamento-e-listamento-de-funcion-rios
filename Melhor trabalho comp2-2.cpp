#include <stdio.h>
#include <string.h>
#define LIMIT 300

struct Funcionario {
private:
    char nome[51];
    char cpf[20];
    char dataAdmissao[100];
    float salario;

public:
    // Métodos para acessar os atributos
    const char* getNome() const {
        return nome;
    }

    const char* getCPF() const {
        return cpf;
    }

    float getSalario() const {
        return salario;
    }

    const char* getDataAdmissao() const {
        return dataAdmissao;
    }

    // Métodos para modificar os atributos
    void setNome(const char* novoNome) {
        strncpy(nome, novoNome, sizeof(nome) - 1);
        nome[sizeof(nome) - 1] = '\0'; // Garante que a string é terminada corretamente
    }

    void setCPF(const char* novoCPF) {
        strncpy(cpf, novoCPF, sizeof(cpf) - 1);
        cpf[sizeof(cpf) - 1] = '\0'; // Garante que a string é terminada corretamente
    }

    void setSalario(float novoSalario) {
        salario = novoSalario;
    }

    void setDataAdmissao(const char* novaDataAdmissao) {
        strncpy(dataAdmissao, novaDataAdmissao, sizeof(dataAdmissao) - 1);
        dataAdmissao[sizeof(dataAdmissao) - 1] = '\0'; // Garante que a string é terminada corretamente
    }
};

struct Funcionario funcionarios[LIMIT];
int contador = 0;

void funcionarioCreate() {
    printf("\nCadastro de Funcionario\n");

    if (contador < LIMIT) {
        printf("Nome: ");
        char nome[51];
        scanf("%50s", nome);
        funcionarios[contador].setNome(nome);

        printf("CPF: ");
        char cpf[20];
        scanf("%19s", cpf);
        funcionarios[contador].setCPF(cpf);

        printf("Salario: ");
        float salario;
        scanf("%f", &salario);
        funcionarios[contador].setSalario(salario);

        printf("Data de Admissao: ");
        char dataAdmissao[100];
        scanf("%99s", dataAdmissao);
        funcionarios[contador].setDataAdmissao(dataAdmissao);

        contador++;
    } else {
        printf("Limite de funcionarios atingido!\n");
    }
}

void funcionarioList() {
    printf("\nLista de Funcionarios\n");
    if (contador == 0) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }
    for (int i = 0; i < contador; i++) {
        printf("Funcionario %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].getNome());
        printf("CPF: %s\n", funcionarios[i].getCPF());
        printf("Salario: %.2f\n", funcionarios[i].getSalario());
        printf("Data de Admissao: %s\n", funcionarios[i].getDataAdmissao());
        printf("\n");
    }
}

void funcionarioSearch() {
    printf("\nBuscar Funcionario\n");
    if (contador == 0) {
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }
    char cpfBusca[20];
    printf("Digite o CPF do funcionario que deseja buscar: ");
    scanf("%19s", cpfBusca);

    for (int i = 0; i < contador; i++) {
        if (strcmp(funcionarios[i].getCPF(), cpfBusca) == 0) {
            printf("Funcionario encontrado:\n");
            printf("Nome: %s\n", funcionarios[i].getNome());
            printf("CPF: %s\n", funcionarios[i].getCPF());
            printf("Salario: %.2f\n", funcionarios[i].getSalario());
            printf("Data de Admissao: %s\n", funcionarios[i].getDataAdmissao());
            return;
        }
    }

    printf("Funcionario com CPF %s nao encontrado.\n", cpfBusca);
}

void menuDefault() {
    int op = 0;

    while (op != 9) {
        printf("\nSelecione a opcao desejada:\n");
        printf("1 - Cadastrar Novo Funcionario\n");
        printf("2 - Lista de Funcionarios\n");
        printf("3 - Buscar Funcionario\n");
        printf("9 - Sair\n");

        scanf("%d", &op);
        while (getchar() != '\n'); // Limpa o buffer de entrada

        switch (op) {
            case 1:
                funcionarioCreate();
                break;
            case 2:
                funcionarioList();
                break;
            case 3:
                funcionarioSearch();
                break;
            case 9:
                printf("Ate a proxima!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
}

int main() {
    menuDefault();
    return 0;
}

