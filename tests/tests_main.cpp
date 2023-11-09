/*
 * tests_main.cpp
 *
 * Copyright 2009-2021
 * Giuseppe Penone <giuspen@gmail.com>
 * Evgenii Gurianov <https://github.com/txe>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include "gtest/gtest.h"
#include "ct_filesystem.h"

#ifdef _WIN32
static void _glib_log_handler(const gchar*, GLogLevelFlags, const gchar*, gpointer)
{
}
#endif // _WIN32

int main(int argc, char** argv)
{
#ifdef _WIN32
    g_log_set_default_handler(_glib_log_handler, nullptr);
#endif // _WIN32
    fs::register_exe_path_detect_if_portable(argv[0]);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
