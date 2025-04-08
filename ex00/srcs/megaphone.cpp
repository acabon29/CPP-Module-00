#include <iostream>

// attention, c'est interdit :
// permet de mettre automatiquement std dans std::count et autre
// using namespace std;

// la forme canonique, dite de Coplien sera utilise pour les classes
// faire attention pour les entetes de classe : pas de "double inclusion"
// proteger les entetes avec include guards

int main(int argc, char const *argv[])
{
	std::string str = argv[1];

	if (argc > 2)
		std::cout << "Trop d'arguments" << std::endl;
	for (size_t i = 0; i < str.length(); i++)
		str[i] = toupper(argv[1][i]);
	
	std::cout << str << std::endl;
	return 0;
}
