// Project1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Project1.h"
#include "stdio.h"  
#include "io.h"
#include <synchapi.h>
#include <time.h>


#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJECT1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...

            int T = 300; 

            HBITMAP bmw;
            HDC memdc;
            
            int nMyTime =0;
            while (nMyTime < 5) {
                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100bgr_.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);            //фон + фаза 0
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 0, 0, 2000, 2000, memdc, 0, 0, SRCCOPY); //SRCCOPY

                Sleep(T);

                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a0_inv.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);         //удаление - инвертированная фаза 0
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 67, 100, memdc, 0, 0, SRCINVERT);


                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);             //фаза 1
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCCOPY);

                Sleep(T);

                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a1_inv.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);         //удаление - инвертированная фаза 1
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCINVERT);


                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);             //фаза 2
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCCOPY);

                Sleep(T);

                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a2_inv.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);         //удаление - инвертированная фаза 2
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCINVERT);


                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);             //фаза 3
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCCOPY);

                Sleep(T);

                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a3_inv.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);         //удаление - инвертированная фаза 3
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCINVERT);

                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);             //фаза 4
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCCOPY);

                Sleep(T);

                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a4_inv.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);         //удаление - инвертированная фаза 4
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCINVERT);


                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);             //фаза 3 (вниз)
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCCOPY);

                Sleep(T);

                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a3_inv.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);         //удаление - инвертированная фаза 3
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCINVERT);
                nMyTime++;


                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);             //фаза 2 (вниз)
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCCOPY);

                Sleep(T);

                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a2_inv.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);         //удаление - инвертированная фаза 2
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCINVERT);


                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);             //фаза 1 (вниз)
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCCOPY);

                Sleep(T);

                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a1_inv.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);         //удаление - инвертированная фаза 1
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCINVERT);


                bmw = (HBITMAP)LoadImage(NULL, L"D:\\100a0.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);            //фаза 0
                memdc = CreateCompatibleDC(hdc);
                SelectObject(memdc, bmw);
                BitBlt(hdc, 538, 41, 169, 251, memdc, 0, 0, SRCCOPY); //SRCCOPY



                nMyTime++;


            }
            



            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
