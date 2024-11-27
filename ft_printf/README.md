# 📝 ft_printf  

**ft_printf** est un projet clé de la formation 42, où les étudiants recréent leur propre version de la fonction standard `printf`. Ce projet met en avant la compréhension de la manipulation de chaînes, des conversions et des spécifications de format.  

---

## 📚 Table des Matières  
- [Aperçu](#aperçu)  
- [Fonctionnalités](#fonctionnalités)  
- [Installation](#installation)  
- [Guide d'Utilisation](#guide-dutilisation)  
- [Structure du Projet](#structure-du-projet)  
- [Auteur](#auteur)  

---

## 🧐 Aperçu  

`ft_printf` est une implémentation personnalisée de la fonction standard C `printf`.  
- Elle gère plusieurs spécificateurs de format tels que `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, et `%X`.  
- Elle garantit une gestion efficace des buffers et respecte les contraintes de gestion mémoire.  

---

## ✨ Fonctionnalités  

- **Spécifications de format prises en charge** :  
  - Caractère : `%c`  
  - Chaîne : `%s`  
  - Adresse mémoire : `%p`  
  - Entiers signés : `%d`, `%i`  
  - Entiers non signés : `%u`  
  - Hexadécimal : `%x`, `%X`  

- **Précision et largeur** : Prise en charge des modificateurs pour le formatage avancé.  
- **Portabilité** : Compatible avec divers environnements grâce à une conception robuste.  

---

## 🚀 Installation  

### Clonage du dépôt  

```bash
git clone https://github.com/M03TAHALLA/42-cursus-1337MED-.git 42-cursur
cd 42-cursur
cd ft_printf
```  

### Compilation  

- Compilez avec la taille de buffer souhaitée :  

```bash
gcc -Wall -Wextra -Werror ft_printf.c -o ft_printf
```  

- Vous pouvez également intégrer ft_printf dans vos projets en ajoutant les fichiers source nécessaires.  

---

## 🛠️ Guide d'Utilisation  

Voici un exemple d'utilisation simple :  

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Bonjour, %s! Vous avez %d points.\n", "Tahalla", 100);
    return (0);
}
```

---

## 🗂️ Structure du Projet  

- **`ft_printf.c`** : Contient l'implémentation principale de la fonction.  
- **`ft_printf.h`** : Fichier d'en-tête avec les prototypes et les définitions.
- **`Makefile`** : Makefile pour Compiler Functions Utils Et archive ...

---


## 🖋️ Auteur  

Projet réalisé par **[Tahalla Mohammed]**.  

---

**Note** : Ce projet a été validé avec un score parfait de **100/100**.
