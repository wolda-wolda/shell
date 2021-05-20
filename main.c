#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

#ifdef _WIN32
#define OSWindows 1
#define OSLinux 0
#elif __linux__
#define OSLinux 1
#define OSWindows 0
#endif

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

#define reset "\e[0m"
int temp;

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

void mkdr(char *token, int i);

void rmdr(char *token);

void echo(char *token);

void cp(char *token, int i);

void mv(char *token, int i);

void cmod(char *token, int i);

int main() {
#ifdef _WIN64
    printf("Betriebssystem: Windows 64 bit\n");
#elif _WIN32
    printf(": Betriebssystem: Windows 32 bit\n");
#elif __linux__
    printf("Betriebssystem: Linux\n");
#endif
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
        fgets(input, 100, stdin);
        fflush(stdin);
        for (int i = 0; i < 100; ++i) {
            if (input[i] == '\n') {
                input[i] = '\000';
                break;
            }
        }
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
                if (token != NULL) {
                    cat(token);
                }
            }
        } else if (strcmp(input, "touch") == 0) {
            while (token != NULL) {
                token = strtok(NULL, s);
                if (token != NULL) {
                    touch(token);
                }

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
                if (token != NULL) {
                    rm(token);
                }
            }
        } else if (strcmp(input, "mkdir") == 0) {
            int i = 0;
            while (token != NULL) {
                token = strtok(NULL, s);
                if (token != NULL) {
                    mkdr(token, i);
                    i++;
                }
            }
        } else if (strcmp(input, "rmdir") == 0) {
            while (token != NULL) {
                token = strtok(NULL, s);
                if (token != NULL) {
                    rmdr(token);
                }
            }
        } else if (strcmp(input, "echo") == 0) {
            while (token != NULL) {
                token = strtok(NULL, "'");
                if (token != NULL) {
                    echo(token);
                }
            }
        } else if (strcmp(input, "cp") == 0) {
            int i = 0;
            while (token != NULL && i < 2) {
                token = strtok(NULL, s);
                if (token != NULL) {
                    cp(token, i);
                    i++;
                }
            }
        } else if (strcmp(input, "mv") == 0) {
            int i = 0;
            while (token != NULL && i < 2) {
                token = strtok(NULL, s);
                if (token != NULL) {
                    mv(token, i);
                    i++;
                }
            }
        } else if (strcmp(input, "chmod") == 0) {
            if (OSWindows != 1) {
                int i = 0;
                while (token != NULL && i < 2) {
                    token = strtok(NULL, s);
                    if (token != NULL) {
                        cmod(token, i);
                        i++;
                    }
                }
            } else {
                printf("Der chmod Befehl steht nur unter Linux zur Verfuegung");
            }
        } else if (strcmp(input, "settings") == 0) {
            char input[100];
            printf("Welche Schriftfarbe möchten Sie?:\nSchwarz\nRot\nGruen\nGelb\nBlau\nMagenta\nCyan\nWeiß\nReset\n");
            fgets(input, 100, stdin);
            if (strcmp(input, "Schwarz\n") == 0) {
                printf(BLK);
            } else if (strcmp(input, "Rot\n") == 0) {
                printf(RED);
            } else if (strcmp(input, "Gruen\n") == 0) {
                printf(GRN);
            } else if (strcmp(input, "Gelb\n") == 0) {
                printf(YEL);
            } else if (strcmp(input, "Blau\n") == 0) {
                printf(BLU);
            } else if (strcmp(input, "Magenta\n") == 0) {
                printf(MAG);
            } else if (strcmp(input, "Cyan\n") == 0) {
                printf(CYN);
            } else if (strcmp(input, "Weiß\n") == 0) {
                printf(WHT);
            } else {
                printf(reset);
            }
            printf("Welche Hintergrundfarbe möchten Sie?:\nSchwarz\nRot\nGruen\nGelb\nBlau\nMagenta\nCyan\nWeiß\nReset\n");
            fgets(input, 100, stdin);
            if (strcmp(input, "Schwarz\n") == 0) {
                printf(BLKB);
            } else if (strcmp(input, "Rot\n") == 0) {
                printf(REDB);
            } else if (strcmp(input, "Gruen\n") == 0) {
                printf(GRNB);
            } else if (strcmp(input, "Gelb\n") == 0) {
                printf(YELB);
            } else if (strcmp(input, "Blau\n") == 0) {
                printf(BLUB);
            } else if (strcmp(input, "Magenta\n") == 0) {
                printf(MAGB);
            } else if (strcmp(input, "Cyan\n") == 0) {
                printf(CYNB);
            } else if (strcmp(input, "Weiß\n") == 0) {
                printf(WHTB);
            } else {
                printf(reset);
            }
        } else {
            printf(RED"Befehl exestiert nicht"reset"\n");
        }
    }
}

int convertChmodValue(int x) {
    int ret = 0;

    int values[] = {400, 200, 100, 40, 20, 10, 4, 2, 1};
    int dez[] = {256, 128, 64, 32, 16, 8, 4, 2, 1};
    int i;
    for (i = 0; i < 9; i++) {
        if (x - values[i] >= 0) {
            x = x - values[i];
            ret = ret + dez[i];
        }
    }

    if (x == 0) {
        return ret;
    } else {
        return -1;
    }
}

void cmod(char *token, int i) {
    if (i == 0) {
        temp = atoi(token);
    } else {
        if (convertChmodValue(temp) != -1) {
            temp = convertChmodValue(temp);
            printf("%d", temp);
            chmod(token, temp);
            printf("Berechtigungen geändert\n");
        } else {
            printf("Falsche Zahlen\n");
        }
    }
}

void mv(char *token, int i) {
    char buffer[100];
    DIR *dir;
    char *start;

    if (i == 0) {
        start = token;
    } else if (i == 1) {
        dir = opendir(start);
        if (dir) {
            int ret = 0;
            ret = rename(start, token);
            if (ret != 0) {
                perror("rename");
            }
            closedir(dir);
        } else if (ENOENT == errno) {
            perror("opendir");
            printf("\n");
            closedir(dir);
        } else {
            FILE *fp = fopen(start, "r");
            if (fp == NULL) {
                perror("fopen");
                printf("\n");
            } else {
                dir = opendir(token);
                if (dir) {
                    strcat(token, start);
                    closedir(dir);
                } else if (ENOENT == errno) {
                }
                FILE *fp2 = fopen(token, "w");
                if (fp2 == NULL) {
                    perror("fopen");
                    printf("\n");
                } else {
                    while (fgets(buffer, 100, fp) != NULL) {
                        fputs(buffer, fp2);
                    }
                    fclose(fp2);
                    fclose(fp);
                    remove(start);
                }
            }
        }
    }
}

void cp(char *token, int i) {
    FILE *fp;
    FILE *fp2;
    char *token2;
    char buffer[100];

    if (i == 0) {
        token2 = token;
    } else if (i < 2) {
        fp = fopen(token2, "r");
        if (fp == NULL) {
            perror("fopen");
        } else {
            strcat(token, token2);
            fp2 = fopen(token, "w");
            if (fp2 == NULL) {
                perror("fopen");
            } else {
                while (fgets(buffer, 100, fp) != NULL) {
                    fputs(buffer, fp2);
                }
                fclose(fp2);
            }
            fclose(fp);
        }
    }
}

void echo(char *token) {
    printf("%s\n", token);
}

void rmdr(char *token) {
    if ((rmdir(token)) != -1) {
        printf("Folgender Ordner wurde geloescht: %s\n", token);
    } else {
        perror("Fehler beim löschen des Ordners\n");
    }
}

void mkdr(char *token, int i) {
#ifdef WIN32
    if ((mkdir(token)) != -1) {
        printf("Folgender Ordner wurde erstellt: %s\n", token);
    } else {
        perror("Fehler beim erstellen des Ordners\n");
    }
#else
    if((mkdir(token, 0777))!=-1){
        printf("Folgender Ordner wurde erstellt: %s\n", token);
    }else {
        perror("Fehler beim erstellen des Ordners\n");
        }
#endif
}

void rm(char *token) {
    if ((remove(token)) != -1) {
        printf("Folgende Datei wurde geloescht: %s\n", token);
    } else {
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
            printf("%s\n", d->d_name);
        }
    } else {
        perror("getcwd() error");
    }
}

void help() {
    printf("Hilf do selbo i bin zi lost\n");
}
