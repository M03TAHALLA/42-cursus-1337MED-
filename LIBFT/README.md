
# LIBFT

![Badge](https://img.shields.io/badge/Score-125%2F125-brightgreen)
![C Language](https://img.shields.io/badge/Language-C-blue)
![Status](https://img.shields.io/badge/Status-Completed-success)

## 📖 Introduction

**LIBFT** (Library Functions) est un projet de l'école 42 visant à recréer des fonctions standard de la bibliothèque C ainsi que des fonctionnalités supplémentaires. Ce projet constitue la première étape de la formation à 42, renforçant les bases de la programmation en C et des structures de données.

---

## 🛠️ Fonctionnalités

La bibliothèque **LIBFT** inclut :  

### 🔹 Fonctions de la libc
- `ft_atoi` : Conversion de chaîne en entier.  
- `ft_strlen` : Calcul de la longueur d'une chaîne.  
- `ft_memset`, `ft_memcpy`, `ft_memmove` : Manipulation de la mémoire.  
- ... *(et bien d'autres !)*  

### 🔹 Fonctions supplémentaires
- `ft_substr` : Extraction d'une sous-chaîne.  
- `ft_strjoin` : Concatenation de chaînes.  
- `ft_split` : Découpage d'une chaîne en tableau.  

### 🔹 Fonctions de gestion des listes chaînées (bonus)
- `ft_lstnew` : Création d'un nouvel élément.  
- `ft_lstadd_back` : Ajout en fin de liste.  
- `ft_lstmap` : Application d'une fonction à chaque élément.  

---

## 🚀 Compilation et Utilisation

1. **Cloner le dépôt :**
   ```bash
   git clone https://github.com/M03TAHALLA/42-cursus-1337MED-.git
   cd LIBFT
   ```

2. **Compiler la bibliothèque :**
   ```bash
   make
   ```
   Cela génère un fichier `libft.a`.

3. **Inclure dans vos projets :**
   - Ajoutez `libft.a` et `libft.h` à votre projet.
   - Liez la bibliothèque lors de la compilation :
     ```bash
     gcc -Wall -Wextra -Werror main.c -L. -lft -o executable
     ```

---

## 📂 Structure du Projet

```
LIBFT/
├── Makefile
├── libft.h
├── ft_*.c
└── bonus/
    ├── ft_lst*.c
```

---

## 📈 Résultats et Validation

- **Score obtenu** : 125/125  
- Validé avec succès dans l'écosystème 42.

---

## 🤝 Contributeur

- **Tahalla Mohammed**  
  Étudiant à [1337 Med](https://www.1337.ma)  
  [GitHub](https://github.com/M03TAHALLA) | [LinkedIn](#)

---

## 📜 Licence

Ce projet est open-source et disponible sous la licence MIT.

---

**LIBFT** est une base solide pour des projets futurs comme **GNL** et **Ft_printf**. Continuez à apprendre et à construire avec passion !
