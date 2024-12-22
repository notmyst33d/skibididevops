/*
 * Copyright (c) 2024 Myst33d.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

#ifdef __linux__
#include <sys/sysinfo.h>
#elif _WIN32
#include <windows.h>
#else
#error "Unsupported platform"
#endif

long get_uptime() {
#ifdef __linux__
    struct sysinfo info;
    sysinfo(&info);
    return info.uptime;
#elif _WIN32
    return GetTickCount64() / 1000;
#endif
}

int main(void) {
    printf("My edging steak is %ld seconds\n", get_uptime());
}
