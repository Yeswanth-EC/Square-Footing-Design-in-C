#include <stdio.h>
#include<math.h>
int main()
{
  int w,l,b,q,fck,fy,D,E,N,S;
  float A,B,p,m,d,v,o,k,tv,tc,Mu,F,Ast,Ld,La;
  printf("Enter the weight of the Load in (kN):");
  scanf("%d",&w);
  printf("Enter the length of the column in (mm):");
  scanf("%d",&l);
  printf("Enter the breadth of the column in (mm):");
  scanf("%d",&b);
  printf("Enter the safe bearing capacity of the soil in (kN/m^2):");
  scanf("%d",&q);
  printf("Enter the grade of the concrete in (Mpa):");
  scanf("%d",&fck);
  printf("Enter the yeild strength of the steel in (Mpa):");
  scanf("%d",&fy);
  A=(1.1*w)/q;
  B=sqrt(A);
  printf("\n");
  printf("Size of the square footing: %.1f m x %.1f m",B,B);
  p=w/A;
  printf("\nNet soil pressure:%.2f (kN/m^2)",p);
  //(p<q)?((printf("")))
  m=1.5*p*B*(pow((B-b*0.001),2))/8;
  printf("\nDepth of the footing:%.2f mm",1000*sqrt((m/(0.138*fck*B*1000))));
  d=(1.5*p*(B-b*0.001))/(2*(384+(1.5*p)));
  printf("\nProviding 16 mm diameter bars with clear cover of 60 mm");
  D=(d*1000)+68;
  printf("\nOverall depth D:%d mm",D);
  E=D-68;
  printf("\nEffective depth:%d mm",E);
  o=(b+E)*0.001;
  v=1.5*p*((B*B)-(pow(o,2)));
  printf("\nFactored shear:%.2f kN",v);
  tv=0.001*(v/(4*o*(E*0.001)));
  printf("\nNominal shear:%.3f (N/mm^2)",tv);
  k=(0.5+(b/l));
  if(k>=1)
  {
      k=1;
  }
  
  tc=0.25*(sqrt(fck));
  if(tv<tc)
  {
      printf("\nDepth provided is safe");
  }
  else
  {
      printf("\nDepth provided is not safe");
  }
  Mu=0.138*fck*B*1000*(E*E);
  if(m>Mu)
  {
      printf("\nSection is under reinforced");
  }
  else
  {
      printf("\nSection is over reinforced");
  }
  F=4.6*(m*1000000)/(fck*B*1000*E*E);
  Ast=(0.5*fck/fy)*(1-sqrt(1-F))*B*1000*E;
  printf("\nArea of steel required:%.2f (mm^2)",Ast);
  printf("\nProviding 16 mm diameter bars");
  N=(Ast/201.06)+2;
  printf("\nNumber of bars:%d",N);
  printf("\nArea of steel provided:%.1f (mm^2)",N*201.06);
  S=(B*1000)/N;
  printf("\nSpacing of bars:%d mm",S);
  Ld=(0.87*fy*16)/(4*1.6*1.2);
  printf("\nDevelopment Length:%.2f mm",Ld);
  La=0.5*((B*1000-b)-60);
  if(La>Ld)
  {
     printf("\nLength of the footing is safe");
  }
  else
  {
      printf("\nLength of the footing is not safe");
  }
 
  return 0;
  
}
