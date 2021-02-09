

#include <iostream>

int main()
{
    char str1[] = "аааа";
    char str2[] = "аааб";
    char Zero[] = "0";
    char One[] = "1";
    char MinusOne[] = "-1";
    char fd[] = "%s";
    __asm
    {
        lea ebx, str1

        lea ecx, str2

        dec ecx

        dec ebx

        FirstCompare:
                inc ebx
                inc ecx
                mov al,[ebx]
                mov dl,[ecx]
                cmp al,0
                je SecondCompare
                cmp dl,0
                je OutputMinusOne
                cmp al,dl
                je FirstCompare
                jb OutputOne
                jmp OutputMinusOne
        SecondCompare:
            cmp dl,0
            je OutputZero
            jmp OutputOne

        OutputZero:
            lea ebx,Zero
            push ebx
            lea ecx, fd
            push ecx
            call printf
            add esp,8
            jmp End

        OutputOne:
            lea ebx, One
            push ebx
            lea ecx, fd
            push ecx
            call printf
            add esp, 8
            jmp End

        OutputMinusOne:
            lea ebx, MinusOne
            push ebx
            lea ecx, fd
            push ecx
            call printf
            add esp, 8
            jmp End

        End:


            



        


    }
   

   
}

