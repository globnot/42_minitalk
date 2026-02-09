# minitalk

*This project has been created as part of the 42 curriculum by aborda.*

---

## Description

**Minitalk** est un projet de communication inter-processus (IPC) utilisant les signaux UNIX. L'objectif est de transmettre une chaîne de caractères d'un programme client vers un programme serveur, en utilisant uniquement les signaux `SIGUSR1` et `SIGUSR2`.

### Objectifs

- Comprendre le fonctionnement des signaux UNIX
- Implémenter une communication bit par bit entre deux processus
- Gérer la synchronisation et la fiabilité de la transmission

### Fonctionnement

- Le **serveur** démarre et affiche son PID
- Le **client** prend en paramètre le PID du serveur et la chaîne à envoyer
- Chaque caractère est encodé en 8 bits et transmis via `SIGUSR1` (bit 0) et `SIGUSR2` (bit 1)
- Le serveur reconstruit les caractères et les affiche

---

## Instructions

### Prérequis

- `gcc`
- `make`
- Système UNIX/Linux (signaux POSIX)

### Compilation

```bash
make
```

Cette commande génère les exécutables `client` et `server`

### Utilisation

**1. Lancer le serveur :**

```bash
./server
```

Le serveur affiche son PID, par exemple : `server PID : 12345`

**2. Envoyer un message avec le client :**

```bash
./client <PID> "<message>"
```

**Exemples :**

```bash
# Envoyer un message simple
./client 12345 "Hello World"

# Envoyer un message long
./client 12345 "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
```

### Commandes Makefile

- `make` ou `make all` : compile le client et le serveur
- `make clean` : supprime les fichiers objets
- `make fclean` : supprime les fichiers objets et les exécutables
- `make re` : recompile entièrement le projet

### Gestion d'erreurs

Le programme gère les cas suivants :

- Nombre d'arguments invalide
- PID invalide ou négatif
- Échec d'envoi de signal (`kill` retourne -1)

---

## Resources

### Documentation et références

- [Signaux UNIX - man 7 signal](https://man7.org/linux/man-pages/man7/signal.7.html)
- [sigaction - man 2 sigaction](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [kill - man 2 kill](https://man7.org/linux/man-pages/man2/kill.2.html)
- Sujet officiel du projet : `en.subject.pdf`
- Norme 42 : `fr.norme.pdf`

### Utilisation de l'IA

Dans le cadre de ce projet, l'intelligence artificielle (Claude) a été utilisée comme **outil d'assistance pédagogique** en complément du **PEERLEARNING** :

- **Compréhension de concepts** : clarification de notions (signaux UNIX, communication IPC, encodage bit par bit)
- **Raisonnement** : aide à la réflexion sur l'architecture du code et la gestion des signaux
- **Debugging** : assistance dans l'identification de bugs logiques

**Important** : L'IA n'a **jamais été utilisée pour générer du code complet**. L'ensemble du code a été écrit manuellement, avec l'IA servant uniquement de guide pédagogique pour comprendre les concepts et améliorer le raisonnement.

---

## Auteur

**Antoine Borda (aborda)** - École 42 Paris
