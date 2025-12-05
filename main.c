/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:23:47 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/11/29 15:23:47 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

// int print_all(int count , ...)
// {
//     va_list args ; // rest param ...
//     va_start(args,count); // read args after count 

//     int result = 0 ; 
//     for (size_t i = 0; i < count; i++)
//     {
//         result += va_arg(args, int); // add just args type int ;
//     }
//     va_end(args);
//     return result;
// }


// void print_all_2(char *test, ...)
// {
//     va_list args ; // rest param ...
//     va_start(args,test); // read args after count 

//     printf("---------- \n") ;
//     for (size_t i = 0; test[i]; i++)
//     {
//         if (test[i] == 'i')
//         {
//             printf("---------- \n") ;
//             printf("%d\n", va_arg(args, int));
//         }else if (test[i] == 'c')
//         {
//             printf("%c\n", va_arg(args, int));
//         }else if (test[i] == 's')
//         {
//             printf("%s\n", va_arg(args, char *));
//         }else if (test[i] == 'f')
//         {
//             printf("%f\n", va_arg(args, double));
//         }
//         // result += va_arg(args, int); // add just args type int ;
//     }
//     va_end(args);
// }

// int main()
// {
//     print_all_2("test",'a', 20 , 5); 
// }   



#include <stdio.h>
#include <stdarg.h>
void sum(char *format, ...)
{
    va_list args;
    va_start(args, format);

    int sum = 0 ;
    for (size_t i = 0; format[i]; i++)
    {
        if (format[i] == 'i')
        {
            printf("%d\n" , va_arg(args , int)) ;
        }else if (format[i] == 'c')
        {
            printf("%c\n" , va_arg(args , int)) ;
        }else if (format[i] == 's')
        {
            printf("%s\n" , va_arg(args , char *)) ;
        }
        
    }

    va_end(args);
    
}

int main()
{
    sum( "cspdiuxX%" , 'a', 20 ,5); 
}   

