# minitalk

Un programme client et un programme server

Le serveur ne prend aucun argument

./server

Le client prend en argument le PID du serveur (qui s'affiche après l'avoir lancé) et le message à envoyer.

./client PID MESSAGE

Notes:

Ne pas utiliser pause, sinon on peut recevoir un signal avant d'arriver dans pause et le programme hang

Ne pas utiliser de fonctions qui ne sont pas signal safe dans les handlers de signaux
