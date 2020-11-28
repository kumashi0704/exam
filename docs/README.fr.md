# Introduction

Ce système d'examens vous donne des exercices un par un, et vous corrigera au fur et à mesure que vous terminez vos exercices, quand vous le demanderez.

Un examen est une suite de niveaux, et chaque niveaux a un pool d'exercices possibles qui sont distribués aléatoirement. Votre voison n'aura probablement pas les mêmes exercices que vous. Oui, c'est injuste, mais la vie est injuste, faites vous une raison.

Pour chaque niveau que vous validerez, vous gagnerez des points, jusqu'à un maximum de 100.

## Avant l'examen

Avant de passer un examen, vous allez devoir vous inscrire à au moins un projet d'examen sur l'intra (Ou retry au moins un projet si ce n'est pas votre première fois). Vous pouvez vous inscrire à autant d'examens que vous voulez, il n'y a pas de restrictions là dessus.

Une fois que vous vous êtes inscrit à au moins un projet, vous allez pouvoir utiliser `examshell`, mais seulement en mode practice (entraînement).

Si vous voulez passer un examen pour de vrai, vous devez aussi vous inscrire sur l'intra à une session d'exam, y être À L'HEURE, et vous logger en tant que "exam" dans la salle appropriée. Seulement dans ces conditions vous pourrez faire un exam en mode réel.

## Modes d'examen

Il y a deux modes d'examen :

* Le mode "practice" (entraînement), que vous pouvez utiliser depuis votre propre compte, de n'importe où, quand vous voulez. Dans ce mode, tout marche normalement, mais votre note n'est pas prise en compte sur l'intra. Vous pouvez utiliser ce mode autant que vous voulez.
* Le mode "real" (réel), que vous ne pouvez utiliser que depuis le compte exam, dans une salle d'exam, pendant une session d'exam. Dans ce mode, votre note VA être comptée sur l'intra, et sera définitive.

## Examshell

Vous utilisez le système d'examen via un programme appelé `examshell`.

Il doit être lancé dans un terminal à part, tout au plus 10 minutes après le début officiel de l'examen. Comprendre par là que vous devez avoir lancé `examshell`, choisi un projet, un mode et un niveau de départ avant <heure de départ> + 10 minutes. 
Si vous coupez `examshell` sans faire exprès une fois l'exam démarré, ce n'est pas grave, relancez le simplement.

# Version courte

1. Lancement d'examshell
2. Examshell vous donne la liste des examens auxquels vous avez accès
3. Vous choisissez un exam et un niveau de départ
4. Le système vous crée un dépôt Git et le clone dans BASEDIR/rendu
5. Le système vous donne un exercice aléatoire du niveau courant
6. Examshell récupère le sujet et le met dans BASEDIR/subjects/NOM_EXERCICE
7. Examshell vous dit quel exercice faire, combien de points vous pouvez gagner, et où le rendre
8. Vous travaillez sur votre exercice
9. Vous pushez votre exercice sur le dépôt de rendu comme d'habitude
10. Quand vous êtes sûr d'avoir fini, vous dites à examshell de vous corriger avec la commande `grademe`
11. Le système vous corrige
12. Votre trace est sauvée dans BASEDIR/traces/X_Y_NOM_EXERCICE
13. Si réussi: Vous gagnez des points et grimpez d'un niveau. S'il reste des niveaux, goto 5, sinon l'exam est fini.
14. Si échec: Vous restez au même niveau et ne gagnez pas de points. Si il reste des exercices disponibles dans le niveau courant, goto 5, sinon pas de chance, l'exam est fini.

Pas compris ? Tant pis, lisez la version longue.

# Version longue

On va faire un exemple pour cette documentation, en mode practice. Quand on est en practice, on travaille dans `~/exam-basedir/`, mais en mode real, on travaille dans `~/`.

## Etape 1 : Lancer examshell

```
zaz@blackjack ~ $ examshell
examshell v0.1.1

WARNING
Your exam files will be stored in ~/exam-basedir
THIS DIRECTORY WILL BE ENTIRELY EMPTIED BEFORE YOU START
So, if you do have important things there, Ctrl-C NOW and back them up before running this.
(Press Enter to continue...)
```

Cet avertissement est normal, c'est pour être sûr que vous n'avez pas déjà des choses dans `~/exam-basedir/`, car examshell va vider ce dossier pour commencer propre.

En mode real, cet avertissement n'apparaît pas.

## Etape 2 : Choix de l'examen

Vous devez choisir le projet que vous voulez faire, et le niveau auquel vous voulez le démarrer. Vous ne pouvez démarrer qu'aux niveau que vous avez déjà validé une fois pour le projet en question.

```
[...]
Getting current exam session from server...

The following projects are available to you at the moment:

  0 : Exam C
      Maximum start level    : 4 (Best grade you got is 75)
      Real mode available    : no (You must subscribe to an exam event)
      Practice mode available: yes (Ends in 4 hours, 0 minutes and 0 seconds)

There is only one project you can do right now.
Automatically selecting project 0: "Exam C"

This project can only be done in practice mode
In 'practice' mode, your grade will not be taken into account, and you can only access your repository from your regular (non-exam) session

Please select the level at which you would like to start your session
Be aware that if you select a level higher than 0, you will only gain however many points the previous levels would have given you IF you complete your selected starting level !

Desired start level (0-4):
```

S'il y a plus d'un examen disponible, vous allez devoir choisir, bien entendu.

Pour cet exemple, on va démarrer au niveau 0. Si on ne vous demande pas de choisir, c'est normal, c'est juste que vous ne pouvez choisir que 0 de toute façon.

```
[...]
Desired start level (0-4): 0

You are about to start the project "Exam C", in practice mode, at level 0.
You would have 4 hours, 0 minutes and 0 seconds to complete this project
Confirm ? [y/n]
```

Si pour une raison quelconque vous n'êtes pas sûr de votre choix, vous pouvez juste taper `n` pour annuler et recommencer.

Notez qu'après cette étape, si vous relancez examshell, vous n'aurez plus à choisir. Normal.


## Etape 3 : Préparation du répertoire de travail

Après confirmation, examshell va préparer votre répertoire de travail, cloner le dépôt Git approprié, etc ...

```
[...]
Confirm ? [y/n] y
Selecting project...
Creating required directories...
Ensuring your Git repository for this exam is present and correct...
Git repository is not cloned yet. Cloning...
Cloning into '/Users/zaz/exam-basedir/rendu'...
vogsphere: (INFO) Transaction ID : 8ed938b3-fe1e-4eb6-b561-0f6622e12b82
vogsphere: (INFO) Please mention this ID in any ticket you create concerning this transaction
vogsphere: (INFO) This transaction has been started at 2015-05-28 11:07:49, server time.
vogsphere: (INFO) Rights will be determined using this time, so do NOT cut the connection.
vogsphere: (INFO) It appears you are mmontinet. If that's not true, check your Kerberos tickets (klist)
vogsphere: (INFO) You have read and write rights on this repository
warning: You appear to have cloned an empty repository.

Your git repository was successfully cloned to ~/exam-basedir/rendu

The following commands are available to you:
  status: Displays the status of your session, including information about
    your current assignment, and the exam history.
  grademe: Asks the server to grade your current assignment. If you
    have done it right, you will gain the points of the current assignment, go
    up a level, and try the next one. If you fail, however, you will have
    another assignment of the same level to do, and it will potentially bring
    you less points on your grade ... So be sure of yourself before you launch
    this command !
  finish: Tells the server you are finished with your exam.

You can log out at any time. If this program tells you you earned points,
then they will be counted whatever happens.

(Press Enter to continue...)
```

## Etape 4 : Obtenir un exercice

Examshell va récupérer un exercice aléatoire pour vous.

Le sujet sera dans le répertoire `subjects`. Vous pouvez le lire dans un terminal, ce n'est que du texte.

```
[...]
================================================================================
You are currently at level 0
You are running in practice mode (Your grade does not count)
Your current grade is 0/100
Assignments:
  Level 0:
    0: max for 16 potential points (Current)

Your current assignment is max for 16 potential points
It is assignment 0 for level 0
The subject is located at: ~/exam-basedir/subjects/max
You must turn in your files in a subdirectory of your Git repository with the
same name as the assignment (~/exam-basedir/rendu/max).
Of course, you must still push...

The end date for this exam is: 28/05/2015 15:07:47
You have 3 hours, 54 minutes and 11 seconds remaining
================================================================================
You can now work on your assignment. When you are sure you're done with it,
push it to vogsphere, and then use the "grademe" command to be graded.
examshell>
```

Cet affichage est toujours disponible via la commande `status` dans examshell.

## Etape 5 : Travailler sur votre exercice

Maintenant il faut, ben, faire l'exercice.

Notez qu'il DOIT être rendu dans le répertoire précisé par examshell, qui sera toujours un sous-répertoire du clone de votre dépôt de rendu. Pas de fautes, ou rien. Si vous vous trompez de répertoire, ou de nom de fichier, vous allez rater votre exercice sans aucune possibilité de retour en arrière. Ça serait con.

Dans notre exemple, on doit rentre un fichier `max.c` dans le répertoire `~/exam-basedir/rendu/max/`.

Vous DEVEZ push votre travail quand vous avez fini, comme pour un projet normal. N'oubliez pas.

## Etape 6 : Demander à être corrigé

Quand vous êtes SÛR que votre travail est bon, et que tout est push, vous pouvez utiliser la commande `grademe` pour demander une correction:

```
examshell> grademe

Before continuing, please make ABSOLUTELY SURE that you have pushed your files,
that they are in the right directory, that you didn't forget anything, etc...
If your assignment is wrong, you will have another assignment at the same level,
but with less potential points to earn!

Are you sure? [y/N]
```

Disons qu'on est sûr...

```
[...]

Are you sure? [y/N] y
OK, making grading request to server now.

We will now wait for the job to complete.
Please be patient, this CAN take several minutes...
(10 seconds is fast, 30 seconds is expected, 3 minutes is a maximum)
waiting...
```

Maintenant on attend la réponse du système. Cela PEUT prendre un peu de temps, mais c'est NORMAL, donc ne paniquez pas à moins que ça prenne vraiment une ou deux minutes, auquel cas, demandez à un membre du staff.

### Victoire !

```
[...]
waiting...
>>>>>>>>>> SUCCESS <<<<<<<<<<
You have successfully completed the assignment and earned 16 points!
Trace saved to ~/exam-basedir/traces/0-0_max.trace

(Press Enter to continue...)
```

Dans ce cas, on a juste. La trace de correction est sauvegardée pour qu'on puisse la lire si on veut.

Le prochain status montrera que:

* On a gagné les points en jeu pour l'exercice (16)
* On a gagné un niveau (Maintenant on est au 1)
* On a un nouvel exercice

```
[...]
(Press Enter to continue...)

================================================================================
You are currently at level 1
You are running in practice mode (Your grade does not count)
Your current grade is 16/100
Assignments:
  Level 0:
    0: max for 16 potential points (Success)
  Level 1:
    0: wdmatch for 16 potential points (Current)

Your current assignment is wdmatch for 16 potential points
It is assignment 0 for level 1
The subject is located at: ~/exam-basedir/subjects/wdmatch
You must turn in your files in a subdirectory of your Git repository with the
same name as the assignment (~/exam-basedir/rendu/wdmatch).
Of course, you must still push...

The end date for this exam is: 28/05/2015 15:07:47
You have 3 hours, 42 minutes and 27 seconds remaining
================================================================================
You can now work on your assignment. When you are sure you're done with it,
push it to vogsphere, and then use the "grademe" command to be graded.
examshell>
```

Si c'avait été le dernier niveau de l'exam, examshell nous aurait dit que l'exam était fini.

### Pitoyable défaite :(

On va rater celui-ci juste pour voir:

```
[...]
examshell> grademe

Before continuing, please make ABSOLUTELY SURE that you have pushed your files,
that they are in the right directory, that you didn't forget anything, etc...
If your assignment is wrong, you will have another assignment at the same level,
but with less potential points to earn!

Are you sure? [y/N] y
OK, making grading request to server now.

We will now wait for the job to complete.
Please be patient, this CAN take several minutes...
(10 seconds is fast, 30 seconds is expected, 3 minutes is a maximum)
waiting...
>>>>>>>>>> FAILURE <<<<<<<<<<
You have failed the assignment.
Trace saved to ~/exam-basedir/traces/1-0_wdmatch.trace

(Press Enter to continue...)

================================================================================
You are currently at level 1
You are running in practice mode (Your grade does not count)
Your current grade is 16/100
Assignments:
  Level 0:
    0: max for 16 potential points (Success)
  Level 1:
    0: wdmatch for 16 potential points (Failure)
    1: ft_strrev for 11 potential points (Current)

Your current assignment is ft_strrev for 11 potential points
It is assignment 1 for level 1
The subject is located at: ~/exam-basedir/subjects/ft_strrev
You must turn in your files in a subdirectory of your Git repository with the
same name as the assignment (~/exam-basedir/rendu/ft_strrev).
Of course, you must still push...

The end date for this exam is: 28/05/2015 15:07:47
You have 3 hours, 41 minutes and 25 seconds remaining
================================================================================
You can now work on your assignment. When you are sure you're done with it,
push it to vogsphere, and then use the "grademe" command to be graded.
examshell>
```

Dans ce cas c'est raté, donc :

* On ne gagne PAS de points
* On ne gagne PAS de niveau
* On récupère un nouvel exercice, mais avec 5 points de moins à gagner !

Si c'avait été le dernier exercice de ce niveau, examshell nous aurait dit que l'exam était fini.

### Error :<

Il y a la (faible) possibilité que examshell vous dise que la correction a donné une ERROR. Ça ne veut PAS dire que vous avez raté l'exercice, mais que le système de correction lui-même a eu une erreur.

PAS DE PANIQUE !

Vous avez l'option de "retry" ou "abort". Vous DEVRIEZ retry au moins une fois: Les erreurs dans le système de corrections sont rares, et généralement éphémères, donc elles se résolvent souvent comme ça.
Si un retry ne règle pas l'erreur, appelez un membre du staff !

Si vraiment plus rien ne marche, le staff vous dira peut-être d'abort. À ce moment là, l'exercice est compté faux, et vous aurez un nouvel exercice, mais vous n'aurez pas de pénalité !

## Etape 7 : C'est reparti

C'est à peu près tout. Vous allez continuer de recevoir des exercices jusqu'à réussir tout l'exam ou rater tous les exercices d'un niveau.

Si vous voulez arrêter plus tôt, utilisez la commande `finish`:

```
examshell> finish
Please confirm that you REALLY want to end your current session.
If you do, you will not be able to do anything with it anymore!
Are you finished? [y/N] y
Your session has been marked as finished. You may now log out.
zaz@blackjack ~ $
```

# FAQ / Erreurs fréquentes

## J'ai coupé examshell, au secours !

Relancez-le, c'est pas grave.

## Examshell me dit "Login window expired", c'est quoi ?

Vous avez 10 minutes pour choisir un exam après la date de début, après quoi vous aurez cette erreur parce que c'est juste trop tard.
Non, vous ne pouvez plus rien faire.

## Examshell me dit "Mismatched versions"

Votre Mac n'est juste pas à jour. Changez de poste, ou passez au Bocal nous demander de le mettre à jour.

## Pourquoi est-ce que je ne peux pas utiliser le mode practice // le mode real ?

Examshell vous dit exactement pourquoi. Voici les raisons possibles:

* "Can't practice when logged in as 'exam'"
	* Vous devez utiliser votre propre compte pour utiliser le mode practice
* "Project doesn't allow it"
	* Cela signifie que la session à laquelle vous êtes inscrit ne vous permet pas de faire cet examen en particulier. Vous n'y pouvez rien.
* "You must subscribe to an exam event"
	* Comme dit dans l'intro, pour faire un exam en mode réel, vous devez vous inscrire à une session d'examen.
* "You must retry the project on the intranet"
	* Vous ne pouvez pas utiliser le mode réel sans avoir un groupe en cours à un projet d'examen, car le système ne pourrait pas vous noter. Vous devez vous inscrire à un projet d'exam, ou en retry un.
* "Current event doesn't allow for this exam"
	* Certains examens sont restreints à des sessions particulières, en particulier durant les piscines. Vous devez vous inscrire à une session qui autorise cet exam.
* "Can't do it from this location"
	* La plupart des examens sont restreints à certaines salles afin d'assurer des conditions d'examen contrôlées. Vous devez vous rendre dans une de ces salles pour faire cet exam.
* "Too early, well be OK in XXX" // "Too late, ended at XXX"
	* Signifie que votre session d'exam n'est pas encore démarrée ou est déjà finie
* "Must login as 'exam' to run in real mode"
	* Plutôt clair non ? Loggez vous en "exam", avec le mot de passe "exam"

## J'ai pas eu les mêmes exercices que mon voisin, C'EST INJUSTE !

Oui. Pas de bol. C'est la vie.

## Est-ce que je peux accéder à mon dépôt après l'exam ? Et les sujets ?

Normalement, vous recevrez un rapport d'exam par email quand l'exam sera marqué comme terminé. Il contient les sujets, traces, et votre rendu.

Si vous ne le recevez pas, même après avoir bien attendu ... Pas de bol. La vie est injuste.

## Examshell me dit que j'ai échoué, mais je suis sûr d'avoir juste !

Vous avez sûrement oublié un truc:

* Pensé à push ?
* Vraiment ?
* Non mais blague à part, vraiment ?
* Bon répertoire de rendu ?
* Bons noms de fichiers ?
* Est-ce que c'est le bon exercice ?
* Sans déconner, vous avez push ?
* Etc...

Si vous êtes vraiment, vraiment, VRAIMENT, ABSOLUMENT sûr d'avoir juste, et que vous pensez que le système a voulu vous montrer ce que pourrait donner une nuit d'amour avec lui, une batte de baseball et 17,3 kilogrammes de lubrifiant industriel, alors vous pouvez venir le dire au staff, APRÈS L'EXAM. On regardera, mais s'il vous plaît, par PITIÉ, réfléchissez BIEN avant de venir nous voir : C'est VRAIMENT sûrement de votre faute, et ça nous prend du temps de regarder votre exercice pour tenter d'y trouver une éventuelle erreur.

## Votre système il est nul, je veux l'ancien !

Non il est pas nul. Non vous n'aurez pas l'ancien, c'est pas de bol.

## J'ai trouvé un bug ! J'AI TROUVÉ UN BUG !

Sérieux ?

Bon, ben cool, venez nous le montrer. On va pas vous taper dessus, sauf si vous l'exploitez.

## J'ai trouvé un bug, je l'ai exploité, et vous ne m'aurez jamais !

Si, on vous aura. À un moment ! Et on espère de toute coeur que vous passerez un bon moment à chercher une nouvelle école :)

Sérieusement, soyez pas cons, venez nous montrer le bug et passez à autre chose. Ça vaut pas le coup de se faire virer pour quelques points, si ?

## J'ai demandé une correction, mais c'est vraiment long !

Est-ce que ça finit à un moment ? Si oui, alors y'a pas de problème.

Si après une minute ou deux c'est pas fini, passez chercher un staff, parce que ce n'est pas normal, c'est sûrement pas juste vous, et c'est rapide à régler.

## Pourquoi est-ce qu'on ne peut pas utiliser le mode practice en session d'exam ?

Parce que zaz a dit qu'on pouvait pas.

## J'ai une autre question qui n'est pas listée ici, votre FAQ c'est de la merde !

Passez nous voir et on l'ajoutera. On est humains, on ne peut pas penser à tout (Sans drogue)
