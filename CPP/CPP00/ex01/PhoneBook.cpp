/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:03:15 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/16 17:08:09 by jodos-sa         ###   ########.fr       */
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
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		std::cin.ignore();
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
					this->_cont[str[0] - 1 - '0'].get_fname().size())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	/* if (!std::cin.eof())
		this->print(this->_cont[str[0] - 1 - '0']); */
}
