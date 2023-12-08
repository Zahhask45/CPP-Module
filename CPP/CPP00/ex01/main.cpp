/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:05:05 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/12/08 14:17:21 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <stdlib.h> 

#define END		"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

void	menu()
{
	std::cout << "========================================================================" << std::endl;
	std::cout << "||                              MENU                                  ||" << std::endl;
	std::cout << "||   INSERT -> \"ADD\" TO ADD                                           ||" << std::endl;
	std::cout << "||   INSERT -> \"SEARCH\" TO SEARCH                                     ||" << std::endl;
	std::cout << "||   INSERT -> \"EXIT\" TO EXIT                                         ||" << std::endl;
	std::cout << "========================================================================" << std::endl;
}


int main(){
	PhoneBook ph1;
	std::string	str;

	menu();
	while (1){
		std::cout << "INSERT HERE -> ";
		std::cin >> str;
		if (std::cin.fail())
			return (std::cout << "\n", 1);
		if (str == "ADD"){
			system("clear");
			ph1.add();
			menu();
		}
		else if ((str == "SEARCH")){
			system("clear");
			ph1.search();
			menu();
		}
		else if ((str == "EXIT"))
			return (0);
	}
}
