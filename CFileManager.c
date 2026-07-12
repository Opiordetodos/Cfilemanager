#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//gcc ..\proj_Gerenciardor_arquivo_cli.c -o proj_Gerenciardor_arquivo_cli.exe - compiling
void __init__(char *caminho_atual){
    char *perfil = getenv("USERPROFILE");
    strcpy(caminho_atual, perfil);
    strcat(caminho_atual, "\\Desktop");
}
void __return__(char *caminho_atual){
    char *ultimo = strrchr(caminho_atual, '\\');
    if(ultimo != NULL){
        *ultimo = '\0';
    }
}
void __List__(char *caminho_atual){
    WIN32_FIND_DATA dado;
    char caminho_busca[MAX_PATH];
    sprintf(caminho_busca, "%s//*", caminho_atual);
    HANDLE handle = FindFirstFile(caminho_busca, &dado);
    do {
        if(strcmp(dado.cFileName, ".") == 0 || strcmp(dado.cFileName, "..") == 0) continue;
        if(dado.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
            printf("[PASTA] %s\n", dado.cFileName);
        } else {
            printf("[ARQUIVO] %s - %.2f KB\n", dado.cFileName, dado.nFileSizeLow / 1024.0);
        }
    } while(FindNextFile(handle, &dado));
    FindClose(handle);
}
void __entry__(char *caminho_atual){
    while(getchar() != '\n');
    char nome_pasta[MAX_PATH];
    printf("Insira o nome da pasta: ");
    fgets(nome_pasta, MAX_PATH, stdin);
    nome_pasta[strcspn(nome_pasta, "\n")] = '\0';
    strcat(caminho_atual, "\\");
    strcat(caminho_atual, nome_pasta);

}
void __copy__(char *caminho_atual){
    char destino[MAX_PATH];
    char comando[MAX_PATH * 2 + 10];
    char archive_name[MAX_PATH];
    while(getchar() != '\n');
    printf("Qual arquivo deseja copiar: ");
    fgets(archive_name, MAX_PATH, stdin);
    archive_name[strcspn(archive_name, "\n")] = '\0';
    printf("Insira o destino do arquivo copiado: ");
    fgets(destino, MAX_PATH, stdin);
    destino[strcspn(destino, "\n")] = '\0';
    sprintf(comando, "copy \"%s\\%s\" \"%s\"", caminho_atual, archive_name, destino);
    system(comando);
}
void __move__(char *caminho_atual){
    char destino[MAX_PATH];
    char comando[MAX_PATH * 2 + 10];
    char archive_name[MAX_PATH];
    while(getchar() != '\n');
    printf("Qual arquivo deseja mover: ");
    fgets(archive_name, MAX_PATH, stdin);
    archive_name[strcspn(archive_name, "\n")] = '\0';
    printf("Insira o destino do arquivo que ira ser movido: ");
    fgets(destino, MAX_PATH, stdin);
    destino[strcspn(destino, "\n")] = '\0';
    sprintf(comando, "move \"%s\\%s\" \"%s\"", caminho_atual, archive_name, destino);
    system(comando);
}
void __delet__(char *caminho_atual){
    char origem[MAX_PATH];
    char comando[MAX_PATH * 2 + 10];
    char yesorno;
    while(getchar() != '\n');
    printf("Insira o nome do arquivo: ");
    fgets(origem, MAX_PATH,stdin);
    origem[strcspn(origem, "\n")] = '\0';
    printf("Deseja mesmo excluir o arquivo %s \n S - Sim \n N - Nao \n", origem);
    scanf("%c", &yesorno);
    if (yesorno == 'S' || yesorno == 's'){
        sprintf(comando, "del \"%s\\%s\"", caminho_atual, origem);
        system(comando);
        printf("Arquivo excluido com sucesso \n");
    }else{
        printf("Operação cancelada");
    }
}
void __rename__(char *caminho_atual){
    char new_name[MAX_PATH];
    char comando[MAX_PATH * 2 + 10];
    char archive_name[MAX_PATH];
    while(getchar() != '\n');
    printf("Qual arquivo deseja mudar o nome: ");
    fgets(archive_name, MAX_PATH, stdin);
    archive_name[strcspn(archive_name, "\n")] = '\0';

    printf("Insira o novo nome do arquivo: ");
    fgets(new_name, MAX_PATH, stdin);
    new_name[strcspn(new_name, "\n")] = '\0';
    sprintf(comando, "rename \"%s\\%s\" \"%s\"", caminho_atual, archive_name, new_name);
    system(comando);
}
void __createpaste__(char *caminho_atual){
    char paste_name[MAX_PATH];
    char comando[MAX_PATH];
    while(getchar() != '\n');
    printf("Insira o nome da pasta: ");
    fgets(paste_name, MAX_PATH, stdin);
    paste_name[strcspn(paste_name, "\n")] = '\0';
    sprintf(comando, "mkdir %s\\%s", caminho_atual, paste_name);
    system(comando);
}

int main(){
    int IStrue = 1;
    int selected;
    char caminho[MAX_PATH];
    __init__(caminho);
    do{
        printf("%s \n", caminho);
        printf("MENU - GERENCIADOR DE ARQUIVOS \n 1 - Listar conteudo \n 2 - Entrar em pasta \n 3 - Voltar\n 4 - Copiar arquivo (mantem o original)\n 5 - Mover arquivo (remove o original)\n 6 - Deletar arquivo\n 7 - Renomear arquivo ou pasta\n 8 - Criar pasta \n 0 - ENCERRAR PROGRAMA \n");
        scanf("%d", &selected);
        switch (selected){
        case 0:
            IStrue = 0;
            printf("Programa encerrado...");
            break;
        case 1:
            __List__(caminho);
            break;
        case 2:
            __entry__(caminho);
            break;
        case 3: 
            __return__(caminho);
            break;
        case 4:
            __copy__(caminho);
            break;
        case 5:
            __move__(caminho);
            break;
        case 6:
            __delet__(caminho);
            break;
        case 7:
            __rename__(caminho);
            break;
        case 8:
            __createpaste__(caminho);
            break;
        default:
            break;
        }
    }while(IStrue != 0);
    
    
    return 0;
}
