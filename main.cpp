#include "red.h"

int Posicion_Nodo(char *definitivos, int n, char Nd, char *ruta, int i);
void Iimprimir_Ruta(char *definitivos, char *ruta, int n);
int main()
{
    Red red;
    short resp, opc; //menus
    string archivo;
    char nombre,**Matriz2,*definitivos,*ruta,Nodo;
    int n,**matriz,num;
    cout<<"(1) Crear una red interactuando con la consola"<<endl<<"(2) Cargar una red desde un archivo"<<endl<<"(3) Crear una red de manera aleatoria"<<endl;
    cin>>resp;
    switch (resp) {
        case 1:
        break;

        case 2:
            cout<<"Digite el nombre del archivo con la extencion: "<<endl;
            cin>>archivo;
            red.Leer_Archivo(archivo);

        break;

        default:
        char letra;
            int n=30;
            do{
                cout<<"Digite el numero de nodos que van a componer su red: "<<endl;
                cin>>n;
            } while(n>26);
            letra=red.generar_letra();
            red.red_aleatoria("Aleatoria.txt",letra,n);
            red.Leer_Archivo("Aleatoria.txt");
        break;
    }
        while(true){
            cout<<"(1) Agregar un enrutador "<<endl<<"(2) Eliminar un enrutador "<<endl<<"(3) Editar enlaces de un enrutador"<<endl<<"(4) Imprimir tabla de enrutamiento de un nodo"<<endl<<"(5) Imprimir matriz de adyasencia"<<endl<<"(6) Imprimir tabla de enrutamiento"<<endl<<"(7) Costo desde un enrutador origen a uno destino"<<endl;
            cin>>opc;
            switch (opc) {
                case 1:
                    cout<<"Ingrese el nombre del enrutador: "<<endl;
                    cin>>nombre;
                    red.agregar_nuevo_nodo(nombre);
                break;

                case 2:
                    cout<<"Ingresar el nombre del enrutador a eliminar"<<endl;
                    cin>>nombre;
                    red.Eliminar_nodo(nombre);
                break;

                case 3:
                    cout<<"Ingrese el nombre del enrutador a editar"<<endl;
                    cin>>nombre;
                    red.Editar_Nodo(nombre);
                break;
                case 4:
                    cout<<"Ingrese el nombre del enrutador a imprimir: "<<endl;
                    cin>>nombre;
                    red.Imprimir_TEnrutamiento(nombre);
                break;

                case 5:
                    red.Matriz_Adyasencia();
                break;

                case 6:
                    red.Imprimir_Tabla();
                break;

                default:
                    char No, Nd;
                    int posicion=0,menor,cont=0,menordef;
                    bool resp=false;
                    n=red.Contar_Nodos();
                    definitivos=new char [n];
                    matriz=new int *[n];
                    Matriz2=new char *[n];
                    ruta=new char [n];
                    for(int i=0;i<n;i++){
                        matriz[i]=new int [n];
                        Matriz2[i]=new char [n];
                    }
                    cout<<endl<<"Ingrese el nodo origen y el nodo destino respectivamente"<<endl;
                    cin>>No>>Nd;
                    definitivos[0]=No;
                    red.Dijkstra(matriz,Matriz2,n,definitivos);
                    cout<<"Algoritmo de Dijkstra: "<<endl<<endl;
                    for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                            cout<<matriz[i][j]<<Matriz2[i][j]<<"  ";
                        }
                        cout<<endl;
                    }
                    int k=1;
                    posicion=Posicion_Nodo(definitivos,n,Nd,ruta,cont);
                    while(resp==false){
                        menor=101;
                        for(int i=0;i<n;i++){
                            num=matriz[i][posicion];
                            if(num<menor && num !=-2 && num!=-1){
                                menor=num;
                                Nodo=Matriz2[i][posicion];
                                ruta[k]=Nodo;

                                if(k==1) menordef=menor;

                            }
                        }
                        if(k==1) cout<<endl<<"El costo minimo es: "<<menordef<<endl;
                        posicion=Posicion_Nodo(definitivos,n,Nodo,ruta,cont);
                        if(posicion==0) resp=true;
                        k+=1;
                    }
                    ruta[0]=Nd;
                    cout<<"La mejor ruta es: ";
                    Iimprimir_Ruta(definitivos,ruta,n);
                    cout<<endl<<endl;

                break;
            }
        }

    return 0;
}

int Posicion_Nodo(char *definitivos, int n, char Nd, char *ruta,int i){
    int posicion=0;
    for(int k=0;k<n;k++){
        if(definitivos[k]!=Nd){
            posicion+=1;
        }
        else if(i==0){
            ruta[i]=definitivos[n];
            break;
        }
        else break;
    }
    return posicion;
}

void Iimprimir_Ruta(char *definitivos, char *ruta, int n){
    char letra;
    for(int i=n;i>=0;i--){
        letra=ruta[i];
        for(int j =0;j<n;j++){
            if(letra==definitivos[j]){
                cout<<letra<<" ";
                break;
            }
        }
    }
}
