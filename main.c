#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
//prime numbers.
int primes(void){
    int a=0;
    int b=0;
    scanf("%d %d",&a,&b);
    int primeCount=0;
    for(int i=a;i<=b;i++){
        for(int j=2;j<=i;j++){
            if(i == 2){
                primeCount++;
            }else{
                double k=0;
                k = (double)i/(double)j - (double)(i/j);
                if(k > 0.000000 && j< i-1){
                    continue;
                }
                if(k > 0.000000 && j== i-1){
                    primeCount++;
                }
                if(k == 0.000000){
                    j=i;
                }
            }
        }
    }
    printf("%d\n",primeCount);
    return 0;
}



int main1(void){
    primes();//you can call functions which contain scanf within them, it would still work.
    return 0;
}



int enumer(void){//thats how enumerations are used.
    typedef enum{
        MON=1,TUES,WED,THRU,FRI,SAT,SUN
    }days;
    char*Days[]={"Monday","Tuesday","Wednesday","Thrusday","Friday","Saturday","Sunday"};
    for(int i=0;i<=6;i++){
    printf("%s is the %d day of the week.\n",Days[i],MON+i);
    }
    printf("%d\n",'a'-'A');//you can do operations with characters.
    return 0;
}



 int distinctElementsPrinter(void) {
 int arr[] = {1,2,3,3,2,4,1,5,5,5,5,6};
 int n = 12;
 for ( int i = 0; i < n ; i ++) {
 int isUnique = 1;
 for ( int j = 0; j < n ; j ++) {
 if ( arr [ i ] == arr [ j ] && i>j) {
 isUnique = 0;
 break ;
 }else if( arr [ i ] == arr [ j ] && i<j){
    isUnique=1;
    break;
}
 }
 if ( isUnique != 0 ) {
 printf ("% d " , arr[ i ]) ;
 }
 }
 return 0;
 }



 void arrayRotate(void){/*this program rotates the elements of the array.*/
    int n=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
    int k=0;
    scanf("%d",&k);
    while(k>n){
        k=k-n;
    }
    if(k == 0){
        for(int i=0;i<n;i++){
            printf("%d\n",arr[i]);
        }
    }else{
    int counter,hold=0;
    while(counter < k){
    for(int i=n-1;i>=0;i--){
        if(i != 0 && i != n-1){
        arr[i]=arr[i-1];
        }
        else if(i == n-1){
        hold=arr[i];
        arr[i]=arr[i-1];
    }
    else if(i == 0){
     arr[i]=hold;
    }
    }
    counter++;
}
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }   
}
 }


void spaceship(void) {

    int n=0;
    scanf("%d",&n);
    int ids[n];
    float weights[n];
    char wing[n];
    for(int i=0;i<n;i++){
        scanf("%d %f %c",&ids[i],&weights[i],&wing[i]);
    }
    double leftTotalWeight=0;
    double rightTotalWeight=0;
    for(int i=0;i<n;i++){
        if(wing[i] == 'L'){
        leftTotalWeight = leftTotalWeight + (double)weights[i];
        }
        if(wing[i] == 'R'){
            rightTotalWeight = rightTotalWeight + (double)weights[i];
        }
    }
    double totalWeight=0;
    totalWeight = leftTotalWeight + rightTotalWeight;
    double difference=0;
    difference = fabs(leftTotalWeight - rightTotalWeight);
    if(difference <= (0.100000)*totalWeight){
        printf("BALANCED\n");
    }else{
        printf("UNBALANCED\n");
    
    
    int possibleId=0;
    int tempMin=100000;
    
    for(int i =0;i<n;i++){
    if(wing[i] == 'L'){
        rightTotalWeight = rightTotalWeight + weights[i];
        if(fabs(leftTotalWeight - rightTotalWeight) < tempMin ){
            tempMin = fabs(leftTotalWeight - rightTotalWeight);
            possibleId = ids[i]; 
        }
    }
    else if(wing[i] == 'R'){
        leftTotalWeight = leftTotalWeight + weights[i];
         if(fabs(leftTotalWeight - rightTotalWeight) < tempMin ){
            tempMin = fabs(leftTotalWeight - rightTotalWeight);
            possibleId = ids[i]; 
        }
    }
}
    printf("%d\n",possibleId);
    }
    
}

int structInsideStruct(void){/*this is how you can access members of a structure which(that structure) is inside another structure.*/
    struct mystruct{
        int n;
        int m;
        struct{
            int mem1;
            int mem2;
        };
    }myStruct;
    myStruct.mem1=1000;

    printf("%d\n",myStruct.mem1);
    
    return 0;
}


void displayBinaryRepresentation(unsigned int number){//this the most portable form.
    unsigned int displayMask = 1 << (int)__CHAR_BIT__*sizeof(unsigned int) - 1 ;/*here 1 followed by 31 zeroes is the binary 
    representation of "-2147483648" but the dat type of displayMask is unsigned int so the number stored within 
    displayMask would be "2147483648" more of like an implicit conversion. */
    /*A lot imlicit conversion occurs here...*/
    for(unsigned long int i=1;i<=__CHAR_BIT__*sizeof(unsigned int);i++){
        printf(number & displayMask ? "1" : "0");
        number <<= 1;
        if(i % 8 == 0){
        printf(" ");
    }
    }
    printf("\n");
    
}


void reverseBits(unsigned int a){
    displayBinaryRepresentation(a);
    unsigned int displayMask = 1 ;

    for(unsigned long int i=1;i<=__CHAR_BIT__*sizeof(unsigned int);i++){
        printf(a & displayMask ? "1" : "0");
        a >>= 1;
        if(i % 8 == 0){
        printf(" ");
    }
    }
    printf("\n");
}

void packCharacters(char *arr){
    unsigned int a=0;
    a=(int)(*(arr + 0));
    for(int i=1;i<4;i++){
        a = a<<8;
        a = a|arr[i];
    }
    displayBinaryRepresentation(a);
}



void creditInquiry(void){

    FILE* fPtr = fopen("/home/adharvan/ccodes/clients.txt","r");
    if(fPtr == NULL ){
        puts("File could not be opened.");

    }else{
        int option = 0;
        printf("option 1 - show the customers with zero balance.\n");
        printf("option 2 - show the customers with credit balance.\n");
        printf("option 3 - show the customers with debit balance.\n");
        scanf("%d",&option);
        int account =0;
        double test=0;
        char Name[30];
        switch(option){
            case 1:
            for(int i=0;fscanf(fPtr,"\n%d %s %lf",&account,Name,&test) != EOF; i++){
                if(test == (double)0){
                    printf("%d\t%s\t%lf\n",account,Name,(double)test);
                }
            }
                        break;
            case 2:
            for(int i=0;fscanf(fPtr,"\n%d %s %lf",&account,Name,&test) != EOF;i++){
                if(test < (double)0){
                    printf("%d\t%s\t%lf\n",account,Name,(double)test);
                }
            }
            break;
            case 3:
           for(int i=0;fscanf(fPtr,"\n%d %s %lf",&account,Name,&test) != EOF;i++){
                if(test > (double)0){
                    printf("%d\t%s\t%lf\n",account,Name,(double)test);
                }
            }
            break;
        }
        fclose(fPtr);

        puts("Thank you.");
    
    }



}

void accountfinder(void){
    FILE * fPtr=fopen("/home/adharvan/ccodes/clients.txt","r");
    if(fPtr == NULL ){
        puts("File could not be opened.");
    }else{
        int account = 0;
        double balance=0;
        char Name[30];
        char testName[30];
        scanf("%s",testName);
        

        if(islower(testName[0])){
        testName[0] = (char)(toupper(testName[0]));
        }
        
        int j=0;
        for(int i=0;(j = fscanf(fPtr,"%d %s %lf",&account,Name,&balance)) >= EOF;i++){
            if(j > EOF && strcmp(Name,testName) == 0 ){
                printf("%d %s %lf\n",account,Name,balance);
                break;
        }
        
            if(j == EOF){
                puts("Non-Existing Account.");
                break;
        } 
}

}
fclose(fPtr);
}


void changeAccountName(void){
    FILE *fPtr=fopen("/home/adharvan/ccodes/clientsUpdate.txt","w");
    FILE *cPtr=fopen("/home/adharvan/ccodes/clients.txt","r");
    int account = 0;
    char Name[30];
    double balance = 0;
    char changeName[30];
    char testName[30];
    scanf("%s",testName);
    scanf("%s",changeName);
    if(islower(testName[0])){
        testName[0] = (char)(toupper(testName[0]));
        }
    if(islower(changeName[0])){
        changeName[0] = (char)(toupper(changeName[0]));
        }
    for(int i=0;fscanf(cPtr,"%d %s %lf",&account,Name,&balance) != EOF;i++){
        if(strcmp(Name,testName) == 0){
            fprintf(fPtr,"%d %s %lf\n",account,changeName,balance);
        }else{
            fprintf(fPtr,"%d %s %lf\n",account,Name,balance);
        }
    }
    fclose(fPtr);
    fclose(cPtr);
}
/*Random Access Files.*/

typedef struct{
    int account;
    char firstName[10];
    char lastName[15];
    double balance;
} clientData ;

// clientData blankClient={0,"","",0.0};
//         for(int i=1;i<=100;i++) { 
//             fwrite(&blankClient,sizeof(clientData),1,fPtr);
//             fseek(fPtr,sizeof(clientData),SEEK_CUR);
//         }

         

//  clientData client;
//     FILE *fPtr=fopen("/home/adharvan/ccodes/accounts.dat","rb+");
//     if(fPtr == NULL){
//         puts("File could not be opened.");
//     }else{
//         while(1){
//             scanf("%d %s %s %lf",&client.account,client.firstName,client.lastName,&client.balance);
//                   if(client.account != -1){
//                     fwrite(&client,sizeof(clientData),1,fPtr);
//                     fseek(fPtr,(client.account-1)*sizeof(clientData),SEEK_SET);
                    
//                   }else{
//                     break;
//                   }
//                     }          
//                     fclose(fPtr);  
// }
//     return 0;


//  clientData client;
//     FILE *fPtr=fopen("/home/adharvan/ccodes/accounts.dat","rb+");
//     if(fPtr == NULL){
//         puts("File could not be opened.");
//     }else{
//         while(1){
//             scanf("%d %s %s %lf",&client.account,client.firstName,client.lastName,&client.balance);
//                   if(client.account != -1){
//                     fwrite(&client,sizeof(clientData),1,fPtr);
//                     fseek(fPtr,(client.account-1)*sizeof(clientData),SEEK_SET);
//                   }else{
//                     break;
//                   }
//                     }          
//                     fclose(fPtr);  
// }



//         while(!feof(fPtr)){
//             fread(&client,sizeof(clientData),1,fPtr);
//             if(client.account != 0){
//             printf("%d %s %s %lf\n",client.account,client.firstName,client.lastName,client.balance);
//             }
//             fseek(fPtr,(client.account-1)*sizeof(clientData),SEEK_SET);
            
//         }

// fclose(fPtr);  

// int main(void){
//     clientData client={0,"","",0.0};
//     FILE *fPtr=fopen("C:/programs/c codes/accounts.dat","rb+");
//     if(fPtr == NULL){
//         puts("File could not be opened.");
//     }else{
//         int j=0;
//         fread(&client, sizeof(clientData), 1, fPtr);
//         while (1) {
//             if (client.account != 0) {
//                 printf("%d %s %s %.3lf\n",client.account,client.firstName,client.lastName,client.balance);
//             }
//             j=fseek(fPtr,sizeof(clientData),SEEK_CUR);
//            fread(&client, sizeof(clientData), 1, fPtr);
//             if(j != 0){
//                 break;
//             }
//         }
//         fclose(fPtr);
//         printf("Completed.\n");
//     }
    
// return 0;

// }

void displayBinaryRepresentation2(unsigned int number){
    unsigned int displayMask = 1 << (int)__CHAR_BIT__*sizeof(unsigned int) - 1 ;
    for(unsigned long int i=1;i<=__CHAR_BIT__*sizeof(unsigned int);i++){
        if(i>24){
        printf(number & displayMask ? "." : "_");
        }
        number <<= 1;
    }
    
}

void stringToQR(char*str){/*This is a primitive form of QR code generation.*/
    if(strlen(str)%2 ==0){
    for(int i=0;*(str+i) != '\0';i++){
        displayBinaryRepresentation2((unsigned int)(*(str+i)));
        if((i+1)%2 == 0){
            printf("\n");
        }
    }
}else{
    char str2[]=" ";
    stringToQR(strcat(str,str2));
}
}
int charToIntConverter(int x){/*this function takes the ascii code of character digit and returns it as an integer.*/
    for(int i=0;i<10;i++){
       if(x == (i+48)){
            return i;
       }
    }
}




int charToIntConverter2(int x){/*this function takes the ascii code of character digit and returns it as an integer.*/
    for(int i=0;i<10;i++){
       if(x == (i+48)){
            return i;
       }else if( x != (i+48) && i==9){
        return -1;
       }
    }
}

void NumToWordCheck(void){
    /*This function converts amount in numerals to words.Typically used in banking. The numerals after the decimal point 
    are also printed as words.
    example-
    34.87
    THIRTY FOUR point EIGHT SEVEN.*/
    /*"short int" has been used for the "for" loops in the program for memory efficiency but it may lead to the program taking some time to execute 
    So if spped is a concern then use "int" for a system with "word" as 4 bytes int data type is suitable.*/
    puts("Please enter the amount with decimal point as 'xxxx.xxx' ");
    char amount[15];
    scanf("%s",amount);
    char* Numbers1[] ={"ONE","TWO" ,"THREE" ,"FOUR" ,"FIVE" ,"SIX" ,"SEVEN" ,"EIGHT" ,"NINE"};
    char* Numbers2[] ={"TEN","TWENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};
    char* Numbers3="HUNDRED";
    char* Numbers4="THOUSAND";
    char* Numbers5[]={"TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};
    char s1[]=".";
    char* Ptr;
    if(strstr(amount,s1) != NULL){
        Ptr = &amount[0];

     /*the while loop*/  
      while((int)*(Ptr) != (int)'.' ){
if((int)*(Ptr + 4) == (int)'.'){
        for(short int i=0;i<9;i++){
           if( (i+1) == charToIntConverter((int)*Ptr) ){
            printf("%s %s ",Numbers1[i],Numbers4);
           };
    }
    Ptr++;
    continue;
}

if((int)*(Ptr+3) == (int)'.'){
    if((int)*Ptr == '0'){
        Ptr++;
        continue;
    }else{
        for(short int i=0;i<9;i++){
           if( (i+1) == charToIntConverter((int)*Ptr)){
            printf("%s %s ",Numbers1[i],Numbers3);
           };
    }
    Ptr++;
    continue;
}
}

if((int)*Ptr != '1' && (int)*(Ptr+2) == (int)'.' ){
   if((int)*Ptr == '0'){
        Ptr++;
        continue;
    }else{
        for(short int i=0;i<9;i++){
           if( (int)*Ptr != '1' && (i+1) == charToIntConverter((int)*Ptr)){
            printf("%s ",Numbers2[i]);
           }
    }
    Ptr++;
    continue;
}
}

if((int)*(Ptr+1) == (int)'.'){
        for(short int i=0;i<9;i++){
           if( (i+1) == charToIntConverter((int)*Ptr)){
            printf("%s ",Numbers1[i]);
           };
    }
    Ptr++;
    continue;
}

if((int)*Ptr == '1' && (int)*(Ptr+2) == (int)'.'){
       
             Ptr++;
            for(short int i=0;i<9;i++){

                if( (int)*Ptr != '0' && i == charToIntConverter((int)*Ptr)){
                    printf("%s ",Numbers5[i]);
                }
                
                if((int)*Ptr == '0'){
                    printf("%s ",Numbers5[0]);
                }
            }
    
    Ptr++;
    continue;
}


}
Ptr++;
printf("point ");
/*The second while loop*/
while(*(Ptr) != '\0'){
    for(int i=0;i<10;i++){
        if(i==0 && i == charToIntConverter((int)*Ptr)){
            printf("ZERO ");
        }
        if((i+1) == charToIntConverter((int)*Ptr)){
            printf("%s ",Numbers1[i]);
        }
    }
    Ptr++;
    continue;
}
puts("ONLY");
    }else{
        puts("Invalid format for entering amount.");
        return NumToWordCheck();
    }
    

}/*end of NumToWordCheck */



/*THE CALCULATOR PROGRAM   (PRIMITIVE)*/
int calculate(void) {
    char s[1000];
    puts("Please enter a valid expression.");
    scanf("%s",s);
    char*sPtr=s;
    //here spaces are allowed, that is one thing.

    /****************Checking if expression is valid*******************/
    for(int i=0; s[i] != '\0';i++){

        if(i==0){
            if((int)s[i] == (int)' ' || charToIntConverter2((int)s[i]) != -1 || (int)s[i] == (int)'('){
                sPtr++;
                continue;
            }else{
                puts("Invalid expression.Please enter a valid expression");
                return calculate();
            }
        }     

            if( charToIntConverter2((int)s[i]) != -1 ){/* digit */
                if((int)s[i+1] == (int)' ' ||(int)s[i+1] == (int)'+' || (int)s[i+1] == (int)'-'){
                    sPtr++;
                    continue;
                }else{
                puts("Invalid expression.Please enter a valid expression");
                return calculate();
            }
            } 


            if((int)s[i] == (int)' '){
                sPtr++;
                continue;
            }           

              if((int)(s[i]) == (int)'+'){/*  +  *//*i am here!*/
                if( (int)(s[i+1]) == (int)' ' || (int)(s[i+1]) == (int)'(' || charToIntConverter2(s[i+1]) != -1 ){
                    continue;
                }else{
                    puts("Invalid expression.Please enter a valid expression");
                }
            }


            if((int)(s[i]) == (int)'-'){/*  -  */
                if( (int)(s[i+1]) == (int)' ' || (int)(s[i+1]) == (int)'(' || charToIntConverter2(s[i+1]) != -1){
                    continue;
                }
            }


            if((int)(s[i]) == (int)')'){/*  )   */
                if( (int)(s[i+1]) != (int)'(' || charToIntConverter2(s[i+1]) == -1){
                    continue;
                }
            }
            
            if((int)(s[i]) == (int)'('){/*  (   */
                if( (int)(s[i+1]) == (int)' ' || charToIntConverter2(s[i+1]) != -1){
                    continue;
                }
            }

            
        

    }
    /********************************************************************/
    

    while(strstr(sPtr,"(") != NULL){
        sPtr = strstr(sPtr,"(");
    }/*sPtr at innermost paranthesis.*/

    /*********Evaluating stuff inside innermost Paranthesis*********************/
    int p=0;
    while( (int)*sPtr != ')' ){
        if( (int)*sPtr != ' ' ){
            sPtr++;
            continue;
        }
        if( (int)*sPtr >=48 && (int)*sPtr <58 ){
            p=charToIntConverter(*sPtr);
            continue;
        }
        if( (int)*sPtr == (int)'+' ){

        }
    }


}


int main(void){
    NumToWordCheck();
    
    return 0;
}