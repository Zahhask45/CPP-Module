/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:59:42 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/25 16:57:39 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_HPP
#define PHONEBOOK_UTILS_HPP

#include "contact.hpp"

int	search_ui(Contact contacts[8]);

std::string	small_width(std::string str, long unsigned max);

std::string	add_spaces(int n);

#endif
