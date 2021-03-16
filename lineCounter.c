#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp, *fp2;
    char ch;
    int counter = 1;

    if (argc <= 2) {
        printf("\nYou did not insert the necessary parameters: lineCounter file1 file2\n*File1 is the file you want to count\n*File2 is the file you want to save the counted lines\n");
        return -1;
    }

    fp = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");

    //Verificar se os ficheiros sao validos
    if(fp != NULL && fp2 != NULL) {
        printf("\nOcorreu um erro na abertura dos ficheiros!\n");
        return -1;
    }
    //Verificar se chegou ou nao ao fim do ficheiro
    while ((ch = fgetc(fp)) != EOF)
    {
        //Verificar se e uma mudanca de linha ou a primeira linha
        if (ch == '\n' || counter == 1) {

            //Verificar se nao e a primeira linha
            if (counter > 1) {
                fprintf(fp2, "\n");
            }

            //Imprimir o n. da linha
            fprintf(fp2, "%3d - ", counter);

            //Incrementar o n. da linha
            counter++;
        }

        //Verificar se nao e o caracter \n
        if(ch != '\n')
            fprintf(fp2, "%c", ch);
    }
    return 0;
}