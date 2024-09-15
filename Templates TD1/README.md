# Résumé

Ce document pédagogique présente les tableaux dynamiques en C et deux méthodes pour les rendre génériques : 
1. Généricité par pointeurs
2. Généricité par génération de code. 

Le document commence par un rappel des tableaux statiques en C et les problèmes liés à l'allocation statique. Ensuite, il introduit les tableaux dynamiques, en expliquant leur fonctionnement et leur utilité pour gérer des données de taille variable. Le document détaille ensuite les deux méthodes de généricité pour les tableaux, en expliquant leurs avantages et leurs inconvénients respectifs. Finalement, il propose deux exercices : un exercice "facile" pour mettre en pratique la création d'un tableau dynamique de réels sans généricité, et un exercice "moins facile" pour mettre en pratique la généricité par pointeurs ou par génération de code.

## 1. Tableaux dynamiques:

Contrairement aux tableaux statiques déclarés avec une taille fixe, les tableaux dynamiques permettent d'allouer de la mémoire pendant l'exécution du programme.
Ils sont essentiels pour gérer des volumes de données importants ou inconnus à la compilation, car ils utilisent le "TAS" du programme, qui offre une plus grande capacité de mémoire.
Le document souligne l'importance d'utiliser l'allocation dynamique pour les tableaux de grande taille pour éviter les erreurs de type "Killed" dues à un dépassement de la pile.
Citation: "TOUTES les données (tableaux, structures ...) de grandes tailles DOIVENT être allouées dynamiquement" (page 3).
La gestion manuelle de la mémoire est cruciale avec les tableaux dynamiques, impliquant l'utilisation de malloc pour l'allocation et free pour la libération.

## 2. Généricité:

La généricité permet de concevoir du code réutilisable pour différents types de données, évitant ainsi la duplication de code.
Deux approches sont présentées pour implémenter la généricité en C :
Généricité par pointeurs:Remplace le type spécifique par void*, nécessitant des conversions explicites lors de l'utilisation.
Avantage: Facile à mettre en œuvre, code lisible.
Inconvénients: Perte de la vérification de type statique, risque d'erreurs à l'exécution, performance potentiellement réduite due aux indirections.
Généricité par génération de code:Utilise le préprocesseur C (#define, #include) pour générer du code spécialisé pour chaque type utilisé.
Avantage: Vérification de type statique préservée, performance optimisée.
Inconvénients: Code de template moins lisible et plus difficile à déboguer.
Citation: "Certains langages incluent cette généricité grâce aux templates. En C, 2 solutions sont possibles : Généricité par pointeurs [...] Généricité par génération de code" (page 4).

## 3. Exercices:

Le document propose deux exercices pour mettre en pratique les concepts :

1. Facile: Créer un type abstrait table_double pour gérer les tableaux dynamiques de nombres réels.

2. Moins facile: Implémenter un type abstrait générique table_t pour gérer des tableaux dynamiques de n'importe quel type de données en utilisant une des deux méthodes de généricité.


## Conclusion :
Ce document fournit une introduction concise aux tableaux dynamiques et à la généricité en C. Il met en évidence les avantages et les inconvénients des deux approches de généricité et offre des exemples concrets pour aider à la compréhension. L'accent mis sur la gestion manuelle de la mémoire et les risques potentiels liés aux pointeurs non typés souligne l'importance d'une programmation prudente et attentive lorsqu'on travaille avec ces concepts en C.