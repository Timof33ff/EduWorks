#include "Header.h"

DWORD WINAPI ThreadFunc1(LPVOID Param)
{
    RECT R;   int X1, Y1, X2, Y2, R1, G1, B1;
    HWND hwnd; HBRUSH Brush; HDC DC;
    hwnd = (HWND)Param;
    DC = GetDC(hwnd);
    GetWindowRect(hwnd, &R);
    const int MaxWidth = R.right - R.left;
    const int MaxHeight = R.bottom - R.top;
    while (true)
    {
        X1 = rand() % MaxWidth;   Y1 = rand() % MaxHeight;
        X2 = rand() % MaxWidth;   Y2 = rand() % MaxHeight;
        R1 = rand() & 255;  G1 = rand() & 255;   B1 = rand() & 255;
        Brush = CreateSolidBrush(RGB(R1, G1, B1));                              //���� �����
        SelectObject(DC, Brush); //�������� ������ � ��������� �������� ����������
        Rectangle(DC, X1, Y1, X2, Y2); // ������� �������������
        ReleaseDC(hwnd, DC);  // ����������� ��������� ����������
        DeleteObject(Brush); //������� ���������� �����
    }
}

DWORD WINAPI ThreadFunc2(LPVOID Param)
{
    RECT R;   int X1, Y1, X2, Y2, R1, G1, B1;
    HWND hwnd; HBRUSH Brush; HDC DC;
    hwnd = (HWND)Param;
    DC = GetDC(hwnd);
    GetWindowRect(hwnd, &R);
    const int MaxWidth = R.right - R.left;
    const int MaxHeight = R.bottom - R.top;
    while (true)
    {
        X1 = rand() % MaxWidth;   Y1 = rand() % MaxHeight;
        X2 = rand() % MaxWidth;   Y2 = rand() % MaxHeight;
        R1 = rand() & 255;  G1 = rand() & 255;   B1 = rand() & 255;
        Brush = CreateSolidBrush(RGB(R1, G1, B1));                              //���� �����
        SelectObject(DC, Brush); //�������� ������ � ��������� �������� ����������
        Rectangle(DC, X1, Y1, X2, Y2); // ������� �������������
        ReleaseDC(hwnd, DC);  // ����������� ��������� ����������
        DeleteObject(Brush); //������� ���������� �����
    }
}