/*欢迎加入qq群： 430342736【c++ primer plus】：http://jq.qq.com/?_wv=1027&k=cE2SUA 
如果你是初学者，欢迎入门，如果你是有基础的，欢迎提升，如果你是案例操作者，欢迎成为管理员。 
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
vector<string> input;
string temp;
while (cin >> temp && temp != "quit")
    input.push_back(temp);
vector<string>::iterator want=
    find(input.begin(), input.end(), string("bonus"));
if (want != input.end())
{
    vector<string>::reference r = *want;
    r = "bogus";
}
for_each(input.begin(), input.end(), [](string s){cout << s << ", ";});
cin.get();
cin.get();
}
