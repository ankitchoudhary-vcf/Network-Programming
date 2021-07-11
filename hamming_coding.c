

/**
 * eg:- D7 D6 D5 P4 D3 P2 P1
 * where, D7, D6, D5, and D3 are the data bits and P4, P2, and P1 are the parity bits.
 * input:- 1010 
 */

#include<stdio.h>
#include<math.h>

void main(){

    int data[10], dataAtRec[10], c, c1, c2, c3, i;

    printf("Enter 4bits of data one by one \n");

    scanf("%d", &data[0]);
    scanf("%d", &data[1]);
    scanf("%d", &data[2]);
    scanf("%d", &data[4]);


    data[3] = data[2]^data[1]^data[0];
    data[5] = data[4]^data[1]^data[0];
    data[6] = data[4]^data[2]^data[0];

    printf("\nEncode data is:\n");

    for(i=0; i<7; i++){
        printf("%d", data[i]);
    }

    printf("\nEnter received data bits one by one \n");

    for(i=0; i<7; i++){
        scanf("%d",&dataAtRec[i]);
    }

    printf("\nReceived data is:\n");

    for(i=0; i<7; i++){
        printf("%d", dataAtRec[i]);
    }

    c1 = dataAtRec[6]^dataAtRec[4]^dataAtRec[2]^dataAtRec[0];
    c2 = dataAtRec[0]^dataAtRec[1]^dataAtRec[4]^dataAtRec[5];
    c3 = dataAtRec[3]^dataAtRec[2]^dataAtRec[1]^dataAtRec[0];
    c = c3*4 + c2*2 + c1;

    if(c==0)
    {
        printf("\nNo error occur while data transmition\n");
    }
    else{
    printf("\nError in data at position %d", 7-c);

    if(dataAtRec[7-c] == 0)
    {
        dataAtRec[7-c] = 1;
    }
    else{
        dataAtRec[7-c] = 0;
    }
    }

    printf("\nCorrected Receiver data is \n");

    for(i=0; i<7; i++)
    {
        printf("%d", dataAtRec[i]);
    }
    
}
