#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<ctime>
#include<cstdlib>
#include<wininet.h>
#include<typeinfo>
#include<iphlpapi.h>

#pragma comment(lib,"wininet.lib")
//#pragma comment(lib, "Iphlpapi.lib")


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
    std::cout << "User: " << user << std::endl;
    std::cout << "Last login: " << __TIME__ << "\n" << std::endl;
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

void check_connection()
{
   int pingTimes;
   int testNum = 0;
   std::cout << "How many times to ping?: " << std::endl;
   std::cin >> pingTimes;  
   if(pingTimes == 1)
   {
       std::printf("Running %d test, please be patient...", pingTimes); 
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
   }else if(pingTimes > 1)
   {
    std::printf("Running %d tests, please be patient...", pingTimes);

   if(pingTimes > 0 && pingTimes < 10){
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
   else if(pingTimes == 0)
   {
       std::cout << "No tests entered." << std::endl;
   }
   else if(pingTimes < 0)
   {
       std::cout << "pingTimes needs to be greater than 0." << std::endl;
   }
   else if (pingTimes > 10)
   {
	   std::cout << "Cannot have more than 10 tests done." << std::endl;
   }
   }
  
   
}
/*
bool getSentAndRecievedBits(DWORD &dwbitTotalRecv, DWORD &dwbitTotalSend)
{
     DWORD dwBufferLen = 0;  
    GetIfTable(NULL, &dwBufferLen, 0);   
  
          
    PMIB_IFTABLE pMibIfTable = (MIB_IFTABLE*)malloc(dwBufferLen);  
  
         
    DWORD dwRet = GetIfTable(pMibIfTable, &dwBufferLen, 0);  
    if(NO_ERROR != dwRet)  
    {  
        std::cout<<"GetIfTable != NO_ERROR, ErrorCode="<<dwRet<<std::endl;  
        free(pMibIfTable);  
        return false;  
    }  
  
    dwbitTotalRecv = dwbitTotalSend = 0;  
  
        
    for(int i = 0; i != pMibIfTable->dwNumEntries; ++i)  
    {  
        if (pMibIfTable->table[i].dwType <= 23)  
        {  
            dwbitTotalRecv += pMibIfTable->table[i].dwInOctets;  
            dwbitTotalSend += pMibIfTable->table[i].dwOutOctets;  
        }  
    }  
  
        
    dwbitTotalRecv *= 8;  
    dwbitTotalSend *= 8;  
  
    free(pMibIfTable);  
    return true;  
}
*/
void get_ram()
{
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	std::cout << "Physical RAM: " << (float)statex.ullTotalPhys/(1024*1024*1024) << std::endl;
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
        std::cout << "Check Connection: " << std::boolalpha << true << std::endl; 
        greeting();
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
        std::cout<< "Check Connection: " << std::boolalpha << false << std::endl;
        greeting();
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
        std::cout << "Thank you! " << user << std::endl;
        break;
    } 
    else if(isdigit(ans))
    {
        std::cout << ans << "Cannot be digit. (y/n OR Y/N)" << std::endl;
    }
    }
    while(ans != 'y' || ans !='Y' || ans != 'n' || ans !='N' || ans != 'q' || ans != 'Q');

    
}