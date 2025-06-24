#include <stdio.h>
#include <ctype.h>
#include <string.h>
//list of keywords
char keywords[32][10] = {
    "auto", "break","case","char","const","continue","default","do",
    "double","else","enum","extern","float","for","goto","if","int",
    "long","register","return","short","signed","sizeof","static",
    "struct","switch","typedef","union","unsigned","void","volatile",
    "while"
};
//function to check if a word is a keyword
int isKeyword(char *word){
    for (int i =0; i<32; i++){
        if (strcmp(word,keywords[i])==0)
            return 1;
    }
    return 0;
}
//Main function
int main(){
    char ch, buffer[20];
    FILE *fp;
    int i,j=0;
    //Open input file in read mode
    fp=fopen("input.txt","r");
    if (fp==NULL){
        printf("Error:Cannot open file\n");
        return 1;
    }
    //Read file character by character
    while ((ch = fgetc(fp)) != EOF){
        //check for identifiers or keywords
        if (isalnum(ch)){
            buffer[j++]=ch;
        }
        else if((ch==' ' || ch=='\n') && j !=0){
            buffer[j] = '\0';
            j=0;
            //check if it's a keyword
            if (isKeyword(buffer))
                printf("%s-->Keyword\n",buffer);
            else 
                printf("%s-->Identifier\n",buffer);
        }
        //check for operators
        if (ch=='+' || ch=='-' ||ch=='*' || ch=='/' ||ch=='=' || ch=='<' ||
             ch=='>' || ch=='!'){
            printf("%c --> Operator\n",ch);
        }
    }
    fclose(fp);
    return 0;
}