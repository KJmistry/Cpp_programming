#include <iostream>
#include <fstream>
#include <vector> 
using namespace std;

int main()
{
fstream myStream;
string line;
string search = "NAME 2";
unsigned int curLine = 0;
vector <int> lineNo;
char arr[100];

myStream.open("myDataBase", ios_base::out | ios_base::in);

while(getline(myStream, line)) 
{ 
    curLine++;
    if (line.find(search, 0) != string::npos) 
    {
        lineNo.emplace_back(curLine);
        // cout << "found: " << search << "line: " << curLine << endl;
    }
}

    if(lineNo.size() > 0)
    {
        search = "4545454545";
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
newEntry.append(to_string(newNumber));

myStream.close();
}
