/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:03:44 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/25 17:10:51 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class Contact
{
	private:
		std::string _fname;
		std::string _lname;
		std::string _nick;
		std::string _phone_num;
		std::string _secret;

	public:
		Contact(void);
		~Contact(void);
		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nick(void) const;
		std::string	get_phone_num(void) const;
		std::string	get_secret(void) const;

		void	set_fname(std::string);
		void	set_lname(std::string);
		void	set_nick(std::string);
		void	set_phone_num(std::string);
		void	set_secret(std::string);
};

#endif
