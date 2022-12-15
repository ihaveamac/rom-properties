/***************************************************************************
 * ROM Properties Page shell extension. (GTK+ common)                      *
 * ConfigDialog.hpp: Configuration dialog.                                 *
 *                                                                         *
 * Copyright (c) 2017-2022 by David Korth.                                 *
 * SPDX-License-Identifier: GPL-2.0-or-later                               *
 ***************************************************************************/

#ifndef __ROMPROPERTIES_GTK_CONFIG_CONFIGDIALOG_HPP__
#define __ROMPROPERTIES_GTK_CONFIG_CONFIGDIALOG_HPP__

#include "gtk-compat.h"

G_BEGIN_DECLS

#define RP_TYPE_CONFIG_DIALOG (rp_config_dialog_get_type())
G_DECLARE_FINAL_TYPE(RpConfigDialog, rp_config_dialog, RP, CONFIG_DIALOG, GtkDialog)

GtkWidget	*rp_config_dialog_new		(void) G_GNUC_INTERNAL G_GNUC_MALLOC;

G_END_DECLS

#endif /* __ROMPROPERTIES_GTK_CONFIG_CONFIGDIALOG_HPP__ */
