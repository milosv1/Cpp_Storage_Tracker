#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<ctime>
#include<cstdlib>

#define UNLEN 256
#define UNCLEN 256
#define DIV 1024
#define WIDTH 7

void greeting()
{
   std::cout << "Welcome:" << "\n";
   std::cout << "This is my C++ Storage Tracker -  " << "\n";
   std::cout << "A project written in C++ based on my Py Storage Tracker." << "\n";
   std::cout << "This project will be developed over time by Milos.Vuksanovic " << "\n\n";  
}

void get_username()
{
    TCHAR user[UNLEN+1];
    DWORD user_len = UNLEN+1;

    GetUserName((TCHAR*)user, &user_len);
    std::cout << "Last login: " << __TIME__ << "\n";
    std::cout << "User: " << user << "\n";

}

void get_compname()
{
    TCHAR comp[UNCLEN+1];
    DWORD comp_len = UNCLEN+1;

    GetComputerName((TCHAR*)comp, &comp_len);
    std::cout << "Machine Name: " << comp << "\n";
}


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
     std::cout << "Version: " << dwMajorVersion << "." << dwMinorVersion << " " << dwBuild << "\n";
}

void print_os()
{
  #if __APPLE__
	    // apple specific code
        printf("OS: Apple OS\n");
	#elif _WIN32
	    // windows specific code
        printf("OS: Windows OS\n");
	#elif __LINUX__
	    // linux specific code
        printf("OS: Linux OS\n");
	#elif BSD
        printf("OS: BSD based OS\n");
	#else
        printf("OS: Not a Windows OS");
	#endif
}

void get_mem_usage()
{
    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx (&statex);
    //std::statex.dwlength = fmt::format("RAM: {}", sizeof(statex));
    //printf("RAM: %d", sizeof(statex));

    //test run:
    _tprintf(TEXT("Currently there is: %*ld percent of memory in use."),
            WIDTH, statex.dwMemoryLoad);


}

int main()
{   
    greeting();
    get_username();
    get_compname();
    get_version();
    print_os();
    get_mem_usage();
}