
# ft_printf

`ft_printf` est une ré-implémentation personnalisée de la fonction standard `printf` de la bibliothèque C. Ce projet fait partie des défis du cursus 42 et met l'accent sur la compréhension approfondie des fonctions variadiques, de la gestion de la mémoire et de la construction d'une bibliothèque C efficace.

## Fonctionnalités

- Support des conversions classiques telles que :
  - `%c` : caractères
  - `%s` : chaînes de caractères
  - `%p` : adresses mémoire
  - `%d` / `%i` : entiers décimaux
  - `%u` : entiers non signés
  - `%x` / `%X` : entiers hexadécimaux (minuscule/majuscule)
- Gestion robuste des entrées avec des comportements similaires à la fonction standard.

## Structure du Projet

- **Fichiers source** :
  - `base_nbr.c` : Gestion des conversions de bases numériques.
  - `ft_printf.c` : Implémentation principale de la fonction `ft_printf`.
  - `ft_putadd.c`, `ft_putchar.c`, `ft_putnbr.c`, `ft_putstr.c` : Fonctions utilitaires pour afficher des données.
  - `ft_strlen.c` : Calcul de la longueur d'une chaîne.
- **Fichier d'en-tête** : `ft_printf.h`
- **Makefile** : Automatisation de la compilation avec des règles standard (`all`, `clean`, `fclean`, `re`).

## Compilation

Pour compiler le projet, utilisez simplement la commande suivante :

```bash
make
```

Cela générera un fichier exécutable ou une bibliothèque selon votre configuration.

## Utilisation

Incluez `ft_printf.h` dans vos fichiers et utilisez `ft_printf` comme vous le feriez avec la fonction standard `printf`.

Exemple :

```c
#include "ft_printf.h"

int main(void) {
    ft_printf("Hello, %s!\n", "World");
    return 0;
}
```

## Objectifs pédagogiques

Ce projet vise à :

- Renforcer la compréhension des fonctions variadiques.
- Approfondir la manipulation des pointeurs et des chaînes en C.
- Mettre en pratique des concepts de gestion de projet avec `Makefile`.

## Contribution

Les contributions sont les bienvenues. N'hésitez pas à proposer des améliorations ou à signaler des problèmes via des issues sur le [dépôt GitHub](https://github.com/M03TAHALLA/42-cursus-1337MED-).

## Licence

Ce projet est sous licence MIT. Consultez le fichier `LICENSE` pour plus de détails.

---

Fait avec ❤️ dans le cadre du cursus 42.
