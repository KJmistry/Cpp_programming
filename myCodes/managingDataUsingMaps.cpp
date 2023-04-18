#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>

#define MAX_PRODUCT 10

using namespace std;

volatile char key = 0; 
pthread_mutex_t mutex;

struct timingInfo
{
    string date;
    string time;
};


int writeDateTime(struct timingInfo* &ptr)
{   
    if(NULL == ptr)
    {
        printf("[%s]:[%d] NULL pointer detected as timingInfo structure pointer\n", __func__, __LINE__);
        return 1;
    }
    string date = __DATE__;
    string time = __TIME__;
    
    ptr->date = date;
    ptr->time = time;
    return 0;
}

class dataBase
{   
    string productName;
    int cost;

public:
    dataBase(string productName = "Empty Item", int cost = 0) : productName(productName) , cost(cost) {}                // parametarized constructor to initiliaze members
    void displayData();
};

void dataBase::displayData()
{
    cout << "Item Name : " << productName << endl;
    cout << "Item Cost : " << cost << endl;
}


int getEntry(map <int,dataBase*>& ref)                                       // Called when ever key press detected for iteam entry 
{   
    static int index = 0;

    if(index > MAX_PRODUCT)                                                 // validation for Max product limit
        return 1;
    
    string productName;
    int cost;

    cout << "Enter Product Name" << endl;
    cin >> productName ;
    cout << "Enter Product Cost" << endl;
    cin >> cost;

    ref[index] = new dataBase(productName,cost);
    index++;
    
    return 0;
}

int pushData(FILE* fptr, map <int,dataBase*>* ref, char* fileName)
{
    if ((fptr = fopen(fileName, "w")) == NULL) 
    {
        cout << "Can not open file" << endl;
        return 1;
    }
    
    struct timingInfo *tPtr;                                                // creating pointer to structure for time/date Information.
    tPtr = new timingInfo;

    int valid = writeDateTime(tPtr);
    if( valid == 1)
    {
        printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
        return 1;
    }

    fwrite(tPtr, sizeof(struct timingInfo), 1, fptr);
    delete tPtr;
    tPtr = NULL;

    for(auto it : *(ref))
    {
        fwrite(it.second,sizeof(it.second),1,fptr);
    }

	fclose(fptr);
	return 0;    
}

// map <int,dataBase*> *gRef;
map <int,dataBase*> myDataBase;

void handle_sigint(int sig)
{   
    // FILE *fptr = NULL;
    // char fileName[] = "dataBase.txt";
    printf("\033[0;31m");
    printf("Displaying all previous entries !\n");
    // pushData(fptr,gRef,fileName);
    printf("\033[0;36m");
    for(auto it : myDataBase)
    {
        cout << "Entry Index " << it.first << " : " << endl;
        it.second->displayData();
    }
}

void handle_sigstop(int sig)
{   
    int valid;
    printf("\033[0;32m");
    printf("Enter Product Details\n");
    valid = getEntry(myDataBase);
    if(valid == 1)
    {
        cout << "Not enough spce to store data !" << endl;
    }
}

void* routine(void* ptr)
{     
    while(1)
    {   
        signal(SIGINT, handle_sigint);
        signal(SIGQUIT, handle_sigstop);
    }   
}


int main()
{   
    pthread_t t1;
    pthread_mutex_init(&mutex,NULL);

    pthread_create(&t1, NULL, &routine, NULL);       
    pthread_join(t1, NULL);                         
    pthread_mutex_destroy(&mutex);

    // valid = getEntry(myDataBase);
    // if(valid == 1)
    // {
    //     cout << "Not enough spce to store data !" << endl;
    // }

    // pushData(fptr,myDataBase,fileName);
    // cout << sizeof(dataBase);
    
    return 0;
}