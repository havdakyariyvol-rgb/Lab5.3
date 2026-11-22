#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

using namespace std;

double h(const double x);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double qp, qk, y;
    int n;

    cout << "Введіть початкове значення q: ";
    cin >> qp;
    cout << "Введіть кінцеве значення q: ";
    cin >> qk;
    cout << "Введіть кількість відрізків n: ";
    cin >> n;

    if (n <= 0 || qk < qp)
    {
        cout << "Помилка: перевірте межі інтервалу та n." << endl;
        return 1;
    }

    cout << fixed;
    cout << "----------------------------------" << endl;
    cout << "|" << setw(10) << "q" << " |"
        << setw(18) << "y(q)" << " |" << endl;
    cout << "----------------------------------" << endl;

    double dq = (qk - qp) / n;
    double q = qp;
    while (q <= qk + dq / 2.0) // захист від похибки округлення double на останньому кроці
    {
        y = h(q + 1) + h(q * q + 1) + pow(h(q * q), 2);
        cout << "|" << setw(10) << setprecision(5) << q << " |"
            << setw(18) << setprecision(5) << y << " |" << endl;
        q += dq;
    }
    cout << "----------------------------------" << endl;

    return 0;
}

double h(const double x)
{
    if (abs(x) >= 1)
    {
        return (cos(x) + 1) / (pow(cos(x), 2) + 1);
    }
    else
    {
        double S = 0;
        double a = 1;
        S = a;

        for (int i = 1; i <= 6; i++)
        {
            a *= (x * x) / ((2.0 * i - 1) * (2.0 * i));
            S += a;
        }

        return S / cos(x);
    }
}