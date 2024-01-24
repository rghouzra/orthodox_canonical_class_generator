#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctype.h>
#include <ctime>

int main() {
    std::string PATH = "";
    std::string CLASS = "";
    std::string OPTION = "";

    std::cout << "path of your working dir :";
    std::cin >> PATH;
	
    if (std::ifstream(PATH)) {
        chdir(PATH.c_str());
        std::cout << "classs name: ";
        std::cin >> CLASS;

        if (!CLASS.empty()) {
            std::ofstream classHeader(CLASS + ".hpp");
			 std::time_t currentTime = std::time(0);
			classHeader << "//\n";
            classHeader << "// Created by reda ghouzraf on " << std::asctime(std::localtime(&currentTime)) << "//\n";
            classHeader << "#ifndef " << CLASS << "_HPP" << std::endl;
            classHeader << "#define " << CLASS << "_HPP" << std::endl;
            classHeader << "\n#include <iostream>\n" << std::endl;
            classHeader << "\nclass " << CLASS << "\n{" << std::endl;
            classHeader << "public:\n";
            classHeader << "    " << CLASS << "();\n";
            classHeader << "    " << CLASS << "(const " << CLASS << "& obj);\n";
            classHeader << "    ~" << CLASS << "();\n";
            classHeader << "    " << CLASS << "& operator=(const " << CLASS << "& obj);\n";
            classHeader << "\nprivate:\n};\n";
            classHeader << "#endif /*" <<CLASS <<"_HPP*/" << std::endl;

            std::ofstream classSource(CLASS + ".cpp");
			classSource << "//\n";
            classSource << "// Created by reda ghouzraf on " << std::asctime(std::localtime(&currentTime)) << "//\n";
            classSource << "#include \"" << CLASS << ".hpp\"\n" << std::endl;
            classSource << CLASS << "::" << CLASS << "()\n";
            classSource << "{\n";
            classSource << "    std::cout << \"" << CLASS << " : Default Constructor Called\" << std::endl;\n";
            classSource << "}\n\n";
            classSource << CLASS << "::~" << CLASS << "()\n";
            classSource << "{\n";
            classSource << "    std::cout << \"" << CLASS << " : Destructor Called\" << std::endl;\n";
            classSource << "}\n\n";
            classSource << CLASS << "::" << CLASS << "(const " << CLASS << "& obj)\n";
            classSource << "{\n";
            classSource << "    std::cout << \"Copy Constructor Called\" << std::endl;\n";
            classSource << "    if (this != &obj)\n";
            classSource << "        *this = obj;\n";
            classSource << "}\n\n";
            classSource << CLASS << "& " << CLASS << "::operator=(const " << CLASS << "& obj)\n";
            classSource << "{\n";
            classSource << "    std::cout << \"Copy Assignment Operator Called\" << std::endl;\n";
            classSource << "    if (this != &obj)\n";
            classSource << "    {\n";
            classSource << "        // this->attributes = obj.attributes;\n";
            classSource << "        // ...\n";
            classSource << "    }\n";
            classSource << "    return (*this);\n";
            classSource << "}\n";

            std::cout << "\x1b[33mCreate main.cpp and Makefile \033[m[\x1b[32my\033[m/\x1b[31mn\033[m] : ";
            std::cin >> OPTION;

            if (OPTION == "y" || OPTION == "yes") {
                std::ofstream mainFile("main.cpp");
				mainFile << "//\n";
            	mainFile << "// Created by reda ghouzraf on " << std::asctime(std::localtime(&currentTime)) << "//\n";
                mainFile << "#include \"" << CLASS << ".hpp\"\n\n";
                mainFile << "int main()\n";
                mainFile << "{\n";
                mainFile << "    // Your Code\n";
                mainFile << "    return 0;\n";
                mainFile << "}\n";

                std::ofstream makefile("Makefile");
				makefile << "#\n";
            	makefile << "# Created by reda ghouzraf on " << std::asctime(std::localtime(&currentTime)) << "#\n";
                makefile << "NAME = " << CLASS << "\n";
                makefile << "FLAGS = -Wall -Wextra -Werror\n";
                makefile << "CC = c++\n";
                makefile << "STD = -std=c++98\n";
                makefile << "SRC = " << CLASS << ".cpp main.cpp\n";
                makefile << "INC = " << CLASS << ".hpp\n";
                makefile << "OBJ = $(SRC:.cpp=.o)\n";
                makefile << "all: $(NAME)\n";
                makefile << "$(NAME): $(OBJ)\n";
                makefile << "	$(CC) $(FLAGS) $(STD) $(OBJ) -o $(NAME)\n";
                makefile << "%.o: %.cpp $(INC)\n";
                makefile << "	$(CC) $(FLAGS) -c $< -o $@\n";
                makefile << "clean:\n";
                makefile << "	rm -rf $(OBJ)\n";
                makefile << "fclean: clean\n";
                makefile << "	rm -rf $(NAME)\n";
                makefile << "re: fclean all\n";
            } else {
                std::cout << "______________________________________\n";
                std::cout << "\x1b[31mNo Class Name Entered\033[m\n";
            }
        } else {
            std::cout << "______________________________________\n";
            std::cout << "\x1b[31mNo Class Name Entered\033[m\n";
        }
    } else {
        std::cout << "______________________________________\n";
        std::cout << "\x1b[31m*** " << PATH << " : Path not found !!\033[m\n";
    }

    return 0;
}
