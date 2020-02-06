/**
 * @file
 * Send email to an SMTP server
 *
 * @authors
 * Copyright (C) 2018 Richard Russon <rich@flatcap.org>
 * Copyright (C) 2019 Pietro Cerutti <gahr@gahr.ch>
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

#ifndef MUTT_SMTP_H
#define MUTT_SMTP_H

#include "config.h"
#include <stdbool.h>

/* These Config Variables are only used in smtp.c */
extern struct Slist *C_SmtpAuthenticators;
extern char *C_SmtpOauthRefreshCommand;
extern char *C_SmtpPass;
extern char *C_SmtpUser;

#ifdef USE_SMTP
struct AddressList;

int mutt_smtp_send(const struct AddressList *from, const struct AddressList *to,
                   const struct AddressList *cc, const struct AddressList *bcc,
                   const char *msgfile, bool eightbit);
#endif

#endif /* MUTT_SMTP_H */
