#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { 
 int idvoiture; 
 char marque[15]; 
 char nomvoiture[15]; 
 char couleur[7]; 
 int nbplaces; 
 int prixJour; 
 char enLocation[4]; 
}car; 

typedef struct{
	int j;
	int m;
	int a;
}date;

typedef struct{
	float numcontrat;
	int idvoiture;
	int idclient;
	date debut;
	date fin;
	int cout;
}contrat;

typedef struct{
	int idclinet;
	char nom[30];
	char prenom[20];
	char cin[9];
	char adresse[20];
	char tele[11];
}cli;
//les fonction
void testfile(FILE *pt);
void Ajoutvoiture(FILE *ptv);
void listvoiture(FILE *ptv);
void modifier(FILE *ptv);
void suppvoiture(FILE *ptv);
int nbrligne(FILE *p);
void ajoutclient(FILE *ptc);
void listclient(FILE *ptc);
void modifierclient(FILE *ptc);
void suppclient(FILE *ptc);
int rechid(int id);
int rechidv(int id);
int prix(int id);
void mofifierapreslouer(int id);
void louer(FILE *ptf);
void listcontact(FILE *pt);
int nbrligneV(FILE *p);
int nbrlignecont(FILE *p);
void modenlocation(int idv);
void suppcont(int id);
void retournvoiture();
void modifiercont();
//========================================================

int main(){
	char nomf[20];
	int choix,choix2,n=2;
	FILE *ptv,*ptc,*contr;

	do{
			printf("\n	--------------------------------- MENU PRINCIPALE ----------------------------\n");
			printf("		- Location ................................................. : 1\n");
			printf("\n");
			printf("		- Gestion Voitures ......................................... : 2\n");
			printf("\n");
			printf("		- Gestion Clients .......................................... : 3\n");
			printf("\n");
			printf("		- Quitter .................................................. : 4\n");
			printf("	- Votre choix : ");
			scanf("%d",&choix);
		 system("cls");
		 fflush(stdin);
				printf("\n");
		
		if(choix==2){
					printf("....................................- Gestion Voitures -....................................\n");
					printf("		- Liste des voitures ...................................... : 1\n");
					printf("		- Ajouter voiture ......................................... : 2\n");
					printf("		- Modifier voiture ........................................ : 3\n");
					printf("		- Supprimer voiture ....................................... : 4\n");
					printf("		- Rorour .................................................. : 5\n");
					printf("	-Votre choix : ");
					scanf("%d",&choix2);
						 system("cls");
				switch(choix2){
					case 1 : listvoiture(ptv);
					break;
					case 2 : Ajoutvoiture(ptv);
					 break;	
					case 3 : modifier(ptv);
					break;
					case 4 : suppvoiture(ptv);
					break;
					case 5 : break;
				}}
		
		if(choix==1){
				printf("....................................- Location -....................................\n");
				printf("		- Visualiser contrat .................................... : 1\n");
				printf("		- Louer voiture ......................................... : 2\n");
				printf("		- Retourner voiture ..................................... : 3\n");
				printf("		- Modifier contract ..................................... : 4\n");
				printf("		- Retour ................................................ : 5\n");
				printf("	-Votre choix : ");
				scanf("%d",&choix2);
		 system("cls");
			switch(choix2){
				case 1 : listcontact(contr);
				break;
				case 2 : louer(contr);
				break;
				case 3 : retournvoiture();
				break;
				case 4 : modifiercont();
				break;
				case 5 : break;
			}}

		if(choix==3){
				printf("....................................- Gestion Clients -....................................\n");
				printf("		- Liste des clients ...................................... : 1\n");
				printf("		- Ajouter client ......................................... : 2\n");
				printf("		- Modifier client ........................................ : 3\n");
				printf("		- Supprimer client ....................................... : 4\n");
				printf("		- Rorour .................................................. : 5\n");
				printf("	-Votre choix : ");
				scanf("%d",&choix2);
		 system("cls");
			switch(choix2){
				case 1 : listclient(ptc);
				break;
				case 2 : ajoutclient(ptc);
				break;
				case 3 : modifierclient(ptc);
				break;
				case 4 : suppclient(ptc);
				break;
				case 5 : break;
				
			}}
			
		if(choix==4){
			exit(1);	}
		
	} while(1);	
return 0;}

void testfile(FILE *pt){
	if(pt==NULL){
		printf("Error ! ");
		exit(1);
	}
}
void Ajoutvoiture(FILE *ptv){
	int nbv;
	car *tab,*pt;
	printf("Veuillez entrer le nombre des voitures que vous veri ajouter : ");
	scanf("%d",&nbv);
	tab=(car*)malloc(nbv*sizeof(car));
	for(pt=tab;pt<tab+nbv;pt++){
		printf("Veuillez entrer le id de voiture %d                : ",pt-tab+1);
		scanf("%d",&pt->idvoiture);
		fflush(stdin);
		printf("Veuillez entrer la marque de voiture %d            : ",pt-tab+1);
		scanf("%s",&pt->marque);
		fflush(stdin);
		printf("Veuillez entrer le nom de voiture %d               : ",pt-tab+1);
		scanf("%s",&pt->nomvoiture);
		fflush(stdin);
		printf("Veuillez entrer la couleur de voiture %d           : ",pt-tab+1);
		scanf("%s",&pt->couleur);
		fflush(stdin);
		printf("Veuillez entrer le nombre de place de voiture %d   : ",pt-tab+1);
		scanf("%d",&pt->nbplaces);
		fflush(stdin);
		printf("Veuillez entrer le prix par jour de voiture %d     : ",pt-tab+1);
		scanf("%d",&pt->prixJour);
		fflush(stdin);
		printf("La voiture %d est enlocation? oui/non              : ",pt-tab+1);
		scanf("%s",&pt->enLocation);
		fflush(stdin);
		printf("\n");
	}
	ptv=fopen("Voiture.txt","a+");
	testfile(ptv);
	for(pt=tab;pt<tab+nbv;pt++){
		fprintf(ptv,"\n       %d         %s          %s          %s          %d           %d          %s",pt->idvoiture,pt->marque,pt->nomvoiture,pt->couleur,pt->nbplaces,pt->prixJour,pt->enLocation);
	}
	free(tab);
	fclose(ptv);
}
void listvoiture(FILE *ptv){
	char c;
	printf("----- List du Voiture : -----\n ");
	printf("Id voiture | Marque | Nom de Voiture | Couleur | Nombre de Places | Prix | En location \n");
	ptv=fopen("Voiture.txt","r");
	testfile(ptv);
	c=fgetc(ptv);
	while(c != EOF){
		printf("%c",c);
		c=fgetc(ptv);
	}
	fclose(ptv);
}
void modifier(FILE *ptv){  
	FILE *pttmp;
	int idmod;
	pttmp=fopen("voituretmp.txt","w");
	testfile(pttmp);
	ptv=fopen("voiture.txt","r");
	testfile(ptv);
	car tab[1];
	listvoiture(ptv);
	printf("\nEnrer le id de voiture a modifier : ");
	scanf("%d",&idmod);
	while(!feof(ptv)){
		fscanf(ptv,"%d %s %s %s %d %d %s",&tab[0].idvoiture,&tab[0].marque,&tab[0].nomvoiture,&tab[0].couleur,&tab[0].nbplaces,&tab[0].prixJour,&tab[0].enLocation);
			if(idmod == tab[0].idvoiture){
					printf("Entrer le nouvelle id : ");
				scanf("%d",&tab[0].idvoiture);
				fflush(stdin);
				printf("Entrer la nouvelle marque : ");
				scanf("%s",&tab[0].marque);
				fflush(stdin);
				printf("Entrer la nouvelle nom de voiture : ");
				scanf("%s",&tab[0].nomvoiture);
				fflush(stdin);
				printf("Entrer la nouvelle couleur : ");
				scanf("%s",&tab[0].couleur);
				fflush(stdin);
				printf("Entrer le nouvelle nombre de place : ");
				scanf("%d",&tab[0].nbplaces);
				fflush(stdin);
				printf("Entrer le nouvelle prix : ");
				scanf("%d",&tab[0].prixJour);
				fflush(stdin);
				printf("Entrer le nouvelle est on location ? : ");
				scanf("%s",&tab[0].enLocation);
				fflush(stdin);
				fprintf(pttmp,"\n%d %s %s %s %d %d %s",tab[0].idvoiture,tab[0].marque,tab[0].nomvoiture,tab[0].couleur,tab[0].nbplaces,tab[0].prixJour,tab[0].enLocation);
			}
		  else fprintf(pttmp,"\n%d %s %s %s %d %d %s",tab[0].idvoiture,tab[0].marque,tab[0].nomvoiture,tab[0].couleur,tab[0].nbplaces,tab[0].prixJour,tab[0].enLocation);
		}
		fclose(ptv);
		remove("voiture.txt");
		fclose(pttmp);
		rename("voituretmp.txt","voiture.txt");
}
void suppvoiture(FILE *ptv){
	FILE *pttmp;
	int idsupp;
	pttmp=fopen("voituretmp.txt","w");
	testfile(pttmp);
	ptv=fopen("voiture.txt","r");
	testfile(ptv);	
	car tab[1];
	listvoiture(ptv);
	printf("         \n     Entrer le id de voiture a supprimer : ");
	scanf("%d",&idsupp);
	while(!feof(ptv)){
		fscanf(ptv,"%d %s %s %s %d %d %s",&tab[0].idvoiture,&tab[0].marque,&tab[0].nomvoiture,&tab[0].couleur,&tab[0].nbplaces,&tab[0].prixJour,&tab[0].enLocation);
			if(idsupp == tab[0].idvoiture){
				printf("Voiture etait supprimer ");
			}
		  else fprintf(pttmp,"\n%d %s %s %s %d %d %s",tab[0].idvoiture,tab[0].marque,tab[0].nomvoiture,tab[0].couleur,tab[0].nbplaces,tab[0].prixJour,tab[0].enLocation);
		}
		fclose(ptv);
		remove("voiture.txt");
		fclose(pttmp);
		rename("voituretmp.txt","voiture.txt");
	
}

int nbrligne(FILE *p){
	char c;
	int lign=0;
	p=fopen("client.txt","r");
	testfile(p);
	c= getc(p);
	while(c!=EOF){
		if(c=='\n'){
			  lign++;
		}
		c=getc(p);
	}
	fclose(p);
	return lign;
}
int nbrligneV(FILE *p){
	char c;
	int lign=0;
	p=fopen("voiture.txt","r");
	testfile(p);
	c= getc(p);
	while(c!=EOF){
		if(c=='\n'){
			  lign++;
		}
		c=getc(p);
	}
	fclose(p);
	return lign;
}
int nbrlignecont(FILE *p){
	char c;
	int lign=0;
	p=fopen("contact.txt","r");
	testfile(p);
	c= getc(p);
	while(c!=EOF){
		if(c=='\n'){
			  lign++;
		}
		c=getc(p);
	}
	fclose(p);
	return lign;
}
void ajoutclient(FILE *ptc){
	int nbc;
	printf("Veuillez enter le nombre de Client que vous pouvez ajouter : ");
	scanf("%d",&nbc);
	cli *tab,*ptab;
	tab = (cli*)malloc(nbc*sizeof(cli));
		for(ptab=tab;ptab<tab+nbc;ptab++){
			printf("Veuillez enter le ID du client %d            : ",ptab-tab+1);
			scanf("%d",&ptab->idclinet);
			fflush(stdin);
			printf("Veuillez enter le Nom du client %d           : ",ptab-tab+1);
			scanf("%s",&ptab->nom);
			fflush(stdin);
			printf("Veuillez enter le Prenom du client %d        : ",ptab-tab+1);
			scanf("%s",&ptab->prenom);
			fflush(stdin);
			printf("Veuillez enter le CIN du client %d           : ",ptab-tab+1);
			scanf("%s",&ptab->cin);
			fflush(stdin);
			printf("Veuillez enter l'Adresse du client %d        : ",ptab-tab+1);
			scanf("%s",&ptab->adresse);
			fflush(stdin);
			printf("Veuillez enter le Num de Tel du client %d    : ",ptab-tab+1);
			scanf("%s",&ptab->tele);
			fflush(stdin);
			printf("\n");
		}
		ptc=fopen("client.txt","a");
		testfile(ptc);
		for(ptab=tab;ptab<tab+nbc;ptab++){
		fprintf(ptc,"\n%d		%s		%s		%s		%s		%s",ptab->idclinet,ptab->nom,ptab->prenom,ptab->cin,ptab->adresse,ptab->tele);
		}
		free(tab);
		fclose(ptc);
}
void listclient(FILE *ptc){
	ptc=fopen("Client.txt","r");
	testfile(ptc);
	char c=fgetc(ptc);
	printf("-------------------- List du Clients : --------------------\n");
	printf("   Id du client   |   Nom du client   |   Prenom du client   |   CIN client   |   Num Client \n"); 
	while(c!= EOF ){
		printf("%c",c);
		c=getc(ptc);
	}
	fclose(ptc);
}

void modifierclient(FILE *ptc){
	int idmod,nbl;
	listclient(ptc);
	printf("\n Veuillez entrer le id du client a modifier : ");
	scanf("%d",&idmod);
	nbl=nbrligne(ptc);
	cli *tab,*pt;
	tab = (cli*)malloc(nbl*sizeof(cli));
	ptc=fopen("client.txt","r");
	testfile(ptc);
	for(pt=tab;pt<tab+nbl;pt++){
		fscanf(ptc,"%d %s %s %s %s %s",&pt->idclinet,&pt->nom,&pt->prenom,&pt->cin,&pt->adresse,&pt->tele);
	}
	fclose(ptc);
	ptc=fopen("client.txt","w");
	testfile(ptc);
		for(pt=tab;pt<tab+nbl;pt++){
			if(idmod==pt->idclinet){
				printf("Veuillez entrer la nouvelle id       : ");
				scanf("%d",&pt->idclinet);
				fflush(stdin);
				printf("Veuillez entrer la nouvelle nom      : ");
				scanf("%s",&pt->nom);
				fflush(stdin);
				printf("Veuillez entrer la nouvelle prenom   : ");
				scanf("%s",&pt->prenom);
				fflush(stdin);
				printf("Veuillez entrer la nouvelle CIN      : ");
				scanf("%d",&pt->cin);
				fflush(stdin);
				printf("Veuillez entrer la nouvelle Adresse  : ");
				scanf("%s",&pt->adresse);
				fflush(stdin);
				printf("Veuillez entrer la nouvelle tele     : ");
				scanf("%s",&pt->tele);
				fflush(stdin);
			}
		fprintf(ptc,"\n%d %s %s %s %s %s",pt->idclinet,pt->nom,pt->prenom,pt->cin,pt->adresse,pt->tele);
	}
	fclose(ptc);
	free(tab);
	printf("le client a ete modifier ");
}
void suppclient(FILE *ptc){
	int idsup,nbl;
	listclient(ptc);
	printf("\n Veuillez entrer le id du client a supprimer : ");
	scanf("%d",&idsup);
	nbl=nbrligne(ptc);
	cli *tab,*pt;
	tab = (cli*)malloc(nbl*sizeof(cli));
	ptc=fopen("client.txt","r");
	testfile(ptc);
	for(pt=tab;pt<tab+nbl;pt++){
		fscanf(ptc,"%d %s %s %s %s %s",&pt->idclinet,&pt->nom,&pt->prenom,&pt->cin,&pt->adresse,&pt->tele);
	}
	fclose(ptc);
		ptc=fopen("client.txt","w");
		testfile(ptc);
		for(pt=tab;pt<tab+nbl;pt++){
			if(idsup==pt->idclinet){
			}
	 else	fprintf(ptc,"\n%d %s %s %s %s %s",pt->idclinet,pt->nom,pt->prenom,pt->cin,pt->adresse,pt->tele);
	}
	fclose(ptc);
	free(tab);
	printf("le client a ete supprimer ");
}
int rechid(int id){
	FILE *pt;
	pt=fopen("client.txt","r");
	testfile(pt);
	cli v;
	while(!feof(pt)){
		fscanf(pt,"%d %s %s %s %s %s",&v.idclinet,&v.nom,&v.prenom,&v.cin,&v.adresse,&v.tele);
		if(v.idclinet==id){
			return 1;
			break;
		}
	}
	return 0;
	fclose(pt);
}
int rechidv(int id){
	FILE *pt;
	pt=fopen("voiture.txt","r");
	testfile(pt);
	car v;
	int i;
	char ch[4]="non";
	while(!feof(pt)){
			fscanf(pt," %d %s %s %s %d %d %s",&v.idvoiture,&v.marque,&v.nomvoiture,&v.couleur,&v.nbplaces,&v.prixJour,&v.enLocation);
					if(id==v.idvoiture){
					i=strcmp(v.enLocation,ch);
					if(i==0){
					return 1;
					break;
		}
		}
	}
	return 0;
	fclose(pt);
}
 
int prix(int id){
	FILE *p;
	p=fopen("voiture.txt","r");
	testfile(p);
	car v;
	while(!feof(p)){
		fscanf(p," %d %s %s %s %d %d %s",&v.idvoiture,&v.marque,&v.nomvoiture,&v.couleur,&v.nbplaces,&v.prixJour,&v.enLocation);
		if(id==v.idvoiture){
			return v.prixJour;
		}
	}
	fclose(p);
}
void mofifierapreslouer(int id){
	FILE *p;
	car *tab,*pt;
	p=fopen("voiture.txt","r");
	testfile(p);
		int nbl=nbrligneV(p);
	tab=(car*)malloc(nbl*sizeof(car));
		for(pt=tab;pt<tab+nbl;pt++){
		fscanf(p,"%d %s %s %s %d %d %s",&pt->idvoiture,&pt->marque,&pt->nomvoiture,&pt->couleur,&pt->nbplaces,&pt->prixJour,&pt->enLocation);
	}
	fclose(p);
	p=fopen("voiture.txt","w");
	testfile(p);
		for(pt=tab;pt<tab+nbl;pt++){
			if(id==pt->idvoiture){
				strcpy(pt->enLocation,"oui");
				fprintf(p,"\n%d %s %s %s %d %d %s",pt->idvoiture,pt->marque,pt->nomvoiture,pt->couleur,pt->nbplaces,pt->prixJour,pt->enLocation);
			}
		else fprintf(p,"\n%d %s %s %s %d %d %s",pt->idvoiture,pt->marque,pt->nomvoiture,pt->couleur,pt->nbplaces,pt->prixJour,pt->enLocation);
	}
	fclose(p);
	free(tab);
}
void louer(FILE *ptf){
	int louer,w,f,h,j,nbj,cou;
	float num;
	printf("Veuillez enter le nombre des Voiture que vous souhite a louer : ");
	scanf("%d",&louer);
	contrat *tab,*pt;
	ptf=fopen("contact.txt","a");
	testfile(ptf);
	tab = (contrat*)malloc(louer*sizeof(contrat));
		for(pt=tab;pt<tab+louer;pt++){
				num=pt-tab+1;
			printf("contcart num : %.2f \n",num);
			pt->numcontrat=num;
			printf("Veuillez enter le ID du client %d   : ",pt-tab+1);
			scanf("%d",&pt->idclient);
			w=(pt->idclient);
					f=rechid(w);
					if(f==1){
						printf("Veuillez enter le ID du voiture %d   : ",pt-tab+1);
						scanf("%d",&pt->idvoiture);
						h=pt->idvoiture;
						j=rechidv(h);
					if(j==1){
							printf("Veuillez enter la date de debut   : ");
							scanf("%d %d %d",&pt->debut.j,&pt->debut.m,&pt->debut.a);
							printf("Veuillez enter la date de fin   : ");
							scanf("%d%d%d",&pt->fin.j,&pt->fin.m,&pt->fin.a);
							j=prix(h);
							nbj=((pt->fin.a)*365+(pt->fin.m)*30+(pt->fin.j))-((pt->debut.a)*365+(pt->debut.m)*30+(pt->debut.j));
							cou = j*nbj;
							printf("Le cout de location est  : %d DH \n",cou);
							(pt->cout)=cou;
							fprintf(ptf,"\n %.2f   %d   %d   %d %d %d      %d %d %d       %d",pt->numcontrat,pt->idclient,pt->idvoiture,pt->debut.j,pt->debut.m,pt->debut.a,pt->fin.j,pt->fin.m,pt->fin.a,pt->cout);
							mofifierapreslouer(h);
							}
				}
				 if(f==0){
				printf("Le client n'est pas enregistrer, il faut d'abord l'ajouter .");
							}
				else if(j==0){
				printf("La voiture deja louer ou n'exist pas .");
						}
				}
				fclose(ptf);	
		free(tab); 
		}	
void listcontact(FILE *pt){
	char c;
	printf("----- List du Contract : -----\n ");
	printf("Num contract | Id client | Id Voiture | Date debut | Date fin | Cout \n");
	pt=fopen("contact.txt","r");
	testfile(pt);
	c=fgetc(pt);
	while(c != EOF){
		printf("%c",c);
		c=fgetc(pt);
	}
	fclose(pt);
}
void suppcont(int id){
	FILE *p;
	int nbl=nbrlignecont(p);
	contrat *tab,*pt;
	tab=(contrat*)malloc(nbl*sizeof(contrat));
		p=fopen("contact.txt","r");
		testfile(p);
			for(pt=tab;pt<tab+nbl;pt++){
	fscanf(p,"%f %d %d %d %d %d %d %d %d %d",&pt->numcontrat,&pt->idclient,&pt->idvoiture,&pt->debut.j,&pt->debut.m,&pt->debut.a,&pt->fin.j,&pt->fin.m,&pt->fin.a,&pt->cout);
			}
			fclose(p);
		p=fopen("contact.txt","w");
		testfile(p);
		for(pt=tab;pt<tab+nbl;pt++){
			if(id==pt->idvoiture){
				
			}
		else fprintf(p,"\n%f %d %d %d %d %d %d %d %d %d",pt->numcontrat,pt->idclient,pt->idvoiture,pt->debut.j,pt->debut.m,pt->debut.a,pt->fin.j,pt->fin.m,pt->fin.a,&pt->cout);
			}
			printf("\nVoiture retourner est contract a ete supprimer . \n");
			fclose(p);
		free(tab);
}

void retournvoiture(){
	int id;
	printf("Veuillez entrer le id de voiture a retourner : ");
	scanf("%d",&id);
	FILE *pv;
	car *tab,*pt;
	pv=fopen("voiture.txt","r");
	testfile(pv);
		int nbl=nbrligneV(pv);
	tab=(car*)malloc(nbl*sizeof(car));
		for(pt=tab;pt<tab+nbl;pt++){
		fscanf(pv,"%d %s %s %s %d %d %s",&pt->idvoiture,&pt->marque,&pt->nomvoiture,&pt->couleur,&pt->nbplaces,&pt->prixJour,&pt->enLocation);
	}
	fclose(pv);
	pv=fopen("voiture.txt","w");
	testfile(pv);
		for(pt=tab;pt<tab+nbl;pt++){
			if(id==pt->idvoiture){
				strcpy(pt->enLocation,"non");
				fprintf(pv,"\n%d %s %s %s %d %d %s",pt->idvoiture,pt->marque,pt->nomvoiture,pt->couleur,pt->nbplaces,pt->prixJour,pt->enLocation);
			}
		else fprintf(pv,"\n%d %s %s %s %d %d %s",pt->idvoiture,pt->marque,pt->nomvoiture,pt->couleur,pt->nbplaces,pt->prixJour,pt->enLocation);
	}
	fclose(pv);
	suppcont(id);
	free(tab);
}
void modifiercont(){
	int choixc,id,j,nbj,cou;
	FILE *pc;
	contrat *tab,*pt;
	int nblc=nbrlignecont(pc);
	tab=(contrat*)malloc((nblc)*sizeof(contrat));
	printf("			- 1 - Voulez vous changer la date de retoure               .\n ");
	printf("			- 2 - Voulez vous changer la voiture                       . \n");
	printf("votre choix : ");
	scanf("%d",&choixc);
		if(choixc==1){
			printf("enter le id de voiture que vous avez louer : ");
			scanf("%d",&id);
				pc=fopen("contact.txt","r");
				testfile(pc);
				for(pt=tab;pt<tab+nblc;pt++){
			fscanf(pc,"%f %d %d %d %d %d %d %d %d %d",&pt->numcontrat,&pt->idclient,&pt->idvoiture,&pt->debut.j,&pt->debut.m,&pt->debut.a,&pt->fin.j,&pt->fin.m,&pt->fin.a,&pt->cout);
				}
				fclose(pc);
				pc=fopen("contact.txt","w");
				testfile(pc);
			for(pt=tab;pt<tab+nblc;pt++){
				if((pt->idvoiture)==id){
					printf("Veuillez enter la nouvelle date de retour : ");
					scanf("%d%d%d",&pt->fin.j,&pt->fin.m,&pt->fin.a);
					j=prix(id);
					nbj=((pt->fin.a)*365+(pt->fin.m)*30+(pt->fin.j))-((pt->debut.a)*365+(pt->debut.m)*30+(pt->debut.j));
					cou = j*nbj;
					printf("il faut ajouter %d DH .",cou - (pt->cout));
					(pt->cout) = cou;
					fprintf(pc,"\n %.2f %d %d %d %d %d %d %d %d %d ",pt->numcontrat,pt->idclient,pt->idvoiture,pt->debut.j,pt->debut.m,pt->debut.a,pt->fin.j,pt->fin.m,pt->fin.a,pt->cout);
					}
					else {
					fprintf(pc,"\n %.2f %d %d %d %d %d %d %d %d %d ",pt->numcontrat,pt->idclient,pt->idvoiture,pt->debut.j,pt->debut.m,pt->debut.a,pt->fin.j,pt->fin.m,pt->fin.a,pt->cout);
						}
						}
					fclose(pc);
		}
		free(tab);
		if(choixc==2){
			retournvoiture();
			louer(pc);
		}
}
