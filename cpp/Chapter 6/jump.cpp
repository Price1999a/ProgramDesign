/*��ӭ����qqȺ�� 430342736��c++ primer plus����http://jq.qq.com/?_wv=1027&k=cE2SUA 
������ǳ�ѧ�ߣ���ӭ���ţ���������л����ģ���ӭ������������ǰ��������ߣ���ӭ��Ϊ����Ա�� 
*/

// jump.cpp -- using continue and break
#include <iostream>
const int ArSize = 80;
int main()
{
    using namespace std;
    char line[ArSize];
    int spaces = 0; 

    cout << "Enter a line of text:\n";
    cin.get(line, ArSize);
    cout << "Complete line:\n" << line << endl;
    cout << "Line through first period:\n";
    for (int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];    // display character
        if (line[i] == '.') // quit if it's a period
            break;
        if (line[i] != ' ') // skip rest of loop
            continue;
        spaces++;
    }
    cout << "\n" << spaces << " spaces\n";
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}
