#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int jour;
  int mois;
  int année;
} date_t;

typedef struct {
    long code_voyage;
    char destination[30];
    date_t date_départ;
    date_t date_retour;
    int prix;
} voyage;

typedef struct noeud {
    voyage e;
    struct noeud *suiv;
};

struct noeud *head = NULL;
struct noeud *current = NULL;

void insérer(voyage v) {
   struct noeud *aux = (struct noeud*) malloc(sizeof(struct noeud));
   aux->e = v;
   aux->suiv = head;
   head = aux;
}

void ajouter_voyage(struct noeud *list_v){
    voyage v;
    printf("donner le code du voyage:\n");
    scanf("%ld",&v.code_voyage);
    printf("\ndonner la destination:\n");
    scanf("%s",&v.destination);
    printf("\ndonner la date de depart:\n annee:\n");
    scanf("%d",&v.date_départ.année);
    printf("\n mois:\n");
    scanf("%d",&v.date_départ.mois);
    printf("\njour:\n");
    scanf("%d",&v.date_départ.jour);
    printf("\ndonner la date de retour:\n annee:\n");
    scanf("%d",&v.date_retour.année);
    printf("\n mois:\n");
    scanf("%d",&v.date_retour.mois);
    printf("\n jour:\n");
    scanf("%d",&v.date_retour.jour);
    printf("donner le prix:\n");
    scanf("%d",&v.prix);
    insérer(v);
}

void afficher_voyage(struct noeud *list_v){
    struct noeud *aux = head;
    long c;
    printf("donner le code du voyage a afficher: \n");
    scanf("%ld",&c);
    while ((aux != NULL)&&(aux -> e.code_voyage != c)){
        aux = aux -> suiv;
    }
    if(aux==NULL){
        printf("ce voyage n'existe pas.\n");
    }
        else{
            printf("destination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d\n",aux->e.destination,aux->e.date_départ.jour,aux->e.date_départ.mois,aux->e.date_départ.année,aux->e.date_retour.jour,aux->e.date_retour.mois,aux->e.date_retour.année,aux->e.prix);
        } 
}

void supprimer_voyage(struct noeud *list_v){
    struct noeud *aux = head;
    struct noeud *pred = NULL;
    long c;
    printf("donner le code du voyage a supprimer: \n");
    scanf("%ld",&c);
    if(aux->e.code_voyage==c){
        head=aux->suiv;
        free(aux);
    }
    else{
            
        while ((aux != NULL)&&(aux -> e.code_voyage != c)){
            pred = aux;
            aux = aux -> suiv;
        }
        if(aux==NULL){
            printf("ce voyage n'existe pas.\n");
        }
        else{
            pred->suiv=aux->suiv;;
            free(aux);
        }
    }
}

void modifier_voyage(struct noeud *list_v){
    char ch[30];
    int i=0,j,m,a,aa,mm,jj,p;
    struct noeud *aux = head;
    long c;
    printf("donner le donner le code du voyage a modifier: \n");
    scanf("%ld",&c);
    while ((aux != NULL)&&(aux -> e.code_voyage != c)){
        aux = aux -> suiv;
    }
    if(aux==NULL){
        printf("ce voyage n'existe pas.\n");
    }
    else{
        while(i!=5){
            printf("donner le numéro de la modification à faire:\n");
            printf("1-Modifier destination\n2-Modifier la date de départ\n3-Modifier la date de retour\n4-Modifier le prix\n5-Exit.\n");
            scanf("%d",&i);
            switch(i){
                case 1:{
                    gets(ch);
                    printf("Donner la nouvelle destination:\n");
                    gets(ch);
                    strcpy(aux->e.destination,ch);
                    break;
                }
                case 2:{
                    printf("Donner la nouvelle date de depart:\n");
                    printf("Donner l'annee:\n");
                    scanf("%d",&a);
                    printf("Donner le mois:\n");
                    scanf("%d",&m);
                    printf("Donner le jour:\n");
                    scanf("%d",&j);
                    aux->e.date_départ.année=a;
                    aux->e.date_départ.mois=m;
                    aux->e.date_départ.jour=j;
                    break;
                }
                case 3:{
                    printf("Donner la date e retour:\n");
                    printf("Donner l'annee:\n");
                    scanf("%d",&aa);
                    printf("Donner le mois:\n");
                    scanf("%d",&mm);
                    printf("Donner le jour:\n");
                    scanf("%d",&jj);
                    aux->e.date_retour.année=aa;
                    aux->e.date_retour.mois=mm;
                    aux->e.date_retour.jour=jj;
                    break;
                }
                case 4:{
                    printf("Donner le nouveau prix:\n");
                    scanf("%d",&p);
                    aux->e.prix=p;
                    break;
                }
                case 5: break;
                default: printf("numero errone\n");
            }
        }  
    }
}
 void rechercher_voyage(struct noeud *list_v){
    int a1,m1,j1,a2,m2,j2,a,m,j;
    bool b=false;
    struct noeud *aux = head;
    printf("Donner la 1ere date:\n");
    printf("annee: ");
    scanf("%d",&a1);
    printf("mois: ");
    scanf("%d",&m1);
    printf("jour: ");
    scanf("%d",&j1);
    printf("Donner la 2eme date:\n");
    printf("annee: ");
    scanf("%d",&a2);
    printf("mois: ");
    scanf("%d",&m2);
    printf("jour: ");
    scanf("%d",&j2);
    while(aux!=NULL){
        a=aux->e.date_départ.année;
        m=aux->e.date_départ.mois;
        j=aux->e.date_départ.jour;
        if(a>a1 && a<a2){
            printf("code du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->e.code_voyage,aux->e.destination,aux->e.date_départ.jour,aux->e.date_départ.mois,aux->e.date_départ.année,aux->e.date_retour.jour,aux->e.date_retour.mois,aux->e.date_retour.année,aux->e.prix);
            b=true;
        }
        else{
            if(a==a1 && a<a2){
                if(m>m1){
                    printf("code du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->e.code_voyage,aux->e.destination,aux->e.date_départ.jour,aux->e.date_départ.mois,aux->e.date_départ.année,aux->e.date_retour.jour,aux->e.date_retour.mois,aux->e.date_retour.année,aux->e.prix);
                    b=true;
                }
                else{
                    if(m=m1 && j>=j1){
                        printf("code du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->e.code_voyage,aux->e.destination,aux->e.date_départ.jour,aux->e.date_départ.mois,aux->e.date_départ.année,aux->e.date_retour.jour,aux->e.date_retour.mois,aux->e.date_retour.année,aux->e.prix);
                        b=true;
                    }
                }

            }
            else{
                if(a==a1 && a==a2){
                    if(m>m1 && m<m2){
                        printf("code du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->e.code_voyage,aux->e.destination,aux->e.date_départ.jour,aux->e.date_départ.mois,aux->e.date_départ.année,aux->e.date_retour.jour,aux->e.date_retour.mois,aux->e.date_retour.année,aux->e.prix);
                        b=true;
                    }
                    else{
                        if((m==m1 && j>=j1)||(m==m2 && j<=j2)){
                            printf("code du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->e.code_voyage,aux->e.destination,aux->e.date_départ.jour,aux->e.date_départ.mois,aux->e.date_départ.année,aux->e.date_retour.jour,aux->e.date_retour.mois,aux->e.date_retour.année,aux->e.prix);
                        b=true;
                        }
                       
                    }
                }
                else{
                    if(a>a1 && a==a2){
                        if(m<m2){
                            printf("code du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->e.code_voyage,aux->e.destination,aux->e.date_départ.jour,aux->e.date_départ.mois,aux->e.date_départ.année,aux->e.date_retour.jour,aux->e.date_retour.mois,aux->e.date_retour.année,aux->e.prix);
                        b=true;
                        }
                        else{
                            if(m==m2 && j<=j2){
                                printf("code du voyage: %ld\ndestination: %s\ndate depart: %d/%d/%d\ndate retour: %d/%d/%d\nprix: %d",aux->e.code_voyage,aux->e.destination,aux->e.date_départ.jour,aux->e.date_départ.mois,aux->e.date_départ.année,aux->e.date_retour.jour,aux->e.date_retour.mois,aux->e.date_retour.année,aux->e.prix);
                                b=true;
                            }
                        }
                    }
                }
            }
        }
        aux=aux->suiv;
    }
    if(b==false){
        printf("Il n'existe aucun voyage.");
    }
 }
int main(){
    int i,z=1;
    bool b=true;
    struct noeud *list_v = (struct noeud*) malloc(sizeof(struct noeud));
    list_v=head;
    while(z==1){
    
        while (b){
            printf("Donner le numero de la tache a faire: \n");
            printf(" 1:Ajouter un voyage. \n 2:Afficher la description d’un voyage. \n 3:Supprimer un voyage. \n 4:Modifier un voyage. \n 5:Rechercher les voyages disponibles selon les dates données.\n ");
            scanf("%d",&i);
            if(i<=5&&i>=1){
                b=false;
            }
        }
        switch (i){
            case 1: ajouter_voyage(list_v);
            break;
            case 2: afficher_voyage(list_v);
            break;
            case 3: supprimer_voyage(list_v);
            break;
            case 4: modifier_voyage(list_v);
            break;
            case 5: rechercher_voyage(list_v);
            break;
        }
        b=true;
        printf("Pour retourner vers le menu tappez: 1\nPour quitter tappez un autre nombre: \n");
        scanf("%d",&z);
    }
      
}