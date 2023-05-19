#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char ProgName[] = "Лабораторна робота 3";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpszCmdLine, int nCmdShow)
{
    WNDCLASS w;


    w.lpszClassName = ProgName;
    w.hInstance = hInstance;
    w.lpfnWndProc = WndProc;
    w.hCursor = LoadCursor(NULL, IDC_ARROW);
    w.hIcon = 0;
    w.lpszMenuName = 0;
    w.hbrBackground = WHITE_BRUSH;
    w.style = CS_HREDRAW | CS_VREDRAW;
    w.cbClsExtra = 0;
    w.cbWndExtra = 0;
    if (!RegisterClass(&w))
    {
        return 0;
    }
    HWND hWnd;
    MSG lpMsg;
    hWnd = CreateWindow(ProgName, //Ім'я програми
        L"Лабораторна робота 3. Виконав М.І.Волковський", //Заголовок
        WS_OVERLAPPEDWINDOW, //Стиль вікна - комплексний
        100, //положення верхнього кута вікна на екрані по х
        100, // положення верхнього кута вікна на екрані по y
        500, //ширина вікна
        460, //висота вікна
        (HWND)NULL, // ідентифікатор породжуючого вікна
        (HMENU)NULL, //ідентифікатор меню (немає)
        (HINSTANCE)hInstance, //ідентифікатор екземпляра вікна
        (HINSTANCE)NULL); // додаткові параметри відсутні
    ShowWindow(hWnd, nCmdShow);
    int b;
    while ((b = GetMessage(&lpMsg, hWnd, 0, 0)) != 0) {
        if (b == -1) {
            return lpMsg.wParam;
        }
        else {
            TranslateMessage(&lpMsg);
            DispatchMessage(&lpMsg);
        }
    }
    return(lpMsg.wParam);
}

void rad_arrow(HDC hdc, float fi, int px, int py)
{

    int lx, ly, rx, ry;
    lx = px + 15 * cos(fi + 0.3);
    rx = px + 15 * cos(fi - 0.3);
    ly = py + 15 * sin(fi + 0.3);
    ry = py + 15 * sin(fi - 0.3);
    MoveToEx(hdc, lx, ly, NULL);
    LineTo(hdc, px, py);
    LineTo(hdc, rx, ry);
}

void arrow(HDC hdc, float fi, int px, int py)
{
    fi = 3.1416 * (180.0 - fi) / 180.0;
    int lx, ly, rx, ry;
    lx = px + 15 * cos(fi + 0.3);
    rx = px + 15 * cos(fi - 0.3);
    ly = py + 15 * sin(fi + 0.3);
    ry = py + 15 * sin(fi - 0.3);
    MoveToEx(hdc, lx, ly, NULL);
    LineTo(hdc, px, py);
    LineTo(hdc, rx, ry);
}


float setFi(int sx, int sy, int px, int py)
{
    //довжина прилеглого катета
    float adjacent_leg = px - sx;

    // відстань між точками(гіпотенуза)
    float hypotenuse = sqrt((px - sx) * (px - sx) + (py - sy) * (py - sy));

    //по формулі дізнаємось фі через acos()
    float fi = acos(adjacent_leg / hypotenuse);

    // коригування кутів
    if (sy >= py)
    {
        fi = 3.1416 - fi;
    }
    else
    {
        fi = 3.1416 + fi;
    }
    return fi;
}

float calculate_Xoffset(float fi, int radius)
{
    return -(cos(fi) * radius);
}
float calculate_Yoffset(float fi, int radius)
{
    return sin(fi) * radius;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
    WPARAM wParam, LPARAM lParam)
{
    HDC hdc; // контекст
    PAINTSTRUCT ps;
    switch (messg) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        char* nn[10] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", L"10"};
        int nx[10] = { 125,145,200,275,330, 350, 330, 275, 200, 145};
        int ny[10] = { 200,130,90 ,90 ,130, 200, 270, 310, 310, 270};
        int dx = 16, dy = 16, dtx = 5;

        float ugu;
        float fi, x_offset, y_offset;
        srand(time(NULL));
        bool adjacency_matrix[10][10];
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                adjacency_matrix[i][j] = (((1.0 - 0 * 0.02 - 1 * 0.005 - 0.25) * 
                    (float)rand() / (float)RAND_MAX * 2) >= 1.0) ? true : false;
                if (adjacency_matrix[i][j])
                {
                    if (i != j)
                    {
                        MoveToEx(hdc, nx[i], ny[i], NULL);
                        LineTo(hdc, nx[j], ny[j]);
                        fi = setFi(nx[i], ny[i], nx[j], ny[j]);
                        x_offset = calculate_Xoffset(fi, dx);
                        y_offset = calculate_Yoffset(fi, dy);
                        rad_arrow(hdc, fi, nx[j] - x_offset, ny[j] + y_offset);
                    }
                    else
                    {
                        Arc(hdc, nx[i] - 40, ny[i] - 20, nx[i], ny[i] + 20, nx[i], ny[i], nx[i], ny[i]);
                        arrow(hdc, -25.0, nx[j] - dx * 0.4, ny[j] - dy * 0.9);
                    }
                }
                /*if (i == j)
                {
                    Arc(hdc, nx[i]-40, ny[i]-20, nx[i], ny[i]+20, nx[i], ny[i], nx[i], ny[i]);
                    arrow(hdc, -25.0 , nx[j] - dx * 0.4, ny[j] - dy * 0.9);
                }*/
            }
        }
        HPEN BPen = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
        HPEN KPen = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));
        SelectObject(hdc, KPen);
        SelectObject(hdc, BPen);
        for (int i = 0; i <= 9; i++) {
            Ellipse(hdc, nx[i] - dx, ny[i] - dy, nx[i] + dx, ny[i] + dy);
            TextOut(hdc, nx[i] - dtx, ny[i] - dy / 2, nn[i], 2);
        }
        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return(DefWindowProc(hWnd, messg, wParam, lParam));
    }
}
