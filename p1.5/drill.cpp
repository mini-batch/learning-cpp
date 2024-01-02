#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main()
{
    try {
        // 1
        // std::cout << "Success!\n";

        // 2
        // std::cout << "Success!\n";

        // 3
        // std::cout << "Success" << "!\n";

        // 4
        // std::string success {"Success!"};
        // std::cout << success << '\n';

        // 5
        // std::string res {7};
        // std::vector<std::string> v(10);
        // v[5] = res;
        // std::cout << "Success!\n";

        // 6
        // std::vector<int> v(10);
        // v[5] = 7;
        // if (v[5] != 7) std::cout << "Success!\n";

        // 7
        // bool cond {true};
        // if (cond) std::cout << "Success!\n";
        // else std::cout << "Fail!\n";

        // 8
        // bool c = false;
        // if (!c) std::cout << "Success!\n";
        // else std::cout << "Fail!\n";

        // 9
        // std::string s {"ape"};
        // bool c = "fool" > s;
        // if (c) std::cout << "Success!\n";

        // 10
        // std::string s = "ape";
        // if (s != "fool") std::cout << "Success!\n";

        // 11
        // std::string s = "ape";
        // if (s!="fool") std::cout << "Success!\n";

        // 12
        // std::string s = "ape";
        // if (s.append("fool") == "apefool") std::cout << "Success!\n";

        // 13
        // std::vector<char> v(5);
        // for (int i=0; i<v.size(); ++i) ;
        // std::cout << "Success!\n";

        // 14
        // std::vector<char> v(5);
        // for (int i=0; i<v.size(); ++i) ;
        // std::cout << "Success!\n";

        // 15
        // std::string s = "Success!\n";
        // for (int i=0; i<s.size(); ++i) std::cout << s[i];

        // 16
        // if (true) std::cout << "Success!\n";
        // else std::cout << "Fail!\n";

        // 17
        // int x = 2000;
        // char c = x;
        // if (c==char(x)) std::cout << "Success!\n";

        // 18
        // std::string s = "Success!\n";
        // for (int i=0; i<s.size(); ++i) std::cout << s[i];

        // 19
        // std::vector<int> v(5);
        // for (int i=0; i<=v.size(); ++i) ;
        // std::cout << "Success!\n";

        // 20
        // int i=0; 
        // int j = 9;
        // while (i<10) ++i;
        // if (j<i) std::cout << "Success!\n";

        // 21
        // int x = 4; 
        // double d = 5.0/(x-2.0); 
        // if (d==0.5*x+0.5) std::cout << "Success!\n";

        // 22
        // std::string s = "Success!\n";
        // for (int i=0; i< s.size(); ++i) std::cout << s[i];

        // 23
        // int i=0;
        // int j = 0;
        // while (i<10) ++i; 
        // if (j<i) std::cout << "Success!\n";

        // 24
        // int x = 4;
        // double d = 5.0/(x-2.0);
        // if (d=2+0.5) std::cout << "Success!\n";

        // 25
        std::cout << "Success!\n";

        return 0;
    }
    catch (std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cout << "Unknown exception\n";
        return 2;
    }
}