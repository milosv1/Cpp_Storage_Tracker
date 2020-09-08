#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<ctime>
#include<chrono>

#define UNLEN 256
#define UNCLEN 256

//Prints current user.
void get_username()
{
    TCHAR user[UNLEN+1];
    DWORD user_len = UNLEN+1;

    GetUserName((TCHAR*)user, &user_len);
    std::cout << "User: " << user << "\n";

}

//Prints Machine Name.
void get_compname()
{
    TCHAR comp[UNCLEN+1];
    DWORD comp_len = UNCLEN+1;

    GetComputerName((TCHAR*)comp, &comp_len);
    std::cout << "Machine Name: " << comp << "\n";
}

//Prints: last accessed on: Day/time/Year.
void last_accesed()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    std::cout <<"last accessed on: " << dt;
}

//Prints version.
void get_version()
{
    DWORD dwVersion = 0;
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0;
    DWORD dwBuild = 0;
    
    dwVersion = GetVersion();
    
    
    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));

    
    if (dwVersion < 0x80000000)
        dwBuild = (DWORD)(HIWORD(dwVersion));

    //printf("Version is %d.%d %d\n",dwMajorVersion, dwMinorVersion, dwBuild);    
     std::cout << "Version: " << dwMajorVersion << "." << dwMinorVersion << " " << dwBuild ;
}

int main()
{   
    get_username();
    get_compname();
    last_accesed();
    get_version();
   
}