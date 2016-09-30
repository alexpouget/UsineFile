# UsineFile
Implementer la structure de donnée FILE et simuler une utilisation dans une usine

Exercice 2 : L’usine
À l’aide de C++, vous allez écrire un programme qui va simuler une chaîne de production qui assemble des pistons. Le fonctionnement est décrit ci-dessus. En effet, une usine fait appel à vous afin de simuler le fonctionnement de son usine de recyclage de pistons.
Un piston est composé de trois pièces : la tête du piston, la jupe du piston et finalement son axe. L’assemblage des trois pièces se fait au niveau d’une machine principale MP.
L’arrivée des trois pièces à l’usine se fait sur le même dock et elles arrivent mélangées dans un même carton. Nous ne savons pas ce que contient un carton. La première opération consiste donc à trier les pièces pour les séparer. Chaque pièce passe ensuite sur une machine qui va procéder à son usinage pour les rendre de meilleure qualité et ce, dépendamment de sa nature. Nous aurons ainsi une machine MT pour les têtes, MJ pour les jupes et MA pour les axes. Les temps d’usinage respectifs sont de 2, 3 et 2.5 minutes pour les têtes, les jupes et les axes. La machine MP traite les pièces en 1 minute. Cependant, les 4 machines dont vous disposez sont presque toujours en panne et nécessitent des réparations. En effet, pour chaque pièce, une machine aurait jusqu’à 25% de chance de tomber en panne et la réparation nécessite entre 5 et 10 minutes.
Il est évident que la machine MP nécessite la présence des 3 pièces pour fabriquer un piston.
Nous vous demandons de reproduire la chaîne de montage et de déterminer le temps nécessaire pour monter 100 pistons. Le tout devra être effectué en utilisant les files.

Pour les fins de cet exercice vous devrez utiliser la structure File suivante (vous pourrez y apporter quelques modifications si nécessaire) :
  
 template<typename T>
class File
{public: // constructeurs et destructeurs: File() ;
File(const File &);
~File();
// modificateurs
void enfiler(const T&);
T defiler();
// sélecteurs
int taille() const;
bool estVide() const;
bool estPleine() const;
const T& premier() const; //  tête de la file
const T& dernier() const; // queue de la file
// surcharges d'opérateurs
const File<T>& operator = (const File<T>&) throw (bad_alloc);
template <typename U> friend std::ostream& operator <<
(std::ostream& f, const File<U>& q);
private: // ...Modèle d'implantation };
