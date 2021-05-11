#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <time.h>


void mainMenu();

void help();

void ls();

void cat(char *token);

void touch(char *token);

void dir();

int beenden();

void cd(char *token);

void pwd();

void rm(char *token);

void mkdr(char *token);

void rmdr(char *token);

void echo(char *token);

int main() {
    printf("Wilkommen in der Shell\n");
    mainMenu();
    return 0;
}

void mainMenu() {
    char input[100];
    const char s[2] = " ";
    char *token;
    int exit = 0;

    while (exit != 1) {
        printf(">");
        gets(input);
        fflush(stdin);
        token = strtok(input, s);
        if (strcmp(input, "exit") == 0) {
            exit = beenden();
        } else if (strcmp(input, "help") == 0) {
            help();
        } else if (strcmp(input, "ls") == 0) {
            ls();
        } else if (strcmp(input, "dir") == 0) {
            dir();
        } else if (strcmp(input, "cat") == 0) {
            while (token != NULL) {
                token = strtok(NULL, s);
                cat(token);
            }
        } else if (strcmp(input, "touch") == 0) {
            while (token != NULL) {
                token = strtok(NULL, s);
                touch(token);
            }
        } else if (strcmp(input, "cd") == 0) {
            while (token != NULL) {
                token = strtok(NULL, s);
                cd(token);
                break;
            }
        } else if (strcmp(input, "pwd") == 0) {
            pwd();
        } else if (strcmp(input, "rm") == 0) {
            while (token != NULL) {
                token = strtok(NULL, s);
                if(token!=NULL){
                    rm(token);
                }
            }
        }else if (strcmp(input, "mkdir") == 0) {
            while (token != NULL) {
                token = strtok(NULL, s);
                if(token!=NULL){
                    mkdr(token);
                }
            }
        } else if (strcmp(input, "rmdir") == 0) {
            while (token != NULL) {
                token = strtok(NULL, s);
                if(token!=NULL){
                    rmdr(token);
                }
            }
        }else if (strcmp(input, "echo") == 0) {
            while (token != NULL) {
                token = strtok(NULL, "'");
                if(token!=NULL){
                    echo(token);
                }
            }
        }else {
            printf("Befehl gibs net du hurensohn\n");
        }
    }
}

void echo(char *token) {
    printf("%s\n", token);
}

void rmdr(char *token) {
    if((rmdir(token))!=-1){
        printf("Folgender Ordner wurde geloescht: %s\n", token);
    }else{
        perror("Fehler beim löschen des Ordners\n");
    }
}

void mkdr(char *token) {
    if((mkdir(token))!=-1){
        printf("Folgender Ordner wurde erstellt: %s\n", token);
    }else{
        perror("Fehler beim erstellen des Ordners\n");
    }
}

void rm(char *token) {
    if((remove(token))!=-1){
        printf("Folgende Datei wurde geloescht: %s\n", token);
    }else{
        perror("Fehler beim Datei löschen\n");
    }
}

void pwd() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Aktueller Ordner: %s\n", cwd);
    } else {
        perror("Fehler");
    }
}

void cd(char *token) {
    char s[100];

    if (chdir(token) != 0) {
        perror("chdir() felgeschlagen");
    }
    printf("%s\n", getcwd(s, 100));
}

int beenden() {
    return 1;
}

void dir() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}

void touch(char *token) {
    FILE *fp = NULL;
    fp = fopen(token, "w");
    if (fp == NULL) {
    }
    fclose(fp);
}

void cat(char *token) {
    FILE *fp;
    char output[100];
    fp = fopen(token, "r");
    while (fgets(output, 100, fp) != NULL) {
        printf("%s", output);
    }
    fclose(fp);
    printf("\n");
}

void ls() {
    DIR *p;
    struct dirent *d;
    struct stat mystat;
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Ordner: %s\n", cwd);
        p = opendir(cwd);
        if (p == NULL) {
            perror("Kann Ordner nicht öffnen");
            exit(-1);
        }
        while ((d = readdir(p)) != NULL) {
            stat(d->d_name, &mystat);
            if (S_ISDIR(mystat.st_mode)) {
                printf("DIR\t");
            } else {
                printf("\t%ld", mystat.st_size);
            }
            printf("\t");
            //printf("%s\t",ctime(&mystat.st_mtime));
            printf("%s\n", d->d_name);
        }
    } else {
        perror("getcwd() error");
    }
}

void help() {
    printf("Hilf do selbo i bin zi lost\n");
}
