/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:03:39 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/25 16:57:42 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include "PhoneBook_utils.hpp"

class PhoneBook
{
	private:
		Contact	_cont[8];
		int		_index;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add(void);
		void search(void);
		void print(Contact contact);
		Contact get_contact(int index);
};


#endif
