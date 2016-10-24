//
//  main.c
//  15.d
//
//  Created by Chad Wiedemann on 6/7/16.
//  Copyright © 2016 TurnToTech. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <float.h>
#include <limits.h>

long int_maximum = INT_MAX;

int stringLength(char string[]){
    
    int i=0;
    while (string[i]!='\0'){
        i++;
    }//end of while loop
    return i;
}

//15.d
int findWord(char stringLong[], char stringShort[]){
    int i=0;
    while (stringLong[i]!='\0'){
        i++;
    }
    int j=0;
    while (stringShort[j]!='\0'){
        j++;
    }
    int y = 0; //the position of indiifferent
    int x=0;
    for(int k = 0;k<=i;k++){
        x =0;
        if(stringLong[k]==stringShort[x]){
            while(stringLong[k+x]==stringShort[x]){
                if(x==j-1){
                    y= k+1;
                }
                x++;
            }
        }
    
    }
    return y;
}

//15.g
void replaceIndifferent(char quote[]){
    char nonchalant[]="nonchalant";
    char firstHalf[67];
    char secondHalf[33];
    int position = findWord(quote, "t retort");
    for (int x=0; x <= 33; x++){
        secondHalf[x] = quote[position+x];
    }
    for(int y=0;y<=67;y++){
        firstHalf[y]=quote[y];
    }
    char newArray[114];
    
    int counter=0;
    for (int a=0;a<=67;a++){
        newArray[a]=quote[a];
        counter++;
    }
    for (int b=0;b<=9;b++){
        newArray[counter]=nonchalant[b];
        counter++;
    }
    for (int c=0;c<=33;c++){
        newArray[counter]=secondHalf[c];
        counter++;
    }
}

//15.h
void replaceWords(char paragraph[], char oldWord[], char newWord[]){
    int parLength = stringLength(paragraph);
    int newWordLength = stringLength(newWord);
    int oldWordLength = stringLength(oldWord);
    int wordLengthDifference= oldWordLength-newWordLength;
    int newParLength = parLength-wordLengthDifference;
    int oldWordPosition=findWord(paragraph, oldWord);//isnt accurate
    int lastLegPosition=oldWordPosition+oldWordLength;
    int remainderOfParagraph=oldWordPosition+oldWordLength;
    char *newMemory;
    newMemory=(char *) malloc(newParLength);
    int counter=0;
    for(int a=0;a<=oldWordPosition-2;a++){
        newMemory[a]=paragraph[a];
        counter++;
    }
    for(int b=0;b<=newWordLength-1;b++){
        newMemory[counter]=newWord[b];
        counter++;
    }
    for(int c=0;c<=(newParLength-newWordLength-oldWordPosition);c++){
        newMemory[counter]=paragraph[remainderOfParagraph+c-1];
        counter++;
    }
    printf("%s\n",newMemory);
}


//15 i.
void arrayToString(char *arrayOfStrings[]){
//char *arrayOfStrings[6]={"USA","Canada","Mexico","Bermuda","Grenada","Belize"};
int total1=0;
for(int i=0;i<6;i++){
    total1=total1+stringLength(arrayOfStrings[i]);
}
char *concatenatedString;
concatenatedString=(char *) malloc(total1 * sizeof(char));
int counter=0;
for(int i=0;i<6;i++){
    for(int j=0;j<stringLength(arrayOfStrings[i]);j++){
        concatenatedString[counter]=arrayOfStrings[i][j];
        counter+=1;
    }
}
//char countries[]={"USA. Canada, Mexico, Bermuda  Grenada, Belize"};
//twoDemensionalArray(countries);
printf("%s\n",concatenatedString);
}

//15.j-l
int isDelimiter(char character){
    char separators[]={'.',',',' '};
    for (int i=0;i < 3;i++){
        if (separators[i] == character){
            return 1;
        }
    }
    return 0;
}

void twoDemensionalArray(char string[]){
    int lengthOfCountryString=stringLength(string);
    int commaCount=0;
    
    for(int i=0;i<=lengthOfCountryString;i++){
        if (isDelimiter(string[i])==1){
            commaCount++;
        }
    }
    int counter=0;
    int longestElement=0;
    for(int i=0;i<=lengthOfCountryString;i++){
        if (isDelimiter(string[i])==0){
            counter++;
        }else if (longestElement<counter){
            longestElement=counter;
            counter=0;
        }else {counter=0;}
    }
    char **arrayOfStrings=malloc((commaCount+1)*sizeof(char*));
    int letterCounter=0;
    int j=0;
    int counter2=0;
    arrayOfStrings[0] = malloc((longestElement)*sizeof(char*));
    for(int i=0;i<=lengthOfCountryString;i++){
        
        if(isDelimiter(string[counter2])==0){//put a for loop in here to loop through delimiters
            arrayOfStrings[j][letterCounter]=string[counter2];
            letterCounter++;
            counter2++;
        } else {
            j++;
            arrayOfStrings[j] = malloc((longestElement)*sizeof(char*));
            counter2=counter2+2;
            i=i+1;
            letterCounter=0;
        }
    }
    for (int i = 0; i < 6; i++) {
        printf("%s\n",arrayOfStrings[i]);
    }
    printf("\n");
}

//15.k
/*
void twoDemensionalArray2(char string[]){
    //"USA. Canada, Mexico, Bermuda Grenada, Belize"
    int delimiterCount=0;
    int lengthOfCountryString=stringLength(string);
    for(int i=0;i<=lengthOfCountryString;i++){
        if (isDelimiter(string[i])==1){
            delimiterCount++;
        }
    }
    char **arrayOfStrings=malloc((delimiterCount+1)*sizeof(char*));
    
    char currentChar;
    int currentWordStart=0;
    int currentWordEnd=0;
    int currentWordIndex=0;
    for(int i=0;i<lengthOfCountryString+1;i++){
        currentChar=string[i];
        if (isDelimiter(currentChar) == 1 || i == lengthOfCountryString){
            char word[(currentWordEnd-currentWordStart)+1];
            int k=0;
            for(int j=currentWordStart;j<currentWordEnd;j++)
            {
                word[k]=string[j];
                k++;
            }
            word[k+1]='\0';
            arrayOfStrings[currentWordIndex]=word;
            printf("word added:%s\n",word);
            currentWordIndex++;
            currentWordStart=i+1;
            currentWordEnd=i+1;
        }else{
            currentWordEnd++;
        }
    }
    for (int i = 0; i < 6; i++) {
        printf("%s\n",arrayOfStrings[i]);
    }
}
 */
//17.d
int intInFormat=0;
double doubleInFormat;
float floatInFormat;
long BASE10Counter=1;
long result = 0;
long convertStringToLong(char alphanumericString[], long arrayLength, long longInFormat)
{
    if(longInFormat==0){
        BASE10Counter = 1;
    }
    if(arrayLength+1==0){
        return longInFormat;
    }else{
        longInFormat=longInFormat+(alphanumericString[arrayLength]-'0')*(BASE10Counter);
        BASE10Counter=BASE10Counter*10;
        return convertStringToLong(alphanumericString, --arrayLength, longInFormat);
    }
}

double convertStringToDouble(char alphanumericStringWithDot [], int arrayLength, double doubleInFormat)
{
    char dot[]=".";
    if(doubleInFormat==0){
        BASE10Counter=1;
    }
    if(arrayLength==0){
        return doubleInFormat;
    }else{
        if(alphanumericStringWithDot[arrayLength-1]==dot[0]){
            return convertStringToDouble(alphanumericStringWithDot, --arrayLength, doubleInFormat);
        }else if(arrayLength>findWord(alphanumericStringWithDot, ".")){
            doubleInFormat=doubleInFormat+(alphanumericStringWithDot[arrayLength-1]-'0')*pow(10,(findWord(alphanumericStringWithDot, ".")-arrayLength));
            return convertStringToDouble(alphanumericStringWithDot, --arrayLength, doubleInFormat);
        }else{
            doubleInFormat=doubleInFormat+(alphanumericStringWithDot[arrayLength-1]-'0')*pow(10,(findWord(alphanumericStringWithDot, ".")-(arrayLength+1)));
            return convertStringToDouble(alphanumericStringWithDot, --arrayLength, doubleInFormat);
        }
        
        return convertStringToDouble(alphanumericStringWithDot, --arrayLength, doubleInFormat);
    }
    

}

void convertAlphanumeric(char alphanumericString[]){
    long lengthOfAlphanumeric=stringLength(alphanumericString)-1;
    long longInFormat=0;
    long  myNum = (convertStringToLong(alphanumericString, lengthOfAlphanumeric, longInFormat));
    double num2=0;
    char str[stringLength(alphanumericString)];
    sprintf(str, "%lu", myNum);
    double num1=(convertStringToDouble(alphanumericString, stringLength(alphanumericString), num2));
    char str1[stringLength(alphanumericString)];
    sprintf(str1, "%f", num1);
    if(findWord(alphanumericString, ".")==0){
        if(*str!=*alphanumericString){
            printf("Error: this number is too long to fit into a Long\n");
        }

           else if (myNum>INT_MAX && myNum<LONG_MAX){
          
            long longInFormat=0;
            
            long alphanumericLongFormat=convertStringToLong(alphanumericString, lengthOfAlphanumeric, longInFormat);
            
            printf("This is a long: %lu\n",alphanumericLongFormat);
            
        }else if(myNum < int_maximum){
                int alphanumericIntFormat=(int)myNum;
            
            
            printf("This is an int: %d\n",alphanumericIntFormat);
            
        }else{
            
           
            printf("ERROR: this number is too large to fit into a long type\n");
        }
        
         //This is the section to change int or long
    }else{
        if(*str1!=*alphanumericString){
            printf("Error: this number is too large for a double\n");
        } else if(convertStringToDouble(alphanumericString, stringLength(alphanumericString),num2)>FLT_MAX && convertStringToDouble(alphanumericString, stringLength(alphanumericString),num2)< DBL_MAX){
            
            printf("This is a Double: %f\n",convertStringToDouble(alphanumericString, stringLength(alphanumericString),num2));
        
        }else if  (convertStringToDouble(alphanumericString, stringLength(alphanumericString),num2)<FLT_MAX){
            
            int strLength = stringLength(alphanumericString); //correct
            double convertedWithoutDot = convertStringToDouble(alphanumericString, strLength ,num2);
            printf("This number is a Float %f\n",convertedWithoutDot);
        }
                    }
}

int main(int argc, const char * argv[]) {
        char myQuote[]="\"Mr. Fay, is this going to be a battle of wits?\"\n\"If it is,\"was the indifferent retort, \"you have come unarmed!\"\n";
        char indifferent[]="indifferent";
    //15.c
    int len=stringLength(myQuote);
    printf("%d\n",len);
        //15.d
    int answer;
    answer =  findWord(myQuote, indifferent);
    printf("%d\n",answer);
    //15.e
    char comma1[]=", i";
    char comma2[]="s,";
    char comma3[]="t,";
    int comma1Position=findWord(myQuote, comma1);
    int comma2Position=findWord(myQuote, comma2);
    int comma3Position=findWord(myQuote, comma3);
    int commaArray[]={comma1Position,comma2Position,comma3Position};
    //15.f
    char substring[22];
    int position = findWord(myQuote, "\"you have");
    int position2=position-1;
    for (int x=0;x<=22;x++){
        substring[x]=myQuote[position2+x];
    }
    //15.g
    replaceIndifferent(myQuote);
    //15.h
    char oldWord[]="indifferent";
    char newWord[]="nonchalant";
    replaceWords(myQuote, oldWord, newWord);
    //15.i
    char *arrayOfStrings[6]={"USA","Canada","Mexico","Bermuda","Grenada","Belize"};
    arrayToString(arrayOfStrings);
    //15.i-l
    char countries[]={"USA. Canada, Mexico, Bermuda  Grenada, Belize"};
    twoDemensionalArray(countries);
    //17.d last exersize
    printf(" Exersize 17.d\n\n");
    char alphanumeric []="314159";
    char alphanumeric1 []="31415926535897932381651651651656515164626";
    char alphanumeric2 []="31415926535";
    char alphanumeric3 []="3.15159";
    char alphanumeric4 []="31415926535897932384626433831640628620899862803482117067982148086512231725359408128.48111745";
    char alphanumeric5 []="5465465165165465498451651651651651651651651651656516516516516516516516516565165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165165161615151611561516516516516516516516516516516161656161616161156151651651651615611565165165165165165165165165165165498498498498498498498498498498498498984984984984984984984984984984984984489849849849849849498498498498498498498.4984";
    convertAlphanumeric(alphanumeric);
    convertAlphanumeric(alphanumeric1);
    convertAlphanumeric(alphanumeric2);
    convertAlphanumeric(alphanumeric3);
    convertAlphanumeric(alphanumeric4);
    convertAlphanumeric(alphanumeric5);
    return 0;
}




