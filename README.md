# minitalk

Un programme client et un programme server (Unbuntu x64)

Le serveur ne prend aucun argument

./server

Le client prend en argument le PID du serveur (qui s'affiche après l'avoir lancé) et le message à envoyer.

./client PID MESSAGE

Notes:

Ne pas utiliser pause, sinon on peut recevoir un signal avant d'arriver dans pause et le programme hang

Ne pas utiliser de fonctions qui ne sont pas signal safe dans les handlers de signaux

On peut récuperer le PID du client qui a envoyé le signal avec sigaction (voir le man de sigaction), indispendable pour renvoyer un signal au client afin qu'il attende bien que tout sois reçu avant de continuer.
