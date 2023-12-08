/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:03:15 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/12/08 14:07:08 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	std::cout << \
		"Welcome to Crappy! Created an empty phonebook for up to 8 contacts" \
		<< std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "See you soon!" << std::endl;
}

void	PhoneBook::add(void)
{
	std::string	str;

	//* FIRST NAME 
	str = "";
	std::cin.ignore();
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a first name: ";
		if (std::cin >> str && str != "")
			this->_cont[this->_index % 8].set_fname(str);
	}

	//* LAST NAME 
	str = "";
	std::cin.ignore();
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_cont[this->_index % 8].get_fname() << " last name: ";
		if (std::cin >> str && str != "")
			this->_cont[this->_index % 8].set_lname(str);
	}

	//* NICKNAME 
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_cont[this->_index % 8].get_fname() << " nickname: ";
		std::cin.ignore();
		if (std::getline(std::cin, str) && str != "")
			this->_cont[this->_index % 8].set_nick(str);
	}

	//* PHONE NUMBER 
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_cont[this->_index % 8].get_fname() << " phone number: ";
		if (std::cin >> str && str != ""){
			if (str.length() == 9 && str.find_first_not_of("0123456789") != 0)
				this->_cont[this->_index % 8].set_phone_num(str);
			else
				str = "";
		}
	}

	//* DARKEST SECRET 
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_cont[this->_index % 8].get_fname() << " darkest secret: ";
		std::cin.ignore();
		if (std::getline(std::cin, str) && str != "")
			this->_cont[this->_index % 8].set_secret(str);
	}

	std::cout << "Added another contact to the  position (" << this->_index % 8 + 1 << "/8) on the Phonebook"  << std::endl;
	this->_index++;
}

void	PhoneBook::search(void)
{
	std::string	str;

	if (!search_ui(this->_cont))
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return ;
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Select an index: ";
		if (std::cin >> str && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' &&
					this->_cont[str[0] - 1 - '0'].get_fname().size())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
		str = "";
	}
	print(this->_cont[str[0] - 1 - '0']);
}

void	PhoneBook::print(Contact contact)
{
	std::cout << "First name: " << contact.get_fname() << std::endl;
	std::cout << "Last name: " << contact.get_lname() << std::endl;
	std::cout << "Nickname: " << contact.get_nick() << std::endl;
	std::cout << "Phone number: " << contact.get_phone_num() << std::endl;
	std::cout << "Darkest secret: " << contact.get_secret() << std::endl;
}
