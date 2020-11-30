#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
struct complex_number
{
    int a;
    int b;
    complex_number operator+(complex_number r)
    {
        return complex_number{a + r.a, b + r.b};
    }
    bool operator==(complex_number r)
    {
        return r.a == a && r.b == b;
    }
    bool operator<(complex_number r)
    {
        return distanceFromTheCenter() < r.distanceFromTheCenter();
    }
    int distanceFromTheCenter()
    {
        return sqrt((a * a) + (b * b));
    }
};
struct database
{
    std::vector<complex_number> points;
};
database base;
void newPoint()
{
    complex_number point;
    std::cout << "ENter 2 numbers: ";
    std::cin >> point.a;
    std::cin >> point.b;
    base.points.push_back(point);
}
void showPoint()
{
    std::cout << "zawartosc" << std::endl;
    for (complex_number &i : base.points)
    {
        std::cout << "(" << i.a << "," << i.b << ")";
    }
    std::cout << std::endl;
}
void sum()
{
    complex_number sum;
    std::cout << "Suma " << std::endl;
    sum = std::accumulate(base.points.begin(), base.points.end(), complex_number{0, 0});
    std::cout << "(" << sum.a << "," << sum.b << ")" << std::endl;
}
void isLocatedPoint()
{
    complex_number find;
    std::cout << "wprowadz szukany punkt:" << std::endl;
    std::cin >> find.a >> find.b;
    std::vector<complex_number>::iterator i = std::find(base.points.begin(), base.points.end(), find);
    if (i != base.points.end())
    {
        std::cout << "Tak" << std::endl;
    }
    else
    {
        std::cout << "Nein" << std::endl;
    }
}
void findPoint()
{
    std::vector<complex_number>::iterator xd = std::max_element(base.points.begin(), base.points.end());
    if (xd == base.points.end())
    {
        std::cout << "twoj wektor jest pusty";
    }
    else
    {
        std::cout << "(" << xd->a << "," << xd->b << ")" << std::endl
                  << std::endl;
    }
}
int main()
{

    int number;
    while (true)
    {
        std::cout << "[1]Wprowadz  nowy pnkt" << std::endl;
        std::cout << "[2]Wypisz zawartosc bazy" << std::endl;
        std::cout << "[3]Suma all points" << std::endl;
        std::cout << "[4]czy znajduje sie  dany punkt" << std::endl;
        std::cout << "[5]ZNajdz element najdalej  od  srodka xd" << std::endl;
        std::cout << "[6]ExIT" << std::endl;
        std::cin >> number;
        switch (number)
        {
        case 1:
        {
            newPoint();
            break;
        }
        case 2:
        {
            showPoint();
            break;
        }
        case 3:
        {
            sum();
            break;
        }
        case 4:
        {
            isLocatedPoint();
            break;
        }
        case 5:
        {
            findPoint();
            break;
        }
        case 6:
        {
            return 0;
            break;
        }
        }
    }
}
