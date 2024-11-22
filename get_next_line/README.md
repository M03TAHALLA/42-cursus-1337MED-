
# 📝 Get Next Line  

Get Next Line est un projet clé de la formation 42. Il met au défi les étudiants de créer une fonction efficace pour lire ligne par ligne depuis un fichier ou un flux d'entrée, tout en respectant des contraintes strictes de gestion de mémoire.  

---

## 📚 Table des Matières  
- [Aperçu](#aperçu)  
- [Fonctionnalités](#fonctionnalités)  
- [Installation](#installation)  
- [Guide d'Utilisation](#guide-dutilisation)  
- [Structure du Projet](#structure-du-projet)  
- [Mode Bonus](#mode-bonus)  
- [Auteur](#auteur)  

---

## 🧐 Aperçu  

`get_next_line` est une fonction qui :  
- Lit et retourne une ligne complète depuis un descripteur de fichier (jusqu'à un `\n` ou la fin du fichier).  
- Supporte des tailles de buffers dynamiques.  
- Garantit une gestion propre de la mémoire (sans fuite).  

---

## ✨ Fonctionnalités  

- **Lecture ligne par ligne** : Gère la lecture sur des fichiers volumineux ou des flux d'entrée continus.  
- **Descripteurs multiples (bonus)** : Lit simultanément depuis plusieurs fichiers ou flux sans interférence.  
- **Portabilité** : Compatible avec diverses plateformes grâce à son approche modulaire.  

---

## 🚀 Installation  

### Clonage du dépôt  

```bash
git clone <lien_du_dépôt>
cd get_next_line
```  

### Compilation  

- Compilez avec la taille de buffer souhaitée :  

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```  

- Intégrez directement les fichiers source dans votre projet si nécessaire.  

---

## 🛠️ Guide d'Utilisation  

Voici un exemple d'utilisation simple :  

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## 🗂️ Structure du Projet  

- **`get_next_line.c`** : Implémente la fonction principale.  
- **`get_next_line.h`** : Fichier d'en-tête.  
- **`get_next_line_utils.c`** : Contient les fonctions utilitaires.  
- **Bonus :**  
  - `get_next_line_bonus.c` et `get_next_line_bonus.h` : Support des descripteurs multiples.  
  - `get_next_line_utils_bonus.c` : Fonctions utilitaires pour le bonus.  

---

## 🎯 Mode Bonus  

Le mode bonus permet la gestion simultanée de plusieurs descripteurs de fichier ouverts, permettant une lecture parallèle de différents fichiers ou flux.  

---

## 🖋️ Auteur  

Projet réalisé par **[Votre Nom ou Identifiant 42]**.  

---

**Note** : Ce projet a été validé avec un score parfait de **125/125**.
