#include<stdio.h>
#include<stdbool.h>
#define CANT_TORRES 3
#define MAX_CANT_DISCOS 10

typedef struct torre{
    char diametros [MAX_CANT_DISCOS];
    int posicion_disco_superior;//sera -1 si la torre esta vacia. Jarcodeo!
}torre_t;

void mostrar_torres(torre_t torre_izquierda, torre_t torre_centro, torre_t torre_derecha);
void mostrar_disco(torre_t torre, int numero_disco);
torre_t torre_inicializar(int cantidad_discos);
bool es_movimiento_legal(torre_t torre_destino, torre_t torre_origen);
bool esta_vacia(torre_t torre);
bool poner_disco(torre_t* torre,char diametro);
char sacar_disco(torre_t* torre);
bool mover_disco(torre_t* destino, torre_t* origen);
void resolver_torres(torre_t* torre_C, torre_t* torre_B, torre_t* torre_A);

int main(){
    int input;
    printf("ingrese la cantidad de discos a utilizar\n");
    scanf("%d", &input);
    if(input> MAX_CANT_DISCOS)
        return -1;
    torre_t torre_izquierda = torre_inicializar(0);
    torre_t torre_centro= torre_inicializar(0);
    torre_t torre_derecha= torre_inicializar(input);
    mostrar_torres(torre_izquierda,torre_centro,torre_derecha);
    resolver_torres(&torre_izquierda,&torre_centro,&torre_derecha);
    mostrar_torres(torre_izquierda,torre_centro,torre_derecha);

    return 0;
}
void resolver_torres(torre_t* torre_C, torre_t* torre_B, torre_t* torre_A){
    int cantidad_discos = torre_A->posicion_disco_superior+1;
    if(cantidad_discos%2==0){
        while(!esta_vacia(*torre_A) || !esta_vacia(*torre_B)){
            mover_disco(torre_A,torre_B)?0:mover_disco(torre_B,torre_A);
            mostrar_torres(*torre_C,*torre_B,*torre_A);
            mover_disco(torre_A,torre_C)?0:mover_disco(torre_C,torre_A);
            mostrar_torres(*torre_C,*torre_B,*torre_A);
            mover_disco(torre_C,torre_B)?0:mover_disco(torre_B,torre_C);
            mostrar_torres(*torre_C,*torre_B,*torre_A);
        }
    }else{
        while(!esta_vacia(*torre_A) || !esta_vacia(*torre_B)){
            mover_disco(torre_A,torre_C)?0:mover_disco(torre_C,torre_A);
            mostrar_torres(*torre_C,*torre_B,*torre_A);
            mover_disco(torre_A,torre_B)?0:mover_disco(torre_B,torre_A);
            mostrar_torres(*torre_C,*torre_B,*torre_A);
            if(esta_vacia(*torre_B))
                continue;
            mover_disco(torre_C,torre_B)?0:mover_disco(torre_B,torre_C);
            mostrar_torres(*torre_C,*torre_B,*torre_A);
        }

    }
}
bool mover_disco(torre_t* destino, torre_t* origen){
    if(!es_movimiento_legal(*destino,*origen))
        return false;
    char disco = sacar_disco(origen);
    return poner_disco(destino,disco);
}
char sacar_disco(torre_t* torre){
    if(esta_vacia(*torre))
        return 0;
    char retorno = torre->diametros[torre->posicion_disco_superior];
    torre->diametros[torre->posicion_disco_superior]=0;
    torre->posicion_disco_superior--;
    return retorno;
}
bool poner_disco(torre_t* torre,char diametro){
    if(torre->posicion_disco_superior == MAX_CANT_DISCOS-1 && !esta_vacia(*torre))
        return false;//para evitar segfaults
    if(torre->diametros[torre->posicion_disco_superior]< diametro && !esta_vacia(*torre))
        return false;//caso movimiento invalido
    if(diametro<=0)
        return false;

    torre->posicion_disco_superior++;
    torre->diametros[torre->posicion_disco_superior]=diametro;
    return true;
}

bool esta_vacia(torre_t torre){
    return torre.posicion_disco_superior<0;
}
bool es_movimiento_legal(torre_t torre_destino, torre_t torre_origen){
    if(esta_vacia(torre_origen))
        return false;
    if(esta_vacia(torre_destino))
        return true;
    //El codigo a continuacion se rompe con torres vacias, por eso separo los dos casos

    int diametro_disco_destino= torre_destino.diametros[torre_destino.posicion_disco_superior];
    int diametro_disco_origen= torre_origen.diametros[torre_origen.posicion_disco_superior];
    return (diametro_disco_destino>diametro_disco_origen);
}
void mostrar_torres(torre_t torre_izquierda, torre_t torre_centro, torre_t torre_derecha){
    for (int i=MAX_CANT_DISCOS-1;i>=0;i--){
        mostrar_disco(torre_izquierda, i);
        mostrar_disco(torre_centro, i);
        mostrar_disco(torre_derecha, i);
        printf("\n");
    }
}
void mostrar_disco(torre_t torre, int numero_disco){
    int cantidad_discos = torre.diametros[numero_disco];
    int cantidad_espacios = MAX_CANT_DISCOS - cantidad_discos;
    for(int i=0;i<cantidad_discos;i++)
        printf("X");
    for(int i=0;i<cantidad_espacios;i++)
        printf(" ");
}
torre_t torre_inicializar(int cantidad_discos){
    torre_t retorno;
    retorno.posicion_disco_superior=cantidad_discos-1;

    for(int i =0; i<MAX_CANT_DISCOS; i++){
        int diametro_disco_actual= cantidad_discos-i;
        if(i<cantidad_discos)
            retorno.diametros[i]= (char) diametro_disco_actual;
        else
            retorno.diametros[i]=0;
    }

    return retorno;
}

/*codigo de prueba
puts("Torres al comienzo");
mostrar_torres(torre_izquierda,torre_centro,torre_derecha);
mover_disco(&torre_izquierda,&torre_derecha);
mostrar_torres(torre_izquierda,torre_centro,torre_derecha);
mover_disco(&torre_centro,&torre_derecha);
mostrar_torres(torre_izquierda,torre_centro,torre_derecha);
mover_disco(&torre_centro,&torre_izquierda);
mostrar_torres(torre_izquierda,torre_centro,torre_derecha);
*/
