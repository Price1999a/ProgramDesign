/*��ӭ����qqȺ�� 430342736��c++ primer plus����http://jq.qq.com/?_wv=1027&k=cE2SUA 
������ǳ�ѧ�ߣ���ӭ���ţ���������л����ģ���ӭ������������ǰ��������ߣ���ӭ��Ϊ����Ա�� 
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
