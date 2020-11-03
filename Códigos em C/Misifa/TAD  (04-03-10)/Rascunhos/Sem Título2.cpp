/*
*/

#define charclear "0";

short StrComp(char *Str1, char *Str2){
      int i;
      if(*Str2=="\0") return(0);
      for (i=0;*(Str1+i)!="\0";i++)
          if(*(Str1+i)!=*(Str2+i)) return(0);   
      if(*(Str2+i)!="\0") return(0);
      return(1);
}

void Clear(Candidate *C, int DIM){
     *(C.RG)="\0";
     return;
}

*Candidate Search(Candidate *C, char *RG, int DIM){
     int i;
     for (i=0;i<DIM;i++)
         if(StrComp(RG,C+i)) return(C+i);
     return();
}

void Insert(Candidate *C, Candidate *Can){
}

void Remove(Candidate *C, int RG, int DIM){
}

void Alter(Candidate *C, int RG){
}
