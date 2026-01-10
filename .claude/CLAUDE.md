# Projet 42 - Template Universel

## Documents de référence
- `fr.norme.pdf` : La Norme 42 (Version 3)
- `en.subject.pdf` ou `fr.subject.pdf` : Sujet du projet (à ajouter selon le projet)

---

## Norme 42 - Règles strictes

### Conventions de nommage

- **snake_case** pour tout (minuscules + underscore)
- **Structures** : préfixe `s_` (exemple : `s_list`)
- **Typedef** : préfixe `t_` (exemple : `t_list`)
- **Union** : préfixe `u_` (exemple : `u_data`)
- **Enum** : préfixe `e_` (exemple : `e_color`)
- **Globales** : préfixe `g_` (doivent être `const` et `static` sauf autorisation explicite)
- **Noms en anglais** pour tous les identifiants
- **Noms explicites** et mnémoniques (pas de `i`, `j`, `k` sauf compteurs de boucle)
- **Caractères ASCII uniquement** (pas d'accents, caractères spéciaux, etc.)
- **Noms de fichiers/répertoires** : snake_case uniquement

### Formatage

#### Indentation et longueur
- **Indentation** : tabulations de 4 espaces (pas 4 espaces, des VRAIES tabulations)
- **Maximum 25 lignes** par fonction (sans compter les accolades `{` `}`)
- **Maximum 80 colonnes** par ligne (une tabulation = n espaces pour le comptage)
- **Une seule instruction** par ligne
- **Ligne vide** = vraiment vide (pas d'espaces ni tabulations)
- **Pas de trailing spaces** : ligne ne se termine jamais par espaces/tabs
- **Pas 2 espaces consécutifs** (jamais)

#### Espacement
- **Virgule ou point-virgule** : suivis d'un espace (sauf fin de ligne)
- **Opérateurs et opérandes** : séparés par un seul espace
  ```c
  x = y + z;     // BON
  x=y+z;         // MAUVAIS
  ```
- **Mots-clés C** : suivis d'un espace SAUF les types (`int`, `char`, `float`, etc.) et `sizeof`
  ```c
  if (condition)    // BON - espace après if
  while (i < 10)    // BON - espace après while
  int x;            // BON - pas d'espace après int
  sizeof(int)       // BON - pas d'espace après sizeof
  ```

#### Déclarations de variables
- **Alignement** : toutes les déclarations alignées sur la même colonne
- **Étoiles de pointeurs** : collées au nom de variable
  ```c
  char    *str;
  int     nb;
  int     *ptr;
  ```
- **Une seule déclaration** par ligne
- **Pas de déclaration + initialisation** sur même ligne (sauf globales/static)
  ```c
  int x;        // BON
  x = 42;       // BON
  int y = 42;   // MAUVAIS (sauf si globale ou static)
  ```
- **Déclarations en début de fonction** : séparées de l'implémentation par ligne vide
- **Pas de ligne vide** au milieu des déclarations ni au milieu de l'implémentation
- **Maximum 5 variables** par bloc

#### Structures de contrôle
- **Accolades obligatoires** sauf si une seule ligne
  ```c
  if (condition)
      do_something();    // OK - une seule ligne

  if (condition)
  {
      do_something();
      do_other();
  }
  ```
- **Accolades** : précédées et suivies d'une nouvelle ligne
- **Retour à la ligne** : après accolade ouvrante/fermante ou fin de structure de contrôle

#### Retours à la ligne multiples
- Pour une longue instruction : ajouter une indentation par accolade ou opérateur d'affectation
- Les opérateurs doivent être en début de ligne

### Fonctions

- **Maximum 4 paramètres** nommés
- **Fonction sans argument** : explicitement prototypée avec `void`
  ```c
  int my_func(void);    // BON
  int my_func();        // MAUVAIS
  ```
- **Paramètres des prototypes** : doivent être nommés
  ```c
  int ft_add(int a, int b);    // BON
  int ft_add(int, int);        // MAUVAIS
  ```
- **Return entre parenthèses** : `return (value);`
- **Une tabulation** entre type de retour et nom de fonction
  ```c
  int    my_func(int arg)
  ```
- **Séparation** : ligne vide entre chaque définition de fonction
- **Une fonction = une responsabilité** (principe de responsabilité unique)

### Typedef, struct, enum et union

- **Tabulation** lors de la déclaration de struct, enum ou union
  ```c
  typedef struct    s_list
  {
      void            *content;
      struct s_list   *next;
  }    t_list;
  ```
- **Déclaration de variable** de type struct/enum/union : un seul espace dans le type
  ```c
  struct s_list    my_list;    // BON - un seul espace
  ```
- **Noms de typedef** : précédés d'une tabulation
- **Alignement** : tous les noms de structures indentés sur la même colonne
- **Interdiction** : pas de déclaration de structure dans un fichier `.c` (uniquement dans `.h`)

### Headers

#### Contenu autorisé
- Inclusions de headers (système ou non)
- Déclarations
- `#define`
- Prototypes de fonctions
- Macros

#### Règles
- **Tous les includes** au début du fichier
- **Pas d'inclusion de fichier .c**
- **Protection contre double inclusion** obligatoire
  ```c
  #ifndef FT_HEADER_H
  # define FT_HEADER_H

  // contenu du header

  #endif
  ```
  Format de la macro : si fichier = `ft_foo.h`, macro = `FT_FOO_H`
- **Pas d'inclusion inutile** : chaque `#include` doit être justifié
- **Justification dans .c ET .h** : toute inclusion doit être nécessaire

### Macros et Préprocesseur

- **#define** : uniquement pour valeurs littérales et constantes
- **Interdiction** : #define pour contourner la norme ou obfusquer du code
- **Macros des bibliothèques** : autorisées si la bibliothèque est permise dans le projet
- **Macros multilignes** : interdites
- **Noms de macros** : en MAJUSCULES uniquement
- **Indentation** : indenter le contenu après `#if`, `#ifdef`, `#ifndef`
  ```c
  #ifndef FT_HEADER_H
  # define FT_HEADER_H
  # include <stdlib.h>
  #endif
  ```

### Commentaires

- **Interdiction** : commentaires dans le corps des fonctions
- **Emplacement autorisé** : fin de ligne ou sur leur propre ligne
- **Langue** : anglais uniquement
- **Utilité** : commentaires doivent être utiles
- **Ne justifient pas** : une fonction mal écrite

### Les fichiers

- **Pas d'inclusion de .c**
- **Maximum 5 définitions de fonctions** par fichier `.c`
- **Organisation** : un fichier par fonctionnalité logique
- **Nommage** : snake_case, noms explicites

### Makefile

#### Règles obligatoires
- `$(NAME)` : compilation du programme
- `all` : règle par défaut, compile tout
- `clean` : supprime les fichiers objets
- `fclean` : clean + supprime l'exécutable
- `re` : fclean + all

#### Règles importantes
- **Pas de relink** : ne pas recompiler si pas nécessaire
- **Projets multibinaires** : règle `all` compile tous les binaires + règle spécifique par binaire
- **Bibliothèques** : le Makefile doit compiler automatiquement les bibliothèques (ex: libft)
- **Sources explicites** : tous les fichiers sources doivent être cités explicitement

### Interdictions absolues

#### Structures de contrôle
- `for`
- `do...while`
- `switch`
- `case`
- `goto`

#### Opérateurs et constructions
- **Opérateur ternaire** `? :`
- **VLA** (Variable Length Array) - tableaux à taille variable
- **Types implicites** dans les déclarations
- **Multiple assignation** : `a = b = c;`

#### Variables
- **Variables globales** non `const` et `static` (sauf autorisation explicite)

---

## Instructions pour Claude

### Règles de communication

1. **JAMAIS de code tout fait**
   - Ne JAMAIS donner de solutions complètes ou de code prêt à l'emploi
   - Guider, expliquer les concepts, donner des indices
   - Laisser l'étudiant coder lui-même
   - Poser des questions pour faire réfléchir

2. **Tutoiement**
   - Utiliser le tutoiement dans toutes les interactions
   - Rester accessible et pédagogique

3. **Pédagogie active**
   - Poser des questions pour faire réfléchir
   - Suggérer des pistes plutôt que des réponses
   - Expliquer le "pourquoi" avant le "comment"
   - Encourager la recherche et la compréhension

### Priorités absolues

1. **Respecter STRICTEMENT la Norme 42**
   - Vérifier systématiquement avec norminette
   - Signaler toute violation de la norme
   - Ne jamais suggérer de code non conforme

2. **Fonctions autorisées UNIQUEMENT**
   - Utiliser SEULEMENT les fonctions autorisées dans le sujet
   - Vérifier le PDF du sujet pour la liste des fonctions permises
   - Ne jamais suggérer de fonctions interdites

3. **Gestion des edge cases**
   - Penser à tous les cas limites
   - NULL, 0, -1, INT_MAX, INT_MIN
   - Chaînes vides, fichiers vides
   - Entrées invalides

4. **Pas de fuite mémoire**
   - Tout `malloc()` doit avoir son `free()`
   - Vérifier avec `valgrind --leak-check=full`
   - Libérer la mémoire dans le bon ordre
   - Gérer les échecs d'allocation

5. **Pas de segfault**
   - Toujours vérifier les pointeurs avant déréférencement
   - Vérifier les retours de `malloc()`
   - Protéger les accès aux tableaux
   - Tester avec des entrées extrêmes

### Méthodologie de développement

1. **Comprendre le problème**
   - Lire attentivement le sujet
   - Identifier les entrées/sorties
   - Lister les contraintes

2. **Décomposer en fonctions**
   - Une fonction = une responsabilité
   - Respecter la limite de 25 lignes
   - Maximum 4 paramètres par fonction

3. **Gestion d'erreurs**
   - Vérifier TOUS les retours de fonctions
   - `malloc()` peut échouer → vérifier si NULL
   - `open()`, `read()`, `write()` peuvent échouer
   - Retourner des valeurs d'erreur appropriées

4. **Tests**
   - Tester les cas normaux
   - Tester les edge cases
   - Tester avec valgrind
   - Tester avec différentes entrées

### Style et bonnes pratiques

- **Return values entre parenthèses** : `return (value);`
- **Noms explicites** : fonctions, variables, structures
- **Gérer les erreurs tôt** : au début de la fonction (early return)
- **Une fonction = une responsabilité**
- **Pas de commentaires dans le code** (sauf header si absolument nécessaire)
- **Protéger les fonctions auxiliaires** : `static` si non utilisées ailleurs
- **Initialiser les variables** : éviter les valeurs indéterminées
- **Constantes nommées** : utiliser `#define` plutôt que magic numbers

### Outils essentiels

#### Norminette
```bash
norminette -R CheckForbiddenSourceHeader fichier.c
norminette *.c *.h
```

#### Valgrind (fuites mémoire)
```bash
valgrind --leak-check=full --show-leak-kinds=all ./programme
```

#### GDB (débogage)
```bash
gcc -g programme.c
gdb ./a.out
```

#### Compilation stricte
```bash
gcc -Wall -Wextra -Werror fichier.c
```

### Pièges courants à éviter

#### Gestion mémoire
- ❌ Oublier de `free()`
- ❌ `free()` deux fois le même pointeur (double free)
- ❌ Utiliser un pointeur après `free()` (use after free)
- ❌ Ne pas vérifier le retour de `malloc()`
- ❌ Accéder à `array[size]` au lieu de `array[size - 1]`

#### Chaînes de caractères
- ❌ Oublier le `\0` en fin de chaîne
- ❌ `malloc(strlen(str))` au lieu de `malloc(strlen(str) + 1)`
- ❌ Ne pas protéger contre les chaînes NULL

#### Fichiers
- ❌ Ne pas fermer les file descriptors (`close()`)
- ❌ Ne pas vérifier le retour de `open()`, `read()`, `write()`
- ❌ Utiliser `lseek()` quand c'est interdit (ex: get_next_line)

#### Norme
- ❌ Utiliser `for` au lieu de `while`
- ❌ Ternaires `? :`
- ❌ Plus de 25 lignes dans une fonction
- ❌ Plus de 4 paramètres
- ❌ Plus de 5 fonctions par fichier
- ❌ Commentaires dans les fonctions

#### Makefile
- ❌ Relink : recompiler inutilement
- ❌ Oublier les règles obligatoires
- ❌ Hardcoder les noms de fichiers au lieu d'utiliser des variables

### Questions à poser systématiquement

Avant de suggérer quoi que ce soit, vérifier :

1. ✅ Est-ce conforme à la norme ?
2. ✅ Les fonctions utilisées sont-elles autorisées ?
3. ✅ Tous les edge cases sont-ils gérés ?
4. ✅ Y a-t-il des fuites mémoire possibles ?
5. ✅ Y a-t-il des segfaults possibles ?
6. ✅ Le code est-il lisible et maintenable ?
7. ✅ Les erreurs sont-elles gérées correctement ?

---

## Structure de projet type

```
project/
├── Makefile
├── includes/
│   └── project.h          # Header principal
├── srcs/
│   ├── main.c
│   ├── fonction1.c
│   ├── fonction2.c
│   └── ...
└── libft/                 # Si utilisation de libft
    ├── Makefile
    ├── includes/
    └── srcs/
```

---

## Checklist avant de push

- [ ] `norminette` passe sur tous les fichiers
- [ ] Compilation sans warnings avec `-Wall -Wextra -Werror`
- [ ] `valgrind` ne montre aucune fuite mémoire
- [ ] Tous les edge cases testés
- [ ] Makefile respecte les règles (pas de relink)
- [ ] Seules les fonctions autorisées sont utilisées
- [ ] Pas de fichiers inutiles (`.o`, `.a`, exécutables dans le repo)
- [ ] README si nécessaire (certains projets le demandent)

---

## Notes spécifiques au projet

<!-- Ajouter ici les particularités du projet actuel -->
<!-- Exemple pour get_next_line : -->
<!-- - BUFFER_SIZE doit être défini à la compilation -->
<!-- - lseek() est interdit -->
<!-- - Bonus : gérer plusieurs fd en même temps -->

---

*Template créé pour les projets du cursus 42*
*Norme version 3 - Dernière mise à jour : décembre 2024*
