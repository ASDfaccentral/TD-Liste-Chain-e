#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <malloc.h>
 typedef struct elt 
{
  
int data;
   
struct elt *svt;
 
} liste;

 
 
liste * creer_lcc (liste * tete) 
{
  liste * new_node, *ptr;
  int num;
  printf ("\n Entez -1 pour finir la création de la liste");
  printf ("\n Entrez une valeur : ");
  scanf ("%d", &num);
  while (num != -1)
    {
      new_node = (liste *) malloc (sizeof (liste));
      new_node->data = num;
      if (tete == NULL){new_node->svt = NULL;
	                    tete = new_node;}
            else{ptr = tete;
	             while (ptr->svt != NULL)
	             ptr = ptr->svt;
	             ptr->svt = new_node;
	             new_node->svt = NULL;
	             }
      printf ("\n Entrez une valeur : ");
      scanf ("%d", &num);
     }
  return tete;
}


 
 
 
 
liste * Suppoccurance (liste * L, int val) 
{
  liste * p;
  if (L == NULL) return NULL;
   else if (L->data != val) {L->svt = Suppoccurance (L->svt, val);}
            else {p = L;		
                  free (p);
                  L = Suppoccurance (L->svt, val);
                  }
  
   return (L);
}


 
 
 
liste * Supnegapair (liste * L) 
{
  liste * p;
  int val;
  if (L != NULL){val = (-1) * (L->data);
                 if ((L->data < 0) && (val % 2 == 0)){ p = L;
	                                                   free (p);
	                                                   L = Supnegapair (L->svt);}
                     else L->svt = Supnegapair (L->svt);
    
                }
return (L);
}


 
 
 
 
liste * Sommesupp (liste * L) 
{
  liste * p;
  if ((L->svt == NULL) || (L == NULL)) {return L;}
   else{
         L->svt->data = L->data + L->svt->data;
         p = L->svt;
         free (L);
         return (Sommesupp (p));
        }
}


 
 
 
void Suppdouble (liste * L) 
{
  if (L != NULL){L->svt = Suppoccurance (L->svt, L->data);
                 Suppdouble (L->svt);}

}


 
 
 
 
 
void paireImpaire (liste ** L, liste ** Lp, liste ** Limp) 
{
  liste * p;
  if ((*L) != NULL){if (((*L)->data) % 2 == 0)	{ p = (*L)->svt;
                                                  (*L)->svt = (*Lp);
                                                  (*Lp) = (*L);
                                                  (*L) = p;
                                                  paireImpaire (L, Lp, Limp);
                                                  }
      
 
                        else{ p = (*L)->svt;
	                          (*L)->svt = (*Limp);
	                          (*Limp) = (*L);
	                          (*L) = p;
	                          paireImpaire (L, Lp, Limp);
                             }
                    }
}


 
 
 
liste * reverse (liste * head) 
{
  if (head->svt == NULL) return head;
  else { liste * newhead = reverse (head->svt);
         head->svt->svt = head;
         head->svt = NULL;
         return newhead;
        }
}


void INVERSER ()
{
 liste * tete = NULL, *p;
 printf ("Donnez les information de la liste à inverser");
  tete = creer_lcc (tete);
  printf ("\nLa liste avant traitement\n");
  p = tete;
  while (p != NULL) {
                     printf ("%d\t", p->data);
                     p = p->svt;}
  tete = reverse (tete); 
  printf ("\nLa liste  Aprés traitement\n");
  p = tete;
  while (p != NULL) {
                     printf ("%d\t", p->data);
                     p = p->svt;}
}

 
 
liste * minimum (liste * L) 
{
  liste * p;
  if ((L->svt == NULL) || (L == NULL)) return (L);
   else {p = minimum (L->svt);
         if ((p->data) > (L->data)) return (L);
         else return (p);
        }
}


void trier (liste * L) 
{
  liste * p;
  int val;
  if (L->svt != NULL) {p = minimum (L);
                       val = p->data;
                       p->data = L->data;
                       L->data = val;
                       trier (L->svt);
                       }
}


liste * pos (liste * L1, liste ** L2) 
{
  liste * p;
  if (L1 != NULL){if (L1->data < 0){p = L1->svt;
                                    L1->svt = (*L2); 
                                    (*L2) = L1;
                                    L1 = pos (p, L2);
                                    }
      
                    else {L1->svt = pos (L1->svt, L2);}
                   }
  return (L1);
}


 
 
 
liste * neg (liste * L1, liste ** L2) 
{
  liste * p;
  if (L1 != NULL){if (L1->data >= 0){p = L1->svt;
	                                 L1->svt = (*L2);
	                                 (*L2) = L1;
	                                 L1 = neg (p, L2);
	                                 }
                    else{L1->svt = neg (L1->svt, L2);}
                  }
  return (L1);
}


 
 
 
 
void Fragmenter () 
{
 liste * tete = NULL, *L1 = NULL, *L2 = NULL, *p;
 printf ("Donnez les information de la liste à fragmenter");
  tete = creer_lcc (tete);
  printf ("\nLa liste de départ avant traitement\n");
  p = tete;
  while (p != NULL) {
                     printf ("%d\t", p->data);
                     p = p->svt;}
  
 printf ("\nLa liste des éléments paires\n");
 paireImpaire (&tete, &L1, &L2);
 p = L1;
 while (p != NULL) {printf ("%d\t", p->data);
                    p = p->svt;
                    }
  
 printf ("\nLa liste des éléments impaires\n");
 p = L2;
 while (p != NULL){printf ("%d\t", p->data);
                   p = p->svt;
                  }
  printf ("\nLa liste de départ aprés traitement\n");
  p = tete;
  while (p != NULL){printf ("%d\t", p->data);
                    p = p->svt;
                    }
}


void Trier_liste () 
{
  liste * tete = NULL, *p;
  printf ("Donnez les information de la liste à  Trier");
  tete = creer_lcc (tete);
  printf ("\nListe avant trie\n");
  p = tete;
  while (p != NULL) {printf ("%d\t", p->data);
                     p = p->svt;
                     }
  printf ("\nListe trier\n");
  trier (tete);
  p = tete;
  while (p != NULL)
    {
      printf ("%d\t", p->data);
      p = p->svt;
    }

}


 
 
 
void SUPPRIMERDOUBLANT () 
{
  
  liste * tete = NULL, *p;
  printf("Donnez les information de la liste qu'on utilise pour supprimer les doublants");
  tete = creer_lcc (tete);
  printf ("\nListe avant suppression\n");
  p = tete;
  while (p != NULL){printf ("%d\t", p->data);
                    p = p->svt;
                   }
  printf ("\nListe aprés suppression\n");
  Suppdouble (tete);
  p = tete;
  while (p != NULL)
    {
      printf ("%d\t", p->data);
      p = p->svt;
        
    }

}


 
 
 
 
void SUPPRIMERNEGPAIRE () 
{
 liste * tete2 = NULL, *p;
  printf("Donnez les information de la liste qu'on utilise pour supprimer les negative pairs");
  tete2 = creer_lcc (tete2);
  printf ("\nListe avant suppression\n");
  p = tete2;
  while (p != NULL){
                     printf ("%d\t", p->data);
                     p = p->svt;
                    }
  printf ("\n Aprés suppression \n");
  tete2 = Supnegapair (tete2);
  p = tete2;
  while (p != NULL){printf ("%d\t", p->data);
                    p = p->svt;
                    }
 
}


 
 
 
 
void TRAITEMENTNEGPOS () 
{
  liste * Lp = NULL, *Ln = NULL, *p;
  printf ("Donnez les information de la premiere liste");
  Lp = creer_lcc (Lp);
  printf ("Donnez les information de la deuxième liste");
  Ln = creer_lcc (Ln);
  printf ("\n Première liste avant suppression\n");
  p = Lp;
  while (p != NULL){printf ("%d\t", p->data);
                    p = p->svt;
                    }
  printf ("\n Deuxième liste avant suppression\n");
  p = Ln;
  while (p != NULL){printf ("%d\t", p->data);
                    p = p->svt;
                    }
  printf ("\n");
  Lp = pos (Lp, &Ln);
  Ln = neg (Ln, &Lp);
  printf ("\n Première liste aprés suppression\n");
  p = Lp;
  while (p != NULL){printf ("%d\t", p->data);
                    p = p->svt;}
  printf ("\n");
  printf ("\n Deuxième liste aprés suppression\n");
  p = Ln;
  while (p != NULL) {printf ("%d\t   ", p->data);
                     p = p->svt;
                    }
}


 
void SOMMERLISTE () 
 
{
  liste * tete2 = NULL, *p;
  printf("Donnez les information de la liste qu'on utilise pour Sommer la liste");
  tete2 = creer_lcc (tete2);
  printf ("\n La somme de la liste \n");
  tete2 = Sommesupp (tete2);
  p = tete2;
  while (p != NULL){printf ("%d\t", p->data);
                    p = p->svt;}

}


 
int main () 
{
  
 int option;
 clrscr ();
 do
        {printf ("\n\n *****MENU PRINCIPALE *****");
         printf	("\n 6: Inverser une liste chainée.");
         printf	("\n 7: Fragmenter une liste en deux listes pairs et impairs.");
         printf ("\n 8: Trier une liste dans l'ordre croissant.");
         printf ("\n 9: Supprimer tous les doublons d'une liste.");
         printf ("\n 11: Supprimer tous les éléments négatifs pairs d'une liste.");
         printf ("\n 12: Transformer deux listes distinctes d'éléments entiers en deux listes une d'éléments positifs et l'autre d'éléments négatifs.");
         printf ("\n 13: Rendre une liste en un seul élément qui représente la somme de tous les éléments de la liste initiale.");
         printf ("\n 14: Sortir");
         printf ("\n\n Entez votre choix : ");
         scanf ("%d", &option);
         switch (option)
	     {case 6: INVERSER();break;
	     case 7: Fragmenter (); break;
	     case 8: Trier_liste ();break;
	     case 9:SUPPRIMERDOUBLANT ();break;
	     case 11:SUPPRIMERNEGPAIRE ();break;
	     case 12:TRAITEMENTNEGPOS ();break;
	     case 13:SOMMERLISTE ();break;
	     }
         }
  while (option != 14);
  getch ();

}


 
 
