#include <stdio.h>

int len(char s[]);    // calculate the length of an array.
char randomNum0To9(); // using the last digit of the cpu clock speed (in KHz) to generate random number!

char randomNum0To9()
{
    int length; // length of the array.
    length = 0;

    // ------------ open the file.
    FILE *fp = fopen("/sys/devices/system/cpu/cpu1/cpufreq/scaling_cur_freq", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    char line1[8]; // first line of the file. (thread2's frequency)
    fgets(line1, 8, fp);
    fclose(fp);
    // ------------ file closed.

    length = len(line1);
    return line1[length - 1]; // return the last character of the line. (thread1_frequency % 10)
}

int len(char s[]) // calculate the length of an array.
{
    int length;
    length = 0;

    while (s[length])
        ++length;

    --length; // because the last character is '\0' or EOF.

    return length;
}