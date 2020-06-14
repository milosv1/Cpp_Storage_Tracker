#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
//the objective of this project is to recreate the Python Storage Tracker created very recently.
//we need to translate it to C++

#define UNLEN 256

void get_username()
{
    TCHAR user[UNLEN+1];
    DWORD user_len = UNLEN+1;

    GetUserName((TCHAR*)user, &user_len);
    std::cout<< user << "\n";

}

void last_accesed()
{
    SYSTEMTIME lt; //Get local time

    GetSystemTime(&lt);
    //show last accessed time Hr:Min:sec
    std::cout << "Last Accessed: " << lt.wHour << ":" << lt.wMinute << ":" << lt.wSecond <<"\n";
}

void get_version()
{
    DWORD dwVersion = 0;
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0;
    DWORD dwBuild = 0;
    
    dwVersion = GetVersion();
    
    //get windows version
    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));

    //get build number
    if (dwVersion < 0x80000000)
        dwBuild = (DWORD)(HIWORD(dwVersion));

    //printf("Version is %d.%d %d\n",dwMajorVersion, dwMinorVersion, dwBuild);    
     std::cout << "Version: " << dwMajorVersion << "." << dwMinorVersion << " " << dwBuild ;
}

int main()
{   
    get_username();
    last_accesed();
    get_version();

}