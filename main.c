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
#elif __APPLE__
#include <time.h>
#include <sys/sysctl.h>
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
#elif __APPLE__
    struct timeval ts;
    size_t ts_size = sizeof(ts);
    sysctl((int[]){ CTL_KERN, KERN_BOOTTIME }, 2, &ts, &ts_size, NULL, 0);
    return ts.tv_sec;
#endif
}

int main(void) {
    printf("My edging steak is %ld seconds\n", get_uptime());
}
