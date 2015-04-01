# Makefile permettant de lancer la résolution du projet
# Auteur : Arnaud Grall, Thomas Minier, groupe 601A
BASE= "resultats"
REP = "exemple"
RES = $(BASE)/$(REP)
ALL_PLATS = plat10 plat20 plat30 plat40 plat50 plat60 plat70 plat80 plat90 plat100 plat110 plat120 plat130 plat140 plat150
ALL_RELIEFS = relief10 relief20 relief30 relief40 relief50 relief60 relief70 relief80 relief90 relief100 relief110 relief120 relief130 relief140 relief150
# Résolution et exécution	
all: robots run_all

# Résolution de l'exemple
exemple:
	$(eval RES = $(BASE)/$(REP))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/exemple.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;

# Résolution d'un fichier plat (de plat10 à plat150)
plat%:
	$(eval RES = $(BASE)/$@)
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/$@.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;

# Résolution d'un fichier relief (de relief10 à relief150)
relief%:
	$(eval RES = $(BASE)/$@)
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots relief/$@.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;

# Résolution de tous les fichiers
run_all: exemple run_plats run_reliefs

# Résolution de tous les plats
run_plats: $(ALL_PLATS)

# Résolution de tous les reliefs
run_reliefs: $(ALL_RELIEFS)

# Compilation du programme de résolution
robots: clean
	gcc -g Projet_GRALL_MINIER.c -o robots -lglpk -lm

# Nettoyage de l'exécutable
.PHONY: clean
clean:
	@if [ -e robots ] ; then rm -rf robots; fi;