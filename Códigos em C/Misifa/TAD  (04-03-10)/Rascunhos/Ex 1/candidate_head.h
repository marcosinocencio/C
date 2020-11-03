/*
*****************************************************
Def.:
*****************************************************
*/

typedef struct{
        int RG;
        char Name[50];
        char Telephone[14];
        char Address[60];
} candidate;

// Escope of functions

void ClearCandidate(candidate *Can);
void ClearArrayCand(candidate *C, int DIM);
int Search(candidate *C, int RG, int DIM);
int SearchNull(candidate *C, int DIM);
short Insert(candidate *C, candidate *Can, int DIM);
short Remove(candidate *C, int RG, int DIM);
short Alter(candidate *C, candidate *Can, int RG, int DIM);
