#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define f 8
#define c 8
#define b 10

void limpiarpantalla(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int main(){
    char v[f][c], o[f][c];
    int i,j,x,y,op,seguir;

    srand(time(NULL));

    do{
        limpiarpantalla();
        printf("1 jugar\n2 salir\nopcion: ");
        scanf("%d",&op);

        switch(op){
            case 1:
                // inicializar
                for(i=0;i<f;i++){
                    for(j=0;j<c;j++){
                        v[i][j]='#';
                        o[i][j]=' ';
                    }
                }

                // bombas
                for(i=0;i<b;i++){
                    x=rand()%f;
                    y=rand()%c;
                    if(o[x][y]=='*') i--;
                    else o[x][y]='*';
                }

                seguir=1;
                while(seguir){
                    limpiarpantalla();

                    // mostrar
                    for(i=0;i<f;i++){
                        for(j=0;j<c;j++){
                            printf("%c ",v[i][j]);
                        }
                        printf("\n");
                    }

                    // jugada
                    printf("fila: "); scanf("%d",&x);
                    printf("col: "); scanf("%d",&y);

                    if(x<0 || x>=f || y<0 || y>=c){
                        printf("error\n");
                    }else{
                        if(o[x][y]=='*'){
                            printf("perdiste\n");
                            seguir=0;
                        }else{
                            v[x][y]=' ';
                        }
                    }

                    printf("enter...");
                    getchar(); getchar();
                }
                break;

            case 2:
                printf("adios\n");
                break;

            default:
                printf("opcion invalida\n");
                getchar(); getchar();
                break;
        }

    }while(op!=2);

    return 0;
}
