#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

void LoginAut();
int Menu(void);
int Cadastro(void);
void Listar();
void GrupoRisco();

//Structs -- Variáveis Globais, Cadastro e Login
struct VarGlobal
{
    int Op;
    int Cd;

};

struct Cadastro
{
    char Nome[50];
    char Idade[5];
    char Cpf[15];
    char Telefone[15];
    char Endereco[50];
    char Cep[10];
    char Email[35];
    char DataDiagnostico[10];
    char Comorbidade[50];
};

typedef struct
{
    char login[30];
    char senha[30];
} usuario;

//-----//

FILE* DB; //Ponteiro para Banco de Cadastros
FILE* GR; //Ponteiro para Grupo de Risco

struct VarGlobal Global;
struct Cadastro Pessoa;


// --------------FUNÇÃO MAIN()---------------------------------------- //
int main()
{
    setlocale(LC_ALL, "Portuguese");
    LoginAut();
    Menu();
}
// -------------------------------------------------------------------- //

//Função Login
void LoginAut()
{
    usuario user[10];
    char login[30];
    char senha[30];
    strcpy(user[0].login, "adm");
    strcpy(user[0].senha, "0001");

    system("cls");
    printf("--Sistema de Controle de Pacientes com COVID-19 (SCPC)--\n");
    printf("--------------------------------------------------------\n\n");
    printf("Digite o Login: ");
    scanf("%s", login);
    printf("Digite a Senha: ");
    scanf("%s", senha);


    if (strcmp(login, user[0].login) == 0 && strcmp(senha, user[0].senha) == 0)
    {
        printf("\n\nLOGADO!\n\n");
    }
    else
    {
        printf("\n\nUSUARIO OU SENHA INCORRETO(S)!!!!\n\n");
        Sleep(1000);
        main();
    }
}


//Função Menu
int Menu(void)
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("===================================\n");
    printf("REGISTRO DE PACIENTES C/ COVID-19\n");
    printf("===================================\n\n");

    printf("[1] - Cadastrar\n");
    printf("[2] - Listar\n");
    printf("[3] - Remover\n");
    printf("[4] - Grupo de Risco\n");
    printf("[5] - Encerrar\n");
    printf("===============\n");
    printf("Opção: ");
    scanf("%d", &Global.Op);
    getchar();

    switch (Global.Op)
    {
    case 1:
        Cadastro();
        Menu();
        break;

    case 2:
        Listar();
        Menu();
        break;

    case 3:
        system("cls");
        printf("=========\n");
        printf(" REMOVER\n");
        printf("=========\n\n");

        printf("Para remover os dados de um cliente, acesse\no arquivo ");
        printf("dados.txt e realize o processo \nmanualmente, salvando o ");
        printf("arquivo logo em seguida.\n\n");

        printf("\nVoltar ao Menu Principal? 1 = Voltar ao Menu , 2 = Sair: ");
        scanf("%d", &Global.Cd);

        if(Global.Cd == 1)
        {
            Menu();

        }
        else if(Global.Cd != 1)
        {
            printf("Insira Qualquer Tecla para Sair....\n");
        }
        exit(11);
        break;

    case 4:
        GrupoRisco();

    case 5:
        system("cls");
        printf("######################\n");
        printf("# Fim da Execução... #\n");
        printf("######################\n\n");
        exit(0);

    default:
        printf("Valor inválido! Tente novamente...\n");
        Menu();
        break;

    }

    return 1;
}

//Função Cadastro
int Cadastro(void)
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    DB = fopen("dados.txt", "a"); //w: Abertura do arquivo dado.txt para escrita de dados
    GR = fopen("secretaria.txt", "a");

    if((DB == NULL) || (GR == NULL))
    {
        printf("\nErro no Banco de Dados...\n");
        return 1;
    }
    else
    {
        printf("======================\n");
        printf(" CADASTRO DE PACIENTES\n");
        printf("======================\n");

        printf("Nome: ");
        fgets(Pessoa.Nome, 50, stdin); //Recebe Nome

        fflush(stdin);
        printf("\n\nIdade: ");
        fgets(Pessoa.Idade, 5, stdin); //Recebe Idade

        fflush(stdin);
        printf("\n\nDigite seu CPF: ");
        fgets(Pessoa.Cpf, 15, stdin); //Recebe Cpf

        printf("\n\nDigite seu Telefone: ");
        fgets(Pessoa.Telefone, 15, stdin); //Recebe Telefone

        printf("\n\nDigite seu Endereço: ");
        fgets(Pessoa.Endereco, 50, stdin); //Recebe Endereço

        printf("\n\nDigite seu CEP: ");
        fgets(Pessoa.Cep, 10, stdin); //Recebe CEP

        fflush(stdin);
        printf("\n\nE-mail: ");
        fgets(Pessoa.Email, 35, stdin); //Recebe Email

        printf("\n\nDigite sua Data de Diagnostico+ (Positivo): ");
        fgets(Pessoa.DataDiagnostico, 10, stdin); //Recebe Data de Diagnostico Positivo

        fflush(stdin);
        printf("\n\nComorbidades do Paciente: ");
        fgets(Pessoa.Comorbidade, 50, stdin); //Recebe Quais Comorbidades o Paciente Possui


        system("cls");
        printf("\n=============================\n");
        printf("Finalizar cadastro? Selecione 1 para efetuar cadastro ou 2 para cancelar! [1/2] : ");
        scanf("%d", &Global.Cd);

        if(Global.Cd == 1)
        {
            fflush(stdin);
            fprintf(DB,"\n\nNome: %s", Pessoa.Nome);

            fflush(stdin);
            fprintf(DB,"\n\nIdade: %s", Pessoa.Idade);

            fflush(stdin);
            fprintf(DB,"\n\nCPF: %s", Pessoa.Cpf);

            fflush(stdin);
            fprintf(DB,"\n\nTelefone: %s", Pessoa.Telefone);

            fflush(stdin);
            fprintf(DB,"\n\nEndereço: %s", Pessoa.Endereco);

            fflush(stdin);
            fprintf(DB,"\n\nCEP: %s", Pessoa.Cep);

            fflush(stdin);
            fprintf(DB,"\n\nE-mail:  %s", Pessoa.Email);

            fflush(stdin);
            fprintf(DB,"\n\nData de Diagnostico+: %s", Pessoa.Email);

            fflush(stdin);
            fprintf(DB,"\n\nComorbidades: %s", Pessoa.Comorbidade);

            fprintf(DB, "\n---------------------------------------------------\n");

            if ((Pessoa.Idade >= 65) || (Pessoa.Comorbidade != NULL))
            {
                fprintf(GR, "======GRUPO DE RISCO======");
                fprintf(GR,"\nNome: %s", Pessoa.Nome);
                fprintf(GR,"\n\nIdade: %s", Pessoa.Idade);
                fprintf(GR,"\n\nCEP: %s", Pessoa.Cep);
                fprintf(GR,"\n\nComorbidade: %s", Pessoa.Comorbidade);
            }

            fclose(DB); //Fecha arquivo dados.txt
            fclose(GR); //Fechar arquivo dados.txt

            Sleep(1000);
            printf("######################\n");
            printf("# Cadastro Concluído #\n");
            printf("######################\n");

            Menu();

        }
        else if(Global.Cd == 2)
        {
            system("cls");
            printf("Cadastro Cancelado.\nVoltando ao Menu Principal...\n");
            fclose(DB);
            Menu();

        }
        else if(Global.Cd != 1 && Global.Cd != 2)
        {
            printf("Valor inválido. Tente novamente...\n");
            fclose(DB);
            Menu();
        }

    }
    return 0;
}

//Função Listar
void Listar()
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    DB = fopen("dados.txt", "r"); // r: Abertura do DB para leitura de dados

    if(DB == NULL)
    {
        Sleep(1000);
        printf("\nErro no Banco de Dados...\n");
        exit(2);

    }
    else
    {
        printf("=======================\n");
        printf(" LISTAGEM DE PACIENTES\n");
        printf("=======================\n\n");

        char listagem[500]; //Quantidade de cadastros armazenados

        while(fgets(listagem, 500, DB) != NULL)
        {
            printf("%s", listagem);

        } //Considera todos os dados como uma String e exibe na tela

        fclose(DB);

        printf("\nSelecione qualquer tecla para voltar ao menu: ");
        scanf("%d", &Global.Cd);

        if(Global.Cd == 1)
        {
            Menu();

        }
        else if(Global.Cd != 1 && Global.Cd != 2)
        {
            printf("Valor inválido.\nVoltando ao Menu Principal...\n");
            Menu();
        }

    }
} //Fim da função Listar

void GrupoRisco()
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    GR = fopen("secretaria.txt", "r"); // r: Abertura do DB para leitura de dados

    if(DB == NULL)
    {
        Sleep(1000);
        printf("\nErro no Banco de Dados...\n");
        exit(2);

    }
    else
    {
        printf("========================\n");
        printf(" LISTA GRUPO DE RISCO\n");
        printf("========================\n\n");

        char listarisco[500]; //Quantidade de cadastros armazenados

        while(fgets(listarisco, 500, GR) != NULL)
        {
            printf("%s", listarisco);

        } //Considera todos os dados como uma String e exibe na tela

        fclose(DB);

        printf("\nSelecione qualquer tecla para voltar ao menu: ");
        scanf("%d", &Global.Cd);

        if(Global.Cd == 1)
        {
            Menu();

        }
        else if(Global.Cd != 1 && Global.Cd != 2)
        {
            printf("Valor inválido.\nVoltando ao Menu Principal...\n");
            Menu();
        }

    }
} //Fim da função Grupo de Risco
