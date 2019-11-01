#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

char nome[50][50], sexo[15][50], nome_arq[50], nome_arq_carregado[50];
int idade[50], matricula[50], contadorAlunos = 0;
float notas[4][50];

FILE *arq;

void exibeAlunoPorIndice(int i){
	cout<<"Matricula: "<<matricula[i]<<endl;
	cout<<"Nome: "<<nome[i]<<endl;
	cout<<"Idade: "<<idade[i]<<endl;
	cout<<"Sexo: "<<sexo[i]<<endl;
	cout<<"AV1: "<<notas[0][i]<<endl;
	cout<<"AV2: "<<notas[1][i]<<endl;
	cout<<"AV3: "<<notas[2][i]<<endl;
	cout<<"Meida: "<<notas[3][i]<<endl;
}

int calcMediaUni(int a, int b, int c){
	if(a < b && a < c){
		return (b + c)/2;
	} else if(b < a && b < c){
		return (a + c)/2;
	} else{
		return (a + b)/2;
	}
							
}

void retornaAlunosPorFaixaDeNotaMaior(int nota){
	bool encontrado = false; 
	system("cls");
	for(int i = 0; i < contadorAlunos; i++){
		if(notas[3][i] > nota){
			encontrado = true;
			cout<<"----------------------------"<<endl;
			exibeAlunoPorIndice(i);
			cout<<"----------------------------"<<endl;
		}
	}
	if(!encontrado)
		cout<<"NENHUM ALUNO FOI ENCONTRADO."<<endl;
}

void retornaAlunosPorFaixaDeNotaMenor(int nota){
	bool encontrado = false; 
	system("cls");
	for(int i = 0; i < contadorAlunos; i++){
		if(notas[3][i] < nota){
			encontrado = true;
			cout<<"----------------------------"<<endl;
			exibeAlunoPorIndice(i);
			cout<<"----------------------------"<<endl;
		}
	}
	if(!encontrado)
		cout<<"NENHUM ALUNO FOI ENCONTRADO."<<endl;
}

bool verificaPermissaoParaAddAluno(){
	return (contadorAlunos == 50) ? false : true;
}

bool verificaAlunoExistente(int mat){
	for(int i = 0; i < contadorAlunos; i++){
		if(matricula[i] == mat){
			return true;
		}		
	}
	return false;
}

void addAluno(){
	system("cls");
	cout<<"UNICARIOCA - BANCO DE DADOS"<<endl;
	cout<<"ADICIONAR USUARIO"<<endl;
	if(verificaPermissaoParaAddAluno()){
		cout<<"Matricula: "; cin>>matricula[contadorAlunos];
		if(verificaAlunoExistente(matricula[contadorAlunos])){
		cout<<"ALUNO JA CADASTRADO"<<endl;	
		}else{
			cout<<"Nome: "; cin>>nome[contadorAlunos];
			cout<<"Idade: "; cin>>idade[contadorAlunos];
			cout<<"Sexo (M/F): "; cin>>sexo[contadorAlunos];
			cout<<"AV1: "; cin>>notas[0][contadorAlunos];
			cout<<"AV2: "; cin>>notas[1][contadorAlunos];
			cout<<"AV3: "; cin>>notas[2][contadorAlunos];
			notas[3][contadorAlunos] = calcMediaUni(notas[0][contadorAlunos],
													notas[1][contadorAlunos],
													notas[2][contadorAlunos]);
			contadorAlunos++;
		}
	}else{
		cout<<"NNUMERO LIMITE DE CADASTROS ALCANCADO."<<endl;
	}
	system("pause");
}

void persisteAlunosNoArquivoExterno(){
	for(int i = 0; i < contadorAlunos; i++){
		fprintf(arq,"Matricula = %d\n", matricula[i]);
		fprintf(arq,"Nome = %s\n", nome[i]);
		fprintf(arq,"Idade = %d\n", idade[i]);
		fprintf(arq,"Sexo = %s\n", sexo[i]);
		fprintf(arq,"AV1 = %0.1f\n", notas[0][i]);
		fprintf(arq,"AV2 = %0.1f\n", notas[1][i]);
		fprintf(arq,"AV3 = %0.1f\n", notas[2][i]);
		fprintf(arq,"Media = %0.1f\n", notas[3][i]);
		fprintf(arq,"-------\n");

		if(i+1 == contadorAlunos){
			fprintf(arq,"Total = %d", i+1);
		}
	}
}

void salvarAlunos(){
	system("cls");
	if(contadorAlunos != 0){
		cout<<endl<<"NOME DO ARQUIVO: "; cin>>nome_arq;
		strcat(nome_arq,".txt");
		arq = fopen(nome_arq,"w");
		if (arq == NULL)
			cout<<"ERRO NO ARQUIVO"<<endl;
		else{
			persisteAlunosNoArquivoExterno();
			cout<<"ALUNOS SALVOS NO ARQUIVO: "<<nome_arq<<endl;
		}
		fclose(arq);
	}else{
		cout<<"NENHUM ALUNO ENCONTRADO."<<endl;
	}
	system("pause");
}

void exibeAprovados(){
	int opc;
	system("cls");
	cout<<"UNICARIOCA - BANCO DE DADOS"<<endl;
	cout<<"USUARIOS APROVADOS"<<endl;
	cout<<"[1] MEDIA >=7"<<endl;
	cout<<"[2] MEDIA >=9"<<endl;
	cout<<"[0] VOLTAR"<<endl;
	cout<<"OPCAO: "; cin>>opc;
	switch (opc){
		case 1: retornaAlunosPorFaixaDeNotaMaior(6); break;
		case 2: retornaAlunosPorFaixaDeNotaMaior(8); break;
	}
}

void exibeReprovados(){
	int opc;
	system("cls");
	cout<<"UNICARIOCA - BANCO DE DADOS"<<endl;
	cout<<"USUARIOS REPROVADOS"<<endl;
	cout<<"[1] MEDIA < 7"<<endl;
	cout<<"[2] MEDIA < 5"<<endl;
	cout<<"[0] VOLTAR"<<endl;
	cout<<"OPCAO: "; cin>>opc;
	switch (opc){
		case 1: retornaAlunosPorFaixaDeNotaMenor(7); break;
		case 2: retornaAlunosPorFaixaDeNotaMenor(5); break;
	}
}

void exibeTodosAlunos(){
	system("cls");
	for(int i = 0; i < contadorAlunos; i++){
		cout<<"----------------------------"<<endl;
		exibeAlunoPorIndice(i);
		cout<<"----------------------------"<<endl;
	}
}

void exibirAluno(){
	int opc;
	system("cls");
	cout<<"UNICARIOCA - BANCO DE DADOS"<<endl;
	cout<<"EXIBIR USUARIOS"<<endl;
	cout<<"[1] APROVADOS"<<endl;
	cout<<"[2] REPROVADOS"<<endl;
	cout<<"[3] TODOS"<<endl;
	cout<<"[0] VOLTAR"<<endl;
	cout<<"OPCAO: "; cin>>opc;
	switch (opc){
		case 1: exibeAprovados(); break;
		case 2: exibeReprovados(); break;
		case 3: exibeTodosAlunos(); break;
	}
	system("pause");
}

int retornaPosicaoDoAlunoPorMatricula(int mat_pesq){
	for(int i = 0; i < contadorAlunos; i++){
		if(matricula[i] == mat_pesq){
			return i;
		}
	}
	return 51;
}

void pesquisarAluno(){
	int mat_pesquisa;
	system("cls");
	cout<<"UNICARIOCA - BANCO DE DADOS"<<endl;
	cout<<"BUSCAR USUARIO"<<endl;
	cout<<"MATRICULA PARA PESQUISA: "; cin>>mat_pesquisa;
	int i = retornaPosicaoDoAlunoPorMatricula(mat_pesquisa);
	system("cls");
	if(i != 51){
		exibeAlunoPorIndice(i);
	}else{
		system("cls");
		int decisao;
		cout<<"ALUNO NAO ENCONTRADO."<<endl;
		cout<<"DESEJA ADICIONA-LO? (1-SIM/2-NAO): "; cin>>decisao;
		if(decisao == 1)
			addAluno();	
	}
}

void carregarAlunosArqExterno(){
	system("cls");
	int total;
	cout<<"NOME DO ARQUIVO: "; cin>>nome_arq;
	strcat(nome_arq,".txt");
	arq = fopen(nome_arq,"r");
	if (arq == NULL){
		cout<<"ARQUIVO NAO EXISTE"<<endl;
	} else{
		fseek(arq, -1,2);
		fscanf(arq,"%d", &total);
		fseek(arq, 0,0);

		for(int i = contadorAlunos; i < total; i++){
			fseek(arq, 12,1);
			fscanf(arq,"%d \n", &matricula[i]);
			fseek(arq, 7,1);
			fscanf(arq,"%s \n", nome[i]);
			fseek(arq, 8,1);
			fscanf(arq,"%d \n", &idade[i]);
			fseek(arq, 7,1);
			fscanf(arq,"%s \n", sexo[i]);
			fseek(arq, 6,1);
			fscanf(arq,"%f \n", &notas[0][i]);
			fseek(arq, 6,1);
			fscanf(arq,"%f \n", &notas[1][i]);
			fseek(arq, 6,1);
			fscanf(arq,"%f \n", &notas[2][i]);
			fseek(arq, 8,1);
			fscanf(arq,"%f \n", &notas[3][i]);
			fseek(arq, 8,1);
			contadorAlunos++;
		}
		cout<<"ALUNOS CARREGADOS COM SUCESSO."<<endl;
	}
	fclose(arq);
	system("pause");
}

void exibeSalvarCarregar(){
	system("cls");
	int opc;
	cout<<"UNICARIOCA - BANCO DE DADOS"<<endl;
	cout<<"SALVAR/CARREGAR ARQUIVO"<<endl;
	cout<<"[1] SALVAR"<<endl;
	cout<<"[2] CARREGAR"<<endl;
	cout<<"[0] VOLTAR"<<endl;
	cout<<"OPCAO: "; cin>>opc;
	switch (opc){
		case 1: salvarAlunos(); break;
		case 2: carregarAlunosArqExterno(); break;
	}
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
			case 4: exibeSalvarCarregar(); break;
		}
	}while(op!=0);
}
