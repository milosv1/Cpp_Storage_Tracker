#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<ctime>
#include<cstdlib>
#include<wininet.h>
#include<typeinfo>

#pragma comment(lib,"wininet.lib")

#define UNLEN 256
#define UNCLEN 256
#define DIV 1024
#define WIDTH 7

void greeting()
{  
   TCHAR user[UNLEN+1]; 
   DWORD user_len = UNLEN+1;
   GetUserName((TCHAR*)user, &user_len);
   std::cout << " " << std::endl;
   std::cout << "Welcome, " << user << "." << std::endl;
   std::cout << "This is my C++ Storage Tracker." << std::endl;
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
   
     std::cout << "Version: " << dwMajorVersion << "." << dwMinorVersion << " " << dwBuild << std::endl;
}

void print_os()
{
  #if __APPLE__
        printf("OS: Apple OS\n");
	#elif _WIN32
        printf("OS: Windows OS\n");
	#elif __LINUX__
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
   int pingTimes;
   int testNum = 0;
   std::cout << "How many times to ping?: " << std::endl;
   std::cin >> pingTimes;

   if(pingTimes > 0){
      while(testNum < pingTimes)
       { 
        if( system("ping www.google.com") == 0)
        {   
            std::cout << " " << std::endl; 
            std::cout << "Connection successful" << std::endl;
            ++testNum;
        }
        else
        {
            std::cout << "Connection unsuccessful" << std::endl;
        }
        std::cout << "Ping completed: " << testNum << std::endl;
      }
   }
   else if(pingTimes == 0)
   {
       std::cout << "No tests entered." << std::endl;
   }
   else if(pingTimes < 0)
   {
       std::cout << "pingTimes needs to be greater than 0." << std::endl;
   }

}

void get_bytes_sent_recieved()
{
    //gets sent and recieved bytes.
    //[TODO]: get sent and recieved bytes.
}

int main()
{   
    char ans;
    bool check_conn_ans;

    TCHAR user[UNLEN+1];
    DWORD user_len = UNLEN+1;
    GetUserName((TCHAR*)user, &user_len);

    do {
    std::cout << "Do you want to run a connection test? (y/n OR Y/N)" << std::endl;
    std::cin >> ans;   

    if(ans == 'y' || ans == 'Y'){   
        std::cout << "check_connection() ?: " << std::boolalpha << true << std::endl; 
        greeting();
        get_username();
        get_compname();
        get_version();
        print_os();
        get_mem_info();
        check_connection();        
    }
    else if(ans == 'n' || ans == 'N')
    {
        std::cout<< "check_connection() ?: " << std::boolalpha << false << std::endl;
        greeting();
        get_username();
        get_compname();
        get_version();
        print_os();
        get_mem_info();
        break;
    }
    else if(ans =='q'|| ans == 'Q' )
    {
        std::cout << "Exiting.." << std::endl;
        std::cout << "Thank you! " << user << std::endl;
        break;
    } 
    else if(isdigit(ans))
    {
        std::cout << ans << "cannot be int. (y/n OR Y/N)" << std::endl;
    }
    }
    while(ans != 'y' || ans !='Y' || ans != 'n' || ans !='N' || ans != 'q' || ans != 'Q');

    
    
    
}