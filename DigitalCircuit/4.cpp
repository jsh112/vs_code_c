// #include <stdio.h>

// int main()
// {

//     int bin[8][8];
//     int f1[8],f2[8];
//     for (int i = 0; i < 8; i++)
//     {
//         int tmp = i;
//         int j;
//         for (j = 2; j >= 0 && tmp >= 0; j--)
//         {
//             bin[i][j] = tmp % 2;
//             tmp = tmp / 2;
//         }
//     }

//     printf("A B C F\n");
    
//     // Calculate the boolean algebraic expression F = yz + y'z' + xz
//     for(int i = 0; i < 8; i++)
//     {   
//         // yz + y'z' + xz
//         f1[i] = bin[i][1] & bin[i][2] | ((~bin[i][1] & 1) & (~bin[i][2] & 1)) | (bin[i][0] & bin[i][2]);
//         // yz + y'z' + xy'
//         f2[i] = bin[i][1] & bin[i][2] | ((~bin[i][1] & 1) & (~bin[i][2] & 1)) | (bin[i][0] & (~bin[i][1] & 1));
//         printf("%d %d %d %d\n", bin[i][0], bin[i][1], bin[i][2], f1[i]);
//     }
//     printf("\nA B C F\n");

//     for(int i = 0; i<8;i++){
//         printf("%d %d %d %d\n", bin[i][0], bin[i][1], bin[i][2], f2[i]);
//     }

//     return 0;
// }

#include <stdio.h>

typedef struct{
    int x;
    int y;
    int z;
}Input3;

typedef struct{
    int a;
    int b;
    int c;
    int d;
}Input4;

int main(){
    Input3 inputs[8];
    int f1[8],f2[8],f3[8];

    printf("A B C D\n");
    for(int i=0;i<8;i++){
        inputs[i].x = (i>>2) & 1;
        inputs[i].y = (i>>1) & 1;
        inputs[i].z = i & 1;

        f1[i] = inputs[i].y & inputs[i].z | ((~inputs[i].y & 1) & (~inputs[i].z & 1)) | inputs[i].x & inputs[i].z;
        // f2[i] = inputs[i].y & inputs[i].z | ((~inputs[i].y & 1) & (~inputs[i].z & 1)) | (inputs[i].x & (~inputs[i].y & 1));
        f2[i] = inputs[i].x & inputs[i].y | inputs[i].x & (inputs[i].y | inputs[i].z) | inputs[i].y & (inputs[i].y | inputs[i].z);
        f3[i] = inputs[i].y | (inputs[i].x & inputs[i].z);

        printf("%d %d %d %d\n",inputs[i].x,inputs[i].y,inputs[i].z,f1[i]);
    }
    printf("\nA B C D\n");
    for(int i=0;i<8;i++){
        printf("%d %d %d %d\n",inputs[i].x,inputs[i].y,inputs[i].z,f2[i]);
    }
    printf("\nA B C D\n");
    for(int i=0;i<8;i++){
        printf("%d %d %d %d\n",inputs[i].x,inputs[i].y,inputs[i].z,f3[i]);
    }
}







