#include <iostream>
#include <Windows.h>

HINSTANCE hin;
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
/*
ATOM winclass()
{
    WNDCLASSEX wc;
    wc.cbSize() = sizeof(WNDCLASSEX);
    wc.style() = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = (WNDPROC)WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hin;
    wc.hIcon = LoadIcon(hin, IDI_APPLICATION);
    wc.hCursor = LoadCursor(hin, IDC_ARROW);
    wc.hCursor = LoadCursor(hin, IDC_APPSTARTING);
        wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
        wc.lpszMenuName = NULL;
        wc.lpszClassName = "exmplewinclass";
        wc.hIconSm = LoadCursor(hin, IDC_APPSTARTING);
        return RegisterClassEx(&wc);
}*/
HWND makeExampleWin();
void MessageProcess();

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    setlocale(LC_CTYPE, "Russian");

    cout << hInstance << endl;
    cout << hPrevInstance << endl;
    cout << lpCmdLine << endl;
    cout << nCmdShow << endl;
    return 0;
}