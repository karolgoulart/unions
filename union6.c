#include <stdio.h>


typedef struct {
    int x;
    int y;
    int z;
} PontoStruct;

typedef union {
    PontoStruct coord;  
    int vec[3];         
} Ponto;

int main() {
    Ponto pt;

    pt.vec[0] = 10;
    pt.vec[1] = 20;
    pt.vec[2] = 30;

    printf("(%d, %d, %d)\n", pt.coord.x, pt.coord.y, pt.coord.z);

    pt.coord.x = 10;
    pt.coord.y = 20;
    pt.coord.z = 30;

    printf("Vetor: [%d, %d, %d]\n", pt.vec[0], pt.vec[1], pt.vec[2]);

    return 0;
}
