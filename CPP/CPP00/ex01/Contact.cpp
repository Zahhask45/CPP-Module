/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:03:05 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/25 17:01:30 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}
std::string Contact::get_fname(void) const
{
	return (this->_fname);
}

std::string Contact::get_lname(void) const
{
	return (this->_lname);
}

std::string Contact::get_nick(void) const
{
	return (this->_nick);
}

std::string Contact::get_phone_num(void) const
{
	return (this->_phone_num);
}

std::string Contact::get_secret(void) const
{
	return (this->_secret);
}

void Contact::set_fname(std::string str)
{
	this->_fname = str;
}

void Contact::set_lname(std::string str)
{
	this->_lname = str;
}

void Contact::set_nick(std::string str)
{
	this->_nick = str;
}

void Contact::set_phone_num(std::string str)
{
	this->_phone_num = str;
}

void Contact::set_secret(std::string str)
{
	this->_secret = str;
}
