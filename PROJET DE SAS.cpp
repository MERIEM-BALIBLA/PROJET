#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Ntache = 0,complete = 0,incomplete = 0;

//structure date 
struct date {
    int jour;
    int mois;
    int annee;
};

//structure de tache
struct tache{
	int identifiant;
	char titre[100];
	char description[100];
	struct date deadline;
	char statut[100];
};

//declaration des variable globals 
struct tache taches[100];
struct date systeme = {25, 9, 2023};

void Menu(){
    printf("                                      --------------*MESNU*--------------\n");
    printf("\n              choisir la fonction que vous voullez : \n");
    printf("                    1. Ajouter une nouvelle tache\n");
    printf("                    2. Ajouter plusieurs tâches\n");
    printf("                    3. Afficher la liste de toutes les taches \n");                    
    printf("                         1.1. Trier les taches par ordre alphabetique\n");            
    printf("                         1.2. Trier les taches par deadline\n");                        
    printf("                         1.3. Afficher les taches dont le deadline est dans 3 jours ou moins\n");               
    printf("                    4. Modifier une tache\n");             
    printf("                         4.1. Modifier la description d une tache\n");
    printf("                         4.2. Modifier le statut d une tache\n");                       
    printf("                         4.3. Modifier le deadline d une tache\n");                    
    printf("                    5. Supprimer une tache par identifiant\n");                       
    printf("                    6. Rechercher les tches\n");           
    printf("                         6.1. Rechercher une tache par son Identifiant\n");             
    printf("                         6.2. Rechercher une tache par son Titre\n");                   
    printf("                    7. Statistiques\n");   
    printf("                         7.1. Afficher le nombre total des taches\n");                  
    printf("                         7.2. Afficher le nombre de taches completes et incompletes\n"); 
    printf("                         7.3. Afficher le nombre de jours restants jusqu'au delai de chaque tache\n");
    printf("                      -----------------------------------------------------------------\n");
}

//ajouter une tache---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void ajouter_une_tache(){
    printf("\tEntrez le numero d'identification : ");
    scanf("%d", &taches[Ntache].identifiant);

    printf("\tEntrez l'intitule de la tache : ");
    scanf(" %[^\n]s", taches[Ntache].titre);

    printf("\tFaites une description rapide : ");
    scanf(" %[^\n]s", taches[Ntache].description);

    printf("\tEntrez la date limite pour la tache (journée mois annee): ");
	scanf("%d %d %d", &taches[Ntache].deadline.jour, &taches[Ntache].deadline.mois, &taches[Ntache].deadline.annee);
    int N;
    printf("\tRamener l'etat de la tache a 1 = a executer 2 = en cours 3 = finalise : ");
    scanf("%d", &N);

	//statut de la tache
    switch (N) {
        		case 1:
            			strcpy(taches[Ntache].statut, "a executer");
            			
            			//Incrémenter le nombre des taches incompletes
            			incomplete++;
        		break;
        		case 2:
            			strcpy(taches[Ntache].statut, "en cours");
            			
            			//Incrémenter le nombre des taches completes
            			complete++;
        		break;
        		case 3:
            			strcpy(taches[Ntache].statut, "finalise");
            			
            			//Incrémenter le nombre des taches incompletes
            			incomplete++;
            	break;
    			}

    printf("\tL'ajout de la tache a ete effectue avec succes..\n");
    
    // Incrémenter le nombre total de tâches
    Ntache++; 
				}
//ajouter plusieurs taches --------------------------------------------------------------------------------------------------------------------------------------------------------------

void ajouter_plusieurs_Tache() {
    int i;
    int Ntache;
    printf("\tPrecisez le nombre de taches qu'il faut ajouter : ");
    scanf("%d",&Ntache);
    for (int i = 0; i < Ntache; i++) {
        	printf("\ttache %d :\n", i + 1);
        	
        	// Utilisez la fonction ajouter_une_tache pour ajouter les tâches
        	ajouter_une_tache(); 
    								 }
								}
//affichage simple des taches------------------------------------------------------------------------------------------------------------------------------------------
void affichage() {
    int i;
    for (i = 0; i < Ntache; i++) {
        	printf("\t\t\t\t\t\t\t%d\t", taches[i].identifiant);
        	printf("%s\t", taches[i].titre);
        	printf("%s\t", taches[i].description);
        	
        	// Affichage de la deadline
        	printf("%d/%d/%d\t", taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee);
        	printf("%s\n", taches[i].statut);
       							 }
				}
//affichage par tri----------------------------------------------------------------------------------------------------------------------------------------------
void triTache(){
	int i,j;
	int cas;
  	printf("\tTri selon :");
  	scanf("%d", &cas);
 	switch (cas){
    			case 1 : printf("\t3.1. Tri des taches dans l'ordre alphabetique :\n"); 
				    for(i = 0;i < Ntache;i++){
				 		for(j =i+1;j < Ntache;j++){
				 			
				 			//comparer de chaine de caractere 
				 			if(strcmp(taches[i].titre,taches[j].titre) > 0){
            					struct tache reference;
								reference = taches[i];
            					taches[i] = taches[j];
            					taches[j] = reference;
   				 														   }
												  }
						affichage(); break;
				 							}
					
				break;
    	case 2 : 
				printf("\t3.2.Trier les taches en fonction de la date limite :\n");
    			for (i = 0; i < Ntache; i++) {
        			for (j = i + 1; j < Ntache; j++) {
        				
            			// Calculer les jours restants
            			int jours_restants_i = (taches[i].deadline.annee - systeme.annee) * 365 + (taches[i].deadline.mois - systeme.mois) * 30 + (taches[i].deadline.jour - systeme.jour);
            			int jours_restants_j = (taches[j].deadline.annee - systeme.annee) * 365 + (taches[j].deadline.mois - systeme.mois) * 30 + (taches[j].deadline.jour - systeme.jour);
						
						//affectation
            			if (jours_restants_i > jours_restants_j) {
                			struct tache reference = taches[i];
                			taches[i] = taches[j];
                			taches[j] = reference;
            													 }
        			    					}
        				affichage();
        				break;	
    										 }
    	break;
    	case 3 : printf("\t3.3. Affichage des taches avec un delai de 3 jours maximum :\n"); 
				 for(i = 0;i < Ntache;i++){
				 	
				 	 int jours_restants = (taches[i].deadline.annee - systeme.annee) * 365 +(taches[i].deadline.mois - systeme.mois) * 30 +(taches[i].deadline.jour - systeme.jour);
				 	 
        			// Vérifiez si le nombre de jours restants est inférieur ou égal à 3
        			if (jours_restants <= 3) {
           	 			printf("\t\t\t\t\t\t\t%d\t", taches[i].identifiant);
            			printf("%s\t", taches[i].titre);
            			printf("%s\t", taches[i].description);
            			
            			// Affichage de la deadline
            			printf("%d/%d/%d\t", taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee);
            			printf("%s\n", taches[i].statut);
       					 }
				 }
		break;}
		}

//fonction de recherche--------------------------------------------------------------------------------------------------------------------------------

void recherche(){
	
	int methodeRecherche,i;
	char title[100];
	int identifiant;
	printf("\tRecherche selon :");
	scanf("%d",&methodeRecherche);
	switch  (methodeRecherche){
								case 1 :
										//l'identifiant
										printf("\tentrer l'identifiant :");
										scanf("%d",&identifiant);
										for(i = 0;i < Ntache;i++){
											if(taches[i].identifiant == identifiant)
												printf("\t\t\t\t\t\t\t%d %s %s %d %s\n",taches[i].identifiant,taches[i].titre,taches[i].description,
																	taches[i].deadline,taches[i].statut);
											}
								break;
								case 2 :
										//titre
										printf("\tsaisir le titre :");
										scanf("%s",title);
										for(i = 0;i < Ntache;i++){
											if(strcmp(taches[i].titre,title)==0)
												printf("\t\t\t\t\t\t\t%d %s %s %d %s\n",taches[i].identifiant,taches[i].titre,taches[i].description,
																	taches[i].deadline,taches[i].statut);
												}
								break;
							}
}


//fonction moddifier-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void modifier() {
	int i;
    int identifiant_modification,elementaModifier;
    char nouvelle_description[100],nouvelle_statut[100];
	int nouvelle_deadline;
	
	//tache a modifier 
    printf("\tEntrez l'identificateur de la tache a modifier : ");
    scanf("%d", &identifiant_modification);

    // Recherche de la tâche par identifiant
    for (i = 0; i < Ntache; i++) {
        if (taches[i].identifiant == identifiant_modification) {
			
           	//choisir un element 
            printf("\tDonner l'element qui doit etre modifie :");
            scanf("%d",&elementaModifier);
            
            switch (elementaModifier){
            							case 1 :
            									printf("\tTâche trouvée. Entrez la nouvelle description : ");
           		 								scanf(" %[^\n]s", nouvelle_description);

            									// Mettre à jour la description de la tâche
            									strcpy(taches[i].description, nouvelle_description);
            									printf("\tLa description de la tache a ete modifiee avec succes: %s\n",nouvelle_description);
           								break; 
           								case 2 :
           										printf("\tTache trouvee. Entrez la nouvelle statut : ");
           		 								scanf(" %[^\n]s", nouvelle_statut);
           		 		
           		 								// Mettre à jour la statut de la tâche
           		 								strcpy(taches[i].statut, nouvelle_statut);
           		 								printf("\tLa statut de la tache a ete modifiee avec succes: %s\n",nouvelle_statut);
           								break;
           								case 3 :
           										printf("\tTache trouvee. Entrez le nouveau deadline : ");
           		 								scanf(" %d", &nouvelle_deadline);
        
           		 								// Mettre à jour le deadline de la tâche
           		 								taches[i].deadline.jour = nouvelle_deadline;
           		 								printf("\tle nouveau deadline de la tache a ete modifiee avec succes : %d\n",nouvelle_deadline);
           								break;
        							}
        								
        													}
    	else 
        		printf("\t\tTache non trouvee avec l'identifiant specifie.\n");
        break;
        }
    }
//fonction supprimer---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void supprimer() {
	int identifiant_a_supprimer;
    int i;
	printf ("\tDonner l identifiant :");
	scanf("%d",&identifiant_a_supprimer);
    for (i = 0; i < Ntache; i++) {
        if (taches[i].identifiant == identifiant_a_supprimer) {
        	Ntache--;// Décrémenter le nombre total de tâches
            // Déplacer toutes les tâches suivantes vers le haut pour remplir le trou
            for (int j = i; j < Ntache - 1; j++) {
                taches[j] = taches[j + 1];
            }
            printf("\tLa tache a ete supprimee avec succes.\n");
            break; 
        }
    	else printf("\tAucune tache trouvee avec l'identifiant specifi.\n");
    }
    
}
//fonction statistique----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void statistique(){
	int cas,i;
	printf("\tChoisir une fonction :");
	scanf("%d",&cas);
	switch (cas){
			//nombres des taches 
			case 1 :
					printf("\tle nombre des taches : %d",Ntache);
			break;
			//nombre des taches completes et incompletes
			case 2 :
					printf("\tle nombre des taches completes : %d \n",complete);
					printf("\tle nombre des taches incompletes : %d %d ",incomplete,taches[i].identifiant);
	
			break;
			//nombre des heures restants 
			case 3 :
					for(i = 0;i < Ntache; i++){
						 int jours_restants_i = (taches[i].deadline.annee - systeme.annee) * 365 +
                                       (taches[i].deadline.mois - systeme.mois) * 30 +
                                       (taches[i].deadline.jour - systeme.jour);
						printf("\tle nombre des jours restants de la tache %d : %d \n",taches,jours_restants_i);
					}
			break;
	}
}
//MAIN-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(){
	int fonction;
	do{
		Menu();
		printf("\tSaisie la fonction :");
    	scanf("%d", &fonction);
		switch (fonction) 
    					{
      					case 1 : printf("\t1. Ajouter une nouvelle tache\n");
            			 		 ajouter_une_tache();
	  					break;
					    case 2 : printf("\t2. Ajouter plusieurs taches\n");
					               			 ajouter_plusieurs_Tache();
											 break;
					    case 3 : printf("\t3. Afficher la liste de toutes les taches\n"); 
					               			triTache();
						break;
					    case 4 : printf("\t4. Modifier une tache :\n");
									        modifier(); break;
					    case 5 : printf("\t5. Supprimer une tache par identifiant"); 
						  					supprimer(); break;
					    case 6 : printf("\t6. Rechercher les taches"); 
											recherche(); break;
					    case 7 : printf("\t7. Statistiques");
											statistique();
					    break;
					      }
					
	} while(fonction != 0);
	return 0;
}
