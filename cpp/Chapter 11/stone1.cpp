
/*��ӭ����qqȺ�� 430342736��c++ primer plus����http://jq.qq.com/?_wv=1027&k=cE2SUA 
������ǳ�ѧ�ߣ���ӭ���ţ���������л����ģ���ӭ������������ǰ��������ߣ���ӭ��Ϊ����Ա�� 
*/
// stone1.cpp -- user-defined conversion functions
// compile with stonewt1.cpp
#include <iostream>
#include "stonewt1.h"

int main()
{
    using std::cout;
    Stonewt poppins(9,2.8);     // 9 stone, 2.8 pounds
    double p_wt = poppins;      // implicit conversion
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";
	// std::cin.get();
    return 0; 
}
