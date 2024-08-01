#include "main.h"

ATOM winclass() // ����������� ������ ����
{
    WNDCLASSEX wc; // ��������� ��� ���������� � ������ ����
    memset(&wc, 0, sizeof(WNDCLASS)); // ������� ������ ��� ���������
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW; // ����� ������ ����
    wc.lpfnWndProc = (WNDPROC)WndProc; // ����� ������� �������
    wc.cbClsExtra = 0; // �������������� ������
    wc.cbWndExtra = 0; // �������������� ������
    wc.hInstance = hin; // ��������� ����������
    wc.hIcon = LoadIcon(hin, IDI_APPLICATION); // ����������� ��� ����
    wc.hCursor = LoadCursor(hin, IDC_ARROW); // ������ ���� ��� ����
    wc.hCursor = LoadCursor(hin, IDC_APPSTARTING); // ������ ���� ��� ����
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ����� ��� ����
    wc.lpszMenuName = NULL; // ������ ���� ����
    wc.lpszClassName = L"txtpad"; // ��� ������ ����
    wc.hIconSm = LoadCursor(hin, IDC_APPSTARTING); // ������
    return RegisterClassEx(&wc); // P���������� ������ ����.
}