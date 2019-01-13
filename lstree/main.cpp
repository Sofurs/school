#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <string>

void recursive_listing(const char *ptr, int depth) {
    DIR *dir;

    if (!(dir = opendir(ptr))) {
        return;
    }

    dirent *dirstr;
    while (dirstr = readdir(dir)) {
        if (!strcmp(dirstr->d_name, ".") || !strcmp(dirstr->d_name, "..") || dirstr->d_name[0] == '.') {
            continue;
        }

        for (int i = 0; i < depth; i++) {
            std::cout << "  ";
        }

        std::cout << " " << dirstr->d_name;

        if (dirstr->d_type == DT_DIR) {
            std::cout << "/";
        }

        std::cout << '\n';

        recursive_listing((std::string(ptr) + '/' + std::string(dirstr->d_name)).c_str(), depth + 1);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "No path!" << '\n';
        exit(1);
    }
    std::cout << argv[1] << '\n';
    recursive_listing(argv[1], 0);
}