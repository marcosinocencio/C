#include <stdio.h>
#include <stdlib.h>
#include <math.h>

////////////////////////////////////////////////////////////////
double Equacao_1_grau (double a ,double b) {
     double x;
     x=-b/a;
     return(x);
     }
////////////////////////////////////////////////////////////////

double Delta (double b, double c, double d)    {
       double x;
       x=c*c-4*b*d;
       return(x);
       }
       
////////////////////////////////////////////////////////////////

double r1_2_grau (double b, double c, double d) {
       double x;double r1;      
       //if ((Delta (b,c,d))>=0)
       r1 = (-c - sqrt(Delta(b,c,d)))/2.0*b;
       return(r1);
       }
       
////////////////////////////////////////////////////////////////

double r2_2_grau (double b, double c, double d) {
       double x;double r2;        
       //if ((Delta (b,c,d))>=0)
       r2 = (-c + sqrt(Delta(b,c,d)))/2.0*b;
       return(r2);
       }

////////////////////////////////////////////////////////////////
double real (double b, double c, double d) {
       float r;
       r=-c/(2.0*b);
       return(r);   
       }
////////////////////////////////////////////////////////////////
double im (double b, double c, double d) {
       double img;
       img=sqrt(fabs(Delta(b,c,d)))/(2.0*b);
       return(img);   
       }
////////////////////////////////////////////////////////////////
double D_3_grau (double a, double b, double c, double d){
       double a1, p, q, D;
    b=b/a;
    c=c/a;
    d=d/a;
    a1=a/a;
    
    p= d-((b*b)/3);
    q= d+((2*b*b*b)/27)-((b*c)/3);
    
    D= (q*q)/4 + (p*p*p)/27;
    
    return (D);
}
////////////////////////////////////////////////////////////////
double Dmenos_r1_3_grau (double a, double b, double c, double d){
    double a1, u, v, r1, E, r, t, p, q;
    b=b/a;
    c=c/a;
    d=d/a;
    a1=a/a;
       
    p= d-((b*b)/3);
    q= d+((2*b*b*b)/27)-((b*c)/3);
    
    u= cbrt((-q/2) + sqrt(D_3_grau(a,b,c,d)));
    v= cbrt((-q/2) - sqrt(D_3_grau(a,b,c,d)));
    r1 = u + v - (b/3);
       
    E=sqrt(fabs(- D_3_grau(a,b,c,d)));
    r=sqrt(((q*q)/4)+(E*E));
    t= acos(-q/(2*r));
    
    r1= 2*(r1/(3*cos((t/3)))) - (b/3);
    return (r1);
}
////////////////////////////////////////////////////////////////
double Dmenos_r2_3_grau (double a, double b, double c, double d){
    double a1, u, v, r1, r2, E, r, t, p, q;
    b=b/a;
    c=c/a;
    d=d/a;
    a1=a/a;
       
    p= d-((b*b)/3);
    q= d+((2*b*b*b)/27)-((b*c)/3);
    
    u= cbrt((-q/2) + sqrt(D_3_grau(a,b,c,d)));
    v= cbrt((-q/2) - sqrt(D_3_grau(a,b,c,d)));
    r1 = u + v - (b/3);
       
    E=sqrt(fabs(- D_3_grau(a,b,c,d)));
    r=sqrt(((q*q)/4)+(E*E));
    t= acos(-q/(2*r));
    
    r2= 2*(r1/(3*cos((t+(2*M_PI)/3)))) - (b/3);
    return (r2);
}
////////////////////////////////////////////////////////////////
double Dmenos_r3_3_grau (double a, double b, double c, double d){
    double a1, u, v, r1, r3, E, r, t, p, q;
    b=b/a;
    c=c/a;
    d=d/a;
    a1=a/a;
       
    p= d-((b*b)/3);
    q= d+((2*b*b*b)/27)-((b*c)/3);
    
    u= cbrt((-q/2) + sqrt(D_3_grau(a,b,c,d)));
    v= cbrt((-q/2) - sqrt(D_3_grau(a,b,c,d)));
    r1 = u + v - (b/3);
       
    E=sqrt(fabs(- D_3_grau(a,b,c,d)));
    r=sqrt(((q*q)/4)+(E*E));
    t= acos(-q/(2*r));
    
    r3= 2*(r1/(3*cos((t+(4*M_PI)/3)))) - (b/3);
    return (r3);
}
////////////////////////////////////////////////////////////////
double Dmais_r1_grau (double a, double b, double c, double d){
       double E, u, v, d2, r1, a1, p, q;
    b=b/a;
    c=c/a;
    d=d/a;
    a1=a/a;
       
    p= d-((b*b)/3);
    q= d+((2*b*b*b)/27)-((b*c)/3);
    
    E=sqrt(D_3_grau(a,b,c,d));
    u= cbrt((-q/2) + E);
    v= cbrt((-q/2) - E);
    r1 = u + v - (b/3);
    return(r1);
}
////////////////////////////////////////////////////////////////
double Dmais_r2_grau (double a, double b, double c, double d){
       double E, u, v, d2, r1, r2, a1, p, q;
    b=b/a;
    c=c/a;
    d=d/a;
    a1=a/a;
       
    p= d-((b*b)/3);
    q= d+((2*b*b*b)/27)-((b*c)/3);
    
    E=sqrt(D_3_grau(a,b,c,d));
    u= cbrt((-q/2) + E);
    v= cbrt((-q/2) - E);
    r1 = u + v - (b/3);
    d2=((b + r1)*(b + r1)) - 4*1*(-d/r1);
    
    if (d2<0) r2= (-(b+r1)/2);
        return (r2);
}     
////////////////////////////////////////////////////////////////
double im_3_grau (double a, double b, double c, double d){
       double E, u, v, d2, r1, r2, a1, p, q, im;
    b=b/a;
    c=c/a;
    d=d/a;
    a1=a/a;
       
    p= d-((b*b)/3);
    q= d+((2*b*b*b)/27)-((b*c)/3);
    
    E=sqrt(D_3_grau(a,b,c,d));
    u= cbrt((-q/2) + E);
    v= cbrt((-q/2) - E);
    r1 = u + v - (b/3);
    d2=((b + r1)*(b + r1)) - 4*1*(-d/r1);
    
    if (d2<0)  im = sqrt(fabs(-d2));
               else    im = sqrt(fabs(d2));    
               
               return (im);       
}
////////////////////////////////////////////////////////////////
int main (void){
    
       int z;    
       double a,b,c,d;
                         
              printf("Entre com o valor de a: \n");
              scanf("%lf",&a);
              printf("Entre com o valor de b: \n");
              scanf("%lf",&b);
              printf("Entre com o valor de c: \n");
              scanf("%lf",&c);
              printf("Entre com o valor de d: \n");
              scanf("%lf",&d);
              
              system ("cls");
              
              if ((a==0) && (b==0) && (c==0))
                 printf("Esta e uma equacacao degenerada! \n\n\n\n");
              else if ((a==0) && (b==0))
                   printf("Esta E Uma Equacao do Primeiro Grau e Sua Raiz E : %lf \n\n\n\n",Equacao_1_grau(c,d));
              else if ((a==0))
                   if (Delta(b,c,d)>=0)
                      printf("Esta E Uma Equacao do Segundo Grau e Suas Raizes Sao : %lf,%lf \n\n\n\n", r1_2_grau(b,c,d),r2_2_grau(b,c,d));
                   else printf("Esta E Uma Equacao do Segundo Grau e Suas Raizes Sao: %lf + %lf*i e %lf - %lf*i \n\n\n\n", real(b,c,d), im(b,c,d), real(b,c,d), im(b,c,d));
              else if (D_3_grau (a,b,c,d)>0) printf ("Esta E Uma Equacao do Terceiro Grau e Suas Raizes Sao: %lf, %lf+%lf*i, %lf-%lf*i \n\n\n\n", Dmais_r1_grau(a,b,c,d), Dmais_r2_grau(a,b,c,d), im_3_grau(a,b,c,d), Dmais_r2_grau(a,b,c,d), im_3_grau(a,b,c,d));
                       else printf ("Esta E Uma Equacao do Terceiro Grau e Suas Raizes Sao: %lf, %lf, %lf \n\n\n\n",Dmenos_r1_3_grau (a,b,c,d), Dmenos_r2_3_grau (a,b,c,d), Dmenos_r3_3_grau(a,b,c,d));
                       
system("pause");                       
                   
return(0);

}
