#include <fstream>//Para opera��o do arquivo
#include <iostream>//Para entrada e sa�da
#include <locale>//Biblioteca de portugu�s

using namespace std;

int main()
{
    setlocale(LC_ALL,"");
    ofstream myFile; //Objeto para leitura
    ifstream file; //Objeto para escrever
    char ch[30];
    char text;

    cout<<"Digite o texto"<<endl;
    cin.getline(ch,30);  //Fun��o Getline.

    //Abrindo arquivo para escrita
    myFile.open("ArquivoBeg.txt", ios::out);
    if(myFile) //Verificador de erros:
    {
        myFile<<ch;
        cout<<"Sucesso no armazenamento:"<<endl;
    }
    else
        cout<<"Erro ao abrir o arquivo!"<<endl;
    myFile.close(); //Fechar arquivo

    //Abrindo arquivo para leitura
    file.open("ArquivoBeg.txt", ios::in);
    if(file)//Verificar erro
    {
        //Do fim do arquivo, mova 11 bytes pra tr�s
        file.seekg(-11, ios::end);
        cout << endl;

        cout<<"Os ultimos 11 bytes s�o: ";
        while(!file.eof()) // Leia os dados at� o final do arquivo:
        {
            file.get(text); //Lendo
            cout << text; //Escrevendo
        }
    }

    else
        cout<<"Erro ao abrir o arquivo!"<<endl;
    file.close(); //Arquivo fechado

    return 0;
}

