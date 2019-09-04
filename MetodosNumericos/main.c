//
//  main.c
//  MetodosNumericos
//
//  Created by Eduarda Mello on 03/09/19.
//  Copyright © 2019 Eduarda Mello. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menu(void);
void bissecao(float a, float b, float c);
void posicaoFalsa(float a, float b, float c);
void pontoFixo(float a, float b,  float c, float x0);
void newton(float a, float b,  float c, float x0);
void secante(float a, float b,  float c, float x0, float x1);
float polinomio(float);
float derivada(float);
float quici(float);
float mod(float);

//funcao xˆ3-x-1


int main() {
    int opc;
    float a,b,e,x,fx,d,h,x0,x1;
    do{
        opc = menu();
        switch (opc) {
            case 1:
                printf("\nMetodo da Bissecao:\n");
                printf("Entre com a: ");
                scanf("%f", &a);
                printf("Entre com b: ");
                scanf("%f", &b);
                printf("Entre com a precisao: ");
                scanf("%f", &e);
                d = b-a;
                
                if(d<e) {
                    x = a+b;
                    x = x/2;
                    fx = polinomio(x);
                    printf("\nx = %f e f(x) = %f",x, fx);
                }
                bissecao(a, b, e);
                break;
                
            case 2:
                printf("\nMetodo da Posicao Falsa:\n");
                printf("Entre com a: ");
                scanf("%f", &a);
                printf("Entre com b: ");
                scanf("%f", &b);
                printf("Entre com a precisao: ");
                scanf("%f", &e);
                d = b-a;
                
                if(d<e) {
                    x = a+b;
                    x = x/2;
                    fx = polinomio(x);
                    printf("\nx = %f e f(x) = %f",x, fx);
                }
                posicaoFalsa(a, b, e);
                break;
                
            case 3:
                printf("\nMetodo do Ponto Fixo:\n");
                printf("Q(x) = (x+1)ˆ1/3\n");
                printf("Entre com a: ");
                scanf("%f", &a);
                printf("Entre com b: ");
                scanf("%f", &b);
                printf("Entre com a precisao: ");
                scanf("%f", &e);
                printf("Entre com o x0");
                scanf("%f", &x0);
                h = polinomio(x0);
                h = mod(h);
                
                if(h<e) {
                    x = x0;
                    fx = polinomio(x);
                    printf("\nx = %f e f(x) = %f", x, fx);
                }
                pontoFixo(a, b, e, x0);
                break;
                
            case 4:
                printf("\nMetodo de Newton:\n");
                printf("Entre com a: ");
                scanf("%f", &a);
                printf("Entre com b: ");
                scanf("%f", &b);
                printf("Entre com a precisao: ");
                scanf("%f", &e);
                printf("Entre com o x0");
                scanf("%f", &x0);
                h = polinomio(x0);
                h = mod(h);
                
                if(h<e) {
                    x = x0;
                    fx = polinomio(x);
                    printf("\nx = %f e f(x) = %f",x,fx);
                }
                newton(a, b, e, x0);
                break;
                
            case 5:
                printf("\nMetodo de Newton:\n");
                printf("Entre com a: ");
                scanf("%f", &a);
                printf("Entre com b: ");
                scanf("%f", &b);
                printf("Entre com a precisao: ");
                scanf("%f", &e);
                printf("Entre com o x0");
                scanf("%f", &x0);
                printf("Entre com o x1");
                scanf("%f", &x1);
                h = polinomio(x0);
                h = mod(h);
                if(h<e) {
                    x = x0;
                    fx = polinomio(x);
                    printf("\nx = %f e f(x) = %f",x,fx);
                }
                secante(a, b, e, x0, x1);
                break;
                
            default:
                printf("Opcao invalida!");
                break;
            }
        }while(opc!=5);
    return 0;
}

int menu() {
    
    int ret;
    printf("f(x)=xˆ3-x-1\n");
    printf("(1) Bissecao\n");
    printf("(2) Posicao Falsa\n");
    printf("(3) Ponto Fixo\n");
    printf("(4) Newton\n");
    printf("(5) Secante\n");
    printf("(6) Sair\n");
    printf("\n\nEntre com a opcao:\n");
    scanf("%d", &ret);
    
    return ret;
}

float mod(float a) {
    float x;
    x=a*a;
    x=sqrt(x);
    return x;
}

float polinomio(float a) {
    float x;
    x = (a*a)*a;
    x = x-a;
    x = x-1;
    return x;
}
    
float quici(float a) {
    float x, y;
    y = (1.0/3.0);
    x = a+1;
    x = pow(x,y);
    return x;
}

float derivada(float a) {
    float x;
    x = (a*a)*3;
    x = x-1;
    return x;
}

void bissecao(float a, float b, float c){
    int cont = 0;
    float x,fx,fa,fb,s;
    do {
        cont = cont + 1;
        fa = polinomio(a);
        fb = polinomio(b);
        
        x = a+b;
        x = x/2;
        
        fx = polinomio(x);
        
        if(fx<0){
            a=x;
            s= b-a;
        }
        
        if(fx>0){
            b=x;
            s = b-a;
        }
        
        printf("\n iteracao: %d | b-a = %f | x = %f | f(x) = %f", cont, s, x, fx);
    } while(s>c);
}

void posicaoFalsa(float a, float b, float c) {
    int cont = 0;
    float x,fx,fa,fb,s,y,j,l,m;
    
    do{
        cont = cont + 1;
        fa = polinomio(a);
        fb = polinomio(b);
        y = fb-fa;
        j = a*fb;
        l = b*fa;
        x = j-l;
        x = x/y;
        
        fx = polinomio(x);
        m = mod(fx);
        
        if(fx<0){
            a=x;
            s= b-a;
        }
        
        if(fx>0){
            b=x;
            s = b-a;
        }
        
        printf("\n iteracao: %d | b-a = %f | x = %f | f(x) = %f", cont, s, x, fx);
    }while(m>=c);
}

void pontoFixo(float a, float b, float c, float x0){
    
    int cont = 0;
    float x,v,d,fx;
    do{
        cont = cont + 1;
        x = quici(x0);
        fx = polinomio(x);
        v = mod(fx);
        d = mod(d);
        if((v<c) || (d<c)){
            printf("\n iteracao: %d | x = %f | f(x) = %f", cont, x, fx);
            break;
        }
            x0 = x;
            printf("\n iteracao: %d | x = %f | f(x) = %f", cont,x,fx);
    }while ((v>c) || (d>c));
}

void newton(float a, float b, float c, float x0) {
    int cont = 0;
    float x,v,d,fx,w,k,h;
    do {
        cont = cont+1;
        w = polinomio(x0);
        k = derivada(x0);
        h = w/k;
        x = x0-h;
        fx = polinomio(x);
        v = mod(fx);
        d = x-x0;
        d = mod(d);
        
        if((v<c)||(d<c)) {
            printf("\n iteracao: %d | x = %f | f(x) = %f", cont,x,fx);
            break;
        }
        
        x0 = x;
        printf("\n iteracao: %d | x = %f | f(x) = %f", cont,x,fx);
    }while((v>c)||(d>c));
}

void secante(float a, float b, float c, float x0, float x1) {
    int cont = 0;
    float x,s,v,d,fx,w,k,h,j,l,t;
    j = polinomio(x1);
    j = mod(j);
    l = mod(l);
    if((j<c)||(l<c)){
        x = x1;
        fx = polinomio(x);
        printf("\nx= %f e f(x)= %f", x, fx);
    }
    
    do{
        cont = cont + 1;
        w = x1 - x0;
        k = polinomio(x1);
        h = polinomio(x0);
        t = k-h;
        k = k*w;
        x = x1-k;
        fx = polinomio(x);
        v = mod(fx);
        d = x-x1;
        d = mod(d);
        if ((v<c)||(d<c)) {
            printf("\n iteracao : %d | x = %f | f(x) = %f", cont, x, fx);
            break;
        }
        
        x0 = x1;
        x1 = x;
        printf("\n iteracao: %d | x = %f | f(x) = %f", cont,x,fx);
    }while((v>c)||(d>c));
}
