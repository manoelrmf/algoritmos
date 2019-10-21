#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

char nome[50], sexo[15];
int idade, matricula;
float nota1, nota2, nota3, media;

char nome_arq[50];
FILE *arq;

int calcMediaUni(int a, int b, int c){
  	int n1, n2;
	 if(a > b && c < b){
	 	n1 = a; n2 = b;
	 }else if(b > a && a < c){
	 	n1 = b; n2 = c;
	 }else if(c > a && b < c){
	 	n1 = c; n2 = b; 
	 }else if(c > b && a < c){
	 	n1 = c; n2 = a;
	 }
	return (n1 + n2)/2; 
}

void addAluno(){
	system("cls");
	cout<<"UNICARIOCA - BANCO DE DADOS"<<endl;
	cout<<"ADICIONAR USUARIO"<<endl;
	cout<<"Matricula: "; cin>>matricula;
	cout<<"Nome: "; cin>>nome;
	cout<<"Idade: "; cin>>idade;
	cout<<"Sexo: "; cin>>sexo;
	cout<<"Nota 1: "; cin>>nota1;
	cout<<"Nota 2: "; cin>>nota2;
	cout<<"Nota 3: "; cin>>nota3;
	media = calcMediaUni(nota1, nota2, nota3);
	
	cout<<endl<<"Nome do arquivo: "; cin>>nome_arq;
	strcat(nome_arq,".txt");
	arq = fopen(nome_arq,"w");
	if (arq == NULL)
		cout<<"ERRO NO ARQUIVO"<<endl;
	else{
		fprintf(arq,"Matricula = %d\n", &matricula);
		fprintf(arq,"Nome = %s\n", nome);
		fprintf(arq,"Idade = %d\n", &idade);
		fprintf(arq,"Sexo = %s\n", sexo);
		fprintf(arq,"Nota 1 = %0.1f\n", nota1);
		fprintf(arq,"Nota 2 = %0.1f\n", nota2);
		fprintf(arq,"Nota 3 = %0.1f\n", nota3);
		fprintf(arq,"Media = %0.1f\n", media);	
	}
	fclose(arq);
	system("pause");
}

void exibirAluno(){
	/*system("cls");
	cout<<"UNICARIOCA - BANCO DE DADOS"<<endl;
	cout<<"EXIBIR USUARIO"<<endl;
	cout<<"Nome do arquivo: "; cin>>nome_arq;
	strcat(nome_arq,".txt");
	arq = fopen(nome_arq,"r");
	if (arq == NULL)
		cout<<"ARQUIVO NAO EXISTE"<<endl;
	else{
		fseek(arq,6,0);
		fscanf(arq,"%d\n",&matricula);
		fseek(arq,7,1);
		fscanf(arq,"%s\n",nome);
		fseek(arq,8,1);
		fscanf(arq,"%d\n",&idade);
		fseek(arq,9,1);
		fscanf(arq,"%s\n",sexo);
		cout<<"CPF: "<<cpf<<endl;
		cout<<"Nome: "<<nome<<endl;
		cout<<"Idade: "<<idade<<endl;
		cout<<"E-mail: "<<email<<endl;
	}
	fclose(arq);
	system("pause");*/
}

void pesquisarAluno(){
	int mat_pesquisa;
	system("cls");
	cout<<"UNICARIOCA - BANCO DE DADOS"<<endl;
	cout<<"BUSCAR USUARIO"<<endl;
	cout<<"Matricula para pesquisa: "; cin>>mat_pesquisa;
	
	cout<<"Nome do arquivo: "; cin>>nome_arq;
	strcat(nome_arq,".txt");
	arq = fopen(nome_arq,"r");
	if (arq == NULL)
		cout<<"ARQUIVO NAO EXISTE"<<endl;
	else{
		fseek(arq,12,0);
		fscanf(arq,"%d\n", &matricula);
		fseek(arq,7,1);
		fscanf(arq,"%s\n", nome);
		fseek(arq,8,1);
		fscanf(arq,"%d\n", &idade);
		fseek(arq,7,1);
		fscanf(arq,"%s\n", sexo);
		fseek(arq,9,1);
		fscanf(arq,"%f\n", nota1);
		fseek(arq,9,1);
		fscanf(arq,"%f\n", nota2);
		fseek(arq,9,1);
		fscanf(arq,"%f\n", nota3);
		fseek(arq,8,1);
		fscanf(arq,"%f\n", media);
		if (mat_pesquisa == matricula){
			cout<<"Matricula: "<<matricula<<endl;
			cout<<"Nome: "<<nome<<endl;
			cout<<"Idade: "<<idade<<endl;
			cout<<"Sexo: "<<sexo<<endl;
			cout<<"Nota 1: "<<nota1<<endl;
			cout<<"Nota 2: "<<nota2<<endl;
			cout<<"Nota 3: "<<nota3<<endl;
			cout<<"Media: "<<media<<endl;
		} else{
			cout<<"MATRICULA NAO ENCONTRADO"<<endl;
		}
	}
		fclose(arq);
		system("pause");
}

main(){
	int op;
	do{
		system("cls");
		cout<<"UNICARIOCA - BANCO DE DADOS"<<endl;
		cout<<"[1] ADICIONAR"<<endl;
		cout<<"[2] PESQUISAR"<<endl;
		cout<<"[3] EXIBIR"<<endl;
		cout<<"[4] SALVAR/CARREGAR"<<endl;
		cout<<"[0] SAIR"<<endl;
		cout<<"OPCAO: "; cin>>op;
		switch (op){
			case 1: addAluno(); break;
			case 2: pesquisarAluno(); break;
			case 3: exibirAluno(); break;
		}
	}while(op!=0);
}
