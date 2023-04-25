#include <iostream>

using namespace std;

int prof_cur = 1;
int student_cur = 1;

class Person
{
protected:
    string name;
    int age;

public:
    virtual void getdata()
    {
    }
    virtual void putdata()
    {
    }
};

class Professor : public Person
{
    int publications;
    int cur_id;

public:
    void getdata()
    {
        cin >> name;
        cin >> age;
        cin >> publications;
        cur_id = prof_cur;
        prof_cur++;
    }
    void putdata()
    {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

class Student : public Person
{
    int marks[6];
    int cur_id;
    int sum = 0;

    void getdata()
    {
        cin >> name;
        cin >> age;
        for (int i = 0; i < 6; i++)
        {
            cin >> marks[i];
            sum += marks[i];
        }
        cur_id = student_cur;
        student_cur++;
    }
    void putdata()
    {
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
};
int main()
{

    int n, val;
    cin >> n;                                                                           // The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++)
    {

        cin >> val;
        if (val == 1)
        {
                                                                                        // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else
            per[i] = new Student;                                                       // Else the current object is of type Student

        per[i]->getdata();                                                              // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata();                                                              // Print the required output for each object.

    return 0;
}
