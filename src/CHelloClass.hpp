///-------------------------------------------------------------------------------------------------
/// 
/// \file CHelloClass.hpp
/// \brief Hello World Class file.
/// \author Thibaut Monseigne.
/// \version 1.0.
/// \date 29/04/2019.
/// \copyright <a href="https://choosealicense.com/licenses/agpl-3.0/">GNU Affero General Public License v3.0</a>.
/// 
///-------------------------------------------------------------------------------------------------

#pragma once
#include <ostream>
#include <iostream>


/// <summary> Hello World Class. </summary>
class CHelloClass
{
public:
	/// <summary> Great member a. </summary>
	int a = 0;
	
	/// <summary> Default constructor. Initializes a new instance of the <see cref="CHelloClass"/> class. </summary>
	CHelloClass() { std::cout << "Great constructor" << std::endl; }
	/// <summary> Finalizes an instance of the <see cref="CHelloClass"/> class. </summary>
	~CHelloClass() { std::cout << "Great destructor" << std::endl; }
	/// <summary> Default copy constructor (default option make a trivial constructor). Initializes a new instance of the <see cref="CHelloClass"/> class. </summary>
	/// <param name="obj">	The object.</param>
	CHelloClass(CHelloClass& obj) = default;
	/// <summary> Default move constructor (delete option disable move constructor). </summary>
	/// <param name="obj">	The object.</param>
	CHelloClass(CHelloClass&& obj) = delete;
	
	/// <summary> Adds the specified b with a hard formula : \f$ a = a + b \f$ </summary>
	/// <param name="b">The value to addition.</param>
	void add(const int b) { a += b; }
	/// <summary> Subs the specified b with a hard formula :
	/// \f[
	/// a = a - b
	/// \f]
	/// </summary>
	/// <param name="b">The value to substract.</param>
	void sub(const int b) { a -= b; }

	/// <summary> Default copy operator (default option make a trivial operator). </summary>
	/// <param name="obj">The object to copy. </param>
	/// <returns> The copied object. </returns>
	CHelloClass& operator=(const CHelloClass& obj) = default;
	/// <summary> Default move operator (delete option disable move operator). </summary>
	/// <param name="obj">The object to move. </param>
	/// <returns> nothing (it's delete). </returns>
	CHelloClass& operator=(const CHelloClass&& obj) = delete;
};

