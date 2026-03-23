#pragma once

#include "resource.h"

DWORD id1, id2;
HANDLE thread1, thread2;

DWORD WINAPI ThreadFunc1(LPVOID Param);
DWORD WINAPI ThreadFunc2(LPVOID Param);
