#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <sstream>
#include "Windows.h"
#include "winbase.h"
#include <vector>
#include <iterator>
#include <heapapi.h>
#include <QApplication>
#include <QMainWindow>

using namespace std;

static struct {
    UINT type;        // возвращаемый код из GetDriveType
    LPCSTR name;      // ascii имя
} DriveTypeFlags[] = {
   { DRIVE_UNKNOWN,     "Unknown" },
   { DRIVE_NO_ROOT_DIR, "Invalid path" },
   { DRIVE_REMOVABLE,   "Removable" },
   { DRIVE_FIXED,       "Fixed" },
   { DRIVE_REMOTE,      "Network drive" },
   { DRIVE_CDROM,       "CD-ROM" },
   { DRIVE_RAMDISK,     "RAM disk" },
   { 0, NULL},
};

LPCSTR catchDriveType( DWORD type);

string DiscsInfo();

#endif // FUNCS_H
