// C++ code to demonstrate sorting of 2D vector on basis of no. of columns in descending order
#include<iostream>
#include<vector> 
#include<algorithm> 
using namespace std;

// Driver function to sort the 2D vector on basis of a no. of columns in descending order
bool sizecom(const vector<int>& v1, const vector<int>& v2)
{
    if(v1.size() > v2.size())
	    return true;

    else if(v1.size() < v2.size())
        return false;

    else if(v1[0] > v2[0])
        return true;
    
    else if(v1[1] > v2[1])
        return true;
    
    else if(v1[2] > v2[2])
        return true;
}

int main()
{
	vector <vector<int>> vect{{1, 2, 3}, {3, 4, 5}, {6, 6, 8}, {1, 1, 1}, {3, 4, 1}};

	cout << "The Matrix before sorting is:\n";
	for (int long unsigned i=0; i<vect.size(); i++)
	{
		for (int long unsigned j=0; j<vect[i].size() ;j++)
			cout << vect[i][j] << " ";
		cout << endl;
	}

	sort(vect.begin(), vect.end(), sizecom);

	cout << "The Matrix after sorting is:\n";
	for (long unsigned int i=0; i<vect.size(); i++)
	{
		for (int long unsigned j=0; j<vect[i].size() ;j++)
			cout << vect[i][j] << " ";
		cout << endl;
	}

	return 0;

}
