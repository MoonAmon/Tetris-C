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

bool DoesPieceFit(int nTetromino, int nRotate, int nPosX, int nPosY)
{
    for (int px = 0; px < 4; px++)
    {
        for (int py = 0; py < 4; py++)
        {
            // indice da peça
            int pi = Rotate(px, py, nRotate);

            // indice do campo
            int fi = (nPosY + py) * numLargura + (nPosX + px);

            if (nPosX + px >= 0 && nPosX + px < numLargura)
            {
                if (nPosY + py >= 0 && nPosY + py < numAltura)
                {
                    if (tetromino[nTetromino][pi] == L'X' && pCampo[fi] != 0)
                    {
                        return 0; // colisão da peça
                    }
                    
                }
                
            }
            
        }
        
    }
    



    return true;
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

    // game logic stuff
    bool bGameOver = false;

    int nCurrentPiece = 0;
    int nCurrentRotate = 0;
    int nCurrentX = numLargura / 2;
    int nCurrentY = 0;

    while (!bGameOver)
    {
        // game timing

        // input

        // game logic

        // render output


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