*This project has been created as part of the 42 curriculum by margagab.*

<h1 align="center">get_next_line</h1>

## Description

`get_next_line` est un projet que j'ai réalisé dans le cadre du cursus de 42.

Le but de ce projet est de créer une fonction permettant de lire depuis un file descriptor et de retourner une ligne à chaque appel, jusqu'à atteindre la fin du fichier.

La taille du buffer utilisé pour lire les données est définie par la macro `BUFFER_SIZE`, qui peut varier lors de la compilation.

## Instructions

Pour compiler le projet, il suffit de compiler les fichiers sources avec un main.

`BUFFER_SIZE` définit la quantité de caractères lus par `read`.

Par exemple :

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

## Fonctions

### get_next_line

`get_next_line` est la fonction principale du projet. Elle récupère les données conservées lors de l'appel précédent, lit de nouvelles données si nécessaire, puis retourne la prochaine ligne.

Elle utilise une variable `static char *stash` pour conserver les caractères qui n'ont pas encore été retournés. Cette variable permet de retrouver ces caractères lors du prochain appel, même si les variables locales de la fonction ont disparu.

### read_more

`read_more` lit les données du file descriptor par blocs de `BUFFER_SIZE` caractères à l'aide de `read`.

Les données sont ajoutées progressivement à la chaîne `res` grâce à `ft_strjoin`. La lecture continue jusqu'à ce qu'un retour à la ligne soit trouvé dans le bloc lu ou que la fin du fichier soit atteinte.

En cas d'erreur de lecture ou d'allocation, la fonction libère les ressources concernées et retourne `NULL`.

### split_line

`split_line` recherche le premier retour à la ligne dans la chaîne reçue.

Si un `\n` est trouvé, la fonction extrait la ligne complète, en incluant le retour à la ligne, puis conserve les caractères suivants dans `stash` pour le prochain appel.

Si aucun retour à la ligne n'est trouvé, la fonction retourne tous les caractères disponibles et libère l'ancien contenu de `stash`.

### get_stash

`get_stash` récupère les caractères conservés lors de l'appel précédent.

Si aucun caractère n'est conservé, elle crée une chaîne vide. Sinon, elle copie le contenu de `stash` dans une nouvelle chaîne, puis libère l'ancienne allocation et réinitialise le pointeur.

Cette fonction permet de repartir des données déjà lues avant de continuer la lecture du fichier.

### Fonctions utilitaires

`ft_strlen` calcule la longueur d'une chaîne de caractères.

`ft_substr` crée une nouvelle chaîne à partir d'une portion d'une chaîne existante. Elle est utilisée pour extraire la ligne à retourner et les caractères à conserver.

`ft_strchr` recherche un caractère dans une chaîne. Elle permet notamment de détecter la présence d'un retour à la ligne.

`ft_strjoin` concatène deux chaînes de caractères dans une nouvelle allocation. Elle permet d'ajouter les nouveaux blocs lus aux données déjà récupérées.

## Ressources

J'ai principalement utilisé le **man** et le **web** pour comprendre le fonctionnement du projet.

J'ai également consulté des dépôts **GitHub** et demandé de l'aide à d'autres **étudiants** ainsi qu'à des **proches** lorsque j'avais besoin de plus d'explications.

Pour tester mes fonctions, j'ai utilisé des **testeurs disponibles sur Internet** et l'**IA**.

J'ai principalement utilisé l'IA pour ce README et pour m'aider lors des corrections. Son utilisation est restée modérée, avec pour objectif de comprendre les problèmes rencontrés et de progresser.