#include <unistd.h>

int main()
{
    char msg[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    int len = sizeof(msg) - 1;
    write(2, msg, len);
    return 1;
}
