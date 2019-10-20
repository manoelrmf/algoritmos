#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/* Grupo
* Nome: Manoel Ribeiro 
* Matricula: 2019101035
*/

using namespace std;

int main() {
    int matriz[3][4], menor, lmenor, cmenor, ntroca_menor,
    maior, lmaior, cmaior, ntroca_maior;

    for(int l = 0; l < 3; l++){
        for(int c = 0; c < 4; c++){
            cout<<"Cordenada["<<l<<"]["<<c<<"] - Digite um numero : "; cin>>matriz[l][c];
        }
    }

    maior = matriz[0][0];
    lmaior = 0;
    cmaior = 0;
    ntroca_maior = 0;

    menor = matriz[0][0];
    lmenor = 0;
    cmenor = 0;
    ntroca_menor = 0;

    for(int l = 0; l < 3; l++){
        for(int c = 0; c < 4; c++){
            if(matriz[l][c] > maior){
                maior = matriz[l][c];
                lmaior = l;
                cmaior = c;
                ntroca_maior++;
            }else if(matriz[l][c] < menor){
                menor = matriz[l][c];
                lmenor = l;
                cmenor = c;
                ntroca_menor++;
            }
        }
    }

    cout<<"----------------------"<<endl;
    cout<<"Maior: "<<maior<<endl;
    cout<<"Linha do Maior: "<<lmaior<<endl;
    cout<<"Coluna do Maior: "<<cmaior<<endl;
    cout<<"Numero de Troca: "<<ntroca_maior<<endl;
    cout<<"----------------------"<<endl;
    cout<<"Menor: "<<menor<<endl;
    cout<<"Linha do Menor: "<<lmenor<<endl;
    cout<<"Coluna do Menor: "<<cmenor<<endl;
    cout<<"Numero de Troca: "<<ntroca_menor<<endl;
    
    return 0;
}
