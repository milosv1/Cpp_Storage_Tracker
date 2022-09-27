#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<tchar.h>
#include<ctime>
#include<cstdlib>
#include<wininet.h>
#include<typeinfo>
#include<iphlpapi.h>
#include<ctime>

#pragma comment(lib,"wininet.lib")


#define UNLEN 256
#define UNCLEN 256
#define DIV 1024
#define WIDTH 7

//-----------------------------------------------------------------------------
void get_username()
{ 
    std:: cout << "-------------------------" << std::endl;
    TCHAR user[UNLEN+1];
    DWORD user_len = UNLEN+1;
    GetUserName((TCHAR*)user, &user_len);
    std::cout << "User: " << user << std::endl;
    std::cout << "Last login: " << __TIME__ << std::endl;
    std::cout << "--------------------------" << std::endl;
}
//-----------------------------------------------------------------------------
void get_compname()
{
    TCHAR comp[UNCLEN+1];
    DWORD comp_len = UNCLEN+1;

    GetComputerName((TCHAR*)comp, &comp_len);
    std::cout << "Machine Name: " << comp << std::endl;
}
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
void print_os()
{
  #if __APPLE__
        printf("Operating System: Apple OS \n");
	#elif _WIN32
        printf("Operating System: Windows OS \n");
	#elif __LINUX__
        printf("Operating System: Linux OS \n");
	#elif BSD
        printf("Operating System: BSD based OS \n");
	//#else
        //printf("OS: Not a Windows OS");
	#endif
}
//-----------------------------------------------------------------------------
void get_mem_info()
{
    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx (&statex);
                                            //percent
   // _tprintf(TEXT("Currently there is: %*ld percent of memory in use."),
   //         WIDTH, statex.dwMemoryLoad);
    std::printf("Memory (in use): %d percent",statex.dwMemoryLoad);
    std::cout << " " << std::endl;        
}
//-----------------------------------------------------------------------------
void check_connection()
{

  int maxPingTimes = 10; 
  int pingTimes; // How many times to check connection
  int testNum = 0; // amount of tests run
   

  std::cout << "How many times to ping?: " << std::endl;
  std::cin >> pingTimes;  

   if(pingTimes == 1 || pingTimes < maxPingTimes)
   {
       std::printf("Running %d tests, please be patient...", pingTimes); 
       while(testNum < pingTimes)
       {
           while(testNum < pingTimes)
       { 
        if( system("ping www.google.com") == 0)
        {   
            std::cout << " " << std::endl; 
            std::cout << "Connection successful!" << std::endl;
            std::cout << "--------------------------------------" << std::endl;
            std::printf("Currently completing: %d, currently at:", pingTimes);
            ++testNum;
        }
        else
        {
            std::cout << "Connection unsuccessful" << std::endl;
        }
        std::cout << "Ping completed: " << testNum << std::endl;
      }
       }
    }
    else if(pingTimes > maxPingTimes)
    {
        std::cout << "pingTimes must be less than 10" << std::endl;
    }
    else if(pingTimes == 0)
    {
        std::cout << "pingTimes cannot be set to 0" << std::endl;
    }
   
}
//-----------------------------------------------------------------------------
void get_ram()
{
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	std::cout << "Physical RAM: " << (float)statex.ullTotalPhys/(1024*1024*1024) << std::endl;
}
//-----------------------------------------------------------------------------
int main()
{   
    char ans;
    bool check_conn_ans;

    TCHAR user[UNLEN+1];
    DWORD user_len = UNLEN+1;
    GetUserName((TCHAR*)user, &user_len);

    do {
    std::cout << "Do you want to run a connection test? (y/n)" << std::endl;
    std::cin >> ans;  
    std::cout << "\n";

    if(ans == 'y' || ans == 'Y'){   
        std::cout << "Check connection?: " << std::boolalpha << true << std::endl; 
        get_username();
        get_compname();
        get_version();
        print_os();
        get_mem_info();
		get_ram();
        //getSentAndRecievedBits();
        check_connection();  
    }
    else if(ans == 'n' || ans == 'N')
    {
        std::cout<< "Check Connection?: " << std::boolalpha << false << std::endl;
        get_username();
        get_compname();
        get_version();
        print_os();
        get_mem_info();
		get_ram();
        //getSentAndRecievedBits();
        break;
    }
    else if(ans =='q'|| ans == 'Q' )
    {
        std::cout << "Exiting.." << std::endl;
        break;
    } 
    else if(isdigit(ans))
    {
        std::cout << ans << "Cannot be digit. (y/n OR Y/N)" << std::endl;
    }
    }
    while(ans != 'y' || ans !='Y' || ans != 'n' || ans !='N' || ans != 'q' || ans != 'Q');

    
}
