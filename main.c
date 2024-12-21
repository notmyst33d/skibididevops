#include <stdio.h>
#include <sys/sysinfo.h>

int main(void) {
    struct sysinfo info;
    sysinfo(&info);
    printf("My edging steak is %ld seconds\n", info.uptime);
}
