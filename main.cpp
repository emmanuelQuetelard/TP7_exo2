/**
 *
 * @file   TestFunctor.cpp
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    27/04/2010
 *
 * @version V1.0
 *
 * @brief   Premier functor
 *
 **/
#include <iostream>
#include <cassert>
#include <cctype>  // tolower(), toupper()
#include <string>

using namespace std;

class ToLowerFunctor
{
public:
    virtual ~ToLowerFunctor() {}
    virtual int operator()(int c) const {return tolower(c);}
};

string & moulinette (string& str, const ToLowerFunctor& f)
{
    for(char& c : str)
    {
        c = f(c);
    }
    return str;
}

void testFunctor (void)
    {
        cout << "Functor : ";

        string ligne  ("AZECv qrgWSg wrV  wfdgWFDHG  wdfGWXCV");
        string minusc ("azecv qrgwsg wrv  wfdgwfdhg  wdfgwxcv");

        // ToDo
        ToLowerFunctor f;
        assert (minusc == moulinette (ligne, f));

        cout << "OK\n";

    } // testFunctor()

int main()
{
    testFunctor();
    return 0;
}
