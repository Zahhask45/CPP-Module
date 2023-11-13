/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:59:25 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/25 16:58:04 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook_utils.hpp"

std::string	add_spaces(int n)
{
	std::string	str;

	while (n--)
		str.append(" ");
	return (str);
}

std::string	small_width(std::string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int	search_ui(Contact contacts[8])
{
	int		x;
	int			i;
	std::string	str;

	std::cout << "===============================================" << std::endl;
	std::cout << "||     Index|First Name| Last Name|  Nickname||" << std::endl;
	std::cout << "||----------|----------|----------|----------||" << std::endl;
	x = 0;
	i = 0;
	while (++x <= 8)
	{
		if (contacts[x - 1].get_fname().size() && ++i)
		{
			str = x + '0';
			str = small_width(str, 10);
			std::cout << "||" << add_spaces(10 - str.size()) << str;
			str = small_width(contacts[x - 1].get_fname(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = small_width(contacts[x - 1].get_lname(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = small_width(contacts[x - 1].get_nick(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			std::cout << "||" << std::endl;
		}
	}
	std::cout << "===============================================" << std::endl;
	return (i);
}
