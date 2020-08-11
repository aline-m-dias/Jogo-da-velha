#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void tabuleiro (char casas[3][3], int jogadas)
{if (jogadas!=10 && jogadas!=11)
   {system("CLS");}
    printf ("\t %c | %c | %c \n",casas[0][0],casas[0][1],casas[0][2]);
    printf ("\t-----------\n");
    printf ("\t %c | %c | %c \n",casas[1][0],casas[1][1],casas[1][2]);
    printf ("\t-----------\n");
    printf ("\t %c | %c | %c \n",casas[2][0],casas[2][1],casas[2][2]);
    printf("\n\n");}


int det_2 ( int casas_int[3][3] , int i , int j)
{int det , a , b , vet [4] , cont=0;
    for (a=0;a<3;a++)
    {for (b=0;b<3;b++)
        {if (a!=i && b!=j)
            {vet[cont] = casas_int[a][b];
                cont++;}}}
    det = ((vet[0]*vet[3]) - (vet[1]*vet[2]));
    return (det);}

int det_cof ( int casas_int [3][3] , int i , int j )
{
    int cofator, expoente;

    if ((i + j) % 2 == 0){expoente = 1;}

    if ((i + j) % 2 != 0){expoente = -1;}
    cofator = (det_2(casas_int,i,j)*expoente);
    return (cofator);}


int det_total_linha_ (int casas_int_cof[3][3] , int casas_int[3][3] , int k)
{int i,j,det_total_linha=0;
    for (i=0;i<3;i++)
    {for (j=0;j<3;j++)
        {if (i==k)
            {det_total_linha = det_total_linha + (casas_int_cof[i][j]*casas_int[i][j]);}}}
    return (det_total_linha);}

int det_total_coluna_ (int casas_int_cof[3][3] , int casas_int[3][3] , int c)
{int i,j,det_total_coluna=0;
    for (i=0;i<3;i++)
    {for (j=0;j<3;j++)
        {if (j==c)
            {det_total_coluna = det_total_coluna + (casas_int_cof[i][j]*casas_int[i][j]);}}}
    return (det_total_coluna);}

int diagonalprincial(int cof[3][3])
 {int a[]={1,0,0},b[]={0,1,0},c[]={0,0,1},d[]={1,0,0}, e[]={0,1,0}, f[]={0,0,1};
  int r1[3]={0,0,0},r2[3]={0,0,0},r3[3]={0,0,0},s1[3]={0,0,0},s2[3]={0,0,0},s3[3]={0,0,0};
  int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0,i,j,d1,f1;

 for (i=0;i<3;i++)
    {for (j=0;j<3;j++)
        {if(i==0){s1[i]=cof[i][j]*c[j]+s1[i];}
         if(i==1){s2[i]=cof[i][j]*b[j]+s2[i];}
         if(i==2){s3[i]=cof[i][j]*a[j]+s3[i];}}}

for (i=0;i<3;i++)
    {b1=b1+s1[i]*d[i];
     b2=b2+s2[i]*e[i];
     b3=b3+s3[i]*f[i];}

for (i=0;i<3;i++)
    {for (j=0;j<3;j++)
        {if(i==0){r1[i]=cof[i][j]*a[j]+r1[i];}
         if(i==1){r2[i]=cof[i][j]*b[j]+r2[i];}
         if(i==2){r3[i]=cof[i][j]*c[j]+r3[i];}}}

for (i=0;i<3;i++){
     a1=a1+r1[i]*d[i];
     a2=a2+r2[i]*e[i];
     a3=a3+r3[i]*f[i];}
d1= b3*b2*b1; f1= a1*a2*a3;
if(d1==-108||f1==-108){return 0;}   else {return 1;}}

void jogo()
{int jogadas=1,a,c,vez=0,i,j,casas_int[3][3],casas_int_cof[3][3],cont=0,cont1=0,L,C,DET_LINHA,DET_COLUNA;
 char jogador1[100], jogador2[100];


    printf ("Jogador 1 escolha um nome:");
    fgets (jogador1,100,stdin);
    printf ("Jogador 2 escolha um nome:");
    fgets (jogador2,100,stdin);

    for (i=0;i<3;i++)
    {for (j=0;j<3;j++)
         {casas_int[i][j] = cont+1;
          cont++;}}


    for (i=0;i<3;i++)
    {for (j=0;j<3;j++)
         {casas_int_cof[i][j] = -1;}}

    char jogodavelha[3][3];
    for(i=0;i<3;i++)
       {for(j=0;j<3;j++)
           {jogodavelha[i][j]=' ';}}

    while (jogadas<=9)
    {tabuleiro(jogodavelha,jogadas);

       if (vez%2==0)
       {printf ("\nJogador: %s\n",jogador1);}
       else
       {printf ("\nJogador: %s\n",jogador2);}

       printf ("Digite a linha:");
       scanf ("%d",&a);
       printf ("Digite a coluna:");
       scanf ("%d",&c);

       if (a<1 || a>3 || c<1 || c>3)
       {a=0; c=0;}

       else
       {if (jogodavelha[a-1][c-1] != ' ')
       {a=0; c=0;}

       else
       {if (vez%2==0)
           {L=a-1;  C=c-1;
            jogodavelha[L][C]='X';

            casas_int_cof[L][C] = det_cof(casas_int,L,C);}
        else
           {L=a-1;  C=c-1;
            jogodavelha[L][C]='O';

            casas_int_cof[L][C] = det_cof(casas_int,L,C);}

      vez++;
      jogadas++;}}

      for (cont1=0;cont1<3;cont1++)
      {DET_LINHA = det_total_linha_(casas_int_cof,casas_int,cont1);
       DET_COLUNA = det_total_coluna_(casas_int_cof,casas_int,cont1);


          if ((DET_LINHA==0 && jogodavelha[cont1][0]=='X'
               && jogodavelha[cont1][1]=='X' && jogodavelha[cont1][2]=='X')
               || (DET_LINHA==0 && jogodavelha[cont1][0]=='O' && jogodavelha[cont1][1]=='O'
               && jogodavelha[cont1][2]=='O')) {jogadas = 11;}

          if ((DET_COLUNA==0 && jogodavelha[0][cont1]=='X'
               && jogodavelha[1][cont1]=='X' && jogodavelha[2][cont1]=='X')
               || (DET_COLUNA==0 && jogodavelha[0][cont1]=='O' && jogodavelha[1][cont1]=='O'
               && jogodavelha[2][cont1]=='O'))  {jogadas = 11;}

          if((diagonalprincial(casas_int_cof)==0 && jogodavelha[0][0]=='X'
              && jogodavelha[1][1]=='X' && jogodavelha[2][2]=='X')
              || (diagonalprincial(casas_int_cof)==0 && jogodavelha[0][0]=='O'
              && jogodavelha[1][1]=='O' && jogodavelha[2][2]=='O')
              ||(diagonalprincial(casas_int_cof)==0 && jogodavelha[2][0]=='X'
              && jogodavelha[1][1]=='X' && jogodavelha[0][2]=='X')
              || (diagonalprincial(casas_int_cof)==0 && jogodavelha[2][0]=='O'
              && jogodavelha[1][1]=='O' && jogodavelha[0][2]=='O'))  {jogadas = 11;}}}

    if (jogadas==11)
        {system("CLS");
         printf ("*** FIM DE JOGO *** \n");
    if ((vez-1)%2==0)
        {system("CLS");
         printf ("*** O JOGADOR %s VENCEU *** \n",jogador1);}
    else
        {system("CLS");
         printf ("*** O JOGADOR %s VENCEU *** \n",jogador2);}}
    if (jogadas==10)
        {system("CLS");
         printf ("*** JOGO EMPATADO *** \n");}

    tabuleiro(jogodavelha,jogadas);}


int main()
{
    jogo();
    return 0;
}

=
