/*欢迎加入qq群： 430342736【c++ primer plus】：http://jq.qq.com/?_wv=1027&k=cE2SUA 
如果你是初学者，欢迎入门，如果你是有基础的，欢迎提升，如果你是案例操作者，欢迎成为管理员。 
*/

// carrots.cpp -- food processing program
// uses and displays a variable

#include <iostream>

int main()
{
    using namespace std;
    
    int carrots;            // declare an integer variable
    
    carrots = 25;            // assign a value to the variable
    cout << "I have ";
    cout << carrots;        // display the value of the variable
    cout << " carrots.";
    cout << endl;
    carrots = carrots - 1;  // modify the variable
    cout << "Crunch, crunch. Now I have " << carrots << " carrots." << endl;
    // cin.get();
	return 0;
}
