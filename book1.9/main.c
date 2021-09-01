#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

//кодировка ЮТФ8
/*getLine: считывает строку в line, возвращает ее длину*/
int getLine(char line[], int maxLine);
/*copy: копирует строку 'from' в 'to'; длина to считается достаточной*/
void copy(char to[], char from[]);

/*
    вывод самой длинной строки в потоке
*/

int main()
{
    /*длина текущей строки*/
    int len;

    /*текущая максимальная длина*/
    int max;

    /*текущая введенная строка*/
    char line[MAXLINE];

    /*самая длинная строка из введенных*/
    char longest[MAXLINE];

    max = 0;
    while((len = getLine(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }

    /*если была непустая строка*/
    if(max > 0) printf("%s", longest);
    return 0;
}

/*
    getLine: считывает строку в s, возвращает ее длину
    s является указателем на начало массива (не копируется),
    поэтому значения s можно изменять в функции
*/
int getLine(char s[], int lim){
    int c, index;

    for(index = 0; index < lim-1 && (c = getchar()) != EOF && c != '\n'; ++index)
        s[index] = c;

    if(c == '\n'){
        s[index] = c;
        ++index;
    }

    s[index] = '\0';
    return index;
}

/*
    copy: копирует строку 'from' в 'to'; длина to считается достаточной
*/
void copy(char to[], char from[]){
    int index;
    index = 0;

    while((to[index] = from[index]) != '\0') ++index;
}
