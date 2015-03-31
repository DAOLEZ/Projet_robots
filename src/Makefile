# Makefile permettant de lancer la résolution du projet
# Auteur : Arnaud Grall, Thomas Minier, groupe 601A
BASE= "resultats"
REP = "exemple"
REP1 = "plat10"
REP2 = "plat20"
REP3 = "plat30"
REP4 = "plat40"
REP5 = "plat50"
REP6 = "plat60"
REP7 = "plat70"
REP8 = "plat80"
REP9 = "plat90"
REP10 = "plat100"
REP11 = "plat110"
REP12 = "plat120"
REP13 = "plat130"
REP14 = "plat140"
REP15 = "plat150"
RES =$(BASE)/$(REP)
# Résolution et exécution
	
all: robots

run_exemple:
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/exemple.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_10:
	$(eval RES = $(BASE)/$(REP1))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat10.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_20:
	$(eval RES = $(BASE)/$(REP2))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat20.dat >> $(RES)/resultat_glpk
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_30:
	$(eval RES = $(BASE)/$(REP3))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat30.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_40:
	$(eval RES = $(BASE)/$(REP4))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat40.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_50:
	$(eval RES = $(BASE)/$(REP5))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat50.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_60:	
	$(eval RES = $(BASE)/$(REP6))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat60.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_70:	
	$(eval RES = $(BASE)/$(REP7))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat70.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_80:	
	$(eval RES = $(BASE)/$(REP8))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat80.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_90:	
	$(eval RES = $(BASE)/$(REP9))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat90.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_100:	
	$(eval RES = $(BASE)/$(REP10))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat100.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_110:	
	$(eval RES = $(BASE)/$(REP11))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat110.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_120:
	$(eval RES = $(BASE)/$(REP12))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat120.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_130:	
	$(eval RES = $(BASE)/$(REP13))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat130.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_140:	
	$(eval RES = $(BASE)/$(REP14))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat140.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;
run_150:	
	$(eval RES = $(BASE)/$(REP15))
	@if [ ! -d $(RES) ] ;then echo  "**** Création du dossier : $(RES) ****";mkdir $(RES);	else echo "**** Dossier $(RES) déjà existant - Suppression ****";rm -rf $(RES);	echo "**** Création du dossier : $(RES) ****";mkdir $(RES) ;fi;
	-./robots plat/plat150.dat >> $(RES)/resultat_glpk 
	@if [ -e robots.lp ] ;then echo "**** Copie de robots.lp vers : $(RES) ****" ;cp robots.lp ./$(RES)/robots.lp ;else	echo "**** Le fichier robots.lp n'existe pas ! ****" ;fi;


run_all:
	$(MAKE) run_exemple
	$(MAKE) run_10
	$(MAKE) run_20
	$(MAKE) run_30
	$(MAKE) run_40
	$(MAKE) run_50
	$(MAKE) run_60
	$(MAKE) run_70
	$(MAKE) run_80
	$(MAKE) run_90
	$(MAKE) run_100
	$(MAKE) run_110
	$(MAKE) run_120
	$(MAKE) run_130
	$(MAKE) run_140
	$(MAKE) run_150


# Comipilation du programme de résolution
robots: clean
	gcc -g Projet_GRALL_MINIER.c -o robots -lglpk -lm

# nettoyage de l'exécutable
.PHONY: clean
clean:
	@if [ -e robots ] ; then rm -rf robots; fi;