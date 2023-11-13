/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:42:23 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/25 16:41:53 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv){

	if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int x = 0; argv[i][x] != '\0'; x++)
		{
			std::cout << char(toupper(argv[i][x]));
		}
	}
	std::cout << std::endl;
	return (0);
}
