#include <iostream> 
#include <math.h>  
#include <vector>
#include <string>
#include<algorithm>
#include <cmath>

using namespace std;


double calculate2(double x1, double x2 , string oper1);
double calculate3(double x1, double x2 , double x3, string oper1, string oper2);
double calculate4(double x1, double x2 , double x3, double x4, string oper1 , string oper2, string oper3);
void  writebase (int number , int base);

int main()
{

    double x1,x2,x3,x4;
    string oper1,oper2,oper3,oper4;
    int count = 0 ;

    cout << "Console Calculator" << endl;

    while(true)
    {
        cout << endl<<endl;
        cout << "Please enter the count of numbers you want to enter:";
        cin >> count;
        cout << "Please enter " << count << " numbers and " << count - 1 << " operations." << endl;

        if (count == 2)
        {
            cin >> x1 >> oper1 >> x2;
        }
        else if (count ==3)
        {
            cin >> x1 >> oper1 >> x2 >> oper2 >> x3;
        }
        else if (count == 4)
        {
            cin >> x1 >> oper1 >> x2 >> oper2 >> x3 >> oper3 >> x4;
        }

        cout << "Solution: " ;

        if (count == 2)
        {
            if (oper1 == "base")
            {
                writebase(x1,x2);
            }
            else 
            {
                cout << calculate2 (x1,x2,oper1);
            }
        }

        if (count == 3)
        {
            if (oper2 == "base")
            {
                double solution = calculate2 (x1,x2,oper1);
                writebase(solution,x3);
            }
            else 
            {
                cout << calculate3 (x1,x2,x3, oper1, oper2);
            }
        }

        if (count == 4)
        {
            if (oper3 == "base")
            {
                double solution =calculate3 (x1,x2,x3, oper1, oper2);
                writebase(solution,x4);
            }
            else 
            {
                cout << calculate4 (x1,x2,x3, x4, oper1, oper2, oper3);
            }
        }
        
    }


}


double calculate2(double x1, double x2 , string oper)
{
    if (oper == "+")
    {
        return x1 + x2;
    }

    if (oper == "-")
    {
        return x1-x2;
    }

    if (oper == "*")
    {
        return x1*x2;
    }

    if (oper == "/")
    {
        return x1/x2;
    }

    if (oper == "%")
    {
        return (int) x1 % (int) x2;
    }

    if (oper == "^")
    {
        return pow (x1 , x2);
    }
    
    return 0;
}

double calculate3(double x1, double x2 , double x3, string oper1, string oper2)
{
    double value;
    if (oper1 == "^")
    {
        value =pow (x1 , x2);
        return calculate2 (value, x3, oper2);
    }

    if (oper2 == "^")
    {
        value = pow (x2 , x3);
        return calculate2 (x1, value, oper1);
    }

    if (oper2 == "*" || oper2 == "/" )
    {
        value =  calculate2(x2,x3,oper2);
        return calculate2(x1,value,oper1);
    }

    value =  calculate2(x1,x2,oper1);
    return calculate2(value,x3,oper2);

}

double calculate4(double x1, double x2 , double x3, double x4, string oper1 , string oper2, string oper3)
{
    double value = 0;
    if (oper1 == "^")
    {
        value =pow (x1 , x2);
        return calculate3 (value, x3,x4, oper2, oper3);
    }

    if (oper2 == "^")
    {
        value = pow (x2 , x3);
        return calculate3 (x1, value,x4, oper1, oper3);
    }

    if (oper3 == "^")
    {
        value = pow (x3 , x4);
        return calculate3 (x1, x2,value, oper1, oper2);
    }

    if (oper2 == "*")
    {
        value = (int) x2 * (int) x3;
        return calculate3 (x1, value,x4, oper1, oper3);
    }

    if (oper2 == "/")
    {
        value = (int) x2 * (int) x3;
        return calculate3 (x1, value,x4, oper1, oper3);
    }

    if (oper3 == "*")
    {
        value = (int) x3 * (int) x4;
        return calculate3 (x1, x2,value, oper1, oper2);
    }

    if (oper3 == "/")
    {
        value = (int) x3 / (int) x4;
        return calculate3 (x1, x2,value, oper1, oper2);
    }

    value = calculate3 (x1, x2,x3, oper1, oper2);
    return calculate2(value,x4,oper3);
}

void  writebase (int number , int base)
{
    int a = number;

    int t = 1;
    while (number >= t* base)
        {
            t = t * base;
        }

    while (t)
    {
        cout << number/t << ' ';
        number -= t*(number/t);
        t /= base;
    }

    cout << '\n';
}
