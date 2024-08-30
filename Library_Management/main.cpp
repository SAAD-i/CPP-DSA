#include <iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class Book
{
    //complete the class
private:
    int code;
    string title;
    int available;
    int rented;
};
class ChildrenBook:public Book
{
private:
    int age;
};
class ComputerBook:public Book
{
private:
    string publisher;
};
class Novel:public Book
{
private:
    int publish_date;
};
class Person
{
private:
    int id;
    string name;
    int count;
};
class Student:public Person
{
private:
    int code[2];
};
class Teacher:public Person
{
private:
    int code[3];
};
int main()
{
    do
    {

    }while(choice!=0);
}
