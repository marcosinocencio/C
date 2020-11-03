#include <string.h>
#include "car.h"

#define CHARNULL "\0"
#define STRMAX 30

void Print(car *C){
     
     puts((*C).Plate);
     puts((*C).Model);
     puts((*C).Color);
     return;
}

int OrdemAlfa(char *Str1, char *Str2){
     int i;

     for (i=0;((*(Str1+i)!="\0")&&(*(Str2+i)!="\0"));i++){
         if (((int)*(Str1+i))>((int)*(Str2+i)))
            return(1);
         else return(2);
     if ((*(Str1+i)!="\0")&&(*(Str2+i)=="\0")) return(1);  
     else if ((*(Str1+i)=="\0")&&(*(Str2+i)!="\0")) return(2);
          else return(0);
}

void OrdemVet(car *C){
     int i;
     
     while ()
           if((int)*(((*C).Plate)+i)>(int)*(((*(C+1)).Plate)+i))
}

int Search(car *C, char *Str, int DIM){
      int i;
      
      for (i=0;i<DIM;i++)
          if(!strcmp((*(C+i)).Plate,Str)) return(i);
      return(-1);
}

short Insert(car *C, car *Car, int DIM){
      
      if((Search(C,(*Car).Plate,DIM))||(strcmp((*C).Plate,CHARNULL))) return(0);
      strcpy((*C).Plate,(*Car).Plate);
      strcpy((*C).Model,(*Car).Model);
      strcpy((*C).Color,(*Car).Color);
      return(1);
}

void Remove(car *C){
      
      strcpy((*C).Plate,"\0");
      return;
}
