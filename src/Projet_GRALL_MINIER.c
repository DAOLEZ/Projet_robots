/* GRALL Arnaud - MINIER Thomas - groupe 601A */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//Pour les booléens
#include <string.h>
#include <glpk.h> // nous allons utiliser la bibliothèque de fonctions de GLPK 

/* Déclarations pour le compteur de temps CPU */
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

struct timeval start_utime, stop_utime;

// Structure de données contenant les données du problèmes
typedef struct {
	int nb_var;
	int nb_contr;
	int nb_mat;
	int taille_dist;
	int ** distancier;
} donnees;

// Structure contenant un cycle minimal et sa taille
typedef struct {
	int taille_cycle_min;
	int * min;
} cycle_min;

void crono_start()
{
	struct rusage rusage;
	
	getrusage(RUSAGE_SELF, &rusage);
	start_utime = rusage.ru_utime;
}

void crono_stop()
{
	struct rusage rusage;
	
	getrusage(RUSAGE_SELF, &rusage);
	stop_utime = rusage.ru_utime;
}

double crono_ms()
{
	return (stop_utime.tv_sec - start_utime.tv_sec) * 1000 +
    (stop_utime.tv_usec - start_utime.tv_usec) / 1000 ;
}

// Procédure lisant les données du problème depuis un fichier
void lecture_data(char *file, donnees *p) {
	printf("%s \n", "Ouverture du fichier de données :");
	FILE *fin; // Pointeur sur un fichier	
	int val;
	
	fin = fopen(file, "r"); // Ouverture du fichier en lecture
	
	/* Première ligne du fichier, on lit le nombre de variables puis le tableau de valeur */

	fscanf(fin, "%d", &val);
	p->taille_dist = val;
	p->distancier = (int **) malloc (p->taille_dist * sizeof(int *));
	int i,j;	
	for(i = 0; i < p->taille_dist; ++i){
		p->distancier[i] = (int *) malloc (p->taille_dist * sizeof(int ));
		for(j = 0; j < p->taille_dist; ++j){
			fscanf(fin, "%d",&val);
			p->distancier[i][j] = val;
		}
	}
	
	//Paramétrage des autres variables
	p->nb_var = p->taille_dist * p->taille_dist;
	p->nb_contr = 2 *  p->taille_dist;
	p->nb_mat = p->taille_dist * p->taille_dist * 2 - 2 * p->taille_dist; 
	printf("nb_var = %d, nb_cont = %d, nb_mat = %d \n", p->nb_var,p->nb_contr,p->nb_mat);  
	
	
	
	fclose(fin); // Fermeture du fichier
	printf("%s \n", "Fermeture du fichier de données : ");
}

// Fonction qui retourne le + petit cycle
/*
	Paramètres :
	- cycles : tableaux des cycles
	- taille : taille du tableau cycles
	- RETOURNE UNE STRUCTURE MIN contenant le cycle et sa taille
*/
cycle_min min_cycles(int * cycles, int taille) {
	printf("%s\n","!!CALCUL_CYCLE_MIN--ON" );
	int i, j;
	//tableau qui indique si on a déjà  parcouru l'arc
	bool * deja_lu = (bool *)malloc(taille * sizeof(bool));
	//tableau qui indique les débuts de cycles
	bool * est_debut_cycle = (bool *)malloc(taille * sizeof(bool));
	//tableau des cycles
	int * * c = (int * * )malloc(taille * sizeof(int*));
	//tableau des tailles de cycles
	int * taille_cycles = (int * )malloc(taille * sizeof(int));
	//nombre de cycles
	int nb_cycles = 0;

	//initialisation des valeurs des différents tableaux
	for(i = 0; i < taille; i++) {
		deja_lu[i] = false;
		est_debut_cycle[i] = false;
		c[i] = (int *)malloc(taille * sizeof(int));
		taille_cycles[i] = 2; // la taille min d'un cycle est de 2
	}
	//parcours du tableau des cycles
	int z = 0;
	for(i = 0; i < taille; i++) {
		// si l'arc n'a pas été lu
		if( (! deja_lu[i])) {
			int y = cycles[i];
			//on initialise les deux premières valeurs du cycle
			c[z][0] =  i;
			c[z][1] = cycles[i];
			//on a lu le premier arc
			deja_lu[i] = true;
			deja_lu[y] = true;
			//on note que i est un début de cycle
			est_debut_cycle[i] = true;
			est_debut_cycle[y] = true;
			// on incrémente le nombre de cycles
			nb_cycles++;
			j = 2;
			// tant que l'indice du cycle que l'on va lire n'a pas déjà  été lu
			while(deja_lu[cycles[y]] == false) {
				deja_lu[cycles[y]] = true; // on a lu l'arc
				est_debut_cycle[cycles[y]] = true;
				//on remplit les tableaux
				c[z][j] = cycles[y];
				taille_cycles[z]++;
				// on avance dans le parcours
				y = cycles[y];
				j++;
			}
			z++;
		}
	}
	printf("!!CALCUL_CYCLE_MIN-- NB_CYCLES: %d \n",nb_cycles);
	// Affichage pour du debug
	for(i = 0; i < nb_cycles; i++) {
		if(est_debut_cycle[i]) {
			printf("!!CALCUL_CYCLE_MIN-- cycle : (");
			for(j = 0; j < taille_cycles[i]; j++) {
				printf(" %d ", c[i][j]);					
			}
			printf(");\n");
		}
	}

	//recherche de l'indice du min sur taille_cycles
	int min_c = taille_cycles[0];
	int ind_min = 0;
	for(i = 1; i < nb_cycles; i++) {
		if(est_debut_cycle[i]) {
			if(taille_cycles[i] < min_c) {
				min_c = taille_cycles[i];
				ind_min = i;
			}
		}	
	}

	// on a trouvé le plus petit cycle et sa taille
	//Creation de la structure de retour
	cycle_min c_min;
	c_min.taille_cycle_min = min_c;
	printf("!!CALCUL_CYCLE_MIN-- C'est le cycle numéro :  %d de taille %d \n", ind_min + 1, c_min.taille_cycle_min );
	printf("!!CALCUL_CYCLE_MIN-- cycle : (");
	int * res = (int *)malloc (c_min.taille_cycle_min * sizeof(int));
	res = c[ind_min];
	for(i = 0; i < c_min.taille_cycle_min; i++){
		res[i] = c[ind_min][i];
		printf(" %d ", res[i]);
	}
	printf(");\n");
	c_min.min = res;

	//VERIFICATION AVEC LE CYCLE D'AVANT 
	//S'ILS SONT EGAUX, ON CHOISIT LE CYCLE SUIVANT

	printf("%s\n","!!CALCUL_CYCLE_MIN--LIBERATION_MEMOIRE" );
	//libération de la mémoire
	free(deja_lu);
	free(est_debut_cycle);
	free(c);
	free(taille_cycles);
	printf("%s\n","!!CALCUL_CYCLE_MIN--OFF" );

	return c_min;
}


int main(int argc, char *argv[])
{
	double temps;
	donnees datas;
	// à modifier en char file[256]; quand tous sera terminé
	char file[256];
	
	lecture_data(argv[1], &datas);
	
	int i, j;
	double z;
	int nbsol = 0; /* Compteur du nombre d'appels au solveur GLPK */ 
	int nbcontr = 0; /* Compteur du nombre de contraintes ajoutées pour obtenir une solution composée d'un unique cycle */
	int *ia = (int*)malloc((1 + datas.nb_mat) * sizeof(int));
	int *ja = (int*)malloc((1 + datas.nb_mat) * sizeof(int));
	double *ar = (double*)malloc((1 + datas.nb_mat) * sizeof(double));
	//matrice annexe
	double *x = (double*)malloc(datas.nb_var * sizeof(double));
	//Déclaration des tableaux pour les nouvelles contraintes.
	int * cycles = (int*)malloc(datas.taille_dist * sizeof(int)); // tableau des cycles
	
	cycle_min c_min;
	/* Déclarations à compléter... */

	crono_start(); /* Lancement du compteur (juste après le chargement des données à partir d'un fichier */

	glp_prob *prob; /* déclaration du pointeur sur le problème */
	prob = glp_create_prob(); /* allocation mémoire pour le problème */ 
	glp_set_prob_name(prob, "Robot"); /* affectation d'un nom */
	glp_set_obj_dir(prob, GLP_MIN); /* Il s'agit d'un problème de minimisation */

	glp_smcp parm;
	glp_init_smcp(&parm);
	parm.msg_lev = GLP_MSG_OFF; /* Paramètre de GLPK dans la résolution d'un PL en variables continues afin de couper les affichages (dans lesquels on se noierait) */

	glp_iocp parmip;
	glp_init_iocp(&parmip);
	parmip.msg_lev = GLP_MSG_OFF; /* Paramètre de GLPK dans la résolution d'un PL en variables entières afin de couper les affichages (dans lesquels on se noierait) */

	/* Les appels glp_simplex(prob,NULL); et gpl_intopt(prob,NULL); (correspondant aux paramètres par défaut) seront ensuite remplacés par glp_simplex(prob,&parm); et glp_intopt(prob,&parmip); */

	/* ----------------------------------- */

	/* Déclaration du nombre de contraintes (nombre de lignes de la matrice des contraintes) */
	
	glp_add_rows(prob, datas.nb_contr); 

	/* On commence par préciser les bornes sur les contraintes, les indices commencent à 1 (!) dans GLPK */

	for(i = 1; i <= datas.nb_contr; i++) {
		glp_set_row_bnds(prob, i, GLP_FX, 1.0, 1.0);
	}

	/* Déclaration du nombre de variables */
	
	glp_add_cols(prob, datas.nb_var); 

	/* On précise le type des variables, les indices commencent à 1 également pour les variables! */
	
	for(i = 1; i <= datas.nb_var ; i++) {
		glp_set_col_bnds(prob, i, GLP_DB, 0.0, 1.0);
		glp_set_col_kind(prob, i, GLP_BV);	/* les variables sont binaires */	
	}

	/* Définition des coefficients des variables dans la fonction objectif */

	for(i = 1; i <= datas.taille_dist; i++) {
		for(j = 1; j <= datas.taille_dist; j++) {
			glp_set_obj_coef(prob,(i - 1)*datas.taille_dist + j,datas.distancier[i-1][j-1]);
		}
	}

	/* Définition des coefficients non-nuls dans la matrice des contraintes, autrement dit les coefficients de la matrice creuse */

	int pos = 1;
	for(i = 1; i <= datas.taille_dist; i++) {
		for(j = 1; j <= datas.taille_dist; j++) {
			if (i!=j) {
				// Première moitié de la matrice
				ja[pos] = (i - 1)*datas.taille_dist + j;
				ia[pos] = i;
				ar[pos] = 1;
				pos++;

				// Deuxième moitié de la matrice
				ja[pos] = (i - 1)*datas.taille_dist + j;
				ia[pos] = datas.taille_dist + j;
				ar[pos] = 1;
				pos++;
			}
		}
	}

	/* Chargement de la matrice dans le problème */
	
	glp_load_matrix(prob, datas.nb_mat, ia, ja, ar); 

	/* Ecriture de la modélisation dans un fichier */

	glp_write_lp(prob, NULL, "robots.lp");

	/* Résolution, puis lecture des résultats */

	/* Résolution */
	puts("#--------- Résolution n°0 ---------#");
	glp_simplex(prob,NULL);	
	glp_intopt(prob,NULL); 
	z = glp_mip_obj_val(prob); /* Récupération de la valeur optimale. Dans le cas d'un problème en variables continues, l'appel est différent : z = glp_get_obj_val(prob); */
	for(i = 0; i < datas.nb_var; i++) x[i] = glp_mip_col_val(prob, i+1); /* Récupération de la valeur des variables, Appel différent dans le cas d'un problème en variables continues : for(i = 0;i < p.nbvar;i++) x[i] = glp_get_col_prim(prob,i+1); */

	puts("#-------------------#");
	printf("| z = %lf   |\n", z);
	puts("#-------------------#");
	for(i = 0; i < datas.nb_var;i++) {	
		int val = (int)(x[i] + 0.5);	
		printf("| x[%d,%d] = %d        |\n", i / datas.taille_dist, i % datas.taille_dist  , val); /* un cast est ajouté, x[i] pourrait être égal à 0.99999... */ 
		
		// Remplissage du tableau des cycles
		if(val == 1) {
			cycles[i % datas.taille_dist] = i / datas.taille_dist;
		}
	}

	// Affichage des cycles actuels
	puts("#-------------------#");
	puts("|    Cycles         |");
	puts("#-------------------#");
	for(i = 0; i < datas.taille_dist; i++) {
		printf("|    %d -> %d         |\n", i, cycles[i]);
	}
	puts("#-------------------#");
 
	// APPEL A LA FONCTION CALCULANT LE CYCLE MIN
	c_min = min_cycles(cycles,datas.taille_dist);

	//AFFICHAGE DES RESULTATS
	printf("Cycle minimal : (");
	for(i = 0; i < c_min.taille_cycle_min; i++){
		printf("%d",c_min.min[i]);
	}
	printf("); Taille: %d \n",c_min.taille_cycle_min);
	nbsol+=1;
	while(c_min.taille_cycle_min != datas.taille_dist) {

		nbsol += 1;
		nbcontr += 1;
		// ajout d'une contrainte
		datas.nb_contr = glp_add_rows(prob, 1);
		 
		datas.nb_mat += c_min.taille_cycle_min;
		glp_set_row_bnds(prob, datas.nb_contr, GLP_FX, c_min.taille_cycle_min - 1.0, c_min.taille_cycle_min - 1.0);

		// on complète la matrice
		ia = (int*)realloc(ia, (1 + pos + c_min.taille_cycle_min )*sizeof(int));
		ja = (int*)realloc(ja, (1 + pos + c_min.taille_cycle_min)*sizeof(int));
		ar = (double*)realloc(ar, (1 + pos + c_min.taille_cycle_min)*sizeof(double));

		for(i = 0; i < c_min.taille_cycle_min; i++) {
				ja[pos] = c_min.min[i]*datas.taille_dist + (c_min.min[(i + 1)%c_min.taille_cycle_min] + 1);
				ia[pos] = datas.nb_contr;
				ar[pos] = 1;
				pos++;
		}
		
		// on relance le simplexe
		printf("#--------- Résolution n°%d ---------#\n", nbsol);
		for(i = 0; i < c_min.taille_cycle_min; i++){
			printf("%d ",c_min.min[i]);
		}
		printf("); Taille: %d \n",c_min.taille_cycle_min);
		
		glp_load_matrix(prob, datas.nb_mat, ia, ja, ar); 
		
		glp_write_lp(prob, NULL, "robots.lp");
		glp_simplex(prob,NULL);	
		glp_intopt(prob,NULL); 
		z = glp_mip_obj_val(prob);
		

		puts("#-------------------#");
		printf("| z = %lf   |\n", z);
		puts("#-------------------#"); 
		//Récupération des valeurs
		for(i=0;i<datas.nb_var;i++){
			if(glp_mip_col_val(prob, i+1) > 0.0){
				int node = i/datas.taille_dist;
				int nxt_node = i%datas.taille_dist;
				x[node] = nxt_node;
				cycles[node] = nxt_node;
			}
		}

		// on recalcule le cyc min
		// Affichage des cycles actuels
		puts("#-------------------#");
		puts("|    Cycles         |");
		puts("#-------------------#");
		for(i = 0; i < datas.taille_dist; i++) {
			printf("|    %d -> %d         |\n", i, cycles[i]);
		}
		puts("#-------------------#");
	 
		// APPEL A LA FONCTION CALCULANT LE CYCLE MIN
		c_min = min_cycles(cycles,datas.taille_dist );

	}

	/* ----------------------------------- */
	
	/* Résolution achevée, arrêt du compteur de temps et affichage des résultats */
	crono_stop();
	temps = crono_ms()/1000,0;

	printf("\n");
	puts("Résultat Final:");
	puts("-----------");
	/* Affichage de la solution sous la forme d'un cycle avec sa longueur à ajouter */
	printf("Temps : %f\n", temps);	
	printf("Nombre d'appels à GPLK : %d\n", nbsol);
	printf("Nombre de contraintes ajoutées : %d\n", nbcontr);

	/* Libération de la mémoire */
	glp_delete_prob(prob);

	free(ia);
	free(ja);
	free(ar);
	free(cycles);
	for(i = 0; i < datas.taille_dist; i++) {
		free(datas.distancier[i]);
	}
	free(datas.distancier);
	free(x);

}
