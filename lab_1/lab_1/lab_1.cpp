#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <locale.h>
#include <list>
#include <fstream>

using namespace std;



class Student;

class Observer {
public:
    void getInfo(Student& value);   
};

class Student {
private:
    string m_surname;
    string m_name;
    string m_fathername;
    string m_birthday;
    string m_address;
    int m_phone;
    string m_faculty;
    int m_course;

public: 

    Student(string surname, int course) {
        m_surname = surname;
        m_course = course;
    }

    bool operator ==(const Student &other) {
        return this->m_course == other.m_course;
    }

    bool operator !=(const Student& other) {
        return this->m_surname != other.m_surname;
    }

    Student operator =(const Student &other) {
        Student tmp(m_surname = other.m_surname, m_course = other.m_course);
        return tmp;
    }

    friend void Observer::getInfo(Student& value);

    
                                                                                                             //конструкторы
    Student() {
        m_surname = " "; m_name = " "; m_fathername = " ";
        m_birthday = " "; m_address = " "; m_phone = 000000;
        m_faculty = " "; m_course = 0;
    }

    void SetDate(string tmp_surname, string tmp_name, string tmp_fathername, string tmp_birthday, string tmp_address, int tmp_phone, string tmp_faculty, int tmp_course) {
        m_surname = tmp_surname;
        m_name = tmp_name;
        m_fathername = tmp_fathername;
        m_birthday = tmp_birthday;
        m_address = tmp_address;
        m_phone = tmp_phone;
        m_faculty = tmp_faculty;
        m_course = tmp_course;
    }
    
    void GetDate(){    
        cout << m_surname<< " ";
        cout << m_name << " ";
        cout << m_fathername << " ";
        cout << m_birthday << " ";
        cout << m_address << " ";
        cout << m_phone << " ";
        cout << m_faculty << " ";
        cout << m_course << "\n";
    }

    string getSurname() {
        return m_surname;
    }

    void SetSurname(string surname) {
        m_surname = surname;
    }

    int getCourse() {
        return m_course;
    }

    void SetCourse(int course) {
        m_course = course;
    }

    Student CreateCopy(const Student& tmp_people) {             
        m_surname = tmp_people.m_surname;
        m_name = tmp_people.m_name;
        m_fathername = tmp_people.m_fathername;
        m_birthday = tmp_people.m_birthday;
        m_address = tmp_people.m_address;
        m_phone = tmp_people.m_phone;
        m_faculty = tmp_people.m_faculty;
        m_course = tmp_people.m_course;
        return tmp_people;
    }

    int FundSurname(string choosen_surname) {
        if (m_surname == choosen_surname) return 1;
        else return 0;
    }


    int SortFaculty(string choosen_faculty) {
        if (m_faculty == choosen_faculty) return 1;
        else return 0; 
    }

    int SortYear(int choosen_year) {
        int year_int;
        string year_str;
        
        year_str = m_birthday.substr(6, 4);                     //приведение типов
        year_int = stoi(year_str);
        
        if (year_int > choosen_year) return 1;
        else return 0;
    }

    int SortCourse(int choosen_course) {
        if (m_course == choosen_course) return 1;
        else return 0;
    }


    Student(string tmp1_surname, string tmp1_name, string tmp1_fathername, string tmp1_birthday, string tmp1_address, int tmp1_phone, string tmp1_faculty, int tmp1_course) {
        m_surname = tmp1_surname;
        m_name = tmp1_name;
        m_fathername = tmp1_fathername;
        m_birthday = tmp1_birthday;
        m_address = tmp1_address;
        m_phone = tmp1_phone;
        m_faculty = tmp1_faculty;
        m_course = tmp1_course;
    }

    
    ~Student(){/*  std::cout << "Вызов деструктора " << this << std::endl; */}

};








string new_s;

int main(){
    setlocale(0, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int menu_answer;
    int menu_answer_sort;

    string tmp_surname;
    string tmp_name;
    string tmp_fathername;
    string tmp_birthday;
    string tmp_address;
    int tmp_phone = 0;
    string tmp_faculty;
    int tmp_course = 0;

    string choosen_faculty;
    int choosen_year;
    string choosen_surname;
    

    int n;
    printf("Введите количество студентов -> ");
    scanf("%d", &n);
    
    list <Student> mas_peoples;
    list <string> mas_faculty;
    list <int> mas_course;

    for (int i = 0; i < n; ++i) {                                               //задание параметров по умолчанию
        Student people;                 
        //people.GetDate();
    }

    cout << "1) Ввести данные с клавиатуры" << endl;                                    //запись данных
    cout << "2) Прочитать данные из файла" << endl;
    cout << "Введите выбранный вариант -> ";
    cin >> menu_answer;

    switch (menu_answer) {
    case(1): {

        string tmp1_surname = "Новик";
        string tmp1_name = "Илья";
        string tmp1_fathername = "Львович";
        string tmp1_birthday = "20.01.2003";
        string tmp1_address = "Пенза";
        int tmp1_phone = 121214;
        string tmp1_faculty = "ФВТ";
        int tmp1_course = 2;
        Student a(tmp1_surname, tmp1_name, tmp1_fathername, tmp1_birthday, tmp1_address, tmp1_phone, tmp1_faculty, tmp1_course);



        for (int i = 0; i < n; ++i) {
            Student people(tmp1_surname, tmp1_name, tmp1_fathername, tmp1_birthday, tmp1_address, tmp1_phone, tmp1_faculty, tmp1_course);

            cout << ("\n\nВведите фамилию студента -> ");
            cin >> tmp_surname;
            cout << ("Введите имя студента -> ");
            cin >> tmp_name;
            cout << ("Введите отчество студента -> ");
            cin >> tmp_fathername;
            cout << ("Введите день рождения студента -> ");
            cin >> tmp_birthday;
            cout << ("Введите адрес студента -> ");
            cin >> tmp_address;
            cout << ("Введите телефон студента -> ");
            cin >> tmp_phone;
            cout << ("Введите факультет студента -> ");
            cin >> tmp_faculty;
            mas_faculty.push_back(tmp_faculty);
            cout << ("Введите курс студента -> ");
            cin >> tmp_course;
            mas_course.push_back(tmp_course);
            cout << '\n';

            people.SetDate(tmp_surname, tmp_name, tmp_fathername, tmp_birthday, tmp_address, tmp_phone, tmp_faculty, tmp_course);
            mas_peoples.push_back(people);
        }
    }
    case(2): {

        string line;
        ifstream in("database.txt");
        if (in.is_open()) {
            while (!in.eof()) {
                Student people;

                cout << ("\n\nФамилия студента: ");
                getline(in, tmp_surname);
                cout << tmp_surname << endl;
                cout << ("Имя студента: ");
                getline(in, tmp_name);
                cout << tmp_name << endl;
                cout << ("Отчество студента: ");
                getline(in, tmp_fathername);
                cout << tmp_fathername << endl;
                cout << ("День рождения студента: ");
                getline(in, tmp_birthday);
                cout << tmp_birthday << endl;
                cout << ("Адрес студента: ");
                getline(in, tmp_address);
                cout << tmp_address << endl;

                cout << ("Телефон студента: ");
                getline(in, line);
                int tmp_phone{ stoi(line) };
                cout << line << endl;

                cout << ("Факультет студента: ");
                getline(in, tmp_faculty);
                cout << tmp_faculty << endl;
                mas_faculty.push_back(tmp_faculty);

                cout << ("Курс студента: ");
                getline(in, line);
                int tmp_course{ stoi(line) };
                cout << line << endl;
                mas_course.push_back(tmp_course);

                cout << endl;

                people.SetDate(tmp_surname, tmp_name, tmp_fathername, tmp_birthday, tmp_address, tmp_phone, tmp_faculty, tmp_course);
                mas_peoples.push_back(people);
            }
        }
        in.close();
        cout << "Данные из файла записаны успешно\n" << endl;
    }      
    }
    
    int start = 1;
    while (start) {
        cout << "\n\n1) Вывести список студентов заданного факультета" << endl;                                    //выборки и действия
        cout << "2) Вывести списки студентов для каждого факультета и курса" << endl;
        cout << "3) Вывести список студентов, родившихся после заданного года" << endl;
        cout << "4) Создать копию элемента" << endl;
        cout << "5) Перегрузка" << endl;
        cout << "6) Дружественный метод GetInfo " << endl;
        cout << "0) Выход" << endl;
        cout << "Введите выбранный вариант -> ";
        cin >> menu_answer_sort;

        if (menu_answer_sort == 0) {
            start = 0;
        }
        
        else {

            switch (menu_answer_sort) {
            case(1): {                                                  //выборка студентов заданного факультета
                cout << ("Введите факультет для выборки -> ");
                cin >> choosen_faculty;
                Student tmp_people;

                for (int i = 0; i < n; ++i) {
                    tmp_people = mas_peoples.front();
                    if (tmp_people.SortFaculty(choosen_faculty)) tmp_people.GetDate();
                    mas_peoples.pop_front();
                    mas_peoples.push_back(tmp_people);
                }

                break;
            }
            case(2): {                                                 //выборка студентов для каждого факультета и курса
                string t1;
                int t2;
                for (int i = 0; i < n; ++i) {
                    mas_faculty.unique();
                    mas_course.unique();
                    t1 = mas_faculty.front();               //смена мест
                    mas_faculty.pop_front();
                    mas_faculty.push_back(t1);
                    t2 = mas_course.front();
                    mas_course.pop_front();
                    mas_course.push_back(t2);
                }

                int size_faculty = mas_faculty.size();
                int size_course = mas_course.size();

                Student tmp_people;

                cout << "\nСортировка по факультету\n";
                string tmp_faculty_sort;
                for (int i = 0; i < size_faculty; ++i) {
                    tmp_faculty_sort = mas_faculty.front();
                    mas_faculty.pop_front();
                    for (int i = 0; i < n; ++i) {
                        tmp_people = mas_peoples.front();
                        if (tmp_people.SortFaculty(tmp_faculty_sort)) tmp_people.GetDate();
                        mas_peoples.pop_front();
                        mas_peoples.push_back(tmp_people);
                    }
                    cout << "\n";
                }

                cout << "---------------------------------------------------------------------------------\n";
                cout << "Сортировка по курсу\n";
                int tmp_course_sort;
                for (int i = 0; i < size_course; ++i) {
                    tmp_course_sort = mas_course.front();
                    mas_course.pop_front();
                    for (int i = 0; i < n; ++i) {
                        tmp_people = mas_peoples.front();
                        if (tmp_people.SortCourse(tmp_course_sort)) tmp_people.GetDate();
                        mas_peoples.pop_front();
                        mas_peoples.push_back(tmp_people);
                    }
                    cout << "\n";
                }

                break;
            }
            case(3): {                                                 //выборка студентов, родившихся после заданного года
                cout << ("Введите год для выборки студентов, родившихся после заданного -> ");
                cin >> choosen_year;
                Student tmp_people;

                for (int i = 0; i < n; ++i) {
                    tmp_people = mas_peoples.front();
                    if (tmp_people.SortYear(choosen_year)) tmp_people.GetDate();
                    mas_peoples.pop_front();
                    mas_peoples.push_back(tmp_people);
                }

                break;
            }
            case(4): {                                                 //создание копии
                cout << ("Введите фамилию студента, для записи которого необходима копия-> ");
                cin >> choosen_surname;
                Student tmp_people;
                //Student copy_people;//
                for (int i = 0; i < n; ++i) {
                    tmp_people = mas_peoples.front();
                    if (tmp_people.FundSurname(choosen_surname)) {
                        tmp_people.GetDate();
                        //copy_people.CreateCopy(tmp_people);
                        Student copy_people = tmp_people;
                        copy_people.GetDate();
                        mas_peoples.push_back(copy_people);
                    }
                    else tmp_people.GetDate();
                    mas_peoples.pop_front();
                    mas_peoples.push_back(tmp_people);
                }

                break;
            }

/*-----------------------------------------------------------------------------Лабораторная работа №2-------------------------------------------------------------------*/
            case(5): {
                                                                
                Student a("Иванов", 2);
                Student b("Смирнов", 2);
                cout << a.getSurname() << " на " << a.getCourse() << " курсе " << endl;
                cout << b.getSurname() << " на " << b.getCourse() << " курсе " << endl << endl;
                
                bool rezult11 = a == b;                                                                     //Перегрузка операции равенста (1-ый набор данных)
                if (rezult11 == true) cout << "Один курс обученя" << endl;
                else cout << "Разные курсы обученя" << endl;

                bool rezult12 = a != b;                                                                     //Перегрузка операции неравенста (1-ый набор данных)
                if (rezult12 == true) cout << "Разные фамилии" << endl << endl;
                else cout << "Однофамильцы" << endl << endl;

                
                cout << "_________________________________" << endl;
                Student c("Петров", 1);
                Student d("Петров", 2);
                cout << c.getSurname() << " на " << c.getCourse() << " курсе " << endl;
                cout << d.getSurname() << " на " << d.getCourse() << " курсе " << endl << endl;

                bool rezult21 = c == d;                                                                     //Перегрузка операции равенста (2-ой набор данных)
                if (rezult21 == true) cout << "Один курс обученя" << endl;
                else cout << "Разные курсы обученя" << endl;

                bool rezult22 = c != d;                                                                     //Перегрузка операции неравенста (2-ой набор данных)
                if (rezult22 == true) cout << "Разные фамилии" << endl << endl;
                else cout << "Однофамильцы" << endl << endl;



                cout << "_________________________________" << endl;
                cout << "a = " << a.getSurname() << " на " << a.getCourse() << " курсе " << endl;
                cout << "c = " << c.getSurname() << " на " << c.getCourse() << " курсе " << endl << endl;
                Student new_student = a = c;                                                                //Перегрузка операции присвоения
                cout << "a = c = " << new_student.getSurname() << " на " << new_student.getCourse() << " курсе " << endl << endl;

                break;
            }
           

            case(6): {                                                                                      //Дружественный метод GetInfo
                string tmp1_surname = "Новик";
                string tmp1_name = "Илья";
                string tmp1_fathername = "Львович";
                string tmp1_birthday = "20.01.2003";
                string tmp1_address = "Пенза";
                int tmp1_phone = 121214;
                string tmp1_faculty = "ФВТ";
                int tmp1_course = 2;
                Student a(tmp1_surname, tmp1_name, tmp1_fathername, tmp1_birthday, tmp1_address, tmp1_phone, tmp1_faculty, tmp1_course);

                Observer a_copy;
                a_copy.getInfo(a);

                

                break;
            }

            case(0): { break; }
            }
        }
    }                                                           
}

void Observer::getInfo(Student& value) {
    cout << value.m_surname << " ";
    cout << value.m_name << " ";
    cout << value.m_fathername << " ";
    cout << value.m_birthday << " ";
    cout << value.m_address << " ";
    cout << value.m_phone << " ";
    cout << value.m_faculty << " ";
    cout << value.m_course << "\n";
}
