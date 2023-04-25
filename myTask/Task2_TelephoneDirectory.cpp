#include <iostream>
#include <list>
#include <fstream>
#include <signal.h>
#include <limits>
#include <vector>

#define MAX_ENTRY 10
#define MEDICAL 0
#define GOV 1

#define ADD_DATA 11
#define WRITE_DATA 12
#define LOAD_DATA 13
#define DISPLAY_SPECIFIC_ENTRY 14
#define DELETE_ENTRY 15
#define UPDATE_ID_BY_SEARCH 16
#define FREE 20

#define FILE_PATH "./myDataBase"

void setBegin();

using namespace std;

class commonData
{

private:

    string personName;
    long int telephoneNumber;

public:

    virtual void printAllData()=0;
    virtual void printName();
    virtual void printTelephoneNumber();
    virtual void setID(){};

    // GET/SET DATA FUNCTIONS 

    string getName();
    long int getTelephoneNumber();
    void setName(string);
    void setTelephoneNumber(long int);
    virtual ~commonData(){}

};

class govSector : public commonData
{
public:
    int govID;
    
public:

    // govSector();
    void printAllData();
    void printGovID();

    // GET/SET DATA FUNCTIONS 

    int getID();
    void setID(int);
};

class medicalSector : public commonData
{
    int medicalID; 

public:
    void printAllData();
    void printMedicalID();
    
    // GET/SET DATA FUNCTIONS 

    int getID();
    void setID(int);
};

void commonData::printName()
{
    cout << "Person Name : " << personName << endl;
}

void commonData::printTelephoneNumber()
{
    cout << "Telephone Number : " << telephoneNumber << endl;
}

long int commonData::getTelephoneNumber()
{
    return telephoneNumber;
}

string commonData::getName()
{
    return personName;
}

void commonData::setName(string str)
{
    personName = str;
    return;
}

void commonData::setTelephoneNumber(long int num)
{
    telephoneNumber = num;
    return;
}

void govSector::printGovID()
{
    cout << "Gov. ID : " << govID << endl;
    return;
}

int govSector::getID()
{
    return govID;
}

void govSector::setID(int id)
{
    govID = id;
    return;
}

void medicalSector::printMedicalID()
{
    cout << "Medical ID : " << medicalID << endl;
    return;
}

int medicalSector::getID()
{
    return medicalID;
}

void medicalSector::setID(int id)
{
    medicalID = id;
    return;
}

void govSector::printAllData()
{
    printName();
    printTelephoneNumber();
    printGovID();
    return;
}

void medicalSector::printAllData()
{
    printName();
    printTelephoneNumber();
    printMedicalID();
    return;
}

//-----------------------------------------------TO Do-----------------------------------------------------------------

// Templet : to append or add data [ two obj types : gov & medical ]
// Add modification time information at top 
// Validation for all data !
// array of objects of class medicalSector and govSector
// file handling fstream
// load entire file to temp buffer with all data to operate (if already exists)
// inseret at specific location

fstream myStream;
list <govSector*> govList; 
list <medicalSector*> medList;
auto start_Index_gov = govList.begin();
auto start_Index_med = medList.begin();
int valid;

int addData(list <govSector*> &gRef, list <medicalSector*> &mRef)
{
    string entryType;
    string name;
    long int telephoneNumber;
    int govID,medID;

    cout << "Enter 'Gov' for Goverment sector\nEnter 'Med' for Medical sector" << endl;
    cin >> entryType;

    if(entryType == "Gov")
    {  
        cout << "Enter Name :" << endl; 
        cin.ignore();
        getline(cin,name);
        cout << "Enter Telephone Number :" << endl; 
        cin >> telephoneNumber;
        if (cin.fail()) 
        {   
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');            
            cout << "Entered Value is not an integer" << endl;
            return 1;
        }
        cout << "Enter ID Number :" << endl; 
        cin >> govID;
        if (cin.fail()) 
        {   
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');            
            cout << "Entered Value is not an integer" << endl;
            return 1;
        }  

        govSector* ptr = new govSector;
        if( ptr == nullptr)
        {
            cout << "Failed allocating memory" << endl;
            printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
        }
        ptr->setName(name);
        ptr->setTelephoneNumber(telephoneNumber);
        ptr->setID(govID);

        gRef.emplace_back(ptr);
        // cout << "ptr : " << ptr << endl;                                                             // Debug statement 
        return 0;   
    }
    else if(entryType == "Med")
    {   
        cout << "Enter Name :" << endl; 
        cin.ignore();
        getline(cin,name);
        cout << "Enter Telephone Number :" << endl; 
        cin >> telephoneNumber; 
        if (cin.fail()) 
        {   
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');            
            cout << "Entered Value is not an integer" << endl;
            return 1;
        } 
        cout << "Enter ID Number :" << endl; 
        cin >> medID;
        if (cin.fail()) 
        {   
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');            
            cout << "Entered Value is not an integer" << endl;
            return 1;
        }  

        medicalSector* ptr = new medicalSector;
        if( ptr == nullptr)
        {
            cout << "Failed allocating memory" << endl;
            printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
        }
        ptr->setName(name);
        ptr->setTelephoneNumber(telephoneNumber);
        ptr->setID(medID);

        mRef.emplace_back(ptr);

        return 0; 
    }
    else
    {
        cout << "Enter valid string" << endl;
        return 1; 
    }
}

int writeToFile(fstream &myStream,list<govSector*>::iterator &gIndex, list<medicalSector*>::iterator &mIndex, int govListSize, int medListSize)
{   
    setBegin();
    string n = "Last Modified :";
    n.append(__DATE__);
    n.append(" @ ");
    n.append(__TIME__);
    n.append("\n");
    myStream.open(FILE_PATH, ios_base::out);                           // ios_base::in __for writing   &  ios_base::in | ios_base::out __for both

    if (!myStream.is_open()) 
    {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    myStream.write(n.c_str(),n.size());
    n = "Government Sector\n";
    myStream.write(n.c_str(),n.size());

    for(int len = 0; len < govListSize; len++)
    {   
        if((*gIndex) == nullptr)
        {
            cout << "nullptr detected" << endl;
            printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            return 1;
        }
        n = to_string(len+1);
        n.append(". ");
        n.append((*gIndex)->getName());
        n.append(" : ");
        n.append(to_string((*gIndex)->getTelephoneNumber()));
        n.append(" : ");
        n.append(to_string((*gIndex)->getID()));
        n.append("\n");

        myStream.write(n.c_str(),n.size());

        gIndex++;
    }

    n = "\nMedical Sector\n";
    myStream.write(n.c_str(),n.size());


    for(int len = 0; len < medListSize; len++)
    {   
        if((*mIndex) == nullptr)
        {
            cout << "nullptr detected" << endl;
            printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            return 1;
        }
        n = to_string(len+1);
        n.append(". ");
        n.append((*mIndex)->getName());
        n.append(" : ");
        n.append(to_string((*mIndex)->getTelephoneNumber()));
        n.append(" : ");
        n.append(to_string((*mIndex)->getID()));
        n.append("\n");

        myStream.write(n.c_str(),n.size());

        mIndex++;
    }

    myStream.close();

    return 0;
}

int displaySpecificIndexEntry(int govEntries,int entryIndex,fstream &myStream,int sector)
{
    char c;
    int lineIndex = 0, offset = entryIndex + 1;                          // Offset for medical sector entry = NO OF ENTRIES IN GOV SECTOR + 2 
                                                                         // Offset for gov sector entry = 1
    if(sector == MEDICAL)
    {   
        if(entryIndex <= 0 || entryIndex > (int)medList.size())
        {
            printf("Enter Valid Index\n");
            printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            return 1;    
        }
        offset = govEntries + 3 + entryIndex;
    }
    else
    {
        if(entryIndex <= 0 || entryIndex > (int)govList.size())
        {
            printf("Enter Valid Index\n");
            printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            return 1;    
        }
    }
    myStream.open(FILE_PATH, ios_base::in);

    if (!myStream.is_open())
    {
        cout << "Open file failed" << endl;
        return 1;
    }
    char arr[100];

    while (lineIndex < offset)
    {
        do
        {
            myStream.seekg(0, ios_base::cur);
            myStream.get(c);
        }while(c != '\n');

        lineIndex++;
    }

    myStream.getline(arr, 100, '\n');
    cout << arr << endl;
    myStream.close();
    return 0;
}

void loadFileData(fstream &myStream, list<govSector*> &govList,list<medicalSector*> &medList)
{   

    string temp;
    char arr[100];
    int index = 0,length = 0;

    myStream.open(FILE_PATH, ios_base::in);
    
    myStream.seekg(0, ios::end);                                                                            // put the "cursor" at the end of the file
    length = myStream.tellg();                                                                              // find the position of the cursor
    if(length == 0)
    {
        cout << "Attempt to load an empty file" << endl;
        myStream.close();
        return;
    }
    
    myStream.seekg(0, ios::beg);                

    myStream.getline(arr, 100, '\n');                                                                       // skipping 1 line 
    myStream.getline(arr, 100, '\n');                                                                       // skipping 1 line 

    do
    {
        myStream.getline(arr, 100, '\n');                               
        temp = arr;
        if(temp != "")
        {   
            govSector* ptr = new govSector;
            temp.erase(0, 3);
            string delimiter = " : ";
            size_t pos = 0;
            string token;
            while ((pos = temp.find(delimiter)) != string::npos) 
            {
                token = temp.substr(0, pos);
                // cout << token << endl;
                if(index == 0)
                    ptr->setName(token);
                else if(index == 1)
                    ptr->setTelephoneNumber(stol(token));
                temp.erase(0, pos + delimiter.length());
                index++;
            }
            ptr->setID(stoi(temp));
            // cout << temp << endl;
            govList.emplace_back(ptr);
            index = 0;
        }
    }while(temp != "");

    myStream.getline(arr, 100, '\n');                                                                       // skipping 1 line
    temp = arr;
    if(temp != "")
    {
        do
        {   
            myStream.getline(arr, 100, '\n');
            temp = arr;
            if(temp != "")
            {
                medicalSector* ptr = new medicalSector;
                temp.erase(0, 3);

                string delimiter = " : ";
                size_t pos = 0;
                string token;
                while ((pos = temp.find(delimiter)) != string::npos) 
                {
                    token = temp.substr(0, pos);
                    // cout << token << endl;
                    if(index == 0)
                        ptr->setName(token);
                    else if(index == 1)
                        ptr->setTelephoneNumber(stol(token));
                    temp.erase(0, pos + delimiter.length());
                    index++;
                }
                ptr->setID(stoi(temp));
                // cout << temp << endl;
                medList.emplace_back(ptr);
                index = 0;
            }
        }while(!myStream.eof());
    }
    myStream.close();
    return;
}

int deleteEntry(list<govSector*> &govList,list<medicalSector*> &medList,int index,int type)
{   
    setBegin();
    if(GOV == type)
    {
        if(index <= 0 || index > (int)govList.size())
        {
            printf("Enter Valid Index\n");
            printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            return 1;    
        }
        advance(start_Index_gov,(index-1));
        govList.erase(start_Index_gov);
    }
    else if(MEDICAL == type)
    {
        if(index <= 0 || index > (int)medList.size())
        {
            printf("Enter Valid Index\n");
            printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            return 1;    
        }
        advance(start_Index_med,(index-1));
        medList.erase(start_Index_med);
    }
    else
    {   
        printf("Enter Valid Type\n");
        printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
        return 1;    
    }

    valid = writeToFile(myStream,start_Index_gov,start_Index_med,govList.size(),medList.size());
    
    if(valid == 1)
    {
        printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
    }
    
    return 0;
}

int modifyBySearch(fstream &myStream, string name, long int telephoneNum, int newID)
{   
    string n = "Last Modified :";
    n.append(__DATE__);
    n.append(" @ ");
    n.append(__TIME__);
    n.append("\n");

    string line;
    string search = name;
    unsigned int curLine = 0;
    vector <int> lineNo;
    char arr[100];

    myStream.open(FILE_PATH, ios_base::out | ios_base::in);
    myStream.write(n.c_str(),n.size());
    
    myStream.seekg(0);
    
    while(getline(myStream, line)) 
    { 
        curLine++;
        if (line.find(search, 0) != string::npos) 
        {
            lineNo.emplace_back(curLine);
            // cout << "found: " << search << "line: " << curLine << endl;
        }
    }

    if(lineNo.size() > 1)
    {
        search = to_string(telephoneNum);
        curLine = 0;
        lineNo.clear();
        myStream.seekg(0, ios::beg);         
        while(getline(myStream, line)) 
        { 
            curLine++;
            if (line.find(search, 0) != string::npos) 
            {
                lineNo.emplace_back(curLine);
                // cout << "found: " << search << "line: " << curLine << endl;
            }
        }
    }

    cout << lineNo[0] << endl;

    myStream.clear();
    myStream.seekg(0);

    for(int i = 0 ; i < lineNo[0]-1 ; i++)
    {
        myStream.getline(arr,100,'\n');
    }         
        
    myStream.getline(arr,100,'\n');
    line = arr;

    vector<string> strArr;
    string newEntry = line.substr(0,3);

    line.erase(0, 3);
    string delimiter = " : ";
    size_t pos = 0;
    string token;

    while ((pos = line.find(delimiter)) != string::npos) 
    {
        token = line.substr(0, pos);
        strArr.emplace_back(token);
        line.erase(0, pos + delimiter.length());
    }
    strArr.emplace_back(line);

    for(auto i : strArr)
        cout << i << endl;

    newEntry.append(strArr[0]);
    newEntry.append(" : ");
    newEntry.append(strArr[1]);
    newEntry.append(" : ");
    newEntry.append(to_string(newID));
    
    myStream.clear();
    myStream.seekg(0);

    for(int i = 0 ; i < lineNo[0]-1 ; i++)
    {
        myStream.getline(arr,100,'\n');
    }    

    myStream.write(newEntry.c_str(),newEntry.size());

    myStream.close();
    return 0;

}

void setBegin()
{
    start_Index_gov = govList.begin();
    start_Index_med = medList.begin();
}

// int globalFlag = 0;

// void handle_sigint(int sig)
// {
//     addData(govList,medList);  
// }

// void handle_sigstop(int sig)
// {   
//     int valid;
//     start_Index_gov = govList.begin();
//     start_Index_med = medList.begin();
//     valid = writeToFile(myStream,start_Index_gov,start_Index_med,govList.size(),medList.size());                    // call only if some new data is added 
//     globalFlag = 1;
// }


int main()
{   

    int k,type,index,newID;
    string name;
    long int telephoneNumber;

    while(1)
    {   
        printf("\nEnter 11 : For Adding Data\n");
        printf("Enter 12 : For Writing All Data to File\n");
        printf("Enter 13 : For Loading existing Data from file\n");
        printf("Enter 14 : For Displaying specific entry\n");
        printf("Enter 15 : For Deleting specific entry\n");
        printf("Enter 16 : For updating ID by search\n");
        printf("Enter 20 : To Free Memory\n");
        
        cin >> k;

        switch (k)
        {
        case ADD_DATA:
        
            valid = addData(govList,medList);
            if(valid == 1)
            {
                printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            }
            break;
        
        case WRITE_DATA:

            valid = writeToFile(myStream,start_Index_gov,start_Index_med,govList.size(),medList.size());                    // call only if some new data is added 
            if(valid == 1)
            {
                printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            }
            break;
        
        case LOAD_DATA:

            loadFileData(myStream,govList,medList);
            break;

        case DISPLAY_SPECIFIC_ENTRY:
            
            printf("Enter 1 for Government Sector\nEnter 0 for Medical Sector\n");
            cin >> type;
            if(type != 0 && type != 1)
            {
                printf("Enter Valid type 1 OR 0\n");
                break;                
            }
            printf("Enter Index for fetching specific entry\n");
            cin >> index;
            valid = displaySpecificIndexEntry(govList.size(),index,myStream,type);
            if(valid == 1)
            {
                printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            }
            break;

        case DELETE_ENTRY:

            printf("Enter 1 for Government Sector\nEnter 0 for Medical Sector\n");
            cin >> type;
            if(type != 0 && type != 1)
            {
                printf("Enter Valid type 1 OR 0\n");
                break;                
            }
            printf("Enter Index for deleting specific entry\n");
            cin >> index;
            deleteEntry(govList,medList,index,type);
            break;

        case UPDATE_ID_BY_SEARCH:

            printf("Enter Name \n");
            cin.ignore();
            getline(cin,name);
            printf("Ente telephoneNumber\n");
            cin >> telephoneNumber;
            printf("Ente new ID\n");
            cin >> newID;
            
            valid = modifyBySearch(myStream,name,telephoneNumber,newID);
            if(valid == 1)
            {
                printf("[%s]:[%d] Error occured \n", __func__, __LINE__);
            }
            break;

        case FREE:

            for(auto i : govList)
            {   
                i->printAllData();
                delete i;
            } 
            
            for(auto i : medList)
            {   
                i->printAllData();
                delete i;
            }
            
        default:

            cout << "Enter valid input" << endl;
            break;
        }
        
    }
    
    // addData(govList,medList);
    
    // while(1)
    // {
    //     if(1 == globalFlag)
    //         break;
    // }

    // start_Index_gov = govList.begin();
    // start_Index_med = medList.begin();
    // int valid = writeToFile(myStream,start_Index_gov,start_Index_med,govList.size(),medList.size());                    // call only if some new data is added 

    // start_Index_gov = govList.begin();
    // start_Index_med = medList.begin();

    // cout << (*start_Index_gov)->getID() << endl;
    // start_Index_gov++;
    // cout << (*start_Index_gov)->getID() << endl;

    // (*start_Index_med)->printAllData();
    // start_Index_med++;
    // start_Index_med++;
    // (*start_Index_med)->printAllData();
    
    // int valid = displaySpecificIndexEntry(govList.size(),2,myStream,GOV);
    // valid = displaySpecificIndexEntry(govList.size(),1,myStream,MEDICAL);


    // start_Index_gov = govList.begin();
    // start_Index_med = medList.begin();

    return 0;
}
