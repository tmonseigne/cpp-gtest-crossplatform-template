///-------------------------------------------------------------------------------------------------
/// 
/// \file main.cpp
/// \brief main file.
/// \author Thibaut Monseigne.
/// \version 1.0.
/// \date 29/04/2019.
/// \copyright <a href="https://choosealicense.com/licenses/agpl-3.0/">GNU Affero General Public License v3.0</a>.
/// 
///-------------------------------------------------------------------------------------------------

#include "CHelloClass.hpp"

using namespace std;

int main(int argc, char** argv)
{
	CHelloClass obj;
	cout << "Value is : " << obj.a << endl;
	obj.add(10);
	cout << "Value is : " << obj.a << endl;
	obj.sub(5);
	cout << "Value is : " << obj.a << endl;
	return 0;
}