#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];
    char manualStr1[50] = "Hello";
    char manualStr2[50] = "World";
    char manualCopy[50];
    
    printf("--- Built-in Functions ---\n");
    printf("Length of '%s': %lu\n", str1, strlen(str1));
    
    strcpy(str3, str1);
    printf("Copy: %s\n", str3);
    
    strcat(str1, str2);
    printf("Concatenation: %s\n", str1);
    
    if(strcmp(str1, str3) != 0) printf("Comparison: Strings are different\n");

    printf("\n--- Without Built-in Functions ---\n");
    
    int len = 0;
    while(manualStr1[len] != '\0') {
        len++;
    }
    printf("Length of '%s': %d\n", manualStr1, len);

    int i = 0;
    while(manualStr1[i] != '\0') {
        manualCopy[i] = manualStr1[i];
        i++;
    }
    manualCopy[i] = '\0';
    printf("Copy: %s\n", manualCopy);

    int j = 0;
    while(manualStr2[j] != '\0') {
        manualStr1[len + j] = manualStr2[j];
        j++;
    }
    manualStr1[len + j] = '\0';
    printf("Concatenation: %s\n", manualStr1);

    return 0;
}