#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    set<int> sol_AB, sol_C, sol_DE, sol_FG, sol_HI, temp1, temp2;
    set<vector<int>> sol;
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a, b, c, d, e, f, g, h, i;

    for (int i = 0; i < 9; i++)
    {
        a = arr[i];
        for (int j = 0; j < 9; j++)
        {
            b = arr[j];
            for (int k = 0; k < 9; k++)
            {
                c = arr[k];
                if (a == b || b == c || c == a)
                    continue;
                int formula1 = (a * 10 + b) * c;
                if (formula1 >= 100)
                    continue;
                else
                {
                    sol_AB.insert((a * 10 + b));
                    sol_C.insert(c);
                    temp1.insert(formula1);
                }
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        d = arr[i];
        for (int j = 0; j < 9; j++)
        {
            e = arr[j];
            for (int k = 0; k < 9; k++)
            {
                f = arr[k];
                for (int m = 0; m < 9; m++)
                {
                    g = arr[m];
                    if (d == e || e == f || f == g || g == d)
                        continue;
                    int formula2 = (d * 10 + e) + (f * 10 + g);
                    if (formula2 >= 100)
                        continue;
                    else
                        temp2.insert(formula2);
                }
            }
        }
    }
    for (auto it1 = temp1.begin(); it1 != temp1.end(); it1++)
    {
        for (auto it2 = temp2.begin(); it2 != temp2.end(); it2++)
        {
            auto temp = *it1 + *it2;
            if (temp >= 100)
                continue;
            else
            {
                sol_DE.insert(*it1);
                sol_FG.insert(*it2);
                sol_HI.insert(temp);
            }
        }
    }

    for (auto it1 = sol_AB.begin(); it1 != sol_AB.end(); it1++)
    {
        a = *it1 / 10;
        b = *it1 % 10;
        for (auto it2 = sol_C.begin(); it2 != sol_C.end(); it2++)
        {
            c = *it2;
            if (a == b || b == c || c == a ||
                a == 0 || b == 0 || c == 0)
                continue;
            for (auto it3 = sol_DE.begin(); it3 != sol_DE.end(); it3++)
            {
                d = *it3 / 10;
                e = *it3 % 10;
                if (a == b || a == c || a == d || a == e ||
                    b == c || b == d || b == e ||
                    c == d || c == e ||
                    d == e || d == 0 || e == 0)
                    continue;
                for (auto it4 = sol_FG.begin(); it4 != sol_FG.end(); it4++)
                {
                    f = *it4 / 10;
                    g = *it4 % 10;
                    if (a == b || a == c || a == d || a == e || a == f || a == g ||
                        b == c || b == d || b == e || b == f || b == g ||
                        c == d || c == e || c == f || c == g ||
                        d == e || d == f || d == g ||
                        e == f || e == g ||
                        f == g || f == 0 || g == 0)
                        continue;
                    for (auto it5 = sol_HI.begin(); it5 != sol_HI.end(); it5++)
                    {
                        h = *it5 / 10;
                        i = *it5 % 10;
                        if (a == b || a == c || a == d || a == e || a == f || a == g || a == h || a == i ||
                            b == c || b == d || b == e || b == f || b == g || b == h || b == i ||
                            c == d || c == e || c == f || c == g || c == h || c == i ||
                            d == e || d == f || d == g || d == h || d == i ||
                            e == f || e == g || e == h || e == i ||
                            f == g || f == h || f == i ||
                            g == h || g == i ||
                            h == i || h == 0 || i == 0)
                            continue;
                        else
                        {
                            if (*it1 * *it2 == *it3 && (*it3 + *it4) == *it5)
                            {

                                vector<int> temp;
                                temp.push_back(*it1);
                                temp.push_back(*it2);
                                temp.push_back(*it3);
                                temp.push_back(*it4);
                                temp.push_back(*it5);
                                sol.insert(temp);
                            }
                        }
                    }
                }
            }
        }
    }

    /*  for (auto it = sol_AB.begin(); it != sol_AB.end(); it++)
            cout << *it << " ";
        cout << "\n*************************************************************************\n";
        for (auto it = sol_C.begin(); it != sol_C.end(); it++)
            cout << *it << " ";
        cout << "\n*************************************************************************\n";

        for (auto it = sol_DE.begin(); it != sol_DE.end(); it++)
            cout << *it << " ";
        cout << "\n*************************************************************************\n";

        for (auto it = sol_FG.begin(); it != sol_FG.end(); it++)
            cout << *it << " ";
        cout << "\n*************************************************************************\n";

        for (auto it = sol_HI.begin(); it != sol_HI.end(); it++)
            cout << *it << " ";

        cout << "\n*************************************************************************\n";*/

    // all possiblities
    int fact = 1;
    for (int i = 2; i < 10; i++)
    {
        fact = fact * i;
    }
    cout << "Possible ways:" << fact << "\n";

    // answer
    cout << "Answer:";
    for (auto i : sol)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    cout << "possible answer:" << sol.size() << "/" << fact << ".\n";

    return 0;
}