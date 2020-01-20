#include <stdio.h>

void helloWorld(){
    printf("Hello World!");
    return;
}

void exercise2(){
    printf("Hello, I am going to test what happens ");
    printf("if I include \\c chars: ");
    printf("\3 \6 \a \l");
    printf("\n only \\l was printed, the rest were spaces");
}

// Variables and arithmetic expressions
// While loops, floating point operations and formatting output
void exercise3(){
    printf("Table conversion from Farenheit to Celsius \n");
    int lower, upper, step;
    float celsius, farenheit;

    lower = 0;
    upper = 200;
    step = 20;

    while (lower <= upper){
        farenheit = lower;
        celsius = (farenheit - 32) * (5.0 / 9);
        printf("%6.2f %8.2f \n", farenheit, celsius);
        lower += step;
    }
}

void exercise4(){
    printf("Table conversion from Celsius to Farenheit \n");
    int lower, upper, step;
    lower = 0;
    upper = 200;
    step = 20;

    while (lower <= upper){
        printf("%6.2f %8.2f \n", lower * 1.0, lower * 9.0/5 + 32);
        lower += step;
    }
}

// The for statement

void exercise5(){
    printf("Table conversion from Farenheit to Celsius \n");
    int upper = 300;
    int lower = 0;
    int step = 20;
    int fahr;
    for(fahr= upper; fahr >= lower; fahr -= step){
        printf("%6.2f %8.2f \n", fahr * 1.0, (fahr - 32) * 5.0/9);
    }
}

// Symbolic Constants
#define LOWER 0
#define UPPER 300
#define STEP 20

void exercise6(){
    printf("Table conversion from Farenheit to Celsius \n");
    int fahr;
    for(fahr= UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%6.2f %8.2f \n", fahr * 1.0, (fahr - 32) * 5.0/9);
    
}

// Character input and output

// getchar(c) and putchar(c)

void fileCopy(){
    int c;

    while ((c  = getchar()) != EOF)
        putchar(c);

    printf("Once I am done I print the value for EOF: ");
    printf("%d", EOF);
    // not printing any value, check type of EOF, supposed to be a -1
}

void characterCounting(){
    int c;
    double count = 0;

    while ((c = getchar()) != EOF)
        ++count;
    printf("The number of characters are: %.0f", count);
}

void exercise8(){
    int c;
    int newLines = 0;
    int blanks = 0;
    int tabs = 0;

    while((c = getchar()) != EOF){
        switch(c){
            case '\n':
                ++newLines;
                break;
            case ' ':
                ++blanks;
                break;
            case '\t':
                ++tabs;
                break;
            default:
                break;
        }
    }
    printf("The number of tabs are: %d \n", tabs);
    printf("The number of lines are: %d \n", newLines);
    printf("The number of blanks are: %d \n", blanks);
}

// copy input into output removing multiple blanks
void exercise9(){
    int c;
    int previousWasBlank = 0;
    while ((c  = getchar()) != EOF){
        if (c == ' '){
            if (!previousWasBlank){
                putchar(c);
                previousWasBlank = 1;
            }
        }else{
            putchar(c);
            previousWasBlank = 0;
        }
    }
}

void wordCounting(){
    int c;
    int count = 0;
    int inside = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\n'){
            if(inside){
                ++count;
                inside = 0;
            }
        }else{
            inside = 1;
        }
    }
    printf("The number of words is: %d", count);
}


void wordCounting2(){
    #define IN 1
    #define OUT 0
    
    int c, nwords, nlines, nchars, state;
    state = OUT;
    nwords = nlines = nchars = 0;

    while ((c = getchar()) != EOF){
        ++nchars;
        if(c == '\n') ++nlines;
        if(c==' ' || c=='\t' || c=='\n') state = OUT;
        else if (state == OUT){
            nwords ++;
            state = IN;
        }
    }
    printf("chars %d, words %d and lines %d", nchars, nwords, nlines);
}

void exercise12(){
    #define IN 1
    #define OUT 0
    int c, state;
    state = OUT;

    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == IN)
            putchar(c);
        else {
            state = IN;
            putchar('\n');
            putchar(c);
        }
    }
}

// Arrays

void countOcurrencesOfEachDataType(){
    int nother, nwhite, c, i;
    nother = nwhite = 0;
    int ndigit[10];

    for (i; i<10; i++)
        ndigit[i] = 0;

    while((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else 
            ++nother; 
    }
    printf("Digits =");
    for (i=0; i<10; i++)
        printf(" %d", ndigit[i]);
    printf("\n Whites = %d", nwhite);
    printf("\n Others = %d", nother);
    
}

// Histogram of length of words\
// needs to be tested too
void exercise13(){
    #define IN 1
    #define OUT 0
    #define MAXLENGTH 10

    int c, state, wordLength, i;
    wordLength = i = 0;
    state = OUT;
    int histogram[MAXLENGTH];

    for(i; i<MAXLENGTH; ++i)
        histogram[i] = 0;


    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
            ++histogram[wordLength];
            wordLength = 0;
        }
        else if (state == IN)
            ++wordLength;
        else {
            state = IN;
            ++wordLength;
        }
    }

    int j;
    for(i=0; i<MAXLENGTH; ++i){
        printf("%d: ", i);
        for(j=0; j<histogram[i]; ++j){
            printf("|");
        }
        printf("\n");
    }
}

// Vertical Histogram
void exercise13_2(){
    #define IN 1
    #define OUT 0
    #define MAXLENGTH 10
    #define MAXWORDS 5

    int c, state, wordLength, i;
    wordLength = i = 0;
    state = OUT;
    int histogram[MAXLENGTH];

    for(i; i<MAXLENGTH; ++i)
        histogram[i] = 0;


    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
            ++histogram[wordLength];
            wordLength = 0;
        }
        else if (state == IN)
            ++wordLength;
        else {
            state = IN;
            ++wordLength;
        }
    }
    int max = histogram[0];
    for(i=0; i<MAXLENGTH; ++i){
        printf("%d", histogram[i]);
        if(histogram[i] > max)
            max = histogram[i]; 
    }
    printf("\n");

    int j;
    for(max; max>0; --max){
        for(j=0; j<MAXLENGTH; ++j){
            if(histogram[j] >= max) printf("_");
            else printf(" ");
            printf(" ");
        }
        printf("\n");
    }
    for(j=0; j<MAXLENGTH; ++j){
        printf("%d ", j);
    }
}

// Functions
int power (int base, int exponent){
    int result = 1;
    for (exponent; exponent > 0; --exponent)
        result *= base;
    return result;
}

// Arguments - call by value

// Character arrays
void longestLine1(){
    #define MAXLENGTH 255
    int c, i, currentLength, longestLength;
    char line[MAXLENGTH];
    char longestLine[MAXLENGTH];
    currentLength = longestLength = 0;

    while((c = getchar()) != EOF){
        if(c != '\n'){
            line[currentLength] = c;
            ++currentLength;
        }else{
            line[currentLength] = '\0';
            if(currentLength > longestLength){
                longestLength = currentLength;
                i = 0;
                while(line[i] != '\0'){
                    longestLine[i] = line[i];
                    ++i;
                }
                longestLine[i] = line[i];
            }
            currentLength = 0;
        }
    }
    printf("The longest sentence is: %s \n", longestLine);
    printf("The length is: %d", longestLength);
}
int getline(char line[], int maxline);
int copy(char to[], char from[]);

int getline(char s[], int lim){
    int i, c;
    for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;    
}

int copy(char to[], char from[]){
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;        
}


void longestLine2(){
    #define MAXLENGTH 255
    int c, i, currentLength, longestLength;
    longestLength = 0;
    char line[MAXLENGTH];
    char longestLine[MAXLENGTH];
    
    while ((currentLength = getline(line, MAXLENGTH)) > 0){
        if (currentLength > longestLength){
            copy(longestLine, line);
            longestLength = currentLength;
        }
    }

    if (longestLength > 0)
        printf("With length %d the longest sentence is: %s",longestLength, longestLine);
    
}

int main (){
    exercise13_2();
    return 0;
}