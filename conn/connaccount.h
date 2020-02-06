/**
 * @file
 * ConnAccount object
 *
 * @authors
 * Copyright (C) 2000-2005,2008 Brendan Cully <brendan@kublai.com>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MUTT_CONN_ACCOUNT_H
#define MUTT_CONN_ACCOUNT_H

#include "mutt_account.h"

/**
 * enum ConnAccountField - Login credentials
 */
enum ConnAccountField
{
  MUTT_CA_HOST = 1,  ///< Server name
  MUTT_CA_LOGIN,     ///< Login name
  MUTT_CA_USER,      ///< User name
  MUTT_CA_PASS,      ///< Password
  MUTT_CA_OAUTH_CMD, ///< OAuth refresh command
};

/**
 * typedef ca_get_field_t - Prototype for a function to get some login credentials
 * @param field Field to get, e.g. #MUTT_CA_PASS
 * @retval ptr Requested string
 */
typedef const char *(*ca_get_field_t)(enum ConnAccountField field);

/**
 * struct ConnAccount - Login details for a remote server
 */
struct ConnAccount
{
  char user[128];
  char login[128];
  char pass[256];
  char host[128];
  unsigned short port;
  unsigned char type;     ///< Connection type, e.g. #MUTT_ACCT_TYPE_IMAP
  MuttAccountFlags flags; ///< Which fields are initialised, e.g. #MUTT_ACCT_USER
  const char *service;    ///< Name of the service, e.g. "imap"

  ca_get_field_t get_field; ///< Function to get some data
};

#endif /* MUTT_CONN_ACCOUNT_H */
