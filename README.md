# Search Word In Folder :

## Description :
Application C++ sans interface graphique permettant de lister tous les fichier .txt contenant un mot désiré (SANS UTILISER DE CONTENEURS STL !)
(avec les conteneurs stl ça se fait vraiment beaucoup plus rapidemenet et simplement haha)

## Contexte :
Application réalisé dans le cadre d'un text technique pour un processus de recutement. 

## Consigne exacte : 

Sujet de test en C++
« Indexation de document texte »

Objectif : 
Ecrire un programme qui prend un chemin de répertoire sur la ligne de commande.
Ce programme doit alors parcourir ce répertoire ainsi que tous ses sous-répertoires pour rechercher tous les fichiers texte (extension .txt).
Pour chaque fichier texte rencontré, réaliser une indexation en mémoire des mots contenu dans ce fichier.
Une fois cette indexation terminée, le programme doit demander la saisie d’un mot et retourner la liste des fichiers contenant ce mot.
Le programme sera en C++ (compilateur au choix). Ne pas utiliser de librairie tierce (conteneurs de la STL, BOOST, etc.).
Le but étant de concevoir soi-même les structures de données.
Concevoir la structure pour une efficacité maximum, pour être évolutif et facilement maintenable.
Les sources doivent être commentés de manière efficace.
La durée totale de développement est de 1 journée. A réaliser seul, bien-sûr.



***********************************************

## compilator used
gcc

## to compile : 
make

## to execute : 
./app FOLDER_PATH

## examples: 
./app /home/alex/Desktop/PC_SOFT/folder
./app /home/alex/Desktop/PC_SOFT/folder2
./app 


### Cas limite non traité : 
L'application ne gère pas le cas où il y a une apostrophe "au milieu" d'un mot.
Par exemple, le champ "l'auteure" est considéré comme un seul mot alors qu'il y a le mot "l" et le mot "auteure". 

Il y a un Harrypotter.txt dans folder, qui contient "l'auteure", si l'utilisateur cherche "auteure" l'application ne trouvera pas le mot.
