/*
 *主要针对string.h中字符串处理的strlen/strcmp和strcat以及strcpy的实现；
 */
/* $Copyright: $
 * Copyright (c) 2014 - 2014 by Law Yu (huaixiaoz@outlook.com)
 * All Rights reserved
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>

int _strlen(char *str)
{
    int i= 0;
    while(*str)
    {
        i++;
        str++;
    }
    return i;
}

int _strcmp(char *str1, char *str2)
{
    if(str1 == NULL || str2 == NULL)
        return -1;
    while(*str1 == *str2)
    {
        if(*str1 == '\0')  // *str1 == 0
            return 0;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *_strcpy(char *dest, char *src)
{
    char *buf = dest;
    while((*dest++ = *src++))
        ;
    return buf;
}

char *_strcat(char *dest, char *src)
{
    if(sizeof(dest) - _strlen(dest) < _strlen(src))
    {
        printf("!!alert : not enough space of dest for src !\n");
        return dest;
    }
    char *buf = dest;
    while(*dest)
        dest++;
    _strcpy(dest, src);
    return buf;
}
