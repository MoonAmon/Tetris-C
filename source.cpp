#include <iostream>
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <thread>
using namespace std;

wstring tetromino[7];
int numLargura = 12;
int numAltura = 18;
unsigned char *pCampo = nullptr;

int numLarguraTela = 80; // cmd x (colunas)
int numAlturaTela = 30;  // cmd y (pilhas)

int Rotate(int px, int py, int r)
{
    switch (r % 4)
    {
    case 0: return py * 4 + px;        // 0 graus
    case 1: return 12 + py - (px * 4); // 90 graus
    case 2: return 15 - (py * 4) - px; // 180 graus
    case 4: return 3 - py + (px * 4);  // 270 graus
    }
    return 0;
}

int main()
{
    // Criação das peças
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L"..X.");
    tetromino[1].append(L"....");

    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L".X..");
    tetromino[4].append(L"....");

    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L"....");

    tetromino[6].append(L".X..");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L"..X.");
    tetromino[6].append(L"....");

    pCampo = new unsigned char[numLargura * numAltura]; // Criação do campo de jogo
    for (int x = 0; x < numLargura; x++) // Limites do campo
    {
        for (int y = 0; y < numAltura; y++)
        {
            pCampo[y * numLargura + x] = (x == 0 || x == numLargura - 1 || y == numAltura - 1) ? 9 : 0;
        }
    }

    wchar_t*tela = new wchar_t[numLarguraTela * numAlturaTela];
    for (int i = 0; i < numAlturaTela * numLarguraTela; i++) tela[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD PixelsEscrito = 0;

    bool bGameOver = false;

    while (!bGameOver)
    {
        // criação do campo
        for (int x = 0; x < numLargura; x++)
        {
            for (int y = 0; y < numAltura; y++)
            {
                tela[(y + 2) * numLargura + (x + 2)] = L" ABCDEFG=#"[pCampo[y * numLargura + x]];
            }
            
        }
        

        // pixels da tela
        WriteConsoleOutputCharacter(hConsole, tela, numLarguraTela * numAlturaTela, { 0,0 }, &PixelsEscrito);
    }
    


    return 0;
    

}