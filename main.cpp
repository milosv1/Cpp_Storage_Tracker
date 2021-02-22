#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<ctime>
#include<cstdlib>
#include<wininet.h>

#pragma comment(lib,"wininet.lib")
#define UNLEN 256
#define UNCLEN 256
#define DIV 1024
#define WIDTH 7

void greeting()
{  
   std::cout << "Welcome:" << std::endl;
   std::cout << "This is my C++ Storage Tracker -  " << std::endl;
   std::cout << "A project written in C++ based on my Py Storage Tracker." << std::endl;
   std::cout << "This project will be developed over time by Milos.Vuksanovic " << "\n\n";  
}

void get_username()
{
    TCHAR user[UNLEN+1];
    DWORD user_len = UNLEN+1;

    GetUserName((TCHAR*)user, &user_len);
    std::cout << "Last login: " << __TIME__ << std::endl;
    std::cout << "User: " << user << std::endl;
}


void get_compname()
{
    TCHAR comp[UNCLEN+1];
    DWORD comp_len = UNCLEN+1;

    GetComputerName((TCHAR*)comp, &comp_len);
    std::cout << "Machine Name: " << comp << std::endl;
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
     std::cout << "Version: " << dwMajorVersion << "." << dwMinorVersion << " " << dwBuild << std::endl;
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

void get_mem_info()
{
    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx (&statex);
    
    _tprintf(TEXT("Currently there is: %*ld percent of memory in use."),
            WIDTH, statex.dwMemoryLoad);

    std::cout << " " << std::endl;        
}

void check_connection()
{
    //experimental code -- starts:
    //char url[128];
    //strcat(url,"https://www.google.com");
  //  bool cConnection = InternetCheckConnection("https://www.google.com", FLAG_ICC_FORCE_CONNECTION, 0);

  //  if( cConnection )
  //  {
  //      bool conn_made = true;
  //      std::cout << "Connection:" + conn_made << std::endl;

  //  }
   // else
    //{
   //     bool no_conn = false;
  //      std::cout << "Connection made:" + no_conn << std::endl;
   // }
    //experimental code -- ends.

    //system("ping www.google.com -t 2 > nul") == 0
    //Temporary solution.
   if( system("ping -n 2 www.google.com") == 0)
   {   std::cout << " " << std::endl; 
       std::cout << "Working.." << std::endl;
       std::cout << "Connection made" << std::endl;
   }
   else
   {
       std::cout << "Not working..." << std::endl;
       std::cout << "Connection not made" << std::endl;
   }
}

int main()
{   
    greeting();
    get_username();
    get_compname();
    get_version();
    print_os();
    get_mem_info();
    check_connection();
}