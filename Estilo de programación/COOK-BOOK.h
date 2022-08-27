#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define MAX 10005 //maximo numero de vértices
#define Node pair< int , int > //definimos el nodo como un par( first , second ) donde first es el vertice adyacente y second el peso de la arista
#define INF 1<<30 //definimos un valor grande que represente la distancia infinita inicial, basta conque sea superior al maximo valor del peso en alguna de las aristas

struct cmp {
    bool operator() ( const Node &a , const Node &b ) {
        return a.second > b.second;
    }
};
vector< Node > ady[ MAX ]; //lista de adyacencia
int distancia[ MAX ];      //distancia[ u ] distancia de vértice inicial a vértice con ID = u
bool visitado[ MAX ];      //para vértices visitados
priority_queue< Node , vector<Node> , cmp > Q; 
int V;                     //numero de vertices
int previo[ MAX ];         //para la impresion de caminos

//función de inicialización
void init(){
    for( int i = 0 ; i <= V ; ++i ){
        distancia[ i ] = INF;  //inicializamos todas las distancias con valor infinito
        visitado[ i ] = false; //inicializamos todos los vértices como no visitados
        previo[ i ] = -1;      //inicializamos el previo del vertice i con -1
    }
}

//Paso de relajacion
void relajacion( int actual , int adyacente , int peso ){
    //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;  //relajamos el vertice actualizando la distancia
        previo[ adyacente ] = actual;                         //a su vez actualizamos el vertice previo
        Q.push( Node( adyacente , distancia[ adyacente ] ) ); //agregamos adyacente a la cola de prioridad
    }
}

//Impresion del camino mas corto desde el vertice inicial y final ingresados
void print( int destino ){
    if( previo[ destino ] != -1 )    //si aun poseo un vertice previo
        print( previo[ destino ] );  //recursivamente sigo explorando
    printf("%d " , destino );        //terminada la recursion imprimo los vertices recorridos
}

void dijkstra( int inicial ){
    init(); //inicializamos nuestros arreglos
    Q.push( Node( inicial , 0 ) ); //Insertamos el vértice inicial en la Cola de Prioridad
    distancia[ inicial ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    int actual , adyacente , peso;
    while( !Q.empty() ){                   //Mientras cola no este vacia
        actual = Q.top().first;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        Q.pop();                           //Sacamos el elemento de la cola
        if( visitado[ actual ] ) continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        visitado[ actual ] = true;         //Marco como visitado el vértice actual

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){ //reviso sus adyacentes del vertice actual
            adyacente = ady[ actual ][ i ].first;   //id del vertice adyacente
            peso = ady[ actual ][ i ].second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            if( !visitado[ adyacente ] ){        //si el vertice adyacente no fue visitado
                relajacion( actual , adyacente , peso ); //realizamos el paso de relajacion
            }
        }
    }


    printf( "Tiempos mas cortos iniciando en vertice %d\n" , inicial );
    for( int i = 1 ; i <= V ; ++i ){
        printf("Vertice %d , tiempo mas corto = %d minutos \n" , i , distancia[ i ] );
    }

    puts("\n**************Impresion del tiempo mas corto**************");
    printf("Ingrese vertice destino: ");
    int destino;
    scanf("%d" , &destino );
    print( destino );
    printf("\n");
}

void menu1(){

    FILE *fp;
    fp = fopen("rutas.txt","r");
    

    cout<<"\n\t _____________CODIGOS POR CIUDAD(ID)_____________"<<endl;
    cout<<"\t 1    LIMA"<<endl;
    cout<<"\t 2    AREQUIPA"<<endl;
    cout<<"\t 3    LA LIBERTAD"<<endl;
    cout<<"\t 4    PIURA"<<endl;
    cout<<"\t 5    TACNA"<<endl;
    cout<<"\t 6    CAJAMARCA"<<endl;
    cout<<"\t 7    LORETO"<<endl;
    cout<<"\t 8    SAN MARTIN"<<endl;
    cout<<"\t 9    MADRE DE DIOS"<<endl;
    cout<<"\t 10   CUSCO"<<endl;
    cout<<"\t 11   AYACUCHO"<<endl;
    
    int E , origen, destino , peso , inicial;
    
    V=6; //vertices
    E=10;  //aristas

    while( E-- ){  
    fscanf(fp, "%d %d %d", &origen , &destino , &peso);
    ady[ origen ].push_back( Node( destino , peso ) ); //consideremos grafo dirigido
    ady[ destino ].push_back( Node( origen , peso ) ); //grafo no dirigido
    }
    printf("Ingrese el ID de la ciudad inicial: ");
    scanf("%d" , &inicial );
    dijkstra( inicial );

}
