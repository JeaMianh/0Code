#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
typedef struct Polynomial
{
    int coefficient;
    int exponent;
    struct Polynomial *next;
}POLYNOMIAL,*polynomial;
 
 
polynomial create(int n){
    polynomial head,q,p;
    head = q =(polynomial)malloc(sizeof(POLYNOMIAL));
    head->next = NULL;
    int i;
    for(i=0;i<n;i++){
    	  p=(polynomial)malloc(sizeof(POLYNOMIAL));
        cin>>p->coefficient>>p->exponent;
        p->next=NULL;
        q->next=p;
        q=p;
 
    }
    return head;
}
 
polynomial PolynomialOperate(polynomial p1,polynomial p2,int t){
    polynomial head,q,p;
    head = q = (polynomial)malloc(sizeof(POLYNOMIAL));
    polynomial a,b;
    a=p1->next;
    b=p2->next;
 
    while (a!=NULL&&b!=NULL)
    {
        p=(polynomial)malloc(sizeof(POLYNOMIAL));
        p->next=NULL;
        if(a->exponent<b->exponent){
            p->exponent=a->exponent;
            p->coefficient=a->coefficient;
            a=a->next;
        }
        else if(a->exponent>b->exponent){
            p->exponent=b->exponent;
            p->coefficient=b->coefficient;
            b=b->next;
        }
        else{
            p->exponent=a->exponent;
            if(t==0){
                p->coefficient=a->coefficient+b->coefficient;
            }
            else if(t==1){
                p->coefficient=a->coefficient-b->coefficient;
            }
            a=a->next;
            b=b->next;
        }
        q->next=p;
        q=p;
    }
 
    while(a!=NULL){
        p=(polynomial)malloc(sizeof(POLYNOMIAL));
        p->next = NULL;
        p->exponent = a->exponent;
        p->coefficient = a->coefficient;
        q->next=p;
        q=p;
        a=a->next;
    }
 
    while(b!=NULL){
        p=(polynomial)malloc(sizeof(POLYNOMIAL));
        p->next=NULL;
        p->exponent=b->exponent;
        if(t==0){
            p->coefficient=b->coefficient;
        }
        else if(t==1){
            p->coefficient=-b->coefficient;
        }
        q->next=p;
        q=p;
        b=b->next;
    }
    return head;
}
 
void Print_Polynomial(polynomial poly){
    polynomial p=poly->next;
    int cnt = 0;
    while (p!=NULL)
    {
 
        if(p->coefficient>0&&cnt!=0)
            cout<<"+";
 
        if(p->coefficient==0){
            p=p->next;
            continue;
        }
 
        else if(p->coefficient==1){
            if(p->exponent==0){
                cout<<"1";
                cnt++;
            }
            else if(p->exponent==1){
                cout<<"x";
                cnt++;
            }
            else{
                cout<<"x^"<<p->exponent;
                cnt++;
            }
        }
 
        else if(p->coefficient==-1){
            if(p->exponent==0){
                cout<<"-1";
                cnt++;
            }else if(p->exponent==1){
                cout<<"-x";
                cnt++;
            }else{
                cout<<"-x^"<<p->exponent;
                cnt++;
            }
        }
        else{
            if(p->exponent==0){
                cout<<p->coefficient;
                cnt++;
            }
            else if(p->exponent==1){
                cout<<p->coefficient<<"x";
                cnt++;
            }
            else{
                cout<<p->coefficient<<"x^"<<p->exponent;
                cnt++;
            }
        }
        p=p->next;
    }
    if(cnt==0){
        cout<<"0";
        return ;
    }
}
 
int main(){
    int n,m,t;
    polynomial head;
    polynomial p1,p2;
    cin>>n>>m>>t;
    p1 = create(n);
    p2 = create(m);
    head=PolynomialOperate(p1,p2,t);
    Print_Polynomial(head);
}